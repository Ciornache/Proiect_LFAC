%{
    #include "symtable.h"
    #include "arb.h"
    #include <string>
    #define ERR(errl) std::string("Error on line " + to_string(errl) + ": ")

    using namespace std;
    extern int yylex();
    extern FILE * yyin;
    extern char * yytext;
    extern int yylineno;

    bool globalAreaOn = true, funcOn = false, declOn = false;   /// Helper Booleans
    SymTable * globalSymTable; /// SymTable for global variables
    std::vector<SymTable*> symTables, funcSymTables; /// Array of SymTables for Function and Local Variables
    std::vector<ClassSymTable*> classSymTables;     /// Array of ClassSymTables for Classes
    std::vector<std::string> parameters;    /// Parameters for the last Function Call
    std::string lastType;   /// Last type used in an assignment statement
    std::vector<std::pair<std::string, value>> unSymbols;   /// Array of variables that have yet not been declared. It resets after each declaration
    std::pair<bool, int> ifController;  /// Variable that manages the if statement flow.

    /*              Validate Functions            */

    bool isSymbolValid(std::string s, std::string type);   
    bool validateStatement();
    bool validateFunction(std::string name, std::vector<std::string> parameters);
    bool isClassMember(std::string name);

    /*              Process and Update Functions            */

    void processUpdate(SymTable * symTable, std::string name, std::string type, value val, char op);
    void processAssignmentStatement(arb * arb, std::string name, char op);
    void declareClassMethod(ClassSymTable * classSymTable, std::string prv);
    void declareClassMember(ClassSymTable * classSymTable, std::string prv, std::string type);
    void addParameterToFunction(SymTable * funcSymTable, std::string type, std::string name);
    void clearScope();

    /*              Searching SymTable Functions            */

    ClassSymTable * getClassSymTable(std::string name);
    ClassSymTable * getClassIdSymTable(std::string s);
    SymTable * findSymTable(std::string symbol);
    SymTable * getFunctionSymTable(std::string name);

    /*              Helper Functions            */

    void yyerror(std::string s);
    int countWords(std::string word);
    std::pair<std::string, std::string> extractWords(std::string word);

%}
%union {
    char * strValue;
    int iValue;
    bool bValue;
    float fValue;
    char cValue;
    struct Complex* complValue;
    class arb* tree;
}

%token<strValue> ID
%token<iValue> INTEGER
%token<complValue> COMPLEX_LITERAL
%token<strValue> TYPE
%token<bValue> BOOLEAN_LITERAL 
%token<strValue> STRING_LITERAL
%token<fValue> FLOAT_LITERAL
%token<cValue> CHAR_LITERAL
%token OPEN_WALLET CLOSE_WALLET 
%token PRINT TYPEOF
%token PRIVATE PUBLIC PROTECTED TRANSACTION TYPE_ASSIGN
%token CLASS ACCESS
%token AND
%token OR
%token IF ELSE ELSE_IF WHILE FOR
%token SCOPE_START SCOPE_END 
%token INCR DECR
%token RETURN 
%token<strValue> BOOL_OPERATOR ADD_OPERATOR MUL_OPERATOR
%type<tree> FUNCTION_CALL BOOLEAN_EXPRESSION EXPRESSION_LITERAL EXPRESSION PARAMETER
%type<strValue> ARRAY_LITERAL LVALUE_ELEMENT DECL_START
%type<strValue> PRIVATE PUBLIC PROTECTED ACCESS_MODIFIER CLASS_BEGIN_ELEMENT CLASS_LITERAL

%left OR
%left AND
%left BOOL_OPERATOR
%left ADD_OPERATOR
%left MUL_OPERATOR

%start S

%%

///TODO : Treat values as truthy and falsy in boolean expressions

/*  Start Area  */

MAIN_START : OPEN_WALLET {symTables.push_back(new SymTable); globalAreaOn = false; }
MAIN_END : CLOSE_WALLET { clearScope(); }

S : DECLARATIONS MAIN_START MAIN MAIN_END {
        printf("Program compiled succesfully!\n");
        return 0;
}
   ;

/*              Declaration Area            */


/*  Function Declaration Grammar   */

DECL_START : TYPE {declOn = true; lastType = std::string($1); strcpy($$, $1); }

