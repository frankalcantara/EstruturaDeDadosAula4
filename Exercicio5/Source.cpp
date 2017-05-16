/*
* Criar um programa que armazene o nome de 100 pessoas com até 30 caracteres 
* e permita ao usuário definir se o vetor será ordenado em ordem crescente ou decrescente.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//apenas para declarar as variáveis que vamos usar
//para testar seu código, você pode usar apenas 3 pessoas.
//depois substitua por cem
#define QUANTIDADEPESSOAS 3
#define COMPRIMENTONOMES 30

//protótipos
void carregar(char [][COMPRIMENTONOMES]);
void ordenar(char [][COMPRIMENTONOMES], int );
void mostrar(char[][COMPRIMENTONOMES]);


int main(){
	char nomes[QUANTIDADEPESSOAS][COMPRIMENTONOMES];
	int op = 0, c = 0;
	//para preencer o array
	carregar(nomes);
	printf("Informe 1 para ordenar em ordem Crescente, ou 2 para ordenar em ordem Decrescente:");
	scanf_s("%d", &op);
	//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
	while ((c = getchar()) != '\n' && c != EOF) {}
	//para ordenar o array
	ordenar(nomes, op);
	//apenas para o debug e para ver o que foi feito. 
	mostrar(nomes);

	system("Pause");
	return 0;
}

void carregar(char nomes[][COMPRIMENTONOMES]) {
	int c = 0;

	for (int i = 0; i < QUANTIDADEPESSOAS; i++) {
		printf("Informar o nome da pessoa %d: ", i + 1);
		scanf_s("%s", &nomes[i], COMPRIMENTONOMES + 1);
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}
	}
}

void ordenar(char nomes[][COMPRIMENTONOMES], int op)
{
	int flag = 1;
	char nome[COMPRIMENTONOMES];

	while (flag)
	{
		flag = 0;
		for (int i = 0; i < QUANTIDADEPESSOAS - 1; i++)
			if (op == 1)
			{
				if (strcmp(nomes[i], nomes[i + 1]) > 0)
				{
					strcpy_s(nome, nomes[i]);
					strcpy_s(nomes[i], nomes[i + 1]);
					strcpy_s(nomes[i + 1], nome);
					flag = 1;
				}
			}
			else
			{
				if (strcmp(nomes[i], nomes[i + 1]) < 0)
				{
					strcpy_s(nome, nomes[i]);
					strcpy_s(nomes[i], nomes[i + 1]);
					strcpy_s(nomes[i + 1], nome);
					flag = 1;
				}
			}
	}
}

void mostrar(char nomes[][COMPRIMENTONOMES]){
	for (int i = 0; i < QUANTIDADEPESSOAS; i++)	{
		printf("%d:%s\n", i, nomes[i]);
	}
}
