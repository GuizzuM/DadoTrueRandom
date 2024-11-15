#include "lista.h"
#include <stdio.h>


int reduzir(unsigned int random_number, int m){
    short int min = 1;
    short int max = m;
    short int a = min + (random_number % (max - min + 1));
    return a;
}

void imprimir(short int result){
    printf("\t");
    printf("%d ", result);
}


void inserirInicio(Lista *lista, short int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    if(lista->inicio == NULL){
        novo->prox = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->prox = lista->inicio;
        lista->inicio = novo;
    }
 }
void somarLista(Lista *lista, short int valor){
    short int rep=0;
    No *inicio = lista->inicio;
    if(inicio == NULL)
        return;
    else{
        while(inicio != NULL){
                if(inicio->valor == valor){
                    rep++;
                    }
                inicio = inicio->prox;
        }
    }
    short int soma = valor * rep;
    if (rep == 0 || rep == 1)
        return;
    printf("\n\n\t\tSoma dos %d's: %d\n", valor, soma);
}

 void remover(Lista *lista){
    No *inicio = lista->inicio;
    No *noARemover = NULL;
    if(inicio != NULL){
        while(inicio!= NULL){
            noARemover = inicio;
            inicio = inicio->prox;
            if(noARemover != NULL){
                free(noARemover);
            }

        }
    }
    lista->inicio = NULL;
    lista->fim = NULL;
 }
