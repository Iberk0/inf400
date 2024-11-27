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
#line 1 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"

#include "lexer.hpp"

#include <kiraz/ast/Operator.h>
#include <kiraz/ast/Literal.h>
#include <kiraz/token/Literal.h>

int yyerror(const char *msg);
extern std::shared_ptr<Token> curtoken;
extern int yylineno;

#line 83 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_REJECTED = 3,                   /* REJECTED  */
  YYSYMBOL_L_INTEGER = 4,                  /* L_INTEGER  */
  YYSYMBOL_L_STRING = 5,                   /* L_STRING  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_KW_IMPORT = 7,                  /* KW_IMPORT  */
  YYSYMBOL_KW_FUNC = 8,                    /* KW_FUNC  */
  YYSYMBOL_KW_IF = 9,                      /* KW_IF  */
  YYSYMBOL_KW_WHILE = 10,                  /* KW_WHILE  */
  YYSYMBOL_KW_CLASS = 11,                  /* KW_CLASS  */
  YYSYMBOL_KW_LET = 12,                    /* KW_LET  */
  YYSYMBOL_KW_ELSE = 13,                   /* KW_ELSE  */
  YYSYMBOL_KW_RETURN = 14,                 /* KW_RETURN  */
  YYSYMBOL_OP_PLUS = 15,                   /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 16,                  /* OP_MINUS  */
  YYSYMBOL_OP_MULT = 17,                   /* OP_MULT  */
  YYSYMBOL_OP_DIVF = 18,                   /* OP_DIVF  */
  YYSYMBOL_OP_ASSIGN = 19,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_LPAREN = 20,                 /* OP_LPAREN  */
  YYSYMBOL_OP_RPAREN = 21,                 /* OP_RPAREN  */
  YYSYMBOL_OP_LBRACE = 22,                 /* OP_LBRACE  */
  YYSYMBOL_OP_RBRACE = 23,                 /* OP_RBRACE  */
  YYSYMBOL_OP_SCOLON = 24,                 /* OP_SCOLON  */
  YYSYMBOL_OP_COLON = 25,                  /* OP_COLON  */
  YYSYMBOL_OP_COMMA = 26,                  /* OP_COMMA  */
  YYSYMBOL_OP_DOT = 27,                    /* OP_DOT  */
  YYSYMBOL_OP_LESS = 28,                   /* OP_LESS  */
  YYSYMBOL_OP_LESSEQ = 29,                 /* OP_LESSEQ  */
  YYSYMBOL_OP_GREATER = 30,                /* OP_GREATER  */
  YYSYMBOL_OP_GREATEREQ = 31,              /* OP_GREATEREQ  */
  YYSYMBOL_OP_EQUAL = 32,                  /* OP_EQUAL  */
  YYSYMBOL_OP_NOT_EQUAL = 33,              /* OP_NOT_EQUAL  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_program = 35,                   /* program  */
  YYSYMBOL_stmt_list = 36,                 /* stmt_list  */
  YYSYMBOL_stmt = 37,                      /* stmt  */
  YYSYMBOL_expr_stmt = 38,                 /* expr_stmt  */
  YYSYMBOL_class_decl = 39,                /* class_decl  */
  YYSYMBOL_let_stmt = 40,                  /* let_stmt  */
  YYSYMBOL_func_decl = 41,                 /* func_decl  */
  YYSYMBOL_func_args = 42,                 /* func_args  */
  YYSYMBOL_func_arg = 43,                  /* func_arg  */
  YYSYMBOL_if_stmt = 44,                   /* if_stmt  */
  YYSYMBOL_else_stmt = 45,                 /* else_stmt  */
  YYSYMBOL_while_stmt = 46,                /* while_stmt  */
  YYSYMBOL_import_stmt = 47,               /* import_stmt  */
  YYSYMBOL_call_stmt = 48,                 /* call_stmt  */
  YYSYMBOL_dot = 49,                       /* dot  */
  YYSYMBOL_call_args = 50,                 /* call_args  */
  YYSYMBOL_return_stmt = 51,               /* return_stmt  */
  YYSYMBOL_return_value = 52,              /* return_value  */
  YYSYMBOL_scope = 53,                     /* scope  */
  YYSYMBOL_expr = 54,                      /* expr  */
  YYSYMBOL_assign_expr = 55,               /* assign_expr  */
  YYSYMBOL_compare_expr = 56,              /* compare_expr  */
  YYSYMBOL_addsub = 57,                    /* addsub  */
  YYSYMBOL_muldiv = 58,                    /* muldiv  */
  YYSYMBOL_posneg = 59,                    /* posneg  */
  YYSYMBOL_literal = 60                    /* literal  */
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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   164

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    27,    27,    31,    36,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    55,    59,    61,    65,    67,    69,
      74,    80,    81,    83,    92,    99,   101,   106,   107,   111,
     116,   121,   127,   128,   132,   133,   135,   143,   147,   148,
     151,   152,   157,   165,   169,   170,   174,   175,   176,   177,
     178,   179,   180,   184,   185,   186,   190,   191,   192,   196,
     197,   198,   199,   203,   204,   205
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
  "\"end of file\"", "error", "\"invalid token\"", "REJECTED",
  "L_INTEGER", "L_STRING", "IDENTIFIER", "KW_IMPORT", "KW_FUNC", "KW_IF",
  "KW_WHILE", "KW_CLASS", "KW_LET", "KW_ELSE", "KW_RETURN", "OP_PLUS",
  "OP_MINUS", "OP_MULT", "OP_DIVF", "OP_ASSIGN", "OP_LPAREN", "OP_RPAREN",
  "OP_LBRACE", "OP_RBRACE", "OP_SCOLON", "OP_COLON", "OP_COMMA", "OP_DOT",
  "OP_LESS", "OP_LESSEQ", "OP_GREATER", "OP_GREATEREQ", "OP_EQUAL",
  "OP_NOT_EQUAL", "$accept", "program", "stmt_list", "stmt", "expr_stmt",
  "class_decl", "let_stmt", "func_decl", "func_args", "func_arg",
  "if_stmt", "else_stmt", "while_stmt", "import_stmt", "call_stmt", "dot",
  "call_args", "return_stmt", "return_value", "scope", "expr",
  "assign_expr", "compare_expr", "addsub", "muldiv", "posneg", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-96)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,   -96,   -96,   -96,   105,   105,   -13,    -3,   105,   105,
       8,     8,     8,     8,    51,    76,   -96,   -96,    41,   -96,
      43,    54,    65,   -96,    69,    -2,    78,    83,   -96,    89,
      19,    77,   -96,     2,    99,    49,     8,     8,    50,    27,
     -96,   -96,    29,   -96,   -96,   -96,    79,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   105,   105,   -96,   -96,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,   -96,
     105,   103,   106,    33,     8,   105,   -96,    42,   -96,   -96,
      29,    19,    19,    19,    19,    19,    19,    77,    77,   -96,
     -96,    45,   -96,   101,   116,   120,   -96,   125,   119,    12,
     -96,   105,   121,   105,   105,    76,    76,   -96,   -96,     8,
     -96,   -96,   105,   -96,   -96,    76,   124,   132,   133,   134,
     122,   136,   144,   -96,   -96,    76,    10,   137,    76,   -96,
     -96,   -96,   138,   -96
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    63,    64,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     5,     0,     6,
       0,     0,     0,    11,     0,     0,     0,     0,    43,    44,
      46,    53,    56,    62,     0,     0,     0,     0,     0,     0,
      38,    37,    39,    60,    62,    59,     0,     1,     4,     8,
       7,     9,    10,    12,    34,     0,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      21,     0,     0,     0,     0,     0,    61,     0,    35,    33,
      45,    47,    48,    49,    50,    51,    52,    54,    55,    57,
      58,     0,    22,     0,     0,     0,    16,     0,     0,     0,
      31,     0,     0,     0,     0,    40,    40,    15,    17,     0,
      19,    36,     0,    23,    24,     0,     3,     0,     0,     0,
       0,     4,    26,    29,    18,    40,     0,     0,    40,    28,
      25,    20,     0,    27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -96,   -96,     6,     1,   -96,   -96,   -96,   -96,   -96,    59,
      37,   -96,   -96,   -96,   154,   -96,   -96,   -96,   -96,   -95,
     -10,   -96,    -8,    90,    48,     9,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    14,   115,   116,    17,    18,    19,    20,    91,    92,
      21,   130,    22,    23,    24,    25,    77,    26,    41,   117,
      27,    28,    29,    30,    31,    32,    44
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,    16,    42,    46,    34,    35,    15,    36,    38,    39,
      33,   118,     1,     2,     3,    33,    48,    37,    54,     6,
      43,    45,   -32,    11,    12,    55,    71,    72,    13,   -32,
     127,   109,   128,   132,    65,    66,   110,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    74,    10,    11,    12,
      80,    47,    75,    13,    78,    79,    96,    59,    60,    61,
      62,    63,    64,   100,    98,    49,   102,    50,   101,    70,
      93,   103,    73,    33,    16,    99,    89,    90,    51,    97,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    52,
      10,    11,    12,    53,    67,    68,    13,    33,    48,   119,
      76,   111,    56,    93,   114,    33,    33,    57,    58,     1,
       2,     3,   120,    87,    88,    33,   121,    59,    60,    61,
      62,    63,    64,    69,    94,    33,   104,    95,    33,     1,
       2,     3,     4,     5,     6,     7,     8,     9,   105,    10,
      11,    12,   106,   108,   125,    13,   112,   -41,   107,    81,
      82,    83,    84,    85,    86,   122,   123,   126,   124,   -42,
     131,   133,   113,   129,    40
};

