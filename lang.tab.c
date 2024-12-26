/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lang.y"

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


#line 92 "lang.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "lang.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_TYPE = 5,                       /* TYPE  */
  YYSYMBOL_BOOLEAN_LITERAL = 6,            /* BOOLEAN_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 7,             /* STRING_LITERAL  */
  YYSYMBOL_OPEN_WALLET = 8,                /* OPEN_WALLET  */
  YYSYMBOL_CLOSE_WALLET = 9,               /* CLOSE_WALLET  */
  YYSYMBOL_PRINT = 10,                     /* PRINT  */
  YYSYMBOL_TYPEOF = 11,                    /* TYPEOF  */
  YYSYMBOL_PRIVATE = 12,                   /* PRIVATE  */
  YYSYMBOL_PUBLIC = 13,                    /* PUBLIC  */
  YYSYMBOL_PROTECTED = 14,                 /* PROTECTED  */
  YYSYMBOL_CLASS = 15,                     /* CLASS  */
  YYSYMBOL_ACCESS = 16,                    /* ACCESS  */
  YYSYMBOL_AND = 17,                       /* AND  */
  YYSYMBOL_OR = 18,                        /* OR  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_ELSE_IF = 21,                   /* ELSE_IF  */
  YYSYMBOL_WHILE = 22,                     /* WHILE  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_SCOPE_START = 24,               /* SCOPE_START  */
  YYSYMBOL_SCOPE_END = 25,                 /* SCOPE_END  */
  YYSYMBOL_INCR = 26,                      /* INCR  */
  YYSYMBOL_DECR = 27,                      /* DECR  */
  YYSYMBOL_RETURN = 28,                    /* RETURN  */
  YYSYMBOL_BOOL_OPERATOR = 29,             /* BOOL_OPERATOR  */
  YYSYMBOL_ADD_OPERATOR = 30,              /* ADD_OPERATOR  */
  YYSYMBOL_MUL_OPERATOR = 31,              /* MUL_OPERATOR  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* '='  */
  YYSYMBOL_37_ = 37,                       /* '['  */
  YYSYMBOL_38_ = 38,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_S = 40,                         /* S  */
  YYSYMBOL_FUNCTION_DECLARATION = 41,      /* FUNCTION_DECLARATION  */
  YYSYMBOL_FUNCTION_DEFINITION = 42,       /* FUNCTION_DEFINITION  */
  YYSYMBOL_DECL_PARAMETER_SEQUENCE = 43,   /* DECL_PARAMETER_SEQUENCE  */
  YYSYMBOL_CLASS_DEFINITION = 44,          /* CLASS_DEFINITION  */
  YYSYMBOL_CLASS_MEMBER_LIST = 45,         /* CLASS_MEMBER_LIST  */
  YYSYMBOL_CLASS_MEMBER = 46,              /* CLASS_MEMBER  */
  YYSYMBOL_ACCESS_MODIFIER = 47,           /* ACCESS_MODIFIER  */
  YYSYMBOL_LINE_DECLARATION = 48,          /* LINE_DECLARATION  */
  YYSYMBOL_IDSEQUENCE = 49,                /* IDSEQUENCE  */
  YYSYMBOL_ID_SEQUENCE_ELEMENT = 50,       /* ID_SEQUENCE_ELEMENT  */
  YYSYMBOL_DECLARATIONS = 51,              /* DECLARATIONS  */
  YYSYMBOL_DECLARATIONS_ELEMENT = 52,      /* DECLARATIONS_ELEMENT  */
  YYSYMBOL_SCOPE = 53,                     /* SCOPE  */
  YYSYMBOL_BEGIN_SCOPE = 54,               /* BEGIN_SCOPE  */
  YYSYMBOL_END_SCOPE = 55,                 /* END_SCOPE  */
  YYSYMBOL_BLOCK = 56,                     /* BLOCK  */
  YYSYMBOL_FOR_BLOCK = 57,                 /* FOR_BLOCK  */
  YYSYMBOL_FOR_STATEMENT = 58,             /* FOR_STATEMENT  */
  YYSYMBOL_INIT_DECL_COMP = 59,            /* INIT_DECL_COMP  */
  YYSYMBOL_STOP_CONDITION_COMP = 60,       /* STOP_CONDITION_COMP  */
  YYSYMBOL_MODIFY_COMP = 61,               /* MODIFY_COMP  */
  YYSYMBOL_LINE_INITIALIZATION = 62,       /* LINE_INITIALIZATION  */
  YYSYMBOL_WHILE_STATEMENT = 63,           /* WHILE_STATEMENT  */
  YYSYMBOL_WHILE_BLOCK = 64,               /* WHILE_BLOCK  */
  YYSYMBOL_IF_BLOCK = 65,                  /* IF_BLOCK  */
  YYSYMBOL_IF_COMPOSITION = 66,            /* IF_COMPOSITION  */
  YYSYMBOL_IF_STRUCTURE = 67,              /* IF_STRUCTURE  */
  YYSYMBOL_IF_STATEMENT = 68,              /* IF_STATEMENT  */
  YYSYMBOL_ELSE_BLOCKS = 69,               /* ELSE_BLOCKS  */
  YYSYMBOL_ELSE_IF_BLOCK = 70,             /* ELSE_IF_BLOCK  */
  YYSYMBOL_ELSE_BLOCK = 71,                /* ELSE_BLOCK  */
  YYSYMBOL_ELSE_IF_STATEMENT = 72,         /* ELSE_IF_STATEMENT  */
  YYSYMBOL_ELSE_STATEMENT = 73,            /* ELSE_STATEMENT  */
  YYSYMBOL_MAIN = 74,                      /* MAIN  */
  YYSYMBOL_MUL_STATEMENTS = 75,            /* MUL_STATEMENTS  */
  YYSYMBOL_CODE_AREA_ELEMENT = 76,         /* CODE_AREA_ELEMENT  */
  YYSYMBOL_CODE_AREA = 77,                 /* CODE_AREA  */
  YYSYMBOL_STATEMENT = 78,                 /* STATEMENT  */
  YYSYMBOL_LVALUE_ELEMENT = 79,            /* LVALUE_ELEMENT  */
  YYSYMBOL_RETURN_STATEMENT = 80,          /* RETURN_STATEMENT  */
  YYSYMBOL_ASSIGNMENT_STATEMENT = 81,      /* ASSIGNMENT_STATEMENT  */
  YYSYMBOL_PRINT_STATEMENT = 82,           /* PRINT_STATEMENT  */
  YYSYMBOL_TYPE_OF_STATEMENT = 83,         /* TYPE_OF_STATEMENT  */
  YYSYMBOL_BOOLEAN_EXPRESSION = 84,        /* BOOLEAN_EXPRESSION  */
  YYSYMBOL_INTEGER_EXPRESSION = 85,        /* INTEGER_EXPRESSION  */
  YYSYMBOL_FUNCTION_CALL = 86,             /* FUNCTION_CALL  */
  YYSYMBOL_PARAMETER_LIST = 87,            /* PARAMETER_LIST  */
  YYSYMBOL_PARAMETER = 88,                 /* PARAMETER  */
  YYSYMBOL_ARRAY_LITERAL = 89,             /* ARRAY_LITERAL  */
  YYSYMBOL_ARRAY_DECLARATION = 90          /* ARRAY_DECLARATION  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   286

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  225

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,     2,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
       2,    36,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    72,    74,    76,    77,    78,    83,    84,
      85,    86,    88,    89,    91,    92,    93,    94,    95,    96,
      98,    99,   100,   107,   130,   133,   134,   137,   140,   145,
     146,   148,   149,   150,   151,   157,   159,   163,   171,   172,
     173,   177,   181,   185,   186,   188,   190,   193,   194,   198,
     202,   208,   212,   217,   218,   220,   229,   230,   232,   233,
     235,   237,   243,   251,   253,   254,   256,   257,   258,   259,
     262,   263,   268,   269,   270,   271,   272,   273,   276,   277,
     279,   279,   281,   282,   299,   300,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   334,   338,   342,
     350,   354,   364,   367,   370,   373,   377,   383,   386,   389,
     402,   405,   408,   411,   414,   421,   425,   426,   427,   429,
     433,   437,   438
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INTEGER",
  "TYPE", "BOOLEAN_LITERAL", "STRING_LITERAL", "OPEN_WALLET",
  "CLOSE_WALLET", "PRINT", "TYPEOF", "PRIVATE", "PUBLIC", "PROTECTED",
  "CLASS", "ACCESS", "AND", "OR", "IF", "ELSE", "ELSE_IF", "WHILE", "FOR",
  "SCOPE_START", "SCOPE_END", "INCR", "DECR", "RETURN", "BOOL_OPERATOR",
  "ADD_OPERATOR", "MUL_OPERATOR", "'('", "')'", "','", "';'", "'='", "'['",
  "']'", "$accept", "S", "FUNCTION_DECLARATION", "FUNCTION_DEFINITION",
  "DECL_PARAMETER_SEQUENCE", "CLASS_DEFINITION", "CLASS_MEMBER_LIST",
  "CLASS_MEMBER", "ACCESS_MODIFIER", "LINE_DECLARATION", "IDSEQUENCE",
  "ID_SEQUENCE_ELEMENT", "DECLARATIONS", "DECLARATIONS_ELEMENT", "SCOPE",
  "BEGIN_SCOPE", "END_SCOPE", "BLOCK", "FOR_BLOCK", "FOR_STATEMENT",
  "INIT_DECL_COMP", "STOP_CONDITION_COMP", "MODIFY_COMP",
  "LINE_INITIALIZATION", "WHILE_STATEMENT", "WHILE_BLOCK", "IF_BLOCK",
  "IF_COMPOSITION", "IF_STRUCTURE", "IF_STATEMENT", "ELSE_BLOCKS",
  "ELSE_IF_BLOCK", "ELSE_BLOCK", "ELSE_IF_STATEMENT", "ELSE_STATEMENT",
  "MAIN", "MUL_STATEMENTS", "CODE_AREA_ELEMENT", "CODE_AREA", "STATEMENT",
  "LVALUE_ELEMENT", "RETURN_STATEMENT", "ASSIGNMENT_STATEMENT",
  "PRINT_STATEMENT", "TYPE_OF_STATEMENT", "BOOLEAN_EXPRESSION",
  "INTEGER_EXPRESSION", "FUNCTION_CALL", "PARAMETER_LIST", "PARAMETER",
  "ARRAY_LITERAL", "ARRAY_DECLARATION", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-194)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-28)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     198,    13,    24,  -194,  -194,  -194,    30,    38,     9,  -194,
      12,    43,    26,    58,   198,  -194,   204,  -194,    36,   108,
    -194,  -194,    54,  -194,  -194,  -194,    80,  -194,   138,  -194,
     104,    65,   111,   122,  -194,  -194,    52,    87,    39,   158,
     113,     2,   111,   100,   133,   127,   127,   166,  -194,   127,
     105,  -194,   138,  -194,  -194,   121,   121,  -194,  -194,  -194,
    -194,   121,   160,  -194,   138,  -194,    85,   120,  -194,  -194,
    -194,  -194,  -194,   196,   185,    -1,  -194,    65,   188,    51,
    -194,   224,  -194,   197,    65,    65,  -194,  -194,   127,    65,
     137,   233,  -194,    24,  -194,   200,  -194,   162,  -194,   220,
     168,    65,    97,   127,   137,   233,   137,    72,   137,   233,
    -194,   206,  -194,  -194,   171,  -194,  -194,    83,  -194,   229,
     211,   121,   176,   237,    65,    65,  -194,  -194,  -194,   214,
     219,    81,   184,   184,    34,   213,   199,   127,   127,    65,
     222,  -194,  -194,  -194,    24,   225,  -194,  -194,   183,   184,
     232,   234,   236,   167,   218,   172,   223,    20,  -194,   231,
    -194,   238,  -194,  -194,  -194,   127,  -194,   247,  -194,   121,
     121,  -194,   190,  -194,   104,  -194,  -194,  -194,  -194,   239,
    -194,    65,    65,   137,   233,  -194,  -194,    65,  -194,  -194,
     254,   184,  -194,   240,  -194,  -194,  -194,    65,  -194,  -194,
    -194,  -194,  -194,   127,   270,   137,  -194,   253,  -194,  -194,
     184,   184,   148,  -194,  -194,   241,   137,   242,  -194,  -194,
    -194,   270,   244,  -194,  -194
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    20,    21,    22,     0,     0,     0,    34,
       0,     0,     0,     0,    29,    24,    78,    23,    25,     0,
      28,    79,     0,     1,    32,    33,     0,    31,     0,    30,
       7,     0,     0,     0,    93,    95,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,    36,     0,
       0,    69,     0,    66,    40,     0,     0,    39,    38,    51,
      52,     0,     0,    67,    70,    63,     0,     0,    76,    72,
      73,    74,    75,     0,     0,    78,   111,     0,   109,     0,
     110,    78,    26,     0,     0,     0,   106,    96,     0,     0,
      85,    83,    87,     0,    10,     0,    18,     0,    13,     0,
       0,   118,     0,     0,    55,     0,    49,     0,    81,    80,
      68,     0,    41,    50,    53,     2,    71,     0,    64,     0,
       6,     3,     0,     0,     0,     0,   120,    92,    94,     0,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,    17,    11,    12,     0,     0,    19,     9,     0,   119,
       0,   116,     0,     0,     0,     0,     0,    78,    43,     0,
      44,    47,    37,    35,    62,     0,    54,     0,    57,     0,
       0,    65,     0,    77,     7,     4,   114,   107,   108,   112,
     113,     0,     0,    84,    82,    86,   104,     0,   122,   102,
     103,   105,    16,     0,    15,     8,   115,   118,    99,    98,
      97,   101,   100,     0,     0,    61,    56,    58,    60,     5,
      88,    89,     0,    14,   117,     0,    45,    78,    48,    59,
     121,     0,     0,    46,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -194,  -194,     8,    18,   106,  -194,   178,   -94,    21,    15,
     -28,  -194,   267,  -194,   -42,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -193,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,    75,   116,  -194,  -194,  -194,   169,  -194,   -40,  -194,
      -2,  -194,   -27,  -194,  -194,   -39,   -29,   -11,    88,  -194,
    -194,   153
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,    95,    96,    74,    10,    97,    98,    99,    50,
      17,    18,    13,    14,    51,    52,   163,    53,    54,    55,
     159,   215,   222,   160,    56,    57,    58,    59,    60,    61,
     166,   167,   168,   169,   170,    62,    63,    64,    65,    66,
      78,    68,    20,    70,    71,    90,   105,    80,   150,   151,
      21,    92
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    69,    79,   143,    82,    15,   104,   106,     8,    91,
     108,   218,   111,   112,   113,    12,    15,    72,     9,   114,
     109,    11,     8,    15,   116,    69,    67,    16,   223,    12,
      19,   101,     9,    22,   101,    11,    31,    69,    23,    31,
      19,    72,    75,    76,    24,    86,    87,    25,   122,   134,
      67,   137,   138,    72,   143,   132,   133,    31,    26,   135,
     136,    27,    67,   153,   155,   140,    28,   186,    75,    76,
      32,    88,   149,   154,   156,   157,    89,    42,    39,   175,
     161,   124,   125,    40,    75,    76,    75,    86,    84,   126,
      69,    19,   183,    43,    44,   179,   180,    77,   189,   190,
      75,    76,   184,    86,   152,    19,    72,   145,   173,    73,
     191,    49,   178,    88,    81,    67,   193,   146,    89,   117,
     118,   177,   158,    85,    33,    83,   205,   207,   208,    88,
      75,    76,   102,    86,    34,    35,   119,   100,    36,    37,
     110,    41,    19,    42,    38,    48,    34,    35,    43,    44,
      36,    37,   210,   211,   137,   138,    38,    45,   212,    88,
      46,    47,    48,    93,   216,   103,    49,    93,   149,   115,
       3,     4,     5,    93,     3,     4,     5,   161,   124,   125,
       3,     4,     5,    94,   137,   138,   220,   142,    93,   137,
     138,   164,   165,   147,   161,     3,     4,     5,   107,   120,
     199,     1,    19,     2,   123,   201,   124,   125,   195,   176,
       3,     4,     5,     6,   124,   125,   127,   128,   121,    19,
     129,   130,   101,   127,   128,   144,   131,   129,   130,   124,
     125,   162,   172,   131,   187,   141,    30,   188,   -27,   -27,
      75,    31,   139,   124,   125,   174,   176,   139,   124,   125,
     181,   200,   139,   124,   125,   182,   202,   192,   -27,   -27,
     194,    31,   139,   124,   125,   196,   203,   164,   197,   198,
     125,   137,   204,   217,   165,   213,   221,   224,   148,    31,
     209,    29,   219,   206,   185,   214,   171
};

static const yytype_uint8 yycheck[] =
{
       2,    28,    31,    97,    32,     3,    45,    46,     0,    38,
      49,   204,    52,    55,    56,     0,     3,    28,     0,    61,
      49,     0,    14,     3,    64,    52,    28,     3,   221,    14,
      32,    32,    14,     3,    32,    14,    37,    64,     0,    37,
      42,    52,     3,     4,    35,     6,     7,    35,    77,    88,
      52,    17,    18,    64,   148,    84,    85,    37,    15,    88,
      89,    35,    64,   102,   103,    93,     8,    33,     3,     4,
      34,    32,   101,   102,   103,     3,    37,     5,    24,   121,
     107,    30,    31,     3,     3,     4,     3,     6,    36,    38,
     117,    93,   131,    10,    11,   124,   125,    32,   137,   138,
       3,     4,   131,     6,     7,   107,   117,    99,   119,     5,
     139,    28,   123,    32,     3,   117,   144,    99,    37,    34,
      35,   123,   107,    36,    16,     3,   165,   169,   170,    32,
       3,     4,    32,     6,    26,    27,    16,    24,    30,    31,
      35,     3,   144,     5,    36,    24,    26,    27,    10,    11,
      30,    31,   181,   182,    17,    18,    36,    19,   187,    32,
      22,    23,    24,     5,   203,    32,    28,     5,   197,     9,
      12,    13,    14,     5,    12,    13,    14,   204,    30,    31,
      12,    13,    14,    25,    17,    18,    38,    25,     5,    17,
      18,    20,    21,    25,   221,    12,    13,    14,    32,     3,
      33,     3,   204,     5,    16,    33,    30,    31,    25,    33,
      12,    13,    14,    15,    30,    31,    26,    27,    33,   221,
      30,    31,    32,    26,    27,     5,    36,    30,    31,    30,
      31,    25,     3,    36,    35,    35,    32,    38,    34,    35,
       3,    37,    29,    30,    31,    34,    33,    29,    30,    31,
      36,    33,    29,    30,    31,    36,    33,    35,    34,    35,
      35,    37,    29,    30,    31,    33,    35,    20,    34,    33,
      31,    17,    34,     3,    21,    35,    35,    33,   100,    37,
     174,    14,   207,   167,   131,   197,   117
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,    12,    13,    14,    15,    40,    41,    42,
      44,    47,    48,    51,    52,     3,     3,    49,    50,    79,
      81,    89,     3,     0,    35,    35,    15,    35,     8,    51,
      32,    37,    34,    16,    26,    27,    30,    31,    36,    24,
       3,     3,     5,    10,    11,    19,    22,    23,    24,    28,
      48,    53,    54,    56,    57,    58,    63,    64,    65,    66,
      67,    68,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    86,     5,    43,     3,     4,    32,    79,    85,
      86,     3,    49,     3,    36,    36,     6,     7,    32,    37,
      84,    85,    90,     5,    25,    41,    42,    45,    46,    47,
      24,    32,    32,    32,    84,    85,    84,    32,    84,    85,
      35,    77,    53,    53,    53,     9,    77,    34,    35,    16,
       3,    33,    85,    16,    30,    31,    38,    26,    27,    30,
      31,    36,    85,    85,    84,    85,    85,    17,    18,    29,
      49,    35,    25,    46,     5,    41,    42,    25,    45,    85,
      87,    88,     7,    84,    85,    84,    85,     3,    48,    59,
      62,    81,    25,    55,    20,    21,    69,    70,    71,    72,
      73,    75,     3,    86,    34,    53,    33,    79,    86,    85,
      85,    36,    36,    84,    85,    90,    33,    35,    38,    84,
      84,    85,    35,    49,    35,    25,    33,    34,    33,    33,
      33,    33,    33,    35,    34,    84,    71,    53,    53,    43,
      85,    85,    85,    35,    87,    60,    84,     3,    62,    70,
      38,    35,    61,    62,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    42,    43,    43,    43,    44,    44,
      44,    44,    45,    45,    46,    46,    46,    46,    46,    46,
      47,    47,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    52,    52,    53,    54,    55,    56,    56,
      56,    57,    58,    59,    59,    60,    61,    62,    62,    63,
      64,    65,    66,    67,    67,    68,    69,    69,    70,    70,
      71,    72,    73,    74,    75,    75,    76,    76,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    79,    79,
      80,    80,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    82,    82,    82,
      83,    83,    84,    84,    84,    84,    84,    85,    85,    85,
      85,    85,    85,    85,    85,    86,    87,    87,    87,    88,
      89,    90,    90
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     5,     6,     4,     2,     0,     6,     5,
       4,     5,     2,     1,     4,     3,     3,     2,     1,     2,
       1,     1,     1,     2,     2,     1,     3,     1,     1,     1,
       2,     2,     2,     2,     1,     3,     1,     1,     1,     1,
       1,     2,     8,     1,     1,     1,     1,     1,     3,     2,
       2,     1,     1,     2,     3,     2,     2,     1,     2,     3,
       2,     2,     1,     1,     2,     3,     1,     1,     2,     1,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       2,     2,     5,     3,     5,     3,     5,     3,     6,     6,
       4,     4,     4,     2,     4,     2,     3,     4,     4,     4,
       4,     4,     3,     3,     3,     3,     1,     3,     3,     1,
       1,     1,     3,     3,     3,     4,     1,     3,     0,     1,
       4,     5,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* S: DECLARATIONS OPEN_WALLET MAIN CLOSE_WALLET  */
