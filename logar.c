#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <string.h>


void login()
{
	int comparCod,comparSenha;
	
	printf("\n---- Login ----\n");
    fflush(stdin);
    printf("\n\nDigite o codigo do seu cadastro: \n");
    scanf("%d", &comparCod);
    fflush(stdin);
    printf("\nDigite sua senha (apenas numeros): \n");
    scanf("%d", &comparSenha);
   

    system("cls");
    
    struct cadastroCliente{
	char nome[30];
	int idCliente;
	int senhaCliente;
	};
	
	typedef struct cadastroCliente clienteCadastrado;
  	clienteCadastrado  c[100];
    
	

	int id_usuario ,senha_usuario;
    char nome_usuario[30];
    int contador=0;

    FILE* cliente = fopen("cadastro-usuario.txt", "r");
    
    if (cliente != NULL)
   {
     while (fscanf(cliente, "%d %i %[^\n]s", &id_usuario,&senha_usuario, nome_usuario) != EOF){
     	c[contador].idCliente = id_usuario;
     	c[contador].senhaCliente = senha_usuario;
     	strcpy(c[contador].nome, nome_usuario);

     	contador++;
     
	 }
   }

	  
	  
	  
	  
	  
	struct cadastroBarbeiro{
	char nome[30];
	int idFuncionario;
	int senhaFuncionario;
	int horaInicio;
	int horaTerm;
	};
	
	typedef struct cadastroBarbeiro funcionarioCadastrado;
  	funcionarioCadastrado  f[100];
    
	

	int id_funcionario ,senha_funcionario;
	int Inicio;
	int Term;
    char nome_funcionario[30];
    int cont=0;

    FILE* funcionario = fopen("cadastro-Estabelecimento.txt", "r");
    
    if (funcionario != NULL)
   {
     while (fscanf(funcionario, "%d %i %i %d %[^\n]s", &id_funcionario,&senha_funcionario, &Inicio, &Term, nome_funcionario) != EOF){
  		f[cont].idFuncionario = id_funcionario;
     	f[cont].senhaFuncionario = senha_funcionario;
     	f[cont].horaInicio = id_funcionario;
     	f[cont].horaTerm = senha_funcionario;
     	strcpy(f[cont].nome, nome_funcionario);

     	cont++;
     
	 }
   }
   
	  
	  
int i=0, j=0;
	int pessoaCertaCliente =0;
	int pessoaCertaFun =0;
for(i=0;i<100;i++){

	if(c[i].idCliente == comparCod && c[i].senhaCliente == comparSenha){
		printf("------ Bem Vindo! %s ------", c[i].nome); 
	}
	else{
		pessoaCertaCliente  = -1;
	}
}

for(j=0;j<100;j++){
	
	if(f[j].idFuncionario == comparCod && f[j].senhaFuncionario == comparSenha){
		printf("------ Bem Vindo! %s ------", f[j].nome); 
	}
	else{
		pessoaCertaFun  = -1;
	}
}



if(pessoaCertaCliente == -1){
	printf("FILHA DA PUTAAAA"); // Por conta do for sempre fazer mais uma repetição sempra vai ser -1 e não consigo colocar uma validação de senha invalida foda
}

    fclose(cliente);
    fclose(funcionario);

}

