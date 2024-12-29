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
    ClassSymTable * getClassIdSymTable(std::string s);
    std::string lastType;

#line 113 "lang.tab.c"

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
  YYSYMBOL_COMPLEX_LITERAL = 5,            /* COMPLEX_LITERAL  */
  YYSYMBOL_TYPE = 6,                       /* TYPE  */
  YYSYMBOL_BOOLEAN_LITERAL = 7,            /* BOOLEAN_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 8,             /* STRING_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 9,              /* FLOAT_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 10,              /* CHAR_LITERAL  */
  YYSYMBOL_OPEN_WALLET = 11,               /* OPEN_WALLET  */
  YYSYMBOL_CLOSE_WALLET = 12,              /* CLOSE_WALLET  */
  YYSYMBOL_PRINT = 13,                     /* PRINT  */
  YYSYMBOL_TYPEOF = 14,                    /* TYPEOF  */
  YYSYMBOL_PRIVATE = 15,                   /* PRIVATE  */
  YYSYMBOL_PUBLIC = 16,                    /* PUBLIC  */
  YYSYMBOL_PROTECTED = 17,                 /* PROTECTED  */
  YYSYMBOL_TRANSACTION = 18,               /* TRANSACTION  */
  YYSYMBOL_TYPE_ASSIGN = 19,               /* TYPE_ASSIGN  */
  YYSYMBOL_CLASS = 20,                     /* CLASS  */
  YYSYMBOL_ACCESS = 21,                    /* ACCESS  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_IF = 24,                        /* IF  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_ELSE_IF = 26,                   /* ELSE_IF  */
  YYSYMBOL_WHILE = 27,                     /* WHILE  */
  YYSYMBOL_FOR = 28,                       /* FOR  */
  YYSYMBOL_SCOPE_START = 29,               /* SCOPE_START  */
  YYSYMBOL_SCOPE_END = 30,                 /* SCOPE_END  */
  YYSYMBOL_INCR = 31,                      /* INCR  */
  YYSYMBOL_DECR = 32,                      /* DECR  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_BOOL_OPERATOR = 34,             /* BOOL_OPERATOR  */
  YYSYMBOL_ADD_OPERATOR = 35,              /* ADD_OPERATOR  */
  YYSYMBOL_MUL_OPERATOR = 36,              /* MUL_OPERATOR  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* ';'  */
  YYSYMBOL_41_ = 41,                       /* '='  */
  YYSYMBOL_42_ = 42,                       /* '['  */
  YYSYMBOL_43_ = 43,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_MAIN_START = 45,                /* MAIN_START  */
  YYSYMBOL_MAIN_END = 46,                  /* MAIN_END  */
  YYSYMBOL_S = 47,                         /* S  */
  YYSYMBOL_DECL_START = 48,                /* DECL_START  */
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
  YYSYMBOL_EXPRESSION_LITERAL = 97,        /* EXPRESSION_LITERAL  */
  YYSYMBOL_EXPRESSION = 98,                /* EXPRESSION  */
  YYSYMBOL_BOOLEAN_EXPRESSION = 99,        /* BOOLEAN_EXPRESSION  */
  YYSYMBOL_FUNCTION_CALL = 100,            /* FUNCTION_CALL  */
  YYSYMBOL_PARAMETER_LIST = 101,           /* PARAMETER_LIST  */
  YYSYMBOL_PARAMETER = 102,                /* PARAMETER  */
  YYSYMBOL_ARRAY_LITERAL = 103,            /* ARRAY_LITERAL  */
  YYSYMBOL_ARRAY_DECLARATION = 104         /* ARRAY_DECLARATION  */
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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   267

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  222

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      37,    38,     2,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,    90,   108,   119,   120,   121,   123,   125,
     131,   137,   144,   145,   147,   149,   150,   152,   153,   156,
     167,   176,   187,   196,   205,   215,   216,   217,   227,   252,
     265,   266,   269,   270,   275,   276,   278,   279,   280,   281,
     287,   289,   293,   313,   314,   315,   319,   321,   323,   324,
     325,   327,   329,   332,   333,   337,   339,   343,   347,   352,
     353,   355,   364,   365,   367,   368,   370,   372,   380,   388,
     390,   391,   393,   394,   395,   396,   399,   400,   405,   406,
     407,   408,   409,   410,   413,   414,   415,   417,   439,   440,
     442,   443,   444,   445,   446,   447,   452,   459,   469,   476,
     488,   490,   493,   494,   495,   496,   497,   527,   528,   530,
     531,   532,   533,   534,   537,   538,   539,   540,   547,   568,
     569,   570,   572,   576,   578,   579,   580
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
  "COMPLEX_LITERAL", "TYPE", "BOOLEAN_LITERAL", "STRING_LITERAL",
  "FLOAT_LITERAL", "CHAR_LITERAL", "OPEN_WALLET", "CLOSE_WALLET", "PRINT",
  "TYPEOF", "PRIVATE", "PUBLIC", "PROTECTED", "TRANSACTION", "TYPE_ASSIGN",
  "CLASS", "ACCESS", "AND", "OR", "IF", "ELSE", "ELSE_IF", "WHILE", "FOR",
  "SCOPE_START", "SCOPE_END", "INCR", "DECR", "RETURN", "BOOL_OPERATOR",
  "ADD_OPERATOR", "MUL_OPERATOR", "'('", "')'", "','", "';'", "'='", "'['",
  "']'", "$accept", "MAIN_START", "MAIN_END", "S", "DECL_START",
  "FUNC_START", "FUNCTION_DECLARATION", "FUNCTION_DEFINITION",
  "DECL_PARAMETER_SEQUENCE", "CLASS_BEGIN_ELEMENT", "CLASS_BEGIN",
  "CLASS_DEFINITION", "CLASS_MEMBER_LIST", "CLASS_MEMBER",
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

