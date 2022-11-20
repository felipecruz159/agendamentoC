#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "printarHorarios.c"

/**
 * CADASTRAR ESTABELECIMENTO
 */
void cadastroEstabelecimento()
{
    srand(time(NULL));
    struct dadosEstabelecimento
    {
        int codigo;
        int senha;
        char nome[30];
        char marca[30];
    };
    struct dadosEstabelecimento cadastro[4];

    printf("\n---- Cadastro do salao ----\n");
    fflush(stdin);
    cadastro[0].codigo = (rand() % 100);        // PROVISORIO
    printf("Codigo: %d", cadastro[0].codigo); // FIXME: LER CODIGO MAIS RECENTE DO ARQUIVO (BD)
    fflush(stdin);
    printf("\n\nDigite sua senha (apenas numeros): \n");
    scanf("%d", &cadastro[0].senha);
    fflush(stdin);
    printf("\nNome do proprietario: \n");
    gets(cadastro[0].nome);
    fflush(stdin);
    printf("\nNome da sua marca (estabelecimento): \n");
    gets(cadastro[0].marca);

    system("cls");

    typedef struct
    {
        int hora;
        int minuto;
    } time;
    time Hora;

    printf("Digite a hora de inicio: \n");
    int horaInicio = printarHorarios(); // variavel para definir o intervalo do for

    printf("Digite a hora de termino: \n");
    int horaTermino = printarHorarios(); // variavel para definir o intervalo do for

    system("cls");

    // ARMAZENAR VARIAVEIS EM FILE E USAR PARA AGENDAMENTO

    FILE *estabelecimento;
    estabelecimento = fopen("cadastro-estabelecimento.txt", "at");
//    estabelecimento = fopen("cadastro-estabelecimento.txt", "a");

    if (estabelecimento == NULL)
    {
        printf("Erro ao abrir o arquivo de dados!");
        exit(1);
    }
	fprintf(estabelecimento, "%d ", cadastro[0].codigo);
	fprintf(estabelecimento, "%d ", cadastro[0].senha);
	fprintf(estabelecimento, "%d ", horaInicio);
    fprintf(estabelecimento, "%d ", horaTermino);
    fprintf(estabelecimento, "%s ", cadastro[0].nome);
    fprintf(estabelecimento, "%s\n ", cadastro[0].marca);


	printf("Cadastrado com sucesso!");

    fclose(estabelecimento);

    // TODO: COMECAR LOGICA DE HORAS DISPONIVEIS
}