static const yytype_uint8 yycheck[] =
{
       0,     0,    10,    13,     4,     5,     0,    20,     8,     9,
      10,   106,     4,     5,     6,    15,    15,    20,    20,     9,
      11,    12,    20,    15,    16,    27,    36,    37,    20,    27,
     125,    19,    22,   128,    15,    16,    24,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    19,    14,    15,    16,
      58,     0,    25,    20,    54,    55,    23,    28,    29,    30,
      31,    32,    33,    21,    74,    24,    21,    24,    26,    20,
      70,    26,    22,    73,    73,    75,    67,    68,    24,    73,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    24,
      14,    15,    16,    24,    17,    18,    20,    97,    97,   109,
      21,   101,    24,   103,   104,   105,   106,    24,    19,     4,
       5,     6,   112,    65,    66,   115,   115,    28,    29,    30,
      31,    32,    33,    24,    21,   125,    25,    21,   128,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    22,    14,
      15,    16,    22,    24,    22,    20,    25,    23,    23,    59,
      60,    61,    62,    63,    64,    23,    23,    13,    24,    23,
      23,    23,   103,   126,    10
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      14,    15,    16,    20,    35,    36,    37,    38,    39,    40,
      41,    44,    46,    47,    48,    49,    51,    54,    55,    56,
      57,    58,    59,    60,    60,    60,    20,    20,    60,    60,
      48,    52,    56,    59,    60,    59,    54,     0,    37,    24,
      24,    24,    24,    24,    20,    27,    24,    24,    19,    28,
      29,    30,    31,    32,    33,    15,    16,    17,    18,    24,
      20,    54,    54,    22,    19,    25,    21,    50,    60,    60,
      56,    57,    57,    57,    57,    57,    57,    58,    58,    59,
      59,    42,    43,    60,    21,    21,    23,    36,    54,    60,
      21,    26,    21,    26,    25,    22,    22,    23,    24,    19,
      24,    60,    25,    43,    60,    36,    37,    53,    53,    54,
      60,    37,    23,    23,    24,    22,    13,    53,    22,    44,
      45,    23,    53,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    38,    39,    39,    40,    40,    40,
      41,    42,    42,    42,    43,    44,    44,    45,    45,    46,
      47,    48,    49,    49,    50,    50,    50,    51,    52,    52,
      53,    53,    53,    54,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    57,    57,    57,    58,    58,    58,    59,
      59,    59,    59,    60,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     2,     2,
       2,     1,     2,     2,     2,     5,     4,     5,     7,     5,
      10,     0,     1,     3,     3,     9,     7,     3,     1,     7,
       3,     4,     1,     3,     0,     1,     3,     2,     1,     1,
       0,     1,     2,     1,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     2,
       2,     3,     1,     1,     1,     1
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
  case 2: /* program: stmt_list  */
#line 27 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
              {yyval = Node::add<ast::Module>(yyvsp[0]);}
#line 1221 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 3: /* stmt_list: stmt  */
#line 31 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
         { 
            auto nodeList = Node::add<ast::NodeList>();
            nodeList->add_statement(yyvsp[0]);
            yyval = nodeList;
        }
#line 1231 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 4: /* stmt_list: stmt_list stmt  */
#line 36 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                     { 
            yyval = yyvsp[-1];
            std::dynamic_pointer_cast<ast::NodeList>(yyval)->add_statement(yyvsp[0]);
        }