#define YYPACT_NINF (-188)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-33)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     201,    11,  -188,  -188,  -188,  -188,    21,  -188,    72,    53,
      70,    50,  -188,   100,    82,    73,   138,    78,   109,   201,
    -188,   120,  -188,    98,  -188,   121,   115,  -188,  -188,  -188,
     168,   136,  -188,  -188,   173,  -188,  -188,  -188,  -188,   172,
    -188,    70,   124,    53,   177,  -188,  -188,   146,   151,    84,
     154,   169,  -188,    53,   166,  -188,   196,  -188,    68,     9,
     171,   178,   160,   160,  -188,  -188,   160,   170,  -188,   172,
    -188,  -188,   183,   169,   169,  -188,  -188,  -188,  -188,   169,
     210,  -188,   172,  -188,    60,   141,  -188,  -188,  -188,  -188,
    -188,   204,    33,  -188,  -188,  -188,  -188,  -188,  -188,   124,
     124,   214,  -188,    79,  -188,  -188,  -188,   124,   124,   124,
     -30,  -188,    70,  -188,   191,  -188,  -188,  -188,    53,   200,
    -188,   124,   160,   160,   160,   203,    56,    56,   203,    56,
    -188,   212,    46,  -188,  -188,   158,  -188,  -188,  -188,    15,
    -188,   240,  -188,   208,   198,   240,   124,   124,  -188,   -30,
     -30,    61,  -188,  -188,   205,  -188,   -30,   209,   207,   119,
      -2,   189,     4,   194,    39,   124,   160,   160,  -188,  -188,
       8,  -188,   211,  -188,   213,  -188,   160,  -188,   223,  -188,
     169,   169,  -188,   216,  -188,  -188,  -188,   208,  -188,    84,
    -188,  -188,  -188,   124,  -188,  -188,  -188,  -188,  -188,   -30,
    -188,   227,   160,   247,    56,  -188,   228,  -188,   106,   215,
    -188,   217,    56,   218,  -188,  -188,  -188,  -188,   247,   221,
    -188,  -188
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     5,    25,    26,    27,     0,    13,     0,     0,
      11,     0,    39,     0,     0,     0,     0,     0,     0,    34,
      29,     0,     1,    84,    28,    30,     0,    86,    33,    85,
       0,     0,    37,    14,     0,    38,    12,    36,     2,     0,
      35,     0,     0,     0,     0,    94,    95,     0,     0,     0,
      10,     7,    16,     0,     0,    23,     0,    18,     0,    84,
       0,     0,     0,     0,    47,    41,     0,     0,    75,     0,
      72,    45,     0,     0,     0,    44,    43,    57,    58,     0,
       0,    73,    76,    69,     0,     0,    82,    78,    79,    80,
      81,     0,    84,   100,   101,   103,   102,   104,   105,     0,
       0,   106,   109,     0,   107,    31,    87,     0,     0,     0,
      90,    91,    11,     8,     0,    22,    15,    17,     0,     0,
      24,   121,     0,     0,     0,     0,    61,    55,    88,    89,
      74,     0,     0,    46,    56,    59,     3,     4,    77,     0,
      70,     0,     6,   111,     0,     0,     0,     0,   123,    92,
      93,     0,     9,    21,     0,    20,   122,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42,    40,
      84,    49,     0,    50,    53,    68,     0,    60,     0,    63,
       0,     0,    71,    87,    83,   110,   108,   112,   113,     0,
     125,    19,   118,   121,    96,    97,    98,    99,   116,   117,
     114,   115,     0,     0,    67,    62,    64,    66,     0,     0,
     120,     0,    51,    84,    54,    65,   124,   126,     0,     0,
      52,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -188,  -188,  -188,  -188,    13,  -188,   -17,    -1,   143,  -188,
    -188,  -188,  -188,   206,   -21,     3,   -34,  -188,   237,  -188,
     -36,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -187,  -188,  -188,  -188,  -188,  -188,  -188,  -188,    55,    85,
    -188,  -188,  -188,   125,  -188,    16,  -188,    -9,  -188,  -188,
     -37,  -188,  -188,  -188,   -41,   -59,   -29,    74,  -188,  -188,
      76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    39,   137,     8,     9,    10,    11,    12,    31,    13,
      14,    15,    56,    57,    16,    67,    24,    25,    18,    19,
      68,    69,   169,    70,    71,    72,    73,   172,   211,   219,
     173,    74,    75,    76,    77,    78,    79,   177,   178,   179,
     180,   181,    80,    81,    82,    83,    84,   101,    27,    86,
      28,    88,    89,   102,   125,   126,   104,   157,   158,    29,
     111
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,   103,    87,    17,   127,   146,   147,   129,   110,   105,
      90,    20,    20,    58,    20,   113,   214,    54,    92,   114,
     166,   167,    17,    30,    21,   128,   166,   167,    60,    61,
      85,   220,    87,    55,    26,    58,   195,   133,   134,    54,
      90,   119,   197,   135,    26,    87,   121,    53,    66,   170,
      42,    42,     2,    90,    91,    55,    23,   120,   143,   144,
      85,   166,   167,   160,   162,   164,   149,   150,   151,    53,
     121,   118,    22,    85,     2,    42,     2,   198,   166,   167,
     156,   159,   161,   163,   154,   131,     6,    92,    93,    94,
      32,    95,    96,    97,    98,   174,   146,   147,   138,   139,
     140,   189,    87,    33,   190,   187,   188,   200,   201,    26,
      90,    34,   184,    35,   146,   147,   186,   204,    37,    99,
      38,   100,   148,    26,   199,    30,   109,    92,    93,    94,
      85,    95,    96,    97,    98,   171,    44,   -32,   -32,    41,
      42,   146,   147,   212,   206,   207,    45,    46,   208,   216,
      47,    48,   156,   165,   146,   147,    49,   194,    36,    99,
      43,   100,   141,    92,    93,    94,   174,    95,    96,    97,
      98,    50,    45,    46,    51,    59,    47,    48,     2,     2,
     106,   174,    49,   175,   176,    60,    61,   107,     3,     4,
       5,     6,   108,   112,    26,    99,    62,   124,    65,    63,
      64,    65,     2,    52,     1,    66,   115,     2,   122,    26,
     130,     3,     4,     5,     6,   123,     3,     4,     5,     6,
     132,     7,   136,   165,   146,   147,   116,   196,   165,   146,
     147,   153,   185,   146,   147,   145,   185,   165,   146,   147,
     155,   142,   168,   183,   147,   191,   193,   192,   175,   166,
     213,   202,   203,   121,   176,   152,    40,   218,   217,   221,
      42,   215,   117,   205,   182,   209,     0,   210
};

