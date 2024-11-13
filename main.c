#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wincrypt.h>
#include <locale.h>
#include <wchar.h>


int gerar(short int a){

    HCRYPTPROV hProv;
    BYTE randomBytes[4]; // Array de 4 bytes para gerar um nï¿½mero de 32 bits
    unsigned int random_number = 0;

    // Inicializa o provedor de contexto criptogrï¿½fico
    if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)) {
        printf("Falha ao adquirir o contexto criptogrï¿½fico\n");
        return -1;
    }

    // Gera nï¿½meros aleatï¿½rios
    if (!CryptGenRandom(hProv, sizeof(randomBytes), randomBytes)) {
        printf("Falha ao gerar o nÃºmero aleatï¿½rio\n");
        CryptReleaseContext(hProv, 0);
        return -1;
    }

    // Converte os bytes aleatï¿½rios para um nï¿½mero inteiro
    random_number = (randomBytes[0] << 24) | (randomBytes[1] << 16) | (randomBytes[2] << 8) | randomBytes[3];

    short int max = a;
        a= reduzir(random_number, max);
        imprimir(a);
    return a;

}

int reduzir(unsigned int random_number, int m){
    short int min = 1;
    short int max = m;
    short int a = min + (random_number % (max - min + 1));
    return a;
}

void imprimir(short int result){
    printf("%d ", result);
}

typedef struct no{//Um dia eu faÃ§o Ã¡rvore BinÃ¡ria ou B sla.
    short int valor;
    struct no *prox;
}No;
typedef struct{
    No *inicio, *fim;
 }Lista;
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
    setlocale(LC_ALL,"Portuguese");//GlÓRIA AAAAAAAAAAAAAA DESGRAÇA
    char entrada[5];
    short int rep, temp;
    Lista lista;
    lista.inicio = NULL;
    lista.fim = NULL;
do{
        printf("Quantos dados quer jogar?\n00 - Para Sair & cc para limpar\n");
        scanf("%s", entrada);
        printf("\n");
        if(strcmp(entrada, "cc")==0)
        {
            system("cls");
            continue;
        }
        else if((rep = atoi(entrada))<=20 && strcmp(entrada, "00")!=0)
        { printf("----------------------\n");
            for(short int i = 0; i < rep; i++)
                {
                temp = gerar(6);
                inserirInicio(&lista, temp);
                Sleep(350);
                } for(short int i = 1; i < 7; i++){
                    temp = i;
                    somarLista(&lista, temp);
                } remover(&lista);
        printf("----------------------\n");
        printf("\n\n");
        } else if(rep = atoi(entrada)>20)
                printf("\nMáximo de Dados é 20.\n\n");
        Sleep(250);
}while(strcmp(entrada, "00")!= 0);

//CryptReleaseContext(hProv, 0);
    return 0;
}
