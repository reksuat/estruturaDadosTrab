#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int id;
    int paginas;
    int prioridade;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
} Fila;

void inicializar(Fila* f) {
    f->inicio = NULL;
}

void inserir(Fila* f, int id, int paginas, int prioridade) {
    No* novo = (No*) malloc(sizeof(No));
    novo->id = id;
    novo->paginas = paginas;
    novo->prioridade = prioridade;
    novo->prox = NULL;

    if (f->inicio == NULL || prioridade < f->inicio->prioridade) {
        novo->prox = f->inicio;
        f->inicio = novo;
        return;
    }

    No* atual = f->inicio;

    while (atual->prox != NULL && atual->prox->prioridade <= prioridade) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

void remover(Fila* f) {
    if (f->inicio == NULL) {
        printf("Fila vazia\n");
        return;
    }

    No* temp = f->inicio;

    printf("Imprimindo ID:%d Pag:%d Pri:%d\n",
           temp->id, temp->paginas, temp->prioridade);

    f->inicio = temp->prox;
    free(temp);
}

void mostrar(Fila* f) {
    No* atual = f->inicio;

    while (atual != NULL) {
        printf("ID:%d Pag:%d Pri:%d\n",
               atual->id, atual->paginas, atual->prioridade);
        atual = atual->prox;
    }
}

int main() {
    Fila f;
    inicializar(&f);

    int opcao;

    do {
        printf("\n1 - Inserir\n2 - Imprimir\n3 - Mostrar fila\n0 - Sair\n");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id, paginas, prioridade;

            printf("ID: ");
            scanf("%d", &id);

            printf("Paginas: ");
            scanf("%d", &paginas);

            printf("Prioridade: ");
            scanf("%d", &prioridade);

            inserir(&f, id, paginas, prioridade);
        }

        else if (opcao == 2) {
            remover(&f);
        }

        else if (opcao == 3) {
            mostrar(&f);
        }

    } while (opcao != 0);

    return 0;
}
