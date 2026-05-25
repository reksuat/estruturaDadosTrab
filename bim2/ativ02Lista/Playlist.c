#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char musica[100];
    struct No *prox;
    struct No *ant;
} No;

void adicionarMusica(No **head, char *nome) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) {
        fprintf(stderr, "Erro: falha na alocacao de memoria.\n");
        return;
    }
    strncpy(novo->musica, nome, 99);
    novo->musica[99] = '\0';

    if (*head == NULL) {
        novo->prox = novo;
        novo->ant  = novo;
        *head = novo;
        return;
    }

    No *ultimo  = (*head)->ant;
    ultimo->prox = novo;
    novo->ant    = ultimo;
    novo->prox   = *head;
    (*head)->ant = novo;
}

void proximaMusica(No **atual) {
    if (*atual == NULL) return;
    *atual = (*atual)->prox;
}

void musicaAnterior(No **atual) {
    if (*atual == NULL) return;
    *atual = (*atual)->ant;
}

void exibirPlaylist(No *head) {
    if (head == NULL) {
        printf("  (playlist vazia)\n");
        return;
    }
    No *p = head;
    int i = 1;
    do {
        printf("  [%d] %s\n", i++, p->musica);
        p = p->prox;
    } while (p != head);
}

int totalMusicas(No *head) {
    if (head == NULL) return 0;
    int count = 0;
    No *p = head;
    do { count++; p = p->prox; } while (p != head);
    return count;
}

void liberarPlaylist(No **head) {
    if (*head == NULL) return;
    int total = totalMusicas(*head);
    No *atual = *head, *prox;
    for (int i = 0; i < total; i++) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *head = NULL;
}

void tocarTodasMusicas(No *head) {
    if (head == NULL) { printf("  Playlist vazia.\n"); return; }
    int total = totalMusicas(head);
    No *atual = head;
    for (int i = 0; i < total; i++) {
        printf("  [%d/%d] >> %s\n", i + 1, total, atual->musica);
        atual = atual->prox;
    }
    printf(" fim da playlist (%d musicas tocadas)\n", total);
}

int removerMusica(No **head, No **atual, int num) {
    int total = totalMusicas(*head);
    if (num < 1 || num > total) return 0;

    No *alvo = *head;
    for (int i = 1; i < num; i++) alvo = alvo->prox;

    if (total == 1) {
        free(alvo);
        *head  = NULL;
        *atual = NULL;
        return 1;
    }

    alvo->ant->prox = alvo->prox;
    alvo->prox->ant = alvo->ant;

    if (alvo == *head)  *head  = alvo->prox;
    if (alvo == *atual) *atual = alvo->prox;

    free(alvo);
    return 1;
}

void imprimirMenu(void) {
    printf("\n   ♪♫♪♪♫♪ PLAYLIST ♪♫♪♪♫♪     \n");
    printf("---------------------------------\n");
    printf("  1. Adicionar Musica\n");
    printf("  2. Proxima Musica\n");
    printf("  3. Musica Anterior\n");
    printf("  4. Exibir Playlist\n");
    printf("  5. Total Musicas\n");
    printf("  6. Tocar todas musicas\n");
    printf("  7. Remover Musica\n");
    printf("  0. Sair / liberar Playlist\n");
    printf("---------------------------------\n");
}

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    No *head  = NULL;
    No *atual = NULL;
    int opcao;
    char nome[100];

    adicionarMusica(&head, "Rock Legal");
    adicionarMusica(&head, "Jazz Doido");
    adicionarMusica(&head, "Pop Dançante");
    atual = head;

    printf("Playlist carregada com 3 musicas de exemplo.\n");

    do {
        imprimirMenu();

        if (atual != NULL)
            printf("🎧  Musica atual: [%s] \n", atual->musica);
        else
            printf("🎧  Musica atual: (nenhuma)\n");

        printf("\nOpcao: ");
        if (scanf("%d", &opcao) != 1) { limparBuffer(); continue; }
        limparBuffer();

        switch (opcao) {

            case 1:
                printf("♪ Nome da musica: ♪");
                if (fgets(nome, sizeof(nome), stdin) == NULL) break;
                nome[strcspn(nome, "\n")] = '\0';
                if (nome[0] == '\0') { printf("Nome invalido.\n"); break; }
                adicionarMusica(&head, nome);
                if (atual == NULL) atual = head;
                printf("  \"%s\" adicionada. Total: %d\n", nome, totalMusicas(head));
                break;

            case 2:
                if (atual == NULL) { printf("  Playlist vazia.\n"); break; }
                proximaMusica(&atual);
                printf("♪ Proxima: %s ♪\n", atual->musica);
                break;

            case 3:
                if (atual == NULL) { printf("  Playlist vazia.\n"); break; }
                musicaAnterior(&atual);
                printf("♪ Anterior: %s ♪\n", atual->musica);
                break;

            case 4:
                printf("\n♪ Exibir Playlist ♪\n");
                exibirPlaylist(head);
                break;

            case 5:
                printf("♪ Total Musicas = %d ♪\n", totalMusicas(head));
                break;

            case 6:
                printf("\n♪ Tocar Todas Musicas ♪\n");
                tocarTodasMusicas(head);
                break;

            case 7: {
                int total = totalMusicas(head);
                if (total == 0) { printf("  Playlist vazia.\n"); break; }
                printf("  Qual numero remover? (1-%d): ", total);
                int num;
                if (scanf("%d", &num) != 1) { limparBuffer(); break; }
                limparBuffer();
                if (removerMusica(&head, &atual, num))
                    printf("  Musica %d removida. Total: %d\n", num, totalMusicas(head));
                else
                    printf("  Numero invalido.\n");
                break;
            }

            case 0:
                printf("\nliberar Playlist\n");
                liberarPlaylist(&head);
                atual = NULL;
                printf("Memoria liberada. Encerrando.\n");
                break;

            default:
                printf("  Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}
