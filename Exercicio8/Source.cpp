/*
* Criar um programa que armazene em uma matriz 10x10 n�meros quaisquer. 
* Ap�s armazenado, ordenar os valores desta matriz em um vetor.
*/

#include<stdio.h>
#include<stdlib.h>
//apenas para declarar as vari�veis que vamos usar
//para testar seu c�digo, voc� pode usar apenas 3 pessoas.
//depois substitua por DEZ
#define QUANTIDADELINHAS 10
#define QUANTIDADEDECOLUNAS 10
#define COMPRIMENTOVETOR QUANTIDADELINHAS*QUANTIDADEDECOLUNAS

void carregar(int[][QUANTIDADEDECOLUNAS]);
void ordenar(int [][QUANTIDADEDECOLUNAS], int [COMPRIMENTOVETOR]);
void mostrar(int[][QUANTIDADEDECOLUNAS]);
void mostrarVet(int[COMPRIMENTOVETOR]);

int main() {
	int mat[QUANTIDADELINHAS][QUANTIDADEDECOLUNAS] = { { 0 },{ 0 } };
	int vet[COMPRIMENTOVETOR] = { 0 };

	//para poder preencher a matriz
	carregar(mat);
	//para verificar a matriz digitada
	mostrar(mat);
	printf("\n");
	//para ordenar a matriz
	ordenar(mat, vet);
	//para debugar, esta fun��o � apenas para ver o resultado
	mostrarVet(vet);

	system("Pause");
	return 0;
}


void carregar(int mat[][QUANTIDADEDECOLUNAS]) {
	int c = 0;
	for (int linha = 0; linha < QUANTIDADELINHAS; linha++) {
		printf("Digitando a linha %d:\n", linha);
		for (int coluna = 0; coluna < QUANTIDADEDECOLUNAS; coluna++) {
			printf("Digitar o numero da posi��o [%d][%d]:", linha, coluna);
			scanf_s("%d", &mat[linha][coluna]);
			//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
			while ((c = getchar()) != '\n' && c != EOF) {}
		}
	}
}

void ordenar(int mat[][QUANTIDADEDECOLUNAS], int vet[COMPRIMENTOVETOR]) {
	int cont = 0, aux = 0, qtd = 0;

	//transformando a matriz em um array
	for (int i = 0; i < QUANTIDADELINHAS; i++) {
		for (int j = 0; j < QUANTIDADEDECOLUNAS; j++) {
			vet[cont] = mat[i][j];
			cont++;
		}
	}
	//algoritmo de ordena��o
	for (int i = 0; i < COMPRIMENTOVETOR - 1; i++)
		for (int j = i + 1; j < COMPRIMENTOVETOR; j++)
			if (vet[i] > vet[j]) {
				//para ordenar em ordem decrescente use <
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
}


void mostrar(int mat[][QUANTIDADEDECOLUNAS]) {
	for (int linha = 0; linha < QUANTIDADELINHAS; linha++) {
		for (int coluna = 0; coluna < QUANTIDADEDECOLUNAS; coluna++) {
			//para imprimir vamos considerar os endere�os de cada elemento da matriz 
			//na mem�ria. Ent�o podemos correr estes endere�os linearmente
			printf("%d\t", *(*(mat + linha) + coluna));

		}
		printf("\n");
	}
	printf("\n");
}

void mostrarVet(int vet[COMPRIMENTOVETOR]){
	for (int i = 0; i < COMPRIMENTOVETOR; i++){
		printf("%d\t", vet[i]);
	}
	printf("\n");
}
