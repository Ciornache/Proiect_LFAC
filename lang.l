%{
    #include "lang.tab.h"   
    #include <cstring> 
    #include <iostream>
    using namespace std;
%}
%option noyywrap

letter [a-zA-Z]
digit [0-9]
specialCharacters [_|-]

%%
"OPEN WALLET" {return OPEN_WALLET;}
"CLOSE WALLET" {return CLOSE_WALLET;}
"int"|"float"|"char"|"compl"|"bool" {yylval.strValue = strdup(yytext); return TYPE;}
"true" {yylval.bValue = true; return BOOLEAN_LITERAL;}
"false" {yylval.bValue = false; return BOOLEAN_LITERAL;}
"\""[^\\]*"\"" {yylval.strValue = strdup(yytext); return STRING_LITERAL;}
"class"   { 
    return CLASS; 
}
"private" { 
    return PRIVATE; 
}
"public"  { 
    return PUBLIC; 
}
"protected" { 
    return PROTECTED; 
}
"&&" {return AND;}
"||" {return OR;}
"!=" {return NEQ;}
"==" {return EQ;}
">" {return HT;}
"<" {return LT;}
"<=" {return LEQ;}
">=" {return HEQ;}
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
"+" {yylval.strValue = strdup(yytext); return PLUS;}
"-" {yylval.strValue = strdup(yytext); return MINUS;}
"*" {yylval.strValue = strdup(yytext); return MUL;}
"/" {yylval.strValue = strdup(yytext); return DIV;}
"%" {yylval.strValue = strdup(yytext);return MOD;}
"." {return ACCESS;}

{letter}({letter}|{digit}|{specialCharacters})* {yylval.strValue=strdup(yytext); return ID;}
{digit}+ {yylval.iValue = atoi(yytext); return INTEGER;}
\n {yylineno++;}
[-+;*/,=\(\)%\[\]] {return yytext[0];}
<<EOF>> { return 0; } 
[ \t]+ {}
. {}
%%