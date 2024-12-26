%{
    #include "symtable.h"
    #include "arb.h"
    #include <string>
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
%debug
%union {
    char * strValue;
    int iValue;
    bool bValue;
    class arb* tree;
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
%token IF ELSE ELSE_IF WHILE FOR
%token SCOPE_START SCOPE_END 
%token INCR DECR
%token RETURN 
%token<strValue> BOOL_OPERATOR ADD_OPERATOR MUL_OPERATOR
%type<tree> INTEGER_EXPRESSION FUNCTION_CALL BOOLEAN_EXPRESSION
%type<strValue> ARRAY_LITERAL LVALUE_ELEMENT

%left OR
%left AND
%left BOOL_OPERATOR
%left ADD_OPERATOR
%left MUL_OPERATOR

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

FUNCTION_DEFINITION : TYPE ID '(' DECL_PARAMETER_SEQUENCE ')' SCOPE

DECL_PARAMETER_SEQUENCE : TYPE ID ',' DECL_PARAMETER_SEQUENCE
                        | TYPE ID 
                        | /* empty */


/*   Class Declaration Grammar       */

CLASS_DEFINITION : ACCESS_MODIFIER CLASS ID SCOPE_START CLASS_MEMBER_LIST SCOPE_END
                 | ACCESS_MODIFIER CLASS ID SCOPE_START SCOPE_END 
                 | CLASS ID SCOPE_START SCOPE_END
                 | CLASS ID SCOPE_START CLASS_MEMBER_LIST SCOPE_END

CLASS_MEMBER_LIST : CLASS_MEMBER_LIST CLASS_MEMBER
                  | CLASS_MEMBER
                  ;
CLASS_MEMBER : ACCESS_MODIFIER TYPE IDSEQUENCE ';'
             | ACCESS_MODIFIER FUNCTION_DECLARATION ';'
             | TYPE IDSEQUENCE ';'
             | FUNCTION_DECLARATION ';'
             | FUNCTION_DEFINITION
             | ACCESS_MODIFIER FUNCTION_DEFINITION

ACCESS_MODIFIER : PRIVATE
                | PUBLIC
                | PROTECTED
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
            for(auto [symbol, val] : unSymbols)
            {
                symTable->addSymbol(symbol, $1);
                symTable->updateSymbol(symbol, val);
            }
        }
        unSymbols.clear();
}
| ID ID;


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
     ifController = {true, 0};
    if($2->hasConflictingTypes()==true) 
                        std::cout << "Conflicts here" << '\n';
    if($2->getExpressionType()!="bool" && $2->getExpressionResult()!="0" || $2->getExpressionType()=="bool" && $2->getExpressionResult()=="true") 
        ifController.second = 1;
}

ELSE_BLOCKS : ELSE_IF_BLOCK ELSE_BLOCK
            | ELSE_BLOCK

ELSE_IF_BLOCK : ELSE_IF_STATEMENT SCOPE
              | ELSE_IF_STATEMENT SCOPE ELSE_IF_BLOCK

ELSE_BLOCK : ELSE_STATEMENT SCOPE