static const yytype_int16 yycheck[] =
{
       9,    42,    39,     0,    63,    35,    36,    66,    49,    43,
      39,     3,     3,    34,     3,    51,   203,    34,     3,    53,
      22,    23,    19,    10,     3,    66,    22,    23,    13,    14,
      39,   218,    69,    34,    43,    56,    38,    73,    74,    56,
      69,    58,    38,    79,    53,    82,    37,    34,    33,     3,
      42,    42,     6,    82,    41,    56,     3,    58,    99,   100,
      69,    22,    23,   122,   123,   124,   107,   108,   109,    56,
      37,    58,     0,    82,     6,    42,     6,    38,    22,    23,
     121,   122,   123,   124,   118,    69,    18,     3,     4,     5,
      40,     7,     8,     9,    10,   132,    35,    36,    82,    39,
      40,    40,   139,     3,    43,   146,   147,   166,   167,   118,
     139,    29,   141,    40,    35,    36,   145,   176,    40,    35,
      11,    37,    43,   132,   165,   112,    42,     3,     4,     5,
     139,     7,     8,     9,    10,   132,    21,    39,    40,    19,
      42,    35,    36,   202,   180,   181,    31,    32,   189,    43,
      35,    36,   193,    34,    35,    36,    41,    38,    20,    35,
      39,    37,    21,     3,     4,     5,   203,     7,     8,     9,
      10,     3,    31,    32,    38,     3,    35,    36,     6,     6,
       3,   218,    41,    25,    26,    13,    14,    41,    15,    16,
      17,    18,    41,    39,   203,    35,    24,    37,    29,    27,
      28,    29,     6,    30,     3,    33,    40,     6,    37,   218,
      40,    15,    16,    17,    18,    37,    15,    16,    17,    18,
      37,    20,    12,    34,    35,    36,    30,    38,    34,    35,
      36,    40,    38,    35,    36,    21,    38,    34,    35,    36,
      40,    37,    30,     3,    36,    40,    39,    38,    25,    22,
       3,    40,    39,    37,    26,   112,    19,    40,    43,    38,
      42,   206,    56,   178,   139,   189,    -1,   193
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     6,    15,    16,    17,    18,    20,    47,    48,
      49,    50,    51,    53,    54,    55,    58,    59,    62,    63,
       3,     3,     0,     3,    60,    61,    91,    92,    94,   103,
      48,    52,    40,     3,    29,    40,    20,    40,    11,    45,
      62,    19,    42,    39,    21,    31,    32,    35,    36,    41,
       3,    38,    30,    48,    50,    51,    56,    57,    58,     3,
      13,    14,    24,    27,    28,    29,    33,    59,    64,    65,
      67,    68,    69,    70,    75,    76,    77,    78,    79,    80,
      86,    87,    88,    89,    90,    91,    93,    94,    95,    96,
     100,    48,     3,     4,     5,     7,     8,     9,    10,    35,
      37,    91,    97,    98,   100,    60,     3,    41,    41,    42,
      98,   104,    39,    64,    60,    40,    30,    57,    48,    50,
      51,    37,    37,    37,    37,    98,    99,    99,    98,    99,
      40,    89,    37,    64,    64,    64,    12,    46,    89,    39,
      40,    21,    37,    98,    98,    21,    35,    36,    43,    98,
      98,    98,    52,    40,    60,    40,    98,   101,   102,    98,
      99,    98,    99,    98,    99,    34,    22,    23,    30,    66,
       3,    59,    71,    74,    94,    25,    26,    81,    82,    83,
      84,    85,    87,     3,   100,    38,   100,    98,    98,    40,
      43,    40,    38,    39,    38,    38,    38,    38,    38,    98,
      99,    99,    40,    39,    99,    83,    64,    64,    98,   104,
     101,    72,    99,     3,    74,    82,    43,    43,    40,    73,
      74,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      52,    52,    53,    53,    54,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    58,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      64,    65,    66,    67,    67,    67,    68,    69,    70,    71,
      71,    72,    73,    74,    74,    75,    76,    77,    78,    79,
      79,    80,    81,    81,    82,    82,    83,    84,    85,    86,
      87,    87,    88,    88,    88,    88,    89,    89,    90,    90,
      90,    90,    90,    90,    91,    91,    91,    92,    93,    93,
      94,    94,    94,    94,    94,    94,    95,    95,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    98,
      98,    98,    98,    98,    99,    99,    99,    99,   100,   101,
     101,   101,   102,   103,   104,   104,   104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     4,     1,     5,     3,     4,     4,
       2,     0,     2,     1,     2,     4,     3,     2,     1,     4,
       3,     3,     2,     1,     2,     1,     1,     1,     2,     2,
       1,     3,     1,     1,     1,     2,     2,     2,     2,     1,
       3,     1,     1,     1,     1,     1,     2,     1,     8,     1,
       1,     1,     1,     1,     3,     2,     2,     1,     1,     2,
       3,     2,     2,     1,     2,     3,     2,     2,     1,     1,
       2,     3,     1,     1,     2,     1,     1,     2,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     2,     2,
       3,     3,     4,     4,     2,     2,     4,     4,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     2,     3,     3,     3,     3,     3,     3,     4,     1,
       3,     0,     1,     4,     5,     3,     5
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
#line 89 "lang.y"
                         {symTables.push_back(new SymTable); globalAreaOn = false; }
#line 1382 "lang.tab.c"
    break;

  case 3: /* MAIN_END: CLOSE_WALLET  */
#line 90 "lang.y"
                        {
    SymTable * symTable = symTables.back();
    std::map<std::string, bool> symExist = symTable->getSymExist();
    int count = 0;
    for(auto [name, value] : symExist) {
        if(value == true && getClassIdSymTable(name) != NULL)
            count++;
    }       
    for(unsigned int j = 0;j < count; j++) 
    {
        ClassSymTable * classSymTable = classSymTables.back();
        delete classSymTable;
        classSymTables.pop_back();
    }
    delete symTable;
    symTables.pop_back();
}
#line 1404 "lang.tab.c"
    break;

  case 4: /* S: DECLARATIONS MAIN_START MAIN MAIN_END  */
#line 108 "lang.y"
                                          {
        printf("Program compiled succesfully!\n");
        return 0;
}
#line 1413 "lang.tab.c"
    break;

  case 5: /* DECL_START: TYPE  */
#line 119 "lang.y"
                  {declOn = true; lastType = std::string((yyvsp[0].strValue)); strcpy((yyval.strValue), (yyvsp[0].strValue)); }
#line 1419 "lang.tab.c"
    break;

  case 6: /* FUNC_START: TRANSACTION ID TYPE_ASSIGN DECL_START '('  */
#line 120 "lang.y"
                                                       {  funcOn = true; funcSymTables.push_back(new SymTable(std::string((yyvsp[-1].strValue)), std::string((yyvsp[-3].strValue)))); declOn = false;}
#line 1425 "lang.tab.c"
    break;

  case 7: /* FUNCTION_DECLARATION: FUNC_START DECL_PARAMETER_SEQUENCE ')'  */
#line 121 "lang.y"
                                                              { funcOn = false; }
#line 1431 "lang.tab.c"
    break;

  case 8: /* FUNCTION_DEFINITION: FUNC_START DECL_PARAMETER_SEQUENCE ')' SCOPE  */
#line 123 "lang.y"
                                                                   { funcOn = false; }
#line 1437 "lang.tab.c"
    break;

  case 9: /* DECL_PARAMETER_SEQUENCE: DECL_START ID ',' DECL_PARAMETER_SEQUENCE  */
#line 125 "lang.y"
                                                                    {
                            SymTable * symTable = funcSymTables.back();
                            symTable->addParameter(std::string((yyvsp[-3].strValue)));
                            symTable->addSymbol(std::string((yyvsp[-2].strValue)), std::string((yyvsp[-3].strValue)));
                            declOn = false;
                        }
#line 1448 "lang.tab.c"
    break;

  case 10: /* DECL_PARAMETER_SEQUENCE: DECL_START ID  */
#line 131 "lang.y"
                                         {
                            SymTable * symTable = funcSymTables.back();
                            symTable->addParameter(std::string((yyvsp[-1].strValue)));
                            symTable->addSymbol(std::string((yyvsp[0].strValue)), std::string((yyvsp[-1].strValue)));
                            declOn = false;
                        }
#line 1459 "lang.tab.c"
    break;

  case 12: /* CLASS_BEGIN_ELEMENT: ACCESS_MODIFIER CLASS  */
#line 144 "lang.y"
                                            {strcpy((yyval.strValue), (yyvsp[-1].strValue));}
#line 1465 "lang.tab.c"
    break;

  case 13: /* CLASS_BEGIN_ELEMENT: CLASS  */
#line 145 "lang.y"
                            {strcpy((yyval.strValue), "public");}
#line 1471 "lang.tab.c"
    break;

  case 14: /* CLASS_BEGIN: CLASS_BEGIN_ELEMENT ID  */
#line 147 "lang.y"
                                     {classSymTables.push_back(new ClassSymTable(std::string((yyvsp[-1].strValue)), std::string((yyvsp[0].strValue))));}
#line 1477 "lang.tab.c"
    break;

  case 19: /* CLASS_MEMBER: ACCESS_MODIFIER DECL_START IDSEQUENCE ';'  */
#line 156 "lang.y"
                                                         {
                ClassSymTable * symTable = classSymTables.back();
                for(auto [name, value] : unSymbols) 
                {
                    std::string className = std::string((yyvsp[-3].strValue)) + " " + name;
                    symTable->addSymbol(className, std::string((yyvsp[-2].strValue)));
                    processUpdate(symTable, className, std::string((yyvsp[-2].strValue)), value, '=');
                }
                declOn = false;
                unSymbols.clear();
            }
#line 1493 "lang.tab.c"
    break;

  case 20: /* CLASS_MEMBER: ACCESS_MODIFIER FUNCTION_DECLARATION ';'  */
#line 167 "lang.y"
                                                        {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = std::string((yyvsp[-2].strValue)) + " " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
#line 1507 "lang.tab.c"
    break;

  case 21: /* CLASS_MEMBER: DECL_START IDSEQUENCE ';'  */
#line 176 "lang.y"
                                         {
                ClassSymTable * symTable = classSymTables.back();
                for(auto [name, value] : unSymbols) 
                {
                    std::string className = "blockchain " + name;
                    symTable->addSymbol(className, std::string((yyvsp[-2].strValue)));
                    processUpdate(symTable, className, std::string((yyvsp[-2].strValue)), value, '=');
                }
                declOn = false;
                unSymbols.clear();
             }
#line 1523 "lang.tab.c"
    break;

  case 22: /* CLASS_MEMBER: FUNCTION_DECLARATION ';'  */
#line 187 "lang.y"
                                        {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = "blockchain " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
#line 1537 "lang.tab.c"
    break;

  case 23: /* CLASS_MEMBER: FUNCTION_DEFINITION  */
#line 196 "lang.y"
                                   {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = "blockchain " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
#line 1551 "lang.tab.c"
    break;

  case 24: /* CLASS_MEMBER: ACCESS_MODIFIER FUNCTION_DEFINITION  */
#line 205 "lang.y"
                                                   {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = std::string((yyvsp[-1].strValue)) + " " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
#line 1565 "lang.tab.c"
    break;

  case 25: /* ACCESS_MODIFIER: PRIVATE  */
#line 215 "lang.y"
                          {strcpy((yyval.strValue), (yyvsp[0].strValue));}
#line 1571 "lang.tab.c"
    break;

  case 26: /* ACCESS_MODIFIER: PUBLIC  */
#line 216 "lang.y"
                         {strcpy((yyval.strValue), (yyvsp[0].strValue));}
#line 1577 "lang.tab.c"
    break;

  case 27: /* ACCESS_MODIFIER: PROTECTED  */
#line 217 "lang.y"
                            {strcpy((yyval.strValue), (yyvsp[0].strValue));}
#line 1583 "lang.tab.c"
    break;

  case 28: /* LINE_DECLARATION: DECL_START IDSEQUENCE  */
#line 227 "lang.y"
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
                    printf("aiciiiiiiiiiiiiiiii\n");
                    symTable->addSymbol(name, (yyvsp[-1].strValue));
                    processUpdate(symTable, name, std::string((yyvsp[-1].strValue)), val, '=');
                }
            }
            unSymbols.clear();
            declOn = false;
        }
#line 1613 "lang.tab.c"
    break;

  case 29: /* LINE_DECLARATION: ID ID  */
#line 252 "lang.y"
                       {
            ClassSymTable * classSymTable = getClassSymTable(std::string((yyvsp[-1].strValue)));
            if(classSymTable == NULL)
                yyerror(ERR(yylineno) + "Undefined identifier " + std::string((yyvsp[-1].strValue)) + "for class type\n");
            else 
            {
                SymTable * symTable = symTables.back();
                symTable->addSymbol(std::string((yyvsp[0].strValue)), std::string((yyvsp[-1].strValue)));
                classSymTables.push_back(new ClassSymTable(classSymTable, std::string((yyvsp[-1].strValue)), std::string((yyvsp[0].strValue))));
            }
        }
#line 1629 "lang.tab.c"
    break;

  case 32: /* ID_SEQUENCE_ELEMENT: ID  */
#line 269 "lang.y"
                         {unSymbols.push_back({(yyvsp[0].strValue), SymTable::getDefaultValue(lastType)});}
#line 1635 "lang.tab.c"
    break;

  case 41: /* BEGIN_SCOPE: SCOPE_START  */
#line 289 "lang.y"
                          {
    symTables.push_back(new SymTable);
}
#line 1643 "lang.tab.c"
    break;

  case 42: /* END_SCOPE: SCOPE_END  */
#line 293 "lang.y"
                      {
    SymTable * symTable = symTables.back();
    std::map<std::string, bool> symExist = symTable->getSymExist();
    int count = 0;
    for(auto [name, value] : symExist) {
        if(value == true && getClassIdSymTable(name) != NULL)
            count++;
    }       
    for(unsigned int j = 0;j < count; j++) 
    {
        ClassSymTable * classSymTable = classSymTables.back();
        delete classSymTable;
        classSymTables.pop_back();
    }
    delete symTable;
    symTables.pop_back();
}
#line 1665 "lang.tab.c"
    break;

  case 46: /* FOR_BLOCK: FOR_STATEMENT SCOPE  */
#line 319 "lang.y"
                                { symTables.pop_back(); }
#line 1671 "lang.tab.c"
    break;

  case 47: /* FOR_START: FOR  */
#line 321 "lang.y"
                { symTables.push_back(new SymTable); }
#line 1677 "lang.tab.c"
    break;

  case 57: /* IF_BLOCK: IF_COMPOSITION  */
#line 343 "lang.y"
                          {
    ifController = {false, 0};
}
#line 1685 "lang.tab.c"
    break;

  case 58: /* IF_COMPOSITION: IF_STRUCTURE  */
#line 347 "lang.y"
                              {
                      if(ifController.first)
                        ifController.second = -1;
                }
#line 1694 "lang.tab.c"
    break;

  case 61: /* IF_STATEMENT: IF BOOLEAN_EXPRESSION  */
#line 356 "lang.y"
{
    ifController = {true, 0};
    if((yyvsp[0].tree)->hasConflictingTypes()) 
        yyerror(ERR(yylineno) + "Invalid Expression in if statement\n");
    else if((yyvsp[0].tree)->getExpressionType()!="bool" && (yyvsp[0].tree)->getExpressionResult()!="0" || (yyvsp[0].tree)->getExpressionType()=="bool" && (yyvsp[0].tree)->getExpressionResult()=="true") 
        ifController.second = 1;
}
#line 1706 "lang.tab.c"
    break;

  case 67: /* ELSE_IF_STATEMENT: ELSE_IF BOOLEAN_EXPRESSION  */
#line 372 "lang.y"
                                                 {
    if(ifController.second) ifController.second = -1;
    if((yyvsp[0].tree)->hasConflictingTypes()) 
        yyerror(ERR(yylineno) + "Invalid Expression in else if statement\n");
    else if(((yyvsp[0].tree)->getExpressionType()!="bool" && (yyvsp[0].tree)->getExpressionResult()!="0" || (yyvsp[0].tree)->getExpressionType()=="bool" && (yyvsp[0].tree)->getExpressionResult()=="true") && ifController.second == 0)
        ifController.second = 1;
}
#line 1718 "lang.tab.c"
    break;

  case 68: /* ELSE_STATEMENT: ELSE  */
#line 380 "lang.y"
                      {
    if(!ifController.second)
         ifController.second = 1;
}
#line 1727 "lang.tab.c"
    break;

  case 87: /* CLASS_LITERAL: LVALUE_ELEMENT ACCESS ID  */
#line 417 "lang.y"
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
            else if(classSymTable->getSymbolPrivacy(std::string((yyvsp[0].strValue))) != "in_circulation")
                yyerror(ERR(yylineno) + "Identifier " + std::string((yyvsp[0].strValue)) + " is " + classSymTable->getSymbolPrivacy(std::string((yyvsp[0].strValue))) + " in the context of class " + std::string((yyvsp[-2].strValue)));
        }
    }
    char className[101];
    memset(className, false, sizeof(className));
    strcpy(className, (yyvsp[-2].strValue));
    className[strlen(className)] = ' ';
    strcat(className, (yyvsp[0].strValue));
    strcpy((yyval.strValue), className);
}
#line 1753 "lang.tab.c"
    break;

  case 90: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' EXPRESSION  */
