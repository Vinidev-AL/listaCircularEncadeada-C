#include <stdio.h>
#include <stdlib.h>
#include "listaCircularEncadeada.h"

int main(void) {
    Lista* lista = inicializa();


    lista = insere_ordenado(lista, 23, 67);
    lista = insere_ordenado(lista, 45, 98);
    lista = insere_ordenado(lista, 56, 87);
    lista = insere_ordenado(lista, 78, 89);

    printf("Lista de Alunos:\n");
    imprime(lista);


    int codBusca = 45;
    Lista* aluno = busca(lista, codBusca);
    if (aluno != NULL) {
        printf("Nota do aluno %d: %d\n", aluno->codAluno, aluno->nota);
    } else {
        printf("Aluno com ID COD não encontrado.\n", codBusca);
    }

    lista = retira(lista, 78);
    printf("Lista apos retirar o aluno 78:\n");
    imprime(lista);

    lista = retira(lista, 45);
    printf("Lista apos retirar o aluno 45:\n");
    imprime(lista);

    libera(lista);

    return 0;
}
