/*
* Algoritmo de Ordena��o por Inser��o utilizando array como estrutura de dado
* Ordenando em ordem crescente
*/

#include <stdio.h>
#include <stdlib.h>
//apenas para determinar o comporimento do vetor, Neste exemplo o vetor tem dez posi��es
#define COMPRIMENTOVETOR 10

int main() {
	//criamos e inicializamos o vetor
	int vetor[COMPRIMENTOVETOR] = { 8, 16, 34, 13, 19, 7, 45, 3, 12, 9 };
	int aux = 0;
	//algoritmo de ordena��o propriamente dito
	for (int i = 0; i < COMPRIMENTOVETOR -1; i++)
		for (int j = i + 1; j < COMPRIMENTOVETOR; j++)
			if (vetor[i] > vetor[j]){
				//para ordenar em ordem decrescente use <
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
	 //fim da ordena��o

	//para ver o resultado precisamos imprimir o vetor
	for (int i = 0; i < COMPRIMENTOVETOR; i++){
		printf("%d, ", vetor[i]);
	}
	printf("\n");
	
	system("Pause");
	return 0;
}