FUNC_START : TRANSACTION ID TYPE_ASSIGN DECL_START '(' {  funcOn = true; funcSymTables.push_back(new SymTable(std::string($4), std::string($2))); declOn = false;}

FUNCTION_DECLARATION : FUNC_START DECL_PARAMETER_SEQUENCE ')' { funcOn = false; }

FUNCTION_DEFINITION : FUNC_START DECL_PARAMETER_SEQUENCE ')' SCOPE { funcOn = false; }

DECL_PARAMETER_SEQUENCE : DECL_START ID ',' DECL_PARAMETER_SEQUENCE { addParameterToFunction(funcSymTables.back(), std::string($1), std::string($2)); }
                        | DECL_START ID  { addParameterToFunction(funcSymTables.back(), std::string($1), std::string($2)); }
                        | /* empty */


/*   Class Declaration Grammar       */

// TODO : Change rule name to convention. Ask Denis for convention

CLASS_BEGIN_ELEMENT : ACCESS_MODIFIER CLASS {strcpy($$, $1);}
                    | CLASS {strcpy($$, "public");}

CLASS_BEGIN : CLASS_BEGIN_ELEMENT ID {classSymTables.push_back(new ClassSymTable(std::string($1), std::string($2)));} 

CLASS_DEFINITION : CLASS_BEGIN SCOPE_START CLASS_MEMBER_LIST SCOPE_END
                 | CLASS_BEGIN SCOPE_START SCOPE_END 

CLASS_MEMBER_LIST : CLASS_MEMBER_LIST CLASS_MEMBER
                  | CLASS_MEMBER
                  ;

CLASS_MEMBER : ACCESS_MODIFIER DECL_START IDSEQUENCE ';' { declareClassMember(classSymTables.back(), std::string($1), std::string($2));}
             | DECL_START IDSEQUENCE ';' { declareClassMember(classSymTables.back(), "blockchain", std::string($1)); }
             | ACCESS_MODIFIER FUNCTION_DECLARATION ';' { declareClassMethod(classSymTables.back(), std::string($1));}
             | FUNCTION_DECLARATION ';' { declareClassMethod(classSymTables.back(), "blockchain");}
             | ACCESS_MODIFIER FUNCTION_DEFINITION { declareClassMethod(classSymTables.back(), std::string($1));}
             | FUNCTION_DEFINITION {declareClassMethod(classSymTables.back(), "blockchain");}

ACCESS_MODIFIER : PRIVATE {strcpy($$, $1);}
                | PUBLIC {strcpy($$, $1);}
                | PROTECTED {strcpy($$, $1);}
                ;


/* Global Variables Declaration Grammar */

/* Global Variables Declaration Grammar */


LINE_DECLARATION : DECL_START IDSEQUENCE {
            SymTable * symTable = symTables.back();
            bool ok = 0;
            for(unsigned int i = 0;i < unSymbols.size() && !ok; i++)
            {
                std::string symbol = unSymbols[i].first;
                if(symTable->isSymbolValid(symbol)) 
                {
                    ok = 1;
                    yyerror(ERR(yylineno) + symbol + " already declared!");
                }
            }
            if(!ok) 
            {
                for(auto [name, val] : unSymbols)
                {
                    symTable->addSymbol(name, $1);
                    processUpdate(symTable, name, std::string($1), val, '=');
                }
            }
            unSymbols.clear();
            declOn = false;
        }
        | ID ID  {
            ClassSymTable * classSymTable = getClassSymTable(std::string($1));
            if(classSymTable == NULL)
                yyerror(ERR(yylineno) + "Undefined identifier " + std::string($1) + "for class type");
            else 
            {
                SymTable * symTable = symTables.back();
                symTable->addSymbol(std::string($2), std::string($1));
                classSymTables.push_back(new ClassSymTable(classSymTable, std::string($1), std::string($2)));
            }
        }


IDSEQUENCE : ID_SEQUENCE_ELEMENT 
           | ID_SEQUENCE_ELEMENT ',' IDSEQUENCE  
           ;

ID_SEQUENCE_ELEMENT : ID {unSymbols.push_back({$1, SymTable::getDefaultValue(lastType)});}
                    | ASSIGNMENT_STATEMENT


/*  General Declaration Grammar  */

DECLARATIONS :  DECLARATIONS_ELEMENT
             |  DECLARATIONS_ELEMENT DECLARATIONS

