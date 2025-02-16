#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura de um símbolo
typedef struct simbolo {
    char *nome;          // Nome do identificador
    char *tipo;          // Tipo do identificador (ex: INT, VOID)
    char *escopo;        // Nome da função onde o identificador foi declarado (NULL se global)
    struct simbolo *prox; // Ponteiro para o próximo símbolo (lista ligada)
} Simbolo;

// Cabeça da lista de símbolos
Simbolo *tabela_simbolos = NULL;

// Função para criar um novo símbolo
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

// Função para adicionar um símbolo à tabela de símbolos
void adiciona_simbolo(char *nome, char *tipo, char *escopo) {
    Simbolo *novo = cria_simbolo(nome, tipo, escopo);
    novo->prox = tabela_simbolos;
    tabela_simbolos = novo;
}

// Função para buscar um símbolo na tabela
Simbolo* busca_simbolo(char *nome, char *escopo) {
    Simbolo *atual = tabela_simbolos;
    while (atual) {
        if (strcmp(atual->nome, nome) == 0 && 
            (escopo == NULL || strcmp(atual->escopo, escopo) == 0)) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL; // Símbolo não encontrado
}

// Função para liberar a memória da tabela de símbolos
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

// Função para imprimir a tabela de símbolos (para depuração)
void imprime_tabela_simbolos() {
    Simbolo *atual = tabela_simbolos;
    while (atual) {
        printf("Nome: %s, Tipo: %s, Escopo: %s\n", atual->nome, atual->tipo, 
               atual->escopo ? atual->escopo : "Global");
        atual = atual->prox;
    }
}
