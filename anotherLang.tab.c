
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "anotherLang.y"


#include <stdio.h>
#include <stdlib.h>
#include "globalUtils.h"
#include <string.h>
#include <ctype.h>

extern FILE* yyout;
extern FILE* yyin;

/*
 * Global variables
 *
 */

int currentPosition = 0;
const char* constStr = "(const int[]){";
const char* opArray = "arrayOperations(" ;


/*
 * Global data structures
 *
 */

char printType[MAX_SIZE];
char intType[ARR_SIZE];
char arrType[ARR_SIZE][BUFF];

/*
 * Prototypes: Functions declarations
 *
 */

void yyerror();
int yylex();
char* loadFunctionsFile();
char *stringToken(char *srcString, char *delim);
unsigned int isDelim(char c, char *delim);
char* getHeadersAndIncludes();
void statementListHandler(char* res, char* statement,char* statementList);
void blockHandler(char* res,char* begin,char* statement,char* end);
void arrTypeHandler(char* res,char* arrRegex);
void squareParthesisHandler(char* res,char* variable,char* position,char* expression);
void parthesisHandler(char* res,char* p1, char* expr,char* p2);
void dotProductHandler(char * res, char * expression1, char * dotProductAt, char * expression2);
void expressionListHandler(char * res, char * expression_, char * comma_, char * expressionList_);
void variableListHandler(char* res,char* variable_, char* comma_, char* varList);
void ifAndLoopHandler(char* res,char* ifVar,char* openParenthesis,char* cond,char* closeParenthesis,char* thenVar,char* block);
void positionHandler(char* res,char* variable, char* position, char* expression1,char* assigment,char* expression2);
void assigmentHandler(char* res,char* variable,char* assigment,char* expression);
void opHandler(char* res, char* arr1, char* arr2, char* arr3);
void decleratorHandler(char * res,char* langTypes, char* varList);
void pointerHandler(char* src);
bool validateArr(char* identifier);
bool validateArrConst(char* tok);
void storeArray(char* src);
int getArraySize(char* value);
void printHandler(char* expressions);


/* Line 189 of yacc.c  */
#line 136 "anotherLang.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     beginVar = 258,
     endVar = 259,
     numRegex = 260,
     id = 261,
     arrRegex = 262,
     intVar = 263,
     arrVar = 264,
     leftBracket = 265,
     rightBracket = 266,
     openParenthesis = 267,
     closeParenthesis = 268,
     semiColon = 269,
     assigment = 270,
     position = 271,
     comma = 272,
     dotProduct = 273,
     plus = 274,
     minus = 275,
     multiply = 276,
     divide = 277,
     greaterThan = 278,
     lessThan = 279,
     lessEqualThan = 280,
     greateEqualsThan = 281,
     notEquals = 282,
     equals = 283,
     whileVar = 284,
     doVar = 285,
     ifVar = 286,
     thenVar = 287,
     printVar = 288
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 65 "anotherLang.y"

    char token[8192];



