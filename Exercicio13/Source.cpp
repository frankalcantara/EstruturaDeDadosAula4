/*
* Criar um programa que possibilite a pesquisa “sequencial” em um vetor de 100 posições 
* de registros com os seguintes campos: 
*		nome (30 caracteres); 
*		email (50 caracteres); 
*		cpf (11 caractere); 
*		telefone (10 caracteres); 
*		idade. 
*		O usuário deverá ter a possibilidade de definir qual campo ele deseja pesquisar.
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//apenas para declarar as variáveis que vamos usar
//para testar seu código, você pode usar apenas 3 pessoas.
//depois substitua por 100
#define COMPRIMENTOVETOR 3
#define COMPRIMENTONOMES 30
#define COMPRIMENTOCPF	11
#define COMPRIMENTOEMAIL 50
#define COMRIMENTOTELEFONE 10

struct Dados {
	char nome[COMPRIMENTONOMES], email[COMPRIMENTOEMAIL], cpf[COMPRIMENTOCPF], telefone[COMRIMENTOTELEFONE];
	int idade;
};

struct Dados vetor[COMPRIMENTOVETOR];

//protótipos
int menu();
void carregar();
int pesquisar(int);


int main()
{
	int ret;
	carregar();
	ret = pesquisar(menu());
	if (ret > -1){
		printf("Dados localizados.\n");
		printf("Nome: %s\n", vetor[ret].nome);
		printf("Email: %s\n", vetor[ret].email);
		printf("Cpf: %s\n", vetor[ret].cpf);
		printf("Telefone: %s\n", vetor[ret].telefone);
		printf("Idade: %d\n", vetor[ret].idade);
	}
	else
		puts("Dados Não localizados na Matriz");

	system("Pause");
	return 0;
}

int menu()
{
	int op = 0, c = 0;

	printf("Informe 1 para pesquisar por Nome: \n");
	printf("Informe 2 para pesquisar por Email: \n");
	printf("Informe 3 para pesquisar por Cpf: \n");
	printf("Informe 4 para pesquisar por Telefone: \n");
	printf("Informe 5 para pesquisar por Idade:\n");

	scanf("%d", &op);
	//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
	while ((c = getchar()) != '\n' && c != EOF) {}

	return(op);
}

void carregar() {
	int c = 0;

	for (int i = 0; i < COMPRIMENTOVETOR; i++) {
		printf("Informar o Nome da pessoa %d: ", i + 1);
		gets_s(vetor[i].nome);
		
		printf("Informar o eMail da pessoa %d: ", i + 1);
		gets_s(vetor[i].email);
		
		printf("Informar o CPF da pessoa %d: ", i + 1);
		gets_s(vetor[i].cpf);
		
		printf("Informar o Telefone da pessoa %d: ", i + 1);
		gets_s(vetor[i].telefone);
		
		printf("Informar a Idade da pessoa %d: ", i + 1);
		scanf_s("%d", &vetor[i].idade);
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}
	}
}

int pesquisar(int op){
	int idade = 0, c =0 ;
	char nome[COMPRIMENTONOMES], email[COMPRIMENTOEMAIL], cpf[COMPRIMENTOCPF], telefone[COMRIMENTOTELEFONE];

	if (op == 1){
		puts("Informar Nome para pesquisa: ");
		gets_s(nome);
		for (int i = 0; i < 100; i++)
			if (strcmp(vetor[i].nome, nome) == 0)
				return(i);
	}
	
	if (op == 2){
		puts("Informar Email para pesquisa: ");
		gets_s(email);
		for (int i = 0; i < 100; i++)
			if (strcmp(vetor[i].email, email) == 0)
				return(i);
	}

	if (op == 3){
		puts("Informar Cpf para pesquisa: ");
		gets_s(cpf);
		for (int i = 0; i < 100; i++)
			if (strcmp(vetor[i].cpf, cpf) == 0)
				return(i);
	}

	if (op == 4){
		puts("Informar Telefone para pesquisa: ");
		gets_s(telefone);
		for (int i = 0; i < 100; i++)
			if (strcmp(vetor[i].telefone, telefone) == 0)
				return(i);
	}

	if (op == 5){
		puts("Informar Idade para pesquisa: ");
		scanf("%d", &idade);
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}
		for (int i = 0; i < 100; i++)
			if (vetor[i].idade == idade)
				return(i);
	}

	return(-1);
}
