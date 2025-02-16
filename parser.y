%{
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

%}

/* Definição de precedência para evitar conflito shift/reduce no IF-ELSE */
%nonassoc THEN
%nonassoc ELSE

%token IF ELSE WHILE RETURN INT VOID ID NUMBER
%token PLUS MINUS MULT DIV ASSIGN SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE
%token LEQ GEQ EQ NEQ LT GT

%%
programa:
    declaracao_lista { $$ = cria_no("programa", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL); raiz_arvore = $$;};

declaracao_lista:
    declaracao_lista declaracao { $$ = cria_no("declaracao_lista", NULL, NULL, $1, $2, NULL, NULL, NULL, NULL, NULL, NULL);}
    | declaracao {$$ = cria_no("declaracao_lista", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);};

declaracao:
    var_declaracao   { $$ = cria_no("declaracao", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | fun_declaracao { $$ = cria_no("declaracao", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);};

var_declaracao:
    tipo_especificador ID SEMICOLON { 
        $$ = cria_no("var_declaracao", NULL, $2->identificador, $1, $2, $3, NULL, NULL, NULL, NULL, NULL);
        adiciona_simbolo($2->identificador, $1->valor, currScope); // Adiciona à tabela
    };

tipo_especificador:
    INT {$$ = cria_no("tipo_especificador", "int", NULL, folha("INT", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | VOID {$$ = cria_no("tipo_especificador", "void", NULL, folha("VOID", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);};

fun_declaracao:
    tipo_especificador ID {strcpy(currScope, $2->identificador); pushScope();} LPAREN params RPAREN composto_decl {
        popScope();
        $$ = cria_no("fun_declaracao", NULL, NULL, $1, $2, $4, $5, $6, $7, NULL, NULL); 
        adiciona_simbolo($2->identificador, $1->valor, currScope);
    };

params:
    param_lista {$$ = cria_no("params", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | VOID {$$ = cria_no("params", NULL, NULL, folha("VOID", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);};

param_lista:
    param_lista COMMA param {$$ = cria_no("param_lista", NULL, NULL, $1, $2, $3, NULL, NULL, NULL, NULL, NULL);}
    | param {$$ = cria_no("param_lista", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);};

param:
    tipo_especificador ID {
        $$ = cria_no("param", NULL, NULL, $1, $2, NULL, NULL, NULL, NULL, NULL, NULL);
        adiciona_simbolo($2->identificador, $1->valor, currScope);
        }
    | tipo_especificador ID LBRACE RBRACE {
        $$ = cria_no("param", NULL, NULL, $1, $2, $3, $4, NULL, NULL, NULL, NULL);
        adiciona_simbolo($2->identificador, $1->valor, currScope);
        };

composto_decl:
    LBRACE local_declaracoes statement_lista RBRACE {
        $$ = cria_no("composto_decl", NULL, NULL, $1, $2, $3, $4, NULL, NULL, NULL, NULL); 
        };

local_declaracoes:
    local_declaracoes var_declaracao {$$ = cria_no("local_declaracoes", NULL, NULL, $1, $2, NULL, NULL, NULL, NULL, NULL, NULL);}
    | /* vazio */ {$$ = NULL;};

statement_lista:
    statement_lista statement {$$ = cria_no("statement_lista", NULL, NULL, $1, $2, NULL, NULL, NULL, NULL, NULL, NULL);}
    | /* vazio */ {$$ = NULL;};

statement:
    expressao_decl {$$ = cria_no("statement", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | composto_decl {$$ = cria_no("statement", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | selecao_decl {$$ = cria_no("statement", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | iteracao_decl {$$ = cria_no("statement", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | retorno_decl {$$ = cria_no("statement", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);};

expressao_decl:
    expressao SEMICOLON {$$ = cria_no("expressao_decl", NULL, NULL, $1, $2, NULL, NULL, NULL, NULL, NULL, NULL);};

selecao_decl:
    IF LPAREN expressao RPAREN statement %prec THEN {$$ = cria_no("selecao_decl", "IF-THEN", NULL, folha("IF", NULL), $2, $3, $4, $5, NULL, NULL, NULL);}
    | IF LPAREN expressao RPAREN statement ELSE statement {$$ = cria_no("selecao_decl", "IF-ELSE", NULL, folha("IF", NULL), $2, $3, $4, $5, $6, $7, NULL);};

iteracao_decl:
    WHILE LPAREN expressao RPAREN statement {$$ = cria_no("iteracao_decl", "WHILE", NULL, folha("WHILE", NULL), $2, $3, $4, $5, NULL, NULL, NULL);};
retorno_decl:
    RETURN SEMICOLON {$$ = cria_no("retorno_decl", "RETURN", NULL, folha("RETURN", NULL), $2, NULL, NULL, NULL, NULL, NULL, NULL);}
    | RETURN expressao SEMICOLON {$$ = cria_no("retorno_decl", "RETURN", NULL, folha("RETURN", NULL), $2, $3, NULL, NULL, NULL, NULL, NULL);};

expressao:
    var ASSIGN expressao {$$ = cria_no("expressao", "ASSIGN", NULL, $1, $2, $3, NULL, NULL, NULL, NULL, NULL);}
    | simples_expressao {$$ = cria_no("expressao", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);};

var:
    ID {$$ = cria_no("var", "ID", NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | ID LBRACE expressao RBRACE {$$ = cria_no("var", "ID[LBRACE-EXP-RBRACE]", NULL, $1, $2, $3, $4, NULL, NULL, NULL, NULL);};

simples_expressao:
    soma_expressao relacional soma_expressao {$$ = cria_no("simples_expressao", NULL, NULL, $1, $2, $3, NULL, NULL, NULL, NULL, NULL);}
    | soma_expressao {$$ = cria_no("simples_expressao", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);};

relacional:
    LT {$$ = cria_no("relacional", "LT", NULL, folha("LT", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | LEQ {$$ = cria_no("relacional", "LEQ", NULL, folha("LEQ", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | GT {$$ = cria_no("relacional", "GT", NULL, folha("GT",NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | GEQ {$$ = cria_no("relacional", "GEQ", NULL, folha("GEQ", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | EQ {$$ = cria_no("relacional", "EQ", NULL, folha("EQ",NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | NEQ {$$ = cria_no("relacional", "NEQ", NULL, folha("NEQ",NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);};

soma_expressao:
    soma_expressao soma termo {$$ = cria_no("soma_expressao", NULL, NULL, $1, $2, $3, NULL, NULL, NULL, NULL, NULL);}
    | termo {$$ = cria_no("soma_expressao", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);};

soma:
    PLUS {$$ = cria_no("soma", "PLUS", NULL, folha("PLUS", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | MINUS {$$ = cria_no("soma", "MINUS", NULL, folha("MINUS", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);};

termo:
    termo mult fator {$$ = cria_no("termo", NULL, NULL, $1, $2, $3, NULL, NULL, NULL, NULL, NULL);}
    | fator {$$ = cria_no("termo", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);};

mult:
    MULT {$$ = cria_no("mult", "MULT", NULL, folha("MULT", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | DIV {$$ = cria_no("mult", "DIV", NULL, folha("DIV", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);};

fator:
    LPAREN expressao RPAREN {$$ = cria_no("fator", "LPAREN-EXP-RPAREN", NULL, folha("LPAREN", NULL), $2, folha("RPAREN", NULL), NULL, NULL, NULL, NULL, NULL);}
    | var {$$ = cria_no("fator", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | ativacao {$$ = cria_no("fator", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);} // Adicione esta linha
    | NUMBER {$$ = cria_no("fator", "NUMBER", NULL, folha("NUMBER", NULL), NULL, NULL, NULL, NULL, NULL, NULL, NULL);};

ativacao:
    ID LPAREN args RPAREN {$$ = cria_no("ativacao", "ID LPAREN-ARGS-RPAREN", NULL, $1, $2, $3, $4, NULL, NULL, NULL, NULL);};

args:
    arg_lista {$$ = cria_no("arg_lista", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | /* vazio */ {$$ = NULL;};

arg_lista:
    arg_lista COMMA expressao {$$ = cria_no("arg_lista", NULL, NULL, $1, $2, $3, NULL, NULL, NULL, NULL, NULL);}
    | expressao {$$ = cria_no("arg_lista", NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL, NULL, NULL);};
%%

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