DECLARATIONS_ELEMENT : LINE_DECLARATION ';'
                     | FUNCTION_DECLARATION ';'
                     | CLASS_DEFINITION ';'
                     | FUNCTION_DEFINITION


/*             Scope Grammar              */


SCOPE : BEGIN_SCOPE CODE_AREA END_SCOPE

BEGIN_SCOPE : SCOPE_START {symTables.push_back(new SymTable);}

END_SCOPE : SCOPE_END {clearScope();}

/*              Block Grammar                     */

BLOCK : IF_BLOCK
      | WHILE_BLOCK
      | FOR_BLOCK

/* For Block Grammar   */

FOR_BLOCK : FOR_STATEMENT SCOPE { symTables.pop_back(); }

FOR_START : FOR { symTables.push_back(new SymTable); }

FOR_STATEMENT : FOR_START '(' INIT_DECL_COMP ';' STOP_CONDITION_COMP ';' MODIFY_COMP ')'
INIT_DECL_COMP : LINE_DECLARATION
               | LINE_INITIALIZATION 

STOP_CONDITION_COMP : BOOLEAN_EXPRESSION

MODIFY_COMP : LINE_INITIALIZATION


LINE_INITIALIZATION : ASSIGNMENT_STATEMENT
                    | ASSIGNMENT_STATEMENT ',' LINE_INITIALIZATION

/* While Block Grammar */

WHILE_STATEMENT : WHILE BOOLEAN_EXPRESSION

WHILE_BLOCK : WHILE_STATEMENT SCOPE

/* If Block Grammar */

IF_BLOCK : IF_COMPOSITION {ifController = {false, 0};}

IF_COMPOSITION : IF_STRUCTURE { if(ifController.first) ifController.second = -1;}

IF_STRUCTURE : IF_STATEMENT SCOPE 
             | IF_STATEMENT SCOPE ELSE_BLOCKS

IF_STATEMENT : IF BOOLEAN_EXPRESSION 
{
    ifController = {true, 0};
    if($2->hasConflictingTypes()) 
        yyerror(ERR(yylineno) + "Invalid Expression in if statement");
    else if($2->getExpressionType() != "bool" && $2->getExpressionResult()!="0" || $2->getExpressionType()=="bool" && $2->getExpressionResult()=="true") 
        ifController.second = 1;
}

ELSE_BLOCKS : ELSE_IF_BLOCK ELSE_BLOCK
            | ELSE_BLOCK

ELSE_IF_BLOCK : ELSE_IF_STATEMENT SCOPE
              | ELSE_IF_STATEMENT SCOPE ELSE_IF_BLOCK

ELSE_BLOCK : ELSE_STATEMENT SCOPE

ELSE_IF_STATEMENT : ELSE_IF  BOOLEAN_EXPRESSION  {
    if(ifController.second) ifController.second = -1;
    if($2->hasConflictingTypes()) 
        yyerror(ERR(yylineno) + "Invalid Expression in else if statement");
    else if(($2->getExpressionType()!="bool" && $2->getExpressionResult()!="0" || $2->getExpressionType()=="bool" && $2->getExpressionResult()=="true") && ifController.second == 0)
        ifController.second = 1;
}

ELSE_STATEMENT : ELSE { if(!ifController.second) ifController.second = 1;}

/*              Main Area           */            

MAIN : CODE_AREA 

MUL_STATEMENTS : STATEMENT ';'
               | STATEMENT ',' MUL_STATEMENTS

CODE_AREA_ELEMENT : BLOCK 
                  | MUL_STATEMENTS
                  | LINE_DECLARATION ';'
                  | SCOPE
                  ;

CODE_AREA : CODE_AREA_ELEMENT 
          | CODE_AREA_ELEMENT CODE_AREA
          ;

/*          Statement Area          */

STATEMENT :   ASSIGNMENT_STATEMENT
            | PRINT_STATEMENT
            | TYPE_OF_STATEMENT
            | FUNCTION_CALL
            | RETURN_STATEMENT 
            | LVALUE_ELEMENT ACCESS FUNCTION_CALL
            ;

LVALUE_ELEMENT : ID 
               | ARRAY_LITERAL
               | CLASS_LITERAL 

