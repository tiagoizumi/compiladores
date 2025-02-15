%{
#include <stdio.h>
#include <stdlib.h>

extern int yylineno;
extern char *yytext;

void yyerror(const char *s);
int yylex();


%}

/* Definição de precedência para evitar conflito shift/reduce no IF-ELSE */
%nonassoc THEN
%nonassoc ELSE

%token IF ELSE WHILE RETURN INT VOID ID NUMBER
%token PLUS MINUS MULT DIV ASSIGN SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE
%token LEQ GEQ EQ NEQ LT GT

%%
programa: declaracao_lista;

declaracao_lista: declaracao_lista declaracao | declaracao;

declaracao: var_declaracao | fun_declaracao;

var_declaracao: tipo_especificador ID SEMICOLON 
              | tipo_especificador ID LBRACE NUMBER RBRACE SEMICOLON;

tipo_especificador: INT | VOID;

fun_declaracao: tipo_especificador ID LPAREN params RPAREN composto_decl;

params: param_lista | VOID;

param_lista: param_lista COMMA param | param;

param: tipo_especificador ID | tipo_especificador ID LBRACE RBRACE;

composto_decl: LBRACE local_declaracoes statement_lista RBRACE;

local_declaracoes: local_declaracoes var_declaracao | /* vazio */;

statement_lista: statement_lista statement | /* vazio */;

statement: expressao_decl 
         | composto_decl 
         | selecao_decl 
         | iteracao_decl 
         | retorno_decl;

expressao_decl: expressao SEMICOLON;

selecao_decl: IF LPAREN expressao RPAREN statement %prec THEN
            | IF LPAREN expressao RPAREN statement ELSE statement;

iteracao_decl: WHILE LPAREN expressao RPAREN statement;

retorno_decl: RETURN SEMICOLON 
            | RETURN expressao SEMICOLON;

expressao: var ASSIGN expressao 
         | simples_expressao;

var: ID 
   | ID LBRACE expressao RBRACE;

simples_expressao: soma_expressao relacional soma_expressao 
                 | soma_expressao;

relacional: LT | LEQ | GT | GEQ | EQ | NEQ;

soma_expressao: soma_expressao soma termo | termo;

soma: PLUS | MINUS;

termo: termo mult fator | fator;

mult: MULT | DIV;

fator: LPAREN expressao RPAREN 
     | var 
     | ativacao 
     | NUMBER;

ativacao: ID LPAREN args RPAREN;

args: arg_lista | /* vazio */;

arg_lista: arg_lista COMMA expressao 
         | expressao;

%%

void yyerror(const char *s) {
    fprintf(stderr, "ERRO SINTATICO: TOKEN '%s' LINHA: %d\n", yytext, yylineno);
}

int main() {
    return yyparse();
}