/* Line 214 of yacc.c  */
#line 211 "anotherLang.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 223 "anotherLang.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNRULES -- Number of states.  */
#define YYNSTATES  80

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     9,    12,    14,    17,    20,    22,
      24,    27,    30,    34,    40,    47,    54,    57,    59,    63,
      65,    69,    71,    75,    79,    83,    87,    91,    95,    97,
      99,   103,   107,   109,   111,   113,   115,   117,   119,   121,
     123,   126,   128,   130
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      35,     0,    -1,    36,    -1,     3,    37,     4,    -1,    38,
      37,    -1,    38,    -1,    39,    14,    -1,    40,    14,    -1,
      41,    -1,    42,    -1,    43,    14,    -1,    52,    44,    -1,
      46,    15,    47,    -1,    46,    16,    47,    15,    47,    -1,
      31,    12,    48,    13,    32,    36,    -1,    29,    12,    48,
      13,    30,    36,    -1,    33,    45,    -1,    46,    -1,    46,
      17,    44,    -1,    47,    -1,    47,    17,    45,    -1,    50,
      -1,    47,    19,    47,    -1,    47,    20,    47,    -1,    47,
      21,    47,    -1,    47,    22,    47,    -1,    47,    18,    47,
      -1,    12,    47,    13,    -1,    46,    -1,    51,    -1,    46,
      16,    47,    -1,    47,    49,    47,    -1,    23,    -1,    24,
      -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,     6,
      -1,     5,    -1,    20,     5,    -1,     7,    -1,     8,    -1,
       9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   120,   120,   122,   125,   126,   129,   130,   131,   132,
     133,   136,   139,   141,   144,   149,   154,   157,   158,   161,
     162,   165,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   179,   182,   183,   184,   185,   186,   187,   190,   193,
     194,   195,   198,   199
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "beginVar", "endVar", "numRegex", "id",
  "arrRegex", "intVar", "arrVar", "leftBracket", "rightBracket",
  "openParenthesis", "closeParenthesis", "semiColon", "assigment",
  "position", "comma", "dotProduct", "plus", "minus", "multiply", "divide",
  "greaterThan", "lessThan", "lessEqualThan", "greateEqualsThan",
  "notEquals", "equals", "whileVar", "doVar", "ifVar", "thenVar",
  "printVar", "$accept", "program", "block", "statementList", "statement",
  "declarator", "assignment", "conditional", "loop", "print",
  "variableList", "expressionList", "variable", "expression", "cond",
  "ops", "identifier", "number", "langTypes", 0
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
     285,   286,   287,   288
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    37,    37,    38,    38,    38,    38,
      38,    39,    40,    40,    41,    42,    43,    44,    44,    45,
      45,    46,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    48,    49,    49,    49,    49,    49,    49,    50,    51,
      51,    51,    52,    52
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     1,     2,     2,     1,     1,
       2,     2,     3,     5,     6,     6,     2,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,    38,    42,    43,     0,     0,     0,
       0,     5,     0,     0,     8,     9,     0,     0,    21,     0,
       1,     0,     0,    39,    41,     0,     0,    16,    28,    19,
      29,     3,     4,     6,     7,    10,     0,     0,    11,    17,
       0,     0,     0,     0,    40,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,    32,    33,    34,    35,    36,
      37,     0,     0,     0,    27,    30,    20,    26,    22,    23,
      24,    25,     0,    18,    31,     0,     0,    13,    15,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    10,    11,    12,    13,    14,    15,    16,
      38,    27,    28,    29,    41,    61,    18,    30,    19
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -57
static const yytype_int8 yypact[] =
{
      19,     3,    23,   -57,   -57,   -57,   -57,    12,    14,     1,
      31,     3,    25,    26,   -57,   -57,    52,   -12,   -57,    27,
     -57,     1,     1,   -57,   -57,     1,    33,   -57,    51,    56,
     -57,   -57,   -57,   -57,   -57,   -57,     1,     1,   -57,    66,
      36,    71,    72,    24,   -57,     1,     1,     1,     1,     1,
       1,     1,    29,    50,    27,   -57,   -57,   -57,   -57,   -57,
     -57,     1,    57,    54,   -57,   -57,   -57,    60,   -57,   -57,
      -5,    -5,     1,   -57,    29,    19,    19,    29,   -57,   -57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -56,    77,   -57,   -57,   -57,   -57,   -57,   -57,
      35,    44,    -1,   -20,    69,   -57,   -57,   -57,   -57
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      17,    40,    40,    36,    37,    43,    23,     4,    24,     4,
      17,     5,     6,    25,    48,    49,    52,    53,    39,    78,
      79,    26,     1,    20,    21,    65,    22,    67,    68,    69,
      70,    71,     7,     4,     8,    31,     9,    64,    44,    33,
      34,    74,    47,    48,    49,    50,    51,    47,    48,    49,
      50,    51,    77,    39,    47,    48,    49,    50,    51,    55,
      56,    57,    58,    59,    60,    72,    35,    45,    47,    48,
      49,    50,    51,    46,    47,    48,    49,    50,    51,    48,
      49,    50,    51,    54,    62,    63,    76,    75,    32,    73,
      66,    42
};

