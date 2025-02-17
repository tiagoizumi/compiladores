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
#line 1 "parser.y"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"

extern int yylineno;  // Variável do Flex que conta as linhas
extern char *yytext;  // Token atual    
void yyerror(const char *s);
int yylex();
#define MAX_SCOPE_DEPTH 10

char currScope[30] = "main";  // Current scope
char scopeStack[MAX_SCOPE_DEPTH][30];  // Stack to track nested scopes
int scopeDepth = 0;  // Current depth of the scope stack

// Push the current scope onto the stack
void pushScope() {
    if (scopeDepth < MAX_SCOPE_DEPTH) {
        strcpy(scopeStack[scopeDepth], currScope);
        scopeDepth++;
    } else {
        fprintf(stderr, "Scope stack overflow!\n");
        exit(1);
    }
}

// Pop the previous scope from the stack
void popScope() {
    if (scopeDepth > 0) {
        scopeDepth--;
        strcpy(currScope, scopeStack[scopeDepth]);
    } else {
        fprintf(stderr, "Scope stack underflow!\n");
        exit(1);
    }
}


typedef struct node {
    char *tipo;           // Tipo do nó (ex: "int", "float", "var", "func")
    char *identificador;  // Nome do identificador (ex: nome de uma variável ou função)
    struct node *filho1;
    struct node *filho2;
    struct node *filho3;
    struct node *filho4;
    struct node *filho5;
    struct node *filho6;
    struct node *filho7;
    struct node *filho8;
    char *valor;          // Valor literal, se houver
} Node;


Node* cria_no(char *tipo, char *valor,char *identificador, Node *filho1, Node *filho2, Node *filho3, Node *filho4, Node *filho5, Node *filho6, Node *filho7, Node *filho8) {
    Node* novo_no = (Node*)malloc(sizeof(Node));
    if (novo_no == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(1);  // Ou retornar NULL e tratar o erro na função que chamou
    }
    novo_no->tipo = tipo;
    novo_no->valor = valor;
    novo_no->identificador = identificador;
    novo_no->filho1 = filho1;
    novo_no->filho2 = filho2;    
    novo_no->filho3 = filho3;
    novo_no->filho4 = filho4;
    novo_no->filho5 = filho5;
    novo_no->filho6 = filho6;
    novo_no->filho7 = filho7;
    novo_no->filho8 = filho8;
    return novo_no;
}

Node* folha(char *tipo, char *identificador) {
    Node* novo_no = (Node*)malloc(sizeof(Node));
    if (novo_no == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(1);
    }
    novo_no->tipo = strdup(tipo); // Usar strdup para alocar cópia
    novo_no->identificador = identificador ? strdup(identificador) : NULL;
    novo_no->valor = NULL;
    novo_no->filho1 = NULL;
    novo_no->filho2 = NULL;    
    novo_no->filho3 = NULL;
    novo_no->filho4 = NULL;
    novo_no->filho5 = NULL;
    novo_no->filho6 = NULL;
    novo_no->filho7 = NULL;
    novo_no->filho8 = NULL;
    return novo_no;
}

void imprime_arvore(Node *no, int nivel) {
    if (no == NULL) return;

    for (int i = 0; i < nivel; i++) {
        printf("| ");
    }
    printf("%s", no->tipo);
    if (no->identificador) {
        printf(": %s", no->identificador);
    }
    printf("\n");

    imprime_arvore(no->filho1, nivel + 1);
    imprime_arvore(no->filho2, nivel + 1);
    imprime_arvore(no->filho3, nivel + 1);
    imprime_arvore(no->filho4, nivel + 1);
    imprime_arvore(no->filho5, nivel + 1);
    imprime_arvore(no->filho6, nivel + 1);
    imprime_arvore(no->filho7, nivel + 1);
    imprime_arvore(no->filho8, nivel + 1);

}

// Definindo YYSTYPE como ponteiro para Node
#define YYSTYPE Node*

