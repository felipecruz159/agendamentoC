#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "agendar.c"

void listar()
{
  int id_funcionario, senha_funcionario;
  int Inicio;
  int Term;
  char nome_funcionario[30];
  char nome_marca[30];

  FILE *funcionario = fopen("cadastro-Estabelecimento.txt", "r");

  if (funcionario != NULL)
  {
    while (fscanf(funcionario, "%d %i %i %d %s %[^\n]s", &id_funcionario, &senha_funcionario, &Inicio, &Term, nome_funcionario, nome_marca) != EOF)
    {
      printf("Barbearia: %s\nDono: %s\nCodigo para busca: %i\n-------------------------", nome_marca, nome_funcionario, id_funcionario);
    }
  }

  int escolha;

  printf("\n1 - Agendar com um barbeiro\n");
  scanf("%d", &escolha);
  fclose(funcionario);

  switch (escolha)
  {
  case 1:
    agendar();
    break;
  }
}
