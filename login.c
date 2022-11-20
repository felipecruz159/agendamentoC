#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


void login()
{
    srand(time(NULL));
    struct dadosLogin
    {
        char nomeConfere[30];
        int senhaConfere;
    };
    struct dadosLogin conferir[2];

    printf("\n---- Login ----\n");
    fflush(stdin);
    printf("\n\nDigite o nome do cadastrado\n");
    gets(conferir[0].nomeConfere);
    fflush(stdin);
    printf("\nDigite sua senha (apenas numeros): \n");
    scanf("%d", &conferir[0].senhaConfere);
   

    system("cls");
    
    
    int id_usuario;
    char nome_usuario[30];
    
    FILE* usuario = fopen("cadastroUsuario", "r");
    
    if (usuario != NULL)
   {
     while (fcanf(usuario, "%d %s", &id_usuario, nome_usuario) != EOF){
     	printf("%d %s", id_usuario, nome_usuario);
	 }
   }
   
    fclose(usuario);


}

