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
  YYSYMBOL_RETURN = 39,                    /* RETURN  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* '='  */
  YYSYMBOL_45_ = 45,                       /* '['  */
  YYSYMBOL_46_ = 46,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_S = 48,                         /* S  */
  YYSYMBOL_FUNCTION_DECLARATION = 49,      /* FUNCTION_DECLARATION  */
  YYSYMBOL_FUNCTION_DEFINITION = 50,       /* FUNCTION_DEFINITION  */
  YYSYMBOL_DECL_PARAMETER_SEQUENCE = 51,   /* DECL_PARAMETER_SEQUENCE  */
  YYSYMBOL_CLASS_DEFINITION = 52,          /* CLASS_DEFINITION  */
  YYSYMBOL_CLASS_MEMBER_LIST = 53,         /* CLASS_MEMBER_LIST  */
  YYSYMBOL_CLASS_MEMBER = 54,              /* CLASS_MEMBER  */
  YYSYMBOL_ACCESS_MODIFIER = 55,           /* ACCESS_MODIFIER  */
  YYSYMBOL_LINE_DECLARATION = 56,          /* LINE_DECLARATION  */
  YYSYMBOL_IDSEQUENCE = 57,                /* IDSEQUENCE  */
  YYSYMBOL_ID_SEQUENCE_ELEMENT = 58,       /* ID_SEQUENCE_ELEMENT  */
  YYSYMBOL_DECLARATIONS = 59,              /* DECLARATIONS  */
  YYSYMBOL_DECLARATIONS_ELEMENT = 60,      /* DECLARATIONS_ELEMENT  */
  YYSYMBOL_SCOPE = 61,                     /* SCOPE  */
  YYSYMBOL_BEGIN_SCOPE = 62,               /* BEGIN_SCOPE  */
  YYSYMBOL_END_SCOPE = 63,                 /* END_SCOPE  */
  YYSYMBOL_BLOCK = 64,                     /* BLOCK  */
  YYSYMBOL_FOR_BLOCK = 65,                 /* FOR_BLOCK  */
  YYSYMBOL_FOR_STATEMENT = 66,             /* FOR_STATEMENT  */
  YYSYMBOL_INIT_DECL_COMP = 67,            /* INIT_DECL_COMP  */
  YYSYMBOL_STOP_CONDITION_COMP = 68,       /* STOP_CONDITION_COMP  */
  YYSYMBOL_MODIFY_COMP = 69,               /* MODIFY_COMP  */
  YYSYMBOL_LINE_INITIALIZATION = 70,       /* LINE_INITIALIZATION  */
  YYSYMBOL_WHILE_STATEMENT = 71,           /* WHILE_STATEMENT  */
  YYSYMBOL_WHILE_BLOCK = 72,               /* WHILE_BLOCK  */
  YYSYMBOL_IF_BLOCK = 73,                  /* IF_BLOCK  */
  YYSYMBOL_IF_COMPOSITION = 74,            /* IF_COMPOSITION  */
  YYSYMBOL_IF_STRUCTURE = 75,              /* IF_STRUCTURE  */
  YYSYMBOL_IF_STATEMENT = 76,              /* IF_STATEMENT  */
  YYSYMBOL_ELSE_BLOCKS = 77,               /* ELSE_BLOCKS  */
  YYSYMBOL_ELSE_IF_BLOCK = 78,             /* ELSE_IF_BLOCK  */
  YYSYMBOL_ELSE_BLOCK = 79,                /* ELSE_BLOCK  */
  YYSYMBOL_ELSE_IF_STATEMENT = 80,         /* ELSE_IF_STATEMENT  */
  YYSYMBOL_ELSE_STATEMENT = 81,            /* ELSE_STATEMENT  */
  YYSYMBOL_MAIN = 82,                      /* MAIN  */
  YYSYMBOL_MUL_STATEMENTS = 83,            /* MUL_STATEMENTS  */
  YYSYMBOL_CODE_AREA_ELEMENT = 84,         /* CODE_AREA_ELEMENT  */
  YYSYMBOL_CODE_AREA = 85,                 /* CODE_AREA  */
  YYSYMBOL_STATEMENT = 86,                 /* STATEMENT  */
  YYSYMBOL_LVALUE_ELEMENT = 87,            /* LVALUE_ELEMENT  */
  YYSYMBOL_RETURN_STATEMENT = 88,          /* RETURN_STATEMENT  */
  YYSYMBOL_ASSIGNMENT_STATEMENT = 89,      /* ASSIGNMENT_STATEMENT  */
  YYSYMBOL_PRINT_STATEMENT = 90,           /* PRINT_STATEMENT  */
  YYSYMBOL_TYPE_OF_STATEMENT = 91,         /* TYPE_OF_STATEMENT  */
  YYSYMBOL_OPERATOR = 92,                  /* OPERATOR  */
  YYSYMBOL_BOOLEAN_EXPRESSION = 93,        /* BOOLEAN_EXPRESSION  */
  YYSYMBOL_BOOLEAN_EQUATION = 94,          /* BOOLEAN_EQUATION  */
  YYSYMBOL_INTEGER_EXPRESSION = 95,        /* INTEGER_EXPRESSION  */
  YYSYMBOL_FUNCTION_CALL = 96,             /* FUNCTION_CALL  */
  YYSYMBOL_PARAMETER_LIST = 97,            /* PARAMETER_LIST  */
  YYSYMBOL_PARAMETER = 98,                 /* PARAMETER  */
  YYSYMBOL_ARRAY_LITERAL = 99,             /* ARRAY_LITERAL  */
  YYSYMBOL_ARRAY_DECLARATION = 100         /* ARRAY_DECLARATION  */
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
#define YYLAST   363

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  244

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      40,    41,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    71,    73,    75,    76,    77,    82,    83,
      84,    85,    87,    88,    90,    91,    92,    93,    94,    95,
      97,    98,    99,   106,   129,   132,   133,   136,   139,   144,
     145,   147,   148,   149,   150,   156,   158,   162,   170,   171,
     172,   176,   180,   184,   185,   187,   189,   192,   193,   197,
     201,   207,   211,   216,   217,   219,   225,   226,   228,   229,
     231,   233,   239,   247,   249,   250,   252,   253,   254,   255,
     258,   259,   264,   265,   266,   267,   268,   269,   272,   273,
     275,   277,   278,   295,   296,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   327,   331,   339,   347,   352,   360,
     361,   362,   363,   364,   368,   371,   374,   377,   382,   385,
     388,   391,   395,   398,   401,   404,   407,   413,   416,   419,
     432,   435,   438,   441,   444,   447,   450,   453,   460,   464,
     465,   466,   468,   472,   476,   477
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
  "PLUS", "MINUS", "MUL", "DIV", "MOD", "INCR", "DECR", "RETURN", "'('",
  "')'", "','", "';'", "'='", "'['", "']'", "$accept", "S",
  "FUNCTION_DECLARATION", "FUNCTION_DEFINITION", "DECL_PARAMETER_SEQUENCE",
  "CLASS_DEFINITION", "CLASS_MEMBER_LIST", "CLASS_MEMBER",
  "ACCESS_MODIFIER", "LINE_DECLARATION", "IDSEQUENCE",
  "ID_SEQUENCE_ELEMENT", "DECLARATIONS", "DECLARATIONS_ELEMENT", "SCOPE",
  "BEGIN_SCOPE", "END_SCOPE", "BLOCK", "FOR_BLOCK", "FOR_STATEMENT",
  "INIT_DECL_COMP", "STOP_CONDITION_COMP", "MODIFY_COMP",
  "LINE_INITIALIZATION", "WHILE_STATEMENT", "WHILE_BLOCK", "IF_BLOCK",
  "IF_COMPOSITION", "IF_STRUCTURE", "IF_STATEMENT", "ELSE_BLOCKS",
  "ELSE_IF_BLOCK", "ELSE_BLOCK", "ELSE_IF_STATEMENT", "ELSE_STATEMENT",
  "MAIN", "MUL_STATEMENTS", "CODE_AREA_ELEMENT", "CODE_AREA", "STATEMENT",
  "LVALUE_ELEMENT", "RETURN_STATEMENT", "ASSIGNMENT_STATEMENT",
  "PRINT_STATEMENT", "TYPE_OF_STATEMENT", "OPERATOR", "BOOLEAN_EXPRESSION",
  "BOOLEAN_EQUATION", "INTEGER_EXPRESSION", "FUNCTION_CALL",
  "PARAMETER_LIST", "PARAMETER", "ARRAY_LITERAL", "ARRAY_DECLARATION", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-164)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-28)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     166,     7,    35,  -164,  -164,  -164,    47,    59,    28,  -164,
      65,    64,    67,    54,   166,  -164,   102,  -164,    56,   154,
    -164,  -164,    92,  -164,  -164,  -164,   113,  -164,   138,  -164,
     141,    20,   159,   161,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,    36,   121,   145,   142,    13,   159,   153,   155,    30,
      30,   156,  -164,    20,   140,  -164,   138,  -164,  -164,   164,
     164,  -164,  -164,  -164,  -164,   164,   193,  -164,   138,  -164,
     109,   183,  -164,  -164,  -164,  -164,  -164,   202,   163,    43,
    -164,    20,   190,   201,  -164,    78,  -164,   315,  -164,  -164,
      30,    20,   143,  -164,   297,  -164,    20,    35,  -164,   171,
    -164,   195,  -164,   219,   198,    20,   133,    30,   143,   297,
     143,    89,   290,  -164,   194,  -164,  -164,   148,  -164,  -164,
      46,  -164,   225,   206,   164,   322,   248,    20,    20,    20,
      20,    20,  -164,  -164,  -164,    42,   208,    10,   222,   241,
      30,    30,    20,    20,    20,    20,    20,    20,    20,    20,
     290,   207,  -164,  -164,  -164,    35,   210,  -164,  -164,   218,
     290,   220,   217,   221,    14,   247,    55,   272,    19,  -164,
     229,  -164,   236,  -164,  -164,  -164,    30,  -164,   234,  -164,
     164,   164,  -164,   302,  -164,   141,  -164,  -164,  -164,  -164,
     120,   120,  -164,  -164,  -164,   143,   297,  -164,    20,  -164,
      20,  -164,  -164,   268,   290,   290,   290,   290,   290,   290,
     290,   290,  -164,   243,  -164,  -164,  -164,    20,  -164,  -164,
    -164,  -164,  -164,    30,   299,   143,  -164,   276,  -164,  -164,
     290,   265,  -164,  -164,   266,   143,   267,  -164,  -164,  -164,
     299,   269,  -164,  -164
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    20,    21,    22,     0,     0,     0,    34,
       0,     0,     0,     0,    29,    24,    78,    23,    25,     0,
      28,    79,     0,     1,    32,    33,     0,    31,     0,    30,
       7,     0,     0,     0,    99,   100,   101,   102,   103,    90,
      92,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,    36,     0,     0,    69,     0,    66,    40,     0,
       0,    39,    38,    51,    52,     0,     0,    67,    70,    63,
       0,     0,    76,    72,    73,    74,    75,     0,     0,    78,
     121,     0,   119,     0,   120,    78,    26,     0,   116,    93,
       0,     0,    84,   106,    82,    86,     0,     0,    10,     0,
      18,     0,    13,     0,     0,   131,     0,     0,    55,     0,
      49,     0,    80,    68,     0,    41,    50,    53,     2,    71,
       0,    64,     0,     6,     3,     0,     0,     0,     0,     0,
       0,     0,   133,    89,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,     0,    17,    11,    12,     0,     0,    19,     9,     0,
     132,     0,   129,     0,     0,     0,     0,     0,    78,    43,
       0,    44,    47,    37,    35,    62,     0,    54,     0,    57,
       0,     0,    65,     0,    77,     7,     4,   127,   117,   118,
     122,   124,   123,   126,   125,    83,    81,    85,     0,   107,
       0,   135,   104,   105,   110,   111,   108,   109,   115,   112,
     114,   113,    16,     0,    15,     8,   128,   131,    96,    95,
      94,    98,    97,     0,     0,    61,    56,    58,    60,     5,
      87,     0,    14,   130,     0,    45,    78,    48,    59,   134,
       0,     0,    46,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,     3,     4,   158,  -164,   223,   -96,    86,     6,
     -30,  -164,   314,  -164,   -46,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -163,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,   114,   167,  -164,  -164,  -164,   224,  -164,   -47,  -164,
      -2,  -164,   -27,  -164,  -164,   -79,   -38,  -164,   -16,   -21,
     144,  -164,  -164,   227
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,    99,   100,    78,    10,   101,   102,   103,    54,
      17,    18,    13,    14,    55,    56,   174,    57,    58,    59,
     170,   234,   241,   171,    60,    61,    62,    63,    64,    65,
     177,   178,   179,   180,   181,    66,    67,    68,    69,    70,
      82,    72,    20,    74,    75,    42,    92,    93,   109,    84,
     161,   162,    21,    95
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    73,    86,     8,     9,   154,    12,    76,   136,   114,
      15,   108,   110,   115,   116,    83,    15,     8,     9,   117,
      12,   119,    15,    79,    80,    94,    71,   140,   141,    73,
      19,   140,   141,    79,    80,    76,    88,   112,    16,    79,
      80,    73,    88,    89,    19,    79,    80,    76,    88,    79,
      22,   199,   137,   105,    71,   219,    47,    48,    31,    23,
      81,   237,    28,   154,    31,   125,    71,   151,   164,   166,
      90,    24,   140,   141,   138,   139,    90,   242,   186,    26,
     150,    91,    90,   105,   172,    53,    11,    91,    31,   160,
     165,   167,   168,    73,    46,    19,   221,   195,    32,    76,
      11,   184,   202,   203,   136,   189,   156,   157,    25,    19,
      27,   190,   191,   192,   193,   194,    44,   169,    71,   196,
     -27,   -27,    43,    31,   188,   213,   204,   205,   206,   207,
     208,   209,   210,   211,   227,   228,    79,    80,   225,    88,
     163,    45,    30,    46,   -27,   -27,    77,    31,    47,    48,
      97,   120,   121,    19,   129,   130,   131,     3,     4,     5,
     140,   141,    85,    49,    87,    96,    50,    51,    52,     1,
      33,     2,   104,    90,   175,   176,    98,    53,     3,     4,
       5,     6,   230,   113,   231,   235,    34,    35,    36,    37,
      38,    39,    40,   106,    52,   107,   111,   172,    41,   122,
      97,   160,   118,    97,   124,   123,   126,     3,     4,     5,
       3,     4,     5,   172,   152,    34,    35,    36,    37,    38,
      39,    40,    19,    97,   155,   173,   153,    41,   183,   158,
       3,     4,     5,   127,   128,   129,   130,   131,    19,   142,
     143,   144,   145,   146,   147,   148,   149,   132,   185,   215,
     212,    79,   198,   214,   127,   128,   129,   130,   131,   217,
     175,   216,   218,   187,   142,   143,   144,   145,   146,   147,
     148,   149,   223,   127,   128,   129,   130,   131,   224,   127,
     128,   129,   130,   131,   200,   140,   232,   201,   220,   142,
     143,   144,   145,   146,   147,   148,   149,   127,   128,   129,
     130,   131,   236,   176,   127,   128,   129,   130,   131,   240,
     243,   239,    31,   222,   142,   143,   144,   145,   146,   147,
     148,   149,   127,   128,   129,   130,   131,   159,    29,   127,
     128,   129,   130,   131,    34,    35,    36,    37,    38,   133,
     134,   238,   105,   229,   182,   226,   135,    34,    35,    36,
      37,    38,   133,   134,   127,   128,   129,   130,   131,   135,
       0,   233,   197,   187
};

