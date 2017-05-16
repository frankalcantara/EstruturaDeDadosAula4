/*
* Criar um programa que armazene em uma matriz quadrada de 7x7 números inteiros quaisquer. 
* O programa deverá ordenar a matriz com se fosse um vetor, 
* ou seja o menor número da matriz deverá estar na posição 1º posição (0, 0), 
* o maior número deverá estar na última posição da matriz (6, 6). Veja o exemplo:
*
*	Matriz não ordenada
*	12	7		23
*	73	45	17
*	3		9		21
*	Matiz ordenada
*	3		7		9
*	12	17	21
*	23	45	73
*
* Dica: Como os endereços de uma matriz estão em sequencia na memória, para a ordenação, podemos tratar a matriz como um vetor.  
*/

#include<stdio.h>
#include<stdlib.h>
//apenas para declarar as variáveis que vamos usar
//para testar seu código, você pode usar apenas 3 pessoas.
//depois substitua por SETE
#define QUANTIDADELINHAS 7
#define QUANTIDADEDECOLUNAS 7

void carregar(int[][QUANTIDADEDECOLUNAS]);
void ordenar(int[][QUANTIDADEDECOLUNAS]);
void mostrar(int[][QUANTIDADEDECOLUNAS]);

int main() {
	int mat[QUANTIDADELINHAS][QUANTIDADEDECOLUNAS] = { { 0 },{ 0 } };
	//para poder preencher a matriz
	carregar(mat);
	//para verificar a matriz digitada
	mostrar(mat);
	printf("\n");
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
	int aux = 0, cont = 0;
	char ch = 'N';
	int comp = (QUANTIDADELINHAS*QUANTIDADEDECOLUNAS);
	int temp[(QUANTIDADELINHAS*QUANTIDADEDECOLUNAS)] = { 0 };

	//transformando a matriz em um array
	for (int i = 0; i < QUANTIDADELINHAS; i++){
		for (int j = 0; j < QUANTIDADEDECOLUNAS; j++){
			temp[cont] = mat[i][j];
			cont++;
 		}
 	}
	//algoritmo de ordenação
	for (int i = 0; i < comp - 1; i++)
		for (int j = i + 1; j < comp; j++)
			if (temp[i] > temp[j]) {
				//para ordenar em ordem decrescente use <
				aux = temp[i];
				temp[i] = temp[j];
				temp[j] = aux;
			}
	cont = 0;
	//voltando para a matriz
	for (int i = 0; i < QUANTIDADELINHAS; i++) {
		for (int j = 0; j < QUANTIDADEDECOLUNAS; j++) {
			mat[i][j] = temp[cont];
			cont++;
		}
	}
	//fim do algoritmo de ordenação
}

void mostrar(int mat[][QUANTIDADEDECOLUNAS]) {
	for (int linha = 0; linha < QUANTIDADELINHAS; linha++) {
		for (int coluna = 0; coluna < QUANTIDADEDECOLUNAS; coluna++){
			//para imprimir vamos considerar os endereços de cada elemento da matriz 
			//na memória. Então podemos correr estes endereços linearmente
			printf("%d\t", *(*(mat + linha) + coluna));

		}
		printf("\n");
	}
	printf("\n");
}



