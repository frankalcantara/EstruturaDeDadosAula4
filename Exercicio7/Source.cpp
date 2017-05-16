/*
* Criar um programa que armazene em uma matriz quadrada de 7x7 n�meros inteiros quaisquer. 
* O programa dever� ordenar a matriz com se fosse um vetor, 
* ou seja o menor n�mero da matriz dever� estar na posi��o 1� posi��o (0, 0), 
* o maior n�mero dever� estar na �ltima posi��o da matriz (6, 6). Veja o exemplo:
*
*	Matriz n�o ordenada
*	12	7		23
*	73	45	17
*	3		9		21
*	Matiz ordenada
*	3		7		9
*	12	17	21
*	23	45	73
*
* Dica: Como os endere�os de uma matriz est�o em sequencia na mem�ria, para a ordena��o, podemos tratar a matriz como um vetor.  
*/

#include<stdio.h>
#include<stdlib.h>
//apenas para declarar as vari�veis que vamos usar
//para testar seu c�digo, voc� pode usar apenas 3 pessoas.
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
	//para debugar, esta fun��o � apenas para ver o resultado
	mostrar(mat);

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
	//algoritmo de ordena��o
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
	//fim do algoritmo de ordena��o
}

void mostrar(int mat[][QUANTIDADEDECOLUNAS]) {
	for (int linha = 0; linha < QUANTIDADELINHAS; linha++) {
		for (int coluna = 0; coluna < QUANTIDADEDECOLUNAS; coluna++){
			//para imprimir vamos considerar os endere�os de cada elemento da matriz 
			//na mem�ria. Ent�o podemos correr estes endere�os linearmente
			printf("%d\t", *(*(mat + linha) + coluna));

		}
		printf("\n");
	}
	printf("\n");
}



