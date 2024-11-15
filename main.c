#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "lista.h"
#include "random.h"

int main() {
    //HCRYPTPROV hProv;
    setlocale(LC_ALL,"Portuguese");//Gl”RIA AAAAAAAAAAAAAA DESGRA«A
    char entrada[5];
    short int rep, temp;
    Lista lista;
    lista.inicio = NULL;
    lista.fim = NULL;
do{
        printf("\t\tQuantos dados quer jogar?\n\t\t00 - Para Sair & cc para limpar\n");
        scanf("%s", entrada);
        printf("\t\t\n");
        if(strcmp(entrada, "cc")==0)
        {
            system("cls");
            continue;
        }
        else if((rep = atoi(entrada))<=20 && strcmp(entrada, "00")!=0)
        { printf("\-----------------------------------------------------------------------------------------------------\n");
            for(short int i = 0; i < rep; i++)
                {
                temp = gerar(6);
                inserirInicio(&lista, temp);
                Sleep(350);
                }
 for(short int i = 1; i < 7; i++){
                    temp = i;
                    somarLista(&lista, temp);
                } remover(&lista);
        printf("\n-----------------------------------------------------------------------------------------------------\n");
        printf("\n\n");
        } else if(rep = atoi(entrada)>20)
                printf("\t\t\nM·ximo de Dados È 20.\n\n");
        Sleep(250);
}while(strcmp(entrada, "00")!= 0);

//CryptReleaseContext(hProv, 0);
    return 0;
}
