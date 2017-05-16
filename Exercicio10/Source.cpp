/*
* Criar um programa que possua um vetor de 50 posi��es de registros com os seguintes campos: 
*		Nome, com 30 caracteres; idade (inteiro) e peso (float). 
* Ap�s armazenado os dados o vetor deve ser ordenado pelo peso, 
* sendo que o usu�rio poder� definir se o vetor ser� ordenado pelo m�todo de �Sele��o� ou �Inser��o�.
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//apenas para declarar as vari�veis que vamos usar
//para testar seu c�digo, voc� pode usar apenas 3 pessoas.
//depois substitua por 50
#define COMPRIMENTODOVETOR 3
#define COMPRIMENTONOMES 30

struct Dados {
	char nome[COMPRIMENTONOMES];
	int idade;
	float peso;
};

struct Dados vetor[COMPRIMENTODOVETOR];

//prot�tipos
void carregar();
void ordenarPorSelecao();
void ordenarPorInsercao();
void mostrar(Dados []); 

int main(){
	int op = 0, c = 0;

	carregar();
	printf("Informe 1 para ordenar por Sele��o, ou 2 para ordenar por Inser��o: ");
	scanf("%d", &op);
	//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
	while ((c = getchar()) != '\n' && c != EOF) {}

	if (op == 1) ordenarPorSelecao();
	if (op == 2) ordenarPorInsercao();

	//Para mostrar o array ordenado e verificar os algoritmos
	mostrar(vetor);
	
	system("Pause");
	return 0;
}



void carregar() {
	int c = 0;

	for (int i = 0; i < COMPRIMENTODOVETOR; i++) {
		printf("Informar o Nome da pessoa %d: ", i + 1);
		scanf_s("%s", &vetor[i].nome, COMPRIMENTONOMES);
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}

		printf("Informar a Idade da pessoa %d: ", i + 1);
		scanf_s("%d", &vetor[i].idade);
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}

		printf("Informar o Peso da pessoa %d: ", i + 1);
		scanf_s("%f", &vetor[i].peso);
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}
	}
}

void ordenarPorSelecao() {
	int flag = 1, idade = 0;
	char nome[COMPRIMENTONOMES];
	float peso;

	while (flag){
		flag = 0;
		for (int i = 0; i < COMPRIMENTODOVETOR; i++)
			if (vetor[i].peso > vetor[i + 1].peso){
				strcpy_s(nome, vetor[i].nome); 
				strcpy_s(vetor[i].nome, vetor[i + 1].nome);
				strcpy_s(vetor[i + 1].nome, nome);

				peso = vetor[i].peso;
				vetor[i].peso = vetor[i + 1].peso;
				vetor[i + 1].peso = peso;

				idade = vetor[i].idade;
				vetor[i].idade = vetor[i + 1].idade;
				vetor[i + 1].idade = idade;

				flag = 1;
			}
	}
}

void ordenarPorInsercao(){
	int flag = 1, idade = 0;
	char nome[30];
	float peso;

	for (int i = 0; i<COMPRIMENTODOVETOR-1; i++)
		for (int j = i + 1; j<COMPRIMENTODOVETOR-1; j++)
			if (strcmp(vetor[j].nome, vetor[j + 1].nome) > 0)
			{
				strcpy_s(nome, vetor[i].nome);
				strcpy_s(vetor[i].nome, vetor[j].nome);
				strcpy_s(vetor[j].nome, nome);

				peso = vetor[i].peso;
				vetor[i].peso = vetor[j].peso;
				vetor[j].peso = peso;

				idade = vetor[i].idade;
				vetor[i].idade = vetor[j].idade;
				vetor[j].idade = idade;
			}
}

void mostrar(Dados vetor[]) {
	for (int i = 0; i < COMPRIMENTODOVETOR; i++) {
		printf("Nome: %s\n", vetor[i].nome);
		printf("Idade: %d\n", vetor[i].idade);
		printf("Peso: %0.2f\n", vetor[i].peso);
		printf("\n");
	}
}