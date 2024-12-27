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
    bool globalAreaOn = true, funcOn = false;


    /// TODO: Assign values to class members

    void yyerror(std::string s);
    bool isSymbolValid(std::string s, std::string type);   
    bool validateStatement();
    bool validateFunction(std::string name, std::vector<std::string> parameters);
    void processUpdate(SymTable * symTable, std::string name, std::string type, value val, char op);
    void processAssignmentStatement(SymTable * symTable, std::string name, std::string type, value val, char op);

    std::string extractValueFromValue(value val);
    std::string extractTypeFromVariant(value value);
    ClassSymTable * getClassSymTable(std::string name);
    bool isClassMember(std::string name);
    SymTable * findSymTable(std::string symbol);


    SymTable * globalSymTable;
    std::vector<std::pair<std::string, value>> unSymbols;
    std::pair<bool, int> ifController;
    std::vector<SymTable*> symTables, funcSymTables;
    std::vector<ClassSymTable*> classSymTables;
    std::vector<std::string> parameters;

#line 105 "lang.tab.c"

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
  YYSYMBOL_FUNC_START = 49,                /* FUNC_START  */
  YYSYMBOL_FUNCTION_DECLARATION = 50,      /* FUNCTION_DECLARATION  */
  YYSYMBOL_FUNCTION_DEFINITION = 51,       /* FUNCTION_DEFINITION  */
  YYSYMBOL_DECL_PARAMETER_SEQUENCE = 52,   /* DECL_PARAMETER_SEQUENCE  */
  YYSYMBOL_CLASS_BEGIN_ELEMENT = 53,       /* CLASS_BEGIN_ELEMENT  */
  YYSYMBOL_CLASS_BEGIN = 54,               /* CLASS_BEGIN  */
  YYSYMBOL_CLASS_DEFINITION = 55,          /* CLASS_DEFINITION  */
  YYSYMBOL_CLASS_MEMBER_LIST = 56,         /* CLASS_MEMBER_LIST  */
  YYSYMBOL_CLASS_MEMBER = 57,              /* CLASS_MEMBER  */
  YYSYMBOL_ACCESS_MODIFIER = 58,           /* ACCESS_MODIFIER  */
  YYSYMBOL_LINE_DECLARATION = 59,          /* LINE_DECLARATION  */
  YYSYMBOL_IDSEQUENCE = 60,                /* IDSEQUENCE  */
  YYSYMBOL_ID_SEQUENCE_ELEMENT = 61,       /* ID_SEQUENCE_ELEMENT  */
  YYSYMBOL_DECLARATIONS = 62,              /* DECLARATIONS  */
  YYSYMBOL_DECLARATIONS_ELEMENT = 63,      /* DECLARATIONS_ELEMENT  */
  YYSYMBOL_SCOPE = 64,                     /* SCOPE  */
  YYSYMBOL_BEGIN_SCOPE = 65,               /* BEGIN_SCOPE  */
  YYSYMBOL_END_SCOPE = 66,                 /* END_SCOPE  */
  YYSYMBOL_BLOCK = 67,                     /* BLOCK  */
  YYSYMBOL_FOR_BLOCK = 68,                 /* FOR_BLOCK  */
  YYSYMBOL_FOR_START = 69,                 /* FOR_START  */
  YYSYMBOL_FOR_STATEMENT = 70,             /* FOR_STATEMENT  */
  YYSYMBOL_INIT_DECL_COMP = 71,            /* INIT_DECL_COMP  */
  YYSYMBOL_STOP_CONDITION_COMP = 72,       /* STOP_CONDITION_COMP  */
  YYSYMBOL_MODIFY_COMP = 73,               /* MODIFY_COMP  */
  YYSYMBOL_LINE_INITIALIZATION = 74,       /* LINE_INITIALIZATION  */
  YYSYMBOL_WHILE_STATEMENT = 75,           /* WHILE_STATEMENT  */
  YYSYMBOL_WHILE_BLOCK = 76,               /* WHILE_BLOCK  */
  YYSYMBOL_IF_BLOCK = 77,                  /* IF_BLOCK  */
  YYSYMBOL_IF_COMPOSITION = 78,            /* IF_COMPOSITION  */
  YYSYMBOL_IF_STRUCTURE = 79,              /* IF_STRUCTURE  */
  YYSYMBOL_IF_STATEMENT = 80,              /* IF_STATEMENT  */
  YYSYMBOL_ELSE_BLOCKS = 81,               /* ELSE_BLOCKS  */
  YYSYMBOL_ELSE_IF_BLOCK = 82,             /* ELSE_IF_BLOCK  */
  YYSYMBOL_ELSE_BLOCK = 83,                /* ELSE_BLOCK  */
  YYSYMBOL_ELSE_IF_STATEMENT = 84,         /* ELSE_IF_STATEMENT  */
  YYSYMBOL_ELSE_STATEMENT = 85,            /* ELSE_STATEMENT  */
  YYSYMBOL_MAIN = 86,                      /* MAIN  */
  YYSYMBOL_MUL_STATEMENTS = 87,            /* MUL_STATEMENTS  */
  YYSYMBOL_CODE_AREA_ELEMENT = 88,         /* CODE_AREA_ELEMENT  */
  YYSYMBOL_CODE_AREA = 89,                 /* CODE_AREA  */
  YYSYMBOL_STATEMENT = 90,                 /* STATEMENT  */
  YYSYMBOL_LVALUE_ELEMENT = 91,            /* LVALUE_ELEMENT  */
  YYSYMBOL_CLASS_LITERAL = 92,             /* CLASS_LITERAL  */
  YYSYMBOL_RETURN_STATEMENT = 93,          /* RETURN_STATEMENT  */
  YYSYMBOL_ASSIGNMENT_STATEMENT = 94,      /* ASSIGNMENT_STATEMENT  */
  YYSYMBOL_PRINT_STATEMENT = 95,           /* PRINT_STATEMENT  */
  YYSYMBOL_TYPE_OF_STATEMENT = 96,         /* TYPE_OF_STATEMENT  */
  YYSYMBOL_OPERATOR = 97,                  /* OPERATOR  */
  YYSYMBOL_BOOLEAN_EXPRESSION = 98,        /* BOOLEAN_EXPRESSION  */
  YYSYMBOL_BOOLEAN_EQUATION = 99,          /* BOOLEAN_EQUATION  */
  YYSYMBOL_INTEGER_EXPRESSION = 100,       /* INTEGER_EXPRESSION  */
  YYSYMBOL_FUNCTION_CALL = 101,            /* FUNCTION_CALL  */
  YYSYMBOL_PARAMETER_LIST = 102,           /* PARAMETER_LIST  */
  YYSYMBOL_PARAMETER = 103,                /* PARAMETER  */
  YYSYMBOL_ARRAY_LITERAL = 104,            /* ARRAY_LITERAL  */
  YYSYMBOL_ARRAY_DECLARATION = 105         /* ARRAY_DECLARATION  */
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
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   357

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  250

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
       0,    75,    75,    86,    88,    90,    92,    97,   102,   109,
     110,   112,   114,   115,   117,   118,   121,   131,   140,   149,
     158,   167,   177,   180,   183,   192,   215,   221,   222,   225,
     228,   233,   234,   236,   237,   238,   239,   245,   247,   251,
     259,   260,   261,   265,   267,   269,   270,   271,   273,   275,
     278,   279,   283,   285,   289,   293,   298,   299,   301,   307,
     308,   310,   311,   313,   315,   321,   329,   331,   332,   334,
     335,   336,   337,   340,   341,   346,   347,   348,   349,   350,
     351,   354,   355,   357,   375,   376,   377,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     395,   399,   407,   415,   419,   426,   427,   428,   429,   430,
     434,   437,   440,   443,   448,   451,   454,   457,   461,   464,
     467,   470,   473,   479,   492,   495,   508,   511,   514,   517,
     520,   523,   526,   529,   536,   552,   553,   554,   556,   557,
     558,   562,   564,   565,   566
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
  "')'", "','", "';'", "'='", "'['", "']'", "$accept", "S", "FUNC_START",
  "FUNCTION_DECLARATION", "FUNCTION_DEFINITION", "DECL_PARAMETER_SEQUENCE",
  "CLASS_BEGIN_ELEMENT", "CLASS_BEGIN", "CLASS_DEFINITION",
  "CLASS_MEMBER_LIST", "CLASS_MEMBER", "ACCESS_MODIFIER",
  "LINE_DECLARATION", "IDSEQUENCE", "ID_SEQUENCE_ELEMENT", "DECLARATIONS",
  "DECLARATIONS_ELEMENT", "SCOPE", "BEGIN_SCOPE", "END_SCOPE", "BLOCK",
  "FOR_BLOCK", "FOR_START", "FOR_STATEMENT", "INIT_DECL_COMP",
  "STOP_CONDITION_COMP", "MODIFY_COMP", "LINE_INITIALIZATION",
  "WHILE_STATEMENT", "WHILE_BLOCK", "IF_BLOCK", "IF_COMPOSITION",
  "IF_STRUCTURE", "IF_STATEMENT", "ELSE_BLOCKS", "ELSE_IF_BLOCK",
  "ELSE_BLOCK", "ELSE_IF_STATEMENT", "ELSE_STATEMENT", "MAIN",
  "MUL_STATEMENTS", "CODE_AREA_ELEMENT", "CODE_AREA", "STATEMENT",
  "LVALUE_ELEMENT", "CLASS_LITERAL", "RETURN_STATEMENT",
  "ASSIGNMENT_STATEMENT", "PRINT_STATEMENT", "TYPE_OF_STATEMENT",
  "OPERATOR", "BOOLEAN_EXPRESSION", "BOOLEAN_EQUATION",
  "INTEGER_EXPRESSION", "FUNCTION_CALL", "PARAMETER_LIST", "PARAMETER",
  "ARRAY_LITERAL", "ARRAY_DECLARATION", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-219)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-30)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     327,    29,    33,  -219,  -219,  -219,  -219,    41,    43,    17,
    -219,    54,    37,    40,    78,    60,    97,   327,  -219,    69,
    -219,    71,   166,   285,  -219,  -219,  -219,   123,   104,  -219,
    -219,   152,  -219,  -219,  -219,   151,  -219,  -219,    66,   150,
     165,  -219,  -219,  -219,  -219,  -219,  -219,  -219,     4,   111,
    -219,  -219,    52,   134,   142,   176,    33,  -219,   170,  -219,
     180,  -219,   214,    23,   150,   190,   191,   146,   146,  -219,
    -219,    75,   177,  -219,   151,  -219,  -219,   192,   176,   176,
    -219,  -219,  -219,  -219,   176,   233,  -219,   151,  -219,   153,
     189,  -219,  -219,  -219,  -219,  -219,    -6,  -219,    66,   227,
     182,  -219,   127,  -219,  -219,  -219,  -219,   146,    66,   171,
    -219,   292,  -219,    66,   171,   292,  -219,    66,    43,  -219,
     202,  -219,  -219,  -219,    33,   203,  -219,    84,    95,   146,
     171,   292,   171,  -219,   171,   292,  -219,   216,    13,  -219,
    -219,   181,  -219,  -219,   148,  -219,   245,   302,   251,    66,
      66,    66,    66,    66,  -219,    59,   217,   236,   146,   146,
      66,    66,    66,    66,    66,    66,    66,    66,   312,   312,
    -219,  -219,   212,  -219,  -219,   171,   292,   215,   225,   232,
     122,   242,   126,   267,  -219,  -219,    14,  -219,   237,  -219,
     239,  -219,   146,  -219,   231,  -219,   176,   176,  -219,   257,
    -219,  -219,  -219,  -219,   139,   139,  -219,  -219,  -219,  -219,
      21,  -219,  -219,   281,   312,   312,   312,   312,   312,   312,
     312,   312,  -219,  -219,    84,  -219,  -219,  -219,  -219,  -219,
     146,   301,   171,  -219,   278,  -219,   260,   261,  -219,   288,
     171,   304,  -219,  -219,  -219,  -219,   301,   309,  -219,  -219
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    22,    23,    24,    10,     0,     8,     0,
      36,     0,     0,     0,     0,     0,     0,    31,    26,    81,
      25,    27,     0,     0,    30,    82,     1,     0,     0,    34,
      11,     0,    35,     9,    33,     0,    32,     3,     0,     0,
       0,   105,   106,   107,   108,   109,    96,    98,     0,     0,
      95,    97,     0,     0,     7,     4,     0,    13,     0,    20,
       0,    15,     0,    81,     0,     0,     0,     0,     0,    44,
      38,     0,     0,    72,     0,    69,    42,     0,     0,     0,
      41,    40,    54,    55,     0,     0,    70,    73,    66,     0,
       0,    79,    75,    76,    77,    78,    81,   127,     0,   125,
       0,   126,    81,    28,    83,   122,    99,     0,     0,    90,
     112,    88,    92,     0,    89,    87,    91,     0,     8,     5,
       0,    19,    12,    14,     0,     0,    21,   137,     0,     0,
      58,     0,    52,    86,    85,    84,    71,     0,     0,    43,
      53,    56,     2,    74,     0,    67,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    93,
       6,    18,     0,    17,   139,   140,   138,     0,   135,     0,
       0,     0,     0,     0,    39,    37,    81,    46,     0,    47,
      50,    65,     0,    57,     0,    60,     0,     0,    68,    83,
      80,   133,   123,   124,   128,   130,   129,   132,   131,   113,
       0,   143,   110,   111,   116,   117,   114,   115,   121,   118,
     120,   119,    16,   134,   137,   102,   101,   100,   104,   103,
       0,     0,    64,    59,    61,    63,     0,     0,   136,     0,
      48,    81,    51,    62,   142,   144,     0,     0,    49,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -219,  -219,  -219,   -17,    11,   234,  -219,  -219,  -219,  -219,
     273,    -8,     3,   -35,  -219,   334,  -219,   -49,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -218,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,   119,   160,  -219,  -219,  -219,
     211,  -219,   -65,  -219,    -2,  -219,  -219,   -34,  -219,  -219,
     333,   -21,  -219,   -33,   -23,   133,  -219,  -219,   -50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    28,    11,    12,    13,    60,
      61,    14,    72,    20,    21,    16,    17,    73,    74,   185,
      75,    76,    77,    78,   188,   239,   247,   189,    79,    80,
      81,    82,    83,    84,   193,   194,   195,   196,   197,    85,
      86,    87,    88,    89,    99,    23,    91,    24,    93,    94,
      49,   175,   110,   131,   101,   177,   178,    25,   112
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    92,   116,    15,   103,   100,   119,    96,    97,   137,
     105,   106,    95,   242,    58,   111,   186,    18,    64,   115,
      15,   120,   143,    62,    96,    97,    18,   109,   248,   139,
     140,   114,    18,    90,   127,   141,    19,    22,   135,    38,
      92,    26,    59,    58,   107,   125,   130,   132,    27,   108,
     134,    95,    62,    92,    22,    96,    97,    30,   105,    38,
      29,    98,    22,   127,    95,   147,   108,    31,    38,    96,
      97,    59,    90,   126,   156,   157,   158,   159,    96,    97,
     168,   105,   133,    32,   169,    90,   155,    96,    97,   172,
     105,   174,   107,    33,   176,   181,   183,   108,    96,    97,
     209,   105,   179,    34,   190,    35,    98,   180,   182,    37,
      92,   -29,   -29,    39,    38,   107,   204,   205,   206,   207,
     208,    95,    22,   200,   107,   203,    54,   214,   215,   216,
     217,   218,   219,   220,   221,   107,    22,   212,   213,   158,
     159,   187,    90,   158,   159,    55,   202,   234,   235,    96,
      97,    96,   105,   102,    63,   113,    64,    56,    65,    66,
     237,    65,    66,   226,     3,     4,     5,   228,   104,   -29,
     -29,   232,    38,   151,   152,   153,    67,   236,   117,    68,
      69,    70,    40,    57,   118,    56,   107,    71,   158,   159,
      71,   176,     3,     4,     5,   144,   145,   190,    41,    42,
      43,    44,    45,    46,    47,   146,    70,   191,   192,   240,
      48,   122,   190,   121,   149,   150,   151,   152,   153,   124,
     136,    41,    42,    43,    44,    45,    46,    47,   154,    22,
     128,   129,   138,    48,   160,   161,   162,   163,   164,   165,
     166,   167,   142,   148,    22,   171,   173,   184,   199,   149,
     150,   151,   152,   153,    96,   222,   223,   191,   201,   160,
     161,   162,   163,   164,   165,   166,   167,   224,   149,   150,
     151,   152,   153,   225,   149,   150,   151,   152,   153,   210,
     230,   231,   211,   227,   160,   161,   162,   163,   164,   165,
     166,   167,   149,   150,   151,   152,   153,   127,   158,   149,
     150,   151,   152,   153,   241,   192,   244,   245,   229,   160,
     161,   162,   163,   164,   165,   166,   167,    41,    42,    43,
      44,    45,    50,    51,   149,   150,   151,   152,   153,    52,
       1,   246,     2,   123,   149,   150,   151,   152,   153,     3,
       4,     5,     6,   201,   149,   150,   151,   152,   153,    38,
     249,    36,   170,   243,   233,   198,    53,   238
};

