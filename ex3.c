#include <stdio.h>
#include <stdlib.h>

int main() {
    int *matriz = (int *)malloc(3 * 3 * sizeof(int));

    for (int i = 0; i < 9; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", (matriz + i));
    }
    for (int i = 0; i < 9; i++) {
        *(matriz + i) = *(matriz + i) * 5;
    }
    printf("\nResultado da matriz (cada elemento x 5):\n");

    for (int i = 0; i < 9; i++) {
        printf("%d ", *(matriz + i));
        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
    free(matriz);

    return 0;
}