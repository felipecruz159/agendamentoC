#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "logar.c"
#include "cadastroEstabelecimento.c"
#include "cadastroUsuario.c"
#include "listaBarbeiro.c"


void menu();
void escolha();

int main()
{
    menu();
    escolha();
    return 0;
}

void menu()
{
    int resp;

    printf("\n---- Bem vindo a Nextcut ----");
    
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

    case 2:
       cadastroUsuario();
       break;

  case 3:
      login();
      break;
    }
}

void escolha(){
	int resposta; 

	printf("\n\n 1 - Para listar todos os Barbeiros\n");
	printf(" 2 - Para Agendar o corte\n");
	scanf("%i",&resposta);
	system("cls");
	
	switch (resposta)
    {
    case 1:
        listar();
        break;

//    case 2:
//       cadastroUsuario();
//       break;

    }
}


