/*
* Algoritmo Pesquisa Sequencial
* Ordenando em ordem crescente
*/

#include <stdio.h>
#include <stdlib.h>

#define COMPRIMENTOVETOR 20

int main() {
	//criando e inicializando o vetor
	int vetor[COMPRIMENTOVETOR] = { 3, 7, 8, 10, 13, 15, 18, 22, 26, 27, 32, 35, 43, 47, 53, 57, 62, 63, 72, 84 };
	int x = 0 , aux = 0, c = 0;

	printf("Informe um valor para ser localizado no vetor: ");
	scanf_s("%d", &aux);
	//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
	while ((c = getchar()) != '\n' && c != EOF) {}

	for (x = 0; x < 20; x++)
		if (vetor[x] == aux)
			break;

	if (x < 20)
		printf("O valor informado esta na posicao %d do vetor.", x);
	else
		printf("O valor informado não esta no vetor.");

	system("Pause");
	return 0;
}
