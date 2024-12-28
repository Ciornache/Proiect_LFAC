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
"transaction" {printf("I found token transaction\n");return TRANSACTION;}
"->" {printf("I found token ->\n");return TYPE_ASSIGN;}
"asset"   { 
    printf("I found token class\n");
    return CLASS; 
}
"blockchain" { 
    printf("I found token PRIVATE\n");
    yylval.strValue = strdup(yytext);
    return PRIVATE; 
}
"in circulation"  { 
    printf("I found token PUBLIC\n");
    yylval.strValue = strdup(yytext);
    return PUBLIC; 
}
"value locked" {
    yylval.strValue = strdup(yytext); 
    return PROTECTED; 
}
"OPEN ORDER" {  return SCOPE_START;}
"STOP LOSS" {  return SCOPE_END;}
"int"|"float"|"char"|"compl"|"bool"|"string" {yylval.strValue = strdup(yytext); return TYPE;}
"true" {yylval.bValue = true; return BOOLEAN_LITERAL;}
"false" {yylval.bValue = false; return BOOLEAN_LITERAL;}
'[^']+' {yylval.cValue = yytext[1]; return CHAR_LITERAL;}
"\""[^"]*"\"" {
    char strl[1001];
    strcpy(strl, yytext + 1), 
    strl[strlen(strl)-1] = 0; 
    yylval.strValue = strdup(strl); 
    return STRING_LITERAL;}

"&&" {yylval.strValue = strdup(yytext); return AND;}
"||" {yylval.strValue = strdup(yytext); return OR;}
"!=" { /*cout << "Found relational operator: " << yytext << endl;*/ yylval.strValue = strdup(yytext); return BOOL_OPERATOR; }
"==" { /*cout << "Found relational operator: " << yytext << endl;*/ yylval.strValue = strdup(yytext); return BOOL_OPERATOR; }
">"  { /*cout << "Found relational operator: " << yytext << endl;*/ yylval.strValue = strdup(yytext);  return BOOL_OPERATOR; }
"<"  { /*cout << "Found relational operator: " << yytext << endl;*/ yylval.strValue = strdup(yytext);  return BOOL_OPERATOR; }
"<=" { /*cout << "Found relational operator: " << yytext << endl;*/  yylval.strValue = strdup(yytext); return BOOL_OPERATOR; }
">=" { /*cout << "Found relational operator: " << yytext << endl;*/ yylval.strValue = strdup(yytext);  return BOOL_OPERATOR; }
"+"  { /*cout << "Found arithmetic operator: " << yytext << endl;*/  yylval.strValue = strdup(yytext); return ADD_OPERATOR; }
"-"  { /*cout << "Found arithmetic operator: " << yytext << endl;*/  yylval.strValue = strdup(yytext); return ADD_OPERATOR; }
"*"  { /*cout << "Found arithmetic operator: " << yytext << endl;*/   yylval.strValue = strdup(yytext); return MUL_OPERATOR; }
"/"  { /*cout << "Found arithmetic operator: " << yytext << endl;*/ yylval.strValue = strdup(yytext);  return MUL_OPERATOR; }
"%"  { /*cout << "Found arithmetic operator: " << yytext << endl;*/ yylval.strValue = strdup(yytext);  return MUL_OPERATOR; }
"typeof" {return TYPEOF;}
"print" {return PRINT;}
"if" {return IF;}
"else if" {return ELSE_IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}
"++" {return INCR;}
"--" {return DECR;}
"." {return ACCESS;}
"return" {/*printf("FOUND RETURN\n");*/return RETURN;}

{letter}({letter}|{digit}|{specialCharacters})* {yylval.strValue=strdup(yytext); printf("Found ID:%s \n"
 ,yytext); return ID;}
{digit}+['.']{digit}+ {yylval.fValue = stof(std::string(yytext)); return FLOAT_LITERAL; }
{digit}+ {yylval.iValue = atoi(yytext); return INTEGER;}
\n {yylineno++;}
{commentChr}{commentChr}[^\n]*[\n] { }
[;,=\(\)\[\]] {return yytext[0];}
<<EOF>> { return 0; } 
[ \t]+ {}
. {}
%%