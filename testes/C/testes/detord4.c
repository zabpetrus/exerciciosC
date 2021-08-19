#include <stdio.h>
#include <stdlib.h>

int matriztrestres( int **matr, int ordem );

void exibirmatriz( int **matr, int rows, int cols)
{
	int i, j;
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++)
		{
			printf("%d ", matr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}



int matrizmenor( int xlinha, int xcoluna , int **matr, int ordem )
{
	//faz a matriz menor
	int **matmenor, i, j, k, l, tam;
	
	tam = ordem - 1;
	matmenor = (int **)malloc(tam * sizeof(int*));
	for(i = 0; i < tam; i++)
	{
		matmenor[i] = (int *) malloc(tam * sizeof(int));
	}
	
	k = l = 0;
	for(i = 0; i < ordem; i++)
	{
		for(j = 0; j < ordem; j++)
		{
			if ((i != xlinha) && (j != xcoluna))
			{
				**matmenor = matr[i][j];
				(**matmenor)++;						
			}		
		}
	}
	exibirmatriz(matmenor, tam, tam);
	
	
}


int detsimples(int **matr, int ordem)
{
	int i, j, dpp = 1, dps = 1;
		
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


int ndet( int **matr, int ordem )
{
	if(ordem == 1)
	{
		return **matr;
	}
	
	else if(ordem == 2)
	{
		return (detsimples(matr,ordem));		
	}
	else
	{
		printf("Ainda nao posso fazer isso.");
	}	
}

void criarmatr( int*** matr, int *ord )
{
	FILE *fp;	
	int** temp, i, j, ordem;
	
	fp = fopen("quadrada.txt","r");
	fscanf(fp,"%d",&ordem);
	
	temp = (int **) malloc( ordem * sizeof(int *));
	for(i = 0; i < ordem; i++)
	{
		temp[i] = (int *) malloc( ordem * sizeof(int));
	}
	
	for(i = 0; i < ordem; i++)
	{
		for(j = 0; j < ordem; j++)
		{			
			fscanf(fp,"%d", &temp[i][j]);
		}
	}
	
	
	*matr = temp;
	*ord = ordem;
}

int main()
{
	int** matr, det, ord;	
	criarmatr(&matr, &ord);
	exibirmatriz(matr,ord,ord);
	matrizmenor( 0, 0, matr, ord );
	
	//det = ndet(matr, ord);
	//printf("Determinante: %d", det);
	return 0;
}