#line 60 "lang.y"
                                               {
        printf("Program compiled succesfully!\n");
        return 0;
}
#line 1347 "lang.tab.c"
    break;

  case 23: /* LINE_DECLARATION: TYPE IDSEQUENCE  */
#line 107 "lang.y"
                                   {
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
                symTable->addSymbol(symbol, (yyvsp[-1].strValue));
                symTable->updateSymbol(symbol, val);
            }
        }
        unSymbols.clear();
}
#line 1375 "lang.tab.c"
    break;

  case 27: /* ID_SEQUENCE_ELEMENT: ID  */
#line 137 "lang.y"
                         {
                         unSymbols.push_back({(yyvsp[0].strValue), 0});
                    }
#line 1383 "lang.tab.c"
    break;

  case 36: /* BEGIN_SCOPE: SCOPE_START  */
#line 159 "lang.y"
                          {
    symTables.push_back(new SymTable);
}
#line 1391 "lang.tab.c"
    break;

  case 37: /* END_SCOPE: SCOPE_END  */
#line 163 "lang.y"
                      {
    SymTable * symTable = symTables.back();
    delete symTable;
    symTables.pop_back();
}
#line 1401 "lang.tab.c"
    break;

  case 41: /* FOR_BLOCK: FOR_STATEMENT SCOPE  */
