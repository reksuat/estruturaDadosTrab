#include <stdio.h>
#include <stdlib.h>
// Fibonacci recursivo ineficiente, pois calcula o mesmo valor várias vezes.
// Ineficiente pelo excesso de chamadas.

int fibonacci(int n, int *cont){
    (*cont)++;
    // Casos base: quando n é 0 ou 1 ele retorna o n.
    if (n==0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    // Valor diminui até chegar no caso base
    return fibonacci(n-1, cont) + fibonacci(n-2, cont);
}

int main() {
    int n, cont = 0;
    printf("Digite um numero: ");
    scanf("%d", &n);
// Numeros grandes (ex: 40) demoram para calcular ou podem estourar a pilha.
    int resultado = fibonacci(n, &cont);
    printf("Fibonacci do numero %d: %d\n", n, resultado);
    printf("Numero de chamadas: %d\n", cont);
    return 0;
}