Node *raiz_arvore;  // Variável global que armazenará a raiz da árvore


#line 195 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_THEN = 3,                       /* THEN  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_RETURN = 7,                     /* RETURN  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_ID = 10,                        /* ID  */
  YYSYMBOL_NUMBER = 11,                    /* NUMBER  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_MULT = 14,                      /* MULT  */
  YYSYMBOL_DIV = 15,                       /* DIV  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 17,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_LPAREN = 19,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 20,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 21,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 22,                    /* RBRACE  */
  YYSYMBOL_LEQ = 23,                       /* LEQ  */
  YYSYMBOL_GEQ = 24,                       /* GEQ  */
  YYSYMBOL_EQ = 25,                        /* EQ  */
  YYSYMBOL_NEQ = 26,                       /* NEQ  */
  YYSYMBOL_LT = 27,                        /* LT  */
  YYSYMBOL_GT = 28,                        /* GT  */
  YYSYMBOL_YYACCEPT = 29,                  /* $accept  */
  YYSYMBOL_programa = 30,                  /* programa  */
  YYSYMBOL_declaracao_lista = 31,          /* declaracao_lista  */
  YYSYMBOL_declaracao = 32,                /* declaracao  */
  YYSYMBOL_var_declaracao = 33,            /* var_declaracao  */
  YYSYMBOL_tipo_especificador = 34,        /* tipo_especificador  */
  YYSYMBOL_fun_declaracao = 35,            /* fun_declaracao  */
  YYSYMBOL_36_1 = 36,                      /* $@1  */
  YYSYMBOL_params = 37,                    /* params  */
  YYSYMBOL_param_lista = 38,               /* param_lista  */
  YYSYMBOL_param = 39,                     /* param  */
  YYSYMBOL_composto_decl = 40,             /* composto_decl  */
  YYSYMBOL_local_declaracoes = 41,         /* local_declaracoes  */
  YYSYMBOL_statement_lista = 42,           /* statement_lista  */
  YYSYMBOL_statement = 43,                 /* statement  */
  YYSYMBOL_expressao_decl = 44,            /* expressao_decl  */
  YYSYMBOL_selecao_decl = 45,              /* selecao_decl  */
  YYSYMBOL_iteracao_decl = 46,             /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 47,              /* retorno_decl  */
  YYSYMBOL_expressao = 48,                 /* expressao  */
  YYSYMBOL_var = 49,                       /* var  */
  YYSYMBOL_simples_expressao = 50,         /* simples_expressao  */
  YYSYMBOL_relacional = 51,                /* relacional  */
  YYSYMBOL_soma_expressao = 52,            /* soma_expressao  */
  YYSYMBOL_soma = 53,                      /* soma  */
  YYSYMBOL_termo = 54,                     /* termo  */
  YYSYMBOL_mult = 55,                      /* mult  */
  YYSYMBOL_fator = 56,                     /* fator  */
  YYSYMBOL_ativacao = 57,                  /* ativacao  */
  YYSYMBOL_args = 58,                      /* args  */
  YYSYMBOL_arg_lista = 59                  /* arg_lista  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  98

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   135,   135,   138,   139,   142,   143,   146,   152,   153,
     156,   156,   163,   164,   167,   168,   171,   175,   184,   189,
     190,   193,   194,   197,   198,   199,   200,   201,   204,   207,
     208,   211,   213,   214,   217,   218,   221,   222,   225,   226,
     229,   230,   231,   232,   233,   234,   237,   238,   241,   242,
     245,   246,   249,   250,   253,   254,   255,   256,   259,   262,
     263,   266,   267
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
  "\"end of file\"", "error", "\"invalid token\"", "THEN", "IF", "ELSE",
  "WHILE", "RETURN", "INT", "VOID", "ID", "NUMBER", "PLUS", "MINUS",
  "MULT", "DIV", "ASSIGN", "SEMICOLON", "COMMA", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "LEQ", "GEQ", "EQ", "NEQ", "LT", "GT", "$accept",
  "programa", "declaracao_lista", "declaracao", "var_declaracao",
  "tipo_especificador", "fun_declaracao", "$@1", "params", "param_lista",
  "param", "composto_decl", "local_declaracoes", "statement_lista",
  "statement", "expressao_decl", "selecao_decl", "iteracao_decl",
  "retorno_decl", "expressao", "var", "simples_expressao", "relacional",
  "soma_expressao", "soma", "termo", "mult", "fator", "ativacao", "args",
  "arg_lista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      12,   -64,   -64,    24,    12,   -64,   -64,    20,   -64,   -64,
     -64,    28,   -64,    18,    49,    21,    33,    41,    46,   -64,
      44,    47,    12,    48,   -64,   -64,   -64,   -64,    12,   -64,
      56,     6,    28,    52,    53,    23,   -17,   -64,    -5,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,    57,    51,   -64,    26,
      45,   -64,   -64,    -5,    -5,   -64,    58,    -5,    -5,    59,
     -64,    -5,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
      -5,    -5,   -64,   -64,    -5,    60,    61,   -64,   -64,    62,
      55,    54,   -64,   -64,   -64,    50,    45,   -64,    25,    25,
     -64,    -5,   -64,    64,   -64,   -64,    25,   -64
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     8,     9,     0,     2,     4,     5,     0,     6,     1,
       3,    10,     7,     0,     0,     9,     0,     0,    12,    15,
      16,     0,     0,     0,    20,    11,    14,    17,    22,    19,
       0,     0,     0,     0,     0,     0,    36,    57,     0,    18,
      24,    21,    23,    25,    26,    27,     0,    55,    35,    39,
      47,    51,    56,     0,     0,    32,     0,    60,     0,     0,
      28,     0,    48,    49,    41,    43,    44,    45,    40,    42,
       0,     0,    52,    53,     0,     0,     0,    33,    62,     0,
      59,     0,    54,    34,    55,    38,    46,    50,     0,     0,
      58,     0,    37,    29,    31,    61,     0,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,   -64,    73,    63,   -13,   -64,   -64,   -64,   -64,
      65,    67,   -64,   -64,   -41,   -64,   -64,   -64,   -64,   -35,
     -63,   -64,   -64,     8,   -64,    13,   -64,     9,   -64,   -64,
     -64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    13,    17,    18,
      19,    40,    28,    31,    41,    42,    43,    44,    45,    46,
      47,    48,    70,    49,    71,    50,    74,    51,    52,    79,
      80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      56,    16,    57,    59,    58,    36,    37,    84,    84,    16,
      33,    84,    34,    35,    38,    30,    36,    37,    75,    76,
       1,     2,    78,    81,     9,    38,    83,    24,    39,    33,
      11,    34,    35,    36,    37,    36,    37,    14,    62,    63,
      55,   -13,    38,    20,    38,    12,    24,    93,    94,    64,
      65,    66,    67,    68,    69,    97,    95,     1,    15,    72,
      73,    21,    62,    63,    22,    23,    32,    61,    24,    96,
      27,    53,    54,    91,    60,    77,    92,    10,    85,    82,
      88,    89,    90,    87,    86,     0,     0,    26,    25,     0,
       0,    29
};

static const yytype_int8 yycheck[] =
{
      35,    14,    19,    38,    21,    10,    11,    70,    71,    22,
       4,    74,     6,     7,    19,    28,    10,    11,    53,    54,
       8,     9,    57,    58,     0,    19,    61,    21,    22,     4,
      10,     6,     7,    10,    11,    10,    11,    19,    12,    13,
      17,    20,    19,    10,    19,    17,    21,    88,    89,    23,
      24,    25,    26,    27,    28,    96,    91,     8,     9,    14,
      15,    20,    12,    13,    18,    21,    10,    16,    21,     5,
      22,    19,    19,    18,    17,    17,    22,     4,    70,    20,
      20,    20,    20,    74,    71,    -1,    -1,    22,    21,    -1,
      -1,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,     9,    30,    31,    32,    33,    34,    35,     0,
      32,    10,    17,    36,    19,     9,    34,    37,    38,    39,
      10,    20,    18,    21,    21,    40,    39,    22,    41,    33,
      34,    42,    10,     4,     6,     7,    10,    11,    19,    22,
      40,    43,    44,    45,    46,    47,    48,    49,    50,    52,
      54,    56,    57,    19,    19,    17,    48,    19,    21,    48,
      17,    16,    12,    13,    23,    24,    25,    26,    27,    28,
      51,    53,    14,    15,    55,    48,    48,    17,    48,    58,
      59,    48,    20,    48,    49,    52,    54,    56,    20,    20,
      20,    18,    22,    43,    43,    48,     5,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    29,    30,    31,    31,    32,    32,    33,    34,    34,
      36,    35,    37,    37,    38,    38,    39,    39,    40,    41,
      41,    42,    42,    43,    43,    43,    43,    43,    44,    45,
      45,    46,    47,    47,    48,    48,    49,    49,    50,    50,
      51,    51,    51,    51,    51,    51,    52,    52,    53,    53,
      54,    54,    55,    55,    56,    56,    56,    56,    57,    58,
      58,    59,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     1,     1,
       0,     7,     1,     1,     3,     1,     2,     4,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     2,     5,
       7,     5,     2,     3,     3,     1,     1,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     4,     1,
       0,     3,     1
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
  case 2: /* programa: declaracao_lista  */
