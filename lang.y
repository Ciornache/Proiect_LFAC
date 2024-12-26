%{
    #include "symtable.h"
    using namespace std;
    extern int yylex();
    extern FILE * yyin;
    extern char * yytext;
    extern int yylineno;
    bool globalAreaOn = true, funcOn = false;


    /// TODO: Assign values to class members

    void yyerror(std::string s);
    bool isSymbolValid(std::string s, std::string type);   
    bool validateStatement();
    bool validateFunction(std::string name, std::vector<std::string> parameters);
    void processUpdate(SymTable * symTable, std::string name, std::string type, value val, char op);
    void processAssignmentStatement(SymTable * symTable, std::string name, std::string type, value val, char op);

    std::string extractValueFromValue(value val);
    std::string extractTypeFromVariant(value value);
    ClassSymTable * getClassSymTable(std::string name);
    bool isClassMember(std::string name);
    SymTable * findSymTable(std::string symbol);


    SymTable * globalSymTable;
    std::vector<std::pair<std::string, value>> unSymbols;
    std::pair<bool, int> ifController;
    std::vector<SymTable*> symTables, funcSymTables;
    std::vector<ClassSymTable*> classSymTables;
    std::vector<std::string> parameters;
%}
%union {
    char * strValue;
    int iValue;
    bool bValue;
}

%token<strValue> ID
%token<iValue> INTEGER
%token<strValue> TYPE
%token<bValue> BOOLEAN_LITERAL 
%token<strValue> STRING_LITERAL
%token OPEN_WALLET CLOSE_WALLET 
%token PRINT TYPEOF
%token PRIVATE PUBLIC PROTECTED
%token CLASS ACCESS
%token AND
%token OR
%token EQ NEQ LT LEQ HT HEQ
%token IF ELSE ELSE_IF WHILE FOR
%token SCOPE_START SCOPE_END 
%token PLUS MINUS MUL DIV MOD INCR DECR
%token RETURN 

%type<iValue> INTEGER_EXPRESSION FUNCTION_CALL
%type<bValue> BOOLEAN_EXPRESSION BOOLEAN_EQUATION
%type<strValue> PLUS MINUS MUL DIV MOD OPERATOR 
%type<strValue> ARRAY_LITERAL LVALUE_ELEMENT
%type<strValue> PRIVATE PUBLIC PROTECTED ACCESS_MODIFIER CLASS_BEGIN_ELEMENT CLASS_LITERAL

%left OR
%left AND
%left NEQ EQ LT LEQ HT HEQ
%left PLUS MINUS
%left MUL DIV MOD

%start S

%%

/*  Start Area  */

S : DECLARATIONS OPEN_WALLET MAIN CLOSE_WALLET {
        printf("Program compiled succesfully!\n");
        return 0;
}
   ;

/*              Declaration Area            */


/*  Function Declaration Grammar   */

FUNC_START : TYPE ID '(' { funcOn = true; funcSymTables.push_back(new SymTable(std::string($1), std::string($2))); }

FUNCTION_DECLARATION : FUNC_START DECL_PARAMETER_SEQUENCE ')' { funcOn = false; }

FUNCTION_DEFINITION : FUNC_START DECL_PARAMETER_SEQUENCE ')' SCOPE { funcOn = false; }