CLASS_LITERAL : LVALUE_ELEMENT ACCESS ID {
    if(isClassMember($1)) 
    {
        ClassSymTable * classSymTable = getClassSymTable($1);
        if(classSymTable == NULL)
            yyerror(ERR(yylineno) + "Class Identifier " + std::string($1) + " doesn't exist!");
        else 
        {
            if(!classSymTable->isSymbolInClass(std::string($3))) 
                yyerror(ERR(yylineno) + std::string("Identifier " + std::string($3) + " doesn't exist in class " + std::string($1)));
            else if(classSymTable->getSymbolPrivacy(std::string($3)) != "in_circulation")
                yyerror(ERR(yylineno) + "Identifier " + std::string($3) + " is " + classSymTable->getSymbolPrivacy(std::string($3)) + " in the context of class " + std::string($1));
        }
    }
    std::string className = std::string($1) + " " + std::string($3);
    $$ = strdup(className.c_str());
}

RETURN_STATEMENT : RETURN EXPRESSION
                 | RETURN BOOLEAN_EXPRESSION

ASSIGNMENT_STATEMENT : LVALUE_ELEMENT '=' EXPRESSION { processAssignmentStatement($3, std::string($1), '='); }
                     | LVALUE_ELEMENT '=' ARRAY_DECLARATION {if(declOn) unSymbols.push_back({std::string($1), 0});}
                     | LVALUE_ELEMENT ADD_OPERATOR '=' EXPRESSION { processAssignmentStatement($4, std::string($1), std::string($2)[0]);}
                     | LVALUE_ELEMENT MUL_OPERATOR '=' EXPRESSION { processAssignmentStatement($4, std::string($1), std::string($2)[0]);}
                     | LVALUE_ELEMENT INCR {processAssignmentStatement(new arb("1","int"), std::string($1), '+');}
                     | LVALUE_ELEMENT DECR {processAssignmentStatement(new arb("1","int"), std::string($1), '-');}

/* Print Statement Grammar  */


PRINT_STATEMENT : PRINT '(' EXPRESSION ')' 
                  {
                    if($3->hasConflictingTypes()) 
                        yyerror(ERR(yylineno) + "Invalid Expression in print statement!");
                    else if(validateStatement()) 
                        std::cout << $3->getExpressionResult() << '\n';
                  }
                  | PRINT '(' BOOLEAN_EXPRESSION ')'
                  {
                     if($3->hasConflictingTypes()) 
                        yyerror(ERR(yylineno) + "Invalid Expression in print statement!");
                    else if(validateStatement()) 
                        std::cout << $3->getExpressionResult() << '\n';
                  }
                
/*  Type Of Statement Grammar  */

TYPE_OF_STATEMENT : TYPEOF '(' EXPRESSION ')' 
                    {
                        if($3->hasConflictingTypes()) 
                            yyerror(ERR(yylineno) + "Invalid Expression in typeof statement!");
                        else if(validateStatement()) 
                            std::cout << $3->getExpressionType() << '\n';
                    }
                 | TYPEOF '(' BOOLEAN_EXPRESSION ')'
                    {
                        if($3->hasConflictingTypes()) 
                            yyerror(ERR(yylineno) + "Invalid Expression in typeof statement!");
                        else if(validateStatement()) {
                            std::cout << $3->getExpressionType() << '\n';
                        }
                    }
                

/*         RValue Expressions Area           */

EXPRESSION_LITERAL :  INTEGER {$$ = new arb(SymTable::fromValueToString($1),"int");}
                    | COMPLEX_LITERAL { $$=new arb(SymTable::fromValueToString(Complex($1->real,$1->imag)),"compl"); }
                    | STRING_LITERAL {$$ = new arb(SymTable::fromValueToString(std::string($1)),"string");}
                    | BOOLEAN_LITERAL {$$ = new arb(SymTable::fromValueToString($1),"bool");}
                    | FLOAT_LITERAL {$$ = new arb(SymTable::fromValueToString($1),"float");}
                    | CHAR_LITERAL {$$ = new arb(SymTable::fromValueToString($1),"char");}
                    | LVALUE_ELEMENT {
                        if(countWords(std::string($1)) == 2) {
                            std::string className = extractWords(std::string($1)).first, attribute = extractWords(std::string($1)).second;
                            SymTable * classSymTable = getClassIdSymTable(className); 
                            value val = classSymTable->getSymbolValue("in_circulation " + attribute);
                            $$ = new arb(SymTable::fromValueToString(val), SymTable::extractTypeFromVariant(val));
                        } else {
                            SymTable * symTable = findSymTable(std::string($1));
                            if(symTable != NULL) 
                            {
                                value val = symTable->getSymbolValue(std::string($1));
                                $$ = new arb(SymTable::fromValueToString(val), SymTable::extractTypeFromVariant(val));
                            }
                            else {                           
                                yyerror(ERR(yylineno) + std::string("Undeclared variable ") + std::string($1));
                                $$ = new arb("0", "int");
                            }
                        }
                    }
                    | FUNCTION_CALL {$$ = $1;}
                    | LVALUE_ELEMENT ACCESS FUNCTION_CALL {$$ = $3;}