#line 442 "lang.y"
                                                     { processAssignmentStatement((yyvsp[0].tree), std::string((yyvsp[-2].strValue)), '='); }
#line 1759 "lang.tab.c"
    break;

  case 91: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' ARRAY_DECLARATION  */
#line 443 "lang.y"
                                                            {if(declOn) unSymbols.push_back({std::string((yyvsp[-2].strValue)), 0});}
#line 1765 "lang.tab.c"
    break;

  case 92: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT ADD_OPERATOR '=' EXPRESSION  */
#line 444 "lang.y"
                                                                  { processAssignmentStatement((yyvsp[0].tree), std::string((yyvsp[-3].strValue)), std::string((yyvsp[-2].strValue))[0]);}
#line 1771 "lang.tab.c"
    break;

  case 93: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT MUL_OPERATOR '=' EXPRESSION  */
#line 445 "lang.y"
                                                                  { processAssignmentStatement((yyvsp[0].tree), std::string((yyvsp[-3].strValue)), std::string((yyvsp[-2].strValue))[0]);}
#line 1777 "lang.tab.c"
    break;

  case 94: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT INCR  */
#line 446 "lang.y"
                                           {processAssignmentStatement(new arb("1","int"), std::string((yyvsp[-1].strValue)), '+');}
#line 1783 "lang.tab.c"
    break;

  case 95: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT DECR  */
