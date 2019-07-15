/* A Bison parser, made by GNU Bison 3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lab3.y" /* yacc.c:338  */

    #include <stdio.h>
    // Operators desambiguation
    // RELOP
    #define LT 45           // <
    #define LEQ 46          // <=
    #define GT 47           // >
    #define GEQ 48          // >=
    #define EQ 49           // =
    #define DIF 50          // !=
    // ADOP
    #define PLUS 45         // +
    #define MINUS 46        // -
    // MULTOP
    #define TIMES 57        // *
    #define DIV 58          // /
    #define REM 59          // %
    // Number of tabulations for current line of pretty printer
    int ntabs = 0;

#line 90 "y.tab.c" /* yacc.c:338  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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
    CALL = 258,
    CHAR = 259,
    DO = 260,
    ELSE = 261,
    FALSE = 262,
    FLOAT = 263,
    FOR = 264,
    FUNCTIONS = 265,
    GLOBAL = 266,
    IF = 267,
    INT = 268,
    LOCAL = 269,
    LOGIC = 270,
    MAIN = 271,
    PROGRAM = 272,
    READ = 273,
    RETURN = 274,
    STATEMENTS = 275,
    TRUE = 276,
    VOID = 277,
    WHILE = 278,
    WRITE = 279,
    ID = 280,
    INTCT = 281,
    CHARCT = 282,
    FLOATCT = 283,
    STRING = 284,
    OR = 285,
    AND = 286,
    NOT = 287,
    RELOP = 288,
    ADOP = 289,
    MULTOP = 290,
    NEG = 291,
    ASSIGN = 292,
    OPPAR = 293,
    CLPAR = 294,
    OPBRAK = 295,
    CLBRAK = 296,
    OPBRACE = 297,
    CLBRACE = 298,
    SCOLON = 299,
    COMMA = 300,
    COLON = 301
  };
#endif
/* Tokens.  */
#define CALL 258
#define CHAR 259
#define DO 260
#define ELSE 261
#define FALSE 262
#define FLOAT 263
#define FOR 264
#define FUNCTIONS 265
#define GLOBAL 266
#define IF 267
#define INT 268
#define LOCAL 269
#define LOGIC 270
#define MAIN 271
#define PROGRAM 272
#define READ 273
#define RETURN 274
#define STATEMENTS 275
#define TRUE 276
#define VOID 277
#define WHILE 278
#define WRITE 279
#define ID 280
#define INTCT 281
#define CHARCT 282
#define FLOATCT 283
#define STRING 284
#define OR 285
#define AND 286
#define NOT 287
#define RELOP 288
#define ADOP 289
#define MULTOP 290
#define NEG 291
#define ASSIGN 292
#define OPPAR 293
#define CLPAR 294
#define OPBRAK 295
#define CLBRAK 296
#define OPBRACE 297
#define CLBRACE 298
#define SCOLON 299
#define COMMA 300
#define COLON 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "lab3.y" /* yacc.c:353  */

    char string[128];        // ID and STRING attribute
    int op;                 // For RELOP, ADOP and MULTOPs
    char charVal;           // CHARCT attribute
    int intVal;             // INTCT attribute
    float floatVal;         // FLOATCT attribute

#line 230 "y.tab.c" /* yacc.c:353  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   210

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  108
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  245

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    77,    77,    77,    78,    78,    78,    79,    79,    80,
      80,    81,    82,    83,    84,    85,    86,    86,    86,    87,
      87,    88,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    93,    94,    94,    94,    95,    95,    96,    96,
      96,    97,    98,    98,    98,    99,    99,   100,   100,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   109,   110,   110,   111,   111,
     112,   112,   113,   113,   113,   113,   113,   114,   114,   114,
     115,   115,   115,   115,   116,   116,   116,   117,   117,   118,
     118,   119,   119,   117,   120,   120,   121,   121,   121,   122,
     122,   123,   123,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   128,   129,   129,   130,   130,   130,
     131,   131,   131,   132,   132,   132,   133,   133,   133,   134,
     134,   134,   156,   156,   156,   166,   166,   166,   179,   180,
     181,   182,   216,   217,   218,   218,   219,   219,   219,   220,
     220,   221,   221,   221,   222,   222,   222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CALL", "CHAR", "DO", "ELSE", "FALSE",
  "FLOAT", "FOR", "FUNCTIONS", "GLOBAL", "IF", "INT", "LOCAL", "LOGIC",
  "MAIN", "PROGRAM", "READ", "RETURN", "STATEMENTS", "TRUE", "VOID",
  "WHILE", "WRITE", "ID", "INTCT", "CHARCT", "FLOATCT", "STRING", "OR",
  "AND", "NOT", "RELOP", "ADOP", "MULTOP", "NEG", "ASSIGN", "OPPAR",
  "CLPAR", "OPBRAK", "CLBRAK", "OPBRACE", "CLBRACE", "SCOLON", "COMMA",
  "COLON", "$accept", "Prog", "$@1", "GlobDecls", "$@2", "DeclList",
  "Declaration", "$@3", "Type", "ElemList", "$@4", "Elem", "$@5", "Dims",
  "$@6", "DimList", "Functions", "$@7", "FuncList", "Function", "$@8",
  "Header", "$@9", "$@10", "Params", "ParamList", "$@11", "Parameter",
  "LocDecls", "$@12", "Stats", "$@13", "StatList", "Statement", "$@14",
  "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23",
  "CompStat", "$@24", "IfStat", "$@25", "$@26", "$@27", "$@28", "ElseStat",
  "$@29", "WhileStat", "$@30", "$@31", "$@32", "DoStat", "$@33", "$@34",
  "ForStat", "$@35", "$@36", "$@37", "$@38", "$@39", "$@40", "ReadStat",
  "$@41", "ReadList", "$@42", "WriteStat", "$@43", "WriteList", "$@44",
  "WriteElem", "CallStat", "$@45", "FuncCall", "$@46", "Arguments",
  "ReturnStat", "$@47", "AssignStat", "$@48", "ExprList", "$@49",
  "Expression", "$@50", "AuxExpr1", "$@51", "AuxExpr2", "$@52", "AuxExpr3",
  "$@53", "AuxExpr4", "$@54", "Term", "$@55", "Factor", "$@56", "$@57",
  "Variable", "$@58", "Subscripts", "$@59", "SubscrList", "$@60", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -162

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-162)))

