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

    ///TODO : Ciornei: Refactor Code and Fix Class Sym Tables
    ///TODO : Marciuc: Change Grammar / Add Complex Numbers 

    #include "symtable.h"
    #include "arb.h"
    #include <string>
    #define ERR(errl) std::string("Error on line " + to_string(errl) + ": ")

    using namespace std;
    extern int yylex();
    extern FILE * yyin;
    extern char * yytext;
    extern int yylineno;
    bool globalAreaOn = true, funcOn = false, declOn = false;

    void yyerror(std::string s);
    bool isSymbolValid(std::string s, std::string type);   
    bool validateStatement();
    bool validateFunction(std::string name, std::vector<std::string> parameters);
    void processUpdate(SymTable * symTable, std::string name, std::string type, value val, char op);
    void processAssignmentStatement(arb * arb, std::string name, char op);

    std::string fromValueToString(value val);
    std::string extractValueFromValue(value val);
    std::string extractTypeFromVariant(value value);
    ClassSymTable * getClassSymTable(std::string name);
    bool isClassMember(std::string name);
    SymTable * findSymTable(std::string symbol);
    SymTable * getFunctionSymTable(std::string name);


    SymTable * globalSymTable;
    std::vector<std::pair<std::string, value>> unSymbols;
    std::pair<bool, int> ifController;
    std::vector<SymTable*> symTables, funcSymTables;
    std::vector<ClassSymTable*> classSymTables;
    std::vector<std::string> parameters;