#line 447 "lang.y"
                                           {processAssignmentStatement(new arb("1","int"), std::string((yyvsp[-1].strValue)), '-');}
#line 1789 "lang.tab.c"
    break;

  case 96: /* PRINT_STATEMENT: PRINT '(' EXPRESSION ')'  */
#line 453 "lang.y"
                  {
                    if((yyvsp[-1].tree)->hasConflictingTypes()) 
                        yyerror(ERR(yylineno) + "Invalid Expression in print statement!\n");
                    else if(validateStatement()) 
                        std::cout << (yyvsp[-1].tree)->getExpressionResult() << '\n';
                  }
#line 1800 "lang.tab.c"
    break;

  case 97: /* PRINT_STATEMENT: PRINT '(' BOOLEAN_EXPRESSION ')'  */
#line 460 "lang.y"
                  {
                     if((yyvsp[-1].tree)->hasConflictingTypes()) 
                        yyerror(ERR(yylineno) + "Invalid Expression in print statement!\n");
                    else if(validateStatement()) 
                        std::cout << (yyvsp[-1].tree)->getExpressionResult() << '\n';
                  }
#line 1811 "lang.tab.c"
    break;

  case 98: /* TYPE_OF_STATEMENT: TYPEOF '(' EXPRESSION ')'  */