#define YYTABLE_NINF -69

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   -14,    65,    27,  -162,  -162,    81,    47,    84,  -162,
      49,    53,  -162,  -162,  -162,    87,  -162,    17,    82,  -162,
    -162,  -162,  -162,  -162,  -162,    74,  -162,    -6,  -162,    59,
      17,  -162,    40,  -162,  -162,  -162,    79,    66,  -162,  -162,
      94,    72,  -162,  -162,    74,    67,    91,  -162,    89,  -162,
    -162,    80,    85,    17,  -162,   -27,  -162,  -162,  -162,   102,
      99,    95,  -162,  -162,   113,   122,  -162,  -162,  -162,  -162,
    -162,     4,    17,  -162,  -162,   131,   121,   143,   140,   136,
     133,   130,   155,   141,   115,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,   124,  -162,   126,  -162,   127,  -162,
    -162,  -162,   129,  -162,  -162,   123,  -162,  -162,    33,   132,
     134,    63,  -162,  -162,  -162,   128,  -162,   144,  -162,   109,
    -162,  -162,  -162,   148,   130,   130,    93,  -162,  -162,   109,
     135,   137,  -162,  -162,   135,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,   -24,   145,  -162,  -162,    57,   139,  -162,  -162,
     109,   109,   142,   138,    35,  -162,  -162,    44,  -162,   147,
     125,    -4,  -162,  -162,   125,   125,   109,  -162,  -162,  -162,
    -162,  -162,  -162,   -22,   -15,  -162,  -162,   146,  -162,   149,
    -162,   150,     9,  -162,   109,  -162,  -162,    31,   109,   109,
     125,   125,   125,  -162,  -162,   109,   109,  -162,   130,  -162,
      93,  -162,  -162,   152,   151,   147,  -162,   145,  -162,   150,
     139,  -162,    63,    63,    32,    11,  -162,  -162,   125,  -162,
    -162,  -162,  -162,   153,  -162,   150,   109,   172,  -162,   109,
     147,  -162,  -162,    15,    63,  -162,  -162,   130,   157,  -162,
     109,    34,  -162,    63,  -162
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,     4,     0,     0,     5,
       0,     0,     9,    26,     3,     9,     7,     0,    33,     8,
      13,    12,    11,    14,    15,     0,    32,    33,    28,     0,
       0,    19,     0,    16,    29,    30,     0,    21,    10,    17,
      42,     0,    22,    20,     0,     0,     0,    34,     0,    18,
      43,     0,     0,    36,    24,     0,     9,    45,    31,     0,
       0,    37,    38,    23,     0,     9,    47,    41,    35,    39,
      25,    46,     0,    70,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,    40,    47,    72,    51,
      80,    53,    84,    55,     0,    57,     0,    59,     0,    61,
     149,    63,     0,   106,    65,   113,    67,    69,    50,     0,
       0,    50,    87,    94,    99,   151,   115,     0,   112,     0,
      71,    73,    81,     0,     0,     0,     0,   152,   150,     0,
       0,     0,   143,   142,   149,   139,   141,   140,   127,   144,
     146,   148,     0,   120,   123,   126,   129,   132,   135,   138,
       0,     0,     0,     0,     0,    96,   104,     0,   101,   105,
       0,     0,   108,   107,     0,     0,     0,   121,   114,   124,
     130,   133,   136,     0,     0,    85,    88,     0,    97,     0,
     102,   154,     0,   116,   110,   128,   145,     0,     0,     0,
       0,     0,     0,    74,    82,     0,     0,    95,     0,   100,
       0,   153,   155,     0,   111,   117,   147,   122,   125,   131,
     134,   137,    50,    50,     0,     0,    98,   103,     0,   109,
     118,    75,    83,     0,    89,   156,     0,    77,    86,     0,
     119,    78,    76,     0,    50,    90,    79,     0,     0,    91,
       0,     0,    92,    50,    93
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,  -162,  -162,  -162,   154,   -12,  -162,    30,  -162,
    -162,   156,  -162,  -162,  -162,  -162,  -162,  -162,  -162,   158,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,   107,  -162,  -162,
    -162,  -162,    96,  -110,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,   -18,  -162,  -162,    69,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -117,  -162,    -1,
    -162,     0,  -162,    24,  -162,  -155,  -162,     1,  -162,  -161,
    -162,  -162,   -81,  -162,  -162,  -162,  -162,  -162
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     8,    12,    15,    16,    17,    59,    32,
      44,    33,    37,    43,    48,    55,    11,    18,    27,    28,
      40,    29,    30,    53,    60,    61,    72,    62,    46,    56,
      52,    66,    71,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    87,    89,   109,   150,   212,
     227,   232,   234,    91,   110,   151,   213,    93,   111,   195,
      95,   124,   196,   229,   237,   240,   243,    97,   125,   154,
     198,    99,   126,   157,   200,   158,   104,   117,   141,   184,
     203,   106,   119,   101,   129,   204,   226,   159,   188,   143,
     189,   144,   164,   145,   190,   146,   191,   147,   192,   148,
     165,   166,   149,   115,   128,   160,   182,   218
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     102,   123,   142,    19,   186,   181,   167,   -64,   167,   -54,
      26,     3,   161,   -56,    63,   167,   -50,   193,    64,     1,
     168,    20,   -58,   -66,   194,    21,   167,   -52,   -60,   -62,
      22,   211,    23,   173,   174,   209,   -64,   -27,   -54,    24,
     183,   167,   -56,   153,   155,   167,    73,    25,   -68,   187,
     201,   -58,   -66,    19,   202,   224,   -52,   -60,   -62,   235,
      36,   167,   167,   225,   167,     4,   -64,   205,   -54,     5,
     206,   223,   -56,   242,   177,    73,   120,   -68,   214,   215,
     178,   -58,   -66,   179,    38,    39,   -52,   -60,   -62,   180,
     170,   171,     7,     9,    10,    13,    14,    -6,    26,    31,
     132,    35,   221,   222,    41,    73,    42,   -68,    45,   230,
      47,    51,   233,    50,   133,    54,   132,   216,   134,   135,
     136,   137,   156,   241,   236,   138,    57,    67,    58,   139,
     133,   140,   132,   244,   134,   135,   136,   137,    68,    70,
      69,   138,   -44,    88,    90,   139,   133,   140,    92,    94,
     134,   135,   136,   137,    96,   100,   238,    98,   103,   107,
     105,   139,   112,   140,   113,   114,   116,   118,   127,   130,
     121,   152,   122,   162,   172,   176,   169,   167,   231,    86,
     175,   163,   217,   108,   171,    34,   131,   207,   185,   208,
     197,   219,   210,   199,   239,     0,   220,   228,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65
};

