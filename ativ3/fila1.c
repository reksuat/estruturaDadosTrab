#include <stdio.h>
#include <stdlib.h>

typedef struct cliente
{
    int id;
    int tempoAtendimento;
    struct cliente *proximo;
} Cliente;

typedef struct {
    Cliente *inicio;
    Cliente *fim;
} Fila;

void enqueue(Fila *f, int id, int tempoAtendimento)
{
    Cliente *novo = malloc(sizeof(Cliente));
    
    if (novo)
    {
        novo-> id = id;
        novo-> tempoAtendimento = tempoAtendimento;
        novo->proximo = NULL;
        if(f->inicio == NULL){
            f->inicio = novo;
            f->fim = novo;
        }
        else {
           f->fim->proximo = novo;
           f->fim = novo;
        }
    }
    else {
        printf("Erro ao alocar memória.\n");
    } 
}

void dequeue(Fila *f){
    Cliente *remover = NULL;

    if(f->inicio) {
        remover = f->inicio;
        f->inicio = remover -> proximo;
        if (f->inicio == NULL)
        {
            f->fim = NULL;
        }
        free(remover);
    }
    else {
        printf("Fila vazia.\n");
    }
}

int main() {
    Fila f;
    f.inicio = NULL;
    f.fim = NULL;

    
    int id, tempoAtendimento, numClientes;
    int tempoEspera = 0;
    printf("Digite o número de clientes: ");
    scanf("%d", &numClientes);

    for(int i = 0; i <numClientes; i++){
        
        printf("Id do cliente: \n");
        scanf("%d", &id);
        printf("Tempo de atendimento: \n");
        scanf("%d", &tempoAtendimento);
        enqueue(&f, id, tempoAtendimento);
    }
    printf("Clientes atendidos: \n");
    while (f.inicio)
    {
        printf("Id: %d\nTempo de atendimento: %d\nTempo de espera: %d\n\n", f.inicio -> id, f.inicio -> tempoAtendimento, tempoEspera);
        tempoEspera += f.inicio -> tempoAtendimento;
        dequeue(&f);
    }
    
} 
