/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LANG_TAB_H_INCLUDED
# define YY_YY_LANG_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    INTEGER = 259,                 /* INTEGER  */
    TYPE = 260,                    /* TYPE  */
    BOOLEAN_LITERAL = 261,         /* BOOLEAN_LITERAL  */
    STRING_LITERAL = 262,          /* STRING_LITERAL  */
    OPEN_WALLET = 263,             /* OPEN_WALLET  */
    CLOSE_WALLET = 264,            /* CLOSE_WALLET  */
    PRINT = 265,                   /* PRINT  */
    TYPEOF = 266,                  /* TYPEOF  */
    PRIVATE = 267,                 /* PRIVATE  */
    PUBLIC = 268,                  /* PUBLIC  */
    PROTECTED = 269,               /* PROTECTED  */
    CLASS = 270,                   /* CLASS  */
    ACCESS = 271,                  /* ACCESS  */
    AND = 272,                     /* AND  */
    OR = 273,                      /* OR  */
    EQ = 274,                      /* EQ  */
    NEQ = 275,                     /* NEQ  */
    LT = 276,                      /* LT  */
    LEQ = 277,                     /* LEQ  */
    HT = 278,                      /* HT  */
    HEQ = 279,                     /* HEQ  */
    IF = 280,                      /* IF  */
    ELSE = 281,                    /* ELSE  */
    ELSE_IF = 282,                 /* ELSE_IF  */
    WHILE = 283,                   /* WHILE  */
    FOR = 284,                     /* FOR  */
    SCOPE_START = 285,             /* SCOPE_START  */
    SCOPE_END = 286,               /* SCOPE_END  */
    PLUS = 287,                    /* PLUS  */
    MINUS = 288,                   /* MINUS  */
    MUL = 289,                     /* MUL  */
    DIV = 290,                     /* DIV  */
    MOD = 291,                     /* MOD  */
    INCR = 292,                    /* INCR  */
    DECR = 293,                    /* DECR  */
    RETURN = 294                   /* RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "lang.y"

    char * strValue;
    int iValue;
    bool bValue;

#line 109 "lang.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LANG_TAB_H_INCLUDED  */