static const yytype_int16 yycheck[] =
{
      81,   111,   119,    15,   165,   160,    30,     3,    30,     5,
      16,    25,   129,     9,    41,    30,    12,    39,    45,    17,
      44,     4,    18,    19,    39,     8,    30,    23,    24,    25,
      13,   192,    15,   150,   151,   190,     3,    43,     5,    22,
      44,    30,     9,   124,   125,    30,    42,    17,    44,   166,
      41,    18,    19,    65,    45,    44,    23,    24,    25,    44,
      30,    30,    30,   218,    30,     0,     3,   184,     5,    42,
      39,    39,     9,    39,    39,    42,    43,    44,   195,   196,
      45,    18,    19,    39,    44,    45,    23,    24,    25,    45,
      33,    34,    11,    46,    10,    46,    43,    10,    16,    25,
       7,    42,   212,   213,    25,    42,    40,    44,    14,   226,
      38,    20,   229,    46,    21,    26,     7,   198,    25,    26,
      27,    28,    29,   240,   234,    32,    46,    25,    43,    36,
      21,    38,     7,   243,    25,    26,    27,    28,    39,    26,
      45,    32,    20,    12,    23,    36,    21,    38,     5,     9,
      25,    26,    27,    28,    18,    25,   237,    24,     3,    44,
      19,    36,    38,    38,    38,    38,    37,    44,    40,    25,
      38,    23,    38,    38,    35,    37,    31,    30,     6,    72,
      38,    44,   200,    87,    34,    27,   117,   188,   164,   189,
      44,    39,   191,    44,    37,    -1,    45,    44,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    48,    25,     0,    42,    49,    11,    50,    46,
      10,    63,    51,    46,    43,    52,    53,    54,    64,    53,
       4,     8,    13,    15,    22,    55,    16,    65,    66,    68,
      69,    25,    56,    58,    66,    42,    55,    59,    44,    45,
      67,    25,    40,    60,    57,    14,    75,    38,    61,    58,
      46,    20,    77,    70,    26,    62,    76,    46,    43,    55,
      71,    72,    74,    41,    45,    52,    78,    25,    39,    45,
      26,    79,    73,    42,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    74,    92,    12,    93,
      23,   100,     5,   104,     9,   107,    18,   114,    24,   118,
      25,   130,   149,     3,   123,    19,   128,    44,    79,    94,
     101,   105,    38,    38,    38,   150,    37,   124,    44,   129,
      43,    38,    38,    80,   108,   115,   119,    40,   151,   131,
      25,   125,     7,    21,    25,    26,    27,    28,    32,    36,
      38,   125,   134,   136,   138,   140,   142,   144,   146,   149,
      95,   102,    23,   149,   116,   149,    29,   120,   122,   134,
     152,   134,    38,    44,   139,   147,   148,    30,    44,    31,
      33,    34,    35,   134,   134,    38,    37,    39,    45,    39,
      45,   142,   153,    44,   126,   140,   146,   134,   135,   137,
     141,   143,   145,    39,    39,   106,   109,    44,   117,    44,
     121,    41,    45,   127,   132,   134,    39,   136,   138,   142,
     144,   146,    96,   103,   134,   134,   149,   122,   154,    39,
      45,    80,    80,    39,    44,   142,   133,    97,    44,   110,
     134,     6,    98,   134,    99,    44,    80,   111,   149,    37,
     112,   134,    39,   113,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    49,    48,    50,    51,    50,    52,    52,    54,
      53,    55,    55,    55,    55,    55,    56,    57,    56,    59,
      58,    60,    61,    60,    62,    62,    64,    63,    65,    65,
      67,    66,    68,    69,    70,    68,    71,    71,    72,    73,
      72,    74,    75,    76,    75,    78,    77,    79,    79,    80,
      81,    80,    82,    80,    83,    80,    84,    80,    85,    80,
      86,    80,    87,    80,    88,    80,    89,    80,    90,    80,
      92,    91,    94,    95,    96,    97,    93,    98,    99,    98,
     101,   102,   103,   100,   105,   106,   104,   108,   109,   110,
     111,   112,   113,   107,   115,   114,   116,   117,   116,   119,
     118,   120,   121,   120,   122,   122,   124,   123,   126,   125,
     127,   127,   128,   129,   128,   131,   130,   132,   133,   132,
     134,   135,   134,   136,   137,   136,   138,   139,   138,   140,
     141,   140,   142,   143,   142,   144,   145,   144,   146,   146,
     146,   146,   146,   146,   147,   146,   148,   146,   146,   150,
     149,   151,   152,   151,   153,   154,   153
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     0,     0,     4,     1,     2,     0,
       4,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       3,     0,     0,     4,     1,     3,     0,     4,     1,     2,
       0,     6,     1,     0,     0,     7,     0,     1,     1,     0,
       4,     2,     0,     0,     4,     0,     4,     0,     2,     1,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     2,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     2,
       0,     4,     0,     0,     0,     0,    10,     0,     0,     3,
       0,     0,     0,     8,     0,     0,     9,     0,     0,     0,
       0,     0,     0,    19,     0,     6,     1,     0,     4,     0,
       6,     1,     0,     4,     1,     1,     0,     4,     0,     5,
       0,     1,     2,     0,     4,     0,     5,     1,     0,     4,
       1,     0,     4,     1,     0,     4,     1,     0,     3,     1,
       0,     4,     1,     0,     4,     1,     0,     4,     1,     1,
       1,     1,     1,     1,     0,     3,     0,     4,     1,     0,
       3,     0,     0,     4,     1,     0,     4
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
    default: /* Avoid compiler warnings. */
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
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

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
                  (unsigned long) yystacksize));

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
#line 77 "lab3.y" /* yacc.c:1645  */
    {printf("program %s {\n\n", (yyvsp[-1].string));}
