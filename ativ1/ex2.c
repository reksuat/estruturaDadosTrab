#include <stdio.h>
int main(){
    int numeros[5];
    printf("Digite 5 numeros (int): ");

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &numeros[i]);
    }
    printf("Ordem inversa: ");
    for (int i = 4; i >= 0; i--)
    {
        printf("\n%d", numeros[i]);
    }
}