static const yytype_uint8 yycheck[] =
{
       1,    21,    22,    15,    16,    25,     5,     6,     7,     6,
      11,     8,     9,    12,    19,    20,    36,    37,    19,    75,
      76,    20,     3,     0,    12,    45,    12,    47,    48,    49,
      50,    51,    29,     6,    31,     4,    33,    13,     5,    14,
      14,    61,    18,    19,    20,    21,    22,    18,    19,    20,
      21,    22,    72,    54,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    15,    14,    16,    18,    19,
      20,    21,    22,    17,    18,    19,    20,    21,    22,    19,
      20,    21,    22,    17,    13,    13,    32,    30,    11,    54,
      46,    22
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    35,    36,     6,     8,     9,    29,    31,    33,
      37,    38,    39,    40,    41,    42,    43,    46,    50,    52,
       0,    12,    12,     5,     7,    12,    20,    45,    46,    47,
      51,     4,    37,    14,    14,    14,    15,    16,    44,    46,
      47,    48,    48,    47,     5,    16,    17,    18,    19,    20,
      21,    22,    47,    47,    17,    23,    24,    25,    26,    27,
      28,    49,    13,    13,    13,    47,    45,    47,    47,    47,
      47,    47,    15,    44,    47,    30,    32,    47,    36,    36
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
# if YYLTYPE_IS_TRIVIAL
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 120 "anotherLang.y"
    {fprintf(yyout, "%s", (yyval.token));;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 122 "anotherLang.y"
    {blockHandler((yyval.token),(yyvsp[(1) - (3)].token),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].token));;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 125 "anotherLang.y"
    {statementListHandler((yyval.token),(yyvsp[(1) - (2)].token),(yyvsp[(2) - (2)].token));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 126 "anotherLang.y"
    {strcpy((yyval.token), (yyvsp[(1) - (1)].token));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 129 "anotherLang.y"
    {strcpy((yyval.token), (yyvsp[(1) - (2)].token)); strcat((yyval.token), (yyvsp[(2) - (2)].token));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 130 "anotherLang.y"
    {strcpy((yyval.token), (yyvsp[(1) - (2)].token)); strcat((yyval.token), (yyvsp[(2) - (2)].token));;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 131 "anotherLang.y"
    {strcpy((yyval.token), (yyvsp[(1) - (1)].token));;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 132 "anotherLang.y"
    {strcpy((yyval.token), (yyvsp[(1) - (1)].token));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 133 "anotherLang.y"
    {strcpy((yyval.token), (yyvsp[(1) - (2)].token)); strcat((yyval.token), (yyvsp[(2) - (2)].token));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 136 "anotherLang.y"
    {decleratorHandler((yyval.token),(yyvsp[(1) - (2)].token),(yyvsp[(2) - (2)].token));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 139 "anotherLang.y"
    {assigmentHandler((yyval.token),(yyvsp[(1) - (3)].token),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].token));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 141 "anotherLang.y"
    {positionHandler((yyval.token),(yyvsp[(1) - (5)].token),(yyvsp[(2) - (5)].token),(yyvsp[(3) - (5)].token),(yyvsp[(4) - (5)].token),(yyvsp[(5) - (5)].token));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 145 "anotherLang.y"
    {ifAndLoopHandler((yyval.token),(yyvsp[(1) - (6)].token),(yyvsp[(2) - (6)].token),(yyvsp[(3) - (6)].token),(yyvsp[(4) - (6)].token),(yyvsp[(5) - (6)].token),(yyvsp[(6) - (6)].token));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 150 "anotherLang.y"
    {ifAndLoopHandler((yyval.token),(yyvsp[(1) - (6)].token),(yyvsp[(2) - (6)].token),(yyvsp[(3) - (6)].token),(yyvsp[(4) - (6)].token),(yyvsp[(5) - (6)].token),(yyvsp[(6) - (6)].token));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 154 "anotherLang.y"
    {printHandler((yyvsp[(2) - (2)].token)); strcpy((yyval.token), printType);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 158 "anotherLang.y"
    {variableListHandler((yyval.token),(yyvsp[(1) - (3)].token),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].token));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 162 "anotherLang.y"
    {expressionListHandler((yyval.token),(yyvsp[(1) - (3)].token),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].token));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 168 "anotherLang.y"
    { opHandler((yyval.token), (yyvsp[(1) - (3)].token), (yyvsp[(2) - (3)].token), (yyvsp[(3) - (3)].token)); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 169 "anotherLang.y"
    { opHandler((yyval.token), (yyvsp[(1) - (3)].token), (yyvsp[(2) - (3)].token), (yyvsp[(3) - (3)].token)); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 170 "anotherLang.y"
    { opHandler((yyval.token), (yyvsp[(1) - (3)].token), (yyvsp[(2) - (3)].token), (yyvsp[(3) - (3)].token)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 171 "anotherLang.y"
    { opHandler((yyval.token), (yyvsp[(1) - (3)].token), (yyvsp[(2) - (3)].token), (yyvsp[(3) - (3)].token)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 172 "anotherLang.y"
    { dotProductHandler((yyval.token),(yyvsp[(1) - (3)].token),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].token));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 173 "anotherLang.y"
    { parthesisHandler((yyval.token),(yyvsp[(1) - (3)].token),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].token));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 176 "anotherLang.y"
    {squareParthesisHandler((yyval.token),(yyvsp[(1) - (3)].token),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].token));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 179 "anotherLang.y"
    {strcpy((yyval.token), (yyvsp[(1) - (3)].token)); strcat((yyval.token), (yyvsp[(2) - (3)].token)); strcat((yyval.token), (yyvsp[(3) - (3)].token));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 194 "anotherLang.y"
    {strcpy((yyval.token), (yyvsp[(1) - (2)].token)); strcat((yyval.token), (yyvsp[(2) - (2)].token));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 195 "anotherLang.y"
    {arrTypeHandler((yyval.token),(yyvsp[(1) - (1)].token));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 199 "anotherLang.y"
    {strcpy((yyval.token), "int*");}
    break;



/* Line 1455 of yacc.c  */
#line 1680 "anotherLang.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 202 "anotherLang.y"


/*
 * Functions- Implementations
 *
 */



/*
 * name:  statementListHandler
 * @params:char* res, char* statement,char* statementList
 * @desc: Concatenating statements according to grammer.
 */

void statementListHandler(char* res, char* statement,char* statementList){
    strcpy(res, statement);
    strcat(res, "\n");
    strcat(res, statementList);
}

/*
 * name:  squareParthesisHandler
 * @params:char* res,char* variable,char* position,char* expression
 * @desc: Concatenating sqaure parathensis for arrays declarations.
 */

void squareParthesisHandler(char* res,char* variable,char* position,char* expression)
{
        if(!validateArr(variable)){
            yyerror("Cannot make an position operation on int type.");
        }else{
            strcpy(res, variable);
            strcat(res,"[");strcat(res,expression);
            strcat(res,"]");
        }
}

/*
 * name:  parthesisHandler
 * @params:char* res,char* p1, char* expr,char* p2
 * @desc: Concatenating  parathensis for declarations.
 */
 
void parthesisHandler(char* res,char* p1, char* expr,char* p2){
    strcpy(res, p1);
    strcat(res, expr);
    strcat(res, p2);
}


/*
 * name:  dotProductHandler
 * @params:char * res, char * expression1, char * dotProductAt, char * expression2
 * @desc: Concatenating  expressions for handle with dot product operation.
 */

 void dotProductHandler(char * res, char * expression1, char * dotProductAt, char * expression2)
{

    if ((validateArr(expression1) || validateArrConst(expression1)) && (validateArr(expression2) || validateArrConst(expression2))) {

        strcpy(res, "dotProduct(");
        strcat(res, expression1);
        strcat(res, ", ");
        strcat(res, expression2);
        strcat(res, ", ");

        if (validateArr(expression1)) {
            strcat(res, "getArraySize(");
            strcat(res, expression1);
            strcat(res, ")");
        } else if (validateArrConst(expression1)) {
            getArraySize(expression1);
            strcat(res, intType);
        }
        strcat(res, ")");
    } else {
        yyerror("Error.Illegal dot product operation.");
    }
}


/*
 * name:  expressionListHandler
 * @params:char * res, char * expression_, char * comma_, char * expressionList_
 * @desc: Concatenating  expression list by the grammer rules.
 */
 
void expressionListHandler(char * res, char * expression_, char * comma_, char * expressionList_)
{
        strcpy(res, expression_);
        strcat(res, "|");
        strcat(res,expressionList_);
}

/*
 * name:  variableListHandler
 * @params:char* res,char* variable_, char* comma_, char* varList
 * @desc: Concatenating  variable list by the grammer rules.
 */

void variableListHandler(char* res,char* variable_, char* comma_, char* varList)
{
strcpy(res, variable_);
strcat(res, comma_);
strcat(res,varList);
}

/*
 * name:  ifAndLoopHandler
 * @params:char* res,char* ifVar,char* openParenthesis,char* cond,char* closeParenthesis,char* thenVar,char* block
 * @desc: Concatenating  if  and loop conditions  by the grammer rules.
 */
void ifAndLoopHandler(char* res,char* ifVar,char* openParenthesis,char* cond,char* closeParenthesis,char* thenVar,char* block)
{
    strcpy(res, ifVar);
    strcat(res, openParenthesis);
    strcat(res, cond);
    strcat(res, closeParenthesis);
    strcat(res, block);
}

/*
 * name:  positionHandler
 * @params:char* res,char* variable, char* position, char* expression1,char* assigment,char* expression2
 * @desc: Positioning ans assigment concatination.
 */
void positionHandler(char* res,char* variable, char* position, char* expression1,char* assigment,char* expression2){
    if(!validateArr(variable)){
    yyerror("Error!Cannot operate array indexing on int type.");
}
    else{
        strcpy(res, variable);
        strcat(res, " = elementAt(");
        strcat(res, variable);
        strcat(res, ", ");
        strcat(res, expression1);
        strcat(res, ", ");
        strcat(res, expression2);
        strcat(res, ")");
    }
}


/*
 * name:  assigmentHandler
 * @params:char* res,char* variable,char* assigment,char* expression
 * @desc: Concatination for assigment expressions.
 */

void assigmentHandler(char* res,char* variable,char* assigment,char* expression)
{
    if(!validateArr(variable)){
        if(validateArrConst(expression)){
            yyerror("Error: Setting arr to an int!!");
        }else{
            strcpy(res, variable);
            strcat(res, assigment);
            strcat(res, expression);
        }
    }else{
    
        strcpy(res, variable);
        strcat(res, assigment);
        strcat(res, "arrayAssigment(");
        strcat(res, variable);
        strcat(res, ",");
        if(validateArr(expression) || validateArrConst(expression)){
            strcat(res, expression);
        }else{

            strcat(res, "(const int[]){");
            strcat(res, expression);
            strcat(res, "}");
            
        }

        if(validateArr(expression)){
                strcat(res, ",getArraySize(");
                strcat(res, expression);
                strcat(res, "))");
        }else{
            if(validateArrConst(expression)){
                getArraySize(expression);
                strcat(res, ",");
                strcat(res, intType);
                strcat(res, ")");
            }else{
                strcat(res, ",");
                strcat(res, "1");
                strcat(res, ")");
            }
        }
        
    }
}   


/*
 * name:  decleratorHandler
 * @params:char * res,char* langTypes, char* varList
 * @desc: Type decleration operations.
 */
void decleratorHandler(char * res,char* langTypes, char* varList)
{
    strcpy(res, langTypes); strcat(res, " "); 
    if(strcmp(langTypes, "int")>0){
        storeArray(varList);
        pointerHandler(varList);
        varList[0] = ' ';
        strcat(res, varList);
    }
    else{
        strcat(res, varList);
    }
}


/*
 * name:  int isDelim
 * @params:int mode,char* res,char* src
 * @desc: Checking for a delimiters in a given string.
 */
unsigned int isDelim(char c, char *delim)
{
    while(*delim != '\0')
    {
        if(c == *delim)
            return 1;
        delim++;
    }
    return 0;
}

/*
 * name:  char *stringToken
 * @params:char *srcString, char *delim
 * @desc:  Tokenizing a string based on a delimiter
 */

char *stringToken(char *srcString, char *delim)
{
    static char *backup_string; // start of the next search
    if(!srcString)
    {
        srcString = backup_string;
    }
    if(!srcString)
    {
        return NULL;
    }
    // handle beginning of the string containing delims
    while(1)
    {
        if(isDelim(*srcString, delim))
        {
            srcString++;
            continue;
        }
        if(*srcString == '\0')
        {
            // we've reached the end of the string
            return NULL; 
        }
        break;
    }
    char *ret = srcString;
    while(1)
    {
        if(*srcString == '\0')
        {
            /*end of the input string and
            next exec will return NULL*/
            backup_string = srcString;
            return ret;
        }
        if(isDelim(*srcString, delim))
        {
            *srcString = '\0';
            backup_string = srcString + 1;
            return ret;
        }
        srcString++;
    }
}

/*
 * name:  pointerHandler
 * @params:char *str
 * @desc: Pointers operations.
 */

void pointerHandler(char *str) {
    char *strToken = stringToken(str, ",");
    char buff[MAX_SIZE];
    buff[0] = 0;
    while (strToken != NULL) {
        strcat(buff, "*");
        strcat(buff, strToken);
        strcat(buff, "=NULL, ");
        strToken = stringToken(NULL, ",");
    }
    if(strlen(buff) >= 4)
        buff[strlen(buff) - 2] = 0;
    strcpy(str, buff);
}

/*
 * name:  storeArray
 * @params:char *str
 * @desc: Storing Arrays in memory.
 */
void storeArray(char *str) {
    char buff[MAX_SIZE];
    strcpy(buff, str);

    char *strToken = stringToken(buff, ",");
    while (strToken != NULL) {
        strcat(arrType[currentPosition++], strToken);
        strToken = stringToken(NULL, ",");
    }
}

/*
 * name:  storeArray
 * @params:char *identifier
 * @desc: Checking array validity.
 */
bool validateArr(char* identifier){
    for( int i = 0; i < currentPosition; i++){
        if(strcmp(arrType[i], identifier) == 0)
            return true;
    }
    const char* dest = "mathOpOnArray(";
    bool ret=strncmp(identifier, dest, strlen(dest));
    return !ret;
}


/*
 * name:  storeArray
 * @params:char *identifier
 * @desc: Checkingif it is a constant array
 */
bool validateArrConst(char* src){
    const char* dest = CONST;
    bool ret=strncmp(src, dest, strlen(dest));
    return !ret;
}

/*
 * name:  storeArray
 * @params:char *identifier
 * @desc: Gets the num of element in the array
 */
int getArraySize(char* value){
    int count = 0;
    if(strlen(value) > 0)
        count++;

    for(int i = 0; i < strlen(value); i++){
        if(value[i] == ',')
            count++;
    }
    intType[0] = 0;
    sprintf( intType, "%d", count );
    return count;
}

/*
 * name:  countChar
 * @params:char* str, char c
 * @desc: Char counter
 */
int countChar(char* str, char c){
    int count = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == c)
            count++;
    }
    return count;
}

/*
 * name:  opHandler
 * @params:char* res, char* arr1, char* arr2, char* arr3
 * @desc: Operations between arrays.
 */
void opHandler(char* res, char* arr1, char* arr2, char* arr3){
    if((validateArr(arr1) || validateArrConst(arr1)) && (validateArr(arr3) || validateArrConst(arr3)))
    {
        strcpy(res, "mathOpOnArray(");
        strcat(res, arr1);
        strcat(res, ", ");
        strcat(res, arr3);
        strcat(res, ", ");
        if(validateArr(arr1)){
            strcat(res, "getArraySize(");
            strcat(res, arr1);
            strcat(res, ")");
        }else{
            getArraySize(arr1);
            strcat(res, intType);
        }
        strcat(res, ",");
        if(validateArr(arr3)){
            strcat(res, "getArraySize(");
            strcat(res, arr3);
            strcat(res, ")");
        }else{
            getArraySize(arr3);
            strcat(res, intType);
        }
        strcat(res, ",'");
        strcat(res, arr2);
        strcat(res, "')");
    }
    else if((validateArr(arr1) || validateArrConst(arr1)) || (validateArr(arr3) || validateArrConst(arr3))){
        yyerror("Error! Cannot operate between array and int types.");
    }
    else
    {
        strcpy(res, arr1);
        strcat(res, arr2);
        strcat(res, arr3);
    }
}

/*
 * name:  printHandler
 * @params:char* expressions
 * @desc: Enabeling  Printing.
 */

void printHandler(char* expressions){
    char buffer[MAX_SIZE];
    int numOfExpressions = countChar(expressions, '|');
    printType[0] = 0;
    strcpy(buffer, expressions);

    char* token = stringToken(buffer, "|");
    while(token != NULL){
        if(validateArr(token))
        {
            strcat(printType, "printArray_(");
            strcat(printType, token);
            strcat(printType, ", getArraySize(");
            strcat(printType, token);
            strcat(printType, "));");
        }else if(validateArrConst(token)){
            strcat(printType, "printArray_(");
            strcat(printType, token);
            strcat(printType, ", ");
            getArraySize(token);
            strcat(printType, intType);
            strcat(printType, ");");
        }else{
            strcat(printType, "printf(\"%d\", ");
            strcat(printType, token);
            strcat(printType, ");");
        }
        if(numOfExpressions>0)
            strcat(printType, "printf(\",\");");
        numOfExpressions--;

        token = stringToken(NULL, "|");
    }
    strcat(printType, "printf(\"\\n\")");    
}

/*
 * name:  blockHandler
 * @params:char* res,char* begin,char* statement,char* end
 * @desc: Concatination with block tokens according to grammer
 */

void blockHandler(char* res,char* begin,char* statement,char* end)
{
    strcpy(res, "{\n");
    strcat(res, statement);
    strcat(res, "\n}");
}

/*
 * name: arrTypeHandler
 * @params:char* res,char* arrRegex
 * @desc: Concatenating const array types.
 */
 void arrTypeHandler(char* res,char* arrRegex)
 {
     strcpy(res, CONST);
     arrRegex[0] = '{'; arrRegex[strcspn(arrRegex, "]")]='}';
     strcat(res, arrRegex);
 }

/*
 * name: loadFunctionsFile
 * @params:void
 * @desc: Return a string that contains the cout.c file.
 */
char* loadFunctionsFile() 
{
     return ("return 0;"
"}\n"
"\n"
"\n"
"int *createArrayAllocation(int *intArr) {\n"
"    if (intArr == NULL)\n"
"        intArr = malloc(sizeof(int));\n"
"        if(!intArr) printf(\"Error! Cannot allocate memory;\");\n"
"    currIndex[numOfArrays] = intArr;\n"
"    arrBuffer[numOfArrays] = 0;\n"
"    numOfArrays++;\n"
"    return intArr;\n"
"}\n"
"\n"
"int *appendToArray(int *arr, int num) {\n"
"    int i;\n"
"\n"
"    for (i = 0; i < numOfArrays; i++)\n"
"        if (currIndex[i] == arr)\n"
"            break;\n"
"\n"
"    if (i == numOfArrays) {\n"
"        if (numOfArrays < ARR_SIZE) {\n"
"            arr = createArrayAllocation(arr);\n"
"        } else {\n"
"            return NULL;\n"
"        }\n"
"    }\n"
"    int size = arrBuffer[i];\n"
"    arrBuffer[i]++;\n"
"    arr = realloc(arr, (size + 1) * sizeof(int));\n"
"    currIndex[i] = arr;\n"
"    arr[size] = num;\n"
"    return arr;\n"
"}\n"
"\n"
"int getArraySize(const int *arr) {\n"
"    int i;\n"
"    for (i = 0; i < numOfArrays; i++)\n"
"        if (currIndex[i] == arr)\n"
"            break;\n"
"    if (i < numOfArrays)\n"
"        return arrBuffer[i];\n"
"    return -1;\n"
"}\n"
"\n"
"int *elementAt(int *intArr, int pos, int val) {\n"
"    int i=0;\n"
"    for (i = 0; i < numOfArrays; i++)\n"
"        if (currIndex[i] == intArr)\n"
"            break;\n"
"\n"
"    if (i == numOfArrays) {\n"
"        if (numOfArrays < ARR_SIZE) {\n"
"            intArr = createArrayAllocation(intArr);\n"
"        } else {\n"
"            return NULL;\n"
"        }\n"
"    }\n"
"    int size = arrBuffer[i];\n"
"    if (pos < size)\n"
"        intArr[pos] = val;\n"
"    else {\n"
"        arrBuffer[i] = pos + 1;\n"
"        intArr = realloc(intArr, (pos + 1) * sizeof(int));\n"
"        if(!intArr) printf(\"Error! Cannot allocate memory;\");\n"
"        currIndex[i] = intArr;\n"
"        intArr[pos] = val;\n"
"    }\n"
"    return intArr;\n"
"}\n"
"\n"
"int *arrayAssigment(int *dest, const int *src, int arrSize) {\n"
"    if (dest != NULL)\n"
"        free(dest);\n"
"    dest = NULL;\n"
"    dest = elementAt(dest, arrSize - 1, src[arrSize - 1]);\n"
"    for (int i = 0; i < arrSize - 1; i++)\n"
"        dest[i] = src[i];\n"
"\n"
"    return dest;\n"
"}\n"
"\n"
"int dotProduct(const int *left, const int *right, int size) {\n"
"    int i, totalSum = 0;\n"
"    for (i = 0; i < size; i++) {\n"
"        totalSum += left[i] * right[i];\n"
"    }\n"
"    return totalSum;\n"
"}\n"
"\n"
"void printArray_(int *arr, int size) {\n"
"    int i;\n"
"    printf(\"{\");\n"
"    for (i = 0; i < size; i++) {\n"
"        printf(\"%%d\", arr[i]);\n"
"        if (i < size - 1)\n"
"            printf(\", \");\n"
"    }\n"
"    printf(\"}\");\n"
"}\n"
"\n"
"int *mathOpOnArray(const int *left, const int *right, int leftSize, int rightSize, char op) {\n"
"    int enlargeSize =0;\n                            "
"    if(leftSize>rightSize)\n                         "
"      enlargeSize=leftSize; \n                       "
"     else             \n                             "
"     enlargeSize=rightSize;  \n                      "       
"    int *newArr = malloc(enlargeSize * sizeof(int));\n"
"    if(!newArr) printf(\"Error! Cannot allocate memory;\");\n"
"    newArr = createArrayAllocation(newArr);\n"
"\n"
"    for (int i = 0; i < numOfArrays; i++)\n"
"        if (currIndex[i] == newArr) { arrBuffer[i] = enlargeSize; }\n"
"\n"
"    for (int i = 0; i < enlargeSize; i++) {\n"
"        int leftValue = i < leftSize ?  left[i] : 0;\n"
"        int rightValue = i < rightSize ? right[i] : 0;\n"
"        switch (op) {\n"
"            case '+':\n"
"                newArr[i] = leftValue + rightValue;\n"
"                break;\n"
"            case '-':\n"
"                newArr[i] = leftValue - rightValue;\n"
"                break;\n"
"            case '*':\n"
"                newArr[i] = leftValue * rightValue;\n"
"                break;\n"
"            case '/':\n"
"                newArr[i] = leftValue / rightValue;\n"
"                break;\n"
"            default:\n"
"                newArr[i] = 0;\n"
"        }\n"
"    }\n"
"    return newArr;\n"
"}");
 }


/*
 * name:  getHeadersAndIncludes
 * @params:void
 * @desc: Returns includes and prototypes of fucntions.
 */
char* getHeadersAndIncludes(){
    return ("\n"
"\n"
"#include <stdio.h>\n"
"#include <stdlib.h>\n"
"#include <string.h>\n"
"#include <ctype.h>\n"
"\n"
"\n"
"int numOfArrays = 0;\n"
"int arrBuffer[ARR_SIZE];\n"
"int *currIndex[ARR_SIZE];\n"
"\n"

"\n"
"int* createArrayAllocation(int *arr);\n"
"int* appendToArray(int *arr, int val);\n"
"int  getArraySize(const int *arr);\n"
"int *arrayAssigment(int *dest, const int *src, int arrSize);\n"
"int* elementAt(int *arr, int index, int val);\n"
"int *mathOpOnArray(const int *left, const int *right, int leftSize, int rightSize, char op);\n"
"void printArray_(int *a, int size);\n"
"int dotProduct(const int *left, const int *right, int size);\n"
"\n"
"\n"
"int main()\n"
"{\n");
}


int main(int argc, char** argv){
    // Open the source code file
    if(argc == 2){
        yyin = fopen(argv[1], "r");
        if(!yyin)
   		{
   		 	fprintf(stderr, "Error! Cannot open the file %s\n", argv[1]);
   		 	return 1;
   		}
    }
    yyout = fopen("out.c", "w");
    if(!yyout){
        fprintf(stderr, "Cannot open the out.c file.\n");
    }
    // Handling dynamoc arrays
    fprintf(yyout, "#define ARR_SIZE %d\n", 128);
    fprintf(yyout,getHeadersAndIncludes());
    // Parsing
    yyparse();
    fprintf(yyout,loadFunctionsFile());

    //Closing files
    fclose(yyin);
    fclose(yyout);
    return 0;
}
