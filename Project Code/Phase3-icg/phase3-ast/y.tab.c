/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_If = 258,
     T_Print = 259,
     T_Do = 260,
     T_While = 261,
     T_Switch = 262,
     T_Else = 263,
     T_Case = 264,
     T_Assignop = 265,
     T_Pluseq = 266,
     T_Shebang = 267,
     T_Minuseq = 268,
     T_Exp = 269,
     T_String = 270,
     T_True = 271,
     T_False = 272,
     T_Use = 273,
     T_Arr = 274,
     T_Id = 275,
     T_Int = 276,
     T_Float = 277,
     T_Double = 278,
     T_Inc = 279,
     T_Dec = 280,
     T_Lesseq = 281,
     T_Greteq = 282,
     T_Or = 283,
     T_And = 284,
     T_Not = 285,
     T_Eq = 286,
     T_Noteq = 287
   };
#endif
/* Tokens.  */
#define T_If 258
#define T_Print 259
#define T_Do 260
#define T_While 261
#define T_Switch 262
#define T_Else 263
#define T_Case 264
#define T_Assignop 265
#define T_Pluseq 266
#define T_Shebang 267
#define T_Minuseq 268
#define T_Exp 269
#define T_String 270
#define T_True 271
#define T_False 272
#define T_Use 273
#define T_Arr 274
#define T_Id 275
#define T_Int 276
#define T_Float 277
#define T_Double 278
#define T_Inc 279
#define T_Dec 280
#define T_Lesseq 281
#define T_Greteq 282
#define T_Or 283
#define T_And 284
#define T_Not 285
#define T_Eq 286
#define T_Noteq 287




/* Copy the first part of user declarations.  */
#line 1 "yacc.y"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdarg.h>
#include "lex.yy.c"
void yyerror(const char*);
int yylex();
void print_sym_tab();
void update_sym_tab(char* typ, char* nam, int line, int scope);
int scope[100];
int scope_ctr;
int scope_ind;
char typ[10]="none";

typedef struct AST{
	char lexeme[100];
	int NumChild;
	struct AST **child;
}AST_node;

struct AST* make_if_node(char* root, AST_node* child1, AST_node* child2, AST_node* child3);
struct AST* make_switch_node(char* root, AST_node* child1, AST_node* child2, AST_node* child3,AST_node* child4);
struct AST * make_node(char*, AST_node*, AST_node*);
struct AST* make_leaf(char* root);
void AST_print(struct AST *t);
extern FILE* yyin;
extern int yylineno;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 38 "yacc.y"
{
	char var_type[100]; 
	char text[100]; 
	struct AST *node;
	}
