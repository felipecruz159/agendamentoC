#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

/**
 * CADASTRAR USUARIO
 */
void cadastroUsuario()
{
    srand(time(NULL));
    struct dadosUsuario
    {
        int codigo;
        char nome[30];
        int senha;
    };
    struct dadosUsuario cadastro[3];

    printf("\n---- Cadastro do Cliente ----\n");
    fflush(stdin);
    cadastro[0].codigo = (rand() % 100);      // PROVISORIO
    printf("Codigo: %d", cadastro[0].codigo); // FIXME: LER CODIGO MAIS RECENTE DO ARQUIVO (BD)
    fflush(stdin);
    printf("\n\nNome completo: \n");
    gets(cadastro[0].nome);
    fflush(stdin);
    printf("\nDigite sua senha (apenas numeros): \n");
    scanf("%d", &cadastro[0].senha);

    system("cls");

    // ARMAZENAR VARIAVEIS EM FILE E USAR PARA AGENDAMENTO

    FILE *usuario;
    usuario = fopen("cadastro-usuario.txt", "at");
    //    usuario = fopen("cadastro-ususario.txt", "a");

    if (usuario == NULL)
    {
        printf("Erro ao abrir o arquivo de dados!");
        exit(1);
    }
    fprintf(usuario, "%d", cadastro[0].codigo);
    fprintf(usuario, " %d", cadastro[0].senha);
    fprintf(usuario, " %s\n", cadastro[0].nome);

    printf("Cadastrado com sucesso!");
    menu();

    fclose(usuario);
}