#line 1508 "y.tab.c" /* yacc.c:1645  */
    break;

  case 3:
#line 77 "lab3.y" /* yacc.c:1645  */
    {printf("}\n");}
#line 1514 "y.tab.c" /* yacc.c:1645  */
    break;

  case 5:
#line 78 "lab3.y" /* yacc.c:1645  */
    {print_tabs(); printf("global%c\n", ':'); ntabs++;}
#line 1520 "y.tab.c" /* yacc.c:1645  */
    break;

  case 6:
#line 78 "lab3.y" /* yacc.c:1645  */
    {ntabs--; printf("\n");}
#line 1526 "y.tab.c" /* yacc.c:1645  */
    break;

  case 9:
#line 80 "lab3.y" /* yacc.c:1645  */
    {print_tabs();}
#line 1532 "y.tab.c" /* yacc.c:1645  */
    break;

  case 10:
#line 80 "lab3.y" /* yacc.c:1645  */
    {printf(";\n");}
#line 1538 "y.tab.c" /* yacc.c:1645  */
    break;

  case 11:
#line 81 "lab3.y" /* yacc.c:1645  */
    {printf("int");}
#line 1544 "y.tab.c" /* yacc.c:1645  */
    break;

  case 12:
#line 82 "lab3.y" /* yacc.c:1645  */
    {printf("float");}
