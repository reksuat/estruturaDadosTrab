#include <stdio.h>
#include <stdlib.h>

int** alocarMatriz(){
    int **m;
    m = (int **) malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; i++)
    {
        m[i] = (int*) malloc(3 * sizeof(int));
    }
    return m;
}

int main(){
    
    int **original = alocarMatriz();
    int **identidade = alocarMatriz();
    int **total = alocarMatriz();

    int cont = 1;
printf("Matriz original: \n");
    for (int i = 0; i < 3; i++)
    {   for (int j = 0; j < 3; j++)
    {
        original[i][j] = cont++;
        printf("%d ", original[i][j]);
    }
    printf("\n");
    }
printf("\n Matriz identidade: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i==j)
            {
                identidade[i][j] = 1;
            }else{
                identidade[i][j] = 0;
            }
            printf("%d ", identidade[i][j]);
        }
        printf("\n");
    }
printf("\n Resultado da multiplicação: \n");
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        total[i][j] = 0;
        for (int k= 0; k < 3; k++)
        {
            total[i][j] += original[i][k] * identidade[k][j];
        }
        printf("%d ",total[i][j]);
    }
    printf("\n");
    
}
}