/*
* Criar um programa para realizar uma pesquisa sequencial em uma matriz 10x10 de registros 
* com os seguintes campos: Nome (com 30 caracteres), peso e altura. 
* O usuário poderá definir qual campo ele deseja pesquisar.
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//apenas para declarar as variáveis que vamos usar
//para testar seu código, você pode usar apenas 3 pessoas.
//depois substitua por 10
#define NUMERODELINHAS 3
#define NUMERODECOLUNAS 3
#define COMPRIMENTONOMES 30

struct Dados {
	char nome[COMPRIMENTONOMES];
	float peso, altura;
};

struct Dados matriz[NUMERODELINHAS][NUMERODECOLUNAS];

//protótipos
int menu();
void carregar();
int pesquisar(int op);

void carregar() {
	int c = 0;
	for (int i = 0; i < NUMERODELINHAS; i++) {
		for (int j = 0; j < NUMERODECOLUNAS; j++) {
			printf("Informar o Nome da pessoa [%d][%d]: ", i, j);
			scanf_s("%s", &matriz[i][j].nome, COMPRIMENTONOMES);
			//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
			while ((c = getchar()) != '\n' && c != EOF) {}

			printf("Informar a Idade da pessoa [%d][%d]: ", i, j);
			scanf_s("%f", &matriz[i][j].peso);
			//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
			while ((c = getchar()) != '\n' && c != EOF) {}

			printf("Informar o Peso da pessoa [%d][%d]: ", i, j);
			scanf_s("%f", &matriz[i][j].altura);
			//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
			while ((c = getchar()) != '\n' && c != EOF) {}
		}
		//só para ficar organizado vamos limpar a tela a cada linha 
		system("Cls");

	}
}


int pesquisar(int op){
	int c = 0;
	char nome[COMPRIMENTONOMES];
	float peso, altura;

	if (op == 1){
		puts("Informar nome para pesquisa: ");
		gets_s(nome);
		for (int i = 0; i < NUMERODELINHAS; i++)
			for (int j = 0; j < NUMERODECOLUNAS; j++)
				if (strcmp(matriz[i][j].nome, nome) == 0)
					return(1);
	}
							
	if (op == 2){
		puts("Informar Peso para pesquisa: ");
		scanf("%f", &peso);
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}
		for (int i = 0; i < NUMERODELINHAS; i++)
			for (int j = 0; j < NUMERODECOLUNAS; j++)
				if (matriz[i][j].peso == peso)
					return(1);
	}

	if (op == 3){
		puts("Informar Altura para pesquisa: ");
		scanf("%f", &altura);
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}
		for (int i = 0; i < NUMERODELINHAS; i++)
			for (int j = 0; j < NUMERODECOLUNAS; j++)
				if (matriz[i][j].altura == altura)
					return(1);
	}

	return(0);
}


int main(){
	carregar();
	if (pesquisar(menu()))
		puts("Dados localizados na Matriz");
	else
		puts("Dados Não localizados na Matriz");

	system("Pause");
	return 0;
}

int menu() {
	int op = 0, c = 0;

	//só para ficar organizado vamos limpar a tela 
	system("Cls");
	printf("Informe 1 para pesquisar por Nome : \n");
	printf("Informe 2 para pesquisar por Peso : \n");
	printf("Informe 3 para pesquisar por Altura: \n");
	scanf("%d", &op);
	//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
	while ((c = getchar()) != '\n' && c != EOF) {}
	return(op);
}
