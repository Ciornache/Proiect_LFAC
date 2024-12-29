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
    COMPLEX_LITERAL = 260,         /* COMPLEX_LITERAL  */
    TYPE = 261,                    /* TYPE  */
    BOOLEAN_LITERAL = 262,         /* BOOLEAN_LITERAL  */
    STRING_LITERAL = 263,          /* STRING_LITERAL  */
    FLOAT_LITERAL = 264,           /* FLOAT_LITERAL  */
    CHAR_LITERAL = 265,            /* CHAR_LITERAL  */
    OPEN_WALLET = 266,             /* OPEN_WALLET  */
    CLOSE_WALLET = 267,            /* CLOSE_WALLET  */
    PRINT = 268,                   /* PRINT  */
    TYPEOF = 269,                  /* TYPEOF  */
    PRIVATE = 270,                 /* PRIVATE  */
    PUBLIC = 271,                  /* PUBLIC  */
    PROTECTED = 272,               /* PROTECTED  */
    TRANSACTION = 273,             /* TRANSACTION  */
    TYPE_ASSIGN = 274,             /* TYPE_ASSIGN  */
    CLASS = 275,                   /* CLASS  */
    ACCESS = 276,                  /* ACCESS  */
    AND = 277,                     /* AND  */
    OR = 278,                      /* OR  */
    IF = 279,                      /* IF  */
    ELSE = 280,                    /* ELSE  */
    ELSE_IF = 281,                 /* ELSE_IF  */
    WHILE = 282,                   /* WHILE  */
    FOR = 283,                     /* FOR  */
    SCOPE_START = 284,             /* SCOPE_START  */
    SCOPE_END = 285,               /* SCOPE_END  */
    INCR = 286,                    /* INCR  */
    DECR = 287,                    /* DECR  */
    RETURN = 288,                  /* RETURN  */
    BOOL_OPERATOR = 289,           /* BOOL_OPERATOR  */
    ADD_OPERATOR = 290,            /* ADD_OPERATOR  */
    MUL_OPERATOR = 291             /* MUL_OPERATOR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 52 "lang.y"

    char * strValue;
    int iValue;
    bool bValue;
    float fValue;
    char cValue;
    struct Complex* complValue;
    class arb* tree;

#line 110 "lang.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LANG_TAB_H_INCLUDED  */
