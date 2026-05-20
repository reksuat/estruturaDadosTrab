#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;
No *criarNo(int num) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo) {
        novo->valor = num;
        novo->prox = NULL;
    } else {
        printf("[ERRO] Falha ao alocar memória.\n");
    }
    return novo;
}
void exibirLista(No *lista) {
    No *aux = lista;
    while (aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void inserirPosicao(No **lista, int num, int pos) {
    if (pos < 0) {
        printf("[ERRO] Posição inválida.\n");
        return;
    }
    No *novo = criarNo(num);
    // Inserir no início
    if (pos == 0) {
        novo->prox = *lista;
        *lista = novo;
        return;
    }
    No *aux = *lista;
    int i = 0;
    while (aux != NULL && i < pos - 1) {
        aux = aux->prox;
        i++;
    }
    if (aux == NULL) {
        printf("[ERRO] Posição inválida.\n");
        free(novo);
        return;
    }
    novo->prox = aux->prox;
    aux->prox = novo;


}
int buscarValor(No *lista, int valor) {
    No *atual = lista;
    int pos = 0;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return pos; // Valor encontrado
        }
        atual = atual->prox;
        pos++;
    }
    return -1; 
}
void inverterLista(No **lista) {
    No *anterior = NULL;
    No *atual = *lista;
    No *proximo = NULL;
    while (atual != NULL) {
        proximo = atual->prox; 
        atual->prox = anterior; 
        anterior = atual; 
        atual = proximo; 
    }
    *lista = anterior;
}
void dividirLista(No *lista, No **lista1, No **lista2) {
    if (lista == NULL) {
        *lista1 = NULL;
        *lista2 = NULL;
        return;
    }
    No *slow = lista;
    No *fast = lista;
    while (fast->prox != NULL && fast->prox != NULL) {
        slow = slow->prox;
        fast = fast->prox->prox;
    }
    *lista1 = lista; 
    *lista2 = slow->prox; 
    slow->prox = NULL; 
}
int main() {
    int opcao=-1, num, pos, busca, valorBusca;
    No *lista = NULL;
    No *lista1 = NULL;
    No *lista2 = NULL;
    while (opcao != 0)
    {
        printf("GERENCIADOR DE LISTA\n");
        printf("1 - Inserir valor em posição\n");
        printf("2 - Buscar valor\n");
        printf("3 - Inverter lista\n");
        printf("4 - Dividir lista ao meio\n");
        printf("5 - Exibir lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao)
        {        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &num);
            printf("Digite a posição para inserção: ");
            scanf("%d", &pos);
            inserirPosicao(&lista, num, pos);
            break;
        case 2:
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valorBusca);
            busca = buscarValor(lista, valorBusca);
            if (busca != -1) {
                printf("Valor encontrado na posição: %d\n", busca);
            } else {
                printf("Valor não encontrado.\n");
            }
            break;
        case 3:
            printf("Inverter lista\n");
            inverterLista(&lista);
            printf("Lista invertida: \n");
            exibirLista(lista);
            break;
        case 4:
            printf("Dividir lista ao meio\n");
            dividirLista(lista, &lista1, &lista2);
            printf("Listas divididas:\n");
            printf("Lista 1: ");
            exibirLista(lista1);
            printf("Lista 2: ");
            exibirLista(lista2);
            break;
        case 5:
            printf("Lista: \n");
            exibirLista(lista);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida, Tente novamente.\n");
            break;
        }
    }
}