#line 470 "lang.y"
                    {
                        if((yyvsp[-1].tree)->hasConflictingTypes()) 
                            yyerror(ERR(yylineno) + "Invalid Expression in typeof statement!\n");
                        else if(validateStatement()) 
                            std::cout << (yyvsp[-1].tree)->getExpressionType() << '\n';
                    }
#line 1822 "lang.tab.c"
    break;

  case 99: /* TYPE_OF_STATEMENT: TYPEOF '(' BOOLEAN_EXPRESSION ')'  */
#line 477 "lang.y"
                    {
                        if((yyvsp[-1].tree)->hasConflictingTypes()) 
                            yyerror(ERR(yylineno) + "Invalid Expression in typeof statement!\n");
                        else if(validateStatement()) {
                            std::cout << (yyvsp[-1].tree)->getExpressionType() << '\n';
                        }
                    }
#line 1834 "lang.tab.c"
    break;

  case 100: /* EXPRESSION_LITERAL: INTEGER  */
#line 488 "lang.y"
                              {(yyval.tree) = new arb(fromValueToString((yyvsp[0].iValue)),"int");}
#line 1840 "lang.tab.c"
    break;

  case 101: /* EXPRESSION_LITERAL: COMPLEX_LITERAL  */
#line 490 "lang.y"
                                     {
                    (yyval.tree)=new arb(fromValueToString(Complex((yyvsp[0].complValue)->real,(yyvsp[0].complValue)->imag)),"compl");
                    }
