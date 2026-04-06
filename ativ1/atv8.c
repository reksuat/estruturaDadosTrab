#include <stdio.h>

int main() {
    
    int vetor[5];
    int *p;
    
    p = vetor;
    
    for(int i = 0; i < 5; i++) {
        printf("Digite um número: ");
        scanf("%d", (p + i));
    }
    
    printf("\n O dobro dos valores:\n");
    
    for (int i = 0; i < 5; i++) {
        printf("%d\n", *(p + i) * 2);
    }

    return 0;
}
