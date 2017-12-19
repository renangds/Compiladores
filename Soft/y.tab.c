/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "sintatica.y" /* yacc.c:339  */

	#include <iostream>
	#include <string>
	#include <sstream>
	#include <vector>
	#include <stack>
	#include "stdlib.h"

	#define YYSTYPE atributos
	#include "operationsSoft.h"

#line 78 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_CAST = 258,
    TK_OPL = 259,
    TK_OPA = 260,
    TK_TRUE = 261,
    TK_FALSE = 262,
    TK_ADD1 = 263,
    TK_SUB1 = 264,
    TK_ADDI = 265,
    TK_SUBI = 266,
    TK_INVERT = 267,
    TK_MAIN = 268,
    TK_ID = 269,
    TK_CHAR = 270,
    TK_STRING = 271,
    TK_INT = 272,
    TK_FLOAT = 273,
    TK_BOOL = 274,
    TK_TYPES = 275,
    TK_GLOBAL = 276,
    TK_VAR = 277,
    TK_FIM = 278,
    TK_ERROR = 279,
    TK_BEGIN = 280,
    TK_END = 281,
    TK_FUNCTION = 282,
    TK_FUNCTIONS = 283,
    TK_PROCEDURE = 284,
    TK_WHILE = 285,
    TK_FOR = 286,
    TK_DO = 287,
    TK_BREAK = 288,
    TK_CONTINUE = 289,
    TK_UNTIL = 290,
    TK_DEFAULT = 291,
    TK_IF = 292,
    TK_ELSE = 293,
    TK_ELIF = 294,
    TK_CASE = 295,
    TK_SWITCH = 296,
    TK_READLN = 297,
    TK_WRITELN = 298,
    TK_RETURN = 299,
    TK_POW = 300,
    TK_MULTI = 301,
    TK_DIVI = 302,
    TK_FACTORIAL = 303,
    TK_IN = 304,
    TK_FOREACH = 305,
    TK_NOT = 306,
    TK_AS = 307
  };
#endif
/* Tokens.  */
#define TK_CAST 258
#define TK_OPL 259
#define TK_OPA 260
#define TK_TRUE 261
#define TK_FALSE 262
#define TK_ADD1 263
#define TK_SUB1 264
#define TK_ADDI 265
#define TK_SUBI 266
#define TK_INVERT 267
#define TK_MAIN 268
#define TK_ID 269
#define TK_CHAR 270
#define TK_STRING 271
#define TK_INT 272
#define TK_FLOAT 273
#define TK_BOOL 274
#define TK_TYPES 275
#define TK_GLOBAL 276
#define TK_VAR 277
#define TK_FIM 278
#define TK_ERROR 279
#define TK_BEGIN 280
#define TK_END 281
#define TK_FUNCTION 282
#define TK_FUNCTIONS 283
#define TK_PROCEDURE 284
#define TK_WHILE 285
#define TK_FOR 286
#define TK_DO 287
#define TK_BREAK 288
#define TK_CONTINUE 289
#define TK_UNTIL 290
#define TK_DEFAULT 291
#define TK_IF 292
#define TK_ELSE 293
#define TK_ELIF 294
#define TK_CASE 295
#define TK_SWITCH 296
#define TK_READLN 297
#define TK_WRITELN 298
#define TK_RETURN 299
#define TK_POW 300
#define TK_MULTI 301
#define TK_DIVI 302
#define TK_FACTORIAL 303
#define TK_IN 304
#define TK_FOREACH 305
#define TK_NOT 306
#define TK_AS 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 233 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   538

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  273

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    62,     2,     2,
      67,    68,    66,    63,    71,    64,     2,    65,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    70,    69,
      58,    53,    59,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,    73,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,     2,    75,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    54,    55,
      56,    57,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    82,    86,    89,    94,    98,   102,   109,
     120,   131,   132,   133,   136,   142,   148,   159,   163,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   184,   194,   202,   214,   226,
     238,   247,   251,   254,   267,   281,   285,   289,   295,   303,
     313,   340,   372,   395,   420,   427,   431,   437,   448,   459,
     470,   481,   492,   503,   519,   540,   564,   567,   571,   589,
     600,   611,   622,   631,   640,   644,   648,   652,   658,   727,
     737,   747,   750,   756,   769,   775,   783,   791,   802,   826,
     848,   866,   871,   876,   883,   888,   893,   900,   907,   914,
     921,   925,   928,   936,   946,   957,   963,   969,   975,   981,
     987,  1015,  1035,  1041,  1045,  1049,  1052,  1060,  1066,  1070
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_CAST", "TK_OPL", "TK_OPA", "TK_TRUE",
  "TK_FALSE", "TK_ADD1", "TK_SUB1", "TK_ADDI", "TK_SUBI", "TK_INVERT",
  "TK_MAIN", "TK_ID", "TK_CHAR", "TK_STRING", "TK_INT", "TK_FLOAT",
  "TK_BOOL", "TK_TYPES", "TK_GLOBAL", "TK_VAR", "TK_FIM", "TK_ERROR",
  "TK_BEGIN", "TK_END", "TK_FUNCTION", "TK_FUNCTIONS", "TK_PROCEDURE",
  "TK_WHILE", "TK_FOR", "TK_DO", "TK_BREAK", "TK_CONTINUE", "TK_UNTIL",
  "TK_DEFAULT", "TK_IF", "TK_ELSE", "TK_ELIF", "TK_CASE", "TK_SWITCH",
  "TK_READLN", "TK_WRITELN", "TK_RETURN", "TK_POW", "TK_MULTI", "TK_DIVI",
  "TK_FACTORIAL", "TK_IN", "TK_FOREACH", "TK_NOT", "TK_AS", "'='",
  "\"||\"", "\"&&\"", "\"==\"", "\"!=\"", "'<'", "'>'", "\">=\"", "\"<=\"",
  "'%'", "'+'", "'-'", "'/'", "'*'", "'('", "')'", "';'", "':'", "','",
  "'['", "']'", "'{'", "'}'", "$accept", "S", "MAINS", "MAIN", "FUN",
  "PROCEDURE", "DECS", "DEC_FUN", "BLOCO", "COMANDOS", "COMANDO", "BREAK",
  "CONTINUE", "GLOBAL", "DECLARACOES", "VECTOR_MATRIX", "TERMS",
  "VECTOR_MATRIX_OPERATIONS", "SLICE", "OPERACOES", "EXPR", "CALL_FUN",
  "FUN_PARAMS", "FUN_PARAM", "LOGICO", "WHILE", "UNTIL", "FOR", "FOREACH",
  "CAST", "CONIF", "CONIF_NO_MATCHED", "CONIF_MATCHED", "SWITCH", "CASES",
  "CASE", "TERM", "WRITE", "PRINT", "PARAMS", "PARAM", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    61,   308,   309,   310,   311,    60,    62,
     312,   313,    37,    43,    45,    47,    42,    40,    41,    59,
      58,    44,    91,    93,   123,   125
};
# endif

#define YYPACT_NINF -196

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-196)))

