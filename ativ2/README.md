# ATIVIDADE 2
1-

2- 1. Criamos duas estruturas uma No que contém o caractere e *proximo, e a Pilha que guarda o end do No no *topo. 2. PUSH malloc (reserva espaço), o valor preenche o espaço e então o novo nó aponta para o topo e atualiza. POP crio um ponteiro auxiliar chamado remover que aponta para a letra no topo, então passamos o topo para o próximo elemento e liberamos a memória do \*remover de onde ele estava atualmente. 3. na MAIN inicia o topo da pilha como NULL, o for percorre a String e realiza o push em cada letra, depois usa while(p.topo) que imprime a letra no topo (ultima) e desempilha para a próxima letra até que esvazie.
