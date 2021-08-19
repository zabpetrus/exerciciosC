#include <stdio.h>
#include <stdlib.h>

/* Construir um programa que leia dois arquivos, cada um com uma matriz
cujos nomes serão fornecidos pelo usuário. Em seguida:

a) Verifique se é possível realizar a soma entre as matrizes
b) Se for possível, solicite o nome de um novo arquivo e grave o resultado
c) Verifiqye se é possível multiplicar a primeira pela segunda matriz
d) Se for possível, solicite o nome de um novo arquivo e grave o resultado
*/

int valida_somaesub( int m1, int n1, int m2, int n2 ){
	if((m1 == m2) && (n1 == n2)){
		return 1;
	}
	return 0;
}

int valida_produto( int m1, int n1, int m2, int n2 ){
	if(n1 == m2){
		return 1;
	}
	return 0;
}

int calcdif(int la, int ca, int lb, int cb){
	
	int pa, pb;
	pa = abs(la - ca);
	pb = abs(lb - cb);
	if(pa < pb){
		return pa;
	}
	return pb;	
}

void carregarmatriz(FILE *fp, int ***matrA, int *l, int *c){
	
	char *aux;
	int i, j,  **temp, m, n, num, offset;
	
	fscanf(fp, "%d  %d", &m, &n);	
	
	aux = (char *) calloc( m * n, sizeof(char));	
	
	temp = (int **) calloc( m, sizeof(int *));
	for(i = 0; i < m; i++){
		temp[i] = calloc(n, sizeof(int));
	}	
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			fscanf(fp,"%d", &temp[i][j]);
		}
	}
		
	free(aux);
	
	*l = m;
	*c = n;	
	*matrA = temp;	
}

void exibirmatriz( int **matriz, int linhas, int colunas ){
	int i, j;
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void matrizSoma( int ***matrizS, int **matA, int **matB, int l, int c ){
	
	int i, j, **temp;
	temp = (int **) calloc( l, sizeof(int *));
	for(i = 0; i < l; i++){
		temp[i] = (int *) calloc(c, sizeof(int));
	}
	
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			temp[i][j] = matA[i][j] + matB[i][j];
		}
	}
	
	*matrizS = temp;
}


void matrizSubtracao( int ***matrizS, int **matA, int **matB, int l, int c ){
	
	int i, j, **temp, aux;
	temp = (int **) calloc( l, sizeof(int *));
	for(i = 0; i < l; i++){
		temp[i] = (int *) calloc(c, sizeof(int));
	}
	
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			
			aux = matA[i][j] - matB[i][j];		
			temp[i][j] = aux;
			
		}
	}
	
	*matrizS = temp;
}

void matrizProduto( int ***matrizS, int **matA, int **matB, int la, int ca, int lb, int cb ){
	
	int i, j, k, **temp, aux, soma = 0;
	temp = (int **) calloc(la, sizeof(int *));
	for(i = 0; i < la; i++){
		temp[i] = (int *) calloc(cb, sizeof(int));
	}
	
	aux = calcdif(la, ca, lb, cb);
	
	for(i = 0; i < la; i++){
		for(j = 0; j < cb; j++){
			
			for(k = 0; (k < (cb-aux) && k < (lb-aux)); k++){
				soma = soma + (matA[i][k] * matB[k][j]);	
			}
			temp[i][j] = temp[i][j] + soma;	
			soma = 0;			
		}
	}
	
	*matrizS = temp;
}


int main(void){
	
	FILE *fp, *sp;
	int m1, n1, m2, n2, **matrA, **matrB, **matrC;
	char nomeA[30], nomeB[30];
	printf("Entre com o nome do arquivo da matrizA: ");
	fscanf(stdin, "%s", nomeA);
	
	printf("Entre com o nome do arquivo da matrizB: ");
	fscanf(stdin, "%s", nomeB);
	
	fp = fopen(nomeA, "r+");
	sp = fopen(nomeB, "r+");
	
	if(!fp && !sp){
		printf("\nErro durante a abertura dos arquivos.");
		exit(1);
	}	
	
	carregarmatriz(fp, &matrA, &m1, &n1);
	carregarmatriz(sp, &matrB, &m2, &n2);
	
	printf("\nLinhas: %d    Colunas: %d \n", m1, n1);
	printf("\nLinhas: %d    Colunas: %d \n", m2, n2);
	
	
	if(valida_somaesub(m1, n1, m2, n2)){
		
		printf("MATRIZ A:\n");
		exibirmatriz(matrA, m1, n1);
		
		printf("MATRIZ B:\n");
		exibirmatriz(matrB, m2, n2);
		
		printf("MATRIZ SOMA:\n");
		matrizSoma(&matrC, matrA, matrB, m1, n1);
		exibirmatriz(matrC, m1, n1);
		free(matrC);
		
		printf("MATRIZ SUBTRACAO:\n");
		matrizSubtracao(&matrC, matrA, matrB, m1, n1);
		exibirmatriz(matrC, m1, n1);
		free(matrC);		
	}	
	else{
		printf("\nNao eh possivel operar adicao e subracao. Matrizes de dimensoes diferentes.\n");
	}
	
	
	
	if(valida_produto(m1, n1, m2, n2)){	
	
		printf("MATRIZ A:\n");	
		exibirmatriz(matrA, m1, n1);
		
		printf("MATRIZ B:\n");
		exibirmatriz(matrB, m2, n2);
		
		printf("MATRIZ PRODUTO:\n");
		matrizProduto(&matrC, matrA, matrB, m1, n1, m2, n2);
		exibirmatriz(matrC, m1, n2);
		free(matrC);				
	}	
	else{
		printf("\nNao eh possivel multiplicar as matrizes\n.O numero de colunas da matrizA eh diferente do numero de linhas da matrizB.\n");
	}
	
	return 0;
}

