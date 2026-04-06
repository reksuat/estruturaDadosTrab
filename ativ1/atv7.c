#include <stdio.h>
#include <string.h>

const int maxLivros = 5;

struct Livro {
    char titulo[31];
    char autor[16];
    int ano;
};

int main() {
    struct Livro livros[maxLivros];
    char busca[31];
    int i, numLivros = 0;

for (i = 0; i < maxLivros; i++) {
    printf("\nLivro %d:\n", i + 1);

    printf("Titulo: ");
    fgets(livros[i].titulo, 31, stdin);
    livros[i].titulo[strcspn(livros[i].titulo, "\n")] = '\0';

    printf("Autor: ");
    fgets(livros[i].autor, 16, stdin);
    livros[i].autor[strcspn(livros[i].autor, "\n")] = '\0';

    printf("Ano: ");
    scanf("%d", &livros[i].ano);
    getchar();
    }
printf("\nDigite o titulo que deseja buscar: ");
    fgets(busca, 31, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    printf("\nResultados encontrados:\n");

    for (i = 0; i < maxLivros; i++) {
        if (strcmp(livros[i].titulo, busca) == 0) {
            printf("\nTitulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Ano: %d\n", livros[i].ano);
            numLivros++;
        }
    }

    if (numLivros == 0) {
        printf("Nenhum livro encontrado com esse titulo.\n");
    }

    return 0;
}