#line 177 "lang.y"
                                {
    forController.first = false;
}
#line 1409 "lang.tab.c"
    break;

  case 42: /* FOR_STATEMENT: FOR '(' INIT_DECL_COMP ';' STOP_CONDITION_COMP ';' MODIFY_COMP ')'  */
#line 181 "lang.y"
                                                                                   {
    forController.first = true;
}
#line 1417 "lang.tab.c"
    break;

  case 49: /* WHILE_STATEMENT: WHILE BOOLEAN_EXPRESSION  */
#line 198 "lang.y"
                                           {
    whileController.first = true;
}
#line 1425 "lang.tab.c"
    break;

  case 50: /* WHILE_BLOCK: WHILE_STATEMENT SCOPE  */
#line 202 "lang.y"
                                    {
    whileController.first = false;
}
#line 1433 "lang.tab.c"
    break;

  case 51: /* IF_BLOCK: IF_COMPOSITION  */
#line 208 "lang.y"
                          {
    ifController = {false, 0};
}
#line 1441 "lang.tab.c"
    break;

  case 52: /* IF_COMPOSITION: IF_STRUCTURE  */
#line 212 "lang.y"
                               {
                      if(ifController.first)
                        ifController.second = -1;
                }
#line 1450 "lang.tab.c"
    break;

  case 55: /* IF_STATEMENT: IF BOOLEAN_EXPRESSION  */
