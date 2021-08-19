#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int **matr, rows, cols, i, j;
	printf("Entre com o numero de linhas e colunas: ");
	scanf("%d  %d", &rows, &cols);
	
	matr = (int **) malloc( rows * sizeof( int * ));
	for(i = 0; i < rows; i++){
		matr[i] = (int *) malloc(cols * sizeof(int));
	}
	
	
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++)
		{
			matr[i][j] = 0;
		}
	}
	
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++)
		{
			printf("%d  ", matr[i][j]);
		}
		printf("\n");
	}
	return 0;
	
}