#line 1848 "lang.tab.c"
    break;

  case 102: /* EXPRESSION_LITERAL: STRING_LITERAL  */
#line 493 "lang.y"
                                     {(yyval.tree) = new arb(fromValueToString(std::string((yyvsp[0].strValue))),"string");}
#line 1854 "lang.tab.c"
    break;

  case 103: /* EXPRESSION_LITERAL: BOOLEAN_LITERAL  */
#line 494 "lang.y"
                                      {(yyval.tree) = new arb(fromValueToString((yyvsp[0].bValue)),"bool");}
#line 1860 "lang.tab.c"
    break;

  case 104: /* EXPRESSION_LITERAL: FLOAT_LITERAL  */
#line 495 "lang.y"
                                    {(yyval.tree) = new arb(fromValueToString((yyvsp[0].fValue)),"float");}
#line 1866 "lang.tab.c"
    break;

  case 105: /* EXPRESSION_LITERAL: CHAR_LITERAL  */
#line 496 "lang.y"
                                   {(yyval.tree) = new arb(fromValueToString((yyvsp[0].cValue)),"char");}
#line 1872 "lang.tab.c"
    break;

  case 106: /* EXPRESSION_LITERAL: LVALUE_ELEMENT  */
#line 497 "lang.y"
                                     {
                        std::stringstream ss;
                        std::string word;
                        int count = 0;
                        ss << std::string((yyvsp[0].strValue));
                        while(ss >> word)
                            count++;
                        if(count == 2) {
                            ss.clear();
                            ss << std::string((yyvsp[0].strValue));
                            std::string className, attribute;
                            ss >> className >> attribute;
                            SymTable * classSymTable = getClassIdSymTable(className); 
                            value val = classSymTable->getSymbolValue("in_circulation "+attribute);
                            if(extractTypeFromVariant(val)!="compl")
                            (yyval.tree) = new arb(fromValueToString(val), extractTypeFromVariant(val));
                        }
                       else {
                            SymTable * symTable = findSymTable(std::string((yyvsp[0].strValue)));
                            if(symTable != NULL) 
                            {
                            value val = symTable->getSymbolValue(std::string((yyvsp[0].strValue)));
                            (yyval.tree) = new arb(fromValueToString(val), extractTypeFromVariant(val));
                            }
                            else {                           
                                yyerror(ERR(yylineno) + std::string("Undeclared variable ") + std::string((yyvsp[0].strValue)));
                                (yyval.tree) = new arb("0", "int");
                            }
                        }
                    }
#line 1907 "lang.tab.c"
    break;

  case 107: /* EXPRESSION_LITERAL: FUNCTION_CALL  */
#line 527 "lang.y"
                                    {(yyval.tree) = (yyvsp[0].tree);}
#line 1913 "lang.tab.c"
    break;

  case 108: /* EXPRESSION_LITERAL: LVALUE_ELEMENT ACCESS FUNCTION_CALL  */
#line 528 "lang.y"
                                                          {(yyval.tree) = (yyvsp[0].tree);}
#line 1919 "lang.tab.c"
    break;

  case 109: /* EXPRESSION: EXPRESSION_LITERAL  */
#line 530 "lang.y"
                                {(yyval.tree) = (yyvsp[0].tree);}
#line 1925 "lang.tab.c"
    break;

  case 110: /* EXPRESSION: '(' EXPRESSION ')'  */
#line 531 "lang.y"
                                {(yyval.tree)=(yyvsp[-1].tree);}
#line 1931 "lang.tab.c"
    break;

  case 111: /* EXPRESSION: ADD_OPERATOR EXPRESSION  */
#line 532 "lang.y"
                                     {(yyval.tree)= new arb((yyvsp[-1].strValue),"",(yyvsp[0].tree),nullptr);}
#line 1937 "lang.tab.c"
    break;

  case 112: /* EXPRESSION: EXPRESSION ADD_OPERATOR EXPRESSION  */
#line 533 "lang.y"
                                                {(yyval.tree) = new arb((yyvsp[-1].strValue),"",(yyvsp[-2].tree),(yyvsp[0].tree));}
#line 1943 "lang.tab.c"
    break;

  case 113: /* EXPRESSION: EXPRESSION MUL_OPERATOR EXPRESSION  */
