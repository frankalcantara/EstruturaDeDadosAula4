/*
* Algoritmo de Ordenação Bubble sort utilizando array como estrutura de dado
* Ordenando em ordem crescente
*/

#include <stdio.h>
#include <stdlib.h>

#define COMPRIMENTOVETOR 10


int main() {
	//criando e inicializando o vetor
	int vetor[COMPRIMENTOVETOR] = { 8, 16, 34, 13, 19, 7, 45, 3, 12, 9 };
	int aux = 0;
	char ch = ' ';

	//algoritmo de ordenação
	do
	{
		ch = 'N';
		for (int i = 0; i < COMPRIMENTOVETOR - 1; i++)
			if (vetor[i] > vetor[i + 1]) {
				//use < para ordem decrescente
				aux = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = aux;
				ch = 'S';
			}
	} while (ch == 'S');
	//fim do algoritmo de ordenação

	// para ver o resultado precisamos imprimir o vetor
	for (int i = 0; i < COMPRIMENTOVETOR; i++) {
		printf("%d, ", vetor[i]);
	}
	printf("\n");

	system("Pause");
	return 0;
}

