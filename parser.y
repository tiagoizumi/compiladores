%{
#include <stdio.h>
#include <stdlib.h>

extern int yylineno;  // Variável do Flex que conta as linhas
extern char *yytext;  // Token atual    
void yyerror(const char *s);
int yylex();

typedef struct node {
    char *tipo;
    struct node *esquerda;
    struct node *direita;
    char *valor;
} Node;

Node* cria_no(char *tipo, char *valor, Node *esquerda, Node *direita) {
    Node* novo_no = (Node*)malloc(sizeof(Node));
    if (novo_no == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(1);  // Ou retornar NULL e tratar o erro na função que chamou
    }
    novo_no->tipo = tipo;
    novo_no->valor = valor;
    novo_no->esquerda = esquerda;
    novo_no->direita = direita;
    return novo_no;
}

void imprime_arvore(Node *no, int nivel) {
    if (no == NULL) return;

    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }
    printf("%s", no->tipo);
    if (no->valor) {
        printf(": %s", no->valor);
    }
    printf("\n");

    imprime_arvore(no->esquerda, nivel + 1);
    imprime_arvore(no->direita, nivel + 1);
}

// Definindo YYSTYPE como ponteiro para Node
#define YYSTYPE Node*

Node *raiz_arvore;  // Variável global que armazenará a raiz da árvore

%}

/* Definição de precedência para evitar conflito shift/reduce no IF-ELSE */
%nonassoc THEN
%nonassoc ELSE

%token IF ELSE WHILE RETURN INT VOID ID NUMBER
%token PLUS MINUS MULT DIV ASSIGN SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE
%token LEQ GEQ EQ NEQ LT GT

%%
programa:
    declaracao_lista { $$ = cria_no("programa", NULL, $1, NULL); raiz_arvore = $$;}; // Armazena a árvore final 

declaracao_lista:
    declaracao_lista declaracao { $$ = cria_no("declaracao_lista", NULL, $1, $2);}
    | declaracao {$$ = cria_no("declaracao_lista", NULL, $1, NULL);
};

declaracao:
    var_declaracao { $$ = $1;}
    | fun_declaracao { $$ = $1;};

var_declaracao:
    tipo_especificador ID SEMICOLON { $$ = cria_no("var_declaracao", NULL, $1, NULL);}
    | tipo_especificador ID LBRACE NUMBER RBRACE SEMICOLON {$$ = cria_no("var_declaracao", NULL, $1, $4);};

tipo_especificador:
    INT {$$ = cria_no("tipo_especificador", "INT", NULL, NULL);}
    | VOID {$$ = cria_no("tipo_especificador", "VOID", NULL, NULL);};

fun_declaracao:
    tipo_especificador ID LPAREN params RPAREN composto_decl {$$ = cria_no("fun_declaracao", NULL, $1, $6); }; // $1 = tipo_especificador, $6 = composto_decl

params:
    param_lista {$$ = $1;}
    | VOID {$$ = cria_no("params", "VOID", NULL, NULL);};

param_lista:
    param_lista COMMA param {$$ = cria_no("param_lista", NULL, $1, $3);}
    | param {$$ = $1;};

param:
    tipo_especificador ID {$$ = cria_no("param", NULL, $1, NULL);}
    | tipo_especificador ID LBRACE RBRACE {$$ = cria_no("param", NULL, $1, NULL);};

composto_decl:
    LBRACE local_declaracoes statement_lista RBRACE {$$ = cria_no("composto_decl", NULL, $2, $3); }; // $2 = local_declaracoes, $3 = statement_lista

local_declaracoes:
    local_declaracoes var_declaracao {$$ = cria_no("local_declaracoes", NULL, $1, $2);}
    | /* vazio */ {$$ = NULL;};

statement_lista:
    statement_lista statement {$$ = cria_no("statement_lista", NULL, $1, $2);}
    | /* vazio */ {$$ = NULL;};

