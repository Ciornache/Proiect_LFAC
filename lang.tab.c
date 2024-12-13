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


#line 90 "lang.tab.c"

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
  YYSYMBOL_AND = 16,                       /* AND  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_EQ = 18,                        /* EQ  */
  YYSYMBOL_NEQ = 19,                       /* NEQ  */
  YYSYMBOL_LT = 20,                        /* LT  */
  YYSYMBOL_LEQ = 21,                       /* LEQ  */
  YYSYMBOL_HT = 22,                        /* HT  */
  YYSYMBOL_HEQ = 23,                       /* HEQ  */
  YYSYMBOL_IF = 24,                        /* IF  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_ELSE_IF = 26,                   /* ELSE_IF  */
  YYSYMBOL_WHILE = 27,                     /* WHILE  */
  YYSYMBOL_FOR = 28,                       /* FOR  */
  YYSYMBOL_SCOPE_START = 29,               /* SCOPE_START  */
  YYSYMBOL_SCOPE_END = 30,                 /* SCOPE_END  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '-'  */
  YYSYMBOL_33_ = 33,                       /* '*'  */
  YYSYMBOL_34_ = 34,                       /* '/'  */
  YYSYMBOL_35_ = 35,                       /* '%'  */
  YYSYMBOL_36_ = 36,                       /* '('  */
  YYSYMBOL_37_ = 37,                       /* ')'  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* '['  */
  YYSYMBOL_40_ = 40,                       /* ';'  */
  YYSYMBOL_41_ = 41,                       /* ']'  */
  YYSYMBOL_42_ = 42,                       /* '='  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_FUNCTION_CALL = 44,             /* FUNCTION_CALL  */
  YYSYMBOL_PARAMETER_LIST = 45,            /* PARAMETER_LIST  */
  YYSYMBOL_PARAMETER = 46,                 /* PARAMETER  */
  YYSYMBOL_FUNCTION_DECLARATION = 47,      /* FUNCTION_DECLARATION  */
  YYSYMBOL_ARRAY_LITERAL = 48,             /* ARRAY_LITERAL  */
  YYSYMBOL_DECLARATIONS_ELEMENT = 49,      /* DECLARATIONS_ELEMENT  */
  YYSYMBOL_CLASS_DEFINITION = 50,          /* CLASS_DEFINITION  */
  YYSYMBOL_CLASS_MEMBER_LIST = 51,         /* CLASS_MEMBER_LIST  */
  YYSYMBOL_ACCESS_MODIFIER = 52,           /* ACCESS_MODIFIER  */
  YYSYMBOL_DECLARATIONS = 53,              /* DECLARATIONS  */
  YYSYMBOL_DECL_PARAMETER_SEQUENCE = 54,   /* DECL_PARAMETER_SEQUENCE  */
  YYSYMBOL_IDSEQUENCE = 55,                /* IDSEQUENCE  */
  YYSYMBOL_LINE_DECLARATION = 56,          /* LINE_DECLARATION  */
  YYSYMBOL_BEGIN_SCOPE = 57,               /* BEGIN_SCOPE  */
  YYSYMBOL_END_SCOPE = 58,                 /* END_SCOPE  */
  YYSYMBOL_SCOPE = 59,                     /* SCOPE  */
  YYSYMBOL_WHILE_STATEMENT = 60,           /* WHILE_STATEMENT  */
  YYSYMBOL_WHILE_BLOCK = 61,               /* WHILE_BLOCK  */
  YYSYMBOL_IF_BLOCK = 62,                  /* IF_BLOCK  */
  YYSYMBOL_IF_COMPOSITION = 63,            /* IF_COMPOSITION  */
  YYSYMBOL_IF_STRUCTURE = 64,              /* IF_STRUCTURE  */
  YYSYMBOL_ELSE_BLOCKS = 65,               /* ELSE_BLOCKS  */
  YYSYMBOL_IF_STATEMENT = 66,              /* IF_STATEMENT  */
  YYSYMBOL_ELSE_IF_STATEMENT = 67,         /* ELSE_IF_STATEMENT  */
  YYSYMBOL_ELSE_IF_BLOCK = 68,             /* ELSE_IF_BLOCK  */
  YYSYMBOL_ELSE_STATEMENT = 69,            /* ELSE_STATEMENT  */
  YYSYMBOL_ELSE_BLOCK = 70,                /* ELSE_BLOCK  */
  YYSYMBOL_MAIN = 71,                      /* MAIN  */
  YYSYMBOL_CODE_AREA_ELEMENT = 72,         /* CODE_AREA_ELEMENT  */
  YYSYMBOL_CODE_AREA = 73,                 /* CODE_AREA  */
  YYSYMBOL_BLOCK = 74,                     /* BLOCK  */
  YYSYMBOL_STATEMENT = 75,                 /* STATEMENT  */
  YYSYMBOL_ASSIGNMENT_STATEMENT = 76,      /* ASSIGNMENT_STATEMENT  */
  YYSYMBOL_PRINT_STATEMENT = 77,           /* PRINT_STATEMENT  */
  YYSYMBOL_TYPE_OF_STATEMENT = 78,         /* TYPE_OF_STATEMENT  */
  YYSYMBOL_BOOLEAN_EXPRESSION = 79,        /* BOOLEAN_EXPRESSION  */
  YYSYMBOL_BOOLEAN_EQUATION = 80,          /* BOOLEAN_EQUATION  */
  YYSYMBOL_INTEGER_EXPRESSION = 81,        /* INTEGER_EXPRESSION  */
  YYSYMBOL_S = 82                          /* S  */
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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   184

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
       2,     2,     2,     2,     2,     2,     2,    35,     2,     2,
      36,    37,    33,    31,    38,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
       2,    42,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    41,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    56,    57,    59,    60,    62,    64,    65,
      68,    69,    70,    72,    74,    76,    77,    78,    79,    82,
      83,    85,    86,    88,    89,    90,    91,    93,   118,   122,
     128,   130,   132,   134,   138,   143,   144,   146,   147,   149,
     155,   160,   161,   163,   168,   170,   172,   173,   176,   177,
     180,   181,   183,   184,   185,   188,   205,   222,   223,   225,
     229,   238,   241,   245,   248,   251,   256,   259,   262,   265,
     269,   272,   275,   278,   281,   285,   299,   303,   307,   311,
     315,   320,   324,   330
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
  "CLASS", "AND", "OR", "EQ", "NEQ", "LT", "LEQ", "HT", "HEQ", "IF",
  "ELSE", "ELSE_IF", "WHILE", "FOR", "SCOPE_START", "SCOPE_END", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'('", "')'", "','", "'['", "';'", "']'",
  "'='", "$accept", "FUNCTION_CALL", "PARAMETER_LIST", "PARAMETER",
  "FUNCTION_DECLARATION", "ARRAY_LITERAL", "DECLARATIONS_ELEMENT",
  "CLASS_DEFINITION", "CLASS_MEMBER_LIST", "ACCESS_MODIFIER",
  "DECLARATIONS", "DECL_PARAMETER_SEQUENCE", "IDSEQUENCE",
  "LINE_DECLARATION", "BEGIN_SCOPE", "END_SCOPE", "SCOPE",
  "WHILE_STATEMENT", "WHILE_BLOCK", "IF_BLOCK", "IF_COMPOSITION",
  "IF_STRUCTURE", "ELSE_BLOCKS", "IF_STATEMENT", "ELSE_IF_STATEMENT",
  "ELSE_IF_BLOCK", "ELSE_STATEMENT", "ELSE_BLOCK", "MAIN",
  "CODE_AREA_ELEMENT", "CODE_AREA", "BLOCK", "STATEMENT",
  "ASSIGNMENT_STATEMENT", "PRINT_STATEMENT", "TYPE_OF_STATEMENT",
  "BOOLEAN_EXPRESSION", "BOOLEAN_EQUATION", "INTEGER_EXPRESSION", "S", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-33)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-20)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     153,     0,   -33,   -33,   -33,   -33,    76,   -33,    -8,    16,
     -33,    14,   117,   -33,    54,   -33,     7,    72,   -33,    32,
      35,   -33,     5,    35,   -33,    58,    51,    59,    61,     9,
       9,    69,   -33,   -33,   -33,   -33,    69,    33,    72,   -33,
     -33,    60,   -33,   -33,   -33,   111,    94,     8,   -33,    96,
     -33,   -33,    13,    13,   -33,   -33,     2,   -33,   129,   -33,
     -33,     9,     9,   -33,     2,   129,     2,   -33,    72,   -33,
       3,   -33,   -33,   -33,   116,   -33,    17,    78,    45,     9,
       9,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   126,     6,    85,    10,   107,   143,
     -33,     9,   -33,    69,   149,    69,   -33,    32,   -33,   138,
     139,   137,   -33,    13,   -33,   -33,   160,   137,   137,   137,
     137,   137,   137,   137,   137,    23,    23,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,     2,   152,   -33,
     -33,   -33,   -33,    17,   102,   -33,   -33,   -33
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      18,     0,    15,    16,    17,    11,    18,    12,     0,     0,
      10,     0,     0,    27,     0,    20,     0,     0,     1,     0,
       0,    24,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,    51,    50,    33,    34,     0,     0,    48,    45,
      46,     0,    52,    53,    54,     0,     0,     0,    23,    75,
      76,    74,     0,     0,    58,    57,    56,    65,    55,    25,
      14,     0,     0,    75,    39,     0,    31,    28,     0,    32,
      35,    83,    49,    47,    22,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,     0,    36,     0,     0,     0,    38,     0,     6,     0,
       3,     5,    82,     0,     9,    63,    64,    68,    69,    66,
      67,    73,    70,    72,    71,    77,    79,    78,    81,    80,
      13,    60,    59,    62,    61,    29,    30,    40,    41,    37,
      44,    21,     2,     0,     0,    42,     4,     8
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -33,   157,    37,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     175,    75,    12,   -33,   -33,   -33,   -31,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,    46,   -33,    79,   -33,   -33,
     -32,   -33,   -33,   -13,   -33,   -33,   -28,   -33,   -22,   -33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,   108,   109,   110,     5,    55,     6,     7,    94,     8,
       9,    46,    13,    10,    68,   136,    69,    31,    32,    33,
      34,    35,   102,    36,   103,   104,   105,   106,    37,    38,
      39,    40,    41,    14,    43,    44,    56,    57,    65,    11
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    64,    66,    12,    42,    70,    72,    16,    49,    50,
      25,    51,    63,    50,    18,    51,    63,    50,    79,    80,
      49,    50,    79,    80,    17,    42,    79,    80,   100,   101,
      77,    78,    48,    95,    97,    59,    99,    45,    47,    96,
      98,    52,    71,   131,    53,    52,    20,   133,    21,    52,
      22,   115,   116,    52,   111,    42,    91,    92,    93,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   138,   137,   140,    26,    89,    90,    91,    92,
      93,     1,    27,    28,   -19,   113,   114,    60,     2,     3,
       4,   144,    23,    22,    24,    61,    29,    62,    67,    30,
      73,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    74,   112,    89,    90,    91,    92,
      93,   111,   132,    81,    82,    83,    84,    85,    86,    87,
      88,    75,    76,    89,    90,    91,    92,    93,    89,    90,
      91,    92,    93,   147,   134,    81,    82,    83,    84,    85,
      86,    87,    88,    19,   107,    20,   130,    21,     1,    22,
      89,    90,    91,    92,    93,     2,     3,     4,    89,    90,
      91,    92,    93,   135,   100,   142,    79,   143,   101,    54,
     146,    15,   141,   139,   145
};