#line 220 "lang.y"
                                     {
    ifController = {true, 0};
     ifController = {true, 0};
    if((yyvsp[0].tree)->hasConflictingTypes()==true) 
                        std::cout << "Conflicts here" << '\n';
    if((yyvsp[0].tree)->getExpressionType()!="bool" && (yyvsp[0].tree)->getExpressionResult()!="0" || (yyvsp[0].tree)->getExpressionType()=="bool" && (yyvsp[0].tree)->getExpressionResult()=="true") 
        ifController.second = 1;
}
#line 1463 "lang.tab.c"
    break;

  case 61: /* ELSE_IF_STATEMENT: ELSE_IF BOOLEAN_EXPRESSION  */
#line 237 "lang.y"
                                                 {
    if(ifController.second) ifController.second = -1;
    if(((yyvsp[0].tree)->getExpressionType()!="bool" && (yyvsp[0].tree)->getExpressionResult()!="0" || (yyvsp[0].tree)->getExpressionType()=="bool" && (yyvsp[0].tree)->getExpressionResult()=="true") && ifController.second == 0)
        ifController.second = 1;
}
#line 1473 "lang.tab.c"
    break;

  case 62: /* ELSE_STATEMENT: ELSE  */
#line 243 "lang.y"
                      {
    if(!ifController.second)
         ifController.second = 1;
}
#line 1482 "lang.tab.c"
    break;

  case 83: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' INTEGER_EXPRESSION  */
