#ifndef TABELA_SIMBOLOS_H
#define TABELA_SIMBOLOS_H

// Declaração da estrutura de um símbolo
typedef struct simbolo Simbolo;

// Funções para manipulação da tabela de símbolos
Simbolo* cria_simbolo(char *nome, char *tipo, char *escopo);
void adiciona_simbolo(char *nome, char *tipo, char *escopo);
Simbolo* busca_simbolo(char *nome, char *escopo);
void libera_tabela_simbolos();
void imprime_tabela_simbolos();
int ja_declarado(char *nome, char *tipo, char *escopo);
int verifica_compatibilidade(char *nome, char *tipo, char *escopo);

#endif // TABELA_SIMBOLOS_H
