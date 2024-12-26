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
# define YYDEBUG 1
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
    IF = 274,                      /* IF  */
    ELSE = 275,                    /* ELSE  */
    ELSE_IF = 276,                 /* ELSE_IF  */
    WHILE = 277,                   /* WHILE  */
    FOR = 278,                     /* FOR  */
    SCOPE_START = 279,             /* SCOPE_START  */
    SCOPE_END = 280,               /* SCOPE_END  */
    INCR = 281,                    /* INCR  */
    DECR = 282,                    /* DECR  */
    RETURN = 283,                  /* RETURN  */
    BOOL_OPERATOR = 284,           /* BOOL_OPERATOR  */
    ADD_OPERATOR = 285,            /* ADD_OPERATOR  */
    MUL_OPERATOR = 286             /* MUL_OPERATOR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "lang.y"

    char * strValue;
    int iValue;
    bool bValue;
    class arb* tree;

#line 102 "lang.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LANG_TAB_H_INCLUDED  */
