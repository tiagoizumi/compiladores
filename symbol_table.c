#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simbolo {
    char *nome;
    char *tipo;
    char *escopo;
    struct simbolo *prox; 
} Simbolo;

Simbolo *tabela_simbolos = NULL;

Simbolo* cria_simbolo(char *nome, char *tipo, char *escopo) {
    Simbolo *novo = (Simbolo*)malloc(sizeof(Simbolo));
    if (!novo) {
        fprintf(stderr, "Erro de alocação de memória para símbolo.\n");
        exit(1);
    }
    novo->nome = strdup(nome);
    novo->tipo = strdup(tipo);
    novo->escopo = escopo ? strdup(escopo) : NULL;
    novo->prox = NULL;
    return novo;
}

void adiciona_simbolo(char *nome, char *tipo, char *escopo) {
    Simbolo *novo = cria_simbolo(nome, tipo, escopo);
    novo->prox = tabela_simbolos;
    tabela_simbolos = novo;
}

Simbolo* busca_simbolo(char *nome, char *escopo) {
    Simbolo *atual = tabela_simbolos;
    while (atual) {
        if (strcmp(atual->nome, nome) == 0 && 
            (escopo == NULL || strcmp(atual->escopo, escopo) == 0)) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL; 
}

void libera_tabela_simbolos() {
    Simbolo *atual = tabela_simbolos;
    while (atual) {
        Simbolo *temp = atual;
        atual = atual->prox;
        free(temp->nome);
        free(temp->tipo);
        free(temp->escopo);
        free(temp);
    }
    tabela_simbolos = NULL;
}

void imprime_tabela_simbolos() {
    Simbolo *atual = tabela_simbolos;
    while (atual) {
        printf("Nome: %20s, Tipo: %20s, Escopo: %10s\n", atual->nome, atual->tipo, 
               atual->escopo ? atual->escopo : "Global");
        atual = atual->prox;
    }
}

int ja_declarado(char *nome, char *tipo, char *escopo) {
    Simbolo *atual = tabela_simbolos;
    while (atual) {
        if(strcmp(atual->escopo, escopo) == 0 && strcmp(atual->nome, nome) == 0) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

int verifica_compatibilidade(char *nome, char *tipo, char *escopo) {
    Simbolo *atual = tabela_simbolos;
    while (atual) {
        if(strcmp(atual->escopo, escopo) == 0 && strcmp(atual->nome, nome) == 0 && strcmp(atual->tipo, tipo) == 0) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}