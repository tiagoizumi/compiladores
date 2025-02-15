%{
#include <stdio.h>
#include <stdlib.h>

int line_number = 1; // Variável global para rastrear o número da linha
%}

DIGIT   [0-9]
LETTER  [a-zA-Z]
ID      {LETTER}({LETTER}|{DIGIT})*
NUMBER  {DIGIT}+

%%

"if"        { printf("TOKEN_IF\n"); }
"else"      { printf("TOKEN_ELSE\n"); }
"while"     { printf("TOKEN_WHILE\n"); }
"return"    { printf("TOKEN_RETURN\n"); }

{ID}        { printf("TOKEN_ID(%s)\n", yytext); }
{NUMBER}    { printf("TOKEN_NUMBER(%s)\n", yytext); }

"+"         { printf("TOKEN_PLUS\n"); }
"-"         { printf("TOKEN_MINUS\n"); }
"*"         { printf("TOKEN_MULT\n"); }
"/"         { printf("TOKEN_DIV\n"); }
"="         { printf("TOKEN_ASSIGN\n"); }
";"         { printf("TOKEN_SEMICOLON\n"); }
","         { printf("TOKEN_COMMA\n"); }
"("         { printf("TOKEN_LPAREN\n"); }
")"         { printf("TOKEN_RPAREN\n"); }
"{"         { printf("TOKEN_LBRACE\n"); }
"}"         { printf("TOKEN_RBRACE\n"); }

[ \t]+      { /* Ignora espaços e tabulações */ }
\n          { line_number++; } // Incrementa o número da linha para cada nova linha

"//".*      { /* Ignora comentários de linha */ }
"/*"([^*]|\*+[^*/])*\*+"/" { /* Ignora comentários de bloco */ }

.           { printf("Erro na linha %d: lexema '%s'\n", line_number, yytext); }

%%

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    yyin = file;
    yylex();
    fclose(file);
    return 0;
}

int yywrap() {
    return 1;
}