statement:
    expressao_decl {$$ = $1;}
    | composto_decl {$$ = $1;}
    | selecao_decl {$$ = $1;}
    | iteracao_decl {$$ = $1;}
    | retorno_decl {$$ = $1;};

expressao_decl:
    expressao SEMICOLON {$$ = cria_no("expressao_decl", NULL, $1, NULL);};

selecao_decl:
    IF LPAREN expressao RPAREN statement %prec THEN {$$ = cria_no("selecao_decl", "IF-THEN", $3, $5);}
    | IF LPAREN expressao RPAREN statement ELSE statement {$$ = cria_no("selecao_decl", "IF-ELSE", $3, $6);};

iteracao_decl:
    WHILE LPAREN expressao RPAREN statement {$$ = cria_no("iteracao_decl", "WHILE", $3, $5);};

retorno_decl:
    RETURN SEMICOLON {$$ = cria_no("retorno_decl", "RETURN", NULL, NULL);}
    | RETURN expressao SEMICOLON {$$ = cria_no("retorno_decl", "RETURN", $2, NULL);};

expressao:
    var ASSIGN expressao {$$ = cria_no("expressao", "ASSIGN", $1, $3);}
    | simples_expressao {$$ = $1;};

var:
    ID {$$ = cria_no("var", "ID", NULL, NULL);}
    | ID LBRACE expressao RBRACE {$$ = cria_no("var", "ID[LBRACE-EXP-RBRACE]", $3, NULL);};

simples_expressao:
    soma_expressao relacional soma_expressao {$$ = cria_no("simples_expressao", NULL, $1, $3);}
    | soma_expressao {$$ = $1;};

relacional:
    LT {$$ = cria_no("relacional", "LT", NULL, NULL);}
    | LEQ {$$ = cria_no("relacional", "LEQ", NULL, NULL);}
    | GT {$$ = cria_no("relacional", "GT", NULL, NULL);}
    | GEQ {$$ = cria_no("relacional", "GEQ", NULL, NULL);}
    | EQ {$$ = cria_no("relacional", "EQ", NULL, NULL);}
    | NEQ {$$ = cria_no("relacional", "NEQ", NULL, NULL);};

soma_expressao:
    soma_expressao soma termo {$$ = cria_no("soma_expressao", NULL, $1, $3);}
    | termo {$$ = $1;};

soma:
    PLUS {$$ = cria_no("soma", "PLUS", NULL, NULL);}
    | MINUS {$$ = cria_no("soma", "MINUS", NULL, NULL);};

termo:
    termo mult fator {$$ = cria_no("termo", NULL, $1, $3);}
    | fator {$$ = $1;};

mult:
    MULT {$$ = cria_no("mult", "MULT", NULL, NULL);}
    | DIV {$$ = cria_no("mult", "DIV", NULL, NULL);};

fator:
    LPAREN expressao RPAREN {$$ = cria_no("fator", "LPAREN-EXP-RPAREN", $2, NULL);}
    | var {$$ = $1;}
    | ativacao {$$ = $1;}
    | NUMBER {$$ = cria_no("fator", "NUMBER", NULL, NULL);};

ativacao:
    ID LPAREN args RPAREN {$$ = cria_no("ativacao", "ID LPAREN-ARGS-RPAREN", $3, NULL);};

args:
    arg_lista {$$ = $1;}
    | /* vazio */ {$$ = NULL;};

arg_lista:
    arg_lista COMMA expressao {$$ = cria_no("arg_lista", NULL, $1, $3);}
    | expressao {$$ = $1;};

%%

void yyerror(const char *s) {
    fprintf(stderr, "ERRO SINTÁTICO: \"%s\" LINHA: %d\n", yytext, yylineno);
}

int main() {
    yyparse();  // Executa o parsing
    printf("Árvore de Análise Sintática:\n");
    imprime_arvore(raiz_arvore, 0);  // Imprime a árvore
    return 0;
}