DECL_PARAMETER_SEQUENCE : TYPE ID ',' DECL_PARAMETER_SEQUENCE {
                            SymTable * symTable = funcSymTables.back();
                            symTable->addParameter(std::string($1));
                            symTable->addSymbol(std::string($2), std::string($1));
                        }
                        | TYPE ID  {
                            SymTable * symTable = funcSymTables.back();
                            symTable->addParameter(std::string($1));
                            symTable->addSymbol(std::string($2), std::string($1));
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

CLASS_MEMBER : ACCESS_MODIFIER TYPE IDSEQUENCE ';' {
                ClassSymTable * symTable = classSymTables.back();
                for(auto [name, value] : unSymbols) 
                {
                    std::string className = std::string($1) + " " + name;
                    symTable->addSymbol(className, std::string($2));
                    // std::cout << std::string($2) << ' ' << className << '\n';
                    processUpdate(symTable, className, std::string($2), value, '=');
                }
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
             | TYPE IDSEQUENCE ';' {
                ClassSymTable * symTable = classSymTables.back();
                for(auto [name, value] : unSymbols) 
                {
                    std::string className = "private " + name;
                    symTable->addSymbol(className, std::string($1));
                    processUpdate(symTable, className, std::string($1), value, '=');
                }
             }
             | FUNCTION_DECLARATION ';' {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = "private " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
             | FUNCTION_DEFINITION {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = "private " + funcName;
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

ACCESS_MODIFIER : PRIVATE {
                    strcpy($$, $1);
                }
                | PUBLIC {
                    strcpy($$, $1);
                }
                | PROTECTED {
                    strcpy($$, $1);
                }
                ;

/* Global Variables Declaration Grammar */

/* Global Variables Declaration Grammar */

LINE_DECLARATION : TYPE IDSEQUENCE {
        SymTable * symTable = symTables.back();
        bool ok = 0;
        for(unsigned int i = 0;i < unSymbols.size(); i++)
        {
            std::string symbol = unSymbols[i].first;
            if(symTable->isSymbolValid(symbol)) 
            {
                ok = 1;
                yyerror(symbol + " already declared!");
                break;
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
}
| ID ID {
    SymTable * symTable = symTables.back();
    symTable->addSymbol(std::string($2), std::string($1));
}


IDSEQUENCE : ID_SEQUENCE_ELEMENT 
           | ID_SEQUENCE_ELEMENT ',' IDSEQUENCE  
           ;

ID_SEQUENCE_ELEMENT : ID {
                         unSymbols.push_back({$1, 0});
                    }
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

IF_STATEMENT : IF BOOLEAN_EXPRESSION {
    ifController = {true, 0};
    if($2) 
        ifController.second = 1;
}

ELSE_BLOCKS : ELSE_IF_BLOCK ELSE_BLOCK
            | ELSE_BLOCK

ELSE_IF_BLOCK : ELSE_IF_STATEMENT SCOPE
              | ELSE_IF_STATEMENT SCOPE ELSE_IF_BLOCK

ELSE_BLOCK : ELSE_STATEMENT SCOPE

ELSE_IF_STATEMENT : ELSE_IF  BOOLEAN_EXPRESSION  {
    if(ifController.second) ifController.second = -1;
    if($2 && ifController.second == 0)
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

CLASS_LITERAL : LVALUE_ELEMENT ACCESS ID {
    if(isClassMember($1)) 
    {
        ClassSymTable * classSymTable = getClassSymTable($1);
        if(classSymTable == NULL) {
            yyerror("Class Identifier " + std::string($1) + " doesn't exist!\n");
            exit(1);
        }
        else {
            if(!classSymTable->isSymbolInClass(std::string($3))) {
                yyerror(std::string("Identifier " + std::string($3) + " doesn't exist in class " + std::string($1)));
                exit(1);
            }
        }
    }
    strcpy($$, $3);
}

RETURN_STATEMENT : RETURN INTEGER_EXPRESSION
                 | RETURN BOOLEAN_EXPRESSION
                 | RETURN STRING_LITERAL

ASSIGNMENT_STATEMENT : CLASS_LITERAL '=' INTEGER_EXPRESSION {processAssignmentStatement(getClassSymTable(std::string($1)), std::string($1), "int", value($3), '='); }
                     | LVALUE_ELEMENT '=' INTEGER_EXPRESSION { processAssignmentStatement(findSymTable(std::string($1)), std::string($1), "int", value($3), '='); }
                     | CLASS_LITERAL '=' BOOLEAN_EXPRESSION {processAssignmentStatement(getClassSymTable(std::string($1)), std::string($1), "bool", value($3), '='); }
                     | LVALUE_ELEMENT '=' BOOLEAN_EXPRESSION { processAssignmentStatement(findSymTable(std::string($1)), std::string($1), "bool", value($3), '=');}
                     | CLASS_LITERAL '=' ARRAY_DECLARATION
                     | LVALUE_ELEMENT '=' ARRAY_DECLARATION
                     | CLASS_LITERAL OPERATOR '=' INTEGER_EXPRESSION 
                     | LVALUE_ELEMENT OPERATOR '=' INTEGER_EXPRESSION { processAssignmentStatement(getClassSymTable(std::string($1)), std::string($1), "int", value($4), std::string($2)[0]);}
                     | CLASS_LITERAL INCR
                     | LVALUE_ELEMENT INCR
                     | CLASS_LITERAL DECR
                     | LVALUE_ELEMENT DECR
                     | LVALUE_ELEMENT '=' STRING_LITERAL {processAssignmentStatement(findSymTable(std::string($1)), std::string($1), "string", value($3), '=');}
/* Print Statement Grammar  */


PRINT_STATEMENT : PRINT '(' INTEGER_EXPRESSION ')' {
                    if(validateStatement()) 
                        std::cout << $3 << '\n';
                }
                | PRINT '(' BOOLEAN_EXPRESSION ')'{
                    if(validateStatement()) 
                    {
                        if($3)
                            std::cout << "true\n";
                        else std::cout << "false\n";
                    }
                }
                | PRINT '(' STRING_LITERAL ')' {
                    if(validateStatement()) {
                        std::cout << $3 << '\n';
                    }
                }

/*  Type Of Statement Grammar  */

TYPE_OF_STATEMENT : TYPEOF '(' INTEGER_EXPRESSION ')' {
                    if(validateStatement()) 
                        std::cout << "integer\n";
                }
                |   TYPEOF '(' BOOLEAN_EXPRESSION ')' {
                    if(validateStatement()) 
                        std::cout << "bool\n";
                }

/*         RValue Expressions Area           */

OPERATOR : PLUS 
         | MINUS 
         | MUL 
         | DIV
         | MOD

/*  Boolean Expression Grammar  */

BOOLEAN_EXPRESSION :  BOOLEAN_EXPRESSION AND BOOLEAN_EXPRESSION {
                            $$ = ($1 && $3);
                    }
                    | BOOLEAN_EXPRESSION OR BOOLEAN_EXPRESSION {
                            $$ = ($1 || $3);
                    }
                    | BOOLEAN_EQUATION {
                        $$ = $1;
                    }
                    | '(' BOOLEAN_EXPRESSION ')' {
                        $$ = $2;
                    }
                    ;

BOOLEAN_EQUATION : INTEGER_EXPRESSION EQ INTEGER_EXPRESSION {
                        $$ = ($1 == $3);
                    }
                    | INTEGER_EXPRESSION NEQ INTEGER_EXPRESSION {
                        $$ = ($1 != $3);
                    }
                    | INTEGER_EXPRESSION AND INTEGER_EXPRESSION {
                        $$ = ($1 && $3);
                    }
                    | INTEGER_EXPRESSION OR INTEGER_EXPRESSION {
                        $$ = ($1 || $3);
                    }
                    |
                    INTEGER_EXPRESSION LEQ INTEGER_EXPRESSION {
                        $$ = ($1 <= $3);
                    }
                    | INTEGER_EXPRESSION HEQ INTEGER_EXPRESSION {
                        $$ = ($1 >= $3);
                    }
                    | INTEGER_EXPRESSION HT INTEGER_EXPRESSION {
                        $$ = ($1 > $3);
                    }
                    | INTEGER_EXPRESSION LT INTEGER_EXPRESSION {
                        $$ = ($1 < $3);
                    }
                    | BOOLEAN_LITERAL { 
                        $$ = $1;
                    }

/*  Integer Expression Grammar      */

INTEGER_EXPRESSION : LVALUE_ELEMENT ACCESS LVALUE_ELEMENT {
                    $$ = 0;
                    SymTable * symTable = findSymTable(std::string($3));
                    if(symTable != NULL && symTable->isSymbolValid(std::string($3))) 
                    {
                        value val = symTable->getSymbolValue(std::string($3));
                        if(std::holds_alternative<int>(val))
                            $$ = std::get<int>(val);
                    }
                    else 
                        yyerror(std::string("Undeclared variable ") + std::string($1));
                }
                | LVALUE_ELEMENT ACCESS FUNCTION_CALL {
                    $$ = 0;
                }
                | LVALUE_ELEMENT {
                    SymTable * symTable = findSymTable(std::string($1));
                    if(symTable != NULL && symTable->isSymbolValid(std::string($1))) 
                    {
                        value val = symTable->getSymbolValue(std::string($1));
                        if(std::holds_alternative<int>(val))
                            $$ = std::get<int>(val);
                    }
                    else {
                        yyerror(std::string("Undeclared variable ") + std::string($1));
                        $$ = 0;
                    }
            }
            | FUNCTION_CALL {
                $$ = 0;
            }
            | INTEGER {
                $$ = $1;
            }
            | INTEGER_EXPRESSION PLUS INTEGER_EXPRESSION {
                $$ = $1 + $3;
            }
            | INTEGER_EXPRESSION MUL INTEGER_EXPRESSION {
                $$ = $1 * $3;
            }
            | INTEGER_EXPRESSION MINUS INTEGER_EXPRESSION {
                $$ = $1 - $3;
            }
            | INTEGER_EXPRESSION MOD INTEGER_EXPRESSION {
                $$ = $1 % $3;
            }
            | INTEGER_EXPRESSION DIV INTEGER_EXPRESSION {
                $$ = $1 / $3;
            }
            | '(' INTEGER_EXPRESSION ')' {
                $$ = $2;
            }
            ;

/*  Function Call Grammar */

FUNCTION_CALL : ID '(' PARAMETER_LIST ')' 
{
    if(validateStatement()) 
    {
        if(!validateFunction(std::string($1), parameters)) 
        {
            yyerror("Function " + std::string($1) + " was not declared in this scope!\n");
            exit(1);
        }
    } 
    $$ = 0;
    parameters.clear();
}

/// TODO : Use syntax tree to refactor this grammar and add the correct data type to parameters array

PARAMETER_LIST : PARAMETER {parameters.push_back("int");}
               | PARAMETER ',' PARAMETER_LIST {parameters.push_back("int");}
               | /* empty */

PARAMETER : INTEGER_EXPRESSION
          | STRING_LITERAL 
          | BOOLEAN_EXPRESSION

/* Array Grammar */

ARRAY_LITERAL : ID '[' INTEGER_EXPRESSION ']' { strcpy($$, $1);}      

ARRAY_DECLARATION : '[' INTEGER_EXPRESSION ';' INTEGER_EXPRESSION ']'
                  | '[' INTEGER_EXPRESSION ']'
                  | '[' INTEGER_EXPRESSION ';' ARRAY_DECLARATION ']'
                  ;


%%

void yyerror(std::string s)
{
    fprintf(stderr, "%s\n", s.c_str());
}

int main(int args, char * argv[])
{
    FILE * f = fopen(argv[1], "r");
    yyin = f;
    ofstream g("log.out");
    g.close();
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

SymTable * findSymTable(std::string s)
{
    for(int j = symTables.size() - 1;j >= 0; --j)
    {
        SymTable * symTable = symTables[j];
        if(symTable->isSymbolValid(s))
            return symTable;
    }

    for(int j = classSymTables.size() - 1; j >= 0; --j)
    {
        SymTable * symTable = classSymTables[j];
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

ClassSymTable * getClassSymTable(std::string name)
{
    for(unsigned int i = 0;i < classSymTables.size(); i++)
    {
        if(classSymTables[i]->getSymTableName() == name)
            return classSymTables[i];
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
                return true;
        }
    }

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
    {
        yyerror("Variable " + name + " is of type " + symTable->getSymbolType(name) + " not of type " + extractTypeFromVariant(val));
        exit(2);
    }
}

void processAssignmentStatement(SymTable * symTable, std::string name, std::string type, value val, char op)
{
    if(validateStatement()) 
    {    
        symTable = findSymTable(name);
        if(isSymbolValid(name, type)) 
        {
            if(op == '=')
                processUpdate(symTable, name, type, val, op);
            else 
                processUpdate(symTable, name, type, val, op);
        }
        else 
        {
            if(op != '=') 
            {
                yyerror("Undeclared variable " + name + ".Can't modify it!");
                exit(3);
            }
            if(globalAreaOn) 
                unSymbols.push_back({name, val});
            else 
            { 
                yyerror(std::string("Undeclared variable ") + name);
                exit(3);
            }
        }
    }
}