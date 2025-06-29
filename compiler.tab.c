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
#line 1 "compiler.y"

#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex(void);
extern int yylineno;
extern FILE *yyin;

void yyerror(const char *s);

// Global AST root
ASTNode* program_root = NULL;


#line 88 "compiler.tab.c"

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

#include "compiler.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_FLOATNUM = 4,                   /* FLOATNUM  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_STRINGLIT = 6,                  /* STRINGLIT  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_STRINGTYPE = 9,                 /* STRINGTYPE  */
  YYSYMBOL_BOOL = 10,                      /* BOOL  */
  YYSYMBOL_TRUE = 11,                      /* TRUE  */
  YYSYMBOL_FALSE = 12,                     /* FALSE  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_PRINT = 18,                     /* PRINT  */
  YYSYMBOL_FUNCTION = 19,                  /* FUNCTION  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_NEQ = 21,                       /* NEQ  */
  YYSYMBOL_GE = 22,                        /* GE  */
  YYSYMBOL_LE = 23,                        /* LE  */
  YYSYMBOL_GT = 24,                        /* GT  */
  YYSYMBOL_LT = 25,                        /* LT  */
  YYSYMBOL_ASSIGN = 26,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 27,                      /* PLUS  */
  YYSYMBOL_MINUS = 28,                     /* MINUS  */
  YYSYMBOL_MUL = 29,                       /* MUL  */
  YYSYMBOL_DIV = 30,                       /* DIV  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_NOT = 33,                       /* NOT  */
  YYSYMBOL_LPAREN = 34,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 35,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 36,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 37,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 38,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_UMINUS = 40,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_stmt_list = 43,                 /* stmt_list  */
  YYSYMBOL_stmt = 44,                      /* stmt  */
  YYSYMBOL_decl = 45,                      /* decl  */
  YYSYMBOL_assign = 46,                    /* assign  */
  YYSYMBOL_expr = 47,                      /* expr  */
  YYSYMBOL_if_stmt = 48,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 49,                /* while_stmt  */
  YYSYMBOL_for_stmt = 50,                  /* for_stmt  */
  YYSYMBOL_print_stmt = 51,                /* print_stmt  */
  YYSYMBOL_return_stmt = 52,               /* return_stmt  */
  YYSYMBOL_function_decl = 53,             /* function_decl  */
  YYSYMBOL_function_call = 54,             /* function_call  */
  YYSYMBOL_type = 55                       /* type  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   444

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    54,    54,    55,    59,    60,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    76,    81,    89,    93,    94,
      99,   104,   105,   110,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     134,   137,   143,   149,   157,   161,   165,   171,   175,   176,
     177,   178
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "FLOATNUM",
  "ID", "STRINGLIT", "INT", "FLOAT", "STRINGTYPE", "BOOL", "TRUE", "FALSE",
  "RETURN", "IF", "ELSE", "WHILE", "FOR", "PRINT", "FUNCTION", "EQ", "NEQ",
  "GE", "LE", "GT", "LT", "ASSIGN", "PLUS", "MINUS", "MUL", "DIV", "AND",
  "OR", "NOT", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON",
  "COMMA", "UMINUS", "$accept", "program", "stmt_list", "stmt", "decl",
  "assign", "expr", "if_stmt", "while_stmt", "for_stmt", "print_stmt",
  "return_stmt", "function_decl", "function_call", "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     251,   -94,   -94,   -10,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,     3,   -21,   -15,   -14,   -12,    18,     3,     3,     3,
      28,   283,   -94,    -9,    -8,   298,   -94,   -94,   -94,     4,
       5,   -94,    34,    71,     3,    -1,    43,   400,   -94,     3,
       3,    31,     3,    44,   -94,   -94,   336,   -94,   -94,   -94,
     -94,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,   -94,   -94,   -94,   -94,    60,   400,   -94,
     352,   368,    45,   384,    52,   -94,   143,   143,    29,    29,
      29,    29,    -4,    -4,   -94,   -94,   113,   413,     3,    53,
      61,     3,   -94,    65,   400,   283,   283,   317,   283,    57,
     111,    83,   146,    88,   -94,    78,    70,   -94,    72,    73,
     283,   283,   181,   216,   -94,   -94
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    19,    20,    18,    21,    48,    49,    50,    51,    22,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     0,     0,     0,     8,     9,    10,     0,
       0,     2,    24,     0,     0,     0,    18,    45,    24,     0,
       0,     0,     0,     0,    39,    38,     0,     1,     5,     6,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,    11,    12,    13,    15,    17,    47,
       0,     0,     0,     0,     0,    25,    30,    31,    34,    35,
      32,    33,    26,    27,    28,    29,    36,    37,     0,     0,
       0,     0,    44,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,    40,    42,     0,     0,    46,     0,     0,
       0,     0,     0,     0,    41,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -93,   -20,    66,    25,    -7,   -94,   -94,   -94,
     -94,   -94,   -94,     0,   -94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    38,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      32,    48,    99,   100,    37,   102,     1,     2,    36,     4,
      44,    45,    46,    39,     9,    10,    34,   112,   113,    40,
      41,    32,    42,    43,    35,    59,    60,    68,    47,    49,
      50,    17,    70,    71,    69,    73,    18,    19,     5,     6,
       7,     8,    64,    65,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    57,    58,    59,    60,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    66,    13,    14,    15,    67,    35,    74,    48,
      48,    94,    48,    91,    97,    17,    88,    93,   105,    95,
      18,    19,    48,    48,   103,    32,    32,    96,    32,    32,
      32,    98,    32,   108,    34,   109,     0,    72,   110,   111,
      32,    32,    32,    32,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   106,    13,    14,    15,
       0,     0,     0,    51,    52,    53,    54,    55,    56,    17,
      57,    58,    59,    60,    18,    19,     0,     0,   104,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,    14,    15,    53,    54,    55,    56,     0,
      57,    58,    59,    60,    17,     0,     0,     0,     0,    18,
      19,     0,     0,   107,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
       0,     0,     0,     0,    18,    19,     0,     0,   114,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     0,     0,     0,     0,    18,
      19,     0,     0,   115,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,    14,    15,
      16,     0,     0,     0,     0,     0,     0,     0,     0,    17,
       0,     0,     0,     0,    18,    19,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     0,     0,     0,     0,    18,    19,    51,    52,
      53,    54,    55,    56,     0,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,    63,    51,    52,    53,
      54,    55,    56,     0,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,   101,    51,    52,    53,    54,
      55,    56,     0,    57,    58,    59,    60,    61,    62,     0,
       0,    75,    51,    52,    53,    54,    55,    56,     0,    57,
      58,    59,    60,    61,    62,     0,     0,    89,    51,    52,
      53,    54,    55,    56,     0,    57,    58,    59,    60,    61,
      62,     0,     0,    90,    51,    52,    53,    54,    55,    56,
       0,    57,    58,    59,    60,    61,    62,     0,     0,    92,
      51,    52,    53,    54,    55,    56,     0,    57,    58,    59,
      60,    61,    62,    51,    52,    53,    54,    55,    56,     0,
      57,    58,    59,    60,    61
};

static const yytype_int8 yycheck[] =
{
       0,    21,    95,    96,    11,    98,     3,     4,     5,     6,
      17,    18,    19,    34,    11,    12,    26,   110,   111,    34,
      34,    21,    34,     5,    34,    29,    30,    34,     0,    38,
      38,    28,    39,    40,    35,    42,    33,    34,     7,     8,
       9,    10,    38,    38,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    27,    28,    29,    30,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    38,    16,    17,    18,     5,    34,    34,    99,
     100,    88,   102,    38,    91,    28,    26,    35,     5,    36,
      33,    34,   112,   113,    37,    95,    96,    36,    98,    99,
     100,    36,   102,    15,    26,    35,    -1,    41,    36,    36,
     110,   111,   112,   113,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,   101,    16,    17,    18,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    28,
      27,    28,    29,    30,    33,    34,    -1,    -1,    37,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    17,    18,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    28,    -1,    -1,    -1,    -1,    33,
      34,    -1,    -1,    37,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    33,
      34,    -1,    -1,    37,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    33,    34,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    33,    34,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    38,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    35,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    35,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    35,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    35,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    29,
      30,    31,    32,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    16,    17,    18,    19,    28,    33,    34,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    26,    34,     5,    47,    54,    34,
      34,    34,    34,     5,    47,    47,    47,     0,    44,    38,
      38,    20,    21,    22,    23,    24,    25,    27,    28,    29,
      30,    31,    32,    38,    38,    38,    38,     5,    47,    35,
      47,    47,    45,    47,    34,    35,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    26,    35,
      35,    38,    35,    35,    47,    36,    36,    47,    36,    43,
      43,    38,    43,    37,    37,     5,    46,    37,    15,    35,
      36,    36,    43,    43,    37,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    45,    45,    46,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      48,    48,    49,    50,    51,    52,    53,    54,    55,    55,
      55,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     2,     2,     2,     2,     2,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       7,    11,     7,    11,     4,     2,     7,     3,     1,     1,
       1,     1
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
  case 2: /* program: function_decl  */
