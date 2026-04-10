#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char letra;
    struct no *proximo;
} No;
typedef struct pilha{
    No *topo;
} Pilha;

void push(Pilha *p, char valor){
    No *novo = malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao alocar memória\n");
        return;
    }
    novo->letra = valor;
    novo->proximo = p->topo;
    p->topo = novo;
}
void pop(Pilha *p) {
    if (p->topo == NULL) {
        printf("Pilha vazia\n");
        return;
    }
    No *remover = p->topo;
    p->topo = remover->proximo;
    free(remover);
    
}

int main(){
    Pilha p;
    p.topo = NULL;
    char frase[100];
    printf("Digite uma String: ");
    fgets(frase, sizeof(frase), stdin); 
    for(int i = 0; i < strlen(frase); i++){
        push(&p, frase[i]);
    }
    printf("String invertida: ");
    while(p.topo){
        printf("%c", p.topo->letra);
        pop(&p);
    }
    printf("\n");
    return 0;

}