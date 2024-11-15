#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wincrypt.h>

int gerar(short int a){

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
        printf("Falha ao gerar o número aleat�rio\n");
        CryptReleaseContext(hProv, 0);
        return -1;
    }

    // Converte os bytes aleat�rios para um n�mero inteiro
    random_number = (randomBytes[0] << 24) | (randomBytes[1] << 16) | (randomBytes[2] << 8) | randomBytes[3];

    short int max = a;
        a= reduzir(random_number, max);
        imprimir(a);
    return a;

}
