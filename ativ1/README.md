            ATIVIDADE 1
1- usa o CHAR para declarar as 3 variáveis usando biblioteca  <stdlib.h>, mostrar a mensagem na tela para que o usuário escreva as 3 palavras seguida uma da outra, scanf para guardar em formato de String e a inversão direta alterando a ordem da saída dos dados (3,2,1).

2- Declara o numeros com espaço de 5 inteiros, mostra a mensagem para que digite, inicia o laço de repetição para guardar 5 números no scanf, em seguida uma mensagem para a ordem inversa, novamente utiliza o laço de repetição mas inicia em 4 e decrementa até que chegue a zero exibindo a nova ordem com um printf.

3-

4- 1. Primeiro foi feito uma função para guardar memória com malloc para depois ser chamada nas 3 matrizes (original, identidade e por fim o total). Na original foi atribuido os valores com um contador no for {1,2,3} {4,5,6} {7,8,9}.
   2. Para ter o valor da matriz de identidade foi utilizado o for para passar por i e j, quando o valor da linha e coluna forem iguais será 1, caso contrário 0, assim forma {1,0,0} {0,1,0} {0,0,1}.
   3. Por fim para obter o resultado foi feito 3 for alinhados para que passe pela linha da original e a coluna da identidade, o K é a ponte O i e o j escolhem a posição do resultado, e o k funciona como um intermediário percorre ambos multiplicando e somando em uma nova matriz. no final usei o free para liberar a memória.
   
