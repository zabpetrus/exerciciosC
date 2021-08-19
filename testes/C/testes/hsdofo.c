#include <stdio.h>
#include <stdlib.h>

int checazero( int **temp, int tam );
void adicionar(int num, int **temp, int size, int index);
void inicializarmat( FILE *fp, int ***matr, int n );
void exibirmatriz( int **matr, int n);
void exibir( int xind, int yind, int **matr, int ordem);

int main(void){
	
	int n, **matr;	
	FILE *fp;
	fp = fopen("quadrada.txt","r");
	fscanf(fp,"%d",&n);
	inicializarmat(fp, &matr, n);
	exibir(0, 0, matr, n);

	
	fclose(fp);	
	return 0;
}

void inicializarmat(FILE *fp,  int ***matr, int n )
{
	int **temp, i, j;
	temp = (int **) malloc(n * sizeof(int *));
	for(i = 0; i < n; i++)
	{
		temp[i] = (int *) malloc(n * sizeof(int));
	}	
	
	for(i = 0; i < n; i++)	
	{
		for(j = 0; j < n; j++)
		{
			fscanf(fp,"%d",&temp[i][j]);
		}
	}
	*matr = temp;
}

void exibirmatriz( int **matr, int n){
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d ", matr[i][j] );
		}
		printf("\n");
	}
}

void exibir( int xind, int yind, int **matr, int ordem){
	int i, j,k, l, m, tam;
	int **temp;
	
	tam = ordem - 1;
	temp = (int **) malloc (tam * sizeof( int *));	
	for(k =0; k < tam; k++)
	{
		temp[k] = (int *) malloc(tam * sizeof(int));	
	}	
	
	for(i =0; i< tam; i++)
	{
		for(j = 0; j < tam; j++)
		{
			temp[i][j] = 0;
		}		
	}
	
	k = 0;
	l = 0;
	
	for(i = 0, k = 0; i < ordem; i++)
	{
		for (j = 0, l = 0; j < ordem; j++){
			
			if((i!= xind) && (j != yind))
			{
				temp[k][l] = matr[i][j];
				l++;
				if(l == tam)
				{
					k++;
				}
			}			
		}
	}	

	exibirmatriz(temp, tam);
}