#line 54 "compiler.y"
                  { program_root = (yyvsp[0].node); }
#line 1264 "compiler.tab.c"
    break;

  case 3: /* program: stmt_list  */
#line 55 "compiler.y"
                { program_root = create_ast_node(PROGRAM_NODE, (yyvsp[0].node), NULL, NULL); }
#line 1270 "compiler.tab.c"
    break;

  case 4: /* stmt_list: stmt  */
#line 59 "compiler.y"
         { (yyval.node) = create_ast_node(STMT_LIST, (yyvsp[0].node), NULL, NULL); }
#line 1276 "compiler.tab.c"
    break;

  case 5: /* stmt_list: stmt_list stmt  */
#line 60 "compiler.y"
                     { (yyval.node) = create_ast_node(STMT_LIST, (yyvsp[-1].node), (yyvsp[0].node), NULL); }
#line 1282 "compiler.tab.c"
    break;

  case 6: /* stmt: decl SEMICOLON  */
#line 64 "compiler.y"
                   { (yyval.node) = (yyvsp[-1].node); }
#line 1288 "compiler.tab.c"
    break;

  case 7: /* stmt: assign SEMICOLON  */
#line 65 "compiler.y"
                       { (yyval.node) = (yyvsp[-1].node); }
#line 1294 "compiler.tab.c"
    break;

  case 8: /* stmt: if_stmt  */
