/*
* Criar um programa para armazenar em uma matriz 3x20, o peso (linha 0), a altura (linha1) e a idade (linha2) de 20 pessoas. 
* Ap�s armazenado, o programa dever� ter a possibilidade de ordenar a matriz pela idade, pela altura e pelo peso, 
* conforme decis�o do usu�rio.
*/

#include<stdio.h>
#include<stdlib.h>
//apenas para declarar as vari�veis que vamos usar
//para testar seu c�digo, voc� pode usar apenas 5 pessoas.
#define QUANTIDADEPESSOAS 3
#define NUMERODELINHAS 3

//declara��es - prot�tipos
void carregar(float[][QUANTIDADEPESSOAS]);
void mostrarPessoas(float[][QUANTIDADEPESSOAS]);
int menu();
void ordenar(float[][QUANTIDADEPESSOAS], int);

int main() {
	int op = 1;
	float pessoas[NUMERODELINHAS][QUANTIDADEPESSOAS];

	//para voc� entrar os dados no vetor e testar o processo de 
	//ordena��o
	carregar(pessoas);

	//a op��o 3 do menu sai do la�o de repeti��o
	//ent�o vamos ficar repetindo o menu a cada op��o do usu�rio
	while (op != 3){
		op = menu();
		if ((op >= 0) && (op < 3))
			ordenar(pessoas, op);
		//a cada ordena��o imprmimos o array para ver se funcionou
		mostrarPessoas(pessoas);
	}

	return 0;
}

int menu() {
	int op = 0, c = 0;
	//como estamos no windows vamos limpar a tela a cada chamada 
	//da fun��o menu;
	system("cls");
	//agora imprimimos o menu na tela
	printf("Informe 0 para ordenar pelo Peso: \n");
	printf("Informe 1 para ordenar pela Altura: \n");
	printf("Informe 2 para ordenar pela Idade: \n");
	printf("Informe 3 para Sair: \n");

	//agora recolhemos a op��o
	scanf_s("%d", &op);
	//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
	while ((c = getchar()) != '\n' && c != EOF) {}

	return(op);
}

void carregar(float pes[][QUANTIDADEPESSOAS]) {
	int c = 0;
	for (int i = 0; i < QUANTIDADEPESSOAS; i++){

		printf("Informar o peso da pessoa %d: ", i + 1);
		scanf_s("%f", &pes[0][i]);
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}
		
		printf("Informar a altura da pessoa %d: ", i + 1);
		scanf_s("%f", &pes[1][i]);
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}
		
		printf("Informar a idade da pessoa %d: ", i + 1);
		scanf_s("%f", &pes[2][i]);
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}

		printf("\n");
	}
}

void mostrarPessoas(float pes[][QUANTIDADEPESSOAS]) {
	for (int i = 0; i < QUANTIDADEPESSOAS; i++){
		printf("Pessoa %d, peso: %0.2f\n", i, pes[0][i]);
		printf("Pessoa %d, altura: %0.2f\n", i, pes[1][i]);
		printf("Pessoa %d, idade: %0.2f\n", i, pes[2][i]);
		printf("\n");
	}
	system("Pause");
}


void ordenar(float pes[][QUANTIDADEPESSOAS], int op) {
	int x, y, flag = 1;
	float aux;

	while (flag){
		flag = 0;
		for (y = 0; y < QUANTIDADEPESSOAS -1; y++)
			if (pes[op][y] > pes[op][y + 1])
			{
				aux = pes[0][y];
				pes[0][y] = pes[0][y + 1];
				pes[0][y + 1] = aux;

				aux = pes[1][y];
				pes[1][y] = pes[1][y + 1];
				pes[1][y + 1] = aux;

				aux = pes[2][y];
				pes[2][y] = pes[2][y + 1];
				pes[2][y + 1] = aux;

				flag = 1;
			}
	}
}
