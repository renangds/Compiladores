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
	#include <map>
	#include <stdlib.h>
	#include <errno.h>	

	#define MAX_TABLE_SIZE 100
	#define YYSTYPE atributos

	using namespace std;

	void yyerror(string MSG);
	void i_casting(string v1, string v2, string op, struct atributos* $$);
	void e_casting(struct atributos* a1);
	void print_matrix();
	void insert_variable(string tipo, string id, string value);	
	void change_type_variable(string id, string type);
	string find_type(string id);
	bool find_variable(string id);
	string to_string(int num);
	string create_var_names();
	string create_temp_names();

	/*
		Estrutura a ser adotada na sprint 2

		Lembrete a ser implementado: A estrutura das funções serão colocadas em uma pilha,
		onde cada instância deverá ter um ponteiro para as demais instâncias das funções
		criadas.

		struct function{
			string tabf[MAX_TABLE_SIZE][3];
			vector<string>atb;
			struct* function;
		};
	*/

	struct atributos
	{
		string label;
		string traducao;
		string t_var;
		string id_var;
		string cast;
	};

	string tabela_v[MAX_TABLE_SIZE][3];
	static int vars = 0;
	static int temps = 0;
	static int total_var = 0;

	void i_casting(string v1, string v2, string op, struct atributos* $$){
		string a1 = find_type(v1);
		string a2 = find_type(v2);

		if(op == "+" || op == "-" || op == "*" || op == "/" || op == "%"){
			if(a1 == "bool" || a2 == "bool"){
				yyerror("Operação não suporta tipo booleano");
			} else if ((a1 == "int" || a2 == "float") || (a1 == "float" || a2 == "int")){
				$$->t_var = "float";
			}
		} else if (op == "==" || op == "!=" || op == ">" || op == "<" || op == "<=" || op == ">="){
			if((a1 == "bool" && a2 != "bool") || (a1 != "bool" && a2 == "bool")){
				yyerror("Operação não permitida");
			}
		}
	}

	void error_module(struct atributos* a1, struct atributos* a2){
		if(a1->t_var == "float" || a1->t_var == "float"){
			yyerror("Operação não infere os tipos float!");
		}
	}

	void print_matrix(){
		cout << "Tipo" << "\t" << "Id" << "\t" << "Valor" << endl;

		for(int i=0; i<total_var; i++){
			cout << tabela_v[i][0] << "\t" << tabela_v[i][1] << "\t" << tabela_v[i][2] << endl;
		}
	}

	void insert_variable(string tipo, string id, string value){
		tabela_v[total_var][0] = tipo;
		tabela_v[total_var][1] = id;
		tabela_v[total_var][2] = value;
		total_var++;
	}

	string find_type(string id){
		for(int i=0; i<total_var; i++){
			if(id == tabela_v[i][1]){
				return tabela_v[i][0];
			}
		}
		return NULL;
	}

	string get_value_variable(string id){
		for(int i=0; i<total_var; i++){
			if(id == tabela_v[i][1]){
				return tabela_v[i][2];
			}
		}
	}

	struct atributos* get_variable(string id){
		struct atributos* temp = (struct atributos*)malloc(sizeof(struct atributos));

		if(!temp){
			exit(0);
		}

		for(int i=0; i<total_var; i++){
			if(id == tabela_v[i][1]){
				temp->label = id;
				temp->t_var = tabela_v[i][0];
				temp->traducao = tabela_v[i][2];
				return temp;
			}
		}
		return NULL;
	}

	bool find_variable(string id){
		for(int i=0; i<total_var; i++){
			if(id == tabela_v[i][1]){
				return true;
			}
		}
		return false;
	}

	void change_type_variable(string id, string type){
		int i = 0;
		while(i<total_var){
			if(id == tabela_v[i][1]){
				tabela_v[i][0] = type;
				break;
			}
		}
	}

	void change_value_variable(string id, string var, string value){
		struct atributos* temp = get_variable(var);

		int i = 0;
		while(i<total_var){
			if(id == tabela_v[i][1]){
				tabela_v[i][2] = value;
				break;
			}
		}
	}

	string to_string(int num){
		ostringstream temp;
		temp << num;
		return temp.str();
	}

	string create_var_names(){
		string var = "var_"+to_string(vars);
		vars++;
		return var;
	}

	string create_temp_names(){
		string temp = "temp"+to_string(temps);
		temps++;
		return temp;
	}

	int yylex(void);
	void yyerror(string);

