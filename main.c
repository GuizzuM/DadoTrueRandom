#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wincrypt.h>

void gerar(int a){

    HCRYPTPROV hProv;
    BYTE randomBytes[4]; // Array de 4 bytes para gerar um número de 32 bits
    unsigned int random_number = 0;

    // Inicializa o provedor de contexto criptográfico
    if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)) {
        printf("Falha ao adquirir o contexto criptográfico\n");
        return;
    }

    // Gera números aleatórios
    if (!CryptGenRandom(hProv, sizeof(randomBytes), randomBytes)) {
        printf("Falha ao gerar o número aleatório\n");
        CryptReleaseContext(hProv, 0);
        return ;
    }

    // Converte os bytes aleatórios para um número inteiro
    random_number = (randomBytes[0] << 24) | (randomBytes[1] << 16) | (randomBytes[2] << 8) | randomBytes[3];

    int max = a;
        a= reduzir(random_number, max);
        imprimir(a);


}

int reduzir(unsigned int random_number, int m){
    int min = 1;
    int max = m;
    int a = min + (random_number % (max - min + 1));
    return a;
}

void imprimir(int result){
    printf("%u ", result);
}

int main() {
    HCRYPTPROV hProv;
    char entrada[5];
    int rep;

do{
        printf("Quantos dados quer jogar?\n00 - Para Sair - cc para limpar\n");
        scanf("%s", entrada);
        printf("\n");
        if(strcmp(entrada, "cc")==0)
        {
            system("cls");
            continue;
        }
        else if((rep = atoi(entrada))<=20)
        { printf("----------------------\n");
            for(int i = 0; i < rep; i++)
                {
                gerar(6);
                Sleep(400);
                }
        printf("\n----------------------\n");
        printf("\n\n");
        } else
                printf("\nMaximo de Dados eh 20.\n\n");
        Sleep(250);
}while(strcmp(entrada, "00")!= 0);

CryptReleaseContext(hProv, 0);
    return 0;
}