#define YYTABLE_NINF -83

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     360,   296,  -196,  -196,  -196,  -196,   -61,  -196,  -196,  -196,
    -196,     4,     7,    50,    26,   401,    47,  -196,   360,  -196,
    -196,    17,  -196,   231,  -196,  -196,  -196,  -196,  -196,  -196,
     296,    35,  -196,   -11,    23,    36,   113,  -196,  -196,  -196,
     401,   401,   401,   401,   401,     5,    22,  -196,   385,   231,
      30,    42,    95,    95,  -196,   231,     6,     6,   114,   114,
    -196,   296,   108,    55,   106,   124,    73,    71,    77,  -196,
      74,   -55,   315,  -196,   296,    79,    95,   118,   385,   296,
     237,   133,    83,    88,   106,  -196,  -196,    89,    91,    97,
     101,   102,   103,   147,   315,   115,   117,   120,   121,  -196,
     122,   125,    70,   126,  -196,  -196,  -196,  -196,  -196,  -196,
     128,   129,  -196,   162,  -196,   315,   110,   127,   130,   401,
     401,   179,   296,   401,   401,  -196,   401,   417,   231,    20,
    -196,   401,   272,   173,   401,   401,   401,    32,   191,   296,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,   181,   182,   136,  -196,   296,   231,   231,  -196,
    -196,   231,   231,   142,   -58,   141,   146,    31,   391,   149,
     148,   231,   151,   152,   439,   154,   155,  -196,   156,   160,
     163,   183,   315,  -196,   296,  -196,   145,   433,   106,   401,
     401,   106,   106,   203,   205,   401,  -196,    32,  -196,    -6,
     192,   164,   -13,   455,  -196,   231,   -12,   165,   231,  -196,
     168,   449,  -196,    75,   210,   210,     3,  -196,   206,   243,
     296,  -196,   455,   193,   433,  -196,   471,  -196,   106,   207,
    -196,  -196,   296,   246,   210,   247,   204,   263,   239,   236,
     455,   253,   238,  -196,   401,   245,  -196,  -196,  -196,   401,
     240,   293,   290,  -196,   106,   249,   315,    19,   106,   251,
    -196,  -196,   106,   294,  -196,  -196,   106,    75,   257,  -196,
    -196,  -196,  -196
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,   105,   106,    72,    73,   104,   108,   110,   107,
     109,     0,     0,     0,     0,     0,     0,     2,     4,     6,
       7,     0,    42,    47,    77,    74,    75,    76,   104,    90,
      81,    40,    41,     0,     0,     0,     0,     1,     3,     8,
       0,     0,     0,     0,     0,     0,    79,    82,     0,    38,
      76,     0,    13,    13,    67,    83,    68,    69,    71,    70,
      78,    81,     0,     0,     0,     0,     0,    11,     0,    80,
       0,    43,    18,     5,    14,     0,    13,     0,     0,     0,
     104,     0,     0,     0,     0,    35,    36,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,    66,
       0,     0,     0,    74,    23,    25,    24,    28,    26,    27,
       0,     0,    15,     0,    12,    18,     0,     0,    48,     0,
       0,     0,     0,     0,     0,    65,    81,     0,    58,    76,
      37,     0,     0,     0,     0,     0,     0,   115,     0,     0,
      16,    17,    29,    30,    34,    19,    33,    20,    31,    21,
      32,    22,     0,     0,    44,    45,     0,    59,    60,    63,
      64,    61,    62,    76,   104,     0,     0,    54,     0,     0,
       0,     0,    74,    74,     0,    76,   116,   119,     0,   113,
       0,     0,    18,    10,     0,    49,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,   115,   111,     0,
       0,     0,   104,     0,    50,    54,   104,     0,    56,    84,
      74,     0,    86,    91,   101,   101,     0,   114,     0,     0,
       0,    46,     0,     0,     0,    55,     0,    85,     0,     0,
      92,    93,     0,     0,   101,     0,   117,     0,     0,     0,
      53,   104,     0,    97,     0,     0,    98,   100,    99,     0,
       0,     0,     0,    51,     0,    74,    18,     0,     0,     0,
       9,    87,     0,   102,   118,    88,     0,    96,     0,    89,
      94,    95,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,   310,  -196,  -196,  -196,   -40,  -196,   -62,   -91,
    -196,  -196,  -196,  -196,    12,   -44,  -151,  -116,  -126,   111,
     -15,  -196,   273,  -196,   -57,  -196,  -196,  -196,  -196,  -196,
    -196,    76,    84,  -196,  -195,  -196,     1,  -196,  -196,   143,
    -196
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    18,    19,    20,    66,    67,    73,    93,
      94,    95,    96,    97,    98,    22,   117,    99,   100,   101,
      23,    24,    45,    46,    25,   104,   105,   106,   107,    26,
     108,   230,   231,   109,   233,   234,    27,   110,   111,   178,
     179
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,   166,    29,   141,    63,   185,    30,    40,   218,    30,
      40,   165,    21,    68,   127,   103,    49,    78,    31,    79,
     235,    32,   133,    40,   153,    55,    56,    57,    58,    59,
      21,    47,    50,   201,   116,    40,   114,   103,     1,   247,
      35,     2,     3,     4,     5,   219,   176,    37,   177,     6,
       7,     8,     9,    10,    30,    30,    51,   102,   103,   222,
     224,   207,    47,    33,    34,   128,    41,    42,    43,    44,
     204,    43,    44,    60,    40,   112,   236,   172,   173,   102,
     118,   129,    41,    42,    43,    44,    39,   223,   -57,   -57,
      52,   200,   264,    61,    41,    42,    43,    44,   166,   -39,
     102,   -56,    15,    53,   157,   158,   165,    48,   161,   162,
      64,    36,   167,   228,   229,    65,   168,    40,    40,   171,
     171,   174,    70,   160,   253,   103,   209,   163,    71,   212,
     213,    72,   210,    41,    42,    43,    44,   175,    74,   148,
     181,    75,    76,   115,   169,    77,    48,   130,     1,   113,
     131,     2,     3,     4,     5,   132,   134,   118,   135,   202,
       7,     8,     9,    10,   136,   263,   243,   102,   137,   138,
     139,   205,   208,   140,   171,   211,    41,    42,    43,    44,
     216,    54,   152,   154,   142,   118,   143,   255,   205,   144,
     145,   146,   261,   159,   147,   149,   265,   150,   151,   103,
     267,   156,   155,   170,   269,   180,   182,   205,   183,   208,
     184,   205,    15,   -82,   186,   190,   187,   203,   189,   191,
     192,   239,   194,   197,   196,   205,   128,   195,   214,   171,
     215,   198,   199,   245,   257,    40,   220,   226,   225,   221,
       1,   102,   129,     2,     3,     4,     5,   119,   120,   121,
     232,     6,     7,     8,     9,    10,     1,   238,   237,     2,
       3,     4,     5,   119,   120,   121,   240,     6,     7,     8,
       9,    10,   246,   248,   244,     1,   249,   250,     2,     3,
       4,     5,   122,   123,   124,   125,     6,     7,     8,     9,
      10,   251,    11,    12,    41,    42,    43,    44,   122,   123,
     124,   125,     2,     3,   126,   252,   254,   259,   258,   127,
      28,     7,     8,     9,    10,   256,   260,   262,     1,   266,
     126,     2,     3,     4,     5,   222,   272,   268,    38,    80,
       7,     8,     9,    10,    69,    11,    81,   242,     0,    15,
     217,     0,     0,   270,     0,    82,    83,    84,    85,    86,
      87,   271,    88,     0,     0,     0,    89,    90,    91,     0,
       0,     0,     0,     1,     0,    92,     2,     3,     4,     5,
       0,     0,     0,     0,     6,     7,     8,     9,    10,     0,
      11,    12,    15,     0,     0,     0,     0,    13,     1,    14,
       0,     2,     3,     4,     5,    40,     0,     0,     0,     6,
       7,     8,     9,    10,     1,    62,     0,     2,     3,     4,
       5,     0,     0,     0,     0,     6,     7,     8,     9,    10,
       1,     0,     0,     2,     3,     4,     5,    15,     0,     0,
       0,   164,     7,     8,     9,    10,     1,     0,     0,     2,
       3,     4,     5,    40,     0,     0,     0,   206,     7,     8,
       9,    10,    15,    40,    41,    42,    43,    44,     1,   188,
       0,     2,     3,     4,     5,     0,     0,     0,    15,   202,
       7,     8,     9,    10,     1,     0,     0,     2,     3,     4,
       5,     0,     0,     0,    15,   241,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     0,    41,    42,    43,    44,     0,   193,     0,     0,
       0,     0,    41,    42,    43,    44,     0,   227,     0,     0,
       0,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15
};

