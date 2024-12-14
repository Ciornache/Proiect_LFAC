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
    std::pair<bool, int> ifController, whileController, forController;
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
  YYSYMBOL_ACCESS = 16,                    /* ACCESS  */
  YYSYMBOL_AND = 17,                       /* AND  */
  YYSYMBOL_OR = 18,                        /* OR  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_NEQ = 20,                       /* NEQ  */
  YYSYMBOL_LT = 21,                        /* LT  */
  YYSYMBOL_LEQ = 22,                       /* LEQ  */
  YYSYMBOL_HT = 23,                        /* HT  */
  YYSYMBOL_HEQ = 24,                       /* HEQ  */
  YYSYMBOL_IF = 25,                        /* IF  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_ELSE_IF = 27,                   /* ELSE_IF  */
  YYSYMBOL_WHILE = 28,                     /* WHILE  */
  YYSYMBOL_FOR = 29,                       /* FOR  */
  YYSYMBOL_SCOPE_START = 30,               /* SCOPE_START  */
  YYSYMBOL_SCOPE_END = 31,                 /* SCOPE_END  */
  YYSYMBOL_PLUS = 32,                      /* PLUS  */
  YYSYMBOL_MINUS = 33,                     /* MINUS  */
  YYSYMBOL_MUL = 34,                       /* MUL  */
  YYSYMBOL_DIV = 35,                       /* DIV  */
  YYSYMBOL_MOD = 36,                       /* MOD  */
  YYSYMBOL_INCR = 37,                      /* INCR  */
  YYSYMBOL_DECR = 38,                      /* DECR  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* ','  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* '='  */
  YYSYMBOL_44_ = 44,                       /* '['  */
  YYSYMBOL_45_ = 45,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_S = 47,                         /* S  */
  YYSYMBOL_FUNCTION_DECLARATION = 48,      /* FUNCTION_DECLARATION  */
  YYSYMBOL_DECL_PARAMETER_SEQUENCE = 49,   /* DECL_PARAMETER_SEQUENCE  */
  YYSYMBOL_CLASS_DEFINITION = 50,          /* CLASS_DEFINITION  */
  YYSYMBOL_CLASS_MEMBER_LIST = 51,         /* CLASS_MEMBER_LIST  */
  YYSYMBOL_CLASS_MEMBER = 52,              /* CLASS_MEMBER  */
  YYSYMBOL_ACCESS_MODIFIER = 53,           /* ACCESS_MODIFIER  */
  YYSYMBOL_LINE_DECLARATION = 54,          /* LINE_DECLARATION  */
  YYSYMBOL_IDSEQUENCE = 55,                /* IDSEQUENCE  */
  YYSYMBOL_ID_SEQUENCE_ELEMENT = 56,       /* ID_SEQUENCE_ELEMENT  */
  YYSYMBOL_DECLARATIONS = 57,              /* DECLARATIONS  */
  YYSYMBOL_DECLARATIONS_ELEMENT = 58,      /* DECLARATIONS_ELEMENT  */
  YYSYMBOL_SCOPE = 59,                     /* SCOPE  */
  YYSYMBOL_BEGIN_SCOPE = 60,               /* BEGIN_SCOPE  */
  YYSYMBOL_END_SCOPE = 61,                 /* END_SCOPE  */
  YYSYMBOL_BLOCK = 62,                     /* BLOCK  */
  YYSYMBOL_FOR_BLOCK = 63,                 /* FOR_BLOCK  */
  YYSYMBOL_FOR_STATEMENT = 64,             /* FOR_STATEMENT  */
  YYSYMBOL_INIT_DECL_COMP = 65,            /* INIT_DECL_COMP  */
  YYSYMBOL_STOP_CONDITION_COMP = 66,       /* STOP_CONDITION_COMP  */
  YYSYMBOL_MODIFY_COMP = 67,               /* MODIFY_COMP  */
  YYSYMBOL_LINE_INITIALIZATION = 68,       /* LINE_INITIALIZATION  */
  YYSYMBOL_WHILE_STATEMENT = 69,           /* WHILE_STATEMENT  */
  YYSYMBOL_WHILE_BLOCK = 70,               /* WHILE_BLOCK  */
  YYSYMBOL_IF_BLOCK = 71,                  /* IF_BLOCK  */
  YYSYMBOL_IF_COMPOSITION = 72,            /* IF_COMPOSITION  */
  YYSYMBOL_IF_STRUCTURE = 73,              /* IF_STRUCTURE  */
  YYSYMBOL_IF_STATEMENT = 74,              /* IF_STATEMENT  */
  YYSYMBOL_ELSE_BLOCKS = 75,               /* ELSE_BLOCKS  */
  YYSYMBOL_ELSE_IF_BLOCK = 76,             /* ELSE_IF_BLOCK  */
  YYSYMBOL_ELSE_BLOCK = 77,                /* ELSE_BLOCK  */
  YYSYMBOL_ELSE_IF_STATEMENT = 78,         /* ELSE_IF_STATEMENT  */
  YYSYMBOL_ELSE_STATEMENT = 79,            /* ELSE_STATEMENT  */
  YYSYMBOL_MAIN = 80,                      /* MAIN  */
  YYSYMBOL_CODE_AREA_ELEMENT = 81,         /* CODE_AREA_ELEMENT  */
  YYSYMBOL_CODE_AREA = 82,                 /* CODE_AREA  */
  YYSYMBOL_STATEMENT = 83,                 /* STATEMENT  */
  YYSYMBOL_ASSIGNMENT_STATEMENT = 84,      /* ASSIGNMENT_STATEMENT  */
  YYSYMBOL_PRINT_STATEMENT = 85,           /* PRINT_STATEMENT  */
  YYSYMBOL_TYPE_OF_STATEMENT = 86,         /* TYPE_OF_STATEMENT  */
  YYSYMBOL_OPERATOR = 87,                  /* OPERATOR  */
  YYSYMBOL_BOOLEAN_EXPRESSION = 88,        /* BOOLEAN_EXPRESSION  */
  YYSYMBOL_BOOLEAN_EQUATION = 89,          /* BOOLEAN_EQUATION  */
  YYSYMBOL_INTEGER_EXPRESSION = 90,        /* INTEGER_EXPRESSION  */
  YYSYMBOL_FUNCTION_CALL = 91,             /* FUNCTION_CALL  */
  YYSYMBOL_PARAMETER_LIST = 92,            /* PARAMETER_LIST  */
  YYSYMBOL_PARAMETER = 93,                 /* PARAMETER  */
  YYSYMBOL_ARRAY_LITERAL = 94              /* ARRAY_LITERAL  */
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
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   305

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      39,    40,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
       2,    43,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    69,    71,    72,    77,    78,    79,    80,
      82,    83,    85,    86,    87,    88,    90,    91,    92,    99,
     122,   125,   126,   129,   132,   137,   138,   140,   141,   142,
     148,   150,   154,   162,   163,   164,   168,   172,   176,   177,
     179,   181,   184,   185,   189,   193,   199,   203,   208,   209,
     211,   217,   218,   220,   221,   223,   225,   230,   238,   240,
     241,   242,   245,   246,   251,   252,   253,   254,   257,   258,
     275,   276,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   305,   309,   320,   323,   329,   330,   331,   332,
     333,   337,   340,   343,   348,   351,   354,   357,   361,   364,
     367,   370,   373,   379,   382,   385,   399,   403,   407,   411,
     415,   419,   423,   430,   432,   433,   435,   436,   440,   441
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
  "CLASS", "ACCESS", "AND", "OR", "EQ", "NEQ", "LT", "LEQ", "HT", "HEQ",
  "IF", "ELSE", "ELSE_IF", "WHILE", "FOR", "SCOPE_START", "SCOPE_END",
  "PLUS", "MINUS", "MUL", "DIV", "MOD", "INCR", "DECR", "'('", "')'",
  "','", "';'", "'='", "'['", "']'", "$accept", "S",
  "FUNCTION_DECLARATION", "DECL_PARAMETER_SEQUENCE", "CLASS_DEFINITION",
  "CLASS_MEMBER_LIST", "CLASS_MEMBER", "ACCESS_MODIFIER",
  "LINE_DECLARATION", "IDSEQUENCE", "ID_SEQUENCE_ELEMENT", "DECLARATIONS",
  "DECLARATIONS_ELEMENT", "SCOPE", "BEGIN_SCOPE", "END_SCOPE", "BLOCK",
  "FOR_BLOCK", "FOR_STATEMENT", "INIT_DECL_COMP", "STOP_CONDITION_COMP",
  "MODIFY_COMP", "LINE_INITIALIZATION", "WHILE_STATEMENT", "WHILE_BLOCK",
  "IF_BLOCK", "IF_COMPOSITION", "IF_STRUCTURE", "IF_STATEMENT",
  "ELSE_BLOCKS", "ELSE_IF_BLOCK", "ELSE_BLOCK", "ELSE_IF_STATEMENT",
  "ELSE_STATEMENT", "MAIN", "CODE_AREA_ELEMENT", "CODE_AREA", "STATEMENT",
  "ASSIGNMENT_STATEMENT", "PRINT_STATEMENT", "TYPE_OF_STATEMENT",
  "OPERATOR", "BOOLEAN_EXPRESSION", "BOOLEAN_EQUATION",
  "INTEGER_EXPRESSION", "FUNCTION_CALL", "PARAMETER_LIST", "PARAMETER",
  "ARRAY_LITERAL", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-180)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      95,    12,    20,  -180,  -180,  -180,    39,    50,   -30,    17,
      48,    25,    61,    95,  -180,    89,  -180,    31,  -180,    49,
    -180,  -180,  -180,    71,  -180,   168,  -180,    78,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,    90,    21,    54,    98,   170,
      83,   103,    98,    75,    76,    10,    10,    79,    88,  -180,
    -180,    87,    87,  -180,  -180,  -180,  -180,    87,   122,   168,
    -180,   101,  -180,  -180,  -180,  -180,   248,   141,   105,   -13,
    -180,  -180,    27,    27,    44,  -180,   239,  -180,  -180,    27,
     131,  -180,    20,  -180,   106,   175,  -180,   152,   186,    29,
      10,    10,   145,    44,   239,    44,    42,  -180,  -180,  -180,
     168,  -180,    77,  -180,  -180,  -180,  -180,  -180,    21,   119,
     129,  -180,   173,   260,   234,    10,    10,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
     269,   135,  -180,  -180,  -180,    20,   139,  -180,   190,   269,
    -180,   146,   144,     3,   191,    11,   215,   117,  -180,   150,
    -180,   153,   174,  -180,    10,  -180,   181,  -180,    87,    87,
      44,   239,  -180,  -180,    27,    90,   177,  -180,  -180,    27,
    -180,  -180,   201,   269,   269,   269,   269,   269,   269,   269,
     269,     5,     5,  -180,  -180,  -180,  -180,   178,  -180,  -180,
    -180,    29,  -180,  -180,  -180,  -180,    10,   216,  -180,  -180,
      44,  -180,   195,  -180,   269,  -180,   208,  -180,  -180,   187,
      44,   131,  -180,  -180,  -180,   216,   188,  -180,  -180
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    16,    17,    18,     0,     0,     0,     0,
       0,     0,     0,    25,    20,    23,    19,    21,    24,     0,
       1,    28,    29,     0,    27,     0,    26,     0,    86,    87,
      88,    89,    90,    79,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
      35,     0,     0,    34,    33,    46,    47,     0,     0,    62,
      58,     0,    64,    65,    66,    67,     0,     0,     0,   105,
     106,   102,     0,     0,    71,    93,    69,    75,    73,     0,
      23,    22,     0,     8,     0,     0,    11,     0,     0,     0,
       0,     0,   105,    50,     0,    44,     0,    61,    31,    36,
       0,    45,    48,     2,    63,    60,    78,    80,     0,     0,
       5,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,     0,    15,     9,    10,     0,     0,     7,     0,   116,
     117,     0,   114,     0,     0,     0,     0,     0,    38,     0,
      39,    42,     0,    57,     0,    49,     0,    52,     0,     0,
      70,    68,    74,    72,     0,     0,   103,   104,   112,     0,
     119,    91,    92,    96,    97,    94,    95,   101,    98,   100,
      99,   107,   109,   108,   111,   110,    14,     0,    13,     6,
     113,     0,    83,    82,    85,    84,     0,     0,    32,    30,
      56,    51,    53,    55,    76,     4,     0,    12,   115,     0,
      40,     0,    43,    54,   118,     0,     0,    41,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -180,  -180,     9,    65,  -180,   157,   -74,    35,     6,   -36,
    -180,   233,  -180,   -47,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -179,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
      52,    96,  -180,  -180,  -180,  -180,   -42,  -180,   -25,  -180,
    -180,   198,   -38,  -180,   -35,   -32,    74,  -180,   169
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,    84,    68,     9,    85,    86,    87,    48,    16,
      17,    12,    13,    99,   100,   199,    49,    50,    51,   149,
     209,   216,   150,    52,    53,    54,    55,    56,    57,   155,
     156,   157,   158,   159,    58,    59,    60,    61,    18,    63,
      64,    37,    74,    75,    94,    65,   141,   142,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      62,    76,    81,   112,    77,   101,    11,    93,    95,     8,
     102,   134,    21,    92,    70,    14,    71,   104,   212,    11,
     115,   116,     8,    15,    69,    70,    89,    71,   115,   116,
      92,    70,    69,    70,    62,    10,   217,   113,   114,   127,
     128,   129,    19,   192,   130,   147,   131,    42,    10,    72,
      20,   194,   143,   145,   139,   144,   146,   140,   152,    22,
      72,   115,   116,    23,   134,    73,    72,    24,    72,    25,
     160,   151,    38,   161,    40,    62,   162,   171,   172,    39,
     167,    66,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    67,   136,    79,     1,   187,
       2,    80,   148,   153,   154,    27,    14,     3,     4,     5,
       6,   202,   203,    88,    90,    91,   200,    98,    96,    27,
      14,    28,    29,    30,    31,    32,    33,    34,    35,   204,
      97,   103,    36,    27,   206,    28,    29,    30,    31,    32,
      33,    34,    89,   105,   110,   111,    36,    27,   132,    28,
      29,    30,    31,    32,    33,    34,   139,   135,   210,   140,
      36,   112,   164,    28,    29,    30,    31,    32,    33,    34,
     165,    41,   151,    42,    36,    82,   166,   186,    43,    44,
      82,   188,     3,     4,     5,   191,   190,     3,     4,     5,
     151,    82,   196,    45,   197,    82,    46,    47,     3,     4,
       5,    83,     3,     4,     5,   198,   133,   153,   117,   118,
     119,   120,   121,   122,   123,   124,    89,   137,   115,   211,
     207,   189,   154,   125,   126,   127,   128,   129,   218,   215,
     205,   193,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   138,    26,   125,   126,   127,
     128,   129,   201,   214,   213,   195,   117,   118,   119,   120,
     121,   122,   123,   124,   109,   208,   125,   126,   127,   128,
     129,   125,   126,   127,   128,   129,   169,   163,     0,   170,
      28,    29,    30,    31,    32,   106,   107,     0,     0,     0,
       0,   108,   125,   126,   127,   128,   129,     0,     0,     0,
     168,   125,   126,   127,   128,   129
};