#line 282 "lang.y"
                                                                {
                                if(validateStatement()) {
                                    std::string symbol((yyvsp[-2].strValue));
                                    SymTable * symTable = findSymTable(symbol);
                                    if(isSymbolValid(symbol, "int"))
                                    {
                                        value val = symTable->getSymbolValue(symbol);
                                        symTable->updateSymbol(symbol, (yyvsp[0].tree)->getExpressionResult());
                                    }
                                    else {
                                        if(globalAreaOn) 
                                            unSymbols.push_back({(yyvsp[-2].strValue), (yyvsp[0].tree)->getExpressionResult()});
                                        else 
                                            yyerror(std::string("Undeclared variable ") + std::string((yyvsp[-2].strValue)));
                                    }
                         }
                    }
#line 1504 "lang.tab.c"
    break;

  case 85: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' BOOLEAN_EXPRESSION  */
#line 300 "lang.y"
                                                              {
                    
                            if(validateStatement()) {
                                std::string symbol((yyvsp[-2].strValue));
                                SymTable * symTable = findSymTable(symbol);
                                if(isSymbolValid(symbol, "bool"))
                                {
                                    value val = symTable->getSymbolValue(symbol);
                                    symTable->updateSymbol(symbol, (yyvsp[0].tree)->getExpressionResult());
                                }
                                else {
                                    if(globalAreaOn) 
                                        unSymbols.push_back({(yyvsp[-2].strValue), value((yyvsp[0].tree)->getExpressionResult())});
                                    else 
                                        yyerror(std::string("Undeclared variable ") + std::string((yyvsp[-2].strValue)));
                                }
                        }
                    }