EXPRESSION : EXPRESSION_LITERAL {$$ = $1;}
           | '(' EXPRESSION ')' {$$=$2;}
           | ADD_OPERATOR EXPRESSION {$$= new arb($1,"",$2,nullptr);}
           | EXPRESSION ADD_OPERATOR EXPRESSION {$$ = new arb($2,"",$1,$3);}
           | EXPRESSION MUL_OPERATOR EXPRESSION {$$ = new arb($2,"",$1,$3);}



/*  Boolean Expression Grammar  */

BOOLEAN_EXPRESSION :  BOOLEAN_EXPRESSION AND BOOLEAN_EXPRESSION {$$ = new arb("&&","",$1,$3);}
                    | BOOLEAN_EXPRESSION OR BOOLEAN_EXPRESSION {$$ = new arb("||","",$1,$3);}
                    | '(' BOOLEAN_EXPRESSION ')' {$$ = $2;}
                    | EXPRESSION BOOL_OPERATOR EXPRESSION {$$ = new arb($2,"",$1,$3);}                       


/*  Integer Expression Grammar      */

/*  Function Call Grammar */

FUNCTION_CALL : ID '(' PARAMETER_LIST ')' 
{
    if(validateStatement()) 
    {
        if(!validateFunction(std::string($1), parameters))
        {
            yyerror(ERR(yylineno) + "Function " + std::string($1) + " was not declared in this scope!");        
            $$ = new arb("0", "int");
        }
        else 
        {
            SymTable * funcSymTable = getFunctionSymTable(std::string($1));
            $$ = new arb("0", funcSymTable->getSymTableType());
        } 
    } 
    parameters.clear();
}

PARAMETER_LIST : PARAMETER {parameters.push_back($1->getExpressionType());}
               | PARAMETER ',' PARAMETER_LIST {parameters.push_back($1->getExpressionType());}
               | /* empty */

PARAMETER : EXPRESSION {$$ = $1;}

/* Array Grammar */

ARRAY_LITERAL : ID '[' EXPRESSION ']' { strcpy($$, $1);}      

ARRAY_DECLARATION : '[' EXPRESSION ';' EXPRESSION ']'
                  | '[' EXPRESSION ']'
                  | '[' EXPRESSION ';' ARRAY_DECLARATION ']'
                  ;
%%

void yyerror(std::string s)
{
    std::ofstream g("errors.txt", ios_base::app);
    g << s << '\n';
    g.close();
}

int main(int args, char * argv[])
{
    FILE * f = fopen(argv[1], "r");
    yyin = f;
    ofstream g("log.out");
    g.close();
    ofstream g2("errors.txt");
    g2.close();
    symTables.push_back(new SymTable);
    yyparse();
    SymTable * symTable = symTables.back();
    symTable->printVariables();
    delete symTable;
    for(auto funcSymTable : funcSymTables) 
    {
        funcSymTable->printFunctionDescription();
        delete funcSymTable;
    }
    for(auto classSymTable : classSymTables) 
    {
        classSymTable->printClassAttributes();
        delete classSymTable;
    }
    std::ifstream fin("errors.txt");
    std::string error;
    while(std::getline(fin, error))
        std::cout << error << '\n';
    fin.close();
    g.close();
}

bool inUnSymbols(std::string s)
{
    for(auto [symbol, value] : unSymbols)
        if(symbol == s)
            return true;
    return false;
}

bool isClassMember(std::string name)
{
    for(unsigned int i = 0; i < classSymTables.size(); i++) 
        if(classSymTables[i]->getSymTableName() == name)
            return true;
    return false;
}

