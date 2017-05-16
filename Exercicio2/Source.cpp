/*
*	Criar um programa que receba o nome das 100 primeiras pessoas que entraram em uma determinada loja. 
* Os dados devem ser armazenados em um vetor e o nome do cliente já em ordem alfabética crescente.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//apenas para declarar as variáveis que vamos usar
//para testar seu código, você pode usar apenas 5 pessoas.
#define QUANTIDADEPESSOAS 100
#define COMPRIMENTONOMES 30

//protótipo da função de ordenação usando array de strings, de char e uma quantidade
void ordenar(char [][COMPRIMENTONOMES], char [COMPRIMENTONOMES], int qtd);

int main() {
	char vet_nomes[QUANTIDADEPESSOAS][COMPRIMENTONOMES];
	char  nome[COMPRIMENTONOMES];

	for (int i = 0; i < QUANTIDADEPESSOAS; i++)	{
		printf("Informe o %d nome : ", i + 1);
		//para carregar o nome completo digitado vamos pegar a linha toda
		gets_s(nome, sizeof(nome));
		ordenar(vet_nomes, nome, i);
	}

	//apenas para verificar se o vetor foi ordenado
	for (int i = 0; i < QUANTIDADEPESSOAS; i++){
		printf("%s\n", vet_nomes[i]);
	}
	system("pause");
	return 0;
}
//definição da função de ordenação
void ordenar(char vetor[][COMPRIMENTONOMES], char nome[COMPRIMENTONOMES], int qtd) {
	int x = 0, y = 0;
	char aux[COMPRIMENTONOMES] = {' '};

	if (qtd == 0) {
		strcpy_s(vetor[0], nome);
	} else {
		for (x = 0; x<qtd; x++) {
			if (strcmp(nome, vetor[x]) < 0)
				for (y = x; y < qtd; y++) {
					strcpy_s(aux, vetor[y]);
					strcpy_s(vetor[y], nome);
					strcpy_s(nome, sizeof(aux), aux);
					x = y;
				}
		}
		strcpy_s(vetor[qtd], nome);
	}
}
