/*
* Criar um programa que receba o nome das 100 primeiras pessoas que entraram em uma determinada loja.
* Ap�s receber estes dados o programa dever� ordenar, em ordem alfab�tica, estes nomes pelo primeiro caractere.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define QUANTIDADEPESSOAS 100
#define COMPRIMENTONOMES 30

//prot�tipos 
void arrange(int n, char *[]);

int main() {
	char *x[QUANTIDADEPESSOAS]; // definindo o ponteiro de arrays

	printf("Digitar� %d nomes: \n", QUANTIDADEPESSOAS);
	printf("Digite os nomes: \n");
	//la�o para a digita��o dos nomes das pessoas
	for (int i = 0; i < QUANTIDADEPESSOAS; i++) {
		// alocando mem�ria para os nomes
		x[i] = (char*)malloc (COMPRIMENTONOMES * sizeof(char));
		//para a digita��o dos nomes
		printf("Nome %d: ", i + 1);
		gets_s(x[i], COMPRIMENTONOMES);
	}

	printf("Os nomes em ordem: \n");
	arrange(QUANTIDADEPESSOAS, x); // chamando o algoritmo de ordena��o
																 //para imprimir o resultado
	for (int i = 0; i < QUANTIDADEPESSOAS; i++) {
		printf("Nome %d: %s\n", i + 1, x[i]);
	}

	system("Pause");
	return 0;
}

//defini��es 
void arrange(int n, char *x[]) {
	char *temp; //defini��o do ponteiro tempor�rio
	for (int str = 0; str < n - 1; ++str)
	{
		for (int i = str + 1; i < n; ++i)
		{
			if (strcmp(x[str], x[i]) > 0) //comparando os nomes
			{
				temp = x[str]; //o nome armazenado no tempor�rio
				x[str] = x[i];
				x[i] = temp;
			}
		}
	}
	return;
}
