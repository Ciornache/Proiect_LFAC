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
    std::pair<bool, int> ifController;
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
%token AND
%token OR
%token EQ NEQ LT LEQ HT HEQ
%token IF ELSE ELSE_IF WHILE FOR
%token SCOPE_START SCOPE_END 

%type<iValue> INTEGER_EXPRESSION
%type<bValue> BOOLEAN_EXPRESSION
%type<bValue> BOOLEAN_EQUATION

%left OR
%left AND
%left NEQ EQ LT LEQ HT HEQ
%left '+' '-'
%left '*' '/' '%'

%start S

%%

FUNCTION_CALL : ID '(' PARAMETER_LIST ')'

PARAMETER_LIST : PARAMETER
               | PARAMETER_LIST PARAMETER

PARAMETER : INTEGER_EXPRESSION
          | FUNCTION_CALL

FUNCTION_DECLARATION : TYPE ID '(' DECL_PARAMETER_SEQUENCE ')'

ARRAY_LITERAL : '[' INTEGER_EXPRESSION ';' INTEGER_EXPRESSION ']'
              | '[' INTEGER_EXPRESSION ']'
              ;

DECLARATIONS_ELEMENT : LINE_DECLARATION
                     | FUNCTION_DECLARATION

DECLARATIONS :  DECLARATIONS_ELEMENT
             |  DECLARATIONS_ELEMENT DECLARATIONS

DECL_PARAMETER_SEQUENCE : TYPE ID ',' DECL_PARAMETER_SEQUENCE
                   | TYPE ID 

IDSEQUENCE :   ID ',' IDSEQUENCE {unSymbols.push_back({$1, 0});}
             | ID ';' {unSymbols.push_back({$1, 0});}
             | ASSIGNMENT_STATEMENT ',' IDSEQUENCE
             | ASSIGNMENT_STATEMENT ';'
             ;
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


BEGIN_SCOPE : SCOPE_START {
    symTables.push_back(new SymTable);
}

END_SCOPE : SCOPE_END {
    SymTable * symTable = symTables.back();
    delete symTable;
    symTables.pop_back();
}

SCOPE : BEGIN_SCOPE CODE_AREA END_SCOPE

WHILE_BLOCK : WHILE '(' BOOLEAN_EXPRESSION ')'

IF_BLOCK : IF_COMPOSITION {
    ifController = {false, 0};
}

IF_COMPOSITION  : IF_STRUCTURE {
                      if(ifController.first)
                        ifController.second = -1;
                }

IF_STRUCTURE : IF_STATEMENT SCOPE 
             | IF_STATEMENT SCOPE ELSE_BLOCKS

ELSE_BLOCKS : ELSE_IF_BLOCK ELSE_BLOCK
            | ELSE_BLOCK

IF_STATEMENT : IF BOOLEAN_EXPRESSION {
    ifController = {true, 0};
    if($2) 
        ifController.second = 1;
}

ELSE_IF_STATEMENT : ELSE_IF  BOOLEAN_EXPRESSION  {
    if($2 && !ifController.second)
        ifController.second = 1;
}

ELSE_IF_BLOCK : ELSE_IF_STATEMENT SCOPE
              | ELSE_IF_STATEMENT SCOPE ELSE_IF_BLOCK

ELSE_STATEMENT : ELSE {
    if(!ifController.second)
         ifController.second = 1;
}

ELSE_BLOCK : ELSE_STATEMENT SCOPE

MAIN : CODE_AREA 

CODE_AREA_ELEMENT : BLOCK 
                  | STATEMENT ';'
                  ;

CODE_AREA : CODE_AREA_ELEMENT 
          | CODE_AREA_ELEMENT CODE_AREA
          ;

BLOCK : IF_BLOCK
      | WHILE_BLOCK
    
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
                
TYPE_OF_STATEMENT : TYPEOF '(' INTEGER_EXPRESSION ')' {
                    std::cout << "integer\n";
                }
                |   TYPEOF '(' BOOLEAN_EXPRESSION ')' {
                    std::cout << "bool\n";
                }

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
            INTEGER_EXPRESSION '+' INTEGER_EXPRESSION {
                $$ = $1 + $3;
            }
            |
            INTEGER_EXPRESSION '*' INTEGER_EXPRESSION {
                $$ = $1 * $3;
            }
            |
            INTEGER_EXPRESSION '-' INTEGER_EXPRESSION {
                $$ = $1 - $3;
            }
            |
            INTEGER_EXPRESSION '%' INTEGER_EXPRESSION {
                std::cout << "AICI!\n";
                $$ = $1 % $3;
            }
            |
            INTEGER_EXPRESSION '/' INTEGER_EXPRESSION {
                $$ = $1 / $3;
            }
            |
            '(' INTEGER_EXPRESSION ')' {
                $$ = $2;
            }
            ;


S : DECLARATIONS OPEN_WALLET MAIN CLOSE_WALLET {
        printf("Program compiled succesfully!\n");
        return 0;
}
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
    return NULL;
}