#line 1550 "y.tab.c" /* yacc.c:1645  */
    break;

  case 13:
#line 83 "lab3.y" /* yacc.c:1645  */
    {printf("char");}
#line 1556 "y.tab.c" /* yacc.c:1645  */
    break;

  case 14:
#line 84 "lab3.y" /* yacc.c:1645  */
    {printf("logic");}
#line 1562 "y.tab.c" /* yacc.c:1645  */
    break;

  case 15:
#line 85 "lab3.y" /* yacc.c:1645  */
    {printf("void");}
#line 1568 "y.tab.c" /* yacc.c:1645  */
    break;

  case 17:
#line 86 "lab3.y" /* yacc.c:1645  */
    {printf(",");}
#line 1574 "y.tab.c" /* yacc.c:1645  */
    break;

  case 19:
#line 87 "lab3.y" /* yacc.c:1645  */
    {printf(" %s", (yyvsp[0].string));}
#line 1580 "y.tab.c" /* yacc.c:1645  */
    break;

  case 22:
#line 88 "lab3.y" /* yacc.c:1645  */
    {printf("[");}
#line 1586 "y.tab.c" /* yacc.c:1645  */
    break;

  case 23:
#line 88 "lab3.y" /* yacc.c:1645  */
    {printf("]");}
#line 1592 "y.tab.c" /* yacc.c:1645  */
    break;

  case 24:
#line 89 "lab3.y" /* yacc.c:1645  */
    {printf("%d", (yyvsp[0].intVal));}
#line 1598 "y.tab.c" /* yacc.c:1645  */
    break;

  case 25:
#line 89 "lab3.y" /* yacc.c:1645  */
    {printf(", %d", (yyvsp[0].intVal));}
#line 1604 "y.tab.c" /* yacc.c:1645  */
    break;

  case 26:
#line 90 "lab3.y" /* yacc.c:1645  */
    {print_tabs(); printf("functions%c\n", ':'); ntabs++;}
#line 1610 "y.tab.c" /* yacc.c:1645  */
    break;

  case 27:
#line 90 "lab3.y" /* yacc.c:1645  */
    {ntabs--;}
#line 1616 "y.tab.c" /* yacc.c:1645  */
    break;

  case 28:
#line 91 "lab3.y" /* yacc.c:1645  */
    {printf("\n");}
#line 1622 "y.tab.c" /* yacc.c:1645  */
    break;

  case 29:
#line 91 "lab3.y" /* yacc.c:1645  */
    {printf("\n");}
#line 1628 "y.tab.c" /* yacc.c:1645  */
    break;

  case 30:
#line 92 "lab3.y" /* yacc.c:1645  */
    {printf(" {\n");}
#line 1634 "y.tab.c" /* yacc.c:1645  */
    break;

  case 31:
#line 92 "lab3.y" /* yacc.c:1645  */
    {print_tabs(); printf("}\n");}
#line 1640 "y.tab.c" /* yacc.c:1645  */
    break;

  case 32:
#line 93 "lab3.y" /* yacc.c:1645  */
    {printf("main");}
#line 1646 "y.tab.c" /* yacc.c:1645  */
    break;

  case 33:
#line 94 "lab3.y" /* yacc.c:1645  */
    {print_tabs();}
#line 1652 "y.tab.c" /* yacc.c:1645  */
    break;

  case 34:
#line 94 "lab3.y" /* yacc.c:1645  */
    {printf(" %s(", (yyvsp[-1].string));}
#line 1658 "y.tab.c" /* yacc.c:1645  */
    break;

  case 35:
#line 94 "lab3.y" /* yacc.c:1645  */
    {printf(")"); }
#line 1664 "y.tab.c" /* yacc.c:1645  */
    break;

  case 39:
#line 96 "lab3.y" /* yacc.c:1645  */
    {printf(", ");}
#line 1670 "y.tab.c" /* yacc.c:1645  */
    break;

  case 41:
#line 97 "lab3.y" /* yacc.c:1645  */
    {printf(" %s", (yyvsp[0].string));}
#line 1676 "y.tab.c" /* yacc.c:1645  */
    break;

  case 43:
#line 98 "lab3.y" /* yacc.c:1645  */
    {print_tabs(); printf("local%c\n", ':'); ntabs++;}
#line 1682 "y.tab.c" /* yacc.c:1645  */
    break;

  case 44:
#line 98 "lab3.y" /* yacc.c:1645  */
    {ntabs--;}
#line 1688 "y.tab.c" /* yacc.c:1645  */
    break;

  case 45:
#line 99 "lab3.y" /* yacc.c:1645  */
    {print_tabs(); printf("statements%c\n", ':'); ntabs++;}
#line 1694 "y.tab.c" /* yacc.c:1645  */
    break;

  case 46:
#line 99 "lab3.y" /* yacc.c:1645  */
    {ntabs--;}
#line 1700 "y.tab.c" /* yacc.c:1645  */
    break;

  case 50:
#line 102 "lab3.y" /* yacc.c:1645  */
    {print_tabs();}
