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
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     INT = 259,
     VOID = 260,
     WHILE = 261,
     IF = 262,
     THEN = 263,
     ELSE = 264,
     READ = 265,
     WRITE = 266,
     FOR = 267,
     RETURN = 268,
     LE = 269,
     GE = 270,
     EQ = 271,
     NE = 272,
     ID = 273,
     UMINUS = 274
   };
#endif
/* Tokens.  */
#define NUM 258
#define INT 259
#define VOID 260
#define WHILE 261
#define IF 262
#define THEN 263
#define ELSE 264
#define READ 265
#define WRITE 266
#define FOR 267
#define RETURN 268
#define LE 269
#define GE 270
#define EQ 271
#define NE 272
#define ID 273
#define UMINUS 274




/* Copy the first part of user declarations.  */
#line 1 "lab5cminustruncate.y"

/*
 *			**** CMINUS ****
 *
 *
 */

/* 
   This lab is designed for you to create YACC directives using the EBNF description of Cminus.

   You are to take the EBNF of CMINUS and create YACC rules that will syntically check if an input
   program is syntactically correct.  You DO NOT have to do any type checking or any checking if an ID 
   has been defined.  

   The nice part of YACC is that it will do the checking for you as long as you define things correctly.
   You will need to report any syntax errors on the appropriate line.  If possible, you should have YACC
    continue with the parsing until end of file

   You will need to ensure that you define your tokens properly and with the correct return values.

   Shaun Cooper
    January 2015

*/


	/* begin specs */
#define max(a,b) (((a)>(b))?(a):(b))
static int level = 0;
static int goffset=0;
static int offset=0;
static int maxoffset=0;
    /* begin specs */
#include <stdio.h>
#include <ctype.h>
#include "ast.c"
#include "symbol.c"
#include "emit.c"
#include "lex.yy.c"

#ifndef SYMTABLE
#define SYMTABLE
#include "symbol.h"
#endif


#ifndef AST
#define AST
#include "AST.h"
#endif


void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s on line %d\n", s, linecount);
}

