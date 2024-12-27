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
    bool globalAreaOn = true, funcOn = false;


    /// TODO: Assign values to class members

    void yyerror(std::string s);
    bool isSymbolValid(std::string s, std::string type);   
    bool validateStatement();
    bool validateFunction(std::string name, std::vector<std::string> parameters);
    void processUpdate(SymTable * symTable, std::string name, std::string type, value val, char op);
    void processAssignmentStatement(SymTable * symTable, std::string name, std::string type, value val, char op);

    std::string fromIntToString(int val);
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


#line 109 "lang.tab.c"

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
  YYSYMBOL_FUNC_START = 41,                /* FUNC_START  */
  YYSYMBOL_FUNCTION_DECLARATION = 42,      /* FUNCTION_DECLARATION  */
  YYSYMBOL_FUNCTION_DEFINITION = 43,       /* FUNCTION_DEFINITION  */
  YYSYMBOL_DECL_PARAMETER_SEQUENCE = 44,   /* DECL_PARAMETER_SEQUENCE  */
  YYSYMBOL_CLASS_BEGIN_ELEMENT = 45,       /* CLASS_BEGIN_ELEMENT  */
  YYSYMBOL_CLASS_BEGIN = 46,               /* CLASS_BEGIN  */
  YYSYMBOL_CLASS_DEFINITION = 47,          /* CLASS_DEFINITION  */
  YYSYMBOL_CLASS_MEMBER_LIST = 48,         /* CLASS_MEMBER_LIST  */
  YYSYMBOL_CLASS_MEMBER = 49,              /* CLASS_MEMBER  */
  YYSYMBOL_ACCESS_MODIFIER = 50,           /* ACCESS_MODIFIER  */
  YYSYMBOL_LINE_DECLARATION = 51,          /* LINE_DECLARATION  */
  YYSYMBOL_IDSEQUENCE = 52,                /* IDSEQUENCE  */
  YYSYMBOL_ID_SEQUENCE_ELEMENT = 53,       /* ID_SEQUENCE_ELEMENT  */
  YYSYMBOL_DECLARATIONS = 54,              /* DECLARATIONS  */
  YYSYMBOL_DECLARATIONS_ELEMENT = 55,      /* DECLARATIONS_ELEMENT  */
  YYSYMBOL_SCOPE = 56,                     /* SCOPE  */
  YYSYMBOL_BEGIN_SCOPE = 57,               /* BEGIN_SCOPE  */
  YYSYMBOL_END_SCOPE = 58,                 /* END_SCOPE  */
  YYSYMBOL_BLOCK = 59,                     /* BLOCK  */
  YYSYMBOL_FOR_BLOCK = 60,                 /* FOR_BLOCK  */
  YYSYMBOL_FOR_START = 61,                 /* FOR_START  */
  YYSYMBOL_FOR_STATEMENT = 62,             /* FOR_STATEMENT  */
  YYSYMBOL_INIT_DECL_COMP = 63,            /* INIT_DECL_COMP  */
  YYSYMBOL_STOP_CONDITION_COMP = 64,       /* STOP_CONDITION_COMP  */
  YYSYMBOL_MODIFY_COMP = 65,               /* MODIFY_COMP  */
  YYSYMBOL_LINE_INITIALIZATION = 66,       /* LINE_INITIALIZATION  */
  YYSYMBOL_WHILE_STATEMENT = 67,           /* WHILE_STATEMENT  */
  YYSYMBOL_WHILE_BLOCK = 68,               /* WHILE_BLOCK  */
  YYSYMBOL_IF_BLOCK = 69,                  /* IF_BLOCK  */
  YYSYMBOL_IF_COMPOSITION = 70,            /* IF_COMPOSITION  */
  YYSYMBOL_IF_STRUCTURE = 71,              /* IF_STRUCTURE  */
  YYSYMBOL_IF_STATEMENT = 72,              /* IF_STATEMENT  */
  YYSYMBOL_ELSE_BLOCKS = 73,               /* ELSE_BLOCKS  */
  YYSYMBOL_ELSE_IF_BLOCK = 74,             /* ELSE_IF_BLOCK  */
  YYSYMBOL_ELSE_BLOCK = 75,                /* ELSE_BLOCK  */
  YYSYMBOL_ELSE_IF_STATEMENT = 76,         /* ELSE_IF_STATEMENT  */
  YYSYMBOL_ELSE_STATEMENT = 77,            /* ELSE_STATEMENT  */
  YYSYMBOL_MAIN = 78,                      /* MAIN  */
  YYSYMBOL_MUL_STATEMENTS = 79,            /* MUL_STATEMENTS  */
  YYSYMBOL_CODE_AREA_ELEMENT = 80,         /* CODE_AREA_ELEMENT  */
  YYSYMBOL_CODE_AREA = 81,                 /* CODE_AREA  */
  YYSYMBOL_STATEMENT = 82,                 /* STATEMENT  */
  YYSYMBOL_LVALUE_ELEMENT = 83,            /* LVALUE_ELEMENT  */
  YYSYMBOL_CLASS_LITERAL = 84,             /* CLASS_LITERAL  */
  YYSYMBOL_RETURN_STATEMENT = 85,          /* RETURN_STATEMENT  */
  YYSYMBOL_ASSIGNMENT_STATEMENT = 86,      /* ASSIGNMENT_STATEMENT  */
  YYSYMBOL_PRINT_STATEMENT = 87,           /* PRINT_STATEMENT  */
  YYSYMBOL_TYPE_OF_STATEMENT = 88,         /* TYPE_OF_STATEMENT  */
  YYSYMBOL_BOOLEAN_EXPRESSION = 89,        /* BOOLEAN_EXPRESSION  */
  YYSYMBOL_INTEGER_EXPRESSION = 90,        /* INTEGER_EXPRESSION  */
  YYSYMBOL_FUNCTION_CALL = 91,             /* FUNCTION_CALL  */
  YYSYMBOL_PARAMETER_LIST = 92,            /* PARAMETER_LIST  */
  YYSYMBOL_PARAMETER = 93,                 /* PARAMETER  */
  YYSYMBOL_ARRAY_LITERAL = 94,             /* ARRAY_LITERAL  */
  YYSYMBOL_ARRAY_DECLARATION = 95          /* ARRAY_DECLARATION  */
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
#define YYLAST   284

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  230

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
       0,    77,    77,    88,    90,    92,    94,    99,   104,   111,
     112,   114,   116,   117,   119,   120,   123,   133,   142,   151,
     160,   169,   179,   182,   185,   194,   217,   223,   224,   227,
     230,   235,   236,   238,   239,   240,   241,   247,   249,   253,
     261,   262,   263,   267,   269,   271,   272,   273,   275,   277,
     280,   281,   285,   287,   291,   295,   300,   301,   303,   312,
     313,   315,   316,   318,   320,   326,   334,   336,   337,   339,
     340,   341,   342,   345,   346,   351,   352,   353,   354,   355,
     356,   359,   360,   362,   380,   381,   382,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   403,   407,   411,   419,   423,   433,   436,   439,
     442,   446,   452,   463,   464,   477,   478,   480,   481,   482,
     487,   503,   504,   505,   507,   508,   509,   513,   515,   516,
     517
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
  "']'", "$accept", "S", "FUNC_START", "FUNCTION_DECLARATION",
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
  "BOOLEAN_EXPRESSION", "INTEGER_EXPRESSION", "FUNCTION_CALL",
  "PARAMETER_LIST", "PARAMETER", "ARRAY_LITERAL", "ARRAY_DECLARATION", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-202)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-30)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     202,    12,    32,  -202,  -202,  -202,  -202,    45,    49,    38,
    -202,    88,    70,    67,    84,    74,   103,   202,  -202,   204,
    -202,    82,   123,   195,  -202,  -202,  -202,   121,    98,  -202,
    -202,   177,  -202,  -202,  -202,   153,  -202,  -202,    40,   124,
     134,  -202,  -202,   119,   126,    64,  -202,  -202,   132,   144,
      10,   131,   133,    32,  -202,   125,  -202,   187,  -202,   165,
      26,   124,   154,   174,    94,    94,  -202,  -202,    71,   173,
    -202,   153,  -202,  -202,   188,   133,   133,  -202,  -202,  -202,
    -202,   133,   201,  -202,   153,  -202,   -27,   157,  -202,  -202,
    -202,  -202,  -202,    58,  -202,    40,   207,   136,  -202,   224,
    -202,  -202,    40,    40,  -202,  -202,    94,    40,    39,   233,
    -202,    40,    40,    39,   233,  -202,    49,  -202,   183,  -202,
    -202,  -202,    32,   205,  -202,   129,   139,    94,    39,   233,
      39,  -202,    39,   233,  -202,   212,    27,  -202,  -202,    60,
    -202,  -202,   102,  -202,   242,   199,   247,    40,    40,  -202,
     203,   203,   178,   213,    87,    94,    94,    40,   203,   203,
    -202,  -202,   220,  -202,  -202,    39,   233,   227,   231,   234,
     180,   218,   186,   223,  -202,  -202,    -1,  -202,   222,  -202,
     232,  -202,    94,  -202,   248,  -202,   133,   133,  -202,   237,
    -202,  -202,  -202,  -202,   239,  -202,  -202,    18,  -202,  -202,
     254,   203,  -202,  -202,   129,  -202,  -202,  -202,  -202,  -202,
      94,   269,    39,  -202,   252,  -202,   197,   236,  -202,   240,
      39,   241,  -202,  -202,  -202,  -202,   269,   243,  -202,  -202
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
       0,    98,   100,     0,     0,     0,    97,    99,     0,     0,
       0,     7,     4,     0,    13,     0,    20,     0,    15,     0,
      81,     0,     0,     0,     0,     0,    44,    38,     0,     0,
      72,     0,    69,    42,     0,     0,     0,    41,    40,    54,
      55,     0,     0,    70,    73,    66,     0,     0,    79,    75,
      76,    77,    78,    81,   116,     0,   114,     0,   115,    81,
      28,    83,     0,     0,   111,   101,     0,     0,    90,    88,
      92,     0,     0,    89,    87,    91,     8,     5,     0,    19,
      12,    14,     0,     0,    21,   123,     0,     0,    58,     0,
      52,    86,    85,    84,    71,     0,     0,    43,    53,    56,
       2,    74,     0,    67,     0,     0,     0,     0,     0,   127,
      93,    95,     0,     0,     0,     0,     0,     0,    94,    96,
       6,    18,     0,    17,   125,   126,   124,     0,   121,     0,
       0,     0,     0,     0,    39,    37,    81,    46,     0,    47,
      50,    65,     0,    57,     0,    60,     0,     0,    68,    83,
      80,   119,   112,   113,   117,   118,   109,     0,   129,   107,
     108,   110,    16,   120,   123,   104,   103,   102,   106,   105,
       0,     0,    64,    59,    61,    63,     0,     0,   122,     0,
      48,    81,    51,    62,   128,   130,     0,     0,    49,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -202,  -202,  -202,     3,     7,   161,  -202,  -202,  -202,  -202,
     225,    22,    11,   -33,  -202,   262,  -202,   -35,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -201,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,    66,    97,  -202,  -202,  -202,
     141,  -202,   -66,  -202,    -2,  -202,  -202,   -32,  -202,  -202,
     -41,   -19,   -23,    80,  -202,  -202,   -49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    28,    11,    12,    13,    57,
      58,    14,    69,    20,    21,    16,    17,    70,    71,   175,
      72,    73,    74,    75,   178,   219,   227,   179,    76,    77,
      78,    79,    80,    81,   183,   184,   185,   186,   187,    82,
      83,    84,    85,    86,    96,    23,    88,    24,    90,    91,
     165,   129,    98,   167,   168,    25,   110
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,   115,    18,    89,   108,   135,   100,   142,   143,   113,
     222,    15,    92,    93,    94,    18,   104,   117,   141,    97,
     118,    93,    94,   128,   130,   228,   109,   132,    15,    18,
     176,   114,    61,    87,    55,    19,    38,    22,    56,    89,
     137,   138,   106,    93,    94,    26,   139,   107,    92,   133,
      95,    22,    89,    59,    27,   107,   155,   156,   125,    22,
      55,    92,   123,    38,    56,   152,   124,    93,    94,    87,
     104,   105,    95,    29,    93,    94,   145,   104,   131,    59,
     181,   182,    87,   150,   151,   170,   172,   153,   154,   162,
     125,    30,   158,   159,    31,    38,   106,    93,    94,    33,
     104,   107,    32,   106,   180,    93,   166,   171,   173,    34,
      89,    35,    62,    63,   199,   200,    39,   147,   148,    92,
      22,   190,   197,   193,    51,   198,   106,    99,   194,   195,
      68,    52,    93,    94,    22,   104,   164,   101,   201,    40,
      87,   212,    93,    94,   192,   104,   169,   177,   217,    41,
      42,   214,   215,    43,    44,   102,    60,    67,    61,    45,
     119,   106,   103,    62,    63,   116,   147,   148,   111,   220,
     122,   106,    64,   144,   149,    65,    66,    67,   216,   180,
     112,    68,    53,    41,    42,   166,   126,    43,    44,     3,
       4,     5,    53,    45,   180,   155,   156,   155,   156,     3,
       4,     5,    54,   155,   156,     1,   127,     2,   134,    22,
     140,   196,   120,   206,     3,     4,     5,     6,   161,   208,
     136,    46,    47,   146,    22,    48,    49,   147,   148,   147,
     148,    50,   191,   147,   148,   224,    37,   174,   -29,   -29,
     163,    38,   157,   147,   148,   189,   191,   157,   147,   148,
      93,   207,   157,   147,   148,   202,   209,   210,   -29,   -29,
     203,    38,   157,   147,   148,   204,   211,   205,   181,   125,
     148,   155,   221,   182,   225,   226,   229,   160,    38,    36,
     223,   213,   121,   188,   218
};