#line 66 "compiler.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1300 "compiler.tab.c"
    break;

  case 9: /* stmt: while_stmt  */
#line 67 "compiler.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1306 "compiler.tab.c"
    break;

  case 10: /* stmt: for_stmt  */
#line 68 "compiler.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1312 "compiler.tab.c"
    break;

  case 11: /* stmt: print_stmt SEMICOLON  */
#line 69 "compiler.y"
                           { (yyval.node) = (yyvsp[-1].node); }
#line 1318 "compiler.tab.c"
    break;

  case 12: /* stmt: return_stmt SEMICOLON  */
#line 70 "compiler.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 1324 "compiler.tab.c"
    break;

  case 13: /* stmt: function_call SEMICOLON  */
#line 71 "compiler.y"
                              { (yyval.node) = (yyvsp[-1].node); }
#line 1330 "compiler.tab.c"
    break;

  case 14: /* stmt: expr SEMICOLON  */
#line 72 "compiler.y"
                     { (yyval.node) = (yyvsp[-1].node); }
#line 1336 "compiler.tab.c"
    break;

  case 15: /* decl: type ID  */
#line 76 "compiler.y"
            { 
        ASTNode* node = create_ast_node(DECL_NODE, NULL, NULL, (yyvsp[0].str));
        node->data_type = (yyvsp[-1].type_code);
        (yyval.node) = node;
    }
#line 1346 "compiler.tab.c"
    break;

  case 16: /* decl: type ID ASSIGN expr  */
#line 81 "compiler.y"
                          { 
        ASTNode* node = create_ast_node(DECL_NODE, (yyvsp[0].node), NULL, (yyvsp[-2].str));
        node->data_type = (yyvsp[-3].type_code);
        (yyval.node) = node;
    }
#line 1356 "compiler.tab.c"
    break;

  case 17: /* assign: ID ASSIGN expr  */
#line 89 "compiler.y"
                   { (yyval.node) = create_ast_node(ASSIGN_NODE, (yyvsp[0].node), NULL, (yyvsp[-2].str)); }
#line 1362 "compiler.tab.c"
    break;

  case 18: /* expr: ID  */
#line 93 "compiler.y"
       { (yyval.node) = create_ast_node(VAR_NODE, NULL, NULL, (yyvsp[0].str)); }
#line 1368 "compiler.tab.c"
    break;

  case 19: /* expr: NUMBER  */
#line 94 "compiler.y"
             { 
        int* num_val = malloc(sizeof(int));
        *num_val = (yyvsp[0].num);
        (yyval.node) = create_ast_node(NUM_NODE, NULL, NULL, num_val); 
    }
#line 1378 "compiler.tab.c"
    break;

  case 20: /* expr: FLOATNUM  */
#line 99 "compiler.y"
               { 
        double* fnum_val = malloc(sizeof(double));
        *fnum_val = (yyvsp[0].fnum);
        (yyval.node) = create_ast_node(FLOAT_NODE, NULL, NULL, fnum_val); 
    }
