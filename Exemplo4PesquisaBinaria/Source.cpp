/*
* Aplicação de pesquisa binária usando recursão
* Neste caso, o uso da recursão simplifica a função 
*/

#include <stdio.h>
#include <stdlib.h>

#define COMPRIMENTOVETOR 20

//protótipo
int pesquisa_binaria (int [], int, int, int);
 
int main() {
	//criando e inicializando o vetor
	int vetor[COMPRIMENTOVETOR] = { 3, 7, 8, 10, 13, 15, 18, 22, 26, 27, 32, 35, 43, 47, 53, 57, 62, 63, 72, 84 };
	int num = 0, pos = 0, c = 0;

	printf("Informe um numero para pesquisa: ");
	scanf_s("%d", &num);
	//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
	while ((c = getchar()) != '\n' && c != EOF) {}

	pos = pesquisa_binaria(vetor, 0, COMPRIMENTOVETOR -1, num);

	if (pos == -1)
		printf("O numero não esta na lista.");
	else
		printf("O numero esta na posicao %d da lista.", pos);

	system("Pause");
	return 0;
}

//declaração
int pesquisa_binaria (int vet[], int inicio, int fim, int numero) {
	int pivo = 0;

	if (inicio > fim)
		return (-1);

	pivo = ((fim - inicio) / 2) + inicio;

	if (numero  > vet[pivo])
		return (pesquisa_binaria (vet, pivo + 1, fim, numero));

	if (numero  < vet[pivo])
		return (pesquisa_binaria (vet, inicio, pivo - 1, numero));

	return (pivo);
}