#line 135 "parser.y"
                     { yyval = cria_no("programa", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL); raiz_arvore = yyval;}
#line 1308 "parser.tab.c"
    break;

  case 3: /* declaracao_lista: declaracao_lista declaracao  */
#line 138 "parser.y"
                                { yyval = cria_no("declaracao_lista", NULL, NULL, yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1314 "parser.tab.c"
    break;

  case 4: /* declaracao_lista: declaracao  */
#line 139 "parser.y"
                 {yyval = cria_no("declaracao_lista", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1320 "parser.tab.c"
    break;

  case 5: /* declaracao: var_declaracao  */
#line 142 "parser.y"
                     { yyval = cria_no("declaracao", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1326 "parser.tab.c"
    break;

  case 6: /* declaracao: fun_declaracao  */
#line 143 "parser.y"
                     { yyval = cria_no("declaracao", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1332 "parser.tab.c"
    break;

  case 7: /* var_declaracao: tipo_especificador ID SEMICOLON  */
#line 146 "parser.y"
                                    { 
        yyval = cria_no("var_declaracao", NULL, yyvsp[-1]->identificador, yyvsp[-2], yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL, NULL);
        adiciona_simbolo(yyvsp[-1]->identificador, yyvsp[-2]->valor, currScope); // Adiciona à tabela
    }
#line 1341 "parser.tab.c"
    break;

  case 8: /* tipo_especificador: INT  */
#line 152 "parser.y"
        {yyval = cria_no("tipo_especificador", "int", NULL, folha("INT", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1347 "parser.tab.c"
    break;

  case 9: /* tipo_especificador: VOID  */
#line 153 "parser.y"
           {yyval = cria_no("tipo_especificador", "void", NULL, folha("VOID", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1353 "parser.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 156 "parser.y"
                          {strcpy(currScope, yyvsp[0]->identificador); pushScope();}
#line 1359 "parser.tab.c"
    break;

  case 11: /* fun_declaracao: tipo_especificador ID $@1 LPAREN params RPAREN composto_decl  */
#line 156 "parser.y"
                                                                                                                  {
        popScope();
        yyval = cria_no("fun_declaracao", NULL, NULL, yyvsp[-6], yyvsp[-5], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0], NULL, NULL); 
        adiciona_simbolo(yyvsp[-5]->identificador, yyvsp[-6]->valor, currScope);
    }
#line 1369 "parser.tab.c"
    break;

  case 12: /* params: param_lista  */
#line 163 "parser.y"
                {yyval = cria_no("params", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1375 "parser.tab.c"
    break;

  case 13: /* params: VOID  */
#line 164 "parser.y"
           {yyval = cria_no("params", NULL, NULL, folha("VOID", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1381 "parser.tab.c"
    break;

  case 14: /* param_lista: param_lista COMMA param  */
#line 167 "parser.y"
                            {yyval = cria_no("param_lista", NULL, NULL, yyvsp[-2], yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL, NULL);}
#line 1387 "parser.tab.c"
    break;

  case 15: /* param_lista: param  */
#line 168 "parser.y"
            {yyval = cria_no("param_lista", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1393 "parser.tab.c"
    break;

  case 16: /* param: tipo_especificador ID  */
#line 171 "parser.y"
                          {
        yyval = cria_no("param", NULL, NULL, yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL);
        adiciona_simbolo(yyvsp[0]->identificador, yyvsp[-1]->valor, currScope);
        }
#line 1402 "parser.tab.c"
    break;

  case 17: /* param: tipo_especificador ID LBRACE RBRACE  */
#line 175 "parser.y"
                                          {
        yyval = cria_no("param", NULL, NULL, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL);
        char val[100];
        strcpy(val, yyvsp[-3]->valor);
        strcat(val, "*");
        adiciona_simbolo(yyvsp[-2]->identificador, val, currScope);
        }
#line 1414 "parser.tab.c"
    break;

  case 18: /* composto_decl: LBRACE local_declaracoes statement_lista RBRACE  */
#line 184 "parser.y"
                                                    {
        yyval = cria_no("composto_decl", NULL, NULL, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL); 
        }
#line 1422 "parser.tab.c"
    break;

  case 19: /* local_declaracoes: local_declaracoes var_declaracao  */
#line 189 "parser.y"
                                     {yyval = cria_no("local_declaracoes", NULL, NULL, yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1428 "parser.tab.c"
    break;

  case 20: /* local_declaracoes: %empty  */
#line 190 "parser.y"
                  {yyval = NULL;}
#line 1434 "parser.tab.c"
    break;

  case 21: /* statement_lista: statement_lista statement  */
#line 193 "parser.y"
                              {yyval = cria_no("statement_lista", NULL, NULL, yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1440 "parser.tab.c"
    break;

  case 22: /* statement_lista: %empty  */
#line 194 "parser.y"
                  {yyval = NULL;}
#line 1446 "parser.tab.c"
    break;

  case 23: /* statement: expressao_decl  */
#line 197 "parser.y"
                   {yyval = cria_no("statement", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1452 "parser.tab.c"
    break;

  case 24: /* statement: composto_decl  */
#line 198 "parser.y"
                    {yyval = cria_no("statement", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1458 "parser.tab.c"
    break;

  case 25: /* statement: selecao_decl  */
#line 199 "parser.y"
                   {yyval = cria_no("statement", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1464 "parser.tab.c"
    break;

  case 26: /* statement: iteracao_decl  */
#line 200 "parser.y"
                    {yyval = cria_no("statement", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1470 "parser.tab.c"
    break;

  case 27: /* statement: retorno_decl  */
#line 201 "parser.y"
                   {yyval = cria_no("statement", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1476 "parser.tab.c"
    break;

  case 28: /* expressao_decl: expressao SEMICOLON  */
#line 204 "parser.y"
                        {yyval = cria_no("expressao_decl", NULL, NULL, yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1482 "parser.tab.c"
    break;

  case 29: /* selecao_decl: IF LPAREN expressao RPAREN statement  */
#line 207 "parser.y"
                                                    {yyval = cria_no("selecao_decl", "IF-THEN", NULL, folha("IF", NULL), yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0], NULL, NULL, NULL);}
#line 1488 "parser.tab.c"
    break;

  case 30: /* selecao_decl: IF LPAREN expressao RPAREN statement ELSE statement  */
#line 208 "parser.y"
                                                          {yyval = cria_no("selecao_decl", "IF-ELSE", NULL, folha("IF", NULL), yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0], NULL);}
#line 1494 "parser.tab.c"
    break;

  case 31: /* iteracao_decl: WHILE LPAREN expressao RPAREN statement  */
#line 211 "parser.y"
                                            {yyval = cria_no("iteracao_decl", "WHILE", NULL, folha("WHILE", NULL), yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0], NULL, NULL, NULL);}
#line 1500 "parser.tab.c"
    break;

  case 32: /* retorno_decl: RETURN SEMICOLON  */
#line 213 "parser.y"
                     {yyval = cria_no("retorno_decl", "RETURN", NULL, folha("RETURN", NULL), yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1506 "parser.tab.c"
    break;

  case 33: /* retorno_decl: RETURN expressao SEMICOLON  */
#line 214 "parser.y"
                                 {yyval = cria_no("retorno_decl", "RETURN", NULL, folha("RETURN", NULL), yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL, NULL);}
#line 1512 "parser.tab.c"
    break;

  case 34: /* expressao: var ASSIGN expressao  */
#line 217 "parser.y"
                         {yyval = cria_no("expressao", "ASSIGN", NULL, yyvsp[-2], yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL, NULL);}
#line 1518 "parser.tab.c"
    break;

  case 35: /* expressao: simples_expressao  */
#line 218 "parser.y"
                        {yyval = cria_no("expressao", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1524 "parser.tab.c"
    break;

  case 36: /* var: ID  */
#line 221 "parser.y"
       {yyval = cria_no("var", "ID", NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1530 "parser.tab.c"
    break;

  case 37: /* var: ID LBRACE expressao RBRACE  */
#line 222 "parser.y"
                                 {yyval = cria_no("var", "ID[LBRACE-EXP-RBRACE]", NULL, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL);}
#line 1536 "parser.tab.c"
    break;

  case 38: /* simples_expressao: soma_expressao relacional soma_expressao  */
#line 225 "parser.y"
                                             {yyval = cria_no("simples_expressao", NULL, NULL, yyvsp[-2], yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL, NULL);}
#line 1542 "parser.tab.c"
    break;

  case 39: /* simples_expressao: soma_expressao  */
#line 226 "parser.y"
                     {yyval = cria_no("simples_expressao", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1548 "parser.tab.c"
    break;

  case 40: /* relacional: LT  */
#line 229 "parser.y"
       {yyval = cria_no("relacional", "LT", NULL, folha("LT", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1554 "parser.tab.c"
    break;

  case 41: /* relacional: LEQ  */
#line 230 "parser.y"
          {yyval = cria_no("relacional", "LEQ", NULL, folha("LEQ", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1560 "parser.tab.c"
    break;

  case 42: /* relacional: GT  */
#line 231 "parser.y"
         {yyval = cria_no("relacional", "GT", NULL, folha("GT",NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1566 "parser.tab.c"
    break;

  case 43: /* relacional: GEQ  */
#line 232 "parser.y"
          {yyval = cria_no("relacional", "GEQ", NULL, folha("GEQ", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1572 "parser.tab.c"
    break;

  case 44: /* relacional: EQ  */
#line 233 "parser.y"
         {yyval = cria_no("relacional", "EQ", NULL, folha("EQ",NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1578 "parser.tab.c"
    break;

  case 45: /* relacional: NEQ  */
#line 234 "parser.y"
          {yyval = cria_no("relacional", "NEQ", NULL, folha("NEQ",NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1584 "parser.tab.c"
    break;

  case 46: /* soma_expressao: soma_expressao soma termo  */
#line 237 "parser.y"
                              {yyval = cria_no("soma_expressao", NULL, NULL, yyvsp[-2], yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL, NULL);}
#line 1590 "parser.tab.c"
    break;

  case 47: /* soma_expressao: termo  */
#line 238 "parser.y"
            {yyval = cria_no("soma_expressao", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1596 "parser.tab.c"
    break;

  case 48: /* soma: PLUS  */
#line 241 "parser.y"
         {yyval = cria_no("soma", "PLUS", NULL, folha("PLUS", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1602 "parser.tab.c"
    break;

  case 49: /* soma: MINUS  */
#line 242 "parser.y"
            {yyval = cria_no("soma", "MINUS", NULL, folha("MINUS", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1608 "parser.tab.c"
    break;

  case 50: /* termo: termo mult fator  */
#line 245 "parser.y"
                     {yyval = cria_no("termo", NULL, NULL, yyvsp[-2], yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL, NULL);}
#line 1614 "parser.tab.c"
    break;

  case 51: /* termo: fator  */
#line 246 "parser.y"
            {yyval = cria_no("termo", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1620 "parser.tab.c"
    break;

  case 52: /* mult: MULT  */
#line 249 "parser.y"
         {yyval = cria_no("mult", "MULT", NULL, folha("MULT", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1626 "parser.tab.c"
    break;

  case 53: /* mult: DIV  */
#line 250 "parser.y"
          {yyval = cria_no("mult", "DIV", NULL, folha("DIV", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1632 "parser.tab.c"
    break;

  case 54: /* fator: LPAREN expressao RPAREN  */
#line 253 "parser.y"
                            {yyval = cria_no("fator", "LPAREN-EXP-RPAREN", NULL, folha("LPAREN", NULL), yyvsp[-1], folha("RPAREN", NULL), NULL, NULL, NULL, NULL, NULL);}
#line 1638 "parser.tab.c"
    break;

  case 55: /* fator: var  */
#line 254 "parser.y"
          {yyval = cria_no("fator", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1644 "parser.tab.c"
    break;

  case 56: /* fator: ativacao  */
#line 255 "parser.y"
               {yyval = cria_no("fator", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1650 "parser.tab.c"
    break;

  case 57: /* fator: NUMBER  */
#line 256 "parser.y"
             {yyval = cria_no("fator", "NUMBER", NULL, folha("NUMBER", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1656 "parser.tab.c"
    break;

  case 58: /* ativacao: ID LPAREN args RPAREN  */
#line 259 "parser.y"
                          {yyval = cria_no("ativacao", "ID LPAREN-ARGS-RPAREN", NULL, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL);}
#line 1662 "parser.tab.c"
    break;

  case 59: /* args: arg_lista  */
#line 262 "parser.y"
              {yyval = cria_no("arg_lista", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1668 "parser.tab.c"
    break;

  case 60: /* args: %empty  */
#line 263 "parser.y"
                  {yyval = NULL;}
#line 1674 "parser.tab.c"
    break;

  case 61: /* arg_lista: arg_lista COMMA expressao  */
#line 266 "parser.y"
                              {yyval = cria_no("arg_lista", NULL, NULL, yyvsp[-2], yyvsp[-1], yyvsp[0], NULL, NULL, NULL, NULL, NULL);}
#line 1680 "parser.tab.c"
    break;

  case 62: /* arg_lista: expressao  */
#line 267 "parser.y"
                {yyval = cria_no("arg_lista", NULL, NULL, yyvsp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1686 "parser.tab.c"
    break;


#line 1690 "parser.tab.c"

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

#line 268 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "ERRO SINTÁTICO: \"%s\" LINHA: %d\n", yytext, yylineno);
}

int main() {
    yyparse();  // Executa o parsing (já deve adicionar símbolos durante a análise)
    printf("Árvore de Análise Sintática:\n");
    imprime_arvore(raiz_arvore, 0);  // Imprime a árvore

    printf("\nTabela de Símbolos:\n");
    imprime_tabela_simbolos();  // Imprime os símbolos coletados

    libera_tabela_simbolos();   // Libera memória da tabela
    return 0;
}