#line 1388 "compiler.tab.c"
    break;

  case 21: /* expr: STRINGLIT  */
#line 104 "compiler.y"
                { (yyval.node) = create_ast_node(STR_NODE, NULL, NULL, (yyvsp[0].str)); }
#line 1394 "compiler.tab.c"
    break;

  case 22: /* expr: TRUE  */
#line 105 "compiler.y"
           { 
        int* bool_val = malloc(sizeof(int));
        *bool_val = 1;
        (yyval.node) = create_ast_node(BOOL_NODE, NULL, NULL, bool_val); 
    }
#line 1404 "compiler.tab.c"
    break;

  case 23: /* expr: FALSE  */
#line 110 "compiler.y"
            { 
        int* bool_val = malloc(sizeof(int));
        *bool_val = 0;
        (yyval.node) = create_ast_node(BOOL_NODE, NULL, NULL, bool_val); 
    }
#line 1414 "compiler.tab.c"
    break;

  case 24: /* expr: function_call  */
#line 115 "compiler.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1420 "compiler.tab.c"
    break;

  case 25: /* expr: LPAREN expr RPAREN  */
#line 116 "compiler.y"
                         { (yyval.node) = (yyvsp[-1].node); }
#line 1426 "compiler.tab.c"
    break;

  case 26: /* expr: expr PLUS expr  */
#line 117 "compiler.y"
                     { (yyval.node) = create_ast_node(BINOP_NODE, (yyvsp[-2].node), (yyvsp[0].node), "+"); }
#line 1432 "compiler.tab.c"
    break;

  case 27: /* expr: expr MINUS expr  */
#line 118 "compiler.y"
                      { (yyval.node) = create_ast_node(BINOP_NODE, (yyvsp[-2].node), (yyvsp[0].node), "-"); }
#line 1438 "compiler.tab.c"
    break;

  case 28: /* expr: expr MUL expr  */
#line 119 "compiler.y"
                    { (yyval.node) = create_ast_node(BINOP_NODE, (yyvsp[-2].node), (yyvsp[0].node), "*"); }
#line 1444 "compiler.tab.c"
    break;

  case 29: /* expr: expr DIV expr  */
#line 120 "compiler.y"
                    { (yyval.node) = create_ast_node(BINOP_NODE, (yyvsp[-2].node), (yyvsp[0].node), "/"); }
#line 1450 "compiler.tab.c"
    break;

  case 30: /* expr: expr EQ expr  */
#line 121 "compiler.y"
                   { (yyval.node) = create_ast_node(BINOP_NODE, (yyvsp[-2].node), (yyvsp[0].node), "=="); }
#line 1456 "compiler.tab.c"
    break;

  case 31: /* expr: expr NEQ expr  */
#line 122 "compiler.y"
                    { (yyval.node) = create_ast_node(BINOP_NODE, (yyvsp[-2].node), (yyvsp[0].node), "!="); }
#line 1462 "compiler.tab.c"
    break;

  case 32: /* expr: expr GT expr  */
#line 123 "compiler.y"
                   { (yyval.node) = create_ast_node(BINOP_NODE, (yyvsp[-2].node), (yyvsp[0].node), ">"); }
#line 1468 "compiler.tab.c"
    break;

  case 33: /* expr: expr LT expr  */
#line 124 "compiler.y"
                   { (yyval.node) = create_ast_node(BINOP_NODE, (yyvsp[-2].node), (yyvsp[0].node), "<"); }
#line 1474 "compiler.tab.c"
    break;

  case 34: /* expr: expr GE expr  */
#line 125 "compiler.y"
                   { (yyval.node) = create_ast_node(BINOP_NODE, (yyvsp[-2].node), (yyvsp[0].node), ">="); }
#line 1480 "compiler.tab.c"
    break;

  case 35: /* expr: expr LE expr  */
#line 126 "compiler.y"
                   { (yyval.node) = create_ast_node(BINOP_NODE, (yyvsp[-2].node), (yyvsp[0].node), "<="); }
#line 1486 "compiler.tab.c"
    break;

  case 36: /* expr: expr AND expr  */
#line 127 "compiler.y"
                    { (yyval.node) = create_ast_node(BINOP_NODE, (yyvsp[-2].node), (yyvsp[0].node), "&&"); }
#line 1492 "compiler.tab.c"
    break;

  case 37: /* expr: expr OR expr  */
#line 128 "compiler.y"
                   { (yyval.node) = create_ast_node(BINOP_NODE, (yyvsp[-2].node), (yyvsp[0].node), "||"); }