static const yytype_uint8 yycheck[] =
{
       2,    35,    52,     0,    39,    38,    55,     3,     4,    74,
       6,     7,    35,   231,    31,    48,     3,     3,     5,    52,
      17,    56,    87,    31,     3,     4,     3,    48,   246,    78,
      79,    52,     3,    35,    40,    84,     3,    39,    71,    45,
      74,     0,    31,    60,    40,    62,    67,    68,     5,    45,
      71,    74,    60,    87,    56,     3,     4,     3,     6,    45,
      43,    40,    64,    40,    87,    98,    45,    30,    45,     3,
       4,    60,    74,    62,   107,   108,    17,    18,     3,     4,
     113,     6,     7,    43,   117,    87,   107,     3,     4,   124,
       6,     7,    40,    15,   127,   128,   129,    45,     3,     4,
      41,     6,     7,    43,   138,     8,    40,   128,   129,    40,
     144,    42,    43,    42,    45,    40,   149,   150,   151,   152,
     153,   144,   124,   146,    40,   148,     3,   160,   161,   162,
     163,   164,   165,   166,   167,    40,   138,   158,   159,    17,
      18,   138,   144,    17,    18,    41,   148,   196,   197,     3,
       4,     3,     6,     3,     3,    44,     5,     5,    10,    11,
     210,    10,    11,    41,    12,    13,    14,    41,     3,    42,
      43,   192,    45,    34,    35,    36,    25,   210,    44,    28,
      29,    30,    16,    31,    42,     5,    40,    39,    17,    18,
      39,   224,    12,    13,    14,    42,    43,   231,    32,    33,
      34,    35,    36,    37,    38,    16,    30,    26,    27,   230,
      44,    31,   246,    43,    32,    33,    34,    35,    36,     5,
      43,    32,    33,    34,    35,    36,    37,    38,    46,   231,
      40,    40,    40,    44,    17,    18,    19,    20,    21,    22,
      23,    24,     9,    16,   246,    43,    43,    31,     3,    32,
      33,    34,    35,    36,     3,    43,    41,    26,    41,    17,
      18,    19,    20,    21,    22,    23,    24,    42,    32,    33,
      34,    35,    36,    41,    32,    33,    34,    35,    36,    43,
      43,    42,    46,    41,    17,    18,    19,    20,    21,    22,
      23,    24,    32,    33,    34,    35,    36,    40,    17,    32,
      33,    34,    35,    36,     3,    27,    46,    46,    41,    17,
      18,    19,    20,    21,    22,    23,    24,    32,    33,    34,
      35,    36,    37,    38,    32,    33,    34,    35,    36,    44,
       3,    43,     5,    60,    32,    33,    34,    35,    36,    12,
      13,    14,    15,    41,    32,    33,    34,    35,    36,    45,
      41,    17,   118,   234,   194,   144,    23,   224
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,    12,    13,    14,    15,    48,    49,    50,
      51,    53,    54,    55,    58,    59,    62,    63,     3,     3,
      60,    61,    91,    92,    94,   104,     0,     5,    52,    43,
       3,    30,    43,    15,    43,     8,    62,    40,    45,    42,
      16,    32,    33,    34,    35,    36,    37,    38,    44,    97,
      37,    38,    44,    97,     3,    41,     5,    31,    50,    51,
      56,    57,    58,     3,     5,    10,    11,    25,    28,    29,
      30,    39,    59,    64,    65,    67,    68,    69,    70,    75,
      76,    77,    78,    79,    80,    86,    87,    88,    89,    90,
      91,    93,    94,    95,    96,   101,     3,     4,    40,    91,
     100,   101,     3,    60,     3,     6,     7,    40,    45,    98,
      99,   100,   105,    44,    98,   100,   105,    44,    42,    64,
      60,    43,    31,    57,     5,    50,    51,    40,    40,    40,
      98,   100,    98,     7,    98,   100,    43,    89,    40,    64,
      64,    64,     9,    89,    42,    43,    16,   100,    16,    32,
      33,    34,    35,    36,    46,    98,   100,   100,    17,    18,
      17,    18,    19,    20,    21,    22,    23,    24,   100,   100,
      52,    43,    60,    43,     7,    98,   100,   102,   103,     7,
      98,   100,    98,   100,    31,    66,     3,    59,    71,    74,
      94,    26,    27,    81,    82,    83,    84,    85,    87,     3,
     101,    41,    91,   101,   100,   100,   100,   100,   100,    41,
      43,    46,    98,    98,   100,   100,   100,   100,   100,   100,
     100,   100,    43,    41,    42,    41,    41,    41,    41,    41,
      43,    42,    98,    83,    64,    64,   100,   105,   102,    72,
      98,     3,    74,    82,    46,    46,    43,    73,    74,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    50,    51,    52,    52,    52,    53,
      53,    54,    55,    55,    56,    56,    57,    57,    57,    57,
      57,    57,    58,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    63,    63,    64,    65,    66,
      67,    67,    67,    68,    69,    70,    71,    71,    72,    73,
      74,    74,    75,    76,    77,    78,    79,    79,    80,    81,
      81,    82,    82,    83,    84,    85,    86,    87,    87,    88,
      88,    88,    88,    89,    89,    90,    90,    90,    90,    90,
      90,    91,    91,    92,    93,    93,    93,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      95,    95,    95,    96,    96,    97,    97,    97,    97,    97,
      98,    98,    98,    98,    99,    99,    99,    99,    99,    99,
      99,    99,    99,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   101,   102,   102,   102,   103,   103,
     103,   104,   105,   105,   105
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     4,     4,     2,     0,     2,
       1,     2,     4,     3,     2,     1,     4,     3,     3,     2,
       1,     2,     1,     1,     1,     2,     2,     1,     3,     1,
       1,     1,     2,     2,     2,     2,     1,     3,     1,     1,
       1,     1,     1,     2,     1,     8,     1,     1,     1,     1,
       1,     3,     2,     2,     1,     1,     2,     3,     2,     2,
       1,     2,     3,     2,     2,     1,     1,     2,     3,     1,
       1,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       3,     1,     1,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     4,     4,     2,     2,     2,     2,     3,
       4,     4,     4,     4,     4,     1,     1,     1,     1,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     4,     1,     3,     0,     1,     1,
       1,     4,     5,     3,     5
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
#line 75 "lang.y"
                                               {
        printf("Program compiled succesfully!\n");
        return 0;
}
#line 1405 "lang.tab.c"
    break;

  case 3: /* FUNC_START: TYPE ID '('  */
#line 86 "lang.y"
                         { funcOn = true; funcSymTables.push_back(new SymTable(std::string((yyvsp[-2].strValue)), std::string((yyvsp[-1].strValue)))); }
#line 1411 "lang.tab.c"
    break;

  case 4: /* FUNCTION_DECLARATION: FUNC_START DECL_PARAMETER_SEQUENCE ')'  */
#line 88 "lang.y"
                                                              { funcOn = false; }
#line 1417 "lang.tab.c"
    break;

  case 5: /* FUNCTION_DEFINITION: FUNC_START DECL_PARAMETER_SEQUENCE ')' SCOPE  */
#line 90 "lang.y"
                                                                   { funcOn = false; }
#line 1423 "lang.tab.c"
    break;

  case 6: /* DECL_PARAMETER_SEQUENCE: TYPE ID ',' DECL_PARAMETER_SEQUENCE  */
#line 92 "lang.y"
                                                              {
                            SymTable * symTable = funcSymTables.back();
                            symTable->addParameter(std::string((yyvsp[-3].strValue)));
                            symTable->addSymbol(std::string((yyvsp[-2].strValue)), std::string((yyvsp[-3].strValue)));
                        }
#line 1433 "lang.tab.c"
    break;

  case 7: /* DECL_PARAMETER_SEQUENCE: TYPE ID  */
#line 97 "lang.y"
                                   {
                            SymTable * symTable = funcSymTables.back();
                            symTable->addParameter(std::string((yyvsp[-1].strValue)));
                            symTable->addSymbol(std::string((yyvsp[0].strValue)), std::string((yyvsp[-1].strValue)));
                        }
#line 1443 "lang.tab.c"
    break;

  case 9: /* CLASS_BEGIN_ELEMENT: ACCESS_MODIFIER CLASS  */
#line 109 "lang.y"
                                            {strcpy((yyval.strValue), (yyvsp[-1].strValue));}
#line 1449 "lang.tab.c"
    break;

  case 10: /* CLASS_BEGIN_ELEMENT: CLASS  */
#line 110 "lang.y"
                            {strcpy((yyval.strValue), "public");}
#line 1455 "lang.tab.c"
    break;

  case 11: /* CLASS_BEGIN: CLASS_BEGIN_ELEMENT ID  */
#line 112 "lang.y"
                                     {classSymTables.push_back(new ClassSymTable(std::string((yyvsp[-1].strValue)), std::string((yyvsp[0].strValue))));}
#line 1461 "lang.tab.c"
    break;

  case 16: /* CLASS_MEMBER: ACCESS_MODIFIER TYPE IDSEQUENCE ';'  */
#line 121 "lang.y"
                                                   {
                ClassSymTable * symTable = classSymTables.back();
                for(auto [name, value] : unSymbols) 
                {
                    std::string className = std::string((yyvsp[-3].strValue)) + " " + name;
                    symTable->addSymbol(className, std::string((yyvsp[-2].strValue)));
                    // std::cout << std::string($2) << ' ' << className << '\n';
                    processUpdate(symTable, className, std::string((yyvsp[-2].strValue)), value, '=');
                }
            }
#line 1476 "lang.tab.c"
    break;

  case 17: /* CLASS_MEMBER: ACCESS_MODIFIER FUNCTION_DECLARATION ';'  */
#line 131 "lang.y"
                                                        {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = std::string((yyvsp[-2].strValue)) + " " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
#line 1490 "lang.tab.c"
    break;

  case 18: /* CLASS_MEMBER: TYPE IDSEQUENCE ';'  */
#line 140 "lang.y"
                                   {
                ClassSymTable * symTable = classSymTables.back();
                for(auto [name, value] : unSymbols) 
                {
                    std::string className = "private " + name;
                    symTable->addSymbol(className, std::string((yyvsp[-2].strValue)));
                    processUpdate(symTable, className, std::string((yyvsp[-2].strValue)), value, '=');
                }
             }
#line 1504 "lang.tab.c"
    break;

  case 19: /* CLASS_MEMBER: FUNCTION_DECLARATION ';'  */
#line 149 "lang.y"
                                        {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = "private " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
#line 1518 "lang.tab.c"
    break;

  case 20: /* CLASS_MEMBER: FUNCTION_DEFINITION  */
#line 158 "lang.y"
                                   {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = "private " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
#line 1532 "lang.tab.c"
    break;

  case 21: /* CLASS_MEMBER: ACCESS_MODIFIER FUNCTION_DEFINITION  */
#line 167 "lang.y"
                                                   {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = std::string((yyvsp[-1].strValue)) + " " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
#line 1546 "lang.tab.c"
    break;

  case 22: /* ACCESS_MODIFIER: PRIVATE  */
#line 177 "lang.y"
                          {
                    strcpy((yyval.strValue), (yyvsp[0].strValue));
                }
#line 1554 "lang.tab.c"
    break;

  case 23: /* ACCESS_MODIFIER: PUBLIC  */
#line 180 "lang.y"
                         {
                    strcpy((yyval.strValue), (yyvsp[0].strValue));
                }
#line 1562 "lang.tab.c"
    break;

  case 24: /* ACCESS_MODIFIER: PROTECTED  */
#line 183 "lang.y"
                            {
                    strcpy((yyval.strValue), (yyvsp[0].strValue));
                }
#line 1570 "lang.tab.c"
    break;

  case 25: /* LINE_DECLARATION: TYPE IDSEQUENCE  */
#line 192 "lang.y"
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
            for(auto [name, val] : unSymbols)
            {
                symTable->addSymbol(name, (yyvsp[-1].strValue));
                processUpdate(symTable, name, std::string((yyvsp[-1].strValue)), val, '=');
            }
        }
        unSymbols.clear();
}
#line 1598 "lang.tab.c"
    break;

  case 26: /* LINE_DECLARATION: ID ID  */
#line 215 "lang.y"
        {
    SymTable * symTable = symTables.back();
    symTable->addSymbol(std::string((yyvsp[0].strValue)), std::string((yyvsp[-1].strValue)));
}
#line 1607 "lang.tab.c"
    break;

  case 29: /* ID_SEQUENCE_ELEMENT: ID  */
#line 225 "lang.y"
                         {
                         unSymbols.push_back({(yyvsp[0].strValue), 0});
                    }
#line 1615 "lang.tab.c"
    break;

  case 38: /* BEGIN_SCOPE: SCOPE_START  */
#line 247 "lang.y"
                          {
    symTables.push_back(new SymTable);
}
#line 1623 "lang.tab.c"
    break;

  case 39: /* END_SCOPE: SCOPE_END  */
#line 251 "lang.y"
                      {
    SymTable * symTable = symTables.back();
    delete symTable;
    symTables.pop_back();
}
#line 1633 "lang.tab.c"
    break;

  case 43: /* FOR_BLOCK: FOR_STATEMENT SCOPE  */
#line 265 "lang.y"
                                { symTables.pop_back(); }
#line 1639 "lang.tab.c"
    break;

  case 44: /* FOR_START: FOR  */
#line 267 "lang.y"
                { symTables.push_back(new SymTable); }
#line 1645 "lang.tab.c"
    break;

  case 54: /* IF_BLOCK: IF_COMPOSITION  */
#line 289 "lang.y"
                          {
    ifController = {false, 0};
}
#line 1653 "lang.tab.c"
    break;

  case 55: /* IF_COMPOSITION: IF_STRUCTURE  */
#line 293 "lang.y"
                              {
                      if(ifController.first)
                        ifController.second = -1;
                }
#line 1662 "lang.tab.c"
    break;

  case 58: /* IF_STATEMENT: IF BOOLEAN_EXPRESSION  */
#line 301 "lang.y"
                                     {
    ifController = {true, 0};
    if((yyvsp[0].bValue)) 
        ifController.second = 1;
}
#line 1672 "lang.tab.c"
    break;

  case 64: /* ELSE_IF_STATEMENT: ELSE_IF BOOLEAN_EXPRESSION  */
#line 315 "lang.y"
                                                 {
    if(ifController.second) ifController.second = -1;
    if((yyvsp[0].bValue) && ifController.second == 0)
        ifController.second = 1;
}
#line 1682 "lang.tab.c"
    break;

  case 65: /* ELSE_STATEMENT: ELSE  */
#line 321 "lang.y"
                      {
    if(!ifController.second)
         ifController.second = 1;
}
#line 1691 "lang.tab.c"
    break;

  case 83: /* CLASS_LITERAL: LVALUE_ELEMENT ACCESS ID  */
#line 357 "lang.y"
                                         {
    if(isClassMember((yyvsp[-2].strValue))) 
    {
        ClassSymTable * classSymTable = getClassSymTable((yyvsp[-2].strValue));
        if(classSymTable == NULL) {
            yyerror("Class Identifier " + std::string((yyvsp[-2].strValue)) + " doesn't exist!\n");
            exit(1);
        }
        else {
            if(!classSymTable->isSymbolInClass(std::string((yyvsp[0].strValue)))) {
                yyerror(std::string("Identifier " + std::string((yyvsp[0].strValue)) + " doesn't exist in class " + std::string((yyvsp[-2].strValue))));
                exit(1);
            }
        }
    }
    strcpy((yyval.strValue), (yyvsp[0].strValue));
}
#line 1713 "lang.tab.c"
    break;

  case 87: /* ASSIGNMENT_STATEMENT: CLASS_LITERAL '=' INTEGER_EXPRESSION  */
#line 379 "lang.y"
                                                            {processAssignmentStatement(getClassSymTable(std::string((yyvsp[-2].strValue))), std::string((yyvsp[-2].strValue)), "int", value((yyvsp[0].iValue)), '='); }
#line 1719 "lang.tab.c"
    break;

  case 88: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' INTEGER_EXPRESSION  */
#line 380 "lang.y"
                                                             { processAssignmentStatement(findSymTable(std::string((yyvsp[-2].strValue))), std::string((yyvsp[-2].strValue)), "int", value((yyvsp[0].iValue)), '='); }
#line 1725 "lang.tab.c"
    break;

  case 89: /* ASSIGNMENT_STATEMENT: CLASS_LITERAL '=' BOOLEAN_EXPRESSION  */
#line 381 "lang.y"
                                                            {processAssignmentStatement(getClassSymTable(std::string((yyvsp[-2].strValue))), std::string((yyvsp[-2].strValue)), "bool", value((yyvsp[0].bValue)), '='); }
#line 1731 "lang.tab.c"
    break;

  case 90: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' BOOLEAN_EXPRESSION  */
#line 382 "lang.y"
                                                             { processAssignmentStatement(findSymTable(std::string((yyvsp[-2].strValue))), std::string((yyvsp[-2].strValue)), "bool", value((yyvsp[0].bValue)), '=');}
#line 1737 "lang.tab.c"
    break;

  case 94: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT OPERATOR '=' INTEGER_EXPRESSION  */
#line 386 "lang.y"
                                                                      { processAssignmentStatement(getClassSymTable(std::string((yyvsp[-3].strValue))), std::string((yyvsp[-3].strValue)), "int", value((yyvsp[0].iValue)), std::string((yyvsp[-2].strValue))[0]);}
#line 1743 "lang.tab.c"
    break;

  case 99: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' STRING_LITERAL  */
#line 391 "lang.y"
                                                         {processAssignmentStatement(findSymTable(std::string((yyvsp[-2].strValue))), std::string((yyvsp[-2].strValue)), "string", value((yyvsp[0].strValue)), '=');}
#line 1749 "lang.tab.c"
    break;

  case 100: /* PRINT_STATEMENT: PRINT '(' INTEGER_EXPRESSION ')'  */
#line 395 "lang.y"
                                                   {
                    if(validateStatement()) 
                        std::cout << (yyvsp[-1].iValue) << '\n';
                }
#line 1758 "lang.tab.c"
    break;

  case 101: /* PRINT_STATEMENT: PRINT '(' BOOLEAN_EXPRESSION ')'  */
#line 399 "lang.y"
                                                  {
                    if(validateStatement()) 
                    {
                        if((yyvsp[-1].bValue))
                            std::cout << "true\n";
                        else std::cout << "false\n";
                    }
                }
#line 1771 "lang.tab.c"
    break;

  case 102: /* PRINT_STATEMENT: PRINT '(' STRING_LITERAL ')'  */
#line 407 "lang.y"
                                               {
                    if(validateStatement()) {
                        std::cout << (yyvsp[-1].strValue) << '\n';
                    }
                }
#line 1781 "lang.tab.c"
    break;

  case 103: /* TYPE_OF_STATEMENT: TYPEOF '(' INTEGER_EXPRESSION ')'  */
#line 415 "lang.y"
                                                      {
                    if(validateStatement()) 
                        std::cout << "integer\n";
                }
#line 1790 "lang.tab.c"
    break;

  case 104: /* TYPE_OF_STATEMENT: TYPEOF '(' BOOLEAN_EXPRESSION ')'  */
#line 419 "lang.y"
                                                      {
                    if(validateStatement()) 
                        std::cout << "bool\n";
                }
#line 1799 "lang.tab.c"
    break;

  case 110: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION AND BOOLEAN_EXPRESSION  */
#line 434 "lang.y"
                                                                {
                            (yyval.bValue) = ((yyvsp[-2].bValue) && (yyvsp[0].bValue));
                    }
#line 1807 "lang.tab.c"
    break;

  case 111: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION OR BOOLEAN_EXPRESSION  */
#line 437 "lang.y"
                                                               {
                            (yyval.bValue) = ((yyvsp[-2].bValue) || (yyvsp[0].bValue));
                    }
#line 1815 "lang.tab.c"
    break;

  case 112: /* BOOLEAN_EXPRESSION: BOOLEAN_EQUATION  */
#line 440 "lang.y"
                                       {
                        (yyval.bValue) = (yyvsp[0].bValue);
                    }
#line 1823 "lang.tab.c"
    break;

  case 113: /* BOOLEAN_EXPRESSION: '(' BOOLEAN_EXPRESSION ')'  */
#line 443 "lang.y"
                                                 {
                        (yyval.bValue) = (yyvsp[-1].bValue);
                    }
#line 1831 "lang.tab.c"
    break;

  case 114: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION EQ INTEGER_EXPRESSION  */
#line 448 "lang.y"
                                                            {
                        (yyval.bValue) = ((yyvsp[-2].iValue) == (yyvsp[0].iValue));
                    }
#line 1839 "lang.tab.c"
    break;

  case 115: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION NEQ INTEGER_EXPRESSION  */
#line 451 "lang.y"
                                                                {
                        (yyval.bValue) = ((yyvsp[-2].iValue) != (yyvsp[0].iValue));
                    }
#line 1847 "lang.tab.c"
    break;

  case 116: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION AND INTEGER_EXPRESSION  */
#line 454 "lang.y"
                                                                {
                        (yyval.bValue) = ((yyvsp[-2].iValue) && (yyvsp[0].iValue));
                    }
#line 1855 "lang.tab.c"
    break;

  case 117: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION OR INTEGER_EXPRESSION  */
#line 457 "lang.y"
                                                               {
                        (yyval.bValue) = ((yyvsp[-2].iValue) || (yyvsp[0].iValue));
                    }
#line 1863 "lang.tab.c"
    break;

  case 118: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION LEQ INTEGER_EXPRESSION  */
#line 461 "lang.y"
                                                              {
                        (yyval.bValue) = ((yyvsp[-2].iValue) <= (yyvsp[0].iValue));
                    }
#line 1871 "lang.tab.c"
    break;

  case 119: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION HEQ INTEGER_EXPRESSION  */
#line 464 "lang.y"
                                                                {
                        (yyval.bValue) = ((yyvsp[-2].iValue) >= (yyvsp[0].iValue));
                    }
#line 1879 "lang.tab.c"
    break;

  case 120: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION HT INTEGER_EXPRESSION  */
#line 467 "lang.y"
                                                               {
                        (yyval.bValue) = ((yyvsp[-2].iValue) > (yyvsp[0].iValue));
                    }
#line 1887 "lang.tab.c"
    break;

  case 121: /* BOOLEAN_EQUATION: INTEGER_EXPRESSION LT INTEGER_EXPRESSION  */
#line 470 "lang.y"
                                                               {
                        (yyval.bValue) = ((yyvsp[-2].iValue) < (yyvsp[0].iValue));
                    }
#line 1895 "lang.tab.c"
    break;

  case 122: /* BOOLEAN_EQUATION: BOOLEAN_LITERAL  */
#line 473 "lang.y"
                                      { 
                        (yyval.bValue) = (yyvsp[0].bValue);
                    }
#line 1903 "lang.tab.c"
    break;

  case 123: /* INTEGER_EXPRESSION: LVALUE_ELEMENT ACCESS LVALUE_ELEMENT  */
#line 479 "lang.y"
                                                          {
                    std::cout << "HERE! " << (yyvsp[-2].strValue) << ' ' << (yyvsp[0].strValue) << '\n';
                    (yyval.iValue) = 0;
                    SymTable * symTable = findSymTable(std::string((yyvsp[0].strValue)));
                    if(symTable != NULL && symTable->isSymbolValid(std::string((yyvsp[0].strValue)))) 
                    {
                        value val = symTable->getSymbolValue(std::string((yyvsp[0].strValue)));
                        if(std::holds_alternative<int>(val))
                            (yyval.iValue) = std::get<int>(val);
                    }
                    else 
                        yyerror(std::string("Undeclared variable ") + std::string((yyvsp[-2].strValue)));
                }
#line 1921 "lang.tab.c"
    break;

  case 124: /* INTEGER_EXPRESSION: LVALUE_ELEMENT ACCESS FUNCTION_CALL  */
#line 492 "lang.y"
                                                      {
                    (yyval.iValue) = 0;
                }
#line 1929 "lang.tab.c"
    break;

  case 125: /* INTEGER_EXPRESSION: LVALUE_ELEMENT  */
#line 495 "lang.y"
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
#line 1947 "lang.tab.c"
    break;

  case 126: /* INTEGER_EXPRESSION: FUNCTION_CALL  */
#line 508 "lang.y"
                            {
                (yyval.iValue) = 0;
            }
#line 1955 "lang.tab.c"
    break;

  case 127: /* INTEGER_EXPRESSION: INTEGER  */
#line 511 "lang.y"
                      {
                (yyval.iValue) = (yyvsp[0].iValue);
            }
#line 1963 "lang.tab.c"
    break;

  case 128: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION PLUS INTEGER_EXPRESSION  */
#line 514 "lang.y"
                                                         {
                (yyval.iValue) = (yyvsp[-2].iValue) + (yyvsp[0].iValue);
            }
#line 1971 "lang.tab.c"
    break;

  case 129: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION MUL INTEGER_EXPRESSION  */
#line 517 "lang.y"
                                                        {
                (yyval.iValue) = (yyvsp[-2].iValue) * (yyvsp[0].iValue);
            }
#line 1979 "lang.tab.c"
    break;

  case 130: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION MINUS INTEGER_EXPRESSION  */
#line 520 "lang.y"
                                                          {
                (yyval.iValue) = (yyvsp[-2].iValue) - (yyvsp[0].iValue);
            }
#line 1987 "lang.tab.c"
    break;

  case 131: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION MOD INTEGER_EXPRESSION  */
#line 523 "lang.y"
                                                        {
                (yyval.iValue) = (yyvsp[-2].iValue) % (yyvsp[0].iValue);
            }
#line 1995 "lang.tab.c"
    break;

  case 132: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION DIV INTEGER_EXPRESSION  */
#line 526 "lang.y"
                                                        {
                (yyval.iValue) = (yyvsp[-2].iValue) / (yyvsp[0].iValue);
            }
#line 2003 "lang.tab.c"
    break;

  case 133: /* INTEGER_EXPRESSION: '(' INTEGER_EXPRESSION ')'  */
#line 529 "lang.y"
                                         {
                (yyval.iValue) = (yyvsp[-1].iValue);
            }
#line 2011 "lang.tab.c"
    break;

  case 134: /* FUNCTION_CALL: ID '(' PARAMETER_LIST ')'  */
#line 537 "lang.y"
{
    if(validateStatement()) 
    {
        if(!validateFunction(std::string((yyvsp[-3].strValue)), parameters)) 
        {
            yyerror("Function " + std::string((yyvsp[-3].strValue)) + " was not declared in this scope!\n");
            exit(1);
        }
    } 
    (yyval.iValue) = 0;
    parameters.clear();
}
#line 2028 "lang.tab.c"
    break;

  case 135: /* PARAMETER_LIST: PARAMETER  */
#line 552 "lang.y"
                           {parameters.push_back("int");}
#line 2034 "lang.tab.c"
    break;

  case 136: /* PARAMETER_LIST: PARAMETER ',' PARAMETER_LIST  */
#line 553 "lang.y"
                                              {parameters.push_back("int");}
#line 2040 "lang.tab.c"
    break;

  case 141: /* ARRAY_LITERAL: ID '[' INTEGER_EXPRESSION ']'  */
#line 562 "lang.y"
                                              { strcpy((yyval.strValue), (yyvsp[-3].strValue));}
#line 2046 "lang.tab.c"
    break;


#line 2050 "lang.tab.c"

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

#line 570 "lang.y"


void yyerror(std::string s)
{
    fprintf(stderr, "%s\n", s.c_str());
}

int main(int args, char * argv[])
{
    FILE * f = fopen(argv[1], "r");
    yyin = f;
    ofstream g("log.out");
    g.close();
    symTables.push_back(new SymTable);
    yyparse();
    SymTable * symTable = symTables.back();
    symTable->printVariables();
    delete symTable;
    for(auto funcSymTable : funcSymTables) 
    {
        funcSymTable->printFunctionDescription();
        delete funcSymTable;
    }
    for(auto classSymTable : classSymTables) 
    {
        classSymTable->printClassAttributes();
        delete classSymTable;
    }
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

    for(int j = classSymTables.size() - 1; j >= 0; --j)
    {
        SymTable * symTable = classSymTables[j];
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

    for(int j = classSymTables.size() - 1; j >= 0; --j)
    {
        SymTable * symTable = classSymTables[j];
        if(symTable->isSymbolValid(s))
            return symTable;
    }

    if(funcOn) 
    {
        for(int j = funcSymTables.size() - 1; j >= 0; --j) 
        {
            SymTable * symTable = funcSymTables[j];
            if(symTable->isSymbolValid(s))
                return symTable;
        }
    }

    return NULL;
}

ClassSymTable * getClassSymTable(std::string name)
{
    for(unsigned int i = 0;i < classSymTables.size(); i++)
    {
        if(classSymTables[i]->getSymTableName() == name)
            return classSymTables[i];
    }
    return NULL;
}

bool validateFunction(std::string name, std::vector<std::string> parameters)
{
    for(unsigned int j = 0;j < funcSymTables.size(); j++) 
        if(funcSymTables[j]->getSymTableName() == name && funcSymTables[j]->isParameterMatch(parameters)) 
            return true;

    if(funcSymTables.back()->getSymTableName() == name && funcSymTables.back()->isParameterMatch(parameters))
        return true;
    

    for(unsigned int j = 0; j < classSymTables.size(); j++)
    {
        std::vector<SymTable*> funcSymTables = classSymTables[j]->getFuncSymTables();
        for(unsigned int i = 0;i < funcSymTables.size(); i++) 
        {
            SymTable * symTable = funcSymTables[i];
            std::string funcName = symTable->getSymTableName();
            std::stringstream ss;
            ss << funcName; ss >> funcName >> funcName;
            if(funcName == name && symTable->isParameterMatch(parameters))
                return true;
        }
    }

    return false;
}

bool isClassMember(std::string name)
{
    for(unsigned int i = 0; i < classSymTables.size(); i++) 
        if(classSymTables[i]->getSymTableName() == name)
            return true;
    return false;
}

std::string extractValueFromValue(value value)
{
    if(std::holds_alternative<int>(value)) 
        std::cout << get<int>(value);
    else if(std::holds_alternative<std::string>(value))
        std::cout << get<std::string>(value);
    else if(std::holds_alternative<float>(value))
        std::cout << get<float>(value);
    else if(std::holds_alternative<char>(value))
        std::cout << get<char>(value);
    else if(std::holds_alternative<Complex>(value))
        std::cout << get<Complex>(value);
    else if(std::holds_alternative<bool>(value))
        std::cout << get<bool>(value);
    return "";
}

std::string extractTypeFromVariant(value value)
{
    if(std::holds_alternative<int>(value)) 
        return "int";
    else if(std::holds_alternative<std::string>(value))
        return "string";
    else if(std::holds_alternative<float>(value))
        return "float";
    else if(std::holds_alternative<char>(value))
        return "char";
    else if(std::holds_alternative<Complex>(value))
        return "compl";
    else 
        return "bool";
}

void processUpdate(SymTable * symTable, std::string name, std::string type, value val, char op)
{
    if(op == '=' && !symTable->updateSymbol(name, val) || op != '=' && !symTable->updateSymbol(name, val, op)) 
    {
        yyerror("Variable " + name + " is of type " + symTable->getSymbolType(name) + " not of type " + extractTypeFromVariant(val));
        exit(2);
    }
}

void processAssignmentStatement(SymTable * symTable, std::string name, std::string type, value val, char op)
{
    if(validateStatement()) 
    {    
        symTable = findSymTable(name);
        if(isSymbolValid(name, type)) 
        {
            if(op == '=')
                processUpdate(symTable, name, type, val, op);
            else 
                processUpdate(symTable, name, type, val, op);
        }
        else 
        {
            if(op != '=') 
            {
                yyerror("Undeclared variable " + name + ".Can't modify it!");
                exit(3);
            }
            if(globalAreaOn) 
                unSymbols.push_back({name, val});
            else 
            { 
                yyerror(std::string("Undeclared variable ") + name);
                exit(3);
            }
        }
    }
}
