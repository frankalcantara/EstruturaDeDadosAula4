/*
* Criar um programa para realizar uma pesquisa sequencial em uma matriz 10x10 de números inteiros.
*/


#include<stdio.h>
#include<stdlib.h>
//apenas para declarar as variáveis que vamos usar
//para testar seu código, você pode usar apenas 3 pessoas.
//depois substitua por 10
#define NUMERODELINHAS 3
#define NUMERODECOLUNAS 3

//protótipos
void carregar(int [NUMERODELINHAS][NUMERODECOLUNAS]);
char pesquisa(int[NUMERODELINHAS][NUMERODECOLUNAS], int );


void main(){
	int num = 0, c = 0,  mat[NUMERODELINHAS][NUMERODECOLUNAS];

	carregar(mat);
	printf("Informe 1 número para pesquisa: ");
	scanf("%d", &num);
	//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
	while ((c = getchar()) != '\n' && c != EOF) {}

	if (pesquisa(mat, num) == 'S')
		printf("O número se encontra na matriz!!!");
	else
		printf("O número não se encontra na matriz!!!");

	system("Pause");
	return 0;
}


void carregar(int mat[NUMERODELINHAS][NUMERODECOLUNAS]){
	int c = 0;

	for (int i = 0; i < NUMERODELINHAS; i++)
		for (int j = 0; j < NUMERODECOLUNAS; j++){
			printf("Informar Número Inteiro para [%d][%d]: ", i , j);
			scanf("%d", &mat[i][j]);
			//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
			while ((c = getchar()) != '\n' && c != EOF) {}
		}
}

char pesquisa(int mat[NUMERODELINHAS][NUMERODECOLUNAS], int num){

	for (int i = 0; i < NUMERODELINHAS; i++)
		for (int j = 0; j < NUMERODECOLUNAS; j++)
			if (num == mat[i][j])
				return('S');
	return('N');
}
