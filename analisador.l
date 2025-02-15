%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "parser.tab.h" // Inclui os tokens gerados pelo Bison

int line_number = 1; // Contador de linhas

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

{ID}        { printf("%s ", yytext); return ID; }
{NUMBER}    { printf("%s ", yytext); return NUMBER; }

"+"         { printf("%s ", yytext); return PLUS; }
"-"         { printf("%s ", yytext); return MINUS; }
"*"         { printf("%s ", yytext); return MULT; }
"/"         { printf("%s ", yytext); return DIV; }
"="         { printf("%s ", yytext); return ASSIGN; }
";"         { printf("%s\n", yytext); return SEMICOLON; }
","         { printf("%s ", yytext); return COMMA; }
"("         { printf("%s", yytext); return LPAREN; }
")"         { printf("%s ", yytext); return RPAREN; }
"{"         { printf("\n%s\n", yytext); return LBRACE; }
"}"         { printf("\n%s\n", yytext); return RBRACE; }
"<="        { printf("%s ", yytext); return LEQ; }
">="        { printf("%s ", yytext); return GEQ; }
"=="        { printf("%s ", yytext); return EQ; }
"!="        { printf("%s ", yytext); return NEQ; }
"<"         { printf("%s ", yytext); return LT; }
">"         { printf("%s ", yytext); return GT; }

[ \t]+      { /* Ignora espaços e tabulações */ }
\n          { printf("\n"); line_number++; yylineno++;} // Conta novas linhas

"//".*      { /* Ignora comentários de linha */ }
"/*"([^*]|\*+[^*/])*\*+"/" { /* Ignora comentários de bloco */ }

.           { printf("ERRO LEXICO: '%s' LINHA: %d\n", yytext, yylineno); }



%%

int yywrap() {
    return 1;
}
