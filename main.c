#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wincrypt.h>

int gerar(int a){

    HCRYPTPROV hProv;
    BYTE randomBytes[4]; // Array de 4 bytes para gerar um n�mero de 32 bits
    unsigned int random_number = 0;

    // Inicializa o provedor de contexto criptogr�fico
    if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)) {
        printf("Falha ao adquirir o contexto criptogr�fico\n");
        return -1;
    }

    // Gera n�meros aleat�rios
    if (!CryptGenRandom(hProv, sizeof(randomBytes), randomBytes)) {
        printf("Falha ao gerar o n�mero aleat�rio\n");
        CryptReleaseContext(hProv, 0);
        return -1;
    }

    // Converte os bytes aleat�rios para um n�mero inteiro
    random_number = (randomBytes[0] << 24) | (randomBytes[1] << 16) | (randomBytes[2] << 8) | randomBytes[3];

    int max = a;
        a= reduzir(random_number, max);
        imprimir(a);
    return a;

}

int reduzir(unsigned int random_number, int m){
    int min = 1;
    int max = m;
    int a = min + (random_number % (max - min + 1));
    return a;
}

void imprimir(int result){
    printf("%d ", result);
}

typedef struct no{//Um dia eu faço árvore Binária ou B sla.
    int valor;
    struct no *prox;
}No;
typedef struct{
    No *inicio, *fim;
 }Lista;
void inserirInicio(Lista *lista, int valor){
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
void somarLista(Lista *lista, int valor){
    int rep=0;
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
    int soma = valor * rep;
    if (rep == 0 || rep == 1)
        return;
    printf("\n\nSoma dos %d's: %d\n", valor, soma);
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

int main() {
    //HCRYPTPROV hProv;
    char entrada[5];
    int rep, temp;
    Lista lista;
    lista.inicio = NULL;
    lista.fim = NULL;

do{
        printf("Quantos dados quer jogar?\n00 - Para Sair - cc para limpar\n");
        scanf("%s", entrada);
        printf("\n");
        if(strcmp(entrada, "cc")==0)
        {
            system("cls");
            continue;
        }
        else if((rep = atoi(entrada))<=20 && strcmp(entrada, "00")!=0)
        { printf("----------------------\n");
            for(int i = 0; i < rep; i++)
                {
                temp = gerar(6);
                inserirInicio(&lista, temp);
                Sleep(350);
                } for(int i = 1; i < 7; i++){
                    temp = i;
                    somarLista(&lista, temp);
                } remover(&lista);
        printf("\n----------------------\n");
        printf("\n\n");
        } else if(rep = atoi(entrada)>=20)
                printf("\nMaximo de Dados eh 20.\n\n");
        Sleep(250);
}while(strcmp(entrada, "00")!= 0);

//CryptReleaseContext(hProv, 0);
    return 0;
}