#line 245 "y.tab.c" /* yacc.c:339  */

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
    TK_TYPE_CHAR = 258,
    TK_TYPE_FLOAT = 259,
    TK_TYPE_BOOL = 260,
    TK_TYPE_INT = 261,
    TK_TYPE_VAR = 262,
    TK_NUM = 263,
    TK_FLOAT = 264,
    TK_DOUBLE = 265,
    TK_SHORT = 266,
    TK_CHAR = 267,
    TK_VAR = 268,
    STRING = 269,
    TK_INT = 270,
    TK_BOOL = 271,
    TK_MAIN = 272,
    TK_ID = 273,
    TK_FIM = 274,
    TK_ERROR = 275,
    TK_BEGIN = 276,
    TK_END = 277,
    TK_FUNCTIONS = 278,
    FOR = 279,
    WHILE = 280,
    DO = 281,
    CONTINUE = 282,
    BREAK = 283,
    TK_JUMP = 284,
    TK_TO = 285,
    IF = 286,
    ELSE = 287,
    ELIF = 288,
    SWITCH = 289,
    UNTIL = 290,
    CASE = 291,
    PARAMS = 292,
    SUPER = 293,
    VAR = 294,
    TK_SUM = 295,
    AND = 296,
    OR = 297,
    ORI = 298,
    NAND = 299,
    TK_CAST = 300
  };
#endif
/* Tokens.  */
#define TK_TYPE_CHAR 258
#define TK_TYPE_FLOAT 259
#define TK_TYPE_BOOL 260
#define TK_TYPE_INT 261
#define TK_TYPE_VAR 262
#define TK_NUM 263
#define TK_FLOAT 264
#define TK_DOUBLE 265
#define TK_SHORT 266
#define TK_CHAR 267
#define TK_VAR 268
#define STRING 269
#define TK_INT 270
#define TK_BOOL 271
#define TK_MAIN 272
#define TK_ID 273
#define TK_FIM 274
#define TK_ERROR 275
#define TK_BEGIN 276
#define TK_END 277
#define TK_FUNCTIONS 278
#define FOR 279
#define WHILE 280
#define DO 281
#define CONTINUE 282
#define BREAK 283
#define TK_JUMP 284
#define TK_TO 285
#define IF 286
#define ELSE 287
#define ELIF 288
#define SWITCH 289
#define UNTIL 290
#define CASE 291
#define PARAMS 292
#define SUPER 293
#define VAR 294
#define TK_SUM 295
#define AND 296
#define OR 297
#define ORI 298
#define NAND 299
#define TK_CAST 300

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

#line 386 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  36
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  75

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      59,    60,    57,    55,     2,    56,     2,    58,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    61,
      51,    46,    52,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    47,    48,    49,    50,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   206,   206,   214,   220,   224,   227,   234,   241,   247,
     253,   259,   262,   266,   273,   279,   285,   290,   295,   300,
     305,   310,   315,   320,   325,   330,   335,   339,   343,   349,
     361,   367,   371,   375,   379,   383,   387
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_TYPE_CHAR", "TK_TYPE_FLOAT",
  "TK_TYPE_BOOL", "TK_TYPE_INT", "TK_TYPE_VAR", "TK_NUM", "TK_FLOAT",
  "TK_DOUBLE", "TK_SHORT", "TK_CHAR", "TK_VAR", "STRING", "TK_INT",
  "TK_BOOL", "TK_MAIN", "TK_ID", "TK_FIM", "TK_ERROR", "TK_BEGIN",
  "TK_END", "TK_FUNCTIONS", "FOR", "WHILE", "DO", "CONTINUE", "BREAK",
  "TK_JUMP", "TK_TO", "IF", "ELSE", "ELIF", "SWITCH", "UNTIL", "CASE",
  "PARAMS", "SUPER", "VAR", "TK_SUM", "AND", "OR", "ORI", "NAND",
  "TK_CAST", "'='", "\"||\"", "\"&&\"", "\"==\"", "\"!=\"", "'<'", "'>'",
  "\">=\"", "\"<=\"", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "';'",
  "$accept", "S", "BLOCO", "COMANDOS", "COMANDO", "E", "C", "V", "T", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,    61,   301,   302,   303,
     304,    60,    62,   305,   306,    43,    45,    42,    47,    40,
      41,    59
};
# endif

