#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int *vetor = (int *)malloc(5 * sizeof(int));

    printf("Digite 5 numeros inteiros:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", (vetor + i));
    }

    printf("\nVetor na ordem inversa:\n");
    for (i = 4; i >= 0; i--) {
        printf("%d ", *(vetor + i));
    }
    free(vetor);

    return 0;
}