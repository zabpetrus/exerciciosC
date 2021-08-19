#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**  Não funciona direito se a diferenca entre linhas e colunas for muito grande
e for ascendente e descendente - 8,5,5,3 ou 3,4,4,7. Dá ruim
**/

int validaproduto(int m1, int n1, int m2, int n2 ){
	if(n1 == m2){
		return 1;
	}
	return 0;
}

int sizecorrector(int m1, int n1, int m2, int n2){
	
	int pa, pb;
	pa = abs(m1 - n1);
	pb = abs(m2 - n2);
	if(pa < pb){
		return pa;
	}
	return pb;
}

void populate(int ***mat, int m, int n){
	int i, j, k;
	int **temp;
	
	srand(time(NULL));
	
	temp = (int **) calloc(m, sizeof(int *));
	for(k = 0; k < m; k++){
		temp[k] = (int *) calloc(n, sizeof(int));
	}
	
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			temp[i][j] = rand() % 100;
		}
	}
		
	*mat = temp;	
}

int linhaproduto(int m1, int n1, int m2, int n2){
	if(n1 == m2){
		return m1;
	}
	return 0;	
}
	
int colunaproduto(int m1, int n1, int m2, int n2){
	if(n1 == m2){
		return n2;
	}
	return 0;
}

void matrizproduto(int ***matp, int **mat1, int **mat2, int m1, int n1, int m2, int n2){
	
	int i, j, k, **temp, soma = 0, lp, cp, adj;
	int *p, *q;
	
	lp = linhaproduto(m1, n1, m2, n2);
	cp = colunaproduto(m1, n1, m2, n2);
	
	//Alocar a matriz produto
	temp = (int**) calloc(lp, sizeof(int *));
	for(i = 0; i < cp; i++){
		temp[i] = (int *) calloc(cp, sizeof(int));
	}
	
	adj = sizecorrector(m1, n1, m2, n2);
	
	//calcular o produto das matrizes A e B
	for(i = 0; i < lp; i++){
		for(j = 0; j < cp; j++){
			
			for(k = 0; (k < (lp - adj)) && (k < (cp - adj)) ; k++){				
				soma = soma + ( ( mat1[i][k] ) * (mat2[k][j]) );
			}
			temp[i][j] = temp[i][j] + soma;	
			soma = 0;
		}		
	}
	
	*matp = temp;
		
}

void exibir(int **mat, int m, int n){
	int i, j;
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%3d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");	
}



int main(void){
	
	int m1,n1, m2, n2, **mat1, **mat2, **matp;
	printf("Entre com o numero de linhas da matriz A: ");
	
	fflush(stdin);
	scanf("%d", &m1);
	printf("Entre com o numero de colunas da matriz A: ");
	
	fflush(stdin);
	scanf("%d", &n1);
	
	printf("Entre com o numero de linhas da matriz B: ");
	
	fflush(stdin);
	scanf("%d", &m2);
	
	printf("Entre com o numero de colunas da matriz B: ");
	
	fflush(stdin);
	scanf("%d", &n2);
	
	if(validaproduto(m1,n1,m2,n2)){
		
		
		printf("\nMATRIZ A (%d x %d): \n", m1, n1 );
		populate(&mat1, m1, n1);		
		exibir(mat1, m1, n1);
		
		printf("\nMATRIZ B: (%d x %d)\n", m2 , n2);
		populate(&mat2, m2, n2);
		exibir(mat2, m2, n2);
		
		printf("\nMATRIZ PRODUTO: (%d x %d)\n", m1 , n2);		
		matrizproduto(&matp, mat1, mat2, m1, n1, m2, n2);
		exibir(matp, m1, n2);
		
	}
	else{
		printf("O produto das matrizes nao eh possivel.");
	}
	
	return 0;	
}


