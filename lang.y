%{
    #include "symtable.h"
    using namespace std;
    extern int yylex();
    extern FILE * yyin;
    extern char * yytext;
    extern int yylineno;
    void yyerror(std::string s);
    bool isSymbolValid(std::string s, std::string type);   
    bool validateStatement();
    SymTable * findSymTable(std::string symbol);
    SymTable * globalSymTable;
    std::vector<std::pair<std::string, value>> unSymbols;
    bool globalAreaOn = true;
    std::pair<bool, int> ifController, whileController, forController;
    std::vector<SymTable*> symTables;

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
%token CLASS
%token AND
%token OR
%token EQ NEQ LT LEQ HT HEQ
%token IF ELSE ELSE_IF WHILE FOR
%token SCOPE_START SCOPE_END 
%token PLUS MINUS MUL DIV MOD INCR DECR

%type<iValue> INTEGER_EXPRESSION
%type<bValue> BOOLEAN_EXPRESSION BOOLEAN_EQUATION
%type<strValue> PLUS MINUS MUL DIV MOD

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


FUNCTION_DECLARATION : TYPE ID '(' DECL_PARAMETER_SEQUENCE ')'

DECL_PARAMETER_SEQUENCE : TYPE ID ',' DECL_PARAMETER_SEQUENCE
                        | TYPE ID 


/*   Class Declaration Grammar       */

CLASS_DEFINITION : ACCESS_MODIFIER CLASS ID SCOPE_START CLASS_MEMBER_LIST SCOPE_END ;

CLASS_MEMBER_LIST : /* empty */ ;

ACCESS_MODIFIER : PRIVATE
                | PUBLIC
                | PROTECTED
                |
                ;

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
            for(auto [symbol, val] : unSymbols)
            {
                symTable->addSymbol(symbol, $1);
                symTable->updateSymbol(symbol, val);
            }
        }
        unSymbols.clear();
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

FOR_BLOCK : FOR_STATEMENT SCOPE {
    forController.first = false;
}

FOR_STATEMENT : FOR '(' INIT_DECL_COMP ';' STOP_CONDITION_COMP ';' MODIFY_COMP ')' {
    forController.first = true;
}

INIT_DECL_COMP : LINE_DECLARATION
               | LINE_INITIALIZATION 

STOP_CONDITION_COMP : BOOLEAN_EXPRESSION

MODIFY_COMP : LINE_INITIALIZATION


LINE_INITIALIZATION : ASSIGNMENT_STATEMENT
                    | ASSIGNMENT_STATEMENT ',' LINE_INITIALIZATION

/* While Block Grammar */

WHILE_STATEMENT : WHILE BOOLEAN_EXPRESSION {
    whileController.first = true;
}

WHILE_BLOCK : WHILE_STATEMENT SCOPE {
    whileController.first = false;
}

/* If Block Grammar */

IF_BLOCK : IF_COMPOSITION {
    ifController = {false, 0};
}

IF_COMPOSITION  : IF_STRUCTURE {
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
    if($2 && !ifController.second)
        ifController.second = 1;
}

ELSE_STATEMENT : ELSE {
    if(!ifController.second)
         ifController.second = 1;
}


/*              Main Area           */            

MAIN : CODE_AREA 

CODE_AREA_ELEMENT : BLOCK 
                  | STATEMENT ';'
                  | LINE_DECLARATION ';'
                  ;

CODE_AREA : CODE_AREA_ELEMENT 
          | CODE_AREA_ELEMENT CODE_AREA
          ;

/*          Statement Area          */

STATEMENT :   ASSIGNMENT_STATEMENT
            | PRINT_STATEMENT
            | TYPE_OF_STATEMENT
            ;

ASSIGNMENT_STATEMENT : ID '=' INTEGER_EXPRESSION {
                        if(validateStatement()) {
                            std::string symbol($1);
                            SymTable * symTable = findSymTable(symbol);
                            if(isSymbolValid(symbol, "int"))
                            {
                                value val = symTable->getSymbolValue(symbol);
                                symTable->updateSymbol(symbol, $3);
                            }
                            else {
                                if(globalAreaOn) 
                                    unSymbols.push_back({$1, $3});
                                else 
                                    yyerror(std::string("Undeclared variable ") + std::string($1));
                            }
                    }
                 }
                    |   ID '=' BOOLEAN_EXPRESSION {
                            if(validateStatement()) {
                                std::string symbol($1);
                                SymTable * symTable = findSymTable(symbol);
                                if(isSymbolValid(symbol, "bool"))
                                {
                                    value val = symTable->getSymbolValue(symbol);
                                    symTable->updateSymbol(symbol, $3);
                                }
                                else {
                                    if(globalAreaOn) 
                                        unSymbols.push_back({$1, value($3)});
                                    else 
                                        yyerror(std::string("Undeclared variable ") + std::string($1));
                                }
                        }
                    }
                    | ID '=' ARRAY_LITERAL
                    | ID '=' FUNCTION_CALL
                    | ID OPERATOR '=' INTEGER_EXPRESSION
                    | ID INCR
                    | ID DECR

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

/*  Type Of Statement Grammar  */

TYPE_OF_STATEMENT : TYPEOF '(' INTEGER_EXPRESSION ')' {
                    std::cout << "integer\n";
                }
                |   TYPEOF '(' BOOLEAN_EXPRESSION ')' {
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

INTEGER_EXPRESSION : ID {
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
            |
            INTEGER {
                $$ = $1;
            }
            |
            INTEGER_EXPRESSION PLUS INTEGER_EXPRESSION {
                $$ = $1 + $3;
            }
            |
            INTEGER_EXPRESSION MUL INTEGER_EXPRESSION {
                $$ = $1 * $3;
            }
            |
            INTEGER_EXPRESSION MINUS INTEGER_EXPRESSION {
                $$ = $1 - $3;
            }
            |
            INTEGER_EXPRESSION MOD INTEGER_EXPRESSION {
                $$ = $1 % $3;
            }
            |
            INTEGER_EXPRESSION DIV INTEGER_EXPRESSION {
                $$ = $1 / $3;
            }
            |
            '(' INTEGER_EXPRESSION ')' {
                $$ = $2;
            }
            ;

/*  Function Call Grammar */

FUNCTION_CALL : ID '(' PARAMETER_LIST ')'

PARAMETER_LIST : PARAMETER
               | PARAMETER ',' PARAMETER_LIST

PARAMETER : INTEGER_EXPRESSION
          | FUNCTION_CALL

/* Array Grammar */

ARRAY_LITERAL : '[' INTEGER_EXPRESSION ';' INTEGER_EXPRESSION ']'
              | '[' INTEGER_EXPRESSION ']'
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
    symTables.push_back(new SymTable);
    yyparse();
    SymTable * symTable = symTables.back();
    symTable->printVariables();
    delete symTable;
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
    return false;
}

bool validateStatement()
{
    if(!ifController.first && !whileController.first && !forController.first)
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
    return NULL;
}