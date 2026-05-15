#include <stdio.h>
#include <stdlib.h>

//Versão ingênua: calcula o mesmo valor várias vezes, sendo ineficiente.
long long fib_ingenua(int n, int *cont) {
    (*cont)++;
    //Caso base: quando n é 0 ou 1, ele retorna o próprio n.
    if (n <= 1) return n;
    //Redução do problema: o valor diminui até chegar no caso base.
    return fib_ingenua(n - 1, cont) + fib_ingenua(n - 2, cont);
}

//Versão otimizada: usa memoização para evitar cálculos repetidos.
long long fib_memoizada(int n, long long *cache, int *cont) {
    (*cont)++;
    
    //Caso base do cache: se o resultado já estiver armazenado, retorna-o imediatamente.
    if (cache[n] != -1) return cache[n];
    
    //Caso base recursivo: retorna n se n for 0 ou 1.
    if (n <= 1) return cache[n] = n;
    
    //Redução do problema: armazena o resultado da soma no cache dinâmico para uso futuro.
    cache[n] = fib_memoizada(n - 1, cache, cont) + fib_memoizada(n - 2, cache, cont);
    return cache[n];
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Insira um numero maior ou igual a zero.\n");
        return 1;
    }

    //Preparação para a versão ingênua
    int chamadas_ingenua = 0;
    long long res_ingenua = fib_ingenua(n, &chamadas_ingenua);

    //Preparação para a versão otimizada com alocação dinâmica
    int chamadas_memoizada = 0;
    long long *cache = (long long *)malloc((n + 1) * sizeof(long long));
    
    //Inicializa o cache com -1 (indicando que nada foi calculado ainda)
    for (int i = 0; i <= n; i++) {
        cache[i] = -1;
    }

    long long res_memoizada = fib_memoizada(n, cache, &chamadas_memoizada);

    //Exibição e comparação dos resultados (Conforme orientação 3)
    printf("\n--- Comparacao para n = %d ---\n", n);
    printf("Resultado (Ingenuo): %lld | Chamadas: %d\n", res_ingenua, chamadas_ingenua);
    printf("Resultado (Otimizado): %lld | Chamadas: %d\n", res_memoizada, chamadas_memoizada);
    printf("Diferenca de eficiencia: %d chamadas a menos na versao otimizada.\n", 
           chamadas_ingenua - chamadas_memoizada);

    //Liberação da memória alocada dinamicamente
    free(cache);

    return 0;
}
