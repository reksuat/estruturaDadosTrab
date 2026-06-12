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
        tabela[i] = NULL;
}

int funcaoHash(char palavra[]){
    int soma = 0;
    for (int i = 0; palavra[i] != '\0'; i++)
        soma += palavra[i];
    return soma % TAM;
}

No *criarNo(char palavra[], char definicao[]){
    No *novo = (No*) malloc(sizeof(No));
    if(novo == NULL){
        printf("*ERRO* Não foi possível alocar memória.\n");
        return NULL;
    }
    strcpy(novo->palavra, palavra);
    strcpy(novo->definicao, definicao);
    novo-> prox = NULL;
    return novo;
}

void liberar(No *tabela[]) {
    for (int i = 0; i < TAM; i++) {
        No *atual = tabela[i];
        while(atual != NULL) {
            No *aux = atual;
            atual=atual->prox;
            free(aux);
        }
        tabela[i]=NULL;
    }
}

/* remove essa parte quando add sua parte Nathaly*/
void exibirEstatisticas(No *tabela[]) {
    (void)tabela;
    printf("*INFO* Estatísticas\n");
}

void inserir(No *tabela[], char palavra[], char definicao[]) {
    int idx = funcaoHash(palavra);

    No *atual = tabela[idx];
    while (atual != NULL) {
        if (strcmp(atual->palavra, palavra) == 0) {
            printf("*AVISO* Palavra \"%s\" já existe. Use a opção de atualização.\n", palavra);
            return;
        }
        atual = atual->prox;
    }

    No *novo = criarNo(palavra, definicao);
    if (novo == NULL) return;

    novo->prox  = tabela[idx];
    tabela[idx] = novo;

    printf("*OK* \"%s\" inserida no índice %d.\n", palavra, idx);
}

No *buscar(No *tabela[], char palavra[]) {
    int idx   = funcaoHash(palavra);
    No *atual = tabela[idx];

    while (atual != NULL) {
        if (strcmp(atual->palavra, palavra) == 0)
            return atual;
        atual = atual->prox;
    }
    return NULL;
}

void remover(No *tabela[], char palavra[]) {
    int idx      = funcaoHash(palavra);
    No *atual    = tabela[idx];
    No *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->palavra, palavra) == 0) {
            if (anterior == NULL)
                tabela[idx] = atual->prox;
            else
                anterior->prox = atual->prox;

            free(atual);
            printf("*OK* \"%s\" removida com sucesso.\n", palavra);
            return;
        }
        anterior = atual;
        atual    = atual->prox;
    }

    printf("*AVISO* Palavra \"%s\" não encontrada.\n", palavra);
}

void exibirTabela(No *tabela[]) {
    printf("\n -------------- TABELA HASH ----------------\n");

    int vazia = 1;
    for (int i = 0; i < TAM; i++) {
        if (tabela[i] != NULL) {
            vazia = 0;
            printf("\n[%02d] ", i);
            No *atual = tabela[i];
            while (atual != NULL) {
                printf(" -> \"%s\" ", atual->palavra);
                if (atual->prox != NULL)
                    printf("*colisão*");
                atual = atual->prox;
            }
        }
    }

    if (vazia)
        printf("\n**tabela vazia**\n");
    printf("\n");
}

static void lerString(const char *prompt, char *dest, int tamanho) {
    printf("%s", prompt);
    fgets(dest, tamanho, stdin);
    dest[strcspn(dest, "\n")] = '\0';
}

static void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void menu(No *tabela[]) {
    int opcao;

    do {
        printf("\n -- DICIONARIO -----------------------------\n");
        printf("  1. Inserir palavra\n");
        printf("  2. Buscar palavra\n");
        printf("  3. Remover palavra\n");
        printf("  4. Exibir tabela\n");
        printf("  5. Exibir estatisticas\n");
        printf("  0. Sair\n");
        printf(" --------------------------------------------\n");
        printf(" Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            printf("*ERRO* Entrada inválida.\n");
            opcao = -1;
            continue;
        }
        limparBuffer();

        char palavra[50];
        char definicao[300];
        No  *resultado;

        switch (opcao) {
            case 1:
                lerString("Palavra: ", palavra,   sizeof(palavra));
                lerString("Definição: ", definicao, sizeof(definicao));
                inserir(tabela, palavra, definicao);
                break;

            case 2:
                lerString("Palavra para buscar: ", palavra, sizeof(palavra));
                resultado = buscar(tabela, palavra);
                if (resultado)
                    printf("\n*ENCONTRADA*\n  Palavra: %s\n  Definição: %s\n",
                           resultado->palavra, resultado->definicao);
                else
                    printf("*AVISO* \"%s\" não encontrada.\n", palavra);
                break;

            case 3:
                lerString("Palavra para remover: ", palavra, sizeof(palavra));
                remover(tabela, palavra);
                break;

            case 4:
                exibirTabela(tabela);
                break;

            case 5:
                exibirEstatisticas(tabela);
                break;

            case 0:
                printf("Encerrando... memória liberada.\n");
                liberar(tabela);
                break;

            default:
                printf("*ERRO* Opção inválida.\n");
        }

    } while (opcao != 0);
}

int main(void) {
    No *tabelaDicionario[TAM];
    inicializar(tabelaDicionario);
    menu(tabelaDicionario);
    return 0;
}