FILE *fp;



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
#line 66 "lab5cminustruncate.y"
{
      int value;
      char * string;
      ASTnode * node;  /* so we can build an AST */
      enum OPERATORS operator;
      
}
/* Line 193 of yacc.c.  */
#line 204 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 217 "y.tab.c"

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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   122

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  117

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   274

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    25,    20,     2,
      30,    31,    23,    21,    32,    22,     2,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
      36,    35,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    29,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,    19,    34,     2,     2,     2,     2,
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
      15,    16,    17,    18,    26
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    18,    25,
      27,    29,    30,    31,    40,    42,    44,    46,    50,    53,
      58,    59,    65,    68,    69,    70,    73,    75,    77,    79,
      81,    83,    85,    87,    89,    92,    94,    98,   104,   112,
     118,   121,   125,   129,   133,   135,   137,   142,   144,   148,
     150,   152,   154,   156,   158,   160,   162,   166,   168,   170,
     172,   176,   178,   180,   184,   186,   188,   190,   195,   197,
     198,   200
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    40,    -1,    41,    -1,    41,    40,    -1,
      42,    -1,    44,    -1,    43,    18,    27,    -1,    43,    18,
      28,     3,    29,    27,    -1,     4,    -1,     5,    -1,    -1,
      -1,    43,    18,    30,    45,    47,    46,    31,    50,    -1,
       5,    -1,    48,    -1,    49,    -1,    48,    32,    49,    -1,
      43,    18,    -1,    43,    18,    28,    29,    -1,    -1,    33,
      51,    52,    53,    34,    -1,    42,    52,    -1,    -1,    -1,
      54,    53,    -1,    55,    -1,    50,    -1,    57,    -1,    58,
      -1,    56,    -1,    59,    -1,    60,    -1,    61,    -1,    62,
      27,    -1,    27,    -1,    63,    35,    55,    -1,     7,    30,
      62,    31,    54,    -1,     7,    30,    62,    31,    54,     9,
      54,    -1,     6,    30,    62,    31,    54,    -1,    13,    27,
      -1,    13,    62,    27,    -1,    10,    63,    27,    -1,    11,
      62,    27,    -1,    64,    -1,    18,    -1,    18,    28,    62,
      29,    -1,    66,    -1,    66,    65,    66,    -1,    14,    -1,
      36,    -1,    37,    -1,    15,    -1,    16,    -1,    17,    -1,
      68,    -1,    66,    67,    68,    -1,    21,    -1,    22,    -1,
      70,    -1,    68,    69,    70,    -1,    23,    -1,    24,    -1,
      30,    62,    31,    -1,     3,    -1,    63,    -1,    71,    -1,
      18,    30,    72,    31,    -1,    73,    -1,    -1,    62,    -1,
      62,    32,    73,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    92,    92,    98,   102,   111,   115,   121,   147,   177,
     181,   189,   211,   187,   260,   264,   270,   274,   285,   315,
     341,   340,   370,   376,   383,   386,   393,   397,   401,   405,
     409,   413,   417,   421,   427,   435,   441,   462,   469,   480,
     488,   492,   500,   510,   521,   529,   554,   585,   589,   618,
     622,   626,   630,   634,   638,   644,   649,   682,   686,   692,
     696,   717,   721,   727,   731,   738,   742,   748,   796,   801,
     806,   814
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "INT", "VOID", "WHILE", "IF",
  "THEN", "ELSE", "READ", "WRITE", "FOR", "RETURN", "LE", "GE", "EQ", "NE",
  "ID", "'|'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "';'",
  "'['", "']'", "'('", "')'", "','", "'{'", "'}'", "'='", "'<'", "'>'",
  "$accept", "P", "DL", "DEC", "VARDEC", "typespec", "FUNDEC", "@1", "@2",
  "params", "paramlist", "param", "compoundstmt", "@3",
  "localdeclarations", "statementlist", "statement", "expressionstmt",
  "assignmentstmt", "selectionstmt", "iterationstmt", "returnstmt",
  "readstmt", "writestmt", "expression", "var", "simpleexpression",
  "relop", "additiveexpression", "addop", "term", "multop", "factor",
  "call", "args", "arglist", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   124,
      38,    43,    45,    42,    47,    37,   274,    59,    91,    93,
      40,    41,    44,   123,   125,    61,    60,    62
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    43,
      43,    45,    46,    44,    47,    47,    48,    48,    49,    49,
      51,    50,    52,    52,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    55,    55,    56,    57,    57,    58,
      59,    59,    60,    61,    62,    63,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    70,    70,    70,    70,    71,    72,    72,
      73,    73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     6,     1,
       1,     0,     0,     8,     1,     1,     1,     3,     2,     4,
       0,     5,     2,     0,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     5,     7,     5,
       2,     3,     3,     3,     1,     1,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     3,     1,     1,     1,     4,     1,     0,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    10,     0,     2,     3,     5,     0,     6,     1,
       4,     0,     7,     0,    11,     0,     0,     0,    10,     0,
      12,    15,    16,     8,    18,     0,     0,     0,     0,    17,
      19,    20,    13,    23,    23,     0,    24,    22,     0,    64,
       0,     0,     0,     0,     0,    45,    35,     0,    27,     0,
      24,    26,    30,    28,    29,    31,    32,    33,     0,    65,
      44,    47,    55,    59,    66,     0,     0,    45,     0,     0,
      65,    40,     0,     0,    69,     0,    21,    25,    34,     0,
      49,    52,    53,    54,    57,    58,    50,    51,     0,     0,
      61,    62,     0,     0,     0,    42,    43,    41,     0,    70,
       0,    68,    63,    36,    48,    56,    60,     0,     0,    46,
       0,    67,    39,    37,    71,     0,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,    16,    25,    20,
      21,    22,    48,    33,    36,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    70,    60,    88,    61,    89,
      62,    92,    63,    64,   100,   101
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -68
static const yytype_int8 yypact[] =
{
      24,   -68,   -68,     4,   -68,    24,   -68,   -10,   -68,   -68,
     -68,    26,   -68,    10,   -68,   -12,    53,    -6,     2,    31,
     -68,    15,   -68,   -68,    27,    30,    24,    38,    44,   -68,
     -68,   -68,   -68,    24,    24,    60,     9,   -68,    32,   -68,
      50,    51,    64,     0,     7,   -21,   -68,     0,   -68,    49,
       9,   -68,   -68,   -68,   -68,   -68,   -68,   -68,    57,    54,
     -68,    29,    40,   -68,   -68,     0,     0,    58,    61,    63,
     -68,   -68,    65,     0,     0,    56,   -68,   -68,   -68,     8,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,     0,     0,
     -68,   -68,     0,    62,    66,   -68,   -68,   -68,    67,    59,
      68,   -68,   -68,   -68,    52,    40,   -68,     9,     9,   -68,
       0,   -68,   -68,    76,   -68,     9,   -68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,    89,   -68,    42,    36,   -68,   -68,   -68,   -68,
     -68,    69,    70,   -68,    71,    72,   -67,    21,   -68,   -68,
     -68,   -68,   -68,   -68,   -42,   -36,   -68,   -68,    13,   -68,
      14,   -68,    12,   -68,   -68,    -8
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -15
static const yytype_int8 yytable[] =
{
      59,    69,    72,    39,     9,    75,    68,    73,    11,    74,
      39,    39,    39,    15,    59,    40,    41,    17,    45,    42,
      43,    23,    44,    93,    94,    45,    45,    45,     1,     2,
      47,    98,    99,   -14,    71,    46,    46,    47,    47,    47,
     112,   113,    31,    80,    81,    82,    83,    26,   116,    24,
      84,    85,    19,    12,    13,    27,    14,     1,    18,    12,
      13,    28,    19,    90,    91,    86,    87,    30,    99,    35,
      35,    59,    59,    84,    85,    34,    34,    31,    38,    59,
      65,    66,    67,    76,    78,   115,    73,   102,    95,    79,
      96,   110,    97,   107,    10,    29,   109,   108,    32,   111,
     103,   104,   114,   105,   106,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77
};

static const yytype_int8 yycheck[] =
{
      36,    43,    44,     3,     0,    47,    42,    28,    18,    30,
       3,     3,     3,     3,    50,     6,     7,    29,    18,    10,
      11,    27,    13,    65,    66,    18,    18,    18,     4,     5,
      30,    73,    74,    31,    27,    27,    27,    30,    30,    30,
     107,   108,    33,    14,    15,    16,    17,    32,   115,    18,
      21,    22,    16,    27,    28,    28,    30,     4,     5,    27,
      28,    31,    26,    23,    24,    36,    37,    29,   110,    33,
      34,   107,   108,    21,    22,    33,    34,    33,    18,   115,
      30,    30,    18,    34,    27,     9,    28,    31,    27,    35,
      27,    32,    27,    31,     5,    26,    29,    31,    28,    31,
      79,    88,   110,    89,    92,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    39,    40,    41,    42,    43,    44,     0,
      40,    18,    27,    28,    30,     3,    45,    29,     5,    43,
      47,    48,    49,    27,    18,    46,    32,    28,    31,    49,
      29,    33,    50,    51,    42,    43,    52,    52,    18,     3,
       6,     7,    10,    11,    13,    18,    27,    30,    50,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    66,    68,    70,    71,    30,    30,    18,    63,    62,
      63,    27,    62,    28,    30,    62,    34,    53,    27,    35,
      14,    15,    16,    17,    21,    22,    36,    37,    65,    67,
      23,    24,    69,    62,    62,    27,    27,    27,    62,    62,
      72,    73,    31,    55,    66,    68,    70,    31,    31,    29,
      32,    31,    54,    54,    73,     9,    54
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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
#line 93 "lab5cminustruncate.y"
    {
            program=(yyvsp[(1) - (1)].node);
        }
    break;

  case 3:
#line 99 "lab5cminustruncate.y"
    {
            (yyval.node)=(yyvsp[(1) - (1)].node);
        }
    break;

  case 4:
#line 103 "lab5cminustruncate.y"
    {
            (yyvsp[(1) - (2)].node)->left=(yyvsp[(2) - (2)].node);
            (yyval.node)= (yyvsp[(1) - (2)].node); /*left connect declarations */
            if (mydebug)  ASTprint(0,(yyvsp[(1) - (2)].node));//?????
            if (mydebug) ASTprint(0,(yyvsp[(2) - (2)].node));//?????
        }
    break;

  case 5:
#line 112 "lab5cminustruncate.y"
    {
            (yyval.node)=(yyvsp[(1) - (1)].node);
        }
    break;

  case 6:
#line 116 "lab5cminustruncate.y"
    {
            (yyval.node)=(yyvsp[(1) - (1)].node);
        }
    break;

  case 7:
#line 122 "lab5cminustruncate.y"
    { /* search symbol table for ID
                              insert if OK, then add the pointer from 
                              insertion into the  ASTnode to have reference
                              to the symbol table entry */
                
    //struct SymbTab * Insert(char *name, enum OPERATORS Type, int isafunc, int  level, int mysize, int offset , ASTnode * fparms)
                if (Search((yyvsp[(2) - (3)].string),level,0)==NULL)
                {
                    (yyval.node)=ASTCreateNode(VARDEC);
                    (yyval.node)->name=(yyvsp[(2) - (3)].string); /* this changes to symbol table*/
                    (yyval.node)->operator=(yyvsp[(1) - (3)].operator);
                    
                    
                    (yyval.node)->istype=(yyvsp[(1) - (3)].operator);//!!
                    (yyval.node)->symbol = Insert((yyvsp[(2) - (3)].string),(yyvsp[(1) - (3)].operator),0,level,1,offset,NULL);
                    offset += 1;
                }
                else
                {
                    yyerror((yyvsp[(2) - (3)].string));
                    yyerror("symbol already used ");
                    exit(1);
                }
                //Display();
            }
    break;

  case 8:
#line 148 "lab5cminustruncate.y"
    { /* search symbol table for ID, if not, place in there with size of array*/


                

                if (Search((yyvsp[(2) - (6)].string),level,0)==NULL)
                {
                    (yyval.node)=ASTCreateNode(VARDEC);
                    (yyval.node)->operator=(yyvsp[(1) - (6)].operator);
                    (yyval.node)->name=(yyvsp[(2) - (6)].string); /* this changes to symbol table*/
                    (yyval.node)->value=(yyvsp[(4) - (6)].value); /* remember dimension*/
                    printf("found an array declaration \n");
                    
                    
                    (yyval.node)->istype = (yyvsp[(1) - (6)].operator);//!!
                    (yyval.node)->symbol = Insert((yyvsp[(2) - (6)].string),(yyvsp[(1) - (6)].operator),2,level,(yyvsp[(4) - (6)].value),offset,NULL);//2 is an array!!
                    offset += (yyvsp[(4) - (6)].value);
                }
                else
                {
                    yyerror((yyvsp[(2) - (6)].string));
                    yyerror("symbol already used ");
                    exit(1);
                }
                //Display();
            }
    break;

  case 9:
#line 178 "lab5cminustruncate.y"
    {
                    (yyval.operator) = INTDEC;
                }
    break;

  case 10:
#line 182 "lab5cminustruncate.y"
    {
                    (yyval.operator) = VOIDDEC;
                }
    break;

  case 11:
#line 189 "lab5cminustruncate.y"
    {
    if (Search((yyvsp[(2) - (3)].string),level,0)==NULL)
    {
        //printf("level in function is %d",level);
        goffset = offset;// when meet the function save the offset to goffset
        offset = 2;
        maxoffset=offset;
        Insert((yyvsp[(2) - (3)].string),(yyvsp[(1) - (3)].operator),1,level,0,0,NULL);
    }
    else
    {
        yyerror((yyvsp[(2) - (3)].string));
        yyerror("name already used");
        exit(1);
    }
    //Display();
}
    break;

  case 12:
#line 211 "lab5cminustruncate.y"
    {
        struct SymbTab *p;//!!
        p=Search((yyvsp[(2) - (5)].string),level,0);//!!
        p->fparms=(yyvsp[(5) - (5)].node);//!!
}
    break;

  case 13:
#line 225 "lab5cminustruncate.y"
    { /* search symbol table for ID
                              insert if OK, then add the pointer from
                              insertion into the  ASTnode to have reference
                              to the symbol table entry */

                            /* need to add paramater listing */
                    (yyval.node)=ASTCreateNode(FUNCTIONDEC);
                    (yyval.node)->operator=(yyvsp[(1) - (8)].operator);//????
                    (yyval.node)->name=(yyvsp[(2) - (8)].string); /* this changes to symbol table*/
                    (yyval.node)->right = (yyvsp[(8) - (8)].node); /* compound statement */
                    (yyval.node)->s1 = (yyvsp[(5) - (8)].node);
                    
                    
                    (yyval.node)->istype=(yyvsp[(1) - (8)].operator);//!!??
                    (yyval.node)->symbol=Search((yyvsp[(2) - (8)].string),level,0);//!!??
                    
                     printf("@@@@@the offset in function is %d\n",offset);
                     maxoffset = max(maxoffset,offset);//!!

                     printf("##### MAXOFFSET is ####### %d\n",maxoffset);

                    (yyval.node)->value=maxoffset;

                    offset -= Delete(1);//!!
                    level=0;//!!
                    
                    
                    offset = goffset;// When the function is done, we must reset the main offset to a stored global offset ( I call mine goffset ).
                    
                
                }
    break;

  case 14:
#line 261 "lab5cminustruncate.y"
    {
                (yyval.node) = NULL;
            }
    break;

  case 15:
#line 265 "lab5cminustruncate.y"
    {
                (yyval.node) = (yyvsp[(1) - (1)].node);
            }
    break;

  case 16:
#line 271 "lab5cminustruncate.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 17:
#line 275 "lab5cminustruncate.y"
    {
                    //$1->left=$3;//???
                    ASTattachleft((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));//link together
                    (yyval.node) = (yyvsp[(1) - (3)].node);//????
                    if (mydebug)  ASTprint(0,(yyvsp[(1) - (3)].node));//?????
                    if (mydebug) ASTprint(0,(yyvsp[(3) - (3)].node));//?????
                }
    break;

  case 18:
#line 286 "lab5cminustruncate.y"
    {
                   
                    
                    if (Search((yyvsp[(2) - (2)].string),level+1,0)==NULL)// why is level+1? not 1
                    {
                        
                        
                        (yyval.node)=ASTCreateNode(PARAMEXPR);
                        (yyval.node)->operator=(yyvsp[(1) - (2)].operator);
                        (yyval.node)->name=(yyvsp[(2) - (2)].string);
                        
                        (yyval.node)->istype=(yyvsp[(1) - (2)].operator);//!!
                        (yyval.node)->symbol=Insert((yyvsp[(2) - (2)].string),(yyvsp[(1) - (2)].operator),0,level+1,1,offset,NULL);//all param is level 1
                                                            // why the myzise is 1
                                                            
                        mydebug && printf("Already in param insert %s %d\n",(yyvsp[(2) - (2)].string),level+1);//!!
                        (yyval.node)->value=0;//!! not an array
                        offset += 1;
                    }
                    else
                    {
                        yyerror((yyvsp[(2) - (2)].string));
                        printf("the para has been declared\n");
                        exit(1);
                    }
                    //Display();
                    
                    
                }
    break;

  case 19:
#line 316 "lab5cminustruncate.y"
    {
              
                
                if (Search((yyvsp[(2) - (4)].string),level+1,0)==NULL)
                {
                    (yyval.node)=ASTCreateNode(PARAMEXPR);
                    (yyval.node)->operator=(yyvsp[(1) - (4)].operator);
                    (yyval.node)->name=(yyvsp[(2) - (4)].string);
                    //printf("insert");
                    (yyval.node)->istype=(yyvsp[(1) - (4)].operator);
                    (yyval.node)->symbol=Insert((yyvsp[(2) - (4)].string),(yyvsp[(1) - (4)].operator),2,level+1,1,offset,NULL);//0 scalar 1 function 2 array
                    offset += 1;
                }
                else
                {
                    yyerror((yyvsp[(2) - (4)].string));
                    yyerror("the para array has been declared\n");
                    exit(1);
                }
               // Display();
            }
    break;

  case 20:
#line 341 "lab5cminustruncate.y"
    {
    level++;
    mydebug && printf("BLOCK level is %d\n",level);
    
}
    break;

  case 21:
#line 349 "lab5cminustruncate.y"
    {
                            
                          (yyval.node)=ASTCreateNode(BLOCK);
                          if ((yyvsp[(3) - (5)].node)==NULL) /* no local declarations */
                                (yyval.node)->right=(yyvsp[(4) - (5)].node);
                          else
                           { /* we had some declarations, put them together */
                             ASTattachleft((yyvsp[(3) - (5)].node),(yyvsp[(4) - (5)].node));
                             (yyval.node)->right=(yyvsp[(3) - (5)].node);
                           }
                           
                           Display();  /* display symbol table as per requirement */
                           maxoffset=max(maxoffset,offset);
                            printf("##### MAXOFFSET is ######!!!! %d\n",maxoffset);

                           offset-=Delete(level);  /* decrease the offset count by the size of values allocated at level */
                           level--;  /* down one level */
                           Display();
                       }
    break;

  case 22:
#line 371 "lab5cminustruncate.y"
    {
                            (yyvsp[(1) - (2)].node)->left=(yyvsp[(2) - (2)].node);//?? why use left??
                            (yyval.node)=(yyvsp[(1) - (2)].node);
                        }
    break;

  case 23:
#line 376 "lab5cminustruncate.y"
    {
                            (yyval.node)=NULL;
                        }
    break;

  case 24:
#line 383 "lab5cminustruncate.y"
    {
                    (yyval.node)=NULL;
                }
    break;

  case 25:
#line 387 "lab5cminustruncate.y"
    {
                    (yyvsp[(1) - (2)].node)->left=(yyvsp[(2) - (2)].node);
                    (yyval.node)=(yyvsp[(1) - (2)].node);
                }
    break;

  case 26:
#line 394 "lab5cminustruncate.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                    }
    break;

  case 27:
#line 398 "lab5cminustruncate.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                    }
    break;

  case 28:
#line 402 "lab5cminustruncate.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                    }
    break;

  case 29:
#line 406 "lab5cminustruncate.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                    }
    break;

  case 30:
#line 410 "lab5cminustruncate.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                    }
    break;

  case 31:
#line 414 "lab5cminustruncate.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                    }
    break;

  case 32:
#line 418 "lab5cminustruncate.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                    }
    break;

  case 33:
#line 422 "lab5cminustruncate.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                    }
    break;

  case 34:
#line 428 "lab5cminustruncate.y"
    {
                        //why!!??
                        (yyval.node)=ASTCreateNode(EXPRSTMT);
                        (yyval.node)->istype=(yyvsp[(1) - (2)].node)->istype;
                        (yyval.node)->right=(yyvsp[(1) - (2)].node);
                        //$$=$1;
                    }
    break;

  case 35:
#line 436 "lab5cminustruncate.y"
    {
                (yyval.node)=NULL;
            }
    break;

  case 36:
#line 442 "lab5cminustruncate.y"
    {(yyval.node)=ASTCreateNode(ASSIGN);
                          /* Assignment statement  we leave left alone so that
                             it can be strung with other statements	*/ 
                              (yyval.node)->right=(yyvsp[(1) - (3)].node);
                              (yyval.node)->s1=(yyvsp[(3) - (3)].node);
                              
                              
                              
                              
                              if(((yyvsp[(1) - (3)].node)->istype == VOIDDEC) || ((yyvsp[(1) - (3)].node)->istype != (yyvsp[(3) - (3)].node)->istype))
                              {
                                  yyerror("type error in assignment statement");
                                  exit(1);
                              }
                      }
    break;

  case 37:
#line 463 "lab5cminustruncate.y"
    {
                        (yyval.node)=ASTCreateNode(IFSTMT);
                        (yyval.node)->right=(yyvsp[(3) - (5)].node);
                        (yyval.node)->s1=(yyvsp[(5) - (5)].node);
                        (yyval.node)->s2=NULL;
                    }
    break;

  case 38:
#line 470 "lab5cminustruncate.y"
    {
                        (yyval.node)=ASTCreateNode(IFSTMT);
                        (yyval.node)->right=(yyvsp[(3) - (7)].node);
                        (yyval.node)->s1=(yyvsp[(5) - (7)].node);
                        (yyval.node)->s2=(yyvsp[(7) - (7)].node);//!!
    
                    }
    break;

  case 39:
#line 481 "lab5cminustruncate.y"
    {
                        (yyval.node)=ASTCreateNode(WHILEEXPR);
                        (yyval.node)->right = (yyvsp[(3) - (5)].node);
                        (yyval.node)->s1=(yyvsp[(5) - (5)].node);
                    }
    break;

  case 40:
#line 489 "lab5cminustruncate.y"
    {
                    (yyval.node)=ASTCreateNode(RETURNEXPR);
                }
    break;

  case 41:
#line 493 "lab5cminustruncate.y"
    {
                    (yyval.node)=ASTCreateNode(RETURNEXPR);
                    (yyval.node)->right=(yyvsp[(2) - (3)].node);
                }
    break;

  case 42:
#line 501 "lab5cminustruncate.y"
    { /* make sure variable is in symbol table */
                        /*  Create a ASTnode for this statement on the right */
                (yyval.node)=ASTCreateNode(READSTMT);
                          /* this will be pointer to symbol table */
                (yyval.node)->right=(yyvsp[(2) - (3)].node);//????
            }
    break;

  case 43:
#line 511 "lab5cminustruncate.y"
    { /* make sure variable is in symbol table */
                    (yyval.node)=ASTCreateNode(WRITESTMT);
                    (yyval.node)->right=(yyvsp[(2) - (3)].node);
                          /*  Create a ASTnode for this statement on the right */
                          
                
                }
    break;

  case 44:
#line 522 "lab5cminustruncate.y"
    {
                    (yyval.node)=(yyvsp[(1) - (1)].node);
                }
    break;

  case 45:
#line 530 "lab5cminustruncate.y"
    {
            struct SymbTab *p;
            if ((p=Search((yyvsp[(1) - (1)].string),level,1)) != NULL)
            {  (yyval.node)=ASTCreateNode(IDENT);
                (yyval.node)->name=(yyvsp[(1) - (1)].string); /*change this to pointer to symbol table */
                (yyval.node)->symbol=p;
                (yyval.node)->istype=p->Type;
                if (p->IsAFunc == 2)
                { yyerror((yyvsp[(1) - (1)].string));
                    yyerror("variable is an array, syntax error ");
                    exit(1);
                }
            }
            else
            {   yyerror((yyvsp[(1) - (1)].string));
                yyerror("undeclared variable ");
                exit(1);
            }
            
            
            
        }
    break;

  case 46:
#line 555 "lab5cminustruncate.y"
    {
            struct SymbTab *p;
            if ((p=Search((yyvsp[(1) - (4)].string),level,1)) != NULL)
            {
                (yyval.node)=ASTCreateNode(IDENT);
                (yyval.node)->name=(yyvsp[(1) - (4)].string); /*change this to pointer to symbol table */
                (yyval.node)->right=(yyvsp[(3) - (4)].node);
                (yyval.node)->istype=p->Type;  /* inherit the type */
                /* check to see if the symbol is an array */
                if ( p->IsAFunc == 2) (yyval.node)->symbol=p;  /* either 0 or bigger than 1 */
                else
                {
                    yyerror((yyvsp[(1) - (4)].string));
                    yyerror("not an array, type mismatch");
                    exit(1);
                }
            }
            else
            {
                yyerror((yyvsp[(1) - (4)].string));
                yyerror("undeclared variable ");
                exit(1);
            }
        
        
        
        }
    break;

  case 47:
#line 586 "lab5cminustruncate.y"
    {
                        (yyval.node)=(yyvsp[(1) - (1)].node);
                    }
    break;

  case 48:
#line 590 "lab5cminustruncate.y"
    {
                           
                           
                           if((yyvsp[(1) - (3)].node)->istype != (yyvsp[(3) - (3)].node)->istype)
                           {
                               yyerror("terms type mismatch");
                               exit(1);
                           }
                          
                               
                               (yyval.node)=ASTCreateNode(EXPR);
                               (yyval.node)->right=(yyvsp[(1) - (3)].node);
                               (yyval.node)->operator=(yyvsp[(2) - (3)].operator);
                               (yyval.node)->s1=(yyvsp[(3) - (3)].node);
                           //Creating a temporary variable to hold the intermediate values
                           (yyval.node)->name=CreateTemp();
                           
                           (yyval.node)->istype=(yyvsp[(1) - (3)].node)->istype;//The type is assigned to istype of the ASTnode to keep a track of it.

                           (yyval.node)->symbol=Insert((yyval.node)->name,INTDEC,0,level,1,offset,NULL);
                           
                           offset++;//!!
                           
                       }
    break;

  case 49:
#line 619 "lab5cminustruncate.y"
    {
            (yyval.operator)=LESSTHANEQUAL;
        }
    break;

  case 50:
#line 623 "lab5cminustruncate.y"
    {
            (yyval.operator)=LESSTHAN;
        }
    break;

  case 51:
#line 627 "lab5cminustruncate.y"
    {
            (yyval.operator)=GREATERTHAN;
        }
    break;

  case 52:
#line 631 "lab5cminustruncate.y"
    {
            (yyval.operator)=GREATERTHANEQUAL;
        }
    break;

  case 53:
#line 635 "lab5cminustruncate.y"
    {
            (yyval.operator)=EQUAL;
        }
    break;

  case 54:
#line 639 "lab5cminustruncate.y"
    {
            (yyval.operator)=NOTEQUAL;
        }
    break;

  case 55:
#line 645 "lab5cminustruncate.y"
    {
                            (yyval.node)=(yyvsp[(1) - (1)].node);
                        }
    break;

  case 56:
#line 650 "lab5cminustruncate.y"
    {
                           
                            
                         
                            
                    // here we do the type checkingt
                            
                            if ((yyvsp[(1) - (3)].node)->istype != (yyvsp[(3) - (3)].node)->istype)
                            {
                                yyerror("Additive term Type confilct");
                                exit(1);
                            }
                            
                                (yyval.node)=ASTCreateNode(EXPR);//!!
                                (yyval.node)->right=(yyvsp[(1) - (3)].node);
                                (yyval.node)->operator=(yyvsp[(2) - (3)].operator);
                                (yyval.node)->s1=(yyvsp[(3) - (3)].node);
                                
                                
                                
                                
                                (yyval.node)->name=CreateTemp();
                                (yyval.node)->istype=INTDEC;//!!??
                                (yyval.node)->symbol=Insert((yyval.node)->name,INTDEC,0,level,1,offset,NULL);//!!
                                offset++;//??



                            
                        }
    break;

  case 57:
#line 683 "lab5cminustruncate.y"
    {
            (yyval.operator)=PLUS;
        }
    break;

  case 58:
#line 687 "lab5cminustruncate.y"
    {
            (yyval.operator)=MINUS;
        }
    break;

  case 59:
#line 693 "lab5cminustruncate.y"
    {
            (yyval.node)=(yyvsp[(1) - (1)].node);
        }
    break;

  case 60:
#line 697 "lab5cminustruncate.y"
    {
            //!!
            if ((yyvsp[(1) - (3)].node)->istype != (yyvsp[(3) - (3)].node)->istype)
            {
                yyerror("term type ERROR *mismatch* ");
                exit (1);
            }
            (yyval.node)=ASTCreateNode(EXPR);
            (yyval.node)->right=(yyvsp[(1) - (3)].node);
            (yyval.node)->operator=(yyvsp[(2) - (3)].operator);
            (yyval.node)->s1=(yyvsp[(3) - (3)].node);
            //!!
            (yyval.node)->istype=INTDEC;
            (yyval.node)->name=CreateTemp();
            (yyval.node)->symbol=Insert((yyval.node)->name,INTDEC,0,level,1,offset,NULL);
            offset++;

        }
    break;

  case 61:
#line 718 "lab5cminustruncate.y"
    {
                (yyval.operator)=TIMES;
            }
    break;

  case 62:
#line 722 "lab5cminustruncate.y"
    {
                (yyval.operator)=DIVIDE;
            }
    break;

  case 63:
#line 728 "lab5cminustruncate.y"
    {
                (yyval.node)=(yyvsp[(2) - (3)].node);
            }
    break;

  case 64:
#line 732 "lab5cminustruncate.y"
    {
                (yyval.node)=ASTCreateNode(NUMBER);
                (yyval.node)->value=(yyvsp[(1) - (1)].value);
                
                (yyval.node)->istype=INTDEC;//!!!!!
            }
    break;

  case 65:
#line 739 "lab5cminustruncate.y"
    {
                (yyval.node)=(yyvsp[(1) - (1)].node);
            }
    break;

  case 66:
#line 743 "lab5cminustruncate.y"
    {
                (yyval.node)=(yyvsp[(1) - (1)].node);
            }
    break;

  case 67:
#line 749 "lab5cminustruncate.y"
    {
            
            
            //every time I see ID I need search
            struct SymbTab *p;

            if ((p=Search((yyvsp[(1) - (4)].string),level,1)) == NULL)//!! why is 0
            {
                yyerror((yyvsp[(1) - (4)].string));
                yyerror("Function name is not defined");
                exit(1);
            }
            else
            {
            
                if(p->IsAFunc!=1)
                { //Checking if the variable fund is a function.
                    printf("%d",p->IsAFunc);
                    yyerror((yyvsp[(1) - (4)].string));
                    yyerror("It is not a function");
                    exit(1);
                }
                
                if(CompareFormals(p->fparms,(yyvsp[(3) - (4)].node))!=1)
                { //The formal and actual parameters are compared.
                    
                    yyerror((yyvsp[(1) - (4)].string));
                    yyerror("Number of parameters in actual and formal are not equal or there is type mismatch");
                    exit(1);
                }
                
                
                (yyval.node)=ASTCreateNode(CALL);
                (yyval.node)->right=(yyvsp[(3) - (4)].node);
                (yyval.node)->name=(yyvsp[(1) - (4)].string);  /*symbol table check */
                
                (yyval.node)->symbol=p;
                (yyval.node)->istype=p->Type;
                
                
                
            }
            
            
          }
    break;

  case 68:
#line 797 "lab5cminustruncate.y"
    {
            (yyval.node)=(yyvsp[(1) - (1)].node);
        }
    break;

  case 69:
#line 801 "lab5cminustruncate.y"
    {
            (yyval.node)=NULL;
        }
    break;

  case 70:
#line 807 "lab5cminustruncate.y"
    {
                (yyval.node)=(yyvsp[(1) - (1)].node);
                //!!
                (yyval.node)=ASTCreateNode(ARGLIST);
                (yyval.node)->right=(yyvsp[(1) - (1)].node);
                (yyval.node)->istype=(yyvsp[(1) - (1)].node)->istype;
            }
    break;

  case 71:
#line 815 "lab5cminustruncate.y"
    {
                (yyval.node)=ASTCreateNode(ARGLIST);
                (yyvsp[(1) - (3)].node)->left=(yyvsp[(3) - (3)].node);
                (yyval.node)=(yyvsp[(1) - (3)].node);
                //!!
           }
    break;


/* Line 1267 of yacc.c.  */
#line 2362 "y.tab.c"
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
		      yytoken, &yylval);
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

  if (yyn == YYFINAL)
    YYACCEPT;

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


#line 825 "lab5cminustruncate.y"
	/* end of rules, start of program */
main(int argc, char *argv[]){
    int i;
    int yaccDebug,lexDebug;
    //printf("%d",argc);
    for(i = 1; i < argc; i++){
        if(strcmp(argv[i],"-d")==0){
            yaccDebug = 1;
            lexDebug = 1;
        }
        if(strcmp(argv[i],"-o")==0){
            char s[100];//char *s  is wrong! because it did not give us enough memory size
            //argv[++i]
                      //  printf("I am here 3\n");

            strcpy(s,argv[++i]);
            strcat(s,".asm");
            fp = fopen(s,"w");
            if(fp==NULL)
            exit(1);
        }
    }
    yyparse();
    
    fprintf(stderr,"the input has been syntactically checked\n");
    fprintf(stderr,"Display runned in main\n");
    Display();
    ASTprint(0,program);
    emitASTprint(program,fp);//!!
    //fclose(fp);
}
