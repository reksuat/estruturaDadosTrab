
#include <stdio.h>
#include <stdlib.h>

struct Aluno
{
    char nome[50];
    int matricula;
    float mFinal;
};

int main(){
    struct Aluno lista[10];
    struct Aluno aprovados[10];
    struct Aluno reprovados[10];

    for (int i = 0; i < 10; i++)
    {
        printf("Aluno %d: \n", i+1);
        printf("Nome: \n");
        scanf("%s", lista[i].nome );
        printf("Num matrícula: \n");
        scanf("%d", &lista[i].matricula);
        printf("Média final: \n");
        scanf("%f", &lista[i].mFinal);
    }
    int ap = 0;
    int re = 0;
    for (int i = 0; i < 10; i++)
    {
        if (lista[i].mFinal>=5 && lista[i].mFinal<=10)
        {
            aprovados[ap] = lista[i];
            ap++; 
        } else {
            reprovados[re] = lista[i];
            re++;
        }
        
    }
    printf("Lista de aprovados\n");
    for (int i = 0; i < ap ; i++)
    {
        printf("Nome: %s | Matrícula: %d | Média final: %.2f \n",aprovados[i].nome, aprovados[i].matricula, aprovados[i].mFinal);
    }
    printf("Lista de reprovados\n");
    for (int i = 0; i < re; i++)
    {
printf("Nome: %s | Matrícula: %d | Média final: %.2f \n",reprovados[i].nome, reprovados[i].matricula, reprovados[i].mFinal);
    }
}