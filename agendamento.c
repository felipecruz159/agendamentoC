#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cadastroEstabelecimento.c"

void menu();
int main()
{

    menu();
    return 0;
}

void menu()
{
    int resp;

    printf("\n---- Bem vindo a Nextcut ----");
    printf("\nEscolha uma opcao:");
    printf("\n\n1 - Cadastrar estabelecimento");
    printf("\n2 - Cadastrar usuario");
    printf("\n3 - Login");
    printf("\n");
    scanf("%d", &resp);
    system("cls");

    switch (resp)
    {
    case 1:
        cadastroEstabelecimento();
        break;

//    case 2:
//        // cadastroUsuario();
//        break;
//
//    case 3:
//        // login();
//        break;
    }
}