ELSE_IF_STATEMENT : ELSE_IF  BOOLEAN_EXPRESSION  {
    if(ifController.second) ifController.second = -1;
    if(($2->getExpressionType()!="bool" && $2->getExpressionResult()!="0" || $2->getExpressionType()=="bool" && $2->getExpressionResult()=="true") && ifController.second == 0)
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

RETURN_STATEMENT : RETURN INTEGER_EXPRESSION | RETURN BOOLEAN_EXPRESSION

ASSIGNMENT_STATEMENT :  LVALUE_ELEMENT ACCESS ID '=' INTEGER_EXPRESSION
                        | LVALUE_ELEMENT '=' INTEGER_EXPRESSION {
                                if(validateStatement()) {
                                    std::string symbol($1);
                                    SymTable * symTable = findSymTable(symbol);
                                    if(isSymbolValid(symbol, "int"))
                                    {
                                        value val = symTable->getSymbolValue(symbol);
                                        symTable->updateSymbol(symbol, $3->getExpressionResult());
                                    }
                                    else {
                                        if(globalAreaOn) 
                                            unSymbols.push_back({$1, $3->getExpressionResult()});
                                        else 
                                            yyerror(std::string("Undeclared variable ") + std::string($1));
                                    }
                         }
                    }
                    |   LVALUE_ELEMENT ACCESS ID '=' BOOLEAN_EXPRESSION
                    |   LVALUE_ELEMENT '=' BOOLEAN_EXPRESSION {
                    
                            if(validateStatement()) {
                                std::string symbol($1);
                                SymTable * symTable = findSymTable(symbol);
                                if(isSymbolValid(symbol, "bool"))
                                {
                                    value val = symTable->getSymbolValue(symbol);
                                    symTable->updateSymbol(symbol, $3->getExpressionResult());
                                }
                                else {
                                    if(globalAreaOn) 
                                        unSymbols.push_back({$1, value($3->getExpressionResult())});
                                    else 
                                        yyerror(std::string("Undeclared variable ") + std::string($1));
                                }
                        }
                    }
                    | LVALUE_ELEMENT ACCESS ID '=' ARRAY_DECLARATION
                    | LVALUE_ELEMENT '=' ARRAY_DECLARATION
                    | LVALUE_ELEMENT ACCESS ID ADD_OPERATOR '=' INTEGER_EXPRESSION
                    | LVALUE_ELEMENT ACCESS ID MUL_OPERATOR '=' INTEGER_EXPRESSION
                    | LVALUE_ELEMENT ADD_OPERATOR '=' INTEGER_EXPRESSION
                    | LVALUE_ELEMENT MUL_OPERATOR '=' INTEGER_EXPRESSION
                    | LVALUE_ELEMENT ACCESS ID INCR
                    | LVALUE_ELEMENT INCR
                    | LVALUE_ELEMENT ACCESS ID DECR
                    | LVALUE_ELEMENT DECR
                    | LVALUE_ELEMENT '=' STRING_LITERAL {
                        std::cout << "HERE!\n";
                    }
/* Print Statement Grammar  */


PRINT_STATEMENT : PRINT '(' INTEGER_EXPRESSION ')' {
                   if(validateStatement() && $3->hasConflictingTypes()==0) 
                        std::cout << $3->getExpressionResult() << '\n';
                }
                | PRINT '(' BOOLEAN_EXPRESSION ')'{
                  if(validateStatement() && $3->hasConflictingTypes()==0) 
                        std::cout << $3->getExpressionResult() << '\n';
                }
                | PRINT '(' STRING_LITERAL ')' {
                    if(validateStatement()) {
                        std::cout << $3 << '\n';
                    }
                }

/*  Type Of Statement Grammar  */

TYPE_OF_STATEMENT : TYPEOF '(' INTEGER_EXPRESSION ')' {
                    if(validateStatement() && $3->hasConflictingTypes()==0) 
                        std::cout << $3->getExpressionType() << '\n';
                }
                |   TYPEOF '(' BOOLEAN_EXPRESSION ')' {
                    if(validateStatement() && $3->hasConflictingTypes()==0) 
                        std::cout << $3->getExpressionType() << '\n';
                }

/*         RValue Expressions Area           */


/*  Boolean Expression Grammar  */

BOOLEAN_EXPRESSION :  BOOLEAN_EXPRESSION AND BOOLEAN_EXPRESSION {
                        $$ = new arb("&&","",$1,$3);
                    }
                    | BOOLEAN_EXPRESSION OR BOOLEAN_EXPRESSION {
                        $$ = new arb("||","",$1,$3);
                    }
                    | '(' BOOLEAN_EXPRESSION ')' {
                        $$ = $2;
                    }
                    | INTEGER_EXPRESSION BOOL_OPERATOR INTEGER_EXPRESSION
                    {
                    $$ = new arb($2,"",$1,$3);
                    }
                    | BOOLEAN_LITERAL { 
                        $$ = new arb("true","bool");
                    }

/*  Integer Expression Grammar      */

INTEGER_EXPRESSION :LVALUE_ELEMENT ACCESS LVALUE_ELEMENT {
                    $$ = new arb("0","int");
                }
                   | LVALUE_ELEMENT ACCESS FUNCTION_CALL {
                    $$ = new arb("0","int");
                   }
            | LVALUE_ELEMENT{
                    $$ = new arb("0","int");
                // SymTable * symTable = findSymTable(std::string($1));
                // if(symTable != NULL && symTable->isSymbolValid(std::string($1))) 
                // {
                //     value val = symTable->getSymbolValue(std::string($1));
                //     if(std::holds_alternative<int>(val))
                //         $$ = std::get<int>(val);
                // }
                // else {
                //     yyerror(std::string("Undeclared variable ") + std::string($1));
                //     $$ = 0;
                // }
            }
            | FUNCTION_CALL {
                    $$ = new arb("0","int");
            }
            | INTEGER {
                    $$ = new arb("0","int");
            }
            | INTEGER_EXPRESSION ADD_OPERATOR INTEGER_EXPRESSION{
            $$ = new arb($2,"",$1,$3);
            }
             | INTEGER_EXPRESSION MUL_OPERATOR INTEGER_EXPRESSION{
            $$ = new arb($2,"",$1,$3);
            }
            | '(' INTEGER_EXPRESSION ')' {
                    $$ = $2;
            }
            ;

/*  Function Call Grammar */

FUNCTION_CALL : ID '(' PARAMETER_LIST ')' {
    $$ = new arb($1,"int");
}

PARAMETER_LIST : PARAMETER
               | PARAMETER ',' PARAMETER_LIST
               | /* empty */

PARAMETER : INTEGER_EXPRESSION

/* Array Grammar */

ARRAY_LITERAL : ID '[' INTEGER_EXPRESSION ']' {
        $$ = $1;
}

ARRAY_DECLARATION : '[' INTEGER_EXPRESSION ';' INTEGER_EXPRESSION ']'
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