#line 1706 "y.tab.c" /* yacc.c:1645  */
    break;

  case 52:
#line 103 "lab3.y" /* yacc.c:1645  */
    {print_tabs();}
#line 1712 "y.tab.c" /* yacc.c:1645  */
    break;

  case 54:
#line 104 "lab3.y" /* yacc.c:1645  */
    {print_tabs();}
#line 1718 "y.tab.c" /* yacc.c:1645  */
    break;

  case 56:
#line 105 "lab3.y" /* yacc.c:1645  */
    {print_tabs();}
#line 1724 "y.tab.c" /* yacc.c:1645  */
    break;

  case 58:
#line 106 "lab3.y" /* yacc.c:1645  */
    {print_tabs();}
#line 1730 "y.tab.c" /* yacc.c:1645  */
    break;

  case 59:
#line 106 "lab3.y" /* yacc.c:1645  */
    {printf("\n");}
#line 1736 "y.tab.c" /* yacc.c:1645  */
    break;

  case 60:
#line 107 "lab3.y" /* yacc.c:1645  */
    {print_tabs();}
#line 1742 "y.tab.c" /* yacc.c:1645  */
    break;

  case 61:
#line 107 "lab3.y" /* yacc.c:1645  */
    {printf("\n");}
#line 1748 "y.tab.c" /* yacc.c:1645  */
    break;

  case 62:
#line 108 "lab3.y" /* yacc.c:1645  */
    {print_tabs();}
#line 1754 "y.tab.c" /* yacc.c:1645  */
    break;

  case 63:
#line 108 "lab3.y" /* yacc.c:1645  */
    {printf("\n");}
#line 1760 "y.tab.c" /* yacc.c:1645  */
    break;

  case 64:
#line 109 "lab3.y" /* yacc.c:1645  */
    {print_tabs();}
#line 1766 "y.tab.c" /* yacc.c:1645  */
    break;

  case 65:
#line 109 "lab3.y" /* yacc.c:1645  */
    {printf("\n");}
#line 1772 "y.tab.c" /* yacc.c:1645  */
    break;

  case 66:
#line 110 "lab3.y" /* yacc.c:1645  */
    {print_tabs();}
#line 1778 "y.tab.c" /* yacc.c:1645  */
    break;

  case 67:
#line 110 "lab3.y" /* yacc.c:1645  */
    {printf("\n");}
#line 1784 "y.tab.c" /* yacc.c:1645  */
    break;

  case 68:
#line 111 "lab3.y" /* yacc.c:1645  */
    {print_tabs();}
#line 1790 "y.tab.c" /* yacc.c:1645  */
    break;

  case 69:
#line 111 "lab3.y" /* yacc.c:1645  */
    {printf("\n");}
#line 1796 "y.tab.c" /* yacc.c:1645  */
    break;

  case 70:
#line 112 "lab3.y" /* yacc.c:1645  */
    {ntabs--; print_tabs(); ntabs++; printf("{\n");}
#line 1802 "y.tab.c" /* yacc.c:1645  */
    break;

  case 71:
#line 112 "lab3.y" /* yacc.c:1645  */
    {ntabs--; print_tabs(); ntabs++; printf("}\n");}
#line 1808 "y.tab.c" /* yacc.c:1645  */
    break;

  case 72:
#line 113 "lab3.y" /* yacc.c:1645  */
    {printf("if");}
#line 1814 "y.tab.c" /* yacc.c:1645  */
    break;

  case 73:
#line 113 "lab3.y" /* yacc.c:1645  */
    {printf(" (");}
#line 1820 "y.tab.c" /* yacc.c:1645  */
    break;

  case 74:
#line 113 "lab3.y" /* yacc.c:1645  */
    {printf(")\n"); ntabs++;}
#line 1826 "y.tab.c" /* yacc.c:1645  */
    break;

  case 75:
#line 113 "lab3.y" /* yacc.c:1645  */
    {ntabs--;}
#line 1832 "y.tab.c" /* yacc.c:1645  */
    break;

  case 78:
#line 114 "lab3.y" /* yacc.c:1645  */
    {print_tabs(); printf("else\n"); ntabs++;}
#line 1838 "y.tab.c" /* yacc.c:1645  */
    break;

  case 79:
#line 114 "lab3.y" /* yacc.c:1645  */
    {ntabs--;}
#line 1844 "y.tab.c" /* yacc.c:1645  */
    break;

  case 80:
#line 115 "lab3.y" /* yacc.c:1645  */
    {printf("while");}
#line 1850 "y.tab.c" /* yacc.c:1645  */
    break;

  case 81:
#line 115 "lab3.y" /* yacc.c:1645  */
    {printf(" (");}
#line 1856 "y.tab.c" /* yacc.c:1645  */
    break;

  case 82:
#line 115 "lab3.y" /* yacc.c:1645  */
    {printf(")\n"); ntabs++;}
#line 1862 "y.tab.c" /* yacc.c:1645  */
    break;

  case 83:
#line 115 "lab3.y" /* yacc.c:1645  */
    {ntabs--;}
