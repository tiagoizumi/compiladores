%{
// Declaração antecipada de Node para evitar erros
typedef struct node Node;

// Define YYSTYPE como Node* para compatibilidade com o parser
#define YYSTYPE Node*

#include "parser.tab.h" // Inclui os tokens gerados pelo Bison
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern Node* folha(char *tipo, char *identificador);

void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}
%}

DIGIT   [0-9]
LETTER  [a-zA-Z]
ID      {LETTER}({LETTER}|{DIGIT})*
NUMBER  {DIGIT}+

%%


"if"        { printf("%s ", yytext); return IF; }
"else"      { printf("%s ", yytext); return ELSE; }
"while"     { printf("%s ", yytext); return WHILE; }
"return"    { printf("%s ", yytext); return RETURN; }
"int"       { printf("%s ", yytext); return INT; }
"void"      { printf("%s ", yytext); return VOID; }

{ID}        { 
    yylval = folha("ID", yytext); // Passa yytext como identificador
    printf("%s ", yytext); 
    return ID; 
}

{NUMBER}    { 
                yylval = folha("NUMBER", NULL); // Números não têm identificador
                printf("%s ", yytext); 
                return NUMBER; 
             }

"+"         { yylval = folha("PLUS", NULL); printf("%s ", yytext); return PLUS; }
"-"         { yylval = folha("MINUS", NULL); printf("%s ", yytext); return MINUS; }
"*"         { yylval = folha("MULT", NULL); printf("%s ", yytext); return MULT; }
"/"         { yylval = folha("DIV", NULL); printf("%s ", yytext); return DIV; }
"="         { yylval = folha("ASSIGN", NULL); printf("%s ", yytext); return ASSIGN; }
";"         { yylval = folha("SEMICOLON", NULL); printf("%s\n", yytext); return SEMICOLON; }
","         { yylval = folha("COMMA", NULL); printf("%s ", yytext); return COMMA; }
"("         { yylval = folha("LPAREN", NULL); printf("%s", yytext); return LPAREN; }
")"         { yylval = folha("RPAREN", NULL); printf("%s ", yytext); return RPAREN; }
"["         { yylval = folha("LBRACE", NULL); printf("%s ", yytext); return LBRACE; }
"]"         { yylval = folha("RBRACE", NULL); printf("%s ", yytext); return RBRACE; }
"{"         { yylval = folha("LBRACE", NULL); printf("\n%s\n", yytext); return LBRACE; }
"}"         { yylval = folha("RBRACE", NULL); printf("\n%s\n", yytext); return RBRACE; }
"<="        { yylval = folha("LEQ", NULL); printf("%s ", yytext); return LEQ; }
">="        { yylval = folha("GEQ", NULL); printf("%s ", yytext); return GEQ; }
"=="        { yylval = folha("EQ", NULL); printf("%s ", yytext); return EQ; }
"!="        { yylval = folha("NEQ", NULL); printf("%s ", yytext); return NEQ; }
"<"         { yylval = folha("LT", NULL); printf("%s ", yytext); return LT; }
">"         { yylval = folha("GT", NULL); printf("%s ", yytext); return GT; }

[ \t]+      { /* Ignora espaços e tabulações */ }
\n          { yylineno++; printf("\n"); }

"//".*      { /* Ignora comentários de linha */ }
"/*"([^*]|\*+[^*/])*\*+"/" {
    int i;
    for (i = 0; yytext[i] != '\0'; i++) {
        if (yytext[i] == '\n') {
            yylineno++;
        }
    }
    /* Ignora comentários de bloco */
}

.           { printf("ERRO LÉXICO: caractere inválido '%s' LINHA: %d\n", yytext, yylineno); }

%%

int yywrap() {
    return 1;
}