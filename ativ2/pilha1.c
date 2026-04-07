#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No* prox;
} No;

typedef struct {
    No* topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = NULL;
}

int vazia(Pilha* p) {
    return p->topo == NULL;
}

void push(Pilha* p, char c) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = c;
    novo->prox = p->topo;
    p->topo = novo;
}

char pop(Pilha* p) {
    if (vazia(p)) return '\0';

    No* temp = p->topo;
    char valor = temp->dado;
    p->topo = temp->prox;
    free(temp);

    return valor;
}

int combina(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') ||
           (abertura == '{' && fechamento == '}') ||
           (abertura == '[' && fechamento == ']');
}

int balanceada(char* expr) {
    Pilha p;
    inicializar(&p);

    for (int i = 0; i < strlen(expr); i++) {
        char c = expr[i];

        if (c == '(' || c == '{' || c == '[') {
            push(&p, c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (vazia(&p)) return 0;

            char topo = pop(&p);

            if (!combina(topo, c)) return 0;
        }
    }

    return vazia(&p);
}

int main() {
    char expressao[100];

    printf("Digite a expressão: ");
    fgets(expressao, 100, stdin);

    expressao[strcspn(expressao, "\n")] = '\0';

    if (balanceada(expressao)) {
        printf("Expressão Válida!\n");
    } else {
        printf("Expressão Inválida!\n");
    }

    return 0;
}
