/*
* Criar um programa que armazene em um vetor o nome de 20 pessoas, em um segundo vetor a idade destas pessoas.
* Observe que os vetores estão relacionados entres si, de tal forma que, na posição '7' de um vetor esta armazenado o nome da pessoa
* e sua idade esta armazenada na posição '7' do outro vetor.
*
* O programa deverá ordenar os vetores pelo nome, em seguida definir a média de idade,
* e em um terceiro momento, listar em ordem alfabética, o nome das pessoas que possuem a idade a baixo desta média.
* Considere que os nomes das pessoas não terão mais que 30 caracteres.
*
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//apenas para declarar as variáveis que vamos usar
//para testar seu código, você pode usar apenas 5 pessoas.
#define QUANTIDADEPESSOAS 3
#define COMPRIMENTONOMES 30

void carregar(char[QUANTIDADEPESSOAS][COMPRIMENTONOMES], int[QUANTIDADEPESSOAS]);
void ordenar(char[QUANTIDADEPESSOAS][COMPRIMENTONOMES], int[QUANTIDADEPESSOAS]);
double media(int[QUANTIDADEPESSOAS]);
void listar(char[QUANTIDADEPESSOAS][COMPRIMENTONOMES], int[QUANTIDADEPESSOAS], double);

int main() {
	char nomes[QUANTIDADEPESSOAS][COMPRIMENTONOMES];
	int idades[QUANTIDADEPESSOAS];

	carregar(nomes, idades);
	ordenar(nomes, idades);
	listar(nomes, idades, media(idades));

	system("Pause");
	return 0;
}

void carregar(char pessoas[QUANTIDADEPESSOAS][COMPRIMENTONOMES], int idades[QUANTIDADEPESSOAS]) {
	int c = 0;
	for (int i = 0; i < QUANTIDADEPESSOAS; i++) {
		printf("Informar o nome da pessoa %d: ", i + 1);
		scanf_s("%s", &pessoas[i], COMPRIMENTONOMES + 1);
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}

		printf("Informar a idade do(a) % s: ", *pessoas[i]);
		scanf_s("%d", &idades[i]);
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}
	}
}

void ordenar(char pessoas[QUANTIDADEPESSOAS][COMPRIMENTONOMES], int idades[QUANTIDADEPESSOAS]) {
	int idade = 0, flag = 1;
	char nome[COMPRIMENTONOMES] = { ' ' };

	while (flag) {
		flag = 0;
		for (int i = 0; i < QUANTIDADEPESSOAS - 1; i++)
			if (strcmp(pessoas[i], pessoas[i + 1]) > 0)
			{
				strcpy_s(nome, pessoas[i]);
				strcpy_s(pessoas[i], pessoas[i + 1]);
				strcpy_s(pessoas[i + 1], nome);

				idade = idades[i];
				idades[i] = idades[i + 1];
				idades[i + 1] = idade;

				flag = 1;
			}
	}
}

double media(int idades[QUANTIDADEPESSOAS]) {
	double media = 0.0;

	for (int i = 0; i < QUANTIDADEPESSOAS; i++)
		media += idades[i];

	media = media / 20;

	return(media);
}

void listar(char pessoas[QUANTIDADEPESSOAS][COMPRIMENTONOMES], int idades[QUANTIDADEPESSOAS], double media) {

	printf("\nLista das pessoas a baixo da média de idade do grupo:\n");

	for (int i = 0; i < QUANTIDADEPESSOAS; i++)
		if (idades[i] < media)
			printf("%s, idade: %d\n", *pessoas[i], idades[i]);
}