#line 1240 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 15: /* class_decl: KW_CLASS literal OP_LBRACE stmt_list OP_RBRACE  */
#line 60 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    { yyval = Node::add<ast::Class>(yyvsp[-3], yyvsp[-1]); }
#line 1246 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 16: /* class_decl: KW_CLASS literal OP_LBRACE OP_RBRACE  */
#line 61 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                                          { yyval = Node::add<ast::Class>(yyvsp[-2]);}
#line 1252 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 17: /* let_stmt: KW_LET literal OP_ASSIGN expr OP_SCOLON  */
#line 66 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    { yyval = Node::add<ast::Let>(yyvsp[-3], nullptr, yyvsp[-1]); }
#line 1258 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 18: /* let_stmt: KW_LET literal OP_COLON literal OP_ASSIGN expr OP_SCOLON  */
#line 68 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    { yyval = Node::add<ast::Let>(yyvsp[-5], yyvsp[-3], yyvsp[-1]); }
#line 1264 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 19: /* let_stmt: KW_LET literal OP_COLON literal OP_SCOLON  */
#line 70 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    { yyval = Node::add<ast::Let>(yyvsp[-3], yyvsp[-1], nullptr); }
#line 1270 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 20: /* func_decl: KW_FUNC literal OP_LPAREN func_args OP_RPAREN OP_COLON literal OP_LBRACE scope OP_RBRACE  */
#line 75 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    { yyval = Node::add<ast::Func>(yyvsp[-8], yyvsp[-6], yyvsp[-3], yyvsp[-1]); }
#line 1276 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 21: /* func_args: %empty  */
#line 80 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    { yyval = Node::add<ast::FuncArgs>(std::vector<Node::Ptr>{}); }
#line 1282 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 22: /* func_args: func_arg  */
#line 82 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    { yyval = Node::add<ast::FuncArgs>(std::vector<Node::Ptr>{ yyvsp[0] }); }
#line 1288 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 23: /* func_args: func_args OP_COMMA func_arg  */
#line 84 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    {
        auto args = std::dynamic_pointer_cast<ast::FuncArgs>(yyvsp[-2]);
        args->add_statement(yyvsp[0]);
        yyval = args;
    }