static const yytype_int16 yycheck[] =
{
      15,   127,     1,    94,    48,   156,    67,     4,    14,    67,
       4,   127,     0,    53,    72,    72,    31,    72,    14,    74,
     215,    14,    84,     4,   115,    40,    41,    42,    43,    44,
      18,    30,    31,   184,    78,     4,    76,    94,     3,   234,
      14,     6,     7,     8,     9,    51,    14,     0,    16,    14,
      15,    16,    17,    18,    67,    67,    67,    72,   115,    72,
      72,   187,    61,    13,    14,    80,    63,    64,    65,    66,
     186,    65,    66,    68,     4,    74,    73,   134,   135,    94,
      79,    80,    63,    64,    65,    66,    69,   203,    68,    69,
      67,   182,    73,    71,    63,    64,    65,    66,   224,    69,
     115,    70,    67,    67,   119,   120,   222,    72,   123,   124,
      68,   126,   127,    38,    39,    20,   131,     4,     4,   134,
     135,   136,    14,   122,   240,   182,   188,   126,    73,   191,
     192,    25,   189,    63,    64,    65,    66,   136,    14,    69,
     139,    68,    71,    25,   132,    68,    72,    14,     3,    70,
      67,     6,     7,     8,     9,    67,    67,   156,    67,    14,
      15,    16,    17,    18,    67,   256,   228,   182,    67,    67,
      67,   186,   187,    26,   189,   190,    63,    64,    65,    66,
     195,    68,    20,    73,    69,   184,    69,   244,   203,    69,
      69,    69,   254,    14,    69,    69,   258,    69,    69,   256,
     262,    71,    75,    30,   266,    14,    25,   222,    26,   224,
      74,   226,    67,    71,    73,    67,    70,    72,    69,    68,
      68,   220,    68,    63,    68,   240,   241,    72,    25,   244,
      25,    68,    49,   232,   249,     4,    44,    69,    73,    75,
       3,   256,   241,     6,     7,     8,     9,    10,    11,    12,
      40,    14,    15,    16,    17,    18,     3,    14,    52,     6,
       7,     8,     9,    10,    11,    12,    73,    14,    15,    16,
      17,    18,    26,    26,    67,     3,    72,    14,     6,     7,
       8,     9,    45,    46,    47,    48,    14,    15,    16,    17,
      18,    52,    20,    21,    63,    64,    65,    66,    45,    46,
      47,    48,     6,     7,    67,    69,    68,    14,    68,    72,
      14,    15,    16,    17,    18,    70,    26,    68,     3,    68,
      67,     6,     7,     8,     9,    72,    69,    33,    18,    14,
      15,    16,    17,    18,    61,    20,    21,   226,    -1,    67,
     197,    -1,    -1,   267,    -1,    30,    31,    32,    33,    34,
      35,   267,    37,    -1,    -1,    -1,    41,    42,    43,    -1,
      -1,    -1,    -1,     3,    -1,    50,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      20,    21,    67,    -1,    -1,    -1,    -1,    27,     3,    29,
      -1,     6,     7,     8,     9,     4,    -1,    -1,    -1,    14,
      15,    16,    17,    18,     3,    20,    -1,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
       3,    -1,    -1,     6,     7,     8,     9,    67,    -1,    -1,
      -1,    14,    15,    16,    17,    18,     3,    -1,    -1,     6,
       7,     8,     9,     4,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    67,     4,    63,    64,    65,    66,     3,    68,
      -1,     6,     7,     8,     9,    -1,    -1,    -1,    67,    14,
      15,    16,    17,    18,     3,    -1,    -1,     6,     7,     8,
       9,    -1,    -1,    -1,    67,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    63,    64,    65,    66,    -1,    68,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    -1,    68,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,     9,    14,    15,    16,    17,
      18,    20,    21,    27,    29,    67,    77,    78,    79,    80,
      81,    90,    91,    96,    97,   100,   105,   112,    14,   112,
      67,    14,    14,    13,    14,    14,    96,     0,    78,    69,
       4,    63,    64,    65,    66,    98,    99,   112,    72,    96,
     112,    67,    67,    67,    68,    96,    96,    96,    96,    96,
      68,    71,    20,    91,    68,    20,    82,    83,    82,    98,
      14,    73,    25,    84,    14,    68,    71,    68,    72,    74,
      14,    21,    30,    31,    32,    33,    34,    35,    37,    41,
      42,    43,    50,    85,    86,    87,    88,    89,    90,    93,
      94,    95,    96,   100,   101,   102,   103,   104,   106,   109,
     113,   114,   112,    70,    82,    25,    91,    92,   112,    10,
      11,    12,    45,    46,    47,    48,    67,    72,    96,   112,
      14,    67,    67,    84,    67,    67,    67,    67,    67,    67,
      26,    85,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    20,    85,    73,    75,    71,    96,    96,    14,
     112,    96,    96,   112,    14,    93,    94,    96,    96,    90,
      30,    96,   100,   100,    96,   112,    14,    16,   115,   116,
      14,   112,    25,    26,    74,    92,    73,    70,    68,    69,
      67,    68,    68,    68,    68,    72,    68,    63,    68,    49,
      85,    92,    14,    72,    93,    96,    14,    94,    96,    84,
     100,    96,    84,    84,    25,    25,    96,   115,    14,    51,
      44,    75,    72,    93,    72,    73,    69,    68,    38,    39,
     107,   108,    40,   110,   111,   110,    73,    52,    14,   112,
      73,    14,    95,    84,    67,   112,    26,   110,    26,    72,
      14,    52,    69,    93,    68,   100,    70,    96,    68,    14,
      26,    84,    68,    85,    73,    84,    68,    84,    33,    84,
     107,   108,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    78,    79,    79,    79,    79,    80,
      81,    82,    82,    82,    83,    83,    84,    85,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    87,    88,    89,    90,    90,
      90,    90,    90,    91,    91,    91,    91,    91,    92,    92,
      93,    93,    93,    93,    93,    94,    94,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    97,    98,
      98,    98,    99,   100,   101,   101,   102,   103,   104,   104,
     105,   106,   106,   106,   107,   107,   107,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   112,   112,   112,   112,
     112,   113,   114,   115,   115,   115,   116,   116,   116,   116
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     5,     1,     1,     2,    13,
       8,     1,     3,     0,     2,     3,     3,     2,     0,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     1,     1,     2,     3,     3,
       2,     2,     1,     5,     8,     8,    11,     1,     1,     3,
       5,     8,     4,     7,     1,     6,     1,     2,     2,     3,
       3,     3,     3,     3,     3,     2,     1,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     0,     1,     3,     5,     6,     5,     9,     9,    10,
       2,     5,     6,     6,     6,     6,     5,     2,     7,     7,
       2,     0,     4,     6,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     1,     3,     0,     1,     4,     7,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 77 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 83 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
			}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 90 "sintatica.y" /* yacc.c:1646  */
    {
				cout << "\n#include <iostream>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <string>\nusing namespace std;\n\nint main (){" << endl;
				cout << "\n" << "\n" << (yyvsp[0]).traducao << "\n\treturn 0;\n}" << endl;
			}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 95 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = " ";
			}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 99 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = " ";
			}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 103 "sintatica.y" /* yacc.c:1646  */
    {
				declaracoes_globais += (yyval).traducao;
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 110 "sintatica.y" /* yacc.c:1646  */
    {
				pilha.top().type_return = (yyvsp[-6]).var_tipo;
				pilha.top().name_return = (yyvsp[-2]).label;
				pilha.top().name = (yyvsp[-11]).nome;
				pilha.top().body = (yyvsp[-4]).traducao;
				funs.push_back(pilha.top());
				pilha.pop();
			}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 121 "sintatica.y" /* yacc.c:1646  */
    {
				pilha.top().type_return = "none";
				pilha.top().name_return = "procedure";
				pilha.top().name = (yyvsp[-6]).nome;
				pilha.top().body = (yyvsp[-1]).traducao;
				funs.push_back(pilha.top());
				pilha.pop();
			}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 137 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_param_names();
				set_parameters((yyvsp[-1]).var_tipo, (yyvsp[0]).nome, "none", (yyval).label);
				set_var((yyvsp[-1]).var_tipo, (yyvsp[0]).nome, "none", (yyval).label);
			}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 143 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_param_names();
			}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 149 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
				if(pilha.size() == 2){
						format_declarations(&(yyval));
						/*free_all(&$$);*/
				}
				pilha.pop();
			}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 160 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao + "\n" + (yyvsp[0]).traducao;
			}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 185 "sintatica.y" /* yacc.c:1646  */
    {
				if(pilha.top().name == "switch"){
					(yyval).traducao = "goto: switch"+to_string(switches);
				} else{
					(yyval).traducao = "\tgoto loop" + to_string(loops) + ";\n";
				}
			}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 195 "sintatica.y" /* yacc.c:1646  */
    {
				int l = loops;
				l--;
				(yyval).traducao = "\tgoto loop" + to_string(l) + ";\n";
			}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 203 "sintatica.y" /* yacc.c:1646  */
    {
				for(int i=0; i < first_exestack->map_vars.size(); i++){
					if(first_exestack->map_vars[i].name == (yyvsp[0]).nome){
						(yyval).traducao = "\n\t" + first_exestack->map_vars[i].id + " = " + first_exestack->map_vars[i].value + ";\n";
						break;
					}
					if(i+1 == first_exestack->map_vars.size()) yyerror(in_line() + " Variável global não declarada!");
				}
			}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 215 "sintatica.y" /* yacc.c:1646  */
    {
				if(search_var((yyvsp[-1]).nome)) yyerror(in_line() + " Variável" + (yyvsp[-1]).nome + "já existe");
				if(get_vector((yyvsp[-1]).nome)){
					yyerror(in_line() + " Existe um vetor " + (yyvsp[-1]).nome + " declarado.");
				}
				(yyval).label = create_var_names();
				(yyval).var_tipo = (yyvsp[-2]).var_tipo;
				implicit_return(&(yyval), &(yyvsp[0]));
				set_var((yyvsp[-2]).var_tipo, (yyvsp[-1]).nome, (yyvsp[0]).valor, (yyval).label);
				(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[0]).label + ";\n";
			}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 227 "sintatica.y" /* yacc.c:1646  */
    {
				if(search_var((yyvsp[-1]).nome)) yyerror(in_line() + " Variável " + (yyvsp[-1]).nome + " já existe");
				if(get_vector((yyvsp[-1]).nome)){
					yyerror(in_line() + " Existe um vetor " + (yyvsp[-1]).nome + " declarado.");
				}
				(yyval).label = create_var_names();
				(yyval).var_tipo = (yyvsp[-2]).var_tipo;
				implicit_return(&(yyval), &(yyvsp[0]));
				set_var((yyvsp[-2]).var_tipo, (yyvsp[-1]).nome, (yyvsp[0]).valor, (yyval).label);
				(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[0]).label + ";";
			}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 239 "sintatica.y" /* yacc.c:1646  */
    {
				if(search_var((yyvsp[0]).nome)) yyerror(in_line() + " Variável" + (yyvsp[0]).nome + "já existe");
				if(get_vector((yyvsp[0]).nome)){
					yyerror(in_line() + " Existe um vetor " + (yyvsp[0]).nome + " declarado.");
				}
				(yyval).label = create_var_names();
				set_var((yyvsp[-1]).var_tipo, (yyvsp[0]).nome, " ", (yyval).label);
			}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 248 "sintatica.y" /* yacc.c:1646  */
    {

			}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 255 "sintatica.y" /* yacc.c:1646  */
    {
					//cout << "entrou1" << endl;
					error_indextype((yyvsp[-1]).var_tipo);

					(yyval).label = create_vectors_names();
					(yyval).var_tipo = (yyvsp[-4]).var_tipo;

					(yyval).traducao = (yyvsp[-1]).traducao + "\t" + (yyval).label + " = (" + (yyval).var_tipo 
					+ "*)malloc(" + (yyvsp[-1]).label + "*sizeof(" + (yyvsp[-4]).var_tipo + "));\n";

					set_vector((yyval).var_tipo, (yyvsp[-3]).nome, (yyvsp[-1]).label, "0", (yyval).label);
				}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 268 "sintatica.y" /* yacc.c:1646  */
    {
					//cout << "entrou2" << endl;
					error_indextype((yyvsp[-4]).var_tipo);
					error_indextype((yyvsp[-1]).var_tipo);

					(yyval).label = create_vectors_names();
					(yyval).var_tipo = (yyvsp[-7]).var_tipo;

					(yyval).traducao = (yyvsp[-4]).traducao + (yyvsp[-1]).traducao + "\t" + (yyval).label + " = (" + (yyval).var_tipo 
					+ "*)malloc(" + (yyvsp[-4]).label + "*" + (yyvsp[-1]).label + "*sizeof(" + (yyvsp[-7]).var_tipo + "));\n";

					set_vector((yyval).var_tipo, (yyvsp[-6]).nome, (yyvsp[-4]).label, (yyvsp[-1]).label, (yyval).label);
				}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 282 "sintatica.y" /* yacc.c:1646  */
    {
					//cout << "entrou3" << endl;
				}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 286 "sintatica.y" /* yacc.c:1646  */
    {
					//cout << "entrou4" << endl;
				}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 290 "sintatica.y" /* yacc.c:1646  */
    {
	
				}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 296 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[0]).traducao;
			VAR temp;
			temp.type = (yyvsp[0]).var_tipo;
			temp.name = (yyvsp[0]).label;
			vec_att.push_back(temp);
		}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 304 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao;
			VAR temp;
			temp.type = (yyvsp[-2]).var_tipo;
			temp.name = (yyvsp[-2]).label;
			vec_att.push_back(temp);
		}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 314 "sintatica.y" /* yacc.c:1646  */
    {
								//cout << "entrou5" << endl;
								error_indextype((yyvsp[-1]).var_tipo);
								VECTORS* temp = get_vector((yyvsp[-4]).nome);

								if(!temp){
									yyerror(in_line() + "Vetor " + (yyvsp[-4]).nome + " não existe!");
								} else if (temp->column != "0"){
									yyerror(in_line() + "Você procura uma tabela seu malakoi");
								}

								(yyval).label = temp->id + "[" + temp->row + "]";
								(yyval).var_tipo = temp->type;

								string jump = create_jump_names();
								string error_msg = "\n\tcout << " + in_line() + "<< \"limite do vetor excedido\" <<endl;";

								string condition = "\n\tif(" + (yyvsp[-2]).label + "<" + temp->row + ") goto " 
								+ jump + ";\n" + error_msg + "\n\texit(1);\n";

								implicit_return(&(yyval), &(yyvsp[0]));

								(yyval).traducao += (yyvsp[-2]).traducao + (yyvsp[0]).traducao + condition + "\n\t" + jump 
								+ ":\n\t" + temp->id + "[" + (yyvsp[-2]).label + "] = " + (yyvsp[0]).label + ";\n";

							}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 341 "sintatica.y" /* yacc.c:1646  */
    {
								//cout << "entrou6" << endl;
								error_indextype((yyvsp[-4]).var_tipo);
								error_indextype((yyvsp[-1]).var_tipo);
								VECTORS* temp = get_matrix((yyvsp[-7]).nome);

								if(!temp){
									yyerror(in_line() + "Matriz " + (yyvsp[-7]).nome + " não existe!");
								}  else if (temp->column != "0"){
									yyerror(in_line() + "Você procura uma tabela seu malakoi");
								}

								(yyval).label = temp->id + "[" + (yyvsp[-5]).label + "*" + temp->row + "+" + (yyvsp[-2]).label + "]";
								(yyval).var_tipo = temp->type;

								string jump1 = create_jump_names();
								string jump2 = create_jump_names();
								string error_msg = "\n\tcout << " + in_line() + "<< \"limite da matriz excedido\"<<endl;";

								string condition = "\n\tif(" + (yyvsp[-5]).label + "<" + temp->row + ") goto " 
								+ jump1 + ";\n" + error_msg + "\n\texit(1);\n";

								condition += "\n\t" + jump1 + ":\n\tif(" + (yyvsp[-2]).label + "<" + temp->column + ") goto " 
								+ jump2 + ";\n" + error_msg + "\n\texit(1);\n";

								implicit_return(&(yyval), &(yyvsp[-3]));

								(yyval).traducao += (yyvsp[-5]).traducao + (yyvsp[-2]).traducao + (yyvsp[0]).traducao + condition + "\n\t" + jump2 
								+ ":\n\t" + (yyval).label + " = " + (yyvsp[0]).label + ";\n";

							}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 373 "sintatica.y" /* yacc.c:1646  */
    {
								//cout << "entrou7" << endl;
								error_indextype((yyvsp[0]).var_tipo);
								VECTORS* temp = get_vector((yyvsp[-3]).nome);

								if(!temp){
									yyerror(in_line() + "Vetor " + (yyvsp[-3]).nome + " não existe!");
								} else if (temp->column != "0"){
									yyerror(in_line() + "Você procura uma tabela seu malakoi");
								}

								(yyval).label = temp->id + "[" + temp->row + "]";
								(yyval).var_tipo = temp->type;

								string jump = create_jump_names();
								string error_msg = "\n\tcout << " + in_line() + "<< \"limite do vetor excedido\" << endl;";

								string condition = (yyvsp[-1]).traducao + "\n\tif(" + (yyvsp[-1]).label + "<" + temp->row + ") goto " 
								+ jump + ";\n" + error_msg + "\n\texit(1);\n\t" + jump + ":\n";

								(yyval).traducao = condition;
							}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 396 "sintatica.y" /* yacc.c:1646  */
    {
								//cout << "entrou8" << endl;
								error_indextype((yyvsp[-3]).var_tipo);
								error_indextype((yyvsp[0]).var_tipo);
								VECTORS* temp = get_matrix((yyvsp[-6]).nome);

								if(!temp){
									yyerror(in_line() + "Matriz " + (yyvsp[-6]).nome + " não existe!");
								}

								(yyval).label = temp->id + "[" + (yyvsp[-4]).label + "*" + temp->row + "+" + (yyvsp[-1]).label + "]";
								(yyval).var_tipo = temp->type;

								string jump1 = create_jump_names();
								string jump2 = create_jump_names();
								string error_msg = "\n\tcout << " + in_line() + "<< \"limite da Matriz excedido\" <<endl;";

								string condition = (yyvsp[-4]).traducao + "\n\tif(" + (yyvsp[-4]).label + "<" + temp->row + ") goto "
								+ jump1 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump1 + ":\n";

								condition += (yyvsp[-1]).traducao + "\n\tif(" + (yyvsp[-4]).label + "<" + temp->row + ") goto "
								+ jump2 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump2 + ":\n";

							}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 421 "sintatica.y" /* yacc.c:1646  */
    {	
								//cout << "entrou9" << endl;
								(yyval) = (yyvsp[0]);
							}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 428 "sintatica.y" /* yacc.c:1646  */
    {

		}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 432 "sintatica.y" /* yacc.c:1646  */
    {

		}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 438 "sintatica.y" /* yacc.c:1646  */
    {
				if(!get_var((yyvsp[-1]).nome)){
					(yyval).label = create_var_names();
					set_var((yyvsp[0]).var_tipo, (yyvsp[-1]).nome, (yyvsp[0]).valor, (yyval).label);
				}
				(yyval).var_tipo = get_var((yyvsp[-1]).nome)->type;
				implicit_return(&(yyval), &(yyvsp[0]));
				(yyval).traducao = (yyvsp[0]).traducao + "\t" + get_var((yyvsp[-1]).nome)->id + " = " + (yyvsp[0]).label + ";\n";
				(yyvsp[0]).traducao = " ";
			}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 449 "sintatica.y" /* yacc.c:1646  */
    {
				if(!get_var((yyvsp[-1]).nome)){
					(yyval).label = create_var_names();
					set_var((yyvsp[0]).var_tipo, (yyvsp[-1]).nome, (yyvsp[0]).valor, (yyval).label);
				}
				(yyval).var_tipo = get_var((yyvsp[-1]).nome)->type;
				implicit_return(&(yyval), &(yyvsp[0]));
				(yyval).traducao = (yyvsp[0]).traducao + "\n \t" + get_var((yyvsp[-1]).nome)->id + " = " + (yyvsp[0]).label + ";\n";
				(yyvsp[0]).traducao = " ";
			}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 460 "sintatica.y" /* yacc.c:1646  */
    {
				if(!get_var((yyvsp[-2]).nome)){
					(yyval).label = create_var_names();
					set_var((yyvsp[-1]).var_tipo, (yyvsp[-2]).nome, (yyvsp[-1]).valor, (yyval).label);
				}
				(yyval).var_tipo = get_var((yyvsp[-2]).nome)->type;
				implicit_return(&(yyval), &(yyvsp[0]));
				(yyval).traducao = (yyvsp[0]).traducao + "\n \t" + get_var((yyvsp[-2]).nome)->id + " += " + get_var((yyvsp[-2]).nome)->id + "+" + (yyvsp[0]).label + ";\n";
				(yyvsp[-1]).traducao = " ";
			}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 471 "sintatica.y" /* yacc.c:1646  */
    {
				if(!get_var((yyvsp[-2]).nome)){
					(yyval).label = create_var_names();
					set_var((yyvsp[-1]).var_tipo, (yyvsp[-2]).nome, (yyvsp[-1]).valor, (yyval).label);
				}
				(yyval).var_tipo = get_var((yyvsp[-2]).nome)->type;
				implicit_return(&(yyval), &(yyvsp[0]));
				(yyval).traducao = (yyvsp[0]).traducao + "\n \t" + get_var((yyvsp[-2]).nome)->id + " = " + get_var((yyvsp[-2]).nome)->id + "-" + (yyvsp[0]).label + ";\n";
				(yyvsp[-1]).traducao = " ";
			}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 482 "sintatica.y" /* yacc.c:1646  */
    {
				if(!get_var((yyvsp[-2]).nome)){
					(yyval).label = create_var_names();
					set_var((yyvsp[-1]).var_tipo, (yyvsp[-2]).nome, (yyvsp[-1]).valor, (yyval).label);
				}
				(yyval).var_tipo = get_var((yyvsp[-2]).nome)->type;
				implicit_return(&(yyval), &(yyvsp[0]));
				(yyval).traducao = (yyvsp[0]).traducao + "\n \t" + get_var((yyvsp[-2]).nome)->id + " = " + get_var((yyvsp[-2]).nome)->id + "*" + (yyvsp[0]).label + ";\n";
				(yyvsp[-1]).traducao = " ";
			}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 493 "sintatica.y" /* yacc.c:1646  */
    {
				if(!get_var((yyvsp[-2]).nome)){
					(yyval).label = create_var_names();
					set_var((yyvsp[-1]).var_tipo, (yyvsp[-2]).nome, (yyvsp[-1]).valor, (yyval).label);
				}
				(yyval).var_tipo = get_var((yyvsp[-2]).nome)->type;
				implicit_return(&(yyval), &(yyvsp[0]));
				(yyval).traducao = (yyvsp[0]).traducao + "\n \t" + get_var((yyvsp[-2]).nome)->id + " = " + get_var((yyvsp[-2]).nome)->id + "/" + (yyvsp[0]).label + ";\n";
				(yyvsp[-1]).traducao = " ";
			}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 504 "sintatica.y" /* yacc.c:1646  */
    {
				if(!get_var((yyvsp[-2]).nome)){
					(yyval).label = create_var_names();
					set_var((yyvsp[-1]).var_tipo, (yyvsp[-2]).nome, (yyvsp[-1]).valor, (yyval).label);
				}

				if(!get_var((yyvsp[0]).nome)){
					(yyval).label = create_var_names();
					set_var((yyvsp[-1]).var_tipo, (yyvsp[-2]).nome, (yyvsp[-1]).valor, (yyval).label);
				}
				(yyval).label = create_temp_names();
				(yyval).var_tipo = get_var((yyvsp[0]).nome)->type;
				set_var((yyval).var_tipo, "temp", (yyvsp[0]).valor, (yyval).label);
				(yyval).traducao += "\n\t" + (yyval).label + " = " + get_var((yyvsp[0]).nome)->id + "\n\t" + get_var((yyvsp[0]).nome)->id + " = " + get_var((yyvsp[-2]).nome)->id + "\n\t" + get_var((yyvsp[-2]).nome)->id + " = " + (yyval).label + ";\n";
			}
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 520 "sintatica.y" /* yacc.c:1646  */
    {
				string loop = create_loop_names();
				string control = create_temp_names();
				string box = create_temp_names();

				set_var("int", "", "0", control);

				VAR* temp = get_var((yyvsp[-2]).nome);

				set_var(temp->type, "", "0", box);

				if(!temp){
					yyerror(in_line() + " Variável não existe, operação requer que já exista");
				}

				(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + loop + ":\n\t" + box + " = " + temp->id + " * " + temp->id + ";\n\t"
				+ temp->id + " = " + box + ";\n\t" + control + " = " + control + " + 1;\n\tif(" + control + " < "
				+ (yyvsp[0]).label + ") goto " + loop + ";\n";

			}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 541 "sintatica.y" /* yacc.c:1646  */
    {
				string loop = create_loop_names();
				string control = create_temp_names();

				VAR* temp = get_var((yyvsp[-1]).nome);

				(yyval).label = temp->id;
				(yyval).var_tipo = temp->type;

				if(!temp){
					yyerror(in_line() + " Variável não existe, operação requer que já exista");
				}

				if((yyval).var_tipo != "int"){
					yyerror(in_line() + "Operação permitida somente com inteiros!");
				}

				set_var("int", "", "0", control);

				(yyval).traducao = "\n\t" + control + " = " + (yyval).label + ";\n";
				(yyval).traducao += "\t" + loop + ":\n\t" + control + " = " + control + " - 1;\n\t"
				+ (yyval).label + " *= " + control + ";\n\t" + "if(" + control + " != 1) goto " + loop + ";\n";
			}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 568 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[-1]);
			}
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 572 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).var_tipo == "string" || (yyvsp[0]).var_tipo == "string"){
					(yyval).label = create_temp_names();
					(yyval).traducao = (yyvsp[-2]).traducao + "\n" + (yyvsp[0]).traducao + "\n";
					implicit_string(&(yyvsp[-2]), &(yyvsp[0]), &(yyval));
					set_var((yyval).var_tipo, "temp", (yyval).valor, (yyval).label);
				} else{
					if((yyvsp[-2]).var_tipo == "bool" || (yyvsp[0]).var_tipo == "bool") yyerror(in_line () + "Operação inválida com booleano");
					(yyval).op = "+";
					(yyval).label = create_temp_names();
					(yyval).traducao = (yyvsp[-2]).traducao + "\n" + (yyvsp[0]).traducao + "\n";
					implicit_cast(&(yyvsp[-2]), &(yyvsp[0]), &(yyval));
					set_var((yyval).var_tipo, "temp", (yyval).valor, (yyval).label);
					(yyval).traducao += "\t" + (yyval).label + " = " + (yyvsp[-2]).label + '+' + (yyvsp[0]).label + ";\n";
					(yyval).valor = (yyval).label;
				}
			}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 590 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).var_tipo == "bool" || (yyvsp[0]).var_tipo == "bool") yyerror(in_line () + "Operação inválida com booleano");
				(yyval).op = "-";
				(yyval).label = create_temp_names();
				(yyval).traducao = (yyvsp[-2]).traducao + "\n" + (yyvsp[0]).traducao + "\n";
				implicit_cast(&(yyvsp[-2]), &(yyvsp[0]), &(yyval));
				set_var((yyval).var_tipo, "temp", (yyval).valor, (yyval).label);
				(yyval).traducao += "\t" + (yyval).label + " = " + (yyvsp[-2]).label + '-' + (yyvsp[0]).label + ";\n";
				(yyval).valor = (yyval).label;
			}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 601 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).var_tipo == "bool" || (yyvsp[0]).var_tipo == "bool") yyerror(in_line () + "Operação inválida com booleano");
				(yyval).op = "*";
				(yyval).label = create_temp_names();
				(yyval).traducao = (yyvsp[-2]).traducao + "\n" + (yyvsp[0]).traducao + "\n";
				implicit_cast(&(yyvsp[-2]), &(yyvsp[0]), &(yyval));
				set_var((yyval).var_tipo, "temp", (yyval).valor, (yyval).label);
				(yyval).traducao += "\t" + (yyval).label + " = " + (yyvsp[-2]).label + '*' + (yyvsp[0]).label + ";\n";
				(yyval).valor = (yyval).label;
			}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 612 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).var_tipo == "bool" || (yyvsp[0]).var_tipo == "bool") yyerror(in_line () + "Operação inválida com booleano");
				(yyval).op = "/";
				(yyval).label = create_temp_names();
				(yyval).traducao = (yyvsp[-2]).traducao + "\n" + (yyvsp[0]).traducao + "\n";
				implicit_cast(&(yyvsp[-2]), &(yyvsp[0]), &(yyval));
				set_var((yyval).var_tipo, "temp", (yyval).valor, (yyval).label);
				(yyval).traducao += "\t" + (yyval).label + " = " + (yyvsp[-2]).label + '/' + (yyvsp[0]).label + ";\n";
				(yyval).valor = (yyval).label;
			}
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 623 "sintatica.y" /* yacc.c:1646  */
    {
				if(!get_var((yyvsp[0]).nome)) yyerror(in_line() + "Variável " + (yyvsp[0]).nome +  "não existe");
				if(get_var((yyvsp[0]).nome)->type == "bool" || get_var((yyvsp[0]).nome)->type == "char") yyerror(in_line () + "Operação só permitida com float e int");
				(yyval).label = create_temp_names();
				(yyval).var_tipo = get_var((yyvsp[0]).nome)->type;
				set_var((yyval).var_tipo, "temp", (yyval).valor, (yyval).label);
				(yyval).traducao = "\t" + (yyval).label + " = "+ get_var((yyvsp[0]).nome)->id + "+1;";
			}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 632 "sintatica.y" /* yacc.c:1646  */
    {
				if(!get_var((yyvsp[0]).nome)) yyerror(in_line() + "Variável " + (yyvsp[0]).nome +  "não existe");
				if(get_var((yyvsp[0]).nome)->type == "bool" || get_var((yyvsp[0]).nome)->type == "char") yyerror(in_line () + "Operação só permitida com float e int");
				(yyval).label = create_temp_names();
				(yyval).var_tipo = get_var((yyvsp[0]).nome)->type;
				set_var((yyval).var_tipo, "temp", (yyval).valor, (yyval).label);
				(yyval).traducao = "\t" + (yyval).label + " = "+ get_var((yyvsp[0]).nome)->id + "-1;";
			}
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 641 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 645 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 649 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 653 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 659 "sintatica.y" /* yacc.c:1646  */
    {
				FUN* function = get_function((yyvsp[-3]).nome);

				if(!function){
					yyerror(in_line() + " A função requisitada não existe ou está declarada abaixo do escopo.");
				}

				set_vars_functions(function);

				(yyval).var_tipo = function->type_return;
				(yyval).label = function->name_return;
				
				if(params.size() < function->map_parameters.size()){
					yyerror(in_line() + " Passagem de parâmetros menor do que o esperado");
				}

				if(params.size() > function->map_parameters.size()){
					yyerror(in_line() + " Passagem de parâmetros maior do que o esperado");
				}

				int j = params.size()-1;

				if((yyval).var_tipo == "none"){
					for(int i=0; i<params.size(); i++){
						ATR passagem;
						ATR parametro;

						passagem.label = params[j].id;
						passagem.var_tipo = params[j].type;
						passagem.nome = params[j].name;
						parametro.label = function->map_parameters[i].id;
						parametro.var_tipo = function->map_parameters[i].type;

						if(!get_var(passagem.nome)) (yyval).traducao += "\n\t" + passagem.label + " = " + params[j].value + ";\n";
						
						implicit_return(&parametro, &passagem);

						(yyval).traducao += passagem.traducao;
						(yyval).traducao += "\n\t" + parametro.label + " = " + passagem.label + ";\n";
						j--;
					}
				} else{
					for(int i=0; i<params.size(); i++){
						ATR passagem;
						ATR parametro;

						passagem.label = params[j].id;
						passagem.var_tipo = params[j].type;
						passagem.nome = params[j].name;
						parametro.label = function->map_parameters[i].id;
						parametro.var_tipo = function->map_parameters[i].type;

						if(!get_var(passagem.nome)) (yyval).traducao += "\n\t" + passagem.label + " = " + params[j].value + ";\n";
						
						implicit_return(&parametro, &passagem);

						(yyval).traducao += passagem.traducao;
						(yyval).traducao += "\n\t" + parametro.label + " = " + passagem.label + ";\n";
						j--;
					}
				}

				params.clear();
				
				(yyval).traducao += function->body;
			}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 728 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				VAR temp;
				temp.value = (yyvsp[0]).valor;
				temp.type = (yyvsp[0]).var_tipo;
				temp.id = (yyvsp[0]).label;
				temp.name = (yyvsp[0]).nome;
				params.push_back(temp);
			}
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 738 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-2]).traducao;
				VAR temp;
				temp.value = (yyvsp[-2]).valor;
				temp.type = (yyvsp[-2]).var_tipo;
				temp.id = (yyvsp[-2]).label;
				temp.name = (yyvsp[-2]).nome;
				params.push_back(temp);
			}
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 751 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 757 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_temp_names();
				(yyval).op = (yyvsp[-1]).op;
				(yyval).var_tipo = "bool";
				(yyval).traducao = (yyvsp[-2]).traducao + "\n" + (yyvsp[0]).traducao + "\n";
				implicit_cast(&(yyvsp[-2]), &(yyvsp[0]), &(yyval));
				set_var(format_boolean(&(yyval)), "temp", (yyval).valor, (yyval).label);
				(yyval).traducao += "\t" + (yyval).label + " = " + (yyvsp[-2]).label + (yyvsp[-1]).op + (yyvsp[0]).label + ";\n";
				(yyval).valor = (yyvsp[-2]).valor + (yyvsp[-1]).op + (yyvsp[0]).valor;
			}
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 770 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).var_tipo != "bool") yyerror(in_line () + "A condição do While só permite booleano como retorno");
				string l_end = create_loop_names();
				(yyval).traducao = "\t" + (yyvsp[-4]).label + ":" + "\n" + (yyvsp[-2]).traducao + "\n\tif(!" + (yyvsp[-2]).label + ") goto " + l_end + ";\n" + (yyvsp[0]).traducao + "\tgoto "+ (yyvsp[-4]).label + ";\n\t" + l_end + ":\n\t";
			}
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 776 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).var_tipo != "bool") yyerror(in_line () + "A condição do While só permite booleano como retorno");
				(yyval).traducao = "\t" + (yyvsp[-5]).label + ":" + "\n" + (yyvsp[-4]).traducao + (yyvsp[-1]).traducao + "\tif(" + (yyvsp[-1]).label + ") goto " + (yyvsp[-5]).label + ";\n";
				pilha.pop();
			}
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 784 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).var_tipo != "bool") yyerror(in_line () + "A condição do Until só permite booleano como retorno");
				string l_end = create_loop_names();
				(yyval).traducao = "\t" + (yyvsp[-4]).label + ":" + "\n" + (yyvsp[-2]).traducao + "\n\tif(" + (yyvsp[-2]).label + ") goto " + l_end + ";\n" + (yyvsp[0]).traducao + "\tgoto "+ (yyvsp[-4]).label + ";\n\t" + l_end + ":\n\t";
			}
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 792 "sintatica.y" /* yacc.c:1646  */
    {
				string l_end = create_loop_names();
				if((yyvsp[-4]).traducao == ""){
					(yyval).traducao = (yyvsp[-6]).traducao + "\n\t" + (yyvsp[-8]).label + ":\n\t" + (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "goto " + (yyvsp[-8]).label + ";\n\t" + l_end + ":\n\t";
				}else{
					(yyval).traducao = (yyvsp[-6]).traducao + "\n\t" + (yyvsp[-8]).label + ":\n\t" + (yyvsp[-4]).traducao + "\tif(!" + (yyvsp[-4]).label + ") goto " + l_end + ";\n" + (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tgoto " + (yyvsp[-8]).label + ";\n\t" + l_end + ":\n\t";
				}
			}
#line 2445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 803 "sintatica.y" /* yacc.c:1646  */
    {
				VECTORS* temp = get_vector((yyvsp[-4]).nome);
				
				if(!temp){
					temp = get_matrix((yyvsp[-4]).nome);
				}

				if(!temp) yyerror(in_line() + "Estrutura não existe");

				string control = create_temp_names();
				string total_loop = create_temp_names();

				(yyvsp[-2]).label = create_temp_names();

				set_var("int", "", "", control);
				set_var("int", "", "", total_loop);
				set_var(temp->type, (yyvsp[-2]).nome, "", (yyvsp[-2]).label);

				(yyval).traducao = "\n\t" + total_loop + " = " + temp->row + " + " + temp->column + ";\n";
				(yyval).traducao += (yyvsp[-6]).traducao + "\n\t" + control + " = " + "0;\n\tstart_foreach:\n\t" + (yyvsp[-2]).label + " = " + temp->id + '[' + control
				+ "];\n\t" + control + " = " + control + " + 1;\n\t" + "if(" + (yyvsp[-2]).label + " != " + (yyvsp[-6]).label + ") goto middle_foreach;\n\t" 
				+ "\n" + (yyvsp[0]).traducao + "\n\tmiddle_foreach:\n\t" + "if(" + control + "<" + total_loop + ") goto start_foreach;\n";
			}
#line 2473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 827 "sintatica.y" /* yacc.c:1646  */
    {
				VECTORS* temp = get_vector((yyvsp[-5]).nome);

				if(!temp) yyerror(in_line() + "Estrutura não existe");

				string control = create_temp_names();
				string total_loop = create_temp_names();

				(yyvsp[-2]).label = create_temp_names();

				set_var("int", "", "", control);
				set_var("int", "", "", total_loop);
				set_var(temp->type, (yyvsp[-2]).nome, "", (yyvsp[-2]).label);

				(yyval).traducao = "\n\t" + total_loop + " = " + temp->row + " + " + temp->column + ";\n";
				(yyval).traducao += (yyvsp[-7]).traducao + "\n\t" + control + " = " + "0;\n\tstart_foreach:\n\t" + (yyvsp[-2]).label + " = " + temp->id + '[' + control
				+ "];\n\t" + control + " = " + control + " + 1;\n\t" + "if(" + (yyvsp[-2]).label + " == " + (yyvsp[-7]).label + ") goto middle_foreach;\n\t" 
				+ "\n" + (yyvsp[0]).traducao + "\n\tmiddle_foreach:\n\t" + "if(" + control + "<" + total_loop + ") goto start_foreach;\n";
			}
#line 2497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 849 "sintatica.y" /* yacc.c:1646  */
    {
				if(search_var((yyvsp[0]).nome)){
					(yyval).traducao = (yyvsp[0]).traducao;
					explicit_cast(&(yyvsp[0]), (yyvsp[-1]).cast);
					(yyval).traducao += (yyvsp[0]).traducao;
					(yyval).label = (yyvsp[0]).label;
					(yyval).var_tipo = (yyvsp[0]).var_tipo;
				}else{
					(yyval).traducao = (yyvsp[0]).traducao;
					explicit_cast(&(yyvsp[0]), (yyvsp[-1]).cast);
					(yyval).traducao += (yyvsp[0]).traducao;
					(yyval).label = (yyvsp[0]).label;
					(yyval).var_tipo = (yyvsp[0]).var_tipo;
				}
			}
#line 2517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 867 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_jump_names();
				(yyval).traducao = (yyvsp[-2]).traducao + "\tif(!" + (yyvsp[-2]).label + ") goto " + (yyval).label + ";\n" + (yyvsp[0]).traducao + "\n\t" + "goto global_end;\n\t" + (yyval).label + ":\n";
			}
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 872 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_jump_names();
				(yyval).traducao = (yyvsp[-3]).traducao + "\tif(!" + (yyvsp[-3]).label + ") goto " + (yyval).label + ";\n" + (yyvsp[-1]).traducao + "\n\t" + "goto global_end;\n\t" + (yyval).label + ":\n" + (yyvsp[0]).traducao + "\n\t" + "global_end:\n";
			}