bool isSymbolValid(std::string s, std::string type)
{
    for(int j = symTables.size() - 1;j >= 0; --j) 
        if(symTables[j]->isSymbolValid(s) && symTables[j]->getSymbolType(s) == type)
            return true;

    for(int j = classSymTables.size() - 1; j >= 0; --j)
        if(classSymTables[j]->isSymbolValid(s) && classSymTables[j]->getSymbolType(s) == type)
            return true;

    return false;
}

bool validateStatement()
{
    if(!ifController.first)
        return true;
    if(ifController.first && ifController.second == 1)
        return true;
    return false;
}

bool validateFunction(std::string name, std::vector<std::string> parameters)
{
    for(unsigned int j = 0;j < funcSymTables.size(); j++) 
        if(funcSymTables[j]->getSymTableName() == name && funcSymTables[j]->isParameterMatch(parameters)) 
            return true;

    if(funcSymTables.back()->getSymTableName() == name && funcSymTables.back()->isParameterMatch(parameters))
        return true;

    bool inClass = false;
    for(unsigned int j = 0; j < classSymTables.size(); j++)
    {
        std::vector<SymTable*> funcSymTables = classSymTables[j]->getFuncSymTables();
        for(unsigned int i = 0;i < funcSymTables.size(); i++) 
        {
            SymTable * symTable = funcSymTables[i];
            std::string funcName = symTable->getSymTableName(), prv = extractWords(funcName).second;
            funcName = extractWords(funcName).first;
            if(funcName == name && symTable->isParameterMatch(parameters)) 
            {
                if(prv == "in_circulation") 
                    return symTable;
                inClass = true;
            }
        }
    }

    if(inClass)
        yyerror(ERR(yylineno) + "Function " + name + " is not public");

    return false;
}


SymTable * findSymTable(std::string s)
{
    for(int j = classSymTables.size() - 1; j >= 0; --j)
        if(classSymTables[j]->isSymbolValid(s))
            return classSymTables[j];

    for(int j = symTables.size() - 1;j >= 0; --j)
        if(symTables[j]->isSymbolValid(s))
            return symTables[j];

    if(funcOn) 
    {
        for(int j = funcSymTables.size() - 1; j >= 0; --j) 
            if(funcSymTables[j]->isSymbolValid(s))
                return funcSymTables[j];
    }

    return NULL;
}

SymTable * getFunctionSymTable(std::string name)
{
    for(unsigned int j = 0; j < funcSymTables.size(); j++)
        if(funcSymTables[j]->getSymTableName() == name)
            return funcSymTables[j];
    if(funcSymTables.back()->getSymTableName() == name && funcSymTables.back()->isParameterMatch(parameters))
        return funcSymTables.back();
    for(unsigned int j = 0; j < classSymTables.size(); j++)
    {
        std::vector<SymTable*> funcSymTables = classSymTables[j]->getFuncSymTables();
        for(unsigned int i = 0;i < funcSymTables.size(); i++) 
        {
            SymTable * symTable = funcSymTables[i];
            std::string funcName = symTable->getSymTableName();
            funcName = extractWords(funcName).second;
            if(funcName == name && symTable->isParameterMatch(parameters)) 
                return symTable;
        }
    }

    return NULL;
}

ClassSymTable * getClassSymTable(std::string name)
{
    for(unsigned int i = 0;i < classSymTables.size(); i++)
    {
        if(classSymTables[i]->getSymTableName() == name)
            return classSymTables[i];
    }
    return NULL;
}
ClassSymTable * getClassIdSymTable(std::string s)
{
    for(int j = classSymTables.size() - 1; j >= 0; --j)
        if(classSymTables[j]->getSymTableName() == s)
            return classSymTables[j];
    return NULL;
}

void processUpdate(SymTable * symTable, std::string name, std::string type, value val, char op)
{
    if(op == '=' && !symTable->updateSymbol(name, val) || op != '=' && !symTable->updateSymbol(name, val, op)) 
        yyerror(ERR(yylineno) + "Variable " + name + " is of type " + symTable->getSymbolType(name) + " not of type " + SymTable::extractTypeFromVariant(val));
}

