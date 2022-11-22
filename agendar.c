#include <stdio.h>
#include <string.h>

void agendar()
{

	int codBarbeiro;

	printf("\nDigite o codigo do barbeiro:");
	scanf("%i", &codBarbeiro);

	struct cadastroBarbeiro
	{
		char nome[30];
		char marca[30];
		int idFuncionario;
		int senhaFuncionario;
		int horaInicio;
		int horaTerm;
	};

	typedef struct cadastroBarbeiro funcionarioCadastrado;
	funcionarioCadastrado f[100];

	int id_funcionario, senha_funcionario;
	int Inicio;
	int Term;
	char nome_funcionario[30];
	char nome_marca[30];
	int cont = 0;

	FILE *funcionario = fopen("cadastro-Estabelecimento.txt", "r");

	if (funcionario != NULL)
	{
		while (fscanf(funcionario, "%i %i %i %i %s %[^\n]s", &id_funcionario, &senha_funcionario, &Inicio, &Term, nome_funcionario, nome_marca) != EOF)
		{
			f[cont].idFuncionario = id_funcionario;
			f[cont].senhaFuncionario = senha_funcionario;
			f[cont].horaInicio = Inicio;
			f[cont].horaTerm = Term;
			strcpy(f[cont].nome, nome_funcionario);
			strcpy(f[cont].marca, nome_marca);

			cont++;
		}
	}

	int i = 0;
	int j = 0;
	int horaDisponivel[24];

	for (i = 0; i < 100; i++)
	{
		if (f[i].idFuncionario == codBarbeiro)
		{
			printf("\nVoce escolheu o Barbeiro %s\n", f[i].nome);
			printf("Barbearia %s\n", f[i].marca);
			printf("Aberto das %i:00 as %i:00", f[i].horaInicio, f[i].horaTerm);

			printf("\n\n");
			printf("Horarios disponiveis:\n");

			while (f[i].horaInicio < f[i].horaTerm)
			{
				horaDisponivel[j] = f[i].horaInicio;
				printf("%d - %d:00 ate %d:00\n", j + 1, horaDisponivel[j], horaDisponivel[j] + 1);
				j++;
				f[i].horaInicio++;
			}
		}
	}
	int agendado;
	scanf("%d", &agendado);

	if (agendado - 1 > j || agendado - 1 < 0){
		system("cls");
		printf("Impossivel agendar!");
	}
	else{
		system("cls");
		printf("Agendado!");
	}
}
