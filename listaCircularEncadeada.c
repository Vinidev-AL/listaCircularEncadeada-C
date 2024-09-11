#include <stdio.h>
#include <stdlib.h>
#include "listaCircularEncadeada.h"

Lista* inicializa(void) {
    return NULL;
}

Lista* insere_inicio(Lista* l, int cod, int nota) {
    Lista* novoNO = (Lista*) malloc(sizeof(Lista));
    novoNO->codAluno = cod;
    novoNO->nota = nota;

    if (l == NULL) { 
        novoNO->prox = novoNO;
        novoNO->ant = novoNO;
        return novoNO;
    }


    Lista* ultimo = l->ant;
    novoNO->prox = l;
    novoNO->ant = ultimo;
    l->ant = novoNO;
    ultimo->prox = novoNO;

    return novoNO;
}

Lista* insere_ordenado(Lista* l, int cod, int nota) {
    Lista* novoNo = (Lista*) malloc(sizeof(Lista));
    novoNo->codAluno = cod;
    novoNo->nota = nota;

    if (l == NULL) { 
        novoNo->prox = novoNo;
        novoNo->ant = novoNo;
        return novoNo;
    }

    Lista* p = l;
    do {
        if (p->codAluno >= cod) {
            break;
        }
        p = p->prox;
    } while (p != l);

    novoNo->prox = p;
    novoNo->ant = p->ant;
    p->ant->prox = novoNo;
    p->ant = novoNo;

    if (p == l && p->codAluno >= cod) {
        return novoNo;
    }

    return l;
}

Lista* busca(Lista* l, int cod) {
    if (l == NULL) return NULL;
    Lista* p = l;
    do {
        if (p->codAluno == cod) {
            return p;
        }
        p = p->prox;
    } while (p != l);
    return NULL;
}

Lista* retira(Lista* l, int cod) {
    if (l == NULL) return NULL;

    Lista* p = l;
    do {
        if (p->codAluno == cod) {
            if (p->prox == p) {
                free(p);
                return NULL;
            }

            p->ant->prox = p->prox;
            p->prox->ant = p->ant;

            if (p == l) { 
                l = p->prox;
            }

            free(p);
            return l;
        }
        p = p->prox;
    } while (p != l);

    return l;
}

void imprime(Lista* l) {
    if (l == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Lista* p = l;
    do {
        printf("Aluno = %d\n", p->codAluno);
        printf("Nota = %d\n", p->nota);
        printf("-----------Fim----------\n");
        p = p->prox;
    } while (p != l);
}

void libera(Lista* l) {
    if (l == NULL) return;

    Lista* p = l;
    do {
        Lista* temp = p->prox;
        free(p);
        p = temp;
    } while (p != l);
}

int vazia(Lista* l) {
    return (l == NULL);
}