#line 2535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 877 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_jump_names();
				(yyval).traducao = (yyvsp[-3]).traducao + "\tif(!" + (yyvsp[-3]).label + ") goto " + (yyvsp[0]).label + ";\n" + (yyvsp[-1]).traducao + "\tgoto " + (yyval).label + ";\n\t" + (yyvsp[0]).label + ":\n" + (yyvsp[0]).traducao + "\n\t" + "goto global_end;\n\t" + (yyval).label + ":\n\t" + "global_end:\n";
			}
#line 2544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 884 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).label = create_jump_names();
					(yyval).traducao = (yyvsp[-3]).traducao + "\tif(!" + (yyvsp[-3]).label + ") goto " + (yyval).label + ";\n" + (yyvsp[-1]).traducao + "\t" + "goto global_end;\n\t" + (yyval).label + ":\n" + (yyvsp[0]).traducao;
				}
#line 2553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 889 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).label = create_jump_names();
					(yyval).traducao = (yyvsp[-3]).traducao + "\tif(!" + (yyvsp[-3]).label + ") goto " + (yyvsp[0]).label + ";\n" + (yyvsp[-1]).traducao + "\tgoto " + (yyval).label + ";\n\t" + (yyvsp[0]).label + ":\n" + (yyvsp[0]).traducao + "\n\t" + "goto global_end;\n\t" + (yyval).label + ":";
				}
