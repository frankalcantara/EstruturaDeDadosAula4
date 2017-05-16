/*
* Criar um programa que possibilite a pesquisa “binária” em um vetor com 10.000 numeros inteiros.
*/

 
#include<stdio.h>
#include<stdlib.h>
#include <time.h> //para usar a função time
//apenas para declarar as variáveis que vamos usar
//para testar seu código, você pode usar apenas 3 pessoas.
//depois substitua por 10000
#define COMPRIMENTOVETOR 10000


//protótipos
int pesquisar(int, int, int, int []);



int main(){
	int vet[COMPRIMENTOVETOR];
	int num = 0, ret = 0, c = 0, temp =0;

	printf("Gerando os numeros...\n");
	//para preencher o array com números aleatórios
	srand(time(0)); //semente para o gerador de números aleatórios
	for (int i = 0; i < COMPRIMENTOVETOR; i++){
		vet[i] = (rand() % 100) + 1;	//gerando números randômicos entre zero e 100
	}
	printf("Ordenando o array...\n");
	//agora precisamos ordenar o vetor gerado 
	//vou usar o bubble sort mesmo sendo lento
	for (int i = 0; i < COMPRIMENTOVETOR; i++) {
		for (int j = i + 1; j < COMPRIMENTOVETOR; j++) {
			if (vet[i] > vet[j]) {
				temp = vet[i];
				vet[i] = vet[j];
				vet[j] = temp;
			}
		}
	}

 	printf("Informar número que deseja pesquisar: ");
	scanf_s("%d", &num);
	//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
	while ((c = getchar()) != '\n' && c != EOF) {}

	ret = pesquisar(0, 9999, num, vet);
	if (ret > -1)
		puts("O Número se encontra no Vetor.\n");
	else
		puts("O Número Não foi localizados no Vetor");

	system("Pause");
	return 0;
}


int pesquisar(int ini, int fim, int num, int vet[]){
	int pos, ret;

	if(ini > fim)
		return(-1);

	pos = ini + (int)((fim - ini) / 2);

	if (vet[pos] == num)
		return(pos);

	else if (num > vet[pos])
		ret = pesquisar(pos + 1, fim, num, vet);
	else
		ret = pesquisar(ini, pos - 1, num, vet);

	return(ret);
}