#line 1498 "compiler.tab.c"
    break;

  case 38: /* expr: NOT expr  */
#line 129 "compiler.y"
               { (yyval.node) = create_ast_node(UNARYOP_NODE, (yyvsp[0].node), NULL, "!"); }
#line 1504 "compiler.tab.c"
    break;

  case 39: /* expr: MINUS expr  */
#line 130 "compiler.y"
                              { (yyval.node) = create_ast_node(UNARYOP_NODE, (yyvsp[0].node), NULL, "-"); }
#line 1510 "compiler.tab.c"
    break;

  case 40: /* if_stmt: IF LPAREN expr RPAREN LBRACE stmt_list RBRACE  */
#line 134 "compiler.y"
                                                  {
        (yyval.node) = create_ast_node(IF_NODE, (yyvsp[-4].node), (yyvsp[-1].node), NULL);
    }
#line 1518 "compiler.tab.c"
    break;

  case 41: /* if_stmt: IF LPAREN expr RPAREN LBRACE stmt_list RBRACE ELSE LBRACE stmt_list RBRACE  */
#line 137 "compiler.y"
                                                                                 {
        (yyval.node) = create_ast_node(IF_ELSE_NODE, (yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node));
    }
#line 1526 "compiler.tab.c"
    break;

  case 42: /* while_stmt: WHILE LPAREN expr RPAREN LBRACE stmt_list RBRACE  */
#line 143 "compiler.y"
                                                     {
        (yyval.node) = create_ast_node(WHILE_NODE, (yyvsp[-4].node), (yyvsp[-1].node), NULL);
    }
#line 1534 "compiler.tab.c"
    break;

  case 43: /* for_stmt: FOR LPAREN decl SEMICOLON expr SEMICOLON assign RPAREN LBRACE stmt_list RBRACE  */
#line 149 "compiler.y"
                                                                                   {
        ASTNode* for_node = create_ast_node(FOR_NODE, (yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-1].node));
        for_node->extra = (yyvsp[-4].node);  // Store update in extra field
        (yyval.node) = for_node;
    }
#line 1544 "compiler.tab.c"
    break;

  case 44: /* print_stmt: PRINT LPAREN expr RPAREN  */
#line 157 "compiler.y"
                             { (yyval.node) = create_ast_node(PRINT_NODE, (yyvsp[-1].node), NULL, NULL); }
#line 1550 "compiler.tab.c"
    break;

  case 45: /* return_stmt: RETURN expr  */
#line 161 "compiler.y"
                { (yyval.node) = create_ast_node(RETURN_NODE, (yyvsp[0].node), NULL, NULL); }
#line 1556 "compiler.tab.c"
    break;

  case 46: /* function_decl: FUNCTION ID LPAREN RPAREN LBRACE stmt_list RBRACE  */
#line 165 "compiler.y"
                                                      {
        (yyval.node) = create_ast_node(FUNC_DECL_NODE, (yyvsp[-1].node), NULL, (yyvsp[-5].str));
    }
#line 1564 "compiler.tab.c"
    break;

  case 47: /* function_call: ID LPAREN RPAREN  */
#line 171 "compiler.y"
                     { (yyval.node) = create_ast_node(FUNC_CALL_NODE, NULL, NULL, (yyvsp[-2].str)); }
#line 1570 "compiler.tab.c"
    break;

  case 48: /* type: INT  */
#line 175 "compiler.y"
        { (yyval.type_code) = TYPE_INT; }
#line 1576 "compiler.tab.c"
    break;

  case 49: /* type: FLOAT  */
#line 176 "compiler.y"
            { (yyval.type_code) = TYPE_FLOAT; }
#line 1582 "compiler.tab.c"
    break;

  case 50: /* type: STRINGTYPE  */
#line 177 "compiler.y"
                 { (yyval.type_code) = TYPE_STRING; }
#line 1588 "compiler.tab.c"
    break;

  case 51: /* type: BOOL  */
#line 178 "compiler.y"
           { (yyval.type_code) = TYPE_BOOL; }
#line 1594 "compiler.tab.c"
    break;


#line 1598 "compiler.tab.c"

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

#line 181 "compiler.y"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", yylineno, s);
}

int main() {
    yyin = fopen("input.txt", "r");
    if (!yyin) {
        perror("input.txt");
        return 1;
    }
    yyparse();
    fclose(yyin);
    
    // Generate and execute code
    if (program_root) {
        execute_ast(program_root);
    }
    
    return 0;
}