static const yytype_uint8 yycheck[] =
{
      22,    29,    30,     3,    17,    36,    38,    15,     3,     4,
       3,     6,     3,     4,     0,     6,     3,     4,    16,    17,
       3,     4,    16,    17,     8,    38,    16,    17,    25,    26,
      52,    53,    20,    61,    62,    23,    68,     5,     3,    61,
      62,    36,     9,    37,    39,    36,    38,    37,    40,    36,
      42,    79,    80,    36,    76,    68,    33,    34,    35,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,   103,   101,   105,     3,    31,    32,    33,    34,
      35,     5,    10,    11,     8,    40,    41,    29,    12,    13,
      14,   113,    38,    42,    40,    36,    24,    36,    29,    27,
      40,    16,    17,    18,    19,    20,    21,    22,    23,    31,
      32,    33,    34,    35,     3,    37,    31,    32,    33,    34,
      35,   143,    37,    16,    17,    18,    19,    20,    21,    22,
      23,    37,    36,    31,    32,    33,    34,    35,    31,    32,
      33,    34,    35,    41,    37,    16,    17,    18,    19,    20,
      21,    22,    23,    36,    38,    38,    30,    40,     5,    42,
      31,    32,    33,    34,    35,    12,    13,    14,    31,    32,
      33,    34,    35,    30,    25,    37,    16,    38,    26,    22,
     143,     6,   107,   104,   138
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    12,    13,    14,    47,    49,    50,    52,    53,
      56,    82,     3,    55,    76,    53,    15,     8,     0,    36,
      38,    40,    42,    38,    40,     3,     3,    10,    11,    24,
      27,    60,    61,    62,    63,    64,    66,    71,    72,    73,
      74,    75,    76,    77,    78,     5,    54,     3,    55,     3,
       4,     6,    36,    39,    44,    48,    79,    80,    81,    55,
      29,    36,    36,     3,    79,    81,    79,    29,    57,    59,
      59,     9,    73,    40,     3,    37,    36,    81,    81,    16,
      17,    16,    17,    18,    19,    20,    21,    22,    23,    31,
      32,    33,    34,    35,    51,    79,    81,    79,    81,    73,
      25,    26,    65,    67,    68,    69,    70,    38,    44,    45,
      46,    81,    37,    40,    41,    79,    79,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      30,    37,    37,    37,    37,    30,    58,    79,    59,    70,
      59,    54,    37,    38,    81,    68,    45,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    48,    48,
      49,    49,    49,    50,    51,    52,    52,    52,    52,    53,
      53,    54,    54,    55,    55,    55,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    64,    65,    65,    66,
      67,    68,    68,    69,    70,    71,    72,    72,    73,    73,
      74,    74,    75,    75,    75,    76,    76,    76,    76,    77,
      77,    78,    78,    79,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    81,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     3,     1,     1,     5,     5,     3,
       1,     1,     1,     6,     0,     1,     1,     1,     0,     1,
       2,     4,     2,     3,     2,     3,     2,     2,     1,     1,
       3,     2,     2,     1,     1,     2,     3,     2,     1,     2,
       2,     2,     3,     1,     2,     1,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     4,
       4,     4,     4,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     4
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
  case 23: /* IDSEQUENCE: ID ',' IDSEQUENCE  */
#line 88 "lang.y"
                                 {unSymbols.push_back({(yyvsp[-2].strValue), 0});}
#line 1271 "lang.tab.c"
    break;

  case 24: /* IDSEQUENCE: ID ';'  */
#line 89 "lang.y"
                      {unSymbols.push_back({(yyvsp[-1].strValue), 0});}
#line 1277 "lang.tab.c"
    break;

  case 27: /* LINE_DECLARATION: TYPE IDSEQUENCE  */
#line 93 "lang.y"
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
#line 1305 "lang.tab.c"
    break;

  case 28: /* BEGIN_SCOPE: SCOPE_START  */
#line 118 "lang.y"
                          {
    symTables.push_back(new SymTable);
}
#line 1313 "lang.tab.c"
    break;

  case 29: /* END_SCOPE: SCOPE_END  */
#line 122 "lang.y"
                      {
    SymTable * symTable = symTables.back();
    delete symTable;
    symTables.pop_back();
}
#line 1323 "lang.tab.c"
    break;

  case 33: /* IF_BLOCK: IF_COMPOSITION  */
#line 134 "lang.y"
                          {
    ifController = {false, 0};
}
#line 1331 "lang.tab.c"
    break;

  case 34: /* IF_COMPOSITION: IF_STRUCTURE  */
#line 138 "lang.y"
                               {
                      if(ifController.first)
                        ifController.second = -1;
                }
#line 1340 "lang.tab.c"
    break;

  case 39: /* IF_STATEMENT: IF BOOLEAN_EXPRESSION  */
#line 149 "lang.y"
                                     {
    ifController = {true, 0};
    if((yyvsp[0].bValue)) 
        ifController.second = 1;
}
#line 1350 "lang.tab.c"
    break;

  case 40: /* ELSE_IF_STATEMENT: ELSE_IF BOOLEAN_EXPRESSION  */
#line 155 "lang.y"
                                                 {
    if((yyvsp[0].bValue) && !ifController.second)
        ifController.second = 1;
}
#line 1359 "lang.tab.c"
    break;

  case 43: /* ELSE_STATEMENT: ELSE  */
#line 163 "lang.y"
                      {
    if(!ifController.second)
         ifController.second = 1;
}
#line 1368 "lang.tab.c"
    break;

  case 55: /* ASSIGNMENT_STATEMENT: ID '=' INTEGER_EXPRESSION  */
#line 188 "lang.y"
                                                 {
                        if(validateStatement()) {
                            std::string symbol((yyvsp[-2].strValue));
                            SymTable * symTable = findSymTable(symbol);
                            if(isSymbolValid(symbol, "int"))
                            {
                                value val = symTable->getSymbolValue(symbol);
                                symTable->updateSymbol(symbol, (yyvsp[0].iValue));
                            }
                            else {
                                if(globalAreaOn) 
                                    unSymbols.push_back({(yyvsp[-2].strValue), (yyvsp[0].iValue)});
                                else 
                                    yyerror(std::string("Undeclared variable ") + std::string((yyvsp[-2].strValue)));
                            }
                    }
                 }
#line 1390 "lang.tab.c"
    break;

  case 56: /* ASSIGNMENT_STATEMENT: ID '=' BOOLEAN_EXPRESSION  */
#line 205 "lang.y"
                                                  {
                            if(validateStatement()) {
                                std::string symbol((yyvsp[-2].strValue));
                                SymTable * symTable = findSymTable(symbol);
                                if(isSymbolValid(symbol, "bool"))
                                {
                                    value val = symTable->getSymbolValue(symbol);
                                    symTable->updateSymbol(symbol, (yyvsp[0].bValue));
                                }
                                else {
                                    if(globalAreaOn) 
                                        unSymbols.push_back({(yyvsp[-2].strValue), value((yyvsp[0].bValue))});
                                    else 
                                        yyerror(std::string("Undeclared variable ") + std::string((yyvsp[-2].strValue)));
                                }
                        }
                    }
#line 1412 "lang.tab.c"
    break;

  case 59: /* PRINT_STATEMENT: PRINT '(' INTEGER_EXPRESSION ')'  */
#line 225 "lang.y"
                                                   {
                    if(validateStatement()) 
                        std::cout << (yyvsp[-1].iValue) << '\n';
                }
#line 1421 "lang.tab.c"
    break;

  case 60: /* PRINT_STATEMENT: PRINT '(' BOOLEAN_EXPRESSION ')'  */
#line 229 "lang.y"
                                                  {
                    if(validateStatement()) 
                    {
                        if((yyvsp[-1].bValue))
                            std::cout << "true\n";
                        else std::cout << "false\n";
                    }
                }
#line 1434 "lang.tab.c"
    break;

  case 61: /* TYPE_OF_STATEMENT: TYPEOF '(' INTEGER_EXPRESSION ')'  */
#line 238 "lang.y"
                                                      {
                    std::cout << "integer\n";
                }
#line 1442 "lang.tab.c"
    break;

  case 62: /* TYPE_OF_STATEMENT: TYPEOF '(' BOOLEAN_EXPRESSION ')'  */
#line 241 "lang.y"
                                                      {
                    std::cout << "bool\n";
                }
#line 1450 "lang.tab.c"
    break;

  case 63: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION AND BOOLEAN_EXPRESSION  */
#line 245 "lang.y"
                                                                {
                            (yyval.bValue) = ((yyvsp[-2].bValue) && (yyvsp[0].bValue));
                    }
#line 1458 "lang.tab.c"
    break;

  case 64: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION OR BOOLEAN_EXPRESSION  */
#line 248 "lang.y"
                                                               {
                            (yyval.bValue) = ((yyvsp[-2].bValue) || (yyvsp[0].bValue));
                    }
#line 1466 "lang.tab.c"
    break;

  case 65: /* BOOLEAN_EXPRESSION: BOOLEAN_EQUATION  */
#line 251 "lang.y"
                                       {
                        (yyval.bValue) = (yyvsp[0].bValue);
                    }
#line 1474 "lang.tab.c"
    break;

  case 66: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION EQ INTEGER_EXPRESSION  */
#line 256 "lang.y"
                                                            {
                        (yyval.bValue) = ((yyvsp[-2].iValue) == (yyvsp[0].iValue));
                    }
#line 1482 "lang.tab.c"
    break;

  case 67: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION NEQ INTEGER_EXPRESSION  */
#line 259 "lang.y"
                                                                {
                        (yyval.bValue) = ((yyvsp[-2].iValue) != (yyvsp[0].iValue));
                    }
#line 1490 "lang.tab.c"
    break;

  case 68: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION AND INTEGER_EXPRESSION  */
#line 262 "lang.y"
                                                                {
                        (yyval.bValue) = ((yyvsp[-2].iValue) && (yyvsp[0].iValue));
                    }
#line 1498 "lang.tab.c"
    break;

  case 69: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION OR INTEGER_EXPRESSION  */
#line 265 "lang.y"
                                                               {
                        (yyval.bValue) = ((yyvsp[-2].iValue) || (yyvsp[0].iValue));
                    }
#line 1506 "lang.tab.c"
    break;

  case 70: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION LEQ INTEGER_EXPRESSION  */
#line 269 "lang.y"
                                                              {
                        (yyval.bValue) = ((yyvsp[-2].iValue) <= (yyvsp[0].iValue));
                    }
#line 1514 "lang.tab.c"
    break;

  case 71: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION HEQ INTEGER_EXPRESSION  */
#line 272 "lang.y"
                                                                {
                        (yyval.bValue) = ((yyvsp[-2].iValue) >= (yyvsp[0].iValue));
                    }
#line 1522 "lang.tab.c"
    break;

  case 72: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION HT INTEGER_EXPRESSION  */
#line 275 "lang.y"
                                                               {
                        (yyval.bValue) = ((yyvsp[-2].iValue) > (yyvsp[0].iValue));
                    }
#line 1530 "lang.tab.c"
    break;

  case 73: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION LT INTEGER_EXPRESSION  */
#line 278 "lang.y"
                                                               {
                        (yyval.bValue) = ((yyvsp[-2].iValue) < (yyvsp[0].iValue));
                    }
#line 1538 "lang.tab.c"
    break;

  case 74: /* BOOLEAN_EQUATION: BOOLEAN_LITERAL  */
#line 281 "lang.y"
                                      { 
                        (yyval.bValue) = (yyvsp[0].bValue);
                    }
#line 1546 "lang.tab.c"
    break;

  case 75: /* INTEGER_EXPRESSION: ID  */
#line 285 "lang.y"
                        {
                SymTable * symTable = findSymTable(std::string((yyvsp[0].strValue)));
                if(symTable != NULL && symTable->isSymbolValid(std::string((yyvsp[0].strValue)))) 
                {
                    value val = symTable->getSymbolValue(std::string((yyvsp[0].strValue)));
                    if(std::holds_alternative<int>(val))
                        (yyval.iValue) = std::get<int>(val);
                }
                else {
                    yyerror(std::string("Undeclared variable ") + std::string((yyvsp[0].strValue)));
                    (yyval.iValue) = 0;
                }
            }
#line 1564 "lang.tab.c"
    break;

  case 76: /* INTEGER_EXPRESSION: INTEGER  */
#line 299 "lang.y"
                    {
                (yyval.iValue) = (yyvsp[0].iValue);
            }
#line 1572 "lang.tab.c"
    break;

  case 77: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION '+' INTEGER_EXPRESSION  */
#line 303 "lang.y"
                                                      {
                (yyval.iValue) = (yyvsp[-2].iValue) + (yyvsp[0].iValue);
            }
#line 1580 "lang.tab.c"
    break;

  case 78: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION '*' INTEGER_EXPRESSION  */
#line 307 "lang.y"
                                                      {
                (yyval.iValue) = (yyvsp[-2].iValue) * (yyvsp[0].iValue);
            }
#line 1588 "lang.tab.c"
    break;

  case 79: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION '-' INTEGER_EXPRESSION  */
#line 311 "lang.y"
                                                      {
                (yyval.iValue) = (yyvsp[-2].iValue) - (yyvsp[0].iValue);
            }
#line 1596 "lang.tab.c"
    break;

  case 80: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION '%' INTEGER_EXPRESSION  */
#line 315 "lang.y"
                                                      {
                std::cout << "AICI!\n";
                (yyval.iValue) = (yyvsp[-2].iValue) % (yyvsp[0].iValue);
            }
#line 1605 "lang.tab.c"
    break;

  case 81: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION '/' INTEGER_EXPRESSION  */
#line 320 "lang.y"
                                                      {
                (yyval.iValue) = (yyvsp[-2].iValue) / (yyvsp[0].iValue);
            }
#line 1613 "lang.tab.c"
    break;

  case 82: /* INTEGER_EXPRESSION: '(' INTEGER_EXPRESSION ')'  */
#line 324 "lang.y"
                                       {
                (yyval.iValue) = (yyvsp[-1].iValue);
            }
#line 1621 "lang.tab.c"
    break;

  case 83: /* S: DECLARATIONS OPEN_WALLET MAIN CLOSE_WALLET  */
#line 330 "lang.y"
                                               {
        printf("Program compiled succesfully!\n");
        return 0;
}
#line 1630 "lang.tab.c"
    break;


#line 1634 "lang.tab.c"

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

#line 335 "lang.y"


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
