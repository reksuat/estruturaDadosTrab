#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 40

typedef struct No {
    char palavra[50];
    char definicao[300];
    struct No *prox;
} No;

void inicializar(No *tabela[]){
    for (int i = 0; i < TAM; i++)
    {
        tabela[i] = NULL;
    }
}

int funcaoHash(char palavra[]){
    int soma = 0;
    for (int i = 0; palavra[i] != '\0'; i++)
    {
        soma+=palavra[i];
    }
    return soma % TAM;
}

No *criarNo(char palavra[], char definicao[]){
    No *novo = (No*) malloc(sizeof(No));
    if(novo == NULL){
        printf("[ERRO] Não foi possível alocar memória.");
        return NULL;
    }
    strcpy(novo->palavra, palavra);
    strcpy(novo->definicao, definicao);
    novo-> prox = NULL;
    return novo;
}
void liberar(No *tabela[]){
    for (int i = 0; i < TAM; i++)
    {
        No *atual = tabela[i];
        while(atual != NULL) {
            No *aux = atual;
            atual=atual->prox;
            free(aux);
        }
        tabela[i]=NULL;
    }
    
}
int main() {
    No *tabelaDicionario[TAM];
    inicializar(tabelaDicionario);

    //chamar o liberar(tabelaDicionario); na opção de sair do menu para liberar a memória
}