#line 534 "lang.y"
                                                {(yyval.tree) = new arb((yyvsp[-1].strValue),"",(yyvsp[-2].tree),(yyvsp[0].tree));}
#line 1949 "lang.tab.c"
    break;

  case 114: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION AND BOOLEAN_EXPRESSION  */
#line 537 "lang.y"
                                                                {(yyval.tree) = new arb("&&","",(yyvsp[-2].tree),(yyvsp[0].tree));}
#line 1955 "lang.tab.c"
    break;

  case 115: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION OR BOOLEAN_EXPRESSION  */
#line 538 "lang.y"
                                                               {(yyval.tree) = new arb("||","",(yyvsp[-2].tree),(yyvsp[0].tree));}
#line 1961 "lang.tab.c"
    break;

  case 116: /* BOOLEAN_EXPRESSION: '(' BOOLEAN_EXPRESSION ')'  */
#line 539 "lang.y"
                                                 {(yyval.tree) = (yyvsp[-1].tree);}
#line 1967 "lang.tab.c"
    break;

  case 117: /* BOOLEAN_EXPRESSION: EXPRESSION BOOL_OPERATOR EXPRESSION  */
#line 540 "lang.y"
                                                          {(yyval.tree) = new arb((yyvsp[-1].strValue),"",(yyvsp[-2].tree),(yyvsp[0].tree));}
#line 1973 "lang.tab.c"
    break;

  case 118: /* FUNCTION_CALL: ID '(' PARAMETER_LIST ')'  */
#line 548 "lang.y"
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
#line 1995 "lang.tab.c"
    break;

  case 119: /* PARAMETER_LIST: PARAMETER  */
#line 568 "lang.y"
                           {parameters.push_back((yyvsp[0].tree)->getExpressionType());}
#line 2001 "lang.tab.c"
    break;

  case 120: /* PARAMETER_LIST: PARAMETER ',' PARAMETER_LIST  */
#line 569 "lang.y"
                                              {parameters.push_back((yyvsp[-2].tree)->getExpressionType());}
#line 2007 "lang.tab.c"
    break;

  case 122: /* PARAMETER: EXPRESSION  */
#line 572 "lang.y"
                       {(yyval.tree) = (yyvsp[0].tree);}
#line 2013 "lang.tab.c"
    break;

  case 123: /* ARRAY_LITERAL: ID '[' EXPRESSION ']'  */
#line 576 "lang.y"
                                      { strcpy((yyval.strValue), (yyvsp[-3].strValue));}
#line 2019 "lang.tab.c"
    break;


#line 2023 "lang.tab.c"

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

#line 584 "lang.y"


void yyerror(std::string s)
{
    std::ofstream g("errors.txt", ios_base::app);
    g << s << '\n';
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
        ClassSymTable * symTable = classSymTables[j];
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
ClassSymTable * getClassIdSymTable(std::string s)
{
    for(int j = classSymTables.size() - 1; j >= 0; --j)
    {
        ClassSymTable * symTable = classSymTables[j];
        if(symTable->getSymTableName() == s)
            return symTable;
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
                if(prv == "in_circulation") 
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
    }
}

void processAssignmentStatement(arb * arb, std::string name, char op)
{
    printf("SUNT IN ASSIGMENT STATEMENT YEEEEEEEEEEEEEEEE\n");
    if(arb->hasConflictingTypes())  
    {
        yyerror(ERR(yylineno) + "Invalid Expression in Assignment Statement!\n");
        return;
    }
    std::string type = arb->getExpressionType();
    value val = arb->getExpressionResult();
    printf("type : %s , value : %s \n",arb->getExpressionType().c_str(),arb->getExpressionResult().c_str());
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
    else if(type=="compl"){
    std::string token=value;
     int imag,real;
    size_t iPos = token.find('i'); // poztia lui i
    if (iPos==string ::npos)
    {
        imag = 0;
        real = stof(token);
        val=Complex(real, imag);
    }
    size_t plusPos = token.find_last_of('+', iPos); // pozitia lu + si -
    size_t minusPos = token.find_last_of('-', iPos);
    size_t splitPos = (plusPos != string::npos) ? plusPos : (minusPos !=string::npos) ? minusPos :string::npos; // vedem care e diferita de npos(care e )
    
    if (splitPos == string::npos)
    {
        real = 0;
        imag = stof(token.substr(0, iPos));
        val=Complex(real, imag);

    }
    imag = stof(token.substr(splitPos + 1, iPos - splitPos - 1));
    real = stof(token.substr(0, splitPos));
    if(token[splitPos]=='-' && imag>0)
    imag=-imag;
    val=Complex(real, imag);
}
    if(validateStatement()) 
       {   
        SymTable * symTable;
        std::stringstream ss;
        std::string word;
        int count = 0;
        ss << name;
        while(ss >> word)
            count++;
        if(count == 2) 
        {
            ss.clear();
            ss << name;
            std::string className, attribute;
            ss >> className >> attribute;
            name = attribute;
            ClassSymTable * classSymTable = getClassIdSymTable(className);
            if(!classSymTable->isSymbolValid(name) || classSymTable->getSymbolPrivacy(name) != "in_circulation")
                return;
            name = "in_circulation " + name;
            symTable = classSymTable;
        }
        else symTable = findSymTable(name);
        if(isSymbolValid(name, type))    
            processUpdate(symTable, name, type, val, op);
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
    else if(std::holds_alternative<Complex>(val))
        ss << get<Complex>(val);
    ss >> s;
    return s;
}