#line 2562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 894 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).label = create_jump_names();
					(yyval).traducao = (yyvsp[-2]).traducao + "\tif(!" + (yyvsp[-2]).label + ") goto " + (yyval).label + ";\n" + (yyvsp[0]).traducao + "\n\t" + (yyval).label + ":\n";
				}
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 901 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).label = create_jump_names();
					(yyval).traducao = (yyvsp[0]).traducao;
				}
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 908 "sintatica.y" /* yacc.c:1646  */
    {
			set_var((yyvsp[-4]).var_tipo, "", (yyvsp[-4]).label, (yyvsp[-6]).label);
			(yyval).label = create_switch_names();
			(yyval).traducao = "\n" + (yyvsp[-4]).traducao + "\n\t" + (yyvsp[-4]).var_tipo + " " + (yyvsp[-6]).label + ";\n\t" + (yyvsp[-6]).label + " = " + (yyvsp[-4]).label + ";\n\t" + (yyvsp[-1]).traducao + "\n\t" + (yyval).label + ":\n";
			pilha.pop();
		}
#line 2591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 915 "sintatica.y" /* yacc.c:1646  */
    {
			//$$.traducao = $6.traducao + $3.traducao;
			//pilha.pop();
		}
#line 2600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 922 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[-1]).traducao + "\n" + (yyvsp[0]).traducao;
		}
