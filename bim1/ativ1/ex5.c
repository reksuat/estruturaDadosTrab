#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor = (int *) malloc(3 * sizeof(int));
    printf("Digite 3 números para o vetor: ");
    for (int i = 0; i < 3; i++)
    {
     scanf("%d", &vetor[i]);   
    }
    int **matriz = (int **) malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
    {
        matriz[i] = (int *) malloc(3 * sizeof(int));
    }
    printf("\nPreencha a matriz 3x3: ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
          scanf("%d", &matriz[i][j]);
        }
        
    }
    int *total = (int *) malloc(3 * sizeof(int));
    printf("\nResultado da multiplicação entre vetor e matriz: \n");
    for (int i = 0; i < 3; i++)
    {
       total[i] = 0;
       for (int j = 0; j < 3; j++)
       {
        total[i] += matriz[j][i] * vetor[j];
       }
       printf(" %d",total[i]);
    }

    for (int k = 0; k < 3; k++)
    {
        free(matriz[k]);
    }
    free(matriz);
    free(vetor);
    free(total);
}