#line 1527 "lang.tab.c"
    break;

  case 96: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' STRING_LITERAL  */
#line 328 "lang.y"
                                                        {
                        std::cout << "HERE!\n";
                    }
#line 1535 "lang.tab.c"
    break;

  case 97: /* PRINT_STATEMENT: PRINT '(' INTEGER_EXPRESSION ')'  */
#line 334 "lang.y"
                                                   {
                   if(validateStatement() && (yyvsp[-1].tree)->hasConflictingTypes()==0) 
                        std::cout << (yyvsp[-1].tree)->getExpressionResult() << '\n';
                }
#line 1544 "lang.tab.c"
    break;

  case 98: /* PRINT_STATEMENT: PRINT '(' BOOLEAN_EXPRESSION ')'  */
#line 338 "lang.y"
                                                  {
                  if(validateStatement() && (yyvsp[-1].tree)->hasConflictingTypes()==0) 
                        std::cout << (yyvsp[-1].tree)->getExpressionResult() << '\n';
                }
#line 1553 "lang.tab.c"
    break;

  case 99: /* PRINT_STATEMENT: PRINT '(' STRING_LITERAL ')'  */
#line 342 "lang.y"
                                               {
                    if(validateStatement()) {
                        std::cout << (yyvsp[-1].strValue) << '\n';
                    }
                }
