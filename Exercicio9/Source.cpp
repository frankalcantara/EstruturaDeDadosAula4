/*
* Criar um programa que possua um vetor de 70 posições de registros 
* com os seguintes campos: Nome, idade e cpf. 
* Após armazenado os dados o vetor deve ser ordenado pelo nome, 
* sendo que o usuário poderá definir se o vetor será ordenado em ordem “crescente” ou “decrescente”.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//apenas para declarar as variáveis que vamos usar
//para testar seu código, você pode usar apenas 3 pessoas.
//depois substitua por CEM
#define COMPRIMENTODOVETOR 70

struct Dados {
	char nome[30], cpf[15];
	int idade;
};

struct Dados vetor[COMPRIMENTODOVETOR];

void carregar();
void ordenar(int);
void mostrar(struct Dados vetor[]);


int main(){
	int op = 0, c = 0 ;

	carregar();
	printf("Informe 1 para ordenar em ordem Crescente, ou 2 para ordenar em ordem Decrescente: ");
	scanf("%d", &op);
	ordenar(op); 
	//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
	while ((c = getchar()) != '\n' && c != EOF) {}

	//para mostrar a ordenação
	mostrar(vetor);
	system("Pause");
	return 0;
}


void carregar(){
	int c = 0;

	for (int i = 0; i < COMPRIMENTODOVETOR; i++) {
		printf("Informar o Nome da pessoa %d: ", i + 1);
		scanf_s("%s", &vetor[i].nome, sizeof(vetor[i].nome));
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}

		printf("Informar a Idade da pessoa %d: ", i + 1);
		scanf_s("%d", &vetor[i].idade);
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}

		printf("Informar o Cpf da pessoa %d: ", i + 1);
		scanf_s("%s", &vetor[i].cpf, sizeof(vetor[i].cpf));
		//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
		while ((c = getchar()) != '\n' && c != EOF) {}
	}
}

void ordenar(int op) {
	int x, y, flag = 1, idade;
	char nome[30], cpf[15];

	while (flag) {
		flag = 0;
		for (y = 0; y < COMPRIMENTODOVETOR-1; y++)
			if (op == 1) {
				if (strcmp(vetor[y].nome, vetor[y + 1].nome) > 0) {
					strcpy_s(nome, vetor[y].nome);
					strcpy_s(vetor[y].nome, vetor[y + 1].nome);
					strcpy_s(vetor[y + 1].nome, nome);

					strcpy_s(cpf, vetor[y].cpf);
					strcpy_s(vetor[y].cpf, vetor[y + 1].cpf);
					strcpy_s(vetor[y + 1].cpf, cpf);

					idade = vetor[y].idade;
					vetor[y].idade = vetor[y + 1].idade;
					vetor[y + 1].idade = idade;

					flag = 1;
				}
			}
			else {
				if (strcmp(vetor[y].nome, vetor[y + 1].nome) < 0) {
					strcpy(nome, vetor[y].nome);
					strcpy(vetor[y].nome, vetor[y + 1].nome);
					strcpy(vetor[y + 1].nome, nome);

					strcpy(cpf, vetor[y].cpf);
					strcpy(vetor[y].cpf, vetor[y + 1].cpf);
					strcpy(vetor[y + 1].cpf, cpf);

					idade = vetor[y].idade;
					vetor[y].idade = vetor[y + 1].idade;
					vetor[y + 1].idade = idade;

					flag = 1;
				}
			}
	}
}


void mostrar(Dados vetor[]) {
	for (int i = 0; i < COMPRIMENTODOVETOR; i++) {
		printf("Nome: %s\n", vetor[i].nome);
		printf("Idade: %d\n", vetor[i].idade);
		printf("Nome: %s\n", vetor[i].cpf);
		printf("\n");
	}
}

