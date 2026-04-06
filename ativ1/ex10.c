#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    float nota;
} Aluno;

Aluno* maiorNota(Aluno *ptrAlunos, int n) {
    Aluno *melhor = ptrAlunos;

    for (int i = 1; i < n; i++) {
        if ((ptrAlunos + i)->nota > melhor->nota) {
            melhor = (ptrAlunos + i);
        }
    }
    return melhor;
}

int main() {
    int n;
    Aluno *ptrAlunos;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);
    getchar();

    ptrAlunos = (Aluno *)malloc(n * sizeof(Aluno));

    if (ptrAlunos == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nome do aluno %d: ", i + 1);
        fgets((ptrAlunos + i)->nome, 50, stdin);
        (ptrAlunos + i)->nome[strcspn((ptrAlunos + i)->nome, "\n")] = 0;

        printf("Nota do aluno %d: ", i + 1);
        scanf("%f", &(ptrAlunos + i)->nota);
        getchar();
    }

    Aluno *vencedor = maiorNota(ptrAlunos, n);

    printf("\nAluno com a maior nota\n");
    printf("Nome: %s\n", vencedor->nome);
    printf("Nota: %.2f\n", vencedor->nota);

    free(ptrAlunos);

    return 0;
}
