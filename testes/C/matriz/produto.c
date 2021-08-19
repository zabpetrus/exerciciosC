#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int calculaproduto(int linhasA, int colunasA, int linhasB, int colunasB);
void criarmatrizvazia( int ***matr, int linhas, int colunas);
void criarmatriz( int ***matr, int linhas, int colunas);
void liberarmatriz(int **matriz, int linhas, int colunas);
void gravarnoarquivo(char* nomedoarquivo, int **matriz, int linhas, int colunas);
void exibirmatriz( int **matriz, int linhas, int colunas);
void matrizproduto( int ***mproduto, int **origA, int **origB, int la, int cb);
void errodegravacao(char *nomedoarquivo );

int main(void){
	
	int la, ca, lb, cb, **mA, **mB, **mP;
	char nomedoarquivo[30];
	
	printf("Entre com o nome do arquivo a ser salvo:");
	fgets(nomedoarquivo, 128, stdin);
	
	
	printf("Entre com o numero de linhas da matrizA: ");
	scanf("%d", &la);
	printf("Entre com o numero de colunas da matrizA: ");
	scanf("%d", &ca);
	
	criarmatriz(&mA, la, ca);
	exibirmatriz(mA, la, ca);
	gravarnoarquivo(nomedoarquivo, mA, la, ca);
	
	
	printf("Entre com o numero de linhas da matrizB: ");
	scanf("%d", &lb);
	printf("Entre com o numero de colunas da matrizB: ");
	scanf("%d", &cb);
	
	criarmatriz(&mB, lb, cb);
	exibirmatriz(mB, lb, cb);
	gravarnoarquivo(nomedoarquivo, mB, lb, cb);	
	
	
	if(calculaproduto(la, ca, lb, cb) == 1){
				
		criarmatrizvazia(&mP, la, cb);
		matrizproduto(&mP, mA, mB, la, cb);
		exibirmatriz(mP, la, cb);
		gravarnoarquivo(nomedoarquivo, mP, la, cb);
		
		liberarmatriz(mA, la, ca);
		liberarmatriz(mB, lb, cb);
		liberarmatriz(mP, la, cb);				
		
	}else
	{
		printf("\nO produto entre as matrizes nao eh possivel.");
		errodegravacao(nomedoarquivo);	
	}
	
	return 0;	
}

void criarmatriz( int ***matr, int linhas, int colunas){
	int i, j, **temp;
	srand(time(NULL));
	
	temp = (int**) calloc(linhas, sizeof(int *));
	for(i = 0; i < linhas; i++){
		temp[i] = (int *) calloc(colunas, sizeof(int));
	}
	
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			temp[i][j] = rand()%100;
		}
	}
	*matr = temp;
}

void criarmatrizvazia( int ***matr, int linhas, int colunas){
	int i, j, **temp;
	
	temp = (int**) calloc(linhas, sizeof(int *));
	for(i = 0; i < linhas; i++){
		temp[i] = (int *) calloc(colunas, sizeof(int));
	}

	*matr = temp;
}


void liberarmatriz(int **matriz, int linhas, int colunas){
	int i, j;	
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			free( *(matriz + j) );
		}				
	}	
}

int calculaproduto(int linhasA, int colunasA, int linhasB, int colunasB){
	if(colunasA == linhasB){
		return 1;
	}
	return 0;
}

void gravarnoarquivo(char* nomedoarquivo, int **matriz, int linhas, int colunas){
	
	int i, j;
	FILE *fp;
	fp = fopen(nomedoarquivo, "aw");
	if(!fp){
		printf("Erro de abertura do arquivo.");
		exit(1);
	}
	
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			fprintf(fp,"%d ", matriz[i][j]);
		}
		fprintf(fp,"\n");
	}
	fprintf(fp,"\n");
	
	fclose(fp);	
}



void exibirmatriz( int **matriz, int linhas, int colunas){
	int i, j;
	
	printf("\n");
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void matrizproduto( int ***mproduto, int **origA, int **origB, int la, int cb){
	int i, j, k, **temp, soma = 0;
	temp = *mproduto;
	
	for(i = 0; i < la; i++){
		for(j = 0; j < cb; j++){
			for(k = 0; (k < (la-1) && k < (cb-1)); k++){
				soma = soma + (origA[i][k] * origB[k][j]);
			}
			temp[i][j] = temp[i][j] + soma;
			soma = 0;
		}
	}	
}

void errodegravacao(char *nomedoarquivo ){
	
	FILE *fp;
	fp = fopen(nomedoarquivo, "aw");
	fprintf(fp,"%s", "O produto entre as matrizes nao eh possivel.");
	fclose(fp);
}





