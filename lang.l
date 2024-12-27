%{
    #include "lang.tab.h"   
    #include <cstring> 
    #include <iostream>
    using namespace std;
%}
%option noyywrap

letter [a-zA-Z]
digit [0-9]
specialCharacters [_]
commentChr [/]

%%
"OPEN WALLET" {return OPEN_WALLET;}
"CLOSE WALLET" {return CLOSE_WALLET;}
"int"|"float"|"char"|"compl"|"bool"|"string" {yylval.strValue = strdup(yytext); return TYPE;}
"true" {yylval.bValue = true; return BOOLEAN_LITERAL;}
"false" {yylval.bValue = false; return BOOLEAN_LITERAL;}
"\""[^"]*"\"" {yylval.strValue = strdup(yytext); return STRING_LITERAL;}
"class"   { 
    /*printf("I found token class\n");*/
    return CLASS; 
}
"private" { 
    yylval.strValue = strdup(yytext);
    return PRIVATE; 
}
"public"  { 
    yylval.strValue = strdup(yytext);
    return PUBLIC; 
}
"protected" {
    yylval.strValue = strdup(yytext); 
    return PROTECTED; 
}
"&&" {std::cout << "FOUND AND!\n"; yylval.strValue = strdup(yytext); return AND;}
"||" {yylval.strValue = strdup(yytext); return OR;}
"!=" { /*cout << "Found relational operator: " << yytext << endl;*/ yylval.strValue = strdup(yytext); return BOOL_OPERATOR; }
"==" { /*cout << "Found relational operator: " << yytext << endl;*/ yylval.strValue = strdup(yytext); return BOOL_OPERATOR; }
">"  { /*cout << "Found relational operator: " << yytext << endl;*/ yylval.strValue = strdup(yytext);  return BOOL_OPERATOR; }
"<"  { /*cout << "Found relational operator: " << yytext << endl;*/ yylval.strValue = strdup(yytext);  return BOOL_OPERATOR; }
"<=" { /*cout << "Found relational operator: " << yytext << endl;*/  yylval.strValue = strdup(yytext); return BOOL_OPERATOR; }
">=" { /*cout << "Found relational operator: " << yytext << endl;*/ yylval.strValue = strdup(yytext);  return BOOL_OPERATOR; }
"+"  { /*cout << "Found arithmetic operator: " << yytext << endl;*/  yylval.strValue = strdup(yytext); return ADD_OPERATOR; }
"-"  { /*cout << "Found arithmetic operator: " << yytext << endl;*/  yylval.strValue = strdup(yytext); return ADD_OPERATOR; }
"*"  { /*cout << "Found arithmetic operator: " << yytext << endl;*/  yylval.strValue = strdup(yytext); return MUL_OPERATOR; }
"/"  { /*cout << "Found arithmetic operator: " << yytext << endl;*/ yylval.strValue = strdup(yytext);  return MUL_OPERATOR; }
"%"  { /*cout << "Found arithmetic operator: " << yytext << endl;*/ yylval.strValue = strdup(yytext);  return MUL_OPERATOR; }
"typeof" {return TYPEOF;}
"print" {return PRINT;}
"if" {return IF;}
"else if" {return ELSE_IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}
"{" {  return SCOPE_START;}
"}" {  return SCOPE_END;}
"++" {return INCR;}
"--" {return DECR;}
"." {return ACCESS;}
"return" {/*printf("FOUND RETURN\n");*/return RETURN;}

{letter}({letter}|{digit}|{specialCharacters})* {yylval.strValue=strdup(yytext);/* printf("Found ID:%s \n"
 ,yytext);*/ return ID;}
{digit}+ {yylval.iValue = atoi(yytext); return INTEGER;}
\n {yylineno++;}
{commentChr}{commentChr}[^\n]*[\n] { }
[;,=\(\)\[\]] {return yytext[0];}
<<EOF>> { return 0; } 
[ \t]+ {}
. {}
%%