/* Line 193 of yacc.c.  */
#line 196 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 221 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   220

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNRULES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    40,     2,     2,
      45,    46,    38,    36,    47,    37,    48,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
      34,    35,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    41,    50,
      51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    10,    21,    32,    37,    44,    51,
      60,    64,    68,    71,    72,    74,    76,    78,    83,    89,
      93,    97,    99,   101,   103,   107,   109,   111,   113,   115,
     119,   123,   127,   131,   134,   138,   140,   144,   146,   148,
     150,   154,   156,   158,   160,   164,   168,   172,   176,   180,
     184,   186,   188,   190,   194,   198,   200,   202,   206,   210,
     212,   216,   218,   220,   222,   226,   229,   232,   235,   238,
     242,   244,   246,   250,   255,   257,   259,   261,   266
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    12,    56,    -1,    60,    42,    56,    -1,
       5,    43,    56,    44,     6,    45,    66,    46,    42,    56,
      -1,    76,    56,     7,    45,    77,    46,    43,    78,    44,
      56,    -1,     4,    15,    42,    56,    -1,     4,    45,    15,
      46,    42,    56,    -1,     4,    45,    20,    46,    42,    56,
      -1,     3,    45,    66,    46,    43,    56,    44,    56,    -1,
      75,    42,    56,    -1,    58,    42,    56,    -1,     1,    56,
      -1,    -1,    21,    -1,    22,    -1,    23,    -1,    19,    35,
      45,    46,    -1,    19,    35,    45,    59,    46,    -1,    57,
      47,    59,    -1,    15,    47,    59,    -1,    57,    -1,    15,
      -1,    61,    -1,    61,    47,    62,    -1,    62,    -1,    20,
      -1,    64,    -1,    15,    -1,    20,    35,    71,    -1,    20,
      35,    15,    -1,    20,    35,    65,    -1,    20,    48,    20,
      -1,     1,    49,    -1,    66,    28,    67,    -1,    67,    -1,
      67,    29,    68,    -1,    68,    -1,    30,    -1,    69,    -1,
      45,    66,    46,    -1,    70,    -1,    16,    -1,    17,    -1,
      70,    34,    71,    -1,    70,    33,    71,    -1,    70,    50,
      71,    -1,    70,    51,    71,    -1,    70,    52,    71,    -1,
      70,    53,    71,    -1,    20,    -1,    57,    -1,    63,    -1,
      71,    36,    72,    -1,    71,    37,    72,    -1,    72,    -1,
      75,    -1,    72,    38,    73,    -1,    72,    39,    73,    -1,
      73,    -1,    74,    14,    73,    -1,    74,    -1,    20,    -1,
      57,    -1,    45,    71,    46,    -1,    20,    24,    -1,    20,
      25,    -1,    24,    20,    -1,    25,    20,    -1,    18,     7,
      42,    -1,    20,    -1,    57,    -1,     9,    79,    81,    -1,
      80,    43,    56,    44,    -1,    57,    -1,    20,    -1,    15,
      -1,     8,    43,    56,    44,    -1,    78,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    47,    47,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    63,    64,    65,    67,    68,    70,
      71,    72,    73,    76,    79,    80,    83,    84,    86,    89,
      90,    91,    94,    95,    97,    98,   101,   102,   105,   106,
     109,   110,   111,   112,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   127,   128,   129,   130,   132,   133,   134,
     136,   137,   139,   140,   141,   144,   145,   146,   147,   149,
     151,   152,   154,   156,   158,   159,   160,   162,   163
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_If", "T_Print", "T_Do", "T_While",
  "T_Switch", "T_Else", "T_Case", "T_Assignop", "T_Pluseq", "T_Shebang",
  "T_Minuseq", "T_Exp", "T_String", "T_True", "T_False", "T_Use", "T_Arr",
  "T_Id", "T_Int", "T_Float", "T_Double", "T_Inc", "T_Dec", "T_Lesseq",
  "T_Greteq", "T_Or", "T_And", "T_Not", "T_Eq", "T_Noteq", "'>'", "'<'",
  "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "\",\"", "';'", "'{'", "'}'",
  "'('", "')'", "','", "'.'", "'\\n'", "\"<=\"", "\">=\"", "\"!=\"",
  "\"==\"", "$accept", "P", "S", "num", "ArrayDecl", "Di", "Declaration",
  "L", "X", "str", "Assign_expr", "B", "cond", "C", "D", "M", "relexp",
  "E", "T", "F", "N", "ue", "us", "arg", "st", "Y", "K", "O", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    62,    60,    61,    43,    45,    42,    47,
      37,   288,    59,   123,   125,    40,    41,    44,    46,    10,
     289,   290,   291,   292
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    57,    58,    58,    59,
      59,    59,    59,    60,    61,    61,    62,    62,    63,    64,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    71,    71,    71,    71,    72,    72,    72,
      73,    73,    74,    74,    74,    75,    75,    75,    75,    76,
      77,    77,    78,    79,    80,    80,    80,    81,    81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,    10,    10,     4,     6,     6,     8,
       3,     3,     2,     0,     1,     1,     1,     4,     5,     3,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       3,     3,     3,     2,     3,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     3,     3,     1,     1,     3,     3,     1,
       3,     1,     1,     1,     3,     2,     2,     2,     2,     3,
       1,     1,     3,     4,     1,     1,     1,     4,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     2,     0,     0,    23,    25,    27,     0,     0,
       1,    12,     0,     0,     0,     0,     0,     0,    65,    66,
       0,    67,    68,     0,     0,     0,     0,     0,    28,    42,
      43,    50,    14,    15,    16,    38,     0,    51,    52,     0,
      35,    37,    39,    41,     0,     0,     0,     0,    69,     0,
       0,    30,    62,     0,    63,    31,    29,    55,    59,    61,
      56,    11,     3,    26,    24,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     0,     0,
       0,    22,    17,    21,     0,    33,     0,    62,     0,     0,
       0,     0,     0,     0,     0,    40,    34,     0,    36,    45,
      44,    46,    47,    48,    49,     0,     0,     0,     0,     0,
      18,    32,    64,    62,    53,    54,    57,    58,    60,    70,
      71,     0,     0,     7,     8,     0,    20,    19,     0,     0,
       0,     0,     9,     0,     0,     0,     0,    76,    75,    74,
       0,     0,     0,     4,     0,    78,    72,     0,     5,     0,
       0,     0,    73,    77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    12,    64,    13,    94,    14,    15,    16,    48,
      17,    65,    49,    50,    51,    52,    53,    66,    67,    68,
      69,    18,    19,   131,   145,   150,   151,   156
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -76
static const yytype_int16 yypact[] =
{
      -8,   141,     7,    49,   -30,    -6,   -25,    37,    20,    70,
      12,    72,   -76,    29,    54,    43,   -76,   -76,    61,   166,
     -76,   -76,   105,    68,   -12,    16,    82,   108,   -76,   -76,
      57,   -76,   -76,    49,    49,    86,    49,   148,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   105,   -76,   -76,   -23,
     135,   -76,   -76,   124,    49,   122,   136,   137,   -76,    -9,
     134,   -76,    51,    64,   -76,   -76,    79,    62,   -76,   174,
     -76,   -76,   -76,   154,   -76,   -76,   151,   -17,   105,   155,
     105,    64,    64,    64,    64,    64,    64,   -76,   158,   159,
     191,   152,   -76,   156,   160,   -76,   182,    94,    71,    25,
      25,    25,    25,    25,   117,   -76,   135,    16,   -76,    79,
      79,    79,    79,    79,    79,    49,    49,   162,   157,   157,
     -76,   -76,   -76,   -76,    62,    62,   -76,   -76,   -76,   -76,
     -76,   163,   161,   -76,   -76,   105,   -76,   -76,   165,    49,
      -4,   195,   -76,   168,   172,   167,    49,   -76,   -76,   -76,
     139,   169,    49,   -76,   170,   -76,   -76,    16,   -76,    16,
     171,   173,   -76,   -76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,    -3,   -21,   -76,    33,   -76,   -76,   179,   -76,
     -76,   -76,   -44,   138,   140,   -76,   -76,    48,    63,   -75,
     -76,   -20,   -76,   -76,    69,   -76,   -76,   -76
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -14
static const yytype_int16 yytable[] =
{
      21,    47,    77,    55,     1,    78,    91,    20,    56,    23,
      70,    78,    42,    43,    44,    22,    37,     3,    25,     4,
       5,     6,    57,    79,    78,    47,   126,   127,   128,   105,
      71,    72,    31,    75,     7,     8,     9,    92,    93,    24,
      10,    11,   143,    70,    26,   123,    42,    43,    44,   -13,
       3,    87,     4,     5,     6,    27,   -13,    47,    60,    47,
     -13,    70,    70,    70,    70,    70,    70,     7,     8,     9,
      63,    33,    61,    10,    11,    28,    29,    62,    42,    43,
      44,    10,    11,   130,    97,    42,    43,    44,    10,    11,
      35,   140,    32,   -13,    28,    29,    34,    93,    93,    96,
     101,   102,    63,    36,   132,    30,    73,    99,   100,    63,
      54,    98,   133,   134,    47,    99,   100,   122,    28,    29,
      38,    39,    40,   149,    58,    41,    42,    43,    44,   109,
     110,   111,   112,   113,   114,    45,   142,   129,    42,    43,
      44,   -13,     3,   153,     4,     5,     6,   154,   144,   158,
      46,   136,   137,    59,   160,    76,   161,    81,    82,     7,
       8,     9,   124,   125,    80,    10,    11,     3,    88,     4,
       5,     6,    91,   -13,    83,    84,    85,    86,    42,    43,
      44,    90,    89,    95,     7,     8,     9,   147,   103,    30,
      10,    11,   148,    42,    43,    44,   104,   117,   107,   118,
     115,   116,   121,   119,   144,   139,   120,   135,   141,   138,
     146,   152,   157,   159,    74,   162,   106,   163,     0,   155,
     108
};

static const yytype_int16 yycheck[] =
{
       3,    22,    46,    15,    12,    28,    15,     0,    20,    15,
      30,    28,    21,    22,    23,    45,    19,     1,    43,     3,
       4,     5,    25,    46,    28,    46,   101,   102,   103,    46,
      33,    34,    20,    36,    18,    19,    20,    46,    59,    45,
      24,    25,    46,    63,     7,    20,    21,    22,    23,     0,
       1,    54,     3,     4,     5,    35,     7,    78,     1,    80,
      44,    81,    82,    83,    84,    85,    86,    18,    19,    20,
      45,    42,    15,    24,    25,    24,    25,    20,    21,    22,
      23,    24,    25,   104,    20,    21,    22,    23,    24,    25,
      47,   135,    20,    44,    24,    25,    42,   118,   119,    48,
      38,    39,    45,    42,   107,    35,    20,    36,    37,    45,
      42,    63,   115,   116,   135,    36,    37,    46,    24,    25,
      15,    16,    17,   144,    42,    20,    21,    22,    23,    81,
      82,    83,    84,    85,    86,    30,   139,    20,    21,    22,
      23,     0,     1,   146,     3,     4,     5,     8,     9,   152,
      45,   118,   119,    45,   157,     7,   159,    33,    34,    18,
      19,    20,    99,   100,    29,    24,    25,     1,    46,     3,
       4,     5,    15,     7,    50,    51,    52,    53,    21,    22,
      23,    44,    46,    49,    18,    19,    20,    15,    14,    35,
      24,    25,    20,    21,    22,    23,    45,     6,    43,    47,
      42,    42,    20,    47,     9,    44,    46,    45,    43,    46,
      42,    44,    43,    43,    35,    44,    78,    44,    -1,   150,
      80
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    55,     1,     3,     4,     5,    18,    19,    20,
      24,    25,    56,    58,    60,    61,    62,    64,    75,    76,
       0,    56,    45,    15,    45,    43,     7,    35,    24,    25,
      35,    20,    20,    42,    42,    47,    42,    56,    15,    16,
      17,    20,    21,    22,    23,    30,    45,    57,    63,    66,
      67,    68,    69,    70,    42,    15,    20,    56,    42,    45,
       1,    15,    20,    45,    57,    65,    71,    72,    73,    74,
      75,    56,    56,    20,    62,    56,     7,    66,    28,    46,
      29,    33,    34,    50,    51,    52,    53,    56,    46,    46,
      44,    15,    46,    57,    59,    49,    48,    20,    71,    36,
      37,    38,    39,    14,    45,    46,    67,    43,    68,    71,
      71,    71,    71,    71,    71,    42,    42,     6,    47,    47,
      46,    20,    46,    20,    72,    72,    73,    73,    73,    20,
      57,    77,    56,    56,    56,    45,    59,    59,    46,    44,
      66,    43,    56,    46,     9,    78,    42,    15,    20,    57,
      79,    80,    44,    56,     8,    78,    81,    43,    56,    43,
      56,    56,    44,    44
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 47 "yacc.y"
    {printf("in yacc\n");(yyvsp[(1) - (2)].node)=make_leaf("Shebang_line");(yyval.node)=make_node("Shebang",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));printf("\n\nAbstract Syntax Tree:\n\n");AST_print((yyval.node));YYACCEPT;}
    break;

  case 3:
#line 50 "yacc.y"
    {(yyval.node)=make_node("Declr",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 4:
#line 51 "yacc.y"
    {(yyval.node)=make_if_node("Do while",(yyvsp[(3) - (10)].node),(yyvsp[(7) - (10)].node),(yyvsp[(10) - (10)].node));}
    break;

  case 5:
#line 52 "yacc.y"
    {(yyval.node)=make_switch_node("use_Switch",(yyvsp[(2) - (10)].node),(yyvsp[(5) - (10)].node),(yyvsp[(8) - (10)].node),(yyvsp[(10) - (10)].node));}
    break;

  case 9:
#line 56 "yacc.y"
    {(yyval.node)=make_if_node("If",(yyvsp[(3) - (8)].node),(yyvsp[(6) - (8)].node),(yyvsp[(8) - (8)].node));}
    break;

  case 12:
#line 59 "yacc.y"
    { yyerrok;yyclearin;  }
    break;

  case 13:
#line 60 "yacc.y"
    {(yyval.node)=make_leaf("epsilon");}
    break;

  case 14:
#line 63 "yacc.y"
    {strcpy((yyval.var_type),(yyvsp[(1) - (1)].var_type));strcpy(typ,(yyvsp[(1) - (1)].var_type));}
    break;

  case 15:
#line 64 "yacc.y"
    {strcpy((yyval.var_type),(yyvsp[(1) - (1)].var_type));strcpy(typ,(yyvsp[(1) - (1)].var_type));}
    break;

  case 16:
#line 65 "yacc.y"
    {strcpy((yyval.var_type),(yyvsp[(1) - (1)].var_type));strcpy(typ,(yyvsp[(1) - (1)].var_type));}
    break;

  case 23:
#line 76 "yacc.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 24:
#line 79 "yacc.y"
    {(yyval.node)=make_node("varlist",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 25:
#line 80 "yacc.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 26:
#line 83 "yacc.y"
    {(yyval.node)=make_leaf((yyvsp[(1) - (1)].text));}
    break;

  case 27:
#line 84 "yacc.y"
    {printf("ae\n");(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 28:
#line 86 "yacc.y"
    {(yyval.node)=make_leaf((yyvsp[(1) - (1)].text));}
    break;

  case 29:
#line 89 "yacc.y"
    {(yyvsp[(1) - (3)].node)=make_leaf((yyvsp[(1) - (3)].text)); (yyval.node)=make_node("=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 30:
#line 90 "yacc.y"
    {(yyvsp[(1) - (3)].node)=make_leaf((yyvsp[(1) - (3)].text));(yyvsp[(3) - (3)].node)=make_leaf(yylval.text);(yyval.node)=make_node("=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 31:
#line 91 "yacc.y"
    {(yyval.node)=make_node("=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 32:
#line 94 "yacc.y"
    {(yyval.node)=make_node("concat",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 33:
#line 95 "yacc.y"
    { yyerrok;                  }
    break;

  case 34:
#line 97 "yacc.y"
    {(yyval.node)=make_node("or",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 35:
#line 98 "yacc.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 36:
#line 101 "yacc.y"
    {(yyval.node)=make_node("and",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 37:
#line 102 "yacc.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 39:
#line 106 "yacc.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 40:
#line 109 "yacc.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 41:
#line 110 "yacc.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 44:
#line 115 "yacc.y"
    {(yyval.node)=make_node("<",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 45:
#line 116 "yacc.y"
    {(yyval.node)=make_node(">",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 46:
#line 117 "yacc.y"
    {(yyval.node)=make_node("<=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 47:
#line 118 "yacc.y"
    {(yyval.node)=make_node(">=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 48:
#line 119 "yacc.y"
    {(yyval.node)=make_node("!=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 49:
#line 120 "yacc.y"
    {(yyval.node)=make_node("==",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 50:
#line 121 "yacc.y"
    {(yyval.node)=make_leaf((yyvsp[(1) - (1)].text));}
    break;

  case 51:
#line 122 "yacc.y"
    {(yyval.node)=make_leaf((yyvsp[(1) - (1)].text));}
    break;

  case 52:
#line 123 "yacc.y"
    {(yyval.node)=make_leaf((yyvsp[(1) - (1)].text));}
    break;

  case 53:
#line 127 "yacc.y"
    {(yyval.node)=make_node("+",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 54:
#line 128 "yacc.y"
    {(yyval.node)=make_node((yyvsp[(2) - (3)].text),(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 55:
#line 129 "yacc.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 56:
#line 130 "yacc.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 57:
#line 132 "yacc.y"
    {(yyval.node)=make_node((yyvsp[(2) - (3)].text),(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 58:
#line 133 "yacc.y"
    {(yyval.node)=make_node((yyvsp[(2) - (3)].text),(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 59:
#line 134 "yacc.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 60:
#line 136 "yacc.y"
    {(yyval.node)=make_node((yyvsp[(2) - (3)].text),(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 61:
#line 137 "yacc.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 62:
#line 139 "yacc.y"
    {(yyval.node)=make_leaf((yyvsp[(1) - (1)].text)); fprintf(yyout,"in tid%s\n",(yyvsp[(1) - (1)].text));}
    break;

  case 63:
#line 140 "yacc.y"
    {(yyval.node)=make_leaf((yyvsp[(1) - (1)].text));}
    break;

  case 64:
#line 141 "yacc.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 65:
#line 144 "yacc.y"
    {(yyvsp[(1) - (2)].node)=make_leaf((yyvsp[(1) - (2)].text));(yyvsp[(2) - (2)].node)=make_leaf("+");(yyval.node)=make_node("+",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 66:
#line 145 "yacc.y"
    {(yyvsp[(1) - (2)].node)=make_leaf((yyvsp[(1) - (2)].text));(yyvsp[(2) - (2)].node)=make_leaf("-");(yyval.node)=make_node("-",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 67:
#line 146 "yacc.y"
    {(yyvsp[(2) - (2)].node)=make_leaf((yyvsp[(2) - (2)].text));(yyvsp[(1) - (2)].node)=make_leaf("+");(yyval.node)=make_node("+",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 68:
#line 147 "yacc.y"
    {(yyvsp[(2) - (2)].node)=make_leaf((yyvsp[(2) - (2)].text));(yyvsp[(1) - (2)].node)=make_leaf("-");(yyval.node)=make_node("-",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 70:
#line 151 "yacc.y"
    {(yyval.node)=make_leaf((yyvsp[(1) - (1)].text));}
    break;

  case 71:
#line 152 "yacc.y"
    {(yyval.node)=make_leaf((yyvsp[(1) - (1)].text));}
    break;

  case 72:
#line 154 "yacc.y"
    {(yyval.node)=make_node("case",(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 73:
#line 156 "yacc.y"
    {(yyval.node)=make_node("case_arg",(yyvsp[(1) - (4)].node),(yyvsp[(3) - (4)].node));}
    break;

  case 74:
#line 158 "yacc.y"
    {(yyval.node)=make_leaf((yyvsp[(1) - (1)].text));}
    break;

  case 75:
#line 159 "yacc.y"
    {(yyval.node)=make_leaf((yyvsp[(1) - (1)].text));}
    break;

  case 76:
#line 160 "yacc.y"
    {(yyval.node)=make_leaf((yyvsp[(1) - (1)].text));}
    break;

  case 77:
#line 162 "yacc.y"
    {(yyvsp[(2) - (4)].node)=make_leaf("NULL");(yyval.node)=make_node("default",(yyvsp[(3) - (4)].node),(yyvsp[(2) - (4)].node));}
    break;

  case 78:
#line 163 "yacc.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;


/* Line 1267 of yacc.c.  */
#line 1901 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 170 "yacc.y"

void yyerror(const char* arg)
{
	printf("%s\n",arg);
}

struct entry
{
	char name[30];
	char type[10];
	int width;
	int line_num;
	int scope;
};




struct entry sym_tab[100];
int ctr = 0;

void update_sym_tab(char* typ, char* nam, int line, int scope)
{
	strcpy(sym_tab[ctr].name,nam);

	if(strcmp(typ,"int")==0)
	{
		strcpy(sym_tab[ctr].type,typ);
		sym_tab[ctr].width=4;
	}

	else if(strcmp(typ,"float")==0)
	{
		strcpy(sym_tab[ctr].type,typ);
		sym_tab[ctr].width=8;
	}
	else if(strcmp(typ,"char")==0)
	{
		strcpy(sym_tab[ctr].type,typ);
		sym_tab[ctr].width=1;	
	}
	sym_tab[ctr].line_num=line;
	sym_tab[ctr].scope=scope;
	ctr++;


}


void print_sym_tab()
 { 	
 		int i; 	
		printf("\n\nSymbol Table: \n"); 
		for(i=0;i<ctr;i++) 	
		{ 		
			printf("Token: %s, Type: %s, Size: %d, Line Number: %d, Scope: %d\n \n",sym_tab[i].name, sym_tab[i].type, sym_tab[i].width,sym_tab[i].line_num,sym_tab[i].scope); 	} 

}

int look_up_sym_tab(char* nam)
{
	int i; 
	for(i=0;i<ctr;i++)
	{
		if(strcmp(sym_tab[i].name,nam)==0)
		{
			int scop=sym_tab[i].scope;
			int flag=0;
			int zero_ctr=0;
			int j=scope_ind-1;
			while(j>=0)
			{
				if(scope[j]==0)
					zero_ctr++;
				else if(scope[j]!=0 && zero_ctr>0)
					zero_ctr--;
				else if(scope[j]!=0 && zero_ctr==0)
				{
					if(scope[j]==scop)
					{
						flag=1;
						return 1;
					}
				}
				j--;
			}
		}
	}
	return 0;
}

int look_up_sym_tab_dec(char* nam, int scop)
{
	int i; 
	for(i=0;i<ctr;i++)
	{
		if(strcmp(sym_tab[i].name,nam)==0 && sym_tab[i].scope==scop)
		{
			return 1;
		}
	}
	return 0;
}


void AST_print(struct AST *t)
{
	static int ctr=0;
	//printf("inside print tree\n");
	int i;
	if(t->NumChild==0) 
		return;

	struct AST *t2=t;
	printf("\nRoot:%s\n",t2->lexeme);
	printf("Children: ");

	for(i=0;i<t2->NumChild;++i) 
	{
		printf("%s ",t2->child[i]->lexeme);
	}
	printf("\n\n");	
	for(i=0;i<t2->NumChild;++i)
	{
		AST_print(t->child[i]);
	}


	
}




/*void AST_print(struct AST *t)
{
	static int ctr=0;
	//printf("inside print tree\n");
	int i;
	if(t->NumChild==0) 
		return;
	struct AST *t2=t;
	printf("\n[ %s ",t2->lexeme);
	
	for(i=0;i<t2->NumChild;++i) 
	{
		printf("%s ",t2->child[i]->lexeme);
	}
	printf("]");	
	for(i=0;i<t2->NumChild;++i)
	{
		AST_print(t->child[i]);
	}
	
}*/







struct AST* make_node(char* root, AST_node* child1, AST_node* child2)
{
	//printf("Creating new node\n");
	struct AST * node = (struct AST*)malloc(sizeof(struct AST));
	node->child = (struct AST**)malloc(2*sizeof(struct AST *));
	node->NumChild = 2;//
	strcpy(node->lexeme,root);
	//printf("Copied lexeme\n");
	//printf("%s\n",node->lexeme);
	node->child[0] = child1;
	node->child[1] = child2;
	return node;
}

struct AST* make_if_node(char* root, AST_node* child1, AST_node* child2, AST_node* child3)
{
	//printf("Creating new node\n");
	struct AST * node = (struct AST*)malloc(sizeof(struct AST));
	node->child = (struct AST**)malloc(3*sizeof(struct AST *));
	node->NumChild = 3;
	strcpy(node->lexeme,root);
	node->child[0] = child1;
	node->child[1] = child2;
	node->child[2] = child3;

	return node;
}
struct AST* make_switch_node(char* root, AST_node* child1, AST_node* child2, AST_node* child3,AST_node*child4)
{
	//printf("Creating new node\n");
	struct AST * node = (struct AST*)malloc(sizeof(struct AST));
	node->child = (struct AST**)malloc(4*sizeof(struct AST *));
	node->NumChild = 4;
	strcpy(node->lexeme,root);
	node->child[0] = child1;
	node->child[1] = child2;
	node->child[2] = child3;
	node->child[3] = child4;
	return node;
}


struct AST* make_leaf(char* root)
{
	//printf("Creating new leaf ");
	struct AST * node = (struct AST*)malloc(sizeof(struct AST));
	strcpy(node->lexeme,root);
	//printf("%s\n",node->lexeme);
	node->NumChild = 0;
	node->child = NULL;
	return node;
}



int main(int argc,char* *argv)
{
	printf("Parsing the following Input:\n\n");
	//yyin=fopen("Input.txt","r");
	//print_sym_tab();
	//yylex();
	char ch,c;
	FILE *f;    
	if(argc != 2) {printf("useage:  calc filename \n"); exit(1);}
	if( !(yyin = fopen(argv[1],"r")) ){ 
	       printf("cannot open file\n");exit(1);
 }
	
	yyparse();
	printf("\n");
	return 0;
}

int get_scope()
{
	//printf("ind :%d\n",scope_ind);
	int i=scope_ind-1;
	int zero_ctr=0;
	int flag=1;
	while(flag && i>0)
	{
		if(scope[i]!=0)
			zero_ctr--;
		else
			zero_ctr++;
		if(zero_ctr==0)
		{
			i--;
			flag=0;
			break;
		}
		i--;
	}
	return scope[i];
}


