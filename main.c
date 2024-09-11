#include <stdio.h>
#include "listaCircularEncadeada.h"

int main(void) {
    Lista* l = inicializa();
    
    l = insere_ordenado(l, 23, 67); 
    l = insere_ordenado(l, 45, 98); 
    l = insere_ordenado(l, 56, 87); 
    l = insere_ordenado(l, 78, 89); 
    
    imprime(l);

    Lista* aluno = busca(l, 45);
    if (aluno != NULL) {
        printf("Nota do aluno 45: %d\n", aluno->nota);
    }

    l = retira(l, 78);
    imprime(l); 

    l = retira(l, 45);
    imprime(l); 

    libera(l); 

    return 0;
}

