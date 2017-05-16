/*
* Criar um programa que receba o nome das 100 primeiras pessoas que entraram em uma determinada loja.
* Após receber estes dados o programa deverá ordenar, em ordem alfabética, estes nomes pelo primeiro caractere.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define QUANTIDADEPESSOAS 100
#define COMPRIMENTONOMES 30

//protótipos 
void arrange(int n, char *[]);

int main() {
	char *x[QUANTIDADEPESSOAS]; // definindo o ponteiro de arrays

	printf("Digitará %d nomes: \n", QUANTIDADEPESSOAS);
	printf("Digite os nomes: \n");
	//laço para a digitação dos nomes das pessoas
	for (int i = 0; i < QUANTIDADEPESSOAS; i++) {
		// alocando memória para os nomes
		x[i] = (char*)malloc (COMPRIMENTONOMES * sizeof(char));
		//para a digitação dos nomes
		printf("Nome %d: ", i + 1);
		gets_s(x[i], COMPRIMENTONOMES);
	}

	printf("Os nomes em ordem: \n");
	arrange(QUANTIDADEPESSOAS, x); // chamando o algoritmo de ordenação
																 //para imprimir o resultado
	for (int i = 0; i < QUANTIDADEPESSOAS; i++) {
		printf("Nome %d: %s\n", i + 1, x[i]);
	}

	system("Pause");
	return 0;
}

//definições 
void arrange(int n, char *x[]) {
	char *temp; //definição do ponteiro temporário
	for (int str = 0; str < n - 1; ++str)
	{
		for (int i = str + 1; i < n; ++i)
		{
			if (strcmp(x[str], x[i]) > 0) //comparando os nomes
			{
				temp = x[str]; //o nome armazenado no temporário
				x[str] = x[i];
				x[i] = temp;
			}
		}
	}
	return;
}
