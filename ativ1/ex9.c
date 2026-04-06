#include <stdio.h>

int ordem(int *a, int *b, int *c) {
    int temp;

    if (*a > *b) { temp = *a; *a = *b; *b = temp; }
    if (*a > *c) { temp = *a; *a = *c; *c = temp; }
    if (*b > *c) { temp = *b; *b = *c; *c = temp; }

    if (*a == *b && *b == *c) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n1, n2, n3;

    printf("Digite três valores:\n");
    scanf("%d %d %d", &n1, &n2, &n3);

    int NIguais = ordem(&n1, &n2, &n3);

    printf("\nValores ordenados:\n");
    printf("Primeira variável: %d\n", v1);
    printf("Segunda variável:  %d\n", v2);
    printf("Terceira variável: %d\n", v3);

    if (NIguais) {
        printf("\nResultado da função: 1\n");
    } else {
        printf("\nResultado da função: 0\n");
    }

    return 0;
}