#line 2608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 929 "sintatica.y" /* yacc.c:1646  */
    {
				int swt = switches;
				swt--;
				(yyval).label = create_jump_names();
				(yyval).traducao = "\n" + (yyvsp[-2]).traducao + "\n\tif(!switch" + to_string(swt) + " == " + (yyvsp[-2]).label + ")\n\t" + (yyvsp[0]).traducao; 
				(yyvsp[-2]).traducao = " ";
 			}
#line 2620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 937 "sintatica.y" /* yacc.c:1646  */
    {
				//$$.label = create_jump_names();
				int swt = switches;
				swt--;
				(yyval).label = create_jump_names();
				(yyval).traducao = "\n" + (yyvsp[-4]).traducao + "\n\tif(!switch" + to_string(swt) + " == " + (yyvsp[-4]).label + ")\n\t"; 
			}
#line 2632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 947 "sintatica.y" /* yacc.c:1646  */
    {
				VAR* temp = get_var((yyvsp[0]).nome);

				if(!temp){
					yyerror(in_line() + "Variável " + (yyvsp[0]).nome +  " não existe");
				}else{
					(yyval).var_tipo = temp->type;
					(yyval).label = temp->id;
				}
			}
#line 2647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 958 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
				format_variable(&(yyval));
				set_var((yyvsp[0]).var_tipo, "temp", (yyvsp[0]).valor, (yyvsp[0]).label);
			}
