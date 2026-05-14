#include <stdio.h>
#include <stdlib.h>

int main() {
    char *p1 = (char *)malloc(30 * sizeof(char));
    char *p2 = (char *)malloc(30 * sizeof(char));
    char *p3 = (char *)malloc(30 * sizeof(char));

    printf("Escreva 3 palavras: ");
    scanf("%s %s %s", p1, p2, p3);

    printf("Ordem inversa: \n%s \n%s \n%s\n", p3, p2, p1);
    free(p1);
    free(p2);
    free(p3);

    return 0;
}