static const yytype_int16 yycheck[] =
{
       2,    28,    32,     0,     0,   101,     0,    28,    87,    56,
       3,    49,    50,    59,    60,    31,     3,    14,    14,    65,
      14,    68,     3,     3,     4,    41,    28,    17,    18,    56,
      32,    17,    18,     3,     4,    56,     6,    53,     3,     3,
       4,    68,     6,     7,    46,     3,     4,    68,     6,     3,
       3,    41,    90,    40,    56,    41,    10,    11,    45,     0,
      40,   224,     8,   159,    45,    81,    68,    97,   106,   107,
      40,    43,    17,    18,    90,    91,    40,   240,   124,    15,
      96,    45,    40,    40,   111,    39,     0,    45,    45,   105,
     106,   107,     3,   120,     5,    97,    41,   135,    42,   120,
      14,   122,   140,   141,   183,   126,   103,   103,    43,   111,
      43,   127,   128,   129,   130,   131,     3,   111,   120,   135,
      42,    43,    30,    45,   126,   155,   142,   143,   144,   145,
     146,   147,   148,   149,   180,   181,     3,     4,   176,     6,
       7,     3,    40,     5,    42,    43,     5,    45,    10,    11,
       5,    42,    43,   155,    34,    35,    36,    12,    13,    14,
      17,    18,     3,    25,     3,    44,    28,    29,    30,     3,
      16,     5,    30,    40,    26,    27,    31,    39,    12,    13,
      14,    15,   198,    43,   200,   223,    32,    33,    34,    35,
      36,    37,    38,    40,    30,    40,    40,   224,    44,    16,
       5,   217,     9,     5,    41,     3,    16,    12,    13,    14,
      12,    13,    14,   240,    43,    32,    33,    34,    35,    36,
      37,    38,   224,     5,     5,    31,    31,    44,     3,    31,
      12,    13,    14,    32,    33,    34,    35,    36,   240,    17,
      18,    19,    20,    21,    22,    23,    24,    46,    42,    31,
      43,     3,    44,    43,    32,    33,    34,    35,    36,    42,
      26,    41,    41,    41,    17,    18,    19,    20,    21,    22,
      23,    24,    43,    32,    33,    34,    35,    36,    42,    32,
      33,    34,    35,    36,    43,    17,    43,    46,    41,    17,
      18,    19,    20,    21,    22,    23,    24,    32,    33,    34,
      35,    36,     3,    27,    32,    33,    34,    35,    36,    43,
      41,    46,    45,    41,    17,    18,    19,    20,    21,    22,
      23,    24,    32,    33,    34,    35,    36,   104,    14,    32,
      33,    34,    35,    36,    32,    33,    34,    35,    36,    37,
      38,   227,    40,   185,   120,   178,    44,    32,    33,    34,
      35,    36,    37,    38,    32,    33,    34,    35,    36,    44,
      -1,   217,   135,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,    12,    13,    14,    15,    48,    49,    50,
      52,    55,    56,    59,    60,     3,     3,    57,    58,    87,
      89,    99,     3,     0,    43,    43,    15,    43,     8,    59,
      40,    45,    42,    16,    32,    33,    34,    35,    36,    37,
      38,    44,    92,    30,     3,     3,     5,    10,    11,    25,
      28,    29,    30,    39,    56,    61,    62,    64,    65,    66,
      71,    72,    73,    74,    75,    76,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    96,     5,    51,     3,
       4,    40,    87,    95,    96,     3,    57,     3,     6,     7,
      40,    45,    93,    94,    95,   100,    44,     5,    31,    49,
      50,    53,    54,    55,    30,    40,    40,    40,    93,    95,
      93,    40,    95,    43,    85,    61,    61,    61,     9,    85,
      42,    43,    16,     3,    41,    95,    16,    32,    33,    34,
      35,    36,    46,    37,    38,    44,    92,    93,    95,    95,
      17,    18,    17,    18,    19,    20,    21,    22,    23,    24,
      95,    57,    43,    31,    54,     5,    49,    50,    31,    53,
      95,    97,    98,     7,    93,    95,    93,    95,     3,    56,
      67,    70,    89,    31,    63,    26,    27,    77,    78,    79,
      80,    81,    83,     3,    96,    42,    61,    41,    87,    96,
      95,    95,    95,    95,    95,    93,    95,   100,    44,    41,
      43,    46,    93,    93,    95,    95,    95,    95,    95,    95,
      95,    95,    43,    57,    43,    31,    41,    42,    41,    41,
      41,    41,    41,    43,    42,    93,    79,    61,    61,    51,
      95,    95,    43,    97,    68,    93,     3,    70,    78,    46,
      43,    69,    70,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    50,    51,    51,    51,    52,    52,
      52,    52,    53,    53,    54,    54,    54,    54,    54,    54,
      55,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    60,    60,    61,    62,    63,    64,    64,
      64,    65,    66,    67,    67,    68,    69,    70,    70,    71,
      72,    73,    74,    75,    75,    76,    77,    77,    78,    78,
      79,    80,    81,    82,    83,    83,    84,    84,    84,    84,
      85,    85,    86,    86,    86,    86,    86,    86,    87,    87,
      88,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    90,    90,    90,    91,    91,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    96,    97,
      97,    97,    98,    99,   100,   100
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
       2,     5,     3,     5,     3,     5,     3,     6,     4,     4,
       2,     4,     2,     3,     4,     4,     4,     4,     4,     1,
       1,     1,     1,     1,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     4,     1,
       3,     0,     1,     4,     5,     3
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
#line 59 "lang.y"
                                               {
        printf("Program compiled succesfully!\n");
        return 0;
}
#line 1382 "lang.tab.c"
    break;

  case 23: /* LINE_DECLARATION: TYPE IDSEQUENCE  */
#line 106 "lang.y"
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
#line 1410 "lang.tab.c"
    break;

  case 27: /* ID_SEQUENCE_ELEMENT: ID  */
#line 136 "lang.y"
                         {
                         unSymbols.push_back({(yyvsp[0].strValue), 0});
                    }
#line 1418 "lang.tab.c"
    break;

  case 36: /* BEGIN_SCOPE: SCOPE_START  */
#line 158 "lang.y"
                          {
    symTables.push_back(new SymTable);
}
#line 1426 "lang.tab.c"
    break;

  case 37: /* END_SCOPE: SCOPE_END  */
#line 162 "lang.y"
                      {
    SymTable * symTable = symTables.back();
    delete symTable;
    symTables.pop_back();
}
#line 1436 "lang.tab.c"
    break;

  case 41: /* FOR_BLOCK: FOR_STATEMENT SCOPE  */
#line 176 "lang.y"
                                {
    forController.first = false;
}
#line 1444 "lang.tab.c"
    break;

  case 42: /* FOR_STATEMENT: FOR '(' INIT_DECL_COMP ';' STOP_CONDITION_COMP ';' MODIFY_COMP ')'  */
#line 180 "lang.y"
                                                                                   {
    forController.first = true;
}
#line 1452 "lang.tab.c"
    break;

  case 49: /* WHILE_STATEMENT: WHILE BOOLEAN_EXPRESSION  */
#line 197 "lang.y"
                                           {
    whileController.first = true;
}
#line 1460 "lang.tab.c"
    break;

  case 50: /* WHILE_BLOCK: WHILE_STATEMENT SCOPE  */
#line 201 "lang.y"
                                    {
    whileController.first = false;
}
#line 1468 "lang.tab.c"
    break;

  case 51: /* IF_BLOCK: IF_COMPOSITION  */
#line 207 "lang.y"
                          {
    ifController = {false, 0};
}
#line 1476 "lang.tab.c"
    break;

  case 52: /* IF_COMPOSITION: IF_STRUCTURE  */
#line 211 "lang.y"
                               {
                      if(ifController.first)
                        ifController.second = -1;
                }
#line 1485 "lang.tab.c"
    break;

  case 55: /* IF_STATEMENT: IF BOOLEAN_EXPRESSION  */
#line 219 "lang.y"
                                     {
    ifController = {true, 0};
    if((yyvsp[0].bValue)) 
        ifController.second = 1;
}
#line 1495 "lang.tab.c"
    break;

  case 61: /* ELSE_IF_STATEMENT: ELSE_IF BOOLEAN_EXPRESSION  */
#line 233 "lang.y"
                                                 {
    if(ifController.second) ifController.second = -1;
    if((yyvsp[0].bValue) && ifController.second == 0)
        ifController.second = 1;
}
#line 1505 "lang.tab.c"
    break;

  case 62: /* ELSE_STATEMENT: ELSE  */
#line 239 "lang.y"
                      {
    if(!ifController.second)
         ifController.second = 1;
}
#line 1514 "lang.tab.c"
    break;

  case 82: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' INTEGER_EXPRESSION  */
#line 278 "lang.y"
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
#line 1536 "lang.tab.c"
    break;

  case 84: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' BOOLEAN_EXPRESSION  */
#line 296 "lang.y"
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
#line 1558 "lang.tab.c"
    break;

  case 93: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' STRING_LITERAL  */
#line 321 "lang.y"
                                                        {
                        std::cout << "HERE!\n";
                    }
#line 1566 "lang.tab.c"
    break;

  case 94: /* PRINT_STATEMENT: PRINT '(' INTEGER_EXPRESSION ')'  */
#line 327 "lang.y"
                                                   {
                    if(validateStatement()) 
                        std::cout << (yyvsp[-1].iValue) << '\n';
                }
#line 1575 "lang.tab.c"
    break;

  case 95: /* PRINT_STATEMENT: PRINT '(' BOOLEAN_EXPRESSION ')'  */
#line 331 "lang.y"
                                                  {
                    if(validateStatement()) 
                    {
                        if((yyvsp[-1].bValue))
                            std::cout << "true\n";
                        else std::cout << "false\n";
                    }
                }
#line 1588 "lang.tab.c"
    break;

  case 96: /* PRINT_STATEMENT: PRINT '(' STRING_LITERAL ')'  */
#line 339 "lang.y"
                                               {
                    if(validateStatement()) {
                        std::cout << (yyvsp[-1].strValue) << '\n';
                    }
                }
#line 1598 "lang.tab.c"
    break;

  case 97: /* TYPE_OF_STATEMENT: TYPEOF '(' INTEGER_EXPRESSION ')'  */
#line 347 "lang.y"
                                                      {
                    if(validateStatement()) {
                        std::cout << "integer\n";
                    }
                }
#line 1608 "lang.tab.c"
    break;

  case 98: /* TYPE_OF_STATEMENT: TYPEOF '(' BOOLEAN_EXPRESSION ')'  */
#line 352 "lang.y"
                                                      {
                    if(validateStatement()) {
                        std::cout << "bool\n";
                    }
                }
#line 1618 "lang.tab.c"
    break;

  case 104: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION AND BOOLEAN_EXPRESSION  */
#line 368 "lang.y"
                                                                {
                            (yyval.bValue) = ((yyvsp[-2].bValue) && (yyvsp[0].bValue));
                    }
#line 1626 "lang.tab.c"
    break;

  case 105: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION OR BOOLEAN_EXPRESSION  */
#line 371 "lang.y"
                                                               {
                            (yyval.bValue) = ((yyvsp[-2].bValue) || (yyvsp[0].bValue));
                    }
#line 1634 "lang.tab.c"
    break;

  case 106: /* BOOLEAN_EXPRESSION: BOOLEAN_EQUATION  */
#line 374 "lang.y"
                                       {
                        (yyval.bValue) = (yyvsp[0].bValue);
                    }
#line 1642 "lang.tab.c"
    break;

  case 107: /* BOOLEAN_EXPRESSION: '(' BOOLEAN_EXPRESSION ')'  */
#line 377 "lang.y"
                                                 {
                        (yyval.bValue) = (yyvsp[-1].bValue);
                    }
#line 1650 "lang.tab.c"
    break;

  case 108: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION EQ INTEGER_EXPRESSION  */
#line 382 "lang.y"
                                                            {
                        (yyval.bValue) = ((yyvsp[-2].iValue) == (yyvsp[0].iValue));
                    }
#line 1658 "lang.tab.c"
    break;

  case 109: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION NEQ INTEGER_EXPRESSION  */
#line 385 "lang.y"
                                                                {
                        (yyval.bValue) = ((yyvsp[-2].iValue) != (yyvsp[0].iValue));
                    }
#line 1666 "lang.tab.c"
    break;

  case 110: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION AND INTEGER_EXPRESSION  */
#line 388 "lang.y"
                                                                {
                        (yyval.bValue) = ((yyvsp[-2].iValue) && (yyvsp[0].iValue));
                    }
#line 1674 "lang.tab.c"
    break;

  case 111: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION OR INTEGER_EXPRESSION  */
#line 391 "lang.y"
                                                               {
                        (yyval.bValue) = ((yyvsp[-2].iValue) || (yyvsp[0].iValue));
                    }
#line 1682 "lang.tab.c"
    break;

  case 112: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION LEQ INTEGER_EXPRESSION  */
#line 395 "lang.y"
                                                              {
                        (yyval.bValue) = ((yyvsp[-2].iValue) <= (yyvsp[0].iValue));
                    }
#line 1690 "lang.tab.c"
    break;

  case 113: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION HEQ INTEGER_EXPRESSION  */
#line 398 "lang.y"
                                                                {
                        (yyval.bValue) = ((yyvsp[-2].iValue) >= (yyvsp[0].iValue));
                    }
#line 1698 "lang.tab.c"
    break;

  case 114: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION HT INTEGER_EXPRESSION  */
#line 401 "lang.y"
                                                               {
                        (yyval.bValue) = ((yyvsp[-2].iValue) > (yyvsp[0].iValue));
                    }
#line 1706 "lang.tab.c"
    break;

  case 115: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION LT INTEGER_EXPRESSION  */
#line 404 "lang.y"
                                                               {
                        (yyval.bValue) = ((yyvsp[-2].iValue) < (yyvsp[0].iValue));
                    }
#line 1714 "lang.tab.c"
    break;

  case 116: /* BOOLEAN_EQUATION: BOOLEAN_LITERAL  */
#line 407 "lang.y"
                                      { 
                        (yyval.bValue) = (yyvsp[0].bValue);
                    }
#line 1722 "lang.tab.c"
    break;

  case 117: /* INTEGER_EXPRESSION: LVALUE_ELEMENT ACCESS LVALUE_ELEMENT  */
#line 413 "lang.y"
                                                         {
                    (yyval.iValue) = 0;
                }
#line 1730 "lang.tab.c"
    break;

  case 118: /* INTEGER_EXPRESSION: LVALUE_ELEMENT ACCESS FUNCTION_CALL  */
#line 416 "lang.y"
                                                         {
                        (yyval.iValue) = 0;
                   }
#line 1738 "lang.tab.c"
    break;

  case 119: /* INTEGER_EXPRESSION: LVALUE_ELEMENT  */
#line 419 "lang.y"
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
#line 1756 "lang.tab.c"
    break;

  case 120: /* INTEGER_EXPRESSION: FUNCTION_CALL  */
#line 432 "lang.y"
                            {
                (yyval.iValue) = 0;
            }
#line 1764 "lang.tab.c"
    break;

  case 121: /* INTEGER_EXPRESSION: INTEGER  */
#line 435 "lang.y"
                      {
                (yyval.iValue) = (yyvsp[0].iValue);
            }
#line 1772 "lang.tab.c"
    break;

  case 122: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION PLUS INTEGER_EXPRESSION  */
#line 438 "lang.y"
                                                         {
                (yyval.iValue) = (yyvsp[-2].iValue) + (yyvsp[0].iValue);
            }
#line 1780 "lang.tab.c"
    break;

  case 123: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION MUL INTEGER_EXPRESSION  */
#line 441 "lang.y"
                                                        {
                (yyval.iValue) = (yyvsp[-2].iValue) * (yyvsp[0].iValue);
            }
#line 1788 "lang.tab.c"
    break;

  case 124: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION MINUS INTEGER_EXPRESSION  */
#line 444 "lang.y"
                                                          {
                (yyval.iValue) = (yyvsp[-2].iValue) - (yyvsp[0].iValue);
            }
#line 1796 "lang.tab.c"
    break;

  case 125: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION MOD INTEGER_EXPRESSION  */
#line 447 "lang.y"
                                                        {
                (yyval.iValue) = (yyvsp[-2].iValue) % (yyvsp[0].iValue);
            }
#line 1804 "lang.tab.c"
    break;

  case 126: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION DIV INTEGER_EXPRESSION  */
#line 450 "lang.y"
                                                        {
                (yyval.iValue) = (yyvsp[-2].iValue) / (yyvsp[0].iValue);
            }
#line 1812 "lang.tab.c"
    break;

  case 127: /* INTEGER_EXPRESSION: '(' INTEGER_EXPRESSION ')'  */
#line 453 "lang.y"
                                         {
                (yyval.iValue) = (yyvsp[-1].iValue);
            }
#line 1820 "lang.tab.c"
    break;

  case 128: /* FUNCTION_CALL: ID '(' PARAMETER_LIST ')'  */
#line 460 "lang.y"
                                          {
    (yyval.iValue) = 0;
}
#line 1828 "lang.tab.c"
    break;

  case 133: /* ARRAY_LITERAL: ID '[' INTEGER_EXPRESSION ']'  */
#line 472 "lang.y"
                                              {
        (yyval.strValue) = (yyvsp[-3].strValue);
}
#line 1836 "lang.tab.c"
    break;


#line 1840 "lang.tab.c"

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

#line 481 "lang.y"


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