#line 1298 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 24: /* func_arg: literal OP_COLON literal  */
#line 93 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    {
        yyval = Node::add<ast::FuncArg>(yyvsp[-2], yyvsp[0]);
    }
#line 1306 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 25: /* if_stmt: KW_IF OP_LPAREN expr OP_RPAREN OP_LBRACE scope OP_RBRACE KW_ELSE else_stmt  */
#line 100 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    { yyval = Node::add<ast::If>(yyvsp[-6], yyvsp[-3], yyvsp[0]); }
#line 1312 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 26: /* if_stmt: KW_IF OP_LPAREN expr OP_RPAREN OP_LBRACE scope OP_RBRACE  */
#line 102 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    { yyval = Node::add<ast::If>(yyvsp[-4], yyvsp[-1], nullptr); }
#line 1318 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 27: /* else_stmt: OP_LBRACE scope OP_RBRACE  */
#line 106 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                              { yyval = yyvsp[-1];}
#line 1324 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 29: /* while_stmt: KW_WHILE OP_LPAREN expr OP_RPAREN OP_LBRACE scope OP_RBRACE  */
#line 112 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    { yyval = Node::add<ast::While>(yyvsp[-4], yyvsp[-1]); }
#line 1330 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 30: /* import_stmt: KW_IMPORT literal OP_SCOLON  */
#line 117 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    { yyval = Node::add<ast::Import>(yyvsp[-1]); }
#line 1336 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 31: /* call_stmt: dot OP_LPAREN call_args OP_RPAREN  */
#line 121 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                                      {
        yyval = Node::add<ast::Call>(yyvsp[-3], yyvsp[-1]);
    }
#line 1344 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 33: /* dot: dot OP_DOT literal  */
#line 128 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                         { yyval = Node::add<ast::OpDot>(yyvsp[-2],yyvsp[0]);}
#line 1350 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 34: /* call_args: %empty  */
#line 132 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    { yyval = Node::add<ast::FuncArgs>(std::vector<Node::Ptr>{}); }
#line 1356 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 35: /* call_args: literal  */
#line 134 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    { yyval = Node::add<ast::FuncArgs>(std::vector<Node::Ptr>{ yyvsp[0] }); }
#line 1362 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 36: /* call_args: call_args OP_COMMA literal  */
#line 136 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    {
        auto args = std::dynamic_pointer_cast<ast::FuncArgs>(yyvsp[-2]);
        args->add_statement(yyvsp[0]);
        yyval = args;
    }
#line 1372 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 37: /* return_stmt: KW_RETURN return_value  */
#line 143 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                                     { yyval = Node::add<ast::Return>(yyvsp[0]);}
#line 1378 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 40: /* scope: %empty  */
#line 151 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
    { yyval = Node::add<ast::NodeList>(std::vector<Node::Ptr>{}); }
#line 1384 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 41: /* scope: stmt  */
#line 152 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
          { 
            auto nodeList = Node::add<ast::NodeList>();
            nodeList->add_statement(yyvsp[0]);
            yyval = nodeList;
        }
#line 1394 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 42: /* scope: stmt_list stmt  */
#line 157 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                     { 
            yyval = yyvsp[-1];
            std::dynamic_pointer_cast<ast::NodeList>(yyval)->add_statement(yyvsp[0]);
        }
#line 1403 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 45: /* assign_expr: compare_expr OP_ASSIGN compare_expr  */
#line 170 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                                          { yyval = Node::add<ast::OpAssign>(yyvsp[-2], yyvsp[0]); }
#line 1409 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 47: /* compare_expr: compare_expr OP_LESS addsub  */
#line 175 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                                  { yyval = Node::add<ast::OpLess>(yyvsp[-2], yyvsp[0]); }
#line 1415 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 48: /* compare_expr: compare_expr OP_LESSEQ addsub  */
#line 176 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                                    { yyval = Node::add<ast::OpLessEq>(yyvsp[-2], yyvsp[0]); }
#line 1421 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 49: /* compare_expr: compare_expr OP_GREATER addsub  */
#line 177 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                                     { yyval = Node::add<ast::OpGreater>(yyvsp[-2], yyvsp[0]); }
#line 1427 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 50: /* compare_expr: compare_expr OP_GREATEREQ addsub  */
#line 178 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                                       { yyval = Node::add<ast::OpGreaterEq>(yyvsp[-2], yyvsp[0]); }
#line 1433 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 51: /* compare_expr: compare_expr OP_EQUAL addsub  */
#line 179 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                                   { yyval = Node::add<ast::OpEqual>(yyvsp[-2], yyvsp[0]); }
#line 1439 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 52: /* compare_expr: compare_expr OP_NOT_EQUAL addsub  */
#line 180 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                                       { yyval = Node::add<ast::OpNotEqual>(yyvsp[-2], yyvsp[0]); }
#line 1445 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 54: /* addsub: addsub OP_PLUS muldiv  */
#line 185 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                            { yyval = Node::add<ast::OpPlus>(yyvsp[-2], yyvsp[0]); }
#line 1451 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 55: /* addsub: addsub OP_MINUS muldiv  */
#line 186 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                             { yyval = Node::add<ast::OpMinus>(yyvsp[-2], yyvsp[0]); }
#line 1457 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 57: /* muldiv: muldiv OP_MULT posneg  */
#line 191 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                            { yyval = Node::add<ast::OpMult>(yyvsp[-2], yyvsp[0]); }
#line 1463 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 58: /* muldiv: muldiv OP_DIVF posneg  */
#line 192 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                            { yyval = Node::add<ast::OpDivF>(yyvsp[-2], yyvsp[0]); }
#line 1469 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 59: /* posneg: OP_MINUS posneg  */
#line 196 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                    { yyval = Node::add<ast::Signed>(OP_MINUS, yyvsp[0]); }
#line 1475 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 60: /* posneg: OP_PLUS posneg  */
#line 197 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                     { yyval = Node::add<ast::Signed>(OP_PLUS, yyvsp[0]); }
#line 1481 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 61: /* posneg: OP_LPAREN expr OP_RPAREN  */
#line 198 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                               { yyval = yyvsp[-1]; }
#line 1487 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 63: /* literal: L_INTEGER  */
#line 203 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
              { yyval = Node::add<ast::Integer>(curtoken); }
#line 1493 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 64: /* literal: L_STRING  */
#line 204 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
               { yyval = Node::add<ast::StringLiteral>(curtoken); }
#line 1499 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;

  case 65: /* literal: IDENTIFIER  */
#line 205 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"
                 { yyval = Node::add<ast::Identifier>(curtoken); }
#line 1505 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"
    break;


#line 1509 "/home/onuralp/Desktop/ODEV/inf400/build/parser.cpp"

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

#line 208 "/home/onuralp/Desktop/ODEV/inf400/parser.yy"


int yyerror(const char *s) {
    if (curtoken) {
        fmt::print("** Parser Error at {}:{} at token: {}\n",
                   yylineno, Token::colno, curtoken->as_string());
    } else {
        fmt::print("** Parser Error at {}:{}, null token\n",
                   yylineno, Token::colno);
    }
    Token::colno = 0;
    Node::reset_root();
    return 1;
}