#line 1868 "y.tab.c" /* yacc.c:1645  */
    break;

  case 84:
#line 116 "lab3.y" /* yacc.c:1645  */
    {printf("do\n"); ntabs++;}
#line 1874 "y.tab.c" /* yacc.c:1645  */
    break;

  case 85:
#line 116 "lab3.y" /* yacc.c:1645  */
    {ntabs--; print_tabs(); printf("while (");}
#line 1880 "y.tab.c" /* yacc.c:1645  */
    break;

  case 86:
#line 116 "lab3.y" /* yacc.c:1645  */
    {printf(");\n");}
#line 1886 "y.tab.c" /* yacc.c:1645  */
    break;

  case 87:
#line 117 "lab3.y" /* yacc.c:1645  */
    {printf("for (");}
#line 1892 "y.tab.c" /* yacc.c:1645  */
    break;

  case 88:
#line 117 "lab3.y" /* yacc.c:1645  */
    {printf(" <- ");}
#line 1898 "y.tab.c" /* yacc.c:1645  */
    break;

  case 89:
#line 118 "lab3.y" /* yacc.c:1645  */
    {printf("; ");}
#line 1904 "y.tab.c" /* yacc.c:1645  */
    break;

  case 90:
#line 118 "lab3.y" /* yacc.c:1645  */
    {printf("; ");}
#line 1910 "y.tab.c" /* yacc.c:1645  */
    break;

  case 91:
#line 119 "lab3.y" /* yacc.c:1645  */
    {printf(" <- ");}
#line 1916 "y.tab.c" /* yacc.c:1645  */
    break;

  case 92:
#line 119 "lab3.y" /* yacc.c:1645  */
    {printf(")\n"); ntabs++;}
#line 1922 "y.tab.c" /* yacc.c:1645  */
    break;

  case 93:
#line 119 "lab3.y" /* yacc.c:1645  */
    {ntabs--;}
#line 1928 "y.tab.c" /* yacc.c:1645  */
    break;

  case 94:
#line 120 "lab3.y" /* yacc.c:1645  */
    {printf("read(");}
#line 1934 "y.tab.c" /* yacc.c:1645  */
    break;

  case 95:
#line 120 "lab3.y" /* yacc.c:1645  */
    {printf(");");}
#line 1940 "y.tab.c" /* yacc.c:1645  */
    break;

  case 97:
#line 121 "lab3.y" /* yacc.c:1645  */
    {printf(", ");}
#line 1946 "y.tab.c" /* yacc.c:1645  */
    break;

  case 99:
#line 122 "lab3.y" /* yacc.c:1645  */
    {printf("write(");}
#line 1952 "y.tab.c" /* yacc.c:1645  */
    break;

  case 100:
#line 122 "lab3.y" /* yacc.c:1645  */
    {printf(");");}
#line 1958 "y.tab.c" /* yacc.c:1645  */
    break;

  case 102:
#line 123 "lab3.y" /* yacc.c:1645  */
    {printf(", ");}
#line 1964 "y.tab.c" /* yacc.c:1645  */
    break;

  case 104:
#line 124 "lab3.y" /* yacc.c:1645  */
    {printf("%s", (yyvsp[0].string));}
#line 1970 "y.tab.c" /* yacc.c:1645  */
    break;

  case 106:
#line 125 "lab3.y" /* yacc.c:1645  */
    {printf("call ");}
#line 1976 "y.tab.c" /* yacc.c:1645  */
    break;

  case 107:
#line 125 "lab3.y" /* yacc.c:1645  */
    {printf(";");}
#line 1982 "y.tab.c" /* yacc.c:1645  */
    break;

  case 108:
#line 126 "lab3.y" /* yacc.c:1645  */
    {printf("%s(", (yyvsp[-1].string));}
#line 1988 "y.tab.c" /* yacc.c:1645  */
    break;

  case 109:
#line 126 "lab3.y" /* yacc.c:1645  */
    {printf(")");}
#line 1994 "y.tab.c" /* yacc.c:1645  */
    break;

  case 112:
#line 128 "lab3.y" /* yacc.c:1645  */
    {printf("return;\n");}
#line 2000 "y.tab.c" /* yacc.c:1645  */
    break;

  case 113:
#line 128 "lab3.y" /* yacc.c:1645  */
    {printf("return ");}
#line 2006 "y.tab.c" /* yacc.c:1645  */
    break;

  case 114:
#line 128 "lab3.y" /* yacc.c:1645  */
    {printf(";\n");}
#line 2012 "y.tab.c" /* yacc.c:1645  */
    break;

  case 115:
#line 129 "lab3.y" /* yacc.c:1645  */
    {printf(" <- ");}
#line 2018 "y.tab.c" /* yacc.c:1645  */
    break;

  case 116:
#line 129 "lab3.y" /* yacc.c:1645  */
    {printf(";");}
#line 2024 "y.tab.c" /* yacc.c:1645  */
    break;

  case 118:
#line 130 "lab3.y" /* yacc.c:1645  */
    {printf(", ");}
#line 2030 "y.tab.c" /* yacc.c:1645  */
    break;

  case 121:
