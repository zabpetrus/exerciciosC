#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Construir um programa que leia dois arquivos, cada um com uma matriz
cujos nomes serão fornecidos pelo usuário. Em seguida:

a) Verifique se é possível realizar a soma entre as matrizes
b) Se for possível, solicite o nome de um novo arquivo e grave o resultado
c) Verifiqye se é possível multiplicar a primeira pela segunda matriz
d) Se for possível, solicite o nome de um novo arquivo e grave o resultado
*/



void gerarmatriz( FILE *fp, int ***matr, int l, int c ){
	
	int i, j, **temp;
	
	fprintf(fp, "%d  %d\n", l, c);
	
	
	temp = (int **) calloc(l, sizeof(int *));
	for(i = 0; i < l; i++){
		temp[i] = (int *) calloc(c, sizeof(int));
	}
	
	for(i = 0; i < l; i++ ){
		for(j = 0; j < c; j++){
			temp[i][j] = rand() % 10;
		}
	}
	
	for(i = 0; i < l; i++ ){
		for(j = 0; j < c; j++){
			fprintf(fp, "%2d ", temp[i][j]);
		}
		fprintf(fp, "\n");
	}	
	*matr = temp;
}

void exibirmatriz(int **matr, int linhas, int colunas){
	int i, j;
	printf("\n");
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			printf("%2d ", matr[i][j]);
		}
		printf("\n");
	}
}


int main(void){
	
	int m1, n1, m2, n2, **matrA, **matrB, **matrC;
	char nomeA[30], nomeB[30];
	FILE *fp, *sp;
	srand(time(NULL));
	
	
	printf("\nEntre com o nome do arquivo da matriz 1: ");
	fscanf(stdin, "%s", nomeA);
	
	printf("\nEntre com o nome do arquivo da matriz 2: ");
	fscanf(stdin, "%s", nomeB);
	
	printf("\nEntre com o numero de linhas da matriz 1: ");
	scanf("%d", &m1);
	printf("\nEntre com o numero de colunas da matriz 1: ");
	scanf("%d", &n1);
	printf("\nEntre com o numero de linhas da matriz 2: ");
	scanf("%d", &m2);
	printf("\vEntre com o numero de colunas da matriz 2: ");
	scanf("%d", &n2);
	
	fp = fopen(nomeA, "w+");
	gerarmatriz(fp, &matrA, m1, n1);
	fclose(fp);
					
	sp = fopen(nomeB, "w+");
	gerarmatriz(sp, &matrB, m2, n2);
	fclose(sp);
	
	exibirmatriz(matrA, m1, n1);
	exibirmatriz(matrB, m2, n2);

	free(matrA);
	free(matrB);
	
	printf("\nArquivos criados com sucesso!\n");	
	return 0;
}