#define YYPACT_NINF -51

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -18,    -6,    16,   -40,   -51,   -36,     6,    -3,   -51,    14,
      17,    20,    22,    23,   -51,   -51,   -51,   -51,   -51,   -51,
      29,    21,    26,    -3,    49,   -51,   -51,    21,    21,    21,
      21,    21,   -51,   -51,   127,   -51,   -51,    21,    21,    21,
      21,    21,    21,    21,    21,     5,    13,    21,    21,   -51,
      62,    75,    88,   101,   114,   -51,   142,   152,   160,   160,
     -12,   -12,   -12,   -12,   -51,   -50,   -51,   -50,   -51,   -51,
     -51,   -51,   -51,   -51,   -51
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     5,     2,     0,
       0,     0,     0,     0,    33,    35,    36,    32,    34,    31,
       0,     0,     0,     5,     0,    28,    27,     0,     0,     0,
       0,     0,    30,    29,     0,     3,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,    12,    26,    24,    23,    25,
      20,    19,    21,    22,    17,    13,    18,    14,    15,    16,
       9,     7,     8,     6,    10
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,    28,   -51,    46,   -51,   -51,   -51
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     8,    22,    23,    24,    25,    33,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       9,    10,    11,    12,    13,     1,    14,    47,    48,    15,
      16,     3,    17,    18,    14,    19,     4,    15,    16,     5,
      17,    18,    14,    19,     6,    15,    16,     7,    17,    18,
      14,    19,    27,    15,    16,    28,    17,    18,    29,    19,
      30,    31,    20,    45,    46,    47,    48,    32,    35,     0,
      20,    36,     0,     0,     0,     0,    21,     0,    20,     0,
      64,     0,     0,     0,    21,     0,    20,    34,     0,    66,
       0,     0,    21,    50,    51,    52,    53,    54,     0,     0,
      21,     0,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    65,    67,    68,    69,    37,    38,     0,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    37,    38,
      49,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    37,    38,    70,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    37,    38,    71,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    37,    38,    72,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      37,    38,    73,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    37,    38,    74,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    55,    37,    38,
       0,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    41,    42,    43,    44,    45,    46,    47,    48
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     6,     7,    23,     9,    57,    58,    12,
      13,    17,    15,    16,     9,    18,     0,    12,    13,    59,
      15,    16,     9,    18,    60,    12,    13,    21,    15,    16,
       9,    18,    18,    12,    13,    18,    15,    16,    18,    18,
      18,    18,    45,    55,    56,    57,    58,    18,    22,    -1,
      45,    23,    -1,    -1,    -1,    -1,    59,    -1,    45,    -1,
      55,    -1,    -1,    -1,    59,    -1,    45,    21,    -1,    56,
      -1,    -1,    59,    27,    28,    29,    30,    31,    -1,    -1,
      59,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    46,    47,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    46,    47,
      61,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    46,    47,    61,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    46,    47,    61,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    46,    47,    61,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      46,    47,    61,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    46,    47,    61,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,    46,    47,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    51,    52,    53,    54,    55,    56,    57,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    63,    17,     0,    59,    60,    21,    64,     3,
       4,     5,     6,     7,     9,    12,    13,    15,    16,    18,
      45,    59,    65,    66,    67,    68,    70,    18,    18,    18,
      18,    18,    18,    69,    67,    22,    65,    46,    47,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    61,
      67,    67,    67,    67,    67,    60,    67,    67,    67,    67,
      67,    67,    67,    67,    55,    67,    56,    67,    67,    67,
      61,    61,    61,    61,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    65,    65,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      69,    70,    70,    70,    70,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     2,     0,     4,     4,     4,     4,
       4,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1
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
#line 207 "sintatica.y" /* yacc.c:1646  */
    {
				cout << "Conheça a Soft, a linguagem sopa de macaco, uma delícia!" << endl;
				cout << "Begin:" << endl << (yyvsp[0]).traducao << "End" << endl;
				print_matrix();
			}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 215 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 221 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao + "\n" + (yyvsp[0]).traducao;
			}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 228 "sintatica.y" /* yacc.c:1646  */
    {
				if(find_variable((yyvsp[-2]).label)) yyerror("Variável já existe!");
				if((yyvsp[-1]).cast == "float") (yyvsp[-1]).t_var = "float";
				insert_variable((yyvsp[-1]).t_var, (yyvsp[-2]).label, (yyvsp[-1]).traducao); //Insere na tabela de símbolos
				(yyval).traducao = "\t" + (yyvsp[-1]).t_var + " " + (yyvsp[-2]).label + " = " + (yyvsp[-1]).traducao;
			}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 235 "sintatica.y" /* yacc.c:1646  */
    {
				if(find_variable((yyvsp[-2]).label)) yyerror("Variável já existe!");
				if((yyvsp[-1]).t_var == "int") (yyvsp[-1]).t_var = "float";
				insert_variable((yyvsp[-1]).t_var, (yyvsp[-2]).label, (yyvsp[-1]).traducao);
				(yyval).traducao = "\t" + (yyvsp[-1]).t_var + " " + (yyvsp[-2]).label + " = " + (yyvsp[-1]).traducao;
			}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 242 "sintatica.y" /* yacc.c:1646  */
    {
				if(find_variable((yyvsp[-2]).label)) yyerror("Variável já existe!");
				insert_variable((yyvsp[-1]).t_var, (yyvsp[-2]).label, (yyvsp[-1]).traducao);
				(yyval).traducao = "\t" + (yyvsp[-1]).t_var + " " + (yyvsp[-2]).label + " = " + (yyvsp[-1]).traducao;
			}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 248 "sintatica.y" /* yacc.c:1646  */
    {
				if(find_variable((yyvsp[-2]).label)) yyerror("Variável já existe!");
				insert_variable((yyvsp[-1]).t_var, (yyvsp[-2]).label, (yyvsp[-1]).traducao);
				(yyval).traducao = "\t" + (yyvsp[-1]).t_var + " " + (yyvsp[-2]).label + " = " + (yyvsp[-1]).traducao;
			}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 254 "sintatica.y" /* yacc.c:1646  */
    {
				if(find_variable((yyvsp[-2]).label)) yyerror("Variável já existe!");
				insert_variable((yyvsp[-1]).t_var, (yyvsp[-2]).label, (yyvsp[-1]).traducao);
				(yyval).traducao = "\t" + (yyvsp[-1]).t_var + " " + (yyvsp[-2]).label + " = " + (yyvsp[-1]).traducao;
			}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 263 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 267 "sintatica.y" /* yacc.c:1646  */
    {
				if(!find_variable((yyvsp[-2]).label) || !find_variable((yyvsp[0]).label)) yyerror("Variável não existe!");
				(yyval).label = create_temp_names();
				(yyval).traducao = (yyval).label + " = " + (yyvsp[-2]).label + " + " + (yyvsp[0]).label + "\n";
				i_casting((yyvsp[-2]).label, (yyvsp[0]).label, "+", &(yyval));
			}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 274 "sintatica.y" /* yacc.c:1646  */
    {
				if(!find_variable((yyvsp[-2]).label) || !find_variable((yyvsp[0]).label)) yyerror("Variável não existe!");
				(yyval).label = create_temp_names();
				i_casting((yyvsp[-2]).label, (yyvsp[0]).label, "-", &(yyval));
			}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 280 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_temp_names();
				if(!find_variable((yyvsp[-2]).label) || !find_variable((yyvsp[0]).label)) yyerror("Variável não existe!");
				i_casting((yyvsp[-2]).label, (yyvsp[0]).label, "*", &(yyval));
			}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 286 "sintatica.y" /* yacc.c:1646  */
    {
				if(!find_variable((yyvsp[-2]).label) || !find_variable((yyvsp[0]).label)) yyerror("Variável não existe!");
				(yyval).label = create_temp_names();
			}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 291 "sintatica.y" /* yacc.c:1646  */
    {
				if(!find_variable((yyvsp[-2]).label) || !find_variable((yyvsp[0]).label)) yyerror("Variável não existe!");
				(yyval).label = create_temp_names();
			}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 296 "sintatica.y" /* yacc.c:1646  */
    {
				if(!find_variable((yyvsp[-2]).label) || !find_variable((yyvsp[0]).label)) yyerror("Variável não existe!");
				(yyval).label = create_temp_names();
			}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 301 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_temp_names();
				i_casting((yyvsp[-2]).label, (yyvsp[0]).label, ">", &(yyval));
			}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 306 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_temp_names();
				i_casting((yyvsp[-2]).label, (yyvsp[0]).label, "<", &(yyval));
			}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 311 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_temp_names();
				i_casting((yyvsp[-2]).label, (yyvsp[0]).label, ">=", &(yyval));
			}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 316 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_temp_names();
				i_casting((yyvsp[-2]).label, (yyvsp[0]).label, "<=", &(yyval));
			}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 321 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_temp_names();
				i_casting((yyvsp[-2]).label, (yyvsp[0]).label, "==", &(yyval));
			}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 326 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_temp_names();
				i_casting((yyvsp[-2]).label, (yyvsp[0]).label, "||", &(yyval));
			}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 331 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_temp_names();
				i_casting((yyvsp[-2]).label, (yyvsp[0]).label, "!=", &(yyval));
			}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 336 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[-2]);
			}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 340 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 344 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 350 "sintatica.y" /* yacc.c:1646  */
    {
				if(!find_variable((yyvsp[0]).label)) yyerror("Variável não existe!");
				if((yyvsp[-1]).cast == "(float)"){
					(yyval).cast = "float";
				}else{
					(yyval).cast = "int";
				}
				(yyval).traducao = get_value_variable((yyvsp[0]).label);
			}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 362 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 368 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 372 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 376 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 380 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 384 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 388 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1841 "y.tab.c" /* yacc.c:1646  */
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
#line 393 "sintatica.y" /* yacc.c:1906  */


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] ) 
{
	yyparse();
	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}
