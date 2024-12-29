%{
    ///TODO : Ciornei: Refactor Code and Fix Class Sym Tables
    ///TODO : Marciuc: Change Grammar / Add Complex Numbers 

    #include "symtable.h"
    #include "arb.h"
    #include <string>
    #define ERR(errl) std::string("Error on line " + to_string(errl) + ": ")

    using namespace std;
    extern int yylex();
    extern FILE * yyin;
    extern char * yytext;
    extern int yylineno;
    bool globalAreaOn = true, funcOn = false, declOn = false;

    void yyerror(std::string s);
    bool isSymbolValid(std::string s, std::string type);   
    bool validateStatement();
    bool validateFunction(std::string name, std::vector<std::string> parameters);
    void processUpdate(SymTable * symTable, std::string name, std::string type, value val, char op);
    void processAssignmentStatement(arb * arb, std::string name, char op);

    std::string fromValueToString(value val);
    std::string extractValueFromValue(value val);
    std::string extractTypeFromVariant(value value);
    ClassSymTable * getClassSymTable(std::string name);
    bool isClassMember(std::string name);
    SymTable * findSymTable(std::string symbol);
    SymTable * getFunctionSymTable(std::string name);
    ClassSymTable * getClassIdSymTable(std::string s);

    std::string lastType;
    SymTable * globalSymTable;
    std::vector<std::pair<std::string, value>> unSymbols;
    std::pair<bool, int> ifController;
    std::vector<SymTable*> symTables, funcSymTables;
    std::vector<ClassSymTable*> classSymTables;
    std::vector<std::string> parameters;
    ClassSymTable * getClassIdSymTable(std::string s);
    std::string lastType;
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
MAIN_END : CLOSE_WALLET {
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
MAIN_START : OPEN_WALLET {symTables.push_back(new SymTable); globalAreaOn = false; }
MAIN_END : CLOSE_WALLET {
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

DECL_PARAMETER_SEQUENCE : DECL_START ID ',' DECL_PARAMETER_SEQUENCE {
                            SymTable * symTable = funcSymTables.back();
                            symTable->addParameter(std::string($1));
                            symTable->addSymbol(std::string($2), std::string($1));
                            declOn = false;
                        }
                        | DECL_START ID  {
                            SymTable * symTable = funcSymTables.back();
                            symTable->addParameter(std::string($1));
                            symTable->addSymbol(std::string($2), std::string($1));
                            declOn = false;
                        }
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

CLASS_MEMBER : ACCESS_MODIFIER DECL_START IDSEQUENCE ';' {
                ClassSymTable * symTable = classSymTables.back();
                for(auto [name, value] : unSymbols) 
                {
                    std::string className = std::string($1) + " " + name;
                    symTable->addSymbol(className, std::string($2));
                    processUpdate(symTable, className, std::string($2), value, '=');
                }
                declOn = false;
                unSymbols.clear();
            }
             | ACCESS_MODIFIER FUNCTION_DECLARATION ';' {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = std::string($1) + " " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
             | DECL_START IDSEQUENCE ';' {
                ClassSymTable * symTable = classSymTables.back();
                for(auto [name, value] : unSymbols) 
                {
                    std::string className = "blockchain " + name;
                    symTable->addSymbol(className, std::string($1));
                    processUpdate(symTable, className, std::string($1), value, '=');
                }
                unSymbols.clear();
                declOn = false;
                unSymbols.clear();
             }
             | FUNCTION_DECLARATION ';' {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = "blockchain " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
             | FUNCTION_DEFINITION {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = "blockchain " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
             | ACCESS_MODIFIER FUNCTION_DEFINITION {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = std::string($1) + " " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }

ACCESS_MODIFIER : PRIVATE {strcpy($$, $1);}
                | PUBLIC {strcpy($$, $1);}
                | PROTECTED {strcpy($$, $1);}
                ;



/* Global Variables Declaration Grammar */

/* Global Variables Declaration Grammar */


LINE_DECLARATION : DECL_START IDSEQUENCE {
            SymTable * symTable = symTables.back();
            bool ok = 0;
            for(unsigned int i = 0;i < unSymbols.size(); i++)
            {
                std::string symbol = unSymbols[i].first;
                if(symTable->isSymbolValid(symbol)) 
                {
                    ok = 1;
                    yyerror(ERR(yylineno) + symbol + " already declared!");
                    break;
                }
            }
            if(!ok) 
            {
                for(auto [name, val] : unSymbols)
                {
                    printf("aiciiiiiiiiiiiiiiii\n");
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
                yyerror(ERR(yylineno) + "Undefined identifier " + std::string($1) + "for class type\n");
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

BEGIN_SCOPE : SCOPE_START {
    symTables.push_back(new SymTable);
}

END_SCOPE : SCOPE_END {
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

IF_BLOCK : IF_COMPOSITION {
    ifController = {false, 0};
}

IF_COMPOSITION : IF_STRUCTURE {
                      if(ifController.first)
                        ifController.second = -1;
                }

IF_STRUCTURE : IF_STATEMENT SCOPE 
             | IF_STATEMENT SCOPE ELSE_BLOCKS

IF_STATEMENT : IF BOOLEAN_EXPRESSION 
{
    ifController = {true, 0};
    if($2->hasConflictingTypes()) 
        yyerror(ERR(yylineno) + "Invalid Expression in if statement\n");
    else if($2->getExpressionType()!="bool" && $2->getExpressionResult()!="0" || $2->getExpressionType()=="bool" && $2->getExpressionResult()=="true") 
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
        yyerror(ERR(yylineno) + "Invalid Expression in else if statement\n");
    else if(($2->getExpressionType()!="bool" && $2->getExpressionResult()!="0" || $2->getExpressionType()=="bool" && $2->getExpressionResult()=="true") && ifController.second == 0)
        ifController.second = 1;
}

ELSE_STATEMENT : ELSE {
    if(!ifController.second)
         ifController.second = 1;
}


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
            yyerror(ERR(yylineno) + "Class Identifier " + std::string($1) + " doesn't exist!\n");
        else 
        {
            if(!classSymTable->isSymbolInClass(std::string($3))) 
                yyerror(ERR(yylineno) + std::string("Identifier " + std::string($3) + " doesn't exist in class " + std::string($1)));
            else if(classSymTable->getSymbolPrivacy(std::string($3)) != "in_circulation")
                yyerror(ERR(yylineno) + "Identifier " + std::string($3) + " is " + classSymTable->getSymbolPrivacy(std::string($3)) + " in the context of class " + std::string($1));
        }
    }
    char className[101];
    memset(className, false, sizeof(className));
    strcpy(className, $1);
    className[strlen(className)] = ' ';
    strcat(className, $3);
    strcpy($$, className);
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
                        yyerror(ERR(yylineno) + "Invalid Expression in print statement!\n");
                    else if(validateStatement()) 
                        std::cout << $3->getExpressionResult() << '\n';
                  }
                  | PRINT '(' BOOLEAN_EXPRESSION ')'
                  {
                     if($3->hasConflictingTypes()) 
                        yyerror(ERR(yylineno) + "Invalid Expression in print statement!\n");
                    else if(validateStatement()) 
                        std::cout << $3->getExpressionResult() << '\n';
                  }
                
/*  Type Of Statement Grammar  */

TYPE_OF_STATEMENT : TYPEOF '(' EXPRESSION ')' 
                    {
                        if($3->hasConflictingTypes()) 
                            yyerror(ERR(yylineno) + "Invalid Expression in typeof statement!\n");
                        else if(validateStatement()) 
                            std::cout << $3->getExpressionType() << '\n';
                    }
                  | TYPEOF '(' BOOLEAN_EXPRESSION ')'
                    {
                        if($3->hasConflictingTypes()) 
                            yyerror(ERR(yylineno) + "Invalid Expression in typeof statement!\n");
                        else if(validateStatement()) {
                            std::cout << $3->getExpressionType() << '\n';
                        }
                    }
                

/*         RValue Expressions Area           */

EXPRESSION_LITERAL :  INTEGER {$$ = new arb(fromValueToString($1),"int");}

                   | COMPLEX_LITERAL {
                    $$=new arb(fromValueToString(Complex($1->real,$1->imag)),"compl");
                    }
                    | STRING_LITERAL {$$ = new arb(fromValueToString(std::string($1)),"string");}
                    | BOOLEAN_LITERAL {$$ = new arb(fromValueToString($1),"bool");}
                    | FLOAT_LITERAL {$$ = new arb(fromValueToString($1),"float");}
                    | CHAR_LITERAL {$$ = new arb(fromValueToString($1),"char");}
                    | LVALUE_ELEMENT {
                        std::stringstream ss;
                        std::string word;
                        int count = 0;
                        ss << std::string($1);
                        while(ss >> word)
                            count++;
                        if(count == 2) {
                            ss.clear();
                            ss << std::string($1);
                            std::string className, attribute;
                            ss >> className >> attribute;
                            SymTable * classSymTable = getClassIdSymTable(className); 
                            value val = classSymTable->getSymbolValue("in_circulation "+attribute);
                            $$ = new arb(fromValueToString(val), extractTypeFromVariant(val));
                        } else {
                            SymTable * symTable = findSymTable(std::string($1));
                            if(symTable != NULL) 
                            {
                                value val = symTable->getSymbolValue(std::string($1));
                                $$ = new arb(fromValueToString(val), extractTypeFromVariant(val));
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
           | '(' EXPRESSION ')' {$$ = $2;}



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
            yyerror(ERR(yylineno) + "Function " + std::string($1) + " was not declared in this scope!\n");        
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

/// TODO : Use syntax tree to refactor this grammar and add the correct data type to parameters array

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

bool isSymbolValid(std::string s, std::string type)
{
    for(int j = symTables.size() - 1;j >= 0; --j) 
    {
        SymTable * symTable = symTables[j];
        if(symTable->isSymbolValid(s) && symTable->getSymbolType(s) == type)
            return true;
    }

    for(int j = classSymTables.size() - 1; j >= 0; --j)
    {
        SymTable * symTable = classSymTables[j];
        if(symTable->isSymbolValid(s) && symTable->getSymbolType(s) == type)
            return true;
    }

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

ClassSymTable * getClassIdSymTable(std::string s)
{
    for(int j = classSymTables.size() - 1; j >= 0; --j)
    {
        ClassSymTable * symTable = classSymTables[j];
        if(symTable->getSymTableName() == s)
            return symTable;
    }
    return NULL;
}

SymTable * findSymTable(std::string s)
{
    for(int j = classSymTables.size() - 1; j >= 0; --j)
    {
        ClassSymTable * symTable = classSymTables[j];
        if(symTable->isSymbolValid(s))
            return symTable;
    }

    for(int j = symTables.size() - 1;j >= 0; --j)
    {
        ClassSymTable * symTable = classSymTables[j];
        if(symTable->isSymbolValid(s))
            return symTable;
    }

    if(funcOn) 
    {
        for(int j = funcSymTables.size() - 1; j >= 0; --j) 
        {
            SymTable * symTable = funcSymTables[j];
            if(symTable->isSymbolValid(s))
                return symTable;
        }
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
            std::stringstream ss;
            ss << funcName; ss >> funcName >> funcName;
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
    {
        ClassSymTable * symTable = classSymTables[j];
        if(symTable->getSymTableName() == s)
            return symTable;
    }
    return NULL;
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
            std::string funcName = symTable->getSymTableName(), prv;
            std::stringstream ss;           
            ss << funcName; ss >> prv >> funcName;
            if(funcName == name && symTable->isParameterMatch(parameters)) 
            {
                if(prv == "in_circulation") 
                    return symTable;
                inClass = true;
            }
        }
    }

    if(inClass)
        yyerror(ERR(yylineno) + "Function " + name + " is not public\n");

    return false;
}

bool isClassMember(std::string name)
{
    for(unsigned int i = 0; i < classSymTables.size(); i++) 
        if(classSymTables[i]->getSymTableName() == name)
            return true;
    return false;
}

std::string extractValueFromValue(value value)
{
    if(std::holds_alternative<int>(value)) 
        std::cout << get<int>(value);
    else if(std::holds_alternative<std::string>(value))
        std::cout << get<std::string>(value);
    else if(std::holds_alternative<float>(value))
        std::cout << get<float>(value);
    else if(std::holds_alternative<char>(value))
        std::cout << get<char>(value);
    else if(std::holds_alternative<Complex>(value))
        std::cout << get<Complex>(value);
    else if(std::holds_alternative<bool>(value))
        std::cout << get<bool>(value);
    return "";
}

std::string extractTypeFromVariant(value value)
{
    if(std::holds_alternative<int>(value)) 
        return "int";
    else if(std::holds_alternative<std::string>(value))
        return "string";
    else if(std::holds_alternative<float>(value))
        return "float";
    else if(std::holds_alternative<char>(value))
        return "char";
    else if(std::holds_alternative<Complex>(value))
        return "compl";
    else 
        return "bool";
}

void processUpdate(SymTable * symTable, std::string name, std::string type, value val, char op)
{
    if(op == '=' && !symTable->updateSymbol(name, val) || op != '=' && !symTable->updateSymbol(name, val, op)) 
        yyerror(ERR(yylineno) + "Variable " + name + " is of type " + symTable->getSymbolType(name) + " not of type " + extractTypeFromVariant(val));
}

void processAssignmentStatement(arb * arb, std::string name, char op)
{
    printf("SUNT IN ASSIGMENT STATEMENT YEEEEEEEEEEEEEEEE\n");
    if(arb->hasConflictingTypes())  
    {
        yyerror(ERR(yylineno) + "Invalid Expression in Assignment Statement!\n");
        return;
    }
    std::string type = arb->getExpressionType();
    value val = arb->getExpressionResult();
    printf("type : %s , value : %s \n",arb->getExpressionType().c_str(),arb->getExpressionResult().c_str());
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
        std::stringstream ss;
        std::string word;
        int count = 0;
        ss << name;
        while(ss >> word)
            count++;
        if(count == 2) 
        {
            ss.clear();
            ss << name;
            std::string className, attribute;
            ss >> className >> attribute;
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

std::string fromValueToString(value val)
{
    if(std::holds_alternative<std::string>(val))
        return std::get<std::string>(val);
    std::stringstream ss;
    std::string s;
    if(std::holds_alternative<int>(val))
        ss << get<int>(val);
    else if(std::holds_alternative<float>(val))
        ss << get<float>(val);
    else if(std::holds_alternative<bool>(val)) 
        ss << get<bool>(val);
    else if(std::holds_alternative<char>(val))
        ss << get<char>(val);
    else if(std::holds_alternative<Complex>(val))
        ss << get<Complex>(val);
    ss >> s;
    return s;
}
