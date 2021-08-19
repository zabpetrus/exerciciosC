#include <stdio.h>
#include <stdlib.h>

void buildmatriz( int ***matr, int ordem )
{
	int **temp, i;
	temp = (int **) malloc( ordem * (sizeof(int *)));
	for(i = 0; i < ordem; i++){
		temp[i] = (int *) malloc( ordem * (sizeof(int)));
	}
	*matr = temp;
}

void preenchermatriz( int **matr, int ordem )
{
	int i, j, tam;
	FILE *fp;
	fp = fopen("det.txt","r");
	
	for(i = 0; i < ordem; i++)
	{
		for(j = 0; j < ordem; j++)
		{
			fscanf(fp,"%d", &matr[i][j]);
		}
	}	
}

int ndet( int **matr, int ordem )
{
	int i, j, dpp = 1, dps = 1;
	
	if(ordem == 2)
	{
		for(i = 0; i < ordem; i++)
		{
			for(j = 0; j < ordem; j++)
			{
				if(i == j)
				{
					dpp = dpp * matr[i][j];
				}
				else
				{
					dps = dps * matr[i][j];
				}
			}
		}
		return( dpp - dps );		
	}	
}


void exibir( int **matr, int ordem )
{
	int i, j;
	for(i = 0; i < ordem; i++ ){
		for(j = 0; j < ordem; j++){
			printf("* %d *", matr[i][j]);
		}
		printf("\n");
	}	
}


int calculardet( int **matr, int ordem )
{
	exibir(matr,ordem);
	return 1;
}


int main(){
	
	int **matr, ordem, determinante;
	printf("Entre com a ordem da matriz: ");
	scanf("%d", &ordem);
	buildmatriz(&matr, ordem);
	preenchermatriz(matr, ordem);
	determinante = calculardet(matr,ordem);
	return 0;	
}