static const yytype_int16 yycheck[] =
{
      25,    36,    38,    16,    36,    52,     0,    45,    46,     0,
      57,    85,    42,     3,     4,     3,     6,    59,   197,    13,
      17,    18,    13,     3,     3,     4,    39,     6,    17,    18,
       3,     4,     3,     4,    59,     0,   215,    72,    73,    34,
      35,    36,     3,    40,    79,     3,    82,     5,    13,    39,
       0,    40,    90,    91,    89,    90,    91,    89,   100,    42,
      39,    17,    18,    15,   138,    44,    39,    42,    39,     8,
     108,    96,    41,   108,     3,   100,   108,   115,   116,    30,
     112,     3,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,     5,    87,    43,     3,   135,
       5,     3,    96,    26,    27,    16,     3,    12,    13,    14,
      15,   158,   159,    30,    39,    39,   154,    30,    39,    16,
       3,    32,    33,    34,    35,    36,    37,    38,    39,   164,
      42,     9,    43,    16,   169,    32,    33,    34,    35,    36,
      37,    38,    39,    42,     3,    40,    43,    16,    42,    32,
      33,    34,    35,    36,    37,    38,   191,     5,   196,   191,
      43,    16,    43,    32,    33,    34,    35,    36,    37,    38,
      41,     3,   197,     5,    43,     5,     3,    42,    10,    11,
       5,    42,    12,    13,    14,    41,    40,    12,    13,    14,
     215,     5,    42,    25,    41,     5,    28,    29,    12,    13,
      14,    31,    12,    13,    14,    31,    31,    26,    17,    18,
      19,    20,    21,    22,    23,    24,    39,    31,    17,     3,
      42,    31,    27,    32,    33,    34,    35,    36,    40,    42,
     165,    40,    17,    18,    19,    20,    21,    22,    23,    24,
      32,    33,    34,    35,    36,    88,    13,    32,    33,    34,
      35,    36,   156,    45,   202,    40,    17,    18,    19,    20,
      21,    22,    23,    24,    66,   191,    32,    33,    34,    35,
      36,    32,    33,    34,    35,    36,    42,   108,    -1,    45,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    43,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    32,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,    12,    13,    14,    15,    47,    48,    50,
      53,    54,    57,    58,     3,     3,    55,    56,    84,     3,
       0,    42,    42,    15,    42,     8,    57,    16,    32,    33,
      34,    35,    36,    37,    38,    39,    43,    87,    41,    30,
       3,     3,     5,    10,    11,    25,    28,    29,    54,    62,
      63,    64,    69,    70,    71,    72,    73,    74,    80,    81,
      82,    83,    84,    85,    86,    91,     3,     5,    49,     3,
       4,     6,    39,    44,    88,    89,    90,    91,    94,    43,
       3,    55,     5,    31,    48,    51,    52,    53,    30,    39,
      39,    39,     3,    88,    90,    88,    39,    42,    30,    59,
      60,    59,    59,     9,    82,    42,    37,    38,    43,    87,
       3,    40,    16,    90,    90,    17,    18,    17,    18,    19,
      20,    21,    22,    23,    24,    32,    33,    34,    35,    36,
      90,    55,    42,    31,    52,     5,    48,    31,    51,    90,
      91,    92,    93,    88,    90,    88,    90,     3,    54,    65,
      68,    84,    82,    26,    27,    75,    76,    77,    78,    79,
      88,    90,    91,    94,    43,    41,     3,    91,    40,    42,
      45,    88,    88,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    42,    55,    42,    31,
      40,    41,    40,    40,    40,    40,    42,    41,    31,    61,
      88,    77,    59,    59,    90,    49,    90,    42,    92,    66,
      88,     3,    68,    76,    45,    42,    67,    68,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    49,    49,    50,    50,    50,    50,
      51,    51,    52,    52,    52,    52,    53,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    58,
      59,    60,    61,    62,    62,    62,    63,    64,    65,    65,
      66,    67,    68,    68,    69,    70,    71,    72,    73,    73,
      74,    75,    75,    76,    76,    77,    78,    79,    80,    81,
      81,    81,    82,    82,    83,    83,    83,    83,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    85,    85,    86,    86,    87,    87,    87,    87,
      87,    88,    88,    88,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    91,    92,    92,    93,    93,    94,    94
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     5,     4,     2,     6,     5,     4,     5,
       2,     1,     4,     3,     3,     2,     1,     1,     1,     2,
       2,     1,     3,     1,     1,     1,     2,     2,     2,     2,
       3,     1,     1,     1,     1,     1,     2,     8,     1,     1,
       1,     1,     1,     3,     2,     2,     1,     1,     2,     3,
       2,     2,     1,     2,     3,     2,     2,     1,     1,     1,
       2,     2,     1,     2,     1,     1,     1,     1,     5,     3,
       5,     3,     5,     3,     5,     3,     6,     4,     4,     2,
       4,     2,     4,     4,     4,     4,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     4,     1,     3,     1,     1,     5,     3
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
#line 57 "lang.y"
                                               {
        printf("Program compiled succesfully!\n");
        return 0;
}
#line 1346 "lang.tab.c"
    break;

  case 19: /* LINE_DECLARATION: TYPE IDSEQUENCE  */
#line 99 "lang.y"
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
#line 1374 "lang.tab.c"
    break;

  case 23: /* ID_SEQUENCE_ELEMENT: ID  */
#line 129 "lang.y"
                         {
                         unSymbols.push_back({(yyvsp[0].strValue), 0});
                    }
#line 1382 "lang.tab.c"
    break;

  case 31: /* BEGIN_SCOPE: SCOPE_START  */
#line 150 "lang.y"
                          {
    symTables.push_back(new SymTable);
}
#line 1390 "lang.tab.c"
    break;

  case 32: /* END_SCOPE: SCOPE_END  */
#line 154 "lang.y"
                      {
    SymTable * symTable = symTables.back();
    delete symTable;
    symTables.pop_back();
}
#line 1400 "lang.tab.c"
    break;

  case 36: /* FOR_BLOCK: FOR_STATEMENT SCOPE  */
#line 168 "lang.y"
                                {
    forController.first = false;
}
#line 1408 "lang.tab.c"
    break;

  case 37: /* FOR_STATEMENT: FOR '(' INIT_DECL_COMP ';' STOP_CONDITION_COMP ';' MODIFY_COMP ')'  */
#line 172 "lang.y"
                                                                                   {
    forController.first = true;
}
#line 1416 "lang.tab.c"
    break;

  case 44: /* WHILE_STATEMENT: WHILE BOOLEAN_EXPRESSION  */
#line 189 "lang.y"
                                           {
    whileController.first = true;
}
#line 1424 "lang.tab.c"
    break;

  case 45: /* WHILE_BLOCK: WHILE_STATEMENT SCOPE  */
#line 193 "lang.y"
                                    {
    whileController.first = false;
}
#line 1432 "lang.tab.c"
    break;

  case 46: /* IF_BLOCK: IF_COMPOSITION  */
#line 199 "lang.y"
                          {
    ifController = {false, 0};
}
#line 1440 "lang.tab.c"
    break;

  case 47: /* IF_COMPOSITION: IF_STRUCTURE  */
#line 203 "lang.y"
                               {
                      if(ifController.first)
                        ifController.second = -1;
                }
#line 1449 "lang.tab.c"
    break;

  case 50: /* IF_STATEMENT: IF BOOLEAN_EXPRESSION  */
#line 211 "lang.y"
                                     {
    ifController = {true, 0};
    if((yyvsp[0].bValue)) 
        ifController.second = 1;
}
#line 1459 "lang.tab.c"
    break;

  case 56: /* ELSE_IF_STATEMENT: ELSE_IF BOOLEAN_EXPRESSION  */
#line 225 "lang.y"
                                                 {
    if((yyvsp[0].bValue) && !ifController.second)
        ifController.second = 1;
}
#line 1468 "lang.tab.c"
    break;

  case 57: /* ELSE_STATEMENT: ELSE  */
#line 230 "lang.y"
                      {
    if(!ifController.second)
         ifController.second = 1;
}
#line 1477 "lang.tab.c"
    break;

  case 69: /* ASSIGNMENT_STATEMENT: ID '=' INTEGER_EXPRESSION  */
#line 258 "lang.y"
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
#line 1499 "lang.tab.c"
    break;

  case 71: /* ASSIGNMENT_STATEMENT: ID '=' BOOLEAN_EXPRESSION  */
#line 276 "lang.y"
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
#line 1521 "lang.tab.c"
    break;

  case 82: /* PRINT_STATEMENT: PRINT '(' INTEGER_EXPRESSION ')'  */
#line 305 "lang.y"
                                                   {
                    if(validateStatement()) 
                        std::cout << (yyvsp[-1].iValue) << '\n';
                }
#line 1530 "lang.tab.c"
    break;

  case 83: /* PRINT_STATEMENT: PRINT '(' BOOLEAN_EXPRESSION ')'  */
#line 309 "lang.y"
                                                  {
                    if(validateStatement()) 
                    {
                        if((yyvsp[-1].bValue))
                            std::cout << "true\n";
                        else std::cout << "false\n";
                    }
                }
#line 1543 "lang.tab.c"
    break;

  case 84: /* TYPE_OF_STATEMENT: TYPEOF '(' INTEGER_EXPRESSION ')'  */
#line 320 "lang.y"
                                                      {
                    std::cout << "integer\n";
                }
#line 1551 "lang.tab.c"
    break;

  case 85: /* TYPE_OF_STATEMENT: TYPEOF '(' BOOLEAN_EXPRESSION ')'  */
#line 323 "lang.y"
                                                      {
                    std::cout << "bool\n";
                }
#line 1559 "lang.tab.c"
    break;

  case 91: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION AND BOOLEAN_EXPRESSION  */
#line 337 "lang.y"
                                                                {
                            (yyval.bValue) = ((yyvsp[-2].bValue) && (yyvsp[0].bValue));
                    }
#line 1567 "lang.tab.c"
    break;

  case 92: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION OR BOOLEAN_EXPRESSION  */
#line 340 "lang.y"
                                                               {
                            (yyval.bValue) = ((yyvsp[-2].bValue) || (yyvsp[0].bValue));
                    }
#line 1575 "lang.tab.c"
    break;

  case 93: /* BOOLEAN_EXPRESSION: BOOLEAN_EQUATION  */
#line 343 "lang.y"
                                       {
                        (yyval.bValue) = (yyvsp[0].bValue);
                    }
#line 1583 "lang.tab.c"
    break;

  case 94: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION EQ INTEGER_EXPRESSION  */
#line 348 "lang.y"
                                                            {
                        (yyval.bValue) = ((yyvsp[-2].iValue) == (yyvsp[0].iValue));
                    }
#line 1591 "lang.tab.c"
    break;

  case 95: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION NEQ INTEGER_EXPRESSION  */
#line 351 "lang.y"
                                                                {
                        (yyval.bValue) = ((yyvsp[-2].iValue) != (yyvsp[0].iValue));
                    }
#line 1599 "lang.tab.c"
    break;

  case 96: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION AND INTEGER_EXPRESSION  */
#line 354 "lang.y"
                                                                {
                        (yyval.bValue) = ((yyvsp[-2].iValue) && (yyvsp[0].iValue));
                    }
#line 1607 "lang.tab.c"
    break;

  case 97: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION OR INTEGER_EXPRESSION  */
#line 357 "lang.y"
                                                               {
                        (yyval.bValue) = ((yyvsp[-2].iValue) || (yyvsp[0].iValue));
                    }
#line 1615 "lang.tab.c"
    break;

  case 98: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION LEQ INTEGER_EXPRESSION  */
#line 361 "lang.y"
                                                              {
                        (yyval.bValue) = ((yyvsp[-2].iValue) <= (yyvsp[0].iValue));
                    }
#line 1623 "lang.tab.c"
    break;

  case 99: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION HEQ INTEGER_EXPRESSION  */
#line 364 "lang.y"
                                                                {
                        (yyval.bValue) = ((yyvsp[-2].iValue) >= (yyvsp[0].iValue));
                    }
#line 1631 "lang.tab.c"
    break;

  case 100: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION HT INTEGER_EXPRESSION  */
#line 367 "lang.y"
                                                               {
                        (yyval.bValue) = ((yyvsp[-2].iValue) > (yyvsp[0].iValue));
                    }
#line 1639 "lang.tab.c"
    break;

  case 101: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION LT INTEGER_EXPRESSION  */
#line 370 "lang.y"
                                                               {
                        (yyval.bValue) = ((yyvsp[-2].iValue) < (yyvsp[0].iValue));
                    }
#line 1647 "lang.tab.c"
    break;

  case 102: /* BOOLEAN_EQUATION: BOOLEAN_LITERAL  */
#line 373 "lang.y"
                                      { 
                        (yyval.bValue) = (yyvsp[0].bValue);
                    }
#line 1655 "lang.tab.c"
    break;

  case 103: /* INTEGER_EXPRESSION: ID ACCESS ID  */
#line 379 "lang.y"
                                 {
                    (yyval.iValue) = 0;
                }
#line 1663 "lang.tab.c"
    break;

  case 104: /* INTEGER_EXPRESSION: ID ACCESS FUNCTION_CALL  */
#line 382 "lang.y"
                                            {
                        (yyval.iValue) = 0;
                   }
#line 1671 "lang.tab.c"
    break;

  case 105: /* INTEGER_EXPRESSION: ID  */
#line 385 "lang.y"
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
#line 1689 "lang.tab.c"
    break;

  case 106: /* INTEGER_EXPRESSION: INTEGER  */
#line 399 "lang.y"
                    {
                (yyval.iValue) = (yyvsp[0].iValue);
            }
#line 1697 "lang.tab.c"
    break;

  case 107: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION PLUS INTEGER_EXPRESSION  */
#line 403 "lang.y"
                                                       {
                (yyval.iValue) = (yyvsp[-2].iValue) + (yyvsp[0].iValue);
            }
#line 1705 "lang.tab.c"
    break;

  case 108: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION MUL INTEGER_EXPRESSION  */
#line 407 "lang.y"
                                                      {
                (yyval.iValue) = (yyvsp[-2].iValue) * (yyvsp[0].iValue);
            }
#line 1713 "lang.tab.c"
    break;

  case 109: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION MINUS INTEGER_EXPRESSION  */
#line 411 "lang.y"
                                                        {
                (yyval.iValue) = (yyvsp[-2].iValue) - (yyvsp[0].iValue);
            }
#line 1721 "lang.tab.c"
    break;

  case 110: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION MOD INTEGER_EXPRESSION  */
#line 415 "lang.y"
                                                      {
                (yyval.iValue) = (yyvsp[-2].iValue) % (yyvsp[0].iValue);
            }
#line 1729 "lang.tab.c"
    break;

  case 111: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION DIV INTEGER_EXPRESSION  */
#line 419 "lang.y"
                                                      {
                (yyval.iValue) = (yyvsp[-2].iValue) / (yyvsp[0].iValue);
            }
#line 1737 "lang.tab.c"
    break;

  case 112: /* INTEGER_EXPRESSION: '(' INTEGER_EXPRESSION ')'  */
#line 423 "lang.y"
                                       {
                (yyval.iValue) = (yyvsp[-1].iValue);
            }
#line 1745 "lang.tab.c"
    break;


#line 1749 "lang.tab.c"

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

#line 444 "lang.y"


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
