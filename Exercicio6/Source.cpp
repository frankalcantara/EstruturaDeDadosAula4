/*
* Criar um programa que armazene em uma matriz 7x7 números inteiros quaisquer. 
* Após armazenados, esta matriz deve ser ordenada por linha.
*/

#include<stdio.h>
#include<stdlib.h>
//apenas para declarar as variáveis que vamos usar
//para testar seu código, você pode usar apenas 3 pessoas.
//depois substitua por SETE
#define QUANTIDADELINHAS 7
#define QUANTIDADEDECOLUNAS 7

void carregar(int [][QUANTIDADEDECOLUNAS]);
void ordenar(int[][QUANTIDADEDECOLUNAS]);
void mostrar(int[][QUANTIDADEDECOLUNAS]);

int main(){
	int mat[QUANTIDADELINHAS][QUANTIDADEDECOLUNAS] = { {0}, {0} };
	//para poder preencher a matriz
	carregar(mat);
	//para ordenar a matriz
	ordenar(mat);
	//para debugar, esta função é apenas para ver o resultado
	mostrar(mat);

	system("Pause");
	return 0;
}

void carregar(int mat[][QUANTIDADEDECOLUNAS]) {
	int c = 0;
	for (int linha = 0; linha < QUANTIDADELINHAS; linha++) {
		printf("Digitando a linha %d:\n", linha);
		for (int coluna = 0; coluna < QUANTIDADEDECOLUNAS; coluna++) {
			printf("Digitar o numero da posição [%d][%d]:", linha, coluna);
			scanf_s("%d", &mat[linha][coluna]);
			//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
			while ((c = getchar()) != '\n' && c != EOF) {}
		}
	}
}

void ordenar(int mat[][QUANTIDADEDECOLUNAS]) {
	int aux = 0, flag = 0;

	for (int linha = 0; linha < QUANTIDADEDECOLUNAS; linha++) {
		flag = 1;
		while (flag) {
			flag = 0;
			for (int coluna = 0; coluna < QUANTIDADEDECOLUNAS - 1; coluna++)
				if (mat[linha][coluna] > mat[linha][coluna + 1]) {
					aux = mat[linha][coluna];
					mat[linha][coluna] = mat[linha][coluna + 1];
					mat[linha][coluna + 1] = aux;
					flag = 1;
				}
		}
	}
}

void mostrar(int mat[][QUANTIDADEDECOLUNAS]) {
	for (int linha = 0; linha < QUANTIDADELINHAS; linha++){
		for (int coluna = 0; coluna < QUANTIDADEDECOLUNAS; coluna++){
			printf("%d\t", mat[linha][coluna]);

		}
		printf("\n");
	}
	printf("\n");
}