#line 112 "lang.tab.c"

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
  YYSYMBOL_FLOAT_LITERAL = 8,              /* FLOAT_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 9,               /* CHAR_LITERAL  */
  YYSYMBOL_OPEN_WALLET = 10,               /* OPEN_WALLET  */
  YYSYMBOL_CLOSE_WALLET = 11,              /* CLOSE_WALLET  */
  YYSYMBOL_PRINT = 12,                     /* PRINT  */
  YYSYMBOL_TYPEOF = 13,                    /* TYPEOF  */
  YYSYMBOL_PRIVATE = 14,                   /* PRIVATE  */
  YYSYMBOL_PUBLIC = 15,                    /* PUBLIC  */
  YYSYMBOL_PROTECTED = 16,                 /* PROTECTED  */
  YYSYMBOL_CLASS = 17,                     /* CLASS  */
  YYSYMBOL_ACCESS = 18,                    /* ACCESS  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_ELSE_IF = 23,                   /* ELSE_IF  */
  YYSYMBOL_WHILE = 24,                     /* WHILE  */
  YYSYMBOL_FOR = 25,                       /* FOR  */
  YYSYMBOL_SCOPE_START = 26,               /* SCOPE_START  */
  YYSYMBOL_SCOPE_END = 27,                 /* SCOPE_END  */
  YYSYMBOL_INCR = 28,                      /* INCR  */
  YYSYMBOL_DECR = 29,                      /* DECR  */
  YYSYMBOL_RETURN = 30,                    /* RETURN  */
  YYSYMBOL_BOOL_OPERATOR = 31,             /* BOOL_OPERATOR  */
  YYSYMBOL_ADD_OPERATOR = 32,              /* ADD_OPERATOR  */
  YYSYMBOL_MUL_OPERATOR = 33,              /* MUL_OPERATOR  */
  YYSYMBOL_34_ = 34,                       /* '('  */
  YYSYMBOL_35_ = 35,                       /* ')'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* '='  */
  YYSYMBOL_39_ = 39,                       /* '['  */
  YYSYMBOL_40_ = 40,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_MAIN_START = 42,                /* MAIN_START  */
  YYSYMBOL_MAIN_END = 43,                  /* MAIN_END  */
  YYSYMBOL_S = 44,                         /* S  */
  YYSYMBOL_DECL_START = 45,                /* DECL_START  */
  YYSYMBOL_FUNC_START = 46,                /* FUNC_START  */
  YYSYMBOL_FUNCTION_DECLARATION = 47,      /* FUNCTION_DECLARATION  */
  YYSYMBOL_FUNCTION_DEFINITION = 48,       /* FUNCTION_DEFINITION  */
  YYSYMBOL_DECL_PARAMETER_SEQUENCE = 49,   /* DECL_PARAMETER_SEQUENCE  */
  YYSYMBOL_CLASS_BEGIN_ELEMENT = 50,       /* CLASS_BEGIN_ELEMENT  */
  YYSYMBOL_CLASS_BEGIN = 51,               /* CLASS_BEGIN  */
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
  YYSYMBOL_FOR_START = 66,                 /* FOR_START  */
  YYSYMBOL_FOR_STATEMENT = 67,             /* FOR_STATEMENT  */
  YYSYMBOL_INIT_DECL_COMP = 68,            /* INIT_DECL_COMP  */
  YYSYMBOL_STOP_CONDITION_COMP = 69,       /* STOP_CONDITION_COMP  */
  YYSYMBOL_MODIFY_COMP = 70,               /* MODIFY_COMP  */
  YYSYMBOL_LINE_INITIALIZATION = 71,       /* LINE_INITIALIZATION  */
  YYSYMBOL_WHILE_STATEMENT = 72,           /* WHILE_STATEMENT  */
  YYSYMBOL_WHILE_BLOCK = 73,               /* WHILE_BLOCK  */
  YYSYMBOL_IF_BLOCK = 74,                  /* IF_BLOCK  */
  YYSYMBOL_IF_COMPOSITION = 75,            /* IF_COMPOSITION  */
  YYSYMBOL_IF_STRUCTURE = 76,              /* IF_STRUCTURE  */
  YYSYMBOL_IF_STATEMENT = 77,              /* IF_STATEMENT  */
  YYSYMBOL_ELSE_BLOCKS = 78,               /* ELSE_BLOCKS  */
  YYSYMBOL_ELSE_IF_BLOCK = 79,             /* ELSE_IF_BLOCK  */
  YYSYMBOL_ELSE_BLOCK = 80,                /* ELSE_BLOCK  */
  YYSYMBOL_ELSE_IF_STATEMENT = 81,         /* ELSE_IF_STATEMENT  */
  YYSYMBOL_ELSE_STATEMENT = 82,            /* ELSE_STATEMENT  */
  YYSYMBOL_MAIN = 83,                      /* MAIN  */
  YYSYMBOL_MUL_STATEMENTS = 84,            /* MUL_STATEMENTS  */
  YYSYMBOL_CODE_AREA_ELEMENT = 85,         /* CODE_AREA_ELEMENT  */
  YYSYMBOL_CODE_AREA = 86,                 /* CODE_AREA  */
  YYSYMBOL_STATEMENT = 87,                 /* STATEMENT  */
  YYSYMBOL_LVALUE_ELEMENT = 88,            /* LVALUE_ELEMENT  */
  YYSYMBOL_CLASS_LITERAL = 89,             /* CLASS_LITERAL  */
  YYSYMBOL_RETURN_STATEMENT = 90,          /* RETURN_STATEMENT  */
  YYSYMBOL_ASSIGNMENT_STATEMENT = 91,      /* ASSIGNMENT_STATEMENT  */
  YYSYMBOL_PRINT_STATEMENT = 92,           /* PRINT_STATEMENT  */
  YYSYMBOL_TYPE_OF_STATEMENT = 93,         /* TYPE_OF_STATEMENT  */
  YYSYMBOL_EXPRESSION_LITERAL = 94,        /* EXPRESSION_LITERAL  */
  YYSYMBOL_EXPRESSION = 95,                /* EXPRESSION  */
  YYSYMBOL_BOOLEAN_EXPRESSION = 96,        /* BOOLEAN_EXPRESSION  */
  YYSYMBOL_FUNCTION_CALL = 97,             /* FUNCTION_CALL  */
  YYSYMBOL_PARAMETER_LIST = 98,            /* PARAMETER_LIST  */
  YYSYMBOL_PARAMETER = 99,                 /* PARAMETER  */
  YYSYMBOL_ARRAY_LITERAL = 100,            /* ARRAY_LITERAL  */
  YYSYMBOL_ARRAY_DECLARATION = 101         /* ARRAY_DECLARATION  */
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
#define YYLAST   247

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
      34,    35,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
       2,    38,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,    87,    89,   100,   102,   104,   106,   108,
     114,   120,   127,   128,   130,   132,   133,   135,   136,   139,
     149,   158,   168,   177,   186,   196,   197,   198,   208,   232,
     238,   239,   242,   243,   248,   249,   251,   252,   253,   254,
     260,   262,   266,   274,   275,   276,   280,   282,   284,   285,
     286,   288,   290,   293,   294,   298,   300,   304,   308,   313,
     314,   316,   325,   326,   328,   329,   331,   333,   341,   349,
     351,   352,   354,   355,   356,   357,   360,   361,   366,   367,
     368,   369,   370,   371,   374,   375,   376,   378,   395,   396,
     398,   399,   400,   401,   402,   403,   408,   415,   425,   432,
     444,   445,   446,   447,   448,   449,   461,   462,   464,   465,
     466,   472,   473,   474,   475,   482,   503,   504,   505,   507,
     511,   513,   514,   515
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
  "TYPE", "BOOLEAN_LITERAL", "STRING_LITERAL", "FLOAT_LITERAL",
  "CHAR_LITERAL", "OPEN_WALLET", "CLOSE_WALLET", "PRINT", "TYPEOF",
  "PRIVATE", "PUBLIC", "PROTECTED", "CLASS", "ACCESS", "AND", "OR", "IF",
  "ELSE", "ELSE_IF", "WHILE", "FOR", "SCOPE_START", "SCOPE_END", "INCR",
  "DECR", "RETURN", "BOOL_OPERATOR", "ADD_OPERATOR", "MUL_OPERATOR", "'('",
  "')'", "','", "';'", "'='", "'['", "']'", "$accept", "MAIN_START",
  "MAIN_END", "S", "DECL_START", "FUNC_START", "FUNCTION_DECLARATION",
  "FUNCTION_DEFINITION", "DECL_PARAMETER_SEQUENCE", "CLASS_BEGIN_ELEMENT",
  "CLASS_BEGIN", "CLASS_DEFINITION", "CLASS_MEMBER_LIST", "CLASS_MEMBER",
  "ACCESS_MODIFIER", "LINE_DECLARATION", "IDSEQUENCE",
  "ID_SEQUENCE_ELEMENT", "DECLARATIONS", "DECLARATIONS_ELEMENT", "SCOPE",
  "BEGIN_SCOPE", "END_SCOPE", "BLOCK", "FOR_BLOCK", "FOR_START",
  "FOR_STATEMENT", "INIT_DECL_COMP", "STOP_CONDITION_COMP", "MODIFY_COMP",
  "LINE_INITIALIZATION", "WHILE_STATEMENT", "WHILE_BLOCK", "IF_BLOCK",
  "IF_COMPOSITION", "IF_STRUCTURE", "IF_STATEMENT", "ELSE_BLOCKS",
  "ELSE_IF_BLOCK", "ELSE_BLOCK", "ELSE_IF_STATEMENT", "ELSE_STATEMENT",
  "MAIN", "MUL_STATEMENTS", "CODE_AREA_ELEMENT", "CODE_AREA", "STATEMENT",
  "LVALUE_ELEMENT", "CLASS_LITERAL", "RETURN_STATEMENT",
  "ASSIGNMENT_STATEMENT", "PRINT_STATEMENT", "TYPE_OF_STATEMENT",
  "EXPRESSION_LITERAL", "EXPRESSION", "BOOLEAN_EXPRESSION",
  "FUNCTION_CALL", "PARAMETER_LIST", "PARAMETER", "ARRAY_LITERAL",
  "ARRAY_DECLARATION", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-187)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-33)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     182,    12,  -187,  -187,  -187,  -187,  -187,    37,    39,    50,
      25,  -187,    41,    45,    27,    70,    58,    88,   182,  -187,
    -187,   155,  -187,    69,   131,  -187,  -187,  -187,    97,    72,
    -187,  -187,    98,  -187,  -187,  -187,  -187,   127,  -187,  -187,
     199,   107,   114,  -187,  -187,   106,   109,    43,   126,   124,
    -187,    39,   137,  -187,   140,  -187,    50,    14,   134,   136,
      82,    82,  -187,  -187,    82,   107,   153,  -187,   127,  -187,
    -187,   154,   124,   124,  -187,  -187,  -187,  -187,   124,   189,
    -187,   127,  -187,    87,   143,  -187,  -187,  -187,  -187,  -187,
     -21,  -187,  -187,  -187,  -187,  -187,   186,  -187,    -2,  -187,
      38,  -187,  -187,   199,   199,   199,   133,  -187,    50,  -187,
     175,  -187,  -187,  -187,    39,   180,  -187,   199,    82,    82,
      82,   151,   200,   200,   151,   200,  -187,   194,    19,  -187,
    -187,   201,  -187,  -187,  -187,    81,  -187,   219,   219,   199,
     199,  -187,   133,   133,   101,  -187,  -187,   188,  -187,   133,
     191,   192,   178,   102,   183,   158,   160,   199,    82,    82,
    -187,  -187,     1,  -187,   190,  -187,   193,  -187,    82,  -187,
     208,  -187,   124,   124,  -187,   197,  -187,  -187,   202,  -187,
      43,  -187,  -187,  -187,   199,  -187,  -187,  -187,  -187,  -187,
     133,  -187,   213,    82,   230,   200,  -187,   211,  -187,    64,
     196,  -187,   203,   200,   198,  -187,  -187,  -187,  -187,   230,
     204,  -187,  -187
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     5,    25,    26,    27,    13,     0,     0,    11,
       0,    39,     0,     0,     0,     0,     0,     0,    34,    29,
       1,    84,    28,    30,     0,    86,    33,    85,     0,     0,
      37,    14,     0,    38,    12,    36,     2,     0,    35,     6,
       0,     0,     0,    94,    95,     0,     0,     0,    10,     7,
      16,     0,     0,    23,     0,    18,     0,    84,     0,     0,
       0,     0,    47,    41,     0,     0,     0,    75,     0,    72,
      45,     0,     0,     0,    44,    43,    57,    58,     0,     0,
      73,    76,    69,     0,     0,    82,    78,    79,    80,    81,
      84,   100,   102,   101,   103,   104,   105,   108,     0,   106,
      84,    31,    87,     0,     0,     0,    90,    91,    11,     8,
       0,    22,    15,    17,     0,     0,    24,   118,     0,     0,
       0,     0,    61,    55,    88,    89,    74,     0,     0,    46,
      56,    59,     3,     4,    77,     0,    70,     0,     0,     0,
       0,   120,    92,    93,     0,     9,    21,     0,    20,   119,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
      42,    40,    84,    49,     0,    50,    53,    68,     0,    60,
       0,    63,     0,     0,    71,    87,    83,   107,   109,   110,
       0,   122,    19,   115,   118,    96,    97,    98,    99,   113,
     114,   111,   112,     0,     0,    67,    62,    64,    66,     0,
       0,   117,     0,    51,    84,    54,    65,   121,   123,     0,
       0,    52,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -187,  -187,  -187,  -187,     7,  -187,     2,    22,   130,  -187,
    -187,  -187,  -187,   187,   -27,     3,   -31,  -187,   224,  -187,
     -37,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -186,  -187,  -187,  -187,  -187,  -187,  -187,  -187,    46,    74,
    -187,  -187,  -187,   110,  -187,   -62,  -187,    -8,  -187,  -187,
     -36,  -187,  -187,  -187,   -38,   -50,    -9,    62,  -187,  -187,
      67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    37,   133,     7,    65,     9,    10,    11,    29,    12,
      13,    14,    54,    55,    15,    66,    22,    23,    17,    18,
      67,    68,   161,    69,    70,    71,    72,   164,   202,   210,
     165,    73,    74,    75,    76,    77,    78,   169,   170,   171,
     172,   173,    79,    80,    81,    82,    83,    96,    25,    85,
      26,    87,    88,    97,   121,   122,    99,   150,   151,    27,
     107
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    86,    98,    16,    19,    56,   127,     8,   205,   106,
     101,   123,   109,   117,   125,    19,    28,    19,    40,   134,
     110,    16,   162,   211,     2,     8,   124,    56,    89,    84,
     139,   140,    86,    24,    52,   129,   130,    20,   141,    51,
      40,   131,    21,    24,    31,    86,    90,    91,   117,    92,
      93,    94,    95,    40,    53,     2,    52,    24,   115,    89,
      84,    51,    30,   114,    33,   142,   143,   144,   153,   155,
     156,    32,    89,    84,   -32,   -32,    53,    40,   116,   149,
     152,   154,   105,   147,    90,    90,    91,    34,    92,    93,
      94,    95,   166,    58,    59,    35,   139,   140,    36,    86,
      48,   178,   179,     2,   207,    41,    24,    49,   191,   192,
     100,    64,     3,     4,     5,    28,   120,   102,   195,   190,
      24,   158,   159,   135,   136,    50,    89,    84,   176,   177,
      57,   163,     2,   139,   140,   197,   198,   186,   180,    58,
      59,   181,   199,   203,   103,     2,   149,   104,    60,    42,
      63,    61,    62,    63,     3,     4,     5,    64,   166,    43,
      44,   137,   108,    45,    46,   139,   140,   112,   118,    47,
     119,    43,    44,   166,   111,    45,    46,   158,   159,   158,
     159,    47,   157,   139,   140,     1,    24,     2,   128,    39,
     126,   -32,   -32,   188,    40,   189,     3,     4,     5,     6,
     132,    24,    90,    91,   138,    92,    93,    94,    95,   157,
     139,   140,   146,   185,   157,   139,   140,   148,   187,   158,
     159,   160,   175,   167,   168,   182,   183,   193,   184,   194,
     167,   117,   158,   204,   168,   140,   208,    40,   145,   212,
     209,   113,    38,   206,   196,   174,   201,   200
};