#line 1563 "lang.tab.c"
    break;

  case 100: /* TYPE_OF_STATEMENT: TYPEOF '(' INTEGER_EXPRESSION ')'  */
#line 350 "lang.y"
                                                      {
                    if(validateStatement() && (yyvsp[-1].tree)->hasConflictingTypes()==0) 
                        std::cout << (yyvsp[-1].tree)->getExpressionType() << '\n';
                }
#line 1572 "lang.tab.c"
    break;

  case 101: /* TYPE_OF_STATEMENT: TYPEOF '(' BOOLEAN_EXPRESSION ')'  */
#line 354 "lang.y"
                                                      {
                    if(validateStatement() && (yyvsp[-1].tree)->hasConflictingTypes()==0) 
                        std::cout << (yyvsp[-1].tree)->getExpressionType() << '\n';
                }
#line 1581 "lang.tab.c"
    break;

  case 102: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION AND BOOLEAN_EXPRESSION  */
#line 364 "lang.y"
                                                                {
                        (yyval.tree) = new arb("&&","",(yyvsp[-2].tree),(yyvsp[0].tree));
                    }
#line 1589 "lang.tab.c"
    break;

  case 103: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION OR BOOLEAN_EXPRESSION  */
#line 367 "lang.y"
                                                               {
                        (yyval.tree) = new arb("||","",(yyvsp[-2].tree),(yyvsp[0].tree));
                    }