static const yytype_uint8 yycheck[] =
{
       2,    50,     3,    35,    45,    71,    39,    34,    35,    50,
     211,     0,    35,     3,     4,     3,     6,    52,    84,    38,
      53,     3,     4,    64,    65,   226,    45,    68,    17,     3,
       3,    50,     5,    35,    31,     3,    37,    39,    31,    71,
      75,    76,    32,     3,     4,     0,    81,    37,    71,    68,
      32,    53,    84,    31,     5,    37,    17,    18,    32,    61,
      57,    84,    59,    37,    57,   106,    59,     3,     4,    71,
       6,     7,    32,    35,     3,     4,    95,     6,     7,    57,
      20,    21,    84,   102,   103,   126,   127,   106,   107,   122,
      32,     3,   111,   112,    24,    37,    32,     3,     4,    15,
       6,    37,    35,    32,   136,     3,   125,   126,   127,    35,
     142,     8,    10,    11,   155,   156,    34,    30,    31,   142,
     122,   144,    35,   146,     3,    38,    32,     3,   147,   148,
      28,    33,     3,     4,   136,     6,     7,     3,   157,    16,
     142,   182,     3,     4,   146,     6,     7,   136,   197,    26,
      27,   186,   187,    30,    31,    36,     3,    24,     5,    36,
      35,    32,    36,    10,    11,    34,    30,    31,    36,   210,
       5,    32,    19,    16,    38,    22,    23,    24,   197,   211,
      36,    28,     5,    26,    27,   204,    32,    30,    31,    12,
      13,    14,     5,    36,   226,    17,    18,    17,    18,    12,
      13,    14,    25,    17,    18,     3,    32,     5,    35,   211,
       9,    33,    25,    33,    12,    13,    14,    15,    35,    33,
      32,    26,    27,    16,   226,    30,    31,    30,    31,    30,
      31,    36,    33,    30,    31,    38,    32,    25,    34,    35,
      35,    37,    29,    30,    31,     3,    33,    29,    30,    31,
       3,    33,    29,    30,    31,    35,    33,    35,    34,    35,
      33,    37,    29,    30,    31,    34,    34,    33,    20,    32,
      31,    17,     3,    21,    38,    35,    33,   116,    37,    17,
     214,   184,    57,   142,   204
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,    12,    13,    14,    15,    40,    41,    42,
      43,    45,    46,    47,    50,    51,    54,    55,     3,     3,
      52,    53,    83,    84,    86,    94,     0,     5,    44,    35,
       3,    24,    35,    15,    35,     8,    54,    32,    37,    34,
      16,    26,    27,    30,    31,    36,    26,    27,    30,    31,
      36,     3,    33,     5,    25,    42,    43,    48,    49,    50,
       3,     5,    10,    11,    19,    22,    23,    24,    28,    51,
      56,    57,    59,    60,    61,    62,    67,    68,    69,    70,
      71,    72,    78,    79,    80,    81,    82,    83,    85,    86,
      87,    88,    91,     3,     4,    32,    83,    90,    91,     3,
      52,     3,    36,    36,     6,     7,    32,    37,    89,    90,
      95,    36,    36,    89,    90,    95,    34,    56,    52,    35,
      25,    49,     5,    42,    43,    32,    32,    32,    89,    90,
      89,     7,    89,    90,    35,    81,    32,    56,    56,    56,
       9,    81,    34,    35,    16,    90,    16,    30,    31,    38,
      90,    90,    89,    90,    90,    17,    18,    29,    90,    90,
      44,    35,    52,    35,     7,    89,    90,    92,    93,     7,
      89,    90,    89,    90,    25,    58,     3,    51,    63,    66,
      86,    20,    21,    73,    74,    75,    76,    77,    79,     3,
      91,    33,    83,    91,    90,    90,    33,    35,    38,    89,
      89,    90,    35,    33,    34,    33,    33,    33,    33,    33,
      35,    34,    89,    75,    56,    56,    90,    95,    92,    64,
      89,     3,    66,    74,    38,    38,    35,    65,    66,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    42,    43,    44,    44,    44,    45,
      45,    46,    47,    47,    48,    48,    49,    49,    49,    49,
      49,    49,    50,    50,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    55,    55,    56,    57,    58,
      59,    59,    59,    60,    61,    62,    63,    63,    64,    65,
      66,    66,    67,    68,    69,    70,    71,    71,    72,    73,
      73,    74,    74,    75,    76,    77,    78,    79,    79,    80,
      80,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    83,    83,    84,    85,    85,    85,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    87,    87,    87,    88,    88,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    90,    90,    90,
      91,    92,    92,    92,    93,    93,    93,    94,    95,    95,
      95
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
       3,     3,     3,     4,     4,     4,     4,     2,     2,     2,
       2,     3,     4,     4,     4,     4,     4,     3,     3,     3,
       3,     1,     3,     3,     1,     1,     1,     3,     3,     3,
       4,     1,     3,     0,     1,     1,     1,     4,     5,     3,
       5
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
#line 77 "lang.y"
                                               {
        printf("Program compiled succesfully!\n");
        return 0;
}
#line 1373 "lang.tab.c"
    break;

  case 3: /* FUNC_START: TYPE ID '('  */
#line 88 "lang.y"
                         { funcOn = true; funcSymTables.push_back(new SymTable(std::string((yyvsp[-2].strValue)), std::string((yyvsp[-1].strValue)))); }
#line 1379 "lang.tab.c"
    break;

  case 4: /* FUNCTION_DECLARATION: FUNC_START DECL_PARAMETER_SEQUENCE ')'  */
#line 90 "lang.y"
                                                              { funcOn = false; }
#line 1385 "lang.tab.c"
    break;

  case 5: /* FUNCTION_DEFINITION: FUNC_START DECL_PARAMETER_SEQUENCE ')' SCOPE  */
#line 92 "lang.y"
                                                                   { funcOn = false; }
#line 1391 "lang.tab.c"
    break;

  case 6: /* DECL_PARAMETER_SEQUENCE: TYPE ID ',' DECL_PARAMETER_SEQUENCE  */
#line 94 "lang.y"
                                                              {
                            SymTable * symTable = funcSymTables.back();
                            symTable->addParameter(std::string((yyvsp[-3].strValue)));
                            symTable->addSymbol(std::string((yyvsp[-2].strValue)), std::string((yyvsp[-3].strValue)));
                        }
#line 1401 "lang.tab.c"
    break;

  case 7: /* DECL_PARAMETER_SEQUENCE: TYPE ID  */
#line 99 "lang.y"
                                   {
                            SymTable * symTable = funcSymTables.back();
                            symTable->addParameter(std::string((yyvsp[-1].strValue)));
                            symTable->addSymbol(std::string((yyvsp[0].strValue)), std::string((yyvsp[-1].strValue)));
                        }
#line 1411 "lang.tab.c"
    break;

  case 9: /* CLASS_BEGIN_ELEMENT: ACCESS_MODIFIER CLASS  */
#line 111 "lang.y"
                                            {strcpy((yyval.strValue), (yyvsp[-1].strValue));}
#line 1417 "lang.tab.c"
    break;

  case 10: /* CLASS_BEGIN_ELEMENT: CLASS  */
#line 112 "lang.y"
                            {strcpy((yyval.strValue), "public");}
#line 1423 "lang.tab.c"
    break;

  case 11: /* CLASS_BEGIN: CLASS_BEGIN_ELEMENT ID  */
#line 114 "lang.y"
                                     {classSymTables.push_back(new ClassSymTable(std::string((yyvsp[-1].strValue)), std::string((yyvsp[0].strValue))));}
#line 1429 "lang.tab.c"
    break;

  case 16: /* CLASS_MEMBER: ACCESS_MODIFIER TYPE IDSEQUENCE ';'  */
#line 123 "lang.y"
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
#line 1444 "lang.tab.c"
    break;

  case 17: /* CLASS_MEMBER: ACCESS_MODIFIER FUNCTION_DECLARATION ';'  */
#line 133 "lang.y"
                                                        {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = std::string((yyvsp[-2].strValue)) + " " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
#line 1458 "lang.tab.c"
    break;

  case 18: /* CLASS_MEMBER: TYPE IDSEQUENCE ';'  */
#line 142 "lang.y"
                                   {
                ClassSymTable * symTable = classSymTables.back();
                for(auto [name, value] : unSymbols) 
                {
                    std::string className = "private " + name;
                    symTable->addSymbol(className, std::string((yyvsp[-2].strValue)));
                    processUpdate(symTable, className, std::string((yyvsp[-2].strValue)), value, '=');
                }
             }
#line 1472 "lang.tab.c"
    break;

  case 19: /* CLASS_MEMBER: FUNCTION_DECLARATION ';'  */
#line 151 "lang.y"
                                        {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = "private " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
#line 1486 "lang.tab.c"
    break;

  case 20: /* CLASS_MEMBER: FUNCTION_DEFINITION  */
#line 160 "lang.y"
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

  case 21: /* CLASS_MEMBER: ACCESS_MODIFIER FUNCTION_DEFINITION  */
#line 169 "lang.y"
                                                   {
                    ClassSymTable * symTable = classSymTables.back();
                    SymTable * funcSymTable = funcSymTables.back();
                    funcSymTables.pop_back();
                    std::string funcName = funcSymTable->getSymTableName();
                    funcName = std::string((yyvsp[-1].strValue)) + " " + funcName;
                    funcSymTable->setFunctionName(funcName);
                    symTable->addFuncSymTable(funcSymTable);
             }
#line 1514 "lang.tab.c"
    break;

  case 22: /* ACCESS_MODIFIER: PRIVATE  */
#line 179 "lang.y"
                          {
                    strcpy((yyval.strValue), (yyvsp[0].strValue));
                }
#line 1522 "lang.tab.c"
    break;

  case 23: /* ACCESS_MODIFIER: PUBLIC  */
#line 182 "lang.y"
                         {
                    strcpy((yyval.strValue), (yyvsp[0].strValue));
                }
#line 1530 "lang.tab.c"
    break;

  case 24: /* ACCESS_MODIFIER: PROTECTED  */
#line 185 "lang.y"
                            {
                    strcpy((yyval.strValue), (yyvsp[0].strValue));
                }
#line 1538 "lang.tab.c"
    break;

  case 25: /* LINE_DECLARATION: TYPE IDSEQUENCE  */
#line 194 "lang.y"
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
#line 1566 "lang.tab.c"
    break;

  case 26: /* LINE_DECLARATION: ID ID  */
#line 217 "lang.y"
        {
    SymTable * symTable = symTables.back();
    symTable->addSymbol(std::string((yyvsp[0].strValue)), std::string((yyvsp[-1].strValue)));
}
#line 1575 "lang.tab.c"
    break;

  case 29: /* ID_SEQUENCE_ELEMENT: ID  */
#line 227 "lang.y"
                         {
                         unSymbols.push_back({(yyvsp[0].strValue), 0});
                    }
#line 1583 "lang.tab.c"
    break;

  case 38: /* BEGIN_SCOPE: SCOPE_START  */
#line 249 "lang.y"
                          {
    symTables.push_back(new SymTable);
}
#line 1591 "lang.tab.c"
    break;

  case 39: /* END_SCOPE: SCOPE_END  */
#line 253 "lang.y"
                      {
    SymTable * symTable = symTables.back();
    delete symTable;
    symTables.pop_back();
}
#line 1601 "lang.tab.c"
    break;

  case 43: /* FOR_BLOCK: FOR_STATEMENT SCOPE  */
#line 267 "lang.y"
                                { symTables.pop_back(); }
#line 1607 "lang.tab.c"
    break;

  case 44: /* FOR_START: FOR  */
#line 269 "lang.y"
                { symTables.push_back(new SymTable); }
#line 1613 "lang.tab.c"
    break;

  case 54: /* IF_BLOCK: IF_COMPOSITION  */
#line 291 "lang.y"
                          {
    ifController = {false, 0};
}
#line 1621 "lang.tab.c"
    break;

  case 55: /* IF_COMPOSITION: IF_STRUCTURE  */
#line 295 "lang.y"
                              {
                      if(ifController.first)
                        ifController.second = -1;
                }
#line 1630 "lang.tab.c"
    break;

  case 58: /* IF_STATEMENT: IF BOOLEAN_EXPRESSION  */
#line 303 "lang.y"
                                     {
    ifController = {true, 0};
     ifController = {true, 0};
    if((yyvsp[0].tree)->hasConflictingTypes()==true) 
                        std::cout << "Conflicts here" << '\n';
    if((yyvsp[0].tree)->getExpressionType()!="bool" && (yyvsp[0].tree)->getExpressionResult()!="0" || (yyvsp[0].tree)->getExpressionType()=="bool" && (yyvsp[0].tree)->getExpressionResult()=="true") 
        ifController.second = 1;
}
#line 1643 "lang.tab.c"
    break;

  case 64: /* ELSE_IF_STATEMENT: ELSE_IF BOOLEAN_EXPRESSION  */
#line 320 "lang.y"
                                                 {
    if(ifController.second) ifController.second = -1;
    if(((yyvsp[0].tree)->getExpressionType()!="bool" && (yyvsp[0].tree)->getExpressionResult()!="0" || (yyvsp[0].tree)->getExpressionType()=="bool" && (yyvsp[0].tree)->getExpressionResult()=="true") && ifController.second == 0)
        ifController.second = 1;
}
#line 1653 "lang.tab.c"
    break;

  case 65: /* ELSE_STATEMENT: ELSE  */
#line 326 "lang.y"
                      {
    if(!ifController.second)
         ifController.second = 1;
}
#line 1662 "lang.tab.c"
    break;

  case 83: /* CLASS_LITERAL: LVALUE_ELEMENT ACCESS ID  */
#line 362 "lang.y"
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
#line 1684 "lang.tab.c"
    break;

  case 87: /* ASSIGNMENT_STATEMENT: CLASS_LITERAL '=' INTEGER_EXPRESSION  */
#line 384 "lang.y"
                                                            {processAssignmentStatement(getClassSymTable(std::string((yyvsp[-2].strValue))), std::string((yyvsp[-2].strValue)), (yyvsp[0].tree)->getExpressionType(), value((yyvsp[0].tree)->getExpressionResult()), '='); }
#line 1690 "lang.tab.c"
    break;

  case 88: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' INTEGER_EXPRESSION  */
#line 385 "lang.y"
                                                             { processAssignmentStatement(findSymTable(std::string((yyvsp[-2].strValue))), std::string((yyvsp[-2].strValue)), (yyvsp[0].tree)->getExpressionType(), value((yyvsp[0].tree)->getExpressionResult()), '='); }
#line 1696 "lang.tab.c"
    break;

  case 89: /* ASSIGNMENT_STATEMENT: CLASS_LITERAL '=' BOOLEAN_EXPRESSION  */
#line 386 "lang.y"
                                                            {processAssignmentStatement(getClassSymTable(std::string((yyvsp[-2].strValue))), std::string((yyvsp[-2].strValue)), (yyvsp[0].tree)->getExpressionType() , value((yyvsp[0].tree)->getExpressionResult()), '='); }
#line 1702 "lang.tab.c"
    break;

  case 90: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' BOOLEAN_EXPRESSION  */
#line 387 "lang.y"
                                                             { processAssignmentStatement(findSymTable(std::string((yyvsp[-2].strValue))), std::string((yyvsp[-2].strValue)), (yyvsp[0].tree)->getExpressionType(), value((yyvsp[0].tree)->getExpressionResult()), '=');}
#line 1708 "lang.tab.c"
    break;

  case 93: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT ADD_OPERATOR '=' INTEGER_EXPRESSION  */
#line 390 "lang.y"
                                                                          { processAssignmentStatement(findSymTable(std::string((yyvsp[-3].strValue))), std::string((yyvsp[-3].strValue)), (yyvsp[0].tree)->getExpressionType(),  value((yyvsp[0].tree)->getExpressionResult()), std::string((yyvsp[-2].strValue))[0]);}
#line 1714 "lang.tab.c"
    break;

  case 94: /* ASSIGNMENT_STATEMENT: CLASS_LITERAL ADD_OPERATOR '=' INTEGER_EXPRESSION  */
#line 391 "lang.y"
                                                                          { processAssignmentStatement(getClassSymTable(std::string((yyvsp[-3].strValue))), std::string((yyvsp[-3].strValue)), (yyvsp[0].tree)->getExpressionType(),  value((yyvsp[0].tree)->getExpressionResult()), std::string((yyvsp[-2].strValue))[0]);}
#line 1720 "lang.tab.c"
    break;

  case 95: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT MUL_OPERATOR '=' INTEGER_EXPRESSION  */
#line 392 "lang.y"
                                                                          { processAssignmentStatement(findSymTable(std::string((yyvsp[-3].strValue))), std::string((yyvsp[-3].strValue)), (yyvsp[0].tree)->getExpressionType(),  value((yyvsp[0].tree)->getExpressionResult()), std::string((yyvsp[-2].strValue))[0]);}
#line 1726 "lang.tab.c"
    break;

  case 96: /* ASSIGNMENT_STATEMENT: CLASS_LITERAL MUL_OPERATOR '=' INTEGER_EXPRESSION  */
#line 393 "lang.y"
                                                                         { processAssignmentStatement(getClassSymTable(std::string((yyvsp[-3].strValue))), std::string((yyvsp[-3].strValue)), (yyvsp[0].tree)->getExpressionType(),  value((yyvsp[0].tree)->getExpressionResult()), std::string((yyvsp[-2].strValue))[0]);}
#line 1732 "lang.tab.c"
    break;

  case 101: /* ASSIGNMENT_STATEMENT: LVALUE_ELEMENT '=' STRING_LITERAL  */
#line 398 "lang.y"
                                                         {processAssignmentStatement(findSymTable(std::string((yyvsp[-2].strValue))), std::string((yyvsp[-2].strValue)), "string", value((yyvsp[0].strValue)), '=');}
#line 1738 "lang.tab.c"
    break;

  case 102: /* PRINT_STATEMENT: PRINT '(' INTEGER_EXPRESSION ')'  */
#line 403 "lang.y"
                                                   {
                   if(validateStatement() && (yyvsp[-1].tree)->hasConflictingTypes()==0) 
                        std::cout << (yyvsp[-1].tree)->getExpressionResult() << '\n';
                }
#line 1747 "lang.tab.c"
    break;

  case 103: /* PRINT_STATEMENT: PRINT '(' BOOLEAN_EXPRESSION ')'  */
#line 407 "lang.y"
                                                  {
                  if(validateStatement() && (yyvsp[-1].tree)->hasConflictingTypes()==0) 
                        std::cout << (yyvsp[-1].tree)->getExpressionResult() << '\n';
                }
#line 1756 "lang.tab.c"
    break;

  case 104: /* PRINT_STATEMENT: PRINT '(' STRING_LITERAL ')'  */
#line 411 "lang.y"
                                               {
                    if(validateStatement()) {
                        std::cout << (yyvsp[-1].strValue) << '\n';
                    }
                }
#line 1766 "lang.tab.c"
    break;

  case 105: /* TYPE_OF_STATEMENT: TYPEOF '(' INTEGER_EXPRESSION ')'  */
#line 419 "lang.y"
                                                      {
                    if(validateStatement() && (yyvsp[-1].tree)->hasConflictingTypes()==0) 
                        std::cout << (yyvsp[-1].tree)->getExpressionType() << '\n';
                }
#line 1775 "lang.tab.c"
    break;

  case 106: /* TYPE_OF_STATEMENT: TYPEOF '(' BOOLEAN_EXPRESSION ')'  */
#line 423 "lang.y"
                                                      {
                    if(validateStatement() && (yyvsp[-1].tree)->hasConflictingTypes()==0) 
                        std::cout << (yyvsp[-1].tree)->getExpressionType() << '\n';
                }
#line 1784 "lang.tab.c"
    break;

  case 107: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION AND BOOLEAN_EXPRESSION  */
#line 433 "lang.y"
                                                                {
                        (yyval.tree) = new arb("&&","",(yyvsp[-2].tree),(yyvsp[0].tree));
                    }
#line 1792 "lang.tab.c"
    break;

  case 108: /* BOOLEAN_EXPRESSION: BOOLEAN_EXPRESSION OR BOOLEAN_EXPRESSION  */
#line 436 "lang.y"
                                                               {
                        (yyval.tree) = new arb("||","",(yyvsp[-2].tree),(yyvsp[0].tree));
                    }
#line 1800 "lang.tab.c"
    break;

  case 109: /* BOOLEAN_EXPRESSION: '(' BOOLEAN_EXPRESSION ')'  */
#line 439 "lang.y"
                                                 {
                        (yyval.tree) = (yyvsp[-1].tree);
                    }
#line 1808 "lang.tab.c"
    break;

  case 110: /* BOOLEAN_EXPRESSION: INTEGER_EXPRESSION BOOL_OPERATOR INTEGER_EXPRESSION  */
#line 443 "lang.y"
                    {
                    (yyval.tree) = new arb((yyvsp[-1].strValue),"",(yyvsp[-2].tree),(yyvsp[0].tree));
                    }
#line 1816 "lang.tab.c"
    break;

  case 111: /* BOOLEAN_EXPRESSION: BOOLEAN_LITERAL  */
#line 446 "lang.y"
                                      { 
                        (yyval.tree) = new arb("true","bool");
                    }
#line 1824 "lang.tab.c"
    break;

  case 112: /* INTEGER_EXPRESSION: LVALUE_ELEMENT ACCESS LVALUE_ELEMENT  */
#line 452 "lang.y"
                                                            {
                        SymTable * symTable = findSymTable(std::string((yyvsp[0].strValue)));
                        if(symTable != NULL && symTable->isSymbolValid(std::string((yyvsp[0].strValue)))) 
                        {
                            value val = symTable->getSymbolValue(std::string((yyvsp[0].strValue)));
                            if(std::holds_alternative<int>(val))
                                (yyval.tree) = new arb(fromIntToString(std::get<int>(val)),"int");
                        }
                        else 
                            yyerror(std::string("Undeclared variable ") + std::string((yyvsp[-2].strValue)));
                     }
#line 1840 "lang.tab.c"
    break;

  case 113: /* INTEGER_EXPRESSION: LVALUE_ELEMENT ACCESS FUNCTION_CALL  */
#line 463 "lang.y"
                                                          {(yyval.tree) = new arb("0","int");}
#line 1846 "lang.tab.c"
    break;

  case 114: /* INTEGER_EXPRESSION: LVALUE_ELEMENT  */
#line 464 "lang.y"
                                      {
                        SymTable * symTable = findSymTable(std::string((yyvsp[0].strValue)));
                        if(symTable != NULL && symTable->isSymbolValid(std::string((yyvsp[0].strValue)))) 
                        {
                            value val = symTable->getSymbolValue(std::string((yyvsp[0].strValue)));
                            if(std::holds_alternative<int>(val)) 
                                (yyval.tree) = new arb(fromIntToString(std::get<int>(val)), "int");
                        }
                        else {
                            yyerror(std::string("Undeclared variable ") + std::string((yyvsp[0].strValue)));
                            (yyval.tree) = 0;
                        }
                        }
#line 1864 "lang.tab.c"
    break;

  case 115: /* INTEGER_EXPRESSION: FUNCTION_CALL  */
#line 477 "lang.y"
                                    {(yyval.tree) = new arb("0","int");}
#line 1870 "lang.tab.c"
    break;

  case 116: /* INTEGER_EXPRESSION: INTEGER  */
#line 478 "lang.y"
                              {
                        (yyval.tree) = new arb(fromIntToString((yyvsp[0].iValue)),"int");}
#line 1877 "lang.tab.c"
    break;

  case 117: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION ADD_OPERATOR INTEGER_EXPRESSION  */
#line 480 "lang.y"
                                                                        { (yyval.tree) = new arb((yyvsp[-1].strValue),"",(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 1883 "lang.tab.c"
    break;

  case 118: /* INTEGER_EXPRESSION: INTEGER_EXPRESSION MUL_OPERATOR INTEGER_EXPRESSION  */
#line 481 "lang.y"
                                                                        { (yyval.tree) = new arb((yyvsp[-1].strValue),"",(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 1889 "lang.tab.c"
    break;

  case 119: /* INTEGER_EXPRESSION: '(' INTEGER_EXPRESSION ')'  */
#line 482 "lang.y"
                                                 {(yyval.tree) = (yyvsp[-1].tree);}
#line 1895 "lang.tab.c"
    break;

  case 120: /* FUNCTION_CALL: ID '(' PARAMETER_LIST ')'  */
#line 488 "lang.y"
{
    if(validateStatement()) 
    {
        if(!validateFunction(std::string((yyvsp[-3].strValue)), parameters)) 
        {
            yyerror("Function " + std::string((yyvsp[-3].strValue)) + " was not declared in this scope!\n");
            exit(1);
        }
    } 
    (yyval.tree) = new arb("0","int");
    parameters.clear();
}
#line 1912 "lang.tab.c"
    break;

  case 121: /* PARAMETER_LIST: PARAMETER  */
#line 503 "lang.y"
                           {parameters.push_back("int");}
#line 1918 "lang.tab.c"
    break;

  case 122: /* PARAMETER_LIST: PARAMETER ',' PARAMETER_LIST  */
#line 504 "lang.y"
                                              {parameters.push_back("int");}
#line 1924 "lang.tab.c"
    break;

  case 127: /* ARRAY_LITERAL: ID '[' INTEGER_EXPRESSION ']'  */
#line 513 "lang.y"
                                              { strcpy((yyval.strValue), (yyvsp[-3].strValue));}
#line 1930 "lang.tab.c"
    break;


#line 1934 "lang.tab.c"

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

#line 521 "lang.y"


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
    std::string value = std::get<std::string>(val);
    if(type == "int")
        val = std::stoi(value);
    else if(type == "bool") 
    {
        if(value == "true") val = true;
        else val = false;
    }
    else if(type == "char")
        val = value[0];
    else if(type == "float")
        val = std::stof(value);
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

std::string fromIntToString(int val)
{
    std::stringstream ss;
    std::string s;
    ss << val; ss >> s;
    return s;
}