static const yytype_uint8 yycheck[] =
{
       8,    37,    40,     0,     3,    32,    68,     0,   194,    47,
      41,    61,    49,    34,    64,     3,     9,     3,    39,    81,
      51,    18,     3,   209,     5,    18,    64,    54,    37,    37,
      32,    33,    68,    41,    32,    72,    73,     0,    40,    32,
      39,    78,     3,    51,     3,    81,     3,     4,    34,     6,
       7,     8,     9,    39,    32,     5,    54,    65,    56,    68,
      68,    54,    37,    56,    37,   103,   104,   105,   118,   119,
     120,    26,    81,    81,    36,    37,    54,    39,    56,   117,
     118,   119,    39,   114,     3,     3,     4,    17,     6,     7,
       8,     9,   128,    12,    13,    37,    32,    33,    10,   135,
       3,   139,   140,     5,    40,    36,   114,    35,   158,   159,
       3,    30,    14,    15,    16,   108,    34,     3,   168,   157,
     128,    19,    20,    36,    37,    27,   135,   135,   137,   138,
       3,   128,     5,    32,    33,   172,   173,    35,    37,    12,
      13,    40,   180,   193,    38,     5,   184,    38,    21,    18,
      26,    24,    25,    26,    14,    15,    16,    30,   194,    28,
      29,    18,    36,    32,    33,    32,    33,    27,    34,    38,
      34,    28,    29,   209,    37,    32,    33,    19,    20,    19,
      20,    38,    31,    32,    33,     3,   194,     5,    34,    34,
      37,    36,    37,    35,    39,    35,    14,    15,    16,    17,
      11,   209,     3,     4,    18,     6,     7,     8,     9,    31,
      32,    33,    37,    35,    31,    32,    33,    37,    35,    19,
      20,    27,     3,    22,    23,    37,    35,    37,    36,    36,
      22,    34,    19,     3,    23,    33,    40,    39,   108,    35,
      37,    54,    18,   197,   170,   135,   184,   180
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,    14,    15,    16,    17,    44,    45,    46,
      47,    48,    50,    51,    52,    55,    56,    59,    60,     3,
       0,     3,    57,    58,    88,    89,    91,   100,    45,    49,
      37,     3,    26,    37,    17,    37,    10,    42,    59,    34,
      39,    36,    18,    28,    29,    32,    33,    38,     3,    35,
      27,    45,    47,    48,    53,    54,    55,     3,    12,    13,
      21,    24,    25,    26,    30,    45,    56,    61,    62,    64,
      65,    66,    67,    72,    73,    74,    75,    76,    77,    83,
      84,    85,    86,    87,    88,    90,    91,    92,    93,    97,
       3,     4,     6,     7,     8,     9,    88,    94,    95,    97,
       3,    57,     3,    38,    38,    39,    95,   101,    36,    61,
      57,    37,    27,    54,    45,    47,    48,    34,    34,    34,
      34,    95,    96,    96,    95,    96,    37,    86,    34,    61,
      61,    61,    11,    43,    86,    36,    37,    18,    18,    32,
      33,    40,    95,    95,    95,    49,    37,    57,    37,    95,
      98,    99,    95,    96,    95,    96,    96,    31,    19,    20,
      27,    63,     3,    56,    68,    71,    91,    22,    23,    78,
      79,    80,    81,    82,    84,     3,    97,    97,    95,    95,
      37,    40,    37,    35,    36,    35,    35,    35,    35,    35,
      95,    96,    96,    37,    36,    96,    80,    61,    61,    95,
     101,    98,    69,    96,     3,    71,    79,    40,    40,    37,
      70,    71,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      49,    49,    50,    50,    51,    52,    52,    53,    53,    54,
      54,    54,    54,    54,    54,    55,    55,    55,    56,    56,
      57,    57,    58,    58,    59,    59,    60,    60,    60,    60,
      61,    62,    63,    64,    64,    64,    65,    66,    67,    68,
      68,    69,    70,    71,    71,    72,    73,    74,    75,    76,
      76,    77,    78,    78,    79,    79,    80,    81,    82,    83,
      84,    84,    85,    85,    85,    85,    86,    86,    87,    87,
      87,    87,    87,    87,    88,    88,    88,    89,    90,    90,
      91,    91,    91,    91,    91,    91,    92,    92,    93,    93,
      94,    94,    94,    94,    94,    94,    94,    94,    95,    95,
      95,    96,    96,    96,    96,    97,    98,    98,    98,    99,
     100,   101,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     4,     1,     3,     3,     4,     4,
       2,     0,     2,     1,     2,     4,     3,     2,     1,     4,
       3,     3,     2,     1,     2,     1,     1,     1,     2,     2,
       1,     3,     1,     1,     1,     2,     2,     2,     2,     1,
       3,     1,     1,     1,     1,     1,     2,     1,     8,     1,
       1,     1,     1,     1,     3,     2,     2,     1,     1,     2,
       3,     2,     2,     1,     2,     3,     2,     2,     1,     1,
       2,     3,     1,     1,     2,     1,     1,     2,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     2,     2,
       3,     3,     4,     4,     2,     2,     4,     4,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     4,     1,     3,     0,     1,
       4,     5,     3,     5
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
  case 2: /* MAIN_START: OPEN_WALLET  */
#line 86 "lang.y"
                         {globalAreaOn = false; }
#line 1369 "lang.tab.c"
    break;

  case 4: /* S: DECLARATIONS MAIN_START MAIN MAIN_END  */
#line 89 "lang.y"
                                          {
        printf("Program compiled succesfully!\n");
        return 0;
}
#line 1378 "lang.tab.c"
    break;

  case 5: /* DECL_START: TYPE  */
#line 100 "lang.y"
                  {declOn = true; strcpy((yyval.strValue), (yyvsp[0].strValue)); }
#line 1384 "lang.tab.c"
    break;

  case 6: /* FUNC_START: DECL_START ID '('  */
#line 102 "lang.y"
                               { funcOn = true; funcSymTables.push_back(new SymTable(std::string((yyvsp[-2].strValue)), std::string((yyvsp[-1].strValue)))); declOn = false;}
#line 1390 "lang.tab.c"
    break;

  case 7: /* FUNCTION_DECLARATION: FUNC_START DECL_PARAMETER_SEQUENCE ')'  */
#line 104 "lang.y"
                                                              { funcOn = false; }
#line 1396 "lang.tab.c"
    break;

  case 8: /* FUNCTION_DEFINITION: FUNC_START DECL_PARAMETER_SEQUENCE ')' SCOPE  */
#line 106 "lang.y"
                                                                   { funcOn = false; }
#line 1402 "lang.tab.c"
    break;

  case 9: /* DECL_PARAMETER_SEQUENCE: DECL_START ID ',' DECL_PARAMETER_SEQUENCE  */
#line 108 "lang.y"
                                                                    {
                            SymTable * symTable = funcSymTables.back();
                            symTable->addParameter(std::string((yyvsp[-3].strValue)));
                            symTable->addSymbol(std::string((yyvsp[-2].strValue)), std::string((yyvsp[-3].strValue)));
                            declOn = false;
                        }
#line 1413 "lang.tab.c"
    break;

  case 10: /* DECL_PARAMETER_SEQUENCE: DECL_START ID  */
#line 114 "lang.y"
                                         {
                            SymTable * symTable = funcSymTables.back();
                            symTable->addParameter(std::string((yyvsp[-1].strValue)));
                            symTable->addSymbol(std::string((yyvsp[0].strValue)), std::string((yyvsp[-1].strValue)));
                            declOn = false;
                        }
#line 1424 "lang.tab.c"
    break;

  case 12: /* CLASS_BEGIN_ELEMENT: ACCESS_MODIFIER CLASS  */
#line 127 "lang.y"
                                            {strcpy((yyval.strValue), (yyvsp[-1].strValue));}
#line 1430 "lang.tab.c"
    break;

  case 13: /* CLASS_BEGIN_ELEMENT: CLASS  */
#line 128 "lang.y"
                            {strcpy((yyval.strValue), "public");}
#line 1436 "lang.tab.c"
    break;

  case 14: /* CLASS_BEGIN: CLASS_BEGIN_ELEMENT ID  */
#line 130 "lang.y"
                                     {classSymTables.push_back(new ClassSymTable(std::string((yyvsp[-1].strValue)), std::string((yyvsp[0].strValue))));}
#line 1442 "lang.tab.c"
    break;

  case 19: /* CLASS_MEMBER: ACCESS_MODIFIER DECL_START IDSEQUENCE ';'  */
#line 139 "lang.y"
                                                         {
                ClassSymTable * symTable = classSymTables.back();
                for(auto [name, value] : unSymbols) 
                {
                    std::string className = std::string((yyvsp[-3].strValue)) + " " + name;
                    symTable->addSymbol(className, std::string((yyvsp[-2].strValue)));
                    processUpdate(symTable, className, std::string((yyvsp[-2].strValue)), value, '=');
                }
                declOn = false;
            }
#line 1457 "lang.tab.c"
    break;

  case 20: /* CLASS_MEMBER: ACCESS_MODIFIER FUNCTION_DECLARATION ';'  */
#line 149 "lang.y"
                                                        {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = std::string((yyvsp[-2].strValue)) + " " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
#line 1471 "lang.tab.c"
    break;

  case 21: /* CLASS_MEMBER: DECL_START IDSEQUENCE ';'  */
#line 158 "lang.y"
                                         {
                ClassSymTable * symTable = classSymTables.back();
                for(auto [name, value] : unSymbols) 
                {
                    std::string className = "private " + name;
                    symTable->addSymbol(className, std::string((yyvsp[-2].strValue)));
                    processUpdate(symTable, className, std::string((yyvsp[-2].strValue)), value, '=');
                }
                declOn = false;
             }
#line 1486 "lang.tab.c"
    break;

  case 22: /* CLASS_MEMBER: FUNCTION_DECLARATION ';'  */
#line 168 "lang.y"
                                        {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = "private " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
#line 1500 "lang.tab.c"
    break;

  case 23: /* CLASS_MEMBER: FUNCTION_DEFINITION  */
#line 177 "lang.y"
                                   {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = "private " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
#line 1514 "lang.tab.c"
    break;

  case 24: /* CLASS_MEMBER: ACCESS_MODIFIER FUNCTION_DEFINITION  */
#line 186 "lang.y"
                                                   {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = std::string((yyvsp[-1].strValue)) + " " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
#line 1528 "lang.tab.c"
    break;

  case 25: /* ACCESS_MODIFIER: PRIVATE  */
#line 196 "lang.y"
                          {strcpy((yyval.strValue), (yyvsp[0].strValue));}
#line 1534 "lang.tab.c"
    break;

  case 26: /* ACCESS_MODIFIER: PUBLIC  */
#line 197 "lang.y"
                         {strcpy((yyval.strValue), (yyvsp[0].strValue));}
#line 1540 "lang.tab.c"
    break;

  case 27: /* ACCESS_MODIFIER: PROTECTED  */
#line 198 "lang.y"
                            {strcpy((yyval.strValue), (yyvsp[0].strValue));}
#line 1546 "lang.tab.c"
    break;

  case 28: /* LINE_DECLARATION: DECL_START IDSEQUENCE  */
#line 208 "lang.y"
                                         {
            SymTable * symTable = symTables.back();
            bool ok = 0;
            for(unsigned int i = 0;i < unSymbols.size(); i++)
            {
                std::string symbol = unSymbols[i].first;
                if(symTable->isSymbolValid(symbol)) 
                {
                    ok = 1;
                    yyerror(ERR(yylineno) + symbol + " already declared!");
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
            declOn = false;
        }
#line 1575 "lang.tab.c"
    break;

  case 29: /* LINE_DECLARATION: ID ID  */
#line 232 "lang.y"
                {
            SymTable * symTable = symTables.back();
            symTable->addSymbol(std::string((yyvsp[0].strValue)), std::string((yyvsp[-1].strValue)));
        }
#line 1584 "lang.tab.c"
    break;

  case 32: /* ID_SEQUENCE_ELEMENT: ID  */
#line 242 "lang.y"
                         {unSymbols.push_back({(yyvsp[0].strValue), 0});}
#line 1590 "lang.tab.c"
    break;

  case 41: /* BEGIN_SCOPE: SCOPE_START  */
#line 262 "lang.y"
                          {
    symTables.push_back(new SymTable);
}
#line 1598 "lang.tab.c"
    break;

  case 42: /* END_SCOPE: SCOPE_END  */
#line 266 "lang.y"
                      {
    SymTable * symTable = symTables.back();
    delete symTable;
    symTables.pop_back();
}
#line 1608 "lang.tab.c"
    break;

  case 46: /* FOR_BLOCK: FOR_STATEMENT SCOPE  */
#line 280 "lang.y"
                                { symTables.pop_back(); }
#line 1614 "lang.tab.c"
    break;

  case 47: /* FOR_START: FOR  */
#line 282 "lang.y"
                { symTables.push_back(new SymTable); }
#line 1620 "lang.tab.c"
    break;

  case 57: /* IF_BLOCK: IF_COMPOSITION  */
#line 304 "lang.y"
                          {
    ifController = {false, 0};
}
#line 1628 "lang.tab.c"
    break;

  case 58: /* IF_COMPOSITION: IF_STRUCTURE  */
#line 308 "lang.y"
                              {
                      if(ifController.first)
                        ifController.second = -1;
                }
#line 1637 "lang.tab.c"
    break;

  case 61: /* IF_STATEMENT: IF BOOLEAN_EXPRESSION  */
#line 317 "lang.y"
{
    ifController = {true, 0};
    if((yyvsp[0].tree)->hasConflictingTypes()) 
        yyerror(ERR(yylineno) + "Invalid Expression in if statement\n");
    else if((yyvsp[0].tree)->getExpressionType()!="bool" && (yyvsp[0].tree)->getExpressionResult()!="0" || (yyvsp[0].tree)->getExpressionType()=="bool" && (yyvsp[0].tree)->getExpressionResult()=="true") 
        ifController.second = 1;
}
#line 1649 "lang.tab.c"
    break;

  case 67: /* ELSE_IF_STATEMENT: ELSE_IF BOOLEAN_EXPRESSION  */
#line 333 "lang.y"
                                                 {
    if(ifController.second) ifController.second = -1;
    if((yyvsp[0].tree)->hasConflictingTypes()) 
        yyerror(ERR(yylineno) + "Invalid Expression in else if statement\n");
    else if(((yyvsp[0].tree)->getExpressionType()!="bool" && (yyvsp[0].tree)->getExpressionResult()!="0" || (yyvsp[0].tree)->getExpressionType()=="bool" && (yyvsp[0].tree)->getExpressionResult()=="true") && ifController.second == 0)
        ifController.second = 1;
}
#line 1661 "lang.tab.c"
    break;

  case 68: /* ELSE_STATEMENT: ELSE  */
#line 341 "lang.y"
                      {
    if(!ifController.second)
         ifController.second = 1;
}
#line 1670 "lang.tab.c"
    break;

  case 87: /* CLASS_LITERAL: LVALUE_ELEMENT ACCESS ID  */
#line 378 "lang.y"
                                         {
    if(isClassMember((yyvsp[-2].strValue))) 
    {
        ClassSymTable * classSymTable = getClassSymTable((yyvsp[-2].strValue));
        if(classSymTable == NULL)
            yyerror(ERR(yylineno) + "Class Identifier " + std::string((yyvsp[-2].strValue)) + " doesn't exist!\n");
        else 
        {
            if(!classSymTable->isSymbolInClass(std::string((yyvsp[0].strValue)))) 
                yyerror(ERR(yylineno) + std::string("Identifier " + std::string((yyvsp[0].strValue)) + " doesn't exist in class " + std::string((yyvsp[-2].strValue))));
            else if(classSymTable->getSymbolPrivacy(std::string((yyvsp[0].strValue))) != "public")
                yyerror(ERR(yylineno) + "Identifier " + std::string((yyvsp[0].strValue)) + " is " + classSymTable->getSymbolPrivacy(std::string((yyvsp[0].strValue))) + " in the context of class " + std::string((yyvsp[-2].strValue)));
        }
    }
    strcpy((yyval.strValue), (yyvsp[0].strValue));
}
#line 1691 "lang.tab.c"
    break;

  case 90: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' EXPRESSION  */
#line 398 "lang.y"
                                                     { processAssignmentStatement((yyvsp[0].tree), std::string((yyvsp[-2].strValue)), '='); }
#line 1697 "lang.tab.c"
    break;

  case 91: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' ARRAY_DECLARATION  */
#line 399 "lang.y"
                                                            {if(declOn) unSymbols.push_back({std::string((yyvsp[-2].strValue)), 0});}
#line 1703 "lang.tab.c"
    break;

  case 92: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT ADD_OPERATOR '=' EXPRESSION  */
#line 400 "lang.y"
                                                                  { processAssignmentStatement((yyvsp[0].tree), std::string((yyvsp[-3].strValue)), std::string((yyvsp[-2].strValue))[0]);}
#line 1709 "lang.tab.c"
    break;

  case 93: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT MUL_OPERATOR '=' EXPRESSION  */
#line 401 "lang.y"
                                                                  { processAssignmentStatement((yyvsp[0].tree), std::string((yyvsp[-3].strValue)), std::string((yyvsp[-2].strValue))[0]);}
#line 1715 "lang.tab.c"
    break;

  case 96: /* PRINT_STATEMENT: PRINT '(' EXPRESSION ')'  */
#line 409 "lang.y"
                  {
                    if((yyvsp[-1].tree)->hasConflictingTypes()) 
                        yyerror(ERR(yylineno) + "Invalid Expression in print statement!\n");
                    else if(validateStatement()) 
                        std::cout << (yyvsp[-1].tree)->getExpressionResult() << '\n';
                  }
#line 1726 "lang.tab.c"
    break;

  case 97: /* PRINT_STATEMENT: PRINT '(' BOOLEAN_EXPRESSION ')'  */
#line 416 "lang.y"
                  {
                     if((yyvsp[-1].tree)->hasConflictingTypes()) 
                        yyerror(ERR(yylineno) + "Invalid Expression in print statement!\n");
                    else if(validateStatement()) 
                        std::cout << (yyvsp[-1].tree)->getExpressionResult() << '\n';
                  }
#line 1737 "lang.tab.c"
    break;

  case 98: /* TYPE_OF_STATEMENT: TYPEOF '(' EXPRESSION ')'  */
#line 426 "lang.y"
                    {
                        if((yyvsp[-1].tree)->hasConflictingTypes()) 
                            yyerror(ERR(yylineno) + "Invalid Expression in typeof statement!\n");
                        else if(validateStatement()) 
                            std::cout << (yyvsp[-1].tree)->getExpressionType() << '\n';
                    }
#line 1748 "lang.tab.c"
    break;

  case 99: /* TYPE_OF_STATEMENT: TYPEOF '(' BOOLEAN_EXPRESSION ')'  */
#line 433 "lang.y"
                    {
                        if((yyvsp[-1].tree)->hasConflictingTypes()) 
                            yyerror(ERR(yylineno) + "Invalid Expression in typeof statement!\n");
                        else if(validateStatement()) {
                            std::cout << (yyvsp[-1].tree)->getExpressionType() << '\n';
                        }
                    }
#line 1760 "lang.tab.c"
    break;

  case 100: /* EXPRESSION_LITERAL: INTEGER  */
#line 444 "lang.y"
                              {(yyval.tree) = new arb(fromValueToString((yyvsp[0].iValue)),"int");}
#line 1766 "lang.tab.c"
    break;

  case 101: /* EXPRESSION_LITERAL: STRING_LITERAL  */
#line 445 "lang.y"
                                     {(yyval.tree) = new arb(fromValueToString(std::string((yyvsp[0].strValue))),"string");}
#line 1772 "lang.tab.c"
    break;

  case 102: /* EXPRESSION_LITERAL: BOOLEAN_LITERAL  */
#line 446 "lang.y"
                                      {(yyval.tree) = new arb(fromValueToString((yyvsp[0].bValue)),"bool");}
#line 1778 "lang.tab.c"
    break;

  case 103: /* EXPRESSION_LITERAL: FLOAT_LITERAL  */
#line 447 "lang.y"
                                    {(yyval.tree) = new arb(fromValueToString((yyvsp[0].fValue)),"float");}
#line 1784 "lang.tab.c"
    break;

  case 104: /* EXPRESSION_LITERAL: CHAR_LITERAL  */
#line 448 "lang.y"
                                   {(yyval.tree) = new arb(fromValueToString((yyvsp[0].cValue)),"char");}
#line 1790 "lang.tab.c"
    break;

  case 105: /* EXPRESSION_LITERAL: LVALUE_ELEMENT  */
#line 449 "lang.y"
                                     {
                        SymTable * symTable = findSymTable(std::string((yyvsp[0].strValue)));
                        if(symTable != NULL && symTable->isSymbolValid(std::string((yyvsp[0].strValue)))) 
                        {
                            value val = symTable->getSymbolValue(std::string((yyvsp[0].strValue)));
                            (yyval.tree) = new arb(fromValueToString(val), extractTypeFromVariant(val));
                        }
                        else {
                            yyerror(ERR(yylineno) + std::string("Undeclared variable ") + std::string((yyvsp[0].strValue)));
                            (yyval.tree) = new arb("0", "int");
                        }
                    }
#line 1807 "lang.tab.c"
    break;

  case 106: /* EXPRESSION_LITERAL: FUNCTION_CALL  */
#line 461 "lang.y"
                                    {(yyval.tree) = (yyvsp[0].tree);}
#line 1813 "lang.tab.c"
    break;

  case 107: /* EXPRESSION_LITERAL: LVALUE_ELEMENT ACCESS FUNCTION_CALL  */
#line 462 "lang.y"
                                                          {(yyval.tree) = (yyvsp[0].tree);}
#line 1819 "lang.tab.c"
    break;

  case 108: /* EXPRESSION: EXPRESSION_LITERAL  */
#line 464 "lang.y"
                                {(yyval.tree) = (yyvsp[0].tree);}
#line 1825 "lang.tab.c"
    break;

  case 109: /* EXPRESSION: EXPRESSION ADD_OPERATOR EXPRESSION  */
#line 465 "lang.y"
                                                {(yyval.tree) = new arb((yyvsp[-1].strValue),"",(yyvsp[-2].tree),(yyvsp[0].tree));}
#line 1831 "lang.tab.c"
    break;

  case 110: /* EXPRESSION: EXPRESSION MUL_OPERATOR EXPRESSION  */
#line 466 "lang.y"
                                                {(yyval.tree) = new arb((yyvsp[-1].strValue),"",(yyvsp[-2].tree),(yyvsp[0].tree));}
#line 1837 "lang.tab.c"
    break;

  case 111: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION AND BOOLEAN_EXPRESSION  */
#line 472 "lang.y"
                                                                {(yyval.tree) = new arb("&&","",(yyvsp[-2].tree),(yyvsp[0].tree));}
#line 1843 "lang.tab.c"
    break;

  case 112: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION OR BOOLEAN_EXPRESSION  */
#line 473 "lang.y"
                                                               {(yyval.tree) = new arb("||","",(yyvsp[-2].tree),(yyvsp[0].tree));}
#line 1849 "lang.tab.c"
    break;

  case 113: /* BOOLEAN_EXPRESSION: '(' BOOLEAN_EXPRESSION ')'  */
#line 474 "lang.y"
                                                 {(yyval.tree) = (yyvsp[-1].tree);}
#line 1855 "lang.tab.c"
    break;

  case 114: /* BOOLEAN_EXPRESSION: EXPRESSION BOOL_OPERATOR EXPRESSION  */
#line 475 "lang.y"
                                                          {(yyval.tree) = new arb((yyvsp[-1].strValue),"",(yyvsp[-2].tree),(yyvsp[0].tree));}
#line 1861 "lang.tab.c"
    break;

  case 115: /* FUNCTION_CALL: ID '(' PARAMETER_LIST ')'  */
#line 483 "lang.y"
{
    if(validateStatement()) 
    {
        if(!validateFunction(std::string((yyvsp[-3].strValue)), parameters))
        {
            yyerror(ERR(yylineno) + "Function " + std::string((yyvsp[-3].strValue)) + " was not declared in this scope!\n");        
            (yyval.tree) = new arb("0", "int");
        }
        else 
        {
            SymTable * funcSymTable = getFunctionSymTable(std::string((yyvsp[-3].strValue)));
            (yyval.tree) = new arb("0", funcSymTable->getSymTableType());
        } 
    } 

    parameters.clear();
}
#line 1883 "lang.tab.c"
    break;

  case 116: /* PARAMETER_LIST: PARAMETER  */
#line 503 "lang.y"
                           {parameters.push_back("int");}
#line 1889 "lang.tab.c"
    break;

  case 117: /* PARAMETER_LIST: PARAMETER ',' PARAMETER_LIST  */
#line 504 "lang.y"
                                              {parameters.push_back("int");}
#line 1895 "lang.tab.c"
    break;

  case 120: /* ARRAY_LITERAL: ID '[' EXPRESSION ']'  */
#line 511 "lang.y"
                                      { strcpy((yyval.strValue), (yyvsp[-3].strValue));}
#line 1901 "lang.tab.c"
    break;


#line 1905 "lang.tab.c"

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

#line 519 "lang.y"


void yyerror(std::string s)
{
    std::ofstream g("errors.txt", ios_base::app);
    g << s;
    g.close();
}

int main(int args, char * argv[])
{
    FILE * f = fopen(argv[1], "r");
    yyin = f;
    ofstream g("log.out");
    g.close();
    ofstream g2("errors.txt");
    g2.close();
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
    std::ifstream fin("errors.txt");
    std::string error;
    while(std::getline(fin, error))
        std::cout << error << '\n';
    fin.close();
    g.close();
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

SymTable * getFunctionSymTable(std::string name)
{
    for(unsigned int j = 0; j < funcSymTables.size(); j++)
        if(funcSymTables[j]->getSymTableName() == name)
            return funcSymTables[j];
    if(funcSymTables.back()->getSymTableName() == name && funcSymTables.back()->isParameterMatch(parameters))
        return funcSymTables.back();
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
    
    bool inClass = false;

    for(unsigned int j = 0; j < classSymTables.size(); j++)
    {
        std::vector<SymTable*> funcSymTables = classSymTables[j]->getFuncSymTables();
        for(unsigned int i = 0;i < funcSymTables.size(); i++) 
        {
            SymTable * symTable = funcSymTables[i];
            std::string funcName = symTable->getSymTableName(), prv;
            std::stringstream ss;
            ss << funcName; ss >> prv >> funcName;
            if(funcName == name && symTable->isParameterMatch(parameters)) 
            {
                if(prv == "public") 
                    return symTable;
                inClass = true;
            }
        }
    }

    if(inClass)
        yyerror(ERR(yylineno) + "Function " + name + " is not public\n");

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
        yyerror(ERR(yylineno) + "Variable " + name + " is of type " + symTable->getSymbolType(name) + " not of type " + extractTypeFromVariant(val));
        exit(2);
    }
}

void processAssignmentStatement(arb * arb, std::string name, char op)
{
    if(arb->hasConflictingTypes())  
    {
        yyerror(ERR(yylineno) + "Invalid Expression in Assignment Statement!\n");
        exit(7);
    }
    std::string type = arb->getExpressionType();
    value val = arb->getExpressionResult();

    std::string value = std::get<std::string>(val);
    if(type == "int")
        val = std::stoi(value);
    else if(type == "bool") 
    {
        if(value == "true" || value[0] != '0') val = true;
        else val = false;
    }
    else if(type == "char")
        val = value[0];
    else if(type == "float")
        val = std::stof(value);
    if(validateStatement()) 
    {    
        SymTable * symTable = findSymTable(name);
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
                yyerror(ERR(yylineno) + "Undeclared variable " + name + ".Can't modify it!");
            else if(globalAreaOn || declOn) 
                unSymbols.push_back({name, val});
            else 
            { 
                if(symTable == NULL)
                    yyerror(ERR(yylineno) + std::string("Variable doesn't exist"));
                else if(!symTable->isSymbolValid(name)) 
                    yyerror(ERR(yylineno) + std::string("Undeclared variable ") + name);
                else 
                    yyerror(ERR(yylineno) + "Variable " + name + " is of type " + symTable->getSymbolType(name) + " not of type " + type);
            }
        }
    }
}

std::string fromValueToString(value val)
{
    if(std::holds_alternative<std::string>(val))
        return std::get<std::string>(val);
    std::stringstream ss;
    std::string s;
    if(std::holds_alternative<int>(val))
        ss << get<int>(val);
    else if(std::holds_alternative<float>(val))
        ss << get<float>(val);
    else if(std::holds_alternative<bool>(val)) 
        ss << get<bool>(val);
    else if(std::holds_alternative<char>(val))
        ss << get<char>(val);
    ss >> s;
    return s;
}