void processAssignmentStatement(arb * arb, std::string name, char op)
{
    if(arb->hasConflictingTypes())  
    {
        yyerror(ERR(yylineno) + "Invalid Expression in Assignment Statement!");
        return;
    }
    std::string type = arb->getExpressionType();
    value val = arb->getExpressionResult();
    std::string value = std::get<std::string>(val);
    if(type == "int")
        val = std::stoi(value);
    else if(type == "bool") 
    {
        if(value == "true" || value[0] != '0') val = true;
        else val = false;
    }
    else if(type == "char")
        val = value[0];
    else if(type == "float")
        val = std::stof(value);
    else if(type=="compl"){
        std::string token=value;
        int imag,real;
        size_t iPos = token.find('i'); // poztia lui i
        if (iPos==string ::npos)
        {
            imag = 0;
            real = stof(token);
            val=Complex(real, imag);
        }
        size_t plusPos = token.find_last_of('+', iPos); // pozitia lu + si -
        size_t minusPos = token.find_last_of('-', iPos);
        size_t splitPos = (plusPos != string::npos) ? plusPos : (minusPos !=string::npos) ? minusPos :string::npos; // vedem care e diferita de npos(care e )
        
        if (splitPos == string::npos)
        {
            real = 0;
            imag = stof(token.substr(0, iPos));
            val=Complex(real, imag);

        }
        imag = stof(token.substr(splitPos + 1, iPos - splitPos - 1));
        real = stof(token.substr(0, splitPos));
        if(token[splitPos]=='-' && imag>0)
        imag=-imag;
        val=Complex(real, imag);
}
    if(validateStatement()) 
    {   
        SymTable * symTable;
        if(countWords(name) == 2) 
        {
            std::string className = extractWords(name).first, attribute = extractWords(name).second;
            name = attribute;
            ClassSymTable * classSymTable = getClassIdSymTable(className);
            if(!classSymTable->isSymbolValid(name) || classSymTable->getSymbolPrivacy(name) != "in_circulation")
                return;
            name = "in_circulation " + name;
            symTable = classSymTable;
        }
        else symTable = findSymTable(name);
        if(isSymbolValid(name, type))    
            processUpdate(symTable, name, type, val, op);
        else 
        {                
            if(op != '=') 
                yyerror(ERR(yylineno) + "Undeclared variable " + name + ".Can't modify it!");
            else if(globalAreaOn || declOn) 
                unSymbols.push_back({name, val});
            else 
            { 
                if(symTable == NULL)
                    yyerror(ERR(yylineno) + std::string("Variable doesn't exist"));
                else if(!symTable->isSymbolValid(name)) 
                    yyerror(ERR(yylineno) + std::string("Undeclared variable ") + name);
                else 
                    yyerror(ERR(yylineno) + "Variable " + name + " is of type " + symTable->getSymbolType(name) + " not of type " + type);
            }
        }
    }
}

void declareClassMember(ClassSymTable * classSymTable, std::string prv, std::string type)
{
    for(auto [name, value] : unSymbols) 
    {
        std::string className = prv + " " + name;
        classSymTable->addSymbol(className, type);
        processUpdate(classSymTable, className, type, value, '=');
    }
    unSymbols.clear();
    declOn = false;
}

void declareClassMethod(ClassSymTable * classSymTable, std::string prv)
{
    SymTable * funcSymTable = funcSymTables.back();
    funcSymTables.pop_back();
    std::string funcName = funcSymTable->getSymTableName();
    funcName = prv + " " + funcName;
    funcSymTable->setFunctionName(funcName);
    classSymTable->addFuncSymTable(funcSymTable);
}

void clearScope()
{
    SymTable * symTable = symTables.back();
    std::map<std::string, bool> symExist = symTable->getSymExist();
    int count = 0;
    for(auto [name, value] : symExist) {
        if(value == true && getClassIdSymTable(name) != NULL)
            count++;
    }       
    for(unsigned int j = 0;j < count; j++) 
    {
        ClassSymTable * classSymTable = classSymTables.back();
        delete classSymTable;
        classSymTables.pop_back();
    }
    delete symTable;
    symTables.pop_back();
}

void addParameterToFunction(SymTable * funcSymTable, std::string type, std::string name)
{
    funcSymTable->addParameter(type);
    funcSymTable->addSymbol(name, type);
    declOn = false;
}

int countWords(std::string word)
{
    std::stringstream ss;
    std::string dummy;
    int count = 0;
    ss << word;
    while(ss >> dummy)
        count++;
    return count;
}

std::pair<std::string, std::string> extractWords(std::string word)
{
    std::stringstream ss;                            
    std::string w1, w2;
    ss << word;
    ss >> w1 >> w2;
    return {w1, w2};
}