#line 2657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 964 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
				format_variable(&(yyval));
				set_var((yyvsp[0]).var_tipo, "temp", (yyvsp[0]).valor, (yyvsp[0]).label);
			}
#line 2667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 970 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
				format_variable(&(yyval));
				set_var((yyvsp[0]).var_tipo, "temp", (yyvsp[0]).valor, (yyvsp[0]).label);
			}
#line 2677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 976 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
				format_variable(&(yyval));
				set_var((yyvsp[0]).var_tipo, "temp", (yyvsp[0]).valor, (yyvsp[0]).label);
			}
#line 2687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 982 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
				format_variable(&(yyval));
				set_var((yyvsp[0]).var_tipo, "temp", (yyvsp[0]).valor, (yyvsp[0]).label);
			}
#line 2697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 988 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
				format_variable(&(yyval));
				set_var((yyvsp[0]).var_tipo, "temp", (yyvsp[0]).valor, (yyvsp[0]).label);
			}
#line 2707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1016 "sintatica.y" /* yacc.c:1646  */
    {
				if(!search_var((yyvsp[-1]).nome)){
					yyerror(in_line () + "Variável não existe");
				}

				VAR* temp = get_var((yyvsp[-1]).nome);

				if(temp->type != "string"){
					(yyval).label = create_temp_names();
					(yyval).var_tipo = temp->type;
					(yyval).traducao = "\t\"cin >> " + temp->id + "\";\n";
					(yyval).traducao += "\n\t" + (yyval).label + " = " + "(" + temp->type + ")";
				} else{
					string word = create_temp_names();
					string lenght = create_temp_names();
					
				}
			}
#line 2730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1036 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "\tcout" + (yyvsp[-1]).traducao + " << endl;\n";
			}
#line 2738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1042 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = " << " + (yyvsp[0]).traducao;
		}
#line 2746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1046 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = " << " + (yyvsp[-2]).traducao + (yyvsp[0]).traducao;
		}
#line 2754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1053 "sintatica.y" /* yacc.c:1646  */
    {
			if(!get_var((yyval).nome)){
				yyerror(in_line() + "Variável " + (yyvsp[0]).nome +  " não existe");
			}else{
				(yyval).traducao = get_var((yyval).nome)->id;
			}
		}
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1061 "sintatica.y" /* yacc.c:1646  */
    {
			if(!get_vector((yyvsp[-3]).nome)) yyerror(in_line () + "Vetor não existe");

			VECTORS* temp = get_vector((yyvsp[-3]).nome);
		}
#line 2776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1067 "sintatica.y" /* yacc.c:1646  */
    {

		}
#line 2784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1071 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[0]).valor;
		}
#line 2792 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2796 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1076 "sintatica.y" /* yacc.c:1906  */


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	FUN function;
	function.next = NULL;
	pilha.push(function);
	first_exestack = &pilha.top();

	yyparse();

	pilha.pop();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}