#line 1597 "lang.tab.c"
    break;

  case 104: /* BOOLEAN_EXPRESSION: '(' BOOLEAN_EXPRESSION ')'  */
#line 370 "lang.y"
                                                 {
                        (yyval.tree) = (yyvsp[-1].tree);
                    }
#line 1605 "lang.tab.c"
    break;

  case 105: /* BOOLEAN_EXPRESSION: INTEGER_EXPRESSION BOOL_OPERATOR INTEGER_EXPRESSION  */
#line 374 "lang.y"
                    {
                    (yyval.tree) = new arb((yyvsp[-1].strValue),"",(yyvsp[-2].tree),(yyvsp[0].tree));
                    }
#line 1613 "lang.tab.c"
    break;

  case 106: /* BOOLEAN_EXPRESSION: BOOLEAN_LITERAL  */
#line 377 "lang.y"
                                      { 
                        (yyval.tree) = new arb("true","bool");
                    }
#line 1621 "lang.tab.c"
    break;

  case 107: /* INTEGER_EXPRESSION: LVALUE_ELEMENT ACCESS LVALUE_ELEMENT  */
#line 383 "lang.y"
                                                         {
                    (yyval.tree) = new arb("0","int");
                }
#line 1629 "lang.tab.c"
    break;

  case 108: /* INTEGER_EXPRESSION: LVALUE_ELEMENT ACCESS FUNCTION_CALL  */
#line 386 "lang.y"
                                                         {
                    (yyval.tree) = new arb("0","int");
                   }
#line 1637 "lang.tab.c"
    break;

  case 109: /* INTEGER_EXPRESSION: LVALUE_ELEMENT  */
#line 389 "lang.y"
                            {
                SymTable * symTable = findSymTable(std::string((yyvsp[0].strValue)));
                if(symTable != NULL && symTable->isSymbolValid(std::string((yyvsp[0].strValue)))) 
                {
                    value val = symTable->getSymbolValue(std::string((yyvsp[0].strValue)));
                    if(std::holds_alternative<int>(val))
                    (yyval.tree) = new arb("0","int");
                }
                else {
                    yyerror(std::string("Undeclared variable ") + std::string((yyvsp[0].strValue)));
                    (yyval.tree) = 0;
                }
            }
#line 1655 "lang.tab.c"
    break;

  case 110: /* INTEGER_EXPRESSION: FUNCTION_CALL  */
#line 402 "lang.y"
                            {
                    (yyval.tree) = new arb("0","int");
            }
#line 1663 "lang.tab.c"
    break;

  case 111: /* INTEGER_EXPRESSION: INTEGER  */
#line 405 "lang.y"
                      {
                    (yyval.tree) = new arb("0","int");
            }
#line 1671 "lang.tab.c"
    break;

  case 112: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION ADD_OPERATOR INTEGER_EXPRESSION  */
#line 408 "lang.y"
                                                                {
            (yyval.tree) = new arb((yyvsp[-1].strValue),"",(yyvsp[-2].tree),(yyvsp[0].tree));
            }
#line 1679 "lang.tab.c"
    break;

  case 113: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION MUL_OPERATOR INTEGER_EXPRESSION  */
#line 411 "lang.y"
                                                                 {
            (yyval.tree) = new arb((yyvsp[-1].strValue),"",(yyvsp[-2].tree),(yyvsp[0].tree));
            }
#line 1687 "lang.tab.c"
    break;

  case 114: /* INTEGER_EXPRESSION: '(' INTEGER_EXPRESSION ')'  */
#line 414 "lang.y"
                                         {
                    (yyval.tree) = (yyvsp[-1].tree);
            }
#line 1695 "lang.tab.c"
    break;

  case 115: /* FUNCTION_CALL: ID '(' PARAMETER_LIST ')'  */
#line 421 "lang.y"
                                          {
    (yyval.tree) = new arb((yyvsp[-3].strValue),"int");
}
#line 1703 "lang.tab.c"
    break;

  case 120: /* ARRAY_LITERAL: ID '[' INTEGER_EXPRESSION ']'  */
#line 433 "lang.y"
                                              {
        (yyval.strValue) = (yyvsp[-3].strValue);
}
#line 1711 "lang.tab.c"
    break;


#line 1715 "lang.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 442 "lang.y"


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