#line 131 "lab3.y" /* yacc.c:1645  */
    {printf(" || ");}
#line 2036 "y.tab.c" /* yacc.c:1645  */
    break;

  case 124:
#line 132 "lab3.y" /* yacc.c:1645  */
    {printf(" && ");}
#line 2042 "y.tab.c" /* yacc.c:1645  */
    break;

  case 127:
#line 133 "lab3.y" /* yacc.c:1645  */
    {printf("!");}
#line 2048 "y.tab.c" /* yacc.c:1645  */
    break;

  case 130:
#line 134 "lab3.y" /* yacc.c:1645  */
    {
    switch ((yyvsp[0].op)) {
        case LEQ:
            printf(" <= ");
            break;
        case LT:
            printf(" < ");
            break;
        case GEQ:
            printf(" >= ");
            break;
        case GT:
            printf(" > ");
            break;
        case EQ:
            printf(" = ");
            break;
        case DIF:
            printf(" != ");
            break;
    }
}
#line 2075 "y.tab.c" /* yacc.c:1645  */
    break;

  case 133:
#line 156 "lab3.y" /* yacc.c:1645  */
    {
    switch ((yyvsp[0].op)) {
        case PLUS:
            printf(" + ");
            break;
        case MINUS:
            printf(" - ");
            break;
    }
}
#line 2090 "y.tab.c" /* yacc.c:1645  */
    break;

  case 136:
#line 166 "lab3.y" /* yacc.c:1645  */
    {
    switch ((yyvsp[0].op)) {
        case TIMES:
            printf("*");
            break;
        case DIV:
            printf("/");
            break;
        case REM:
            printf("%%");
            break;
    }
}
#line 2108 "y.tab.c" /* yacc.c:1645  */
    break;

  case 139:
#line 180 "lab3.y" /* yacc.c:1645  */
    {printf("%d", (yyvsp[0].intVal));}
#line 2114 "y.tab.c" /* yacc.c:1645  */
    break;

  case 140:
#line 181 "lab3.y" /* yacc.c:1645  */
    {printf("%g", (yyvsp[0].floatVal));}
#line 2120 "y.tab.c" /* yacc.c:1645  */
    break;

  case 141:
#line 182 "lab3.y" /* yacc.c:1645  */
    {
                printf("'");
                switch ((yyvsp[0].charVal)) {
                    case '\0':
                        printf("\\0");
                        break;
                    case '\a':
                        printf("\\a");
                        break;
                    case '\b':
                        printf("\\b");
                        break;
                    case '\f':
                        printf("\\f");
                        break;
                    case '\n':
                        printf("\\n");
                        break;
                    case '\r':
                        printf("\\r");
                        break;
                    case '\t':
                        printf("\\t");
                        break;
                    case '\v':
                        printf("\\v");
                        break;
                    case '\'':
                        printf("\\'");
                    default:
                        printf("%c", (yyvsp[0].charVal));
                }
                printf("'");
            }
#line 2159 "y.tab.c" /* yacc.c:1645  */
    break;

  case 142:
#line 216 "lab3.y" /* yacc.c:1645  */
    {printf("true");}
#line 2165 "y.tab.c" /* yacc.c:1645  */
    break;

  case 143:
#line 217 "lab3.y" /* yacc.c:1645  */
    {printf("false");}
#line 2171 "y.tab.c" /* yacc.c:1645  */
    break;

  case 144:
#line 218 "lab3.y" /* yacc.c:1645  */
    {printf("~");}
#line 2177 "y.tab.c" /* yacc.c:1645  */
    break;

  case 146:
#line 219 "lab3.y" /* yacc.c:1645  */
    {printf("(");}
#line 2183 "y.tab.c" /* yacc.c:1645  */
    break;

  case 147:
#line 219 "lab3.y" /* yacc.c:1645  */
    {printf(")");}
#line 2189 "y.tab.c" /* yacc.c:1645  */
    break;

  case 149:
#line 220 "lab3.y" /* yacc.c:1645  */
    {printf("%s", (yyvsp[0].string));}
#line 2195 "y.tab.c" /* yacc.c:1645  */
    break;

  case 152:
#line 221 "lab3.y" /* yacc.c:1645  */
    {printf("[");}
#line 2201 "y.tab.c" /* yacc.c:1645  */
    break;

  case 153:
#line 221 "lab3.y" /* yacc.c:1645  */
    {printf("]");}
#line 2207 "y.tab.c" /* yacc.c:1645  */
    break;

  case 155:
#line 222 "lab3.y" /* yacc.c:1645  */
    {printf(", ");}
#line 2213 "y.tab.c" /* yacc.c:1645  */
    break;


#line 2217 "y.tab.c" /* yacc.c:1645  */
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
#line 224 "lab3.y" /* yacc.c:1903  */


#include "lex.yy.c"

int yyerror ( char * msg ) {
    fprintf ( stdout, "%s\n", msg ) ;
}

void print_tabs() {
    for (int i=0; i<ntabs; i++)
        printf("\t");
}

int main() {
	yyparse();
	return 0;
}
