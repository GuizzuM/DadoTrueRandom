#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no{//Um dia eu faço árvore Binária ou B sla.
    short int valor;
    struct no *prox;
}No;
typedef struct{
    No *inicio, *fim;
 }Lista;

int reduzir(unsigned int random_number, int m);

void imprimir(short int result);

void inserirInicio(Lista *lista, short int valor);

void somarLista(Lista *lista, short int valor);

void remover(Lista *lista);

#endif // LISTA_H_INCLUDED
