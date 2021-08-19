#include <stdio.h>
#include <stdlib.h>

/* 
Programa cria uma matriz independente qualquer dado as dimensoes m e n
*/

void exibir(int **matr, int m, int n){	
	
	int i, j;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%d ", matr[i][j]);
		}
		printf("\n");
	}	
}

void build(int ***matr, int m, int n){
	int i, j, **temp;
	
	if(NULL == (temp = (int**) calloc(m, sizeof(int*)))){
		printf("Sem memoria pra isso.");
	}
	
	for(i = 0; i < m; i++){
		temp[i] = (int *) calloc(n, sizeof(int));
	}
	
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			if(i == j){
				temp[i][j] = 1;
			}
		}
	}
	
	*matr = temp;
}

void liberar( int ***matr, int m, int n ){
	int i, j, *current, **temp;
	temp = *matr;
	
	for(i = 0; i < (m * n); i++){
		current = temp[i];
		free(current);
	}
	
}

int main(void){
	int m, n, **matrA, i, j;
	printf("Entre com o numero de linhas: ");
	scanf("%d", &m);
	
	printf("Entre com o numero de colunas: ");
	scanf("%d", &n);
	
	build(&matrA, m, n);
	exibir(matrA, m, n);
	liberar(&matrA, i, j);

	return 0;	
}
