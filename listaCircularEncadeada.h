#ifndef LISTACIRCULARENCANDEADA_H
#define LISTACIRCULARENCANDEADA_H

typedef struct lista {
    int codAluno;
    int nota;
    struct lista* prox;
    struct lista* ant;
} Lista;

Lista* inicializa(void);
Lista* insere_inicio(Lista* l, int cod, int nota);
Lista* insere_ordenado(Lista* l, int cod, int nota);
Lista* busca(Lista* l, int cod);
Lista* retira(Lista* l, int cod);
void imprime(Lista* l);
void libera(Lista* l);
int vazia(Lista* l);

#endif

