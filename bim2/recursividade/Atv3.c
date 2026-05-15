#include <stdio.h>

void move(int n, char origem, char destino, char auxiliar, int *total_mov) {

    if (n == 1) {
        printf("Mover disco 1: %c -> %c\n", origem, destino);
        (*total_mov)++;
        return;
    }

    move(n - 1, origem, auxiliar, destino, total_mov);
    
    printf("Mover disco %d: %c -> %c\n", n, origem, destino);
    (*total_mov)++;
    
    move(n - 1, auxiliar, destino, origem, total_mov);
}

int main() {
    int n;
    int contador_movimentos = 0;

    printf("Torre de Hanoi\n");
    printf("Digite a quantidade de discos: ");
    scanf("%d", &n);
    
    printf("\nLista de movimentos:\n");
    
    move(n, 'A', 'C', 'B', &contador_movimentos);

    printf("\nTotal de movimentos gerados: %d\n", contador_movimentos);
    return 0;
}
