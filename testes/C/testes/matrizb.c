#include <stdio.h>
#include <stdlib.h>

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

void preencher( int **matrA, int **matrB,  int l1, int c1,  int l2, int c2 )
{
	int i, k, j, cont = 0;
	FILE *fp;
	int source;
	fp = fopen("matriz.txt", "r");	
	
	for(i = 0; i < l1; i++)
	{
		for( j = 0; j < c1;j++)
		{
			fscanf(fp, "%d", &source);
			matrA[i][j] = source;
		}
	}
	
	for(i = 0; i < l2; i++)
	{
		for(j = 0; j < c2; j++)
		{
			fscanf(fp, "%d", &source);
			matrB[i][j] = source;
		}
	}	
}

int foo( int x, int y, int l1, int c1, int l2, int c2, int **matrA, int **matrB)
{
	int i, j, k, l, presto, soma = 0;
	
	for(i = 0; i < l1; i++)
	{
		for(j = 0; j < c1; j++)
		{
			for(k = 0; k < l2; k++)
			{
				for( l = 0; l < c2; l++)
				{
					if(( i == x ) && (l == y))
					{
						soma = soma + (matrA[i][j] * matrB[k][l]);
					}
				}
			}
		}
	}
	
	return soma;
}

void produto( int **matrA, int **matrB,  int l1, int c1,  int l2, int c2 )
{
	int i, j, lp, cp, **mprod; 
	mprod = (int **) malloc(l1 * sizeof (int *) );
	for(i = 0; i < l1; i++)
	{
		mprod[i] = (int *) malloc(c2 * sizeof(int));
	}
	
	for(i = 0; i < l1; i++ )
	{
		for(j = 0; j < c2; j++)
		{
			mprod[i][j] = foo(i, j, l1, c1, l2, c2, matrA, matrB);
		}
	}
	
	exibirmatriz(mprod, l1, c2);		
}




void inicializarmatriz( int ***matr, int linhas, int colunas)
{
	int **temp, i, j;
	temp = (int **) malloc( linhas * (sizeof( int * )));
	for(i = 0; i < linhas; i++)
	{
		temp[i] = (int *) malloc( colunas * (sizeof( int )));
	}
	*matr = temp;
}

int validate( int l1, int c1, int l2, int c2 )
{
	if(c1 == l2)
	{
		return 1;
	}
	return 0;
}

int main(){
	
	int **matrA, **matrB; 
	int l1, l2, c1, c2;
	printf("Entre com as dimensoes da primeira matriz: ");
	scanf("%d  %d", &l1, &c1);
	printf("Entre com as dimensoes da segunda matriz: ");
	scanf("%d   %d", &l2, &c2);
	if(validate(l1, c1, l2, c2))
	{
		inicializarmatriz(&matrA, l1, c1); //inicializando matrizA
		inicializarmatriz(&matrB, l2, c2);
		preencher(matrA, matrB, l1, c1, l2, c2);
		produto(matrA, matrB, l1, c1, l2, c2);		
	}
	else
	{
		printf("Nao eh possivel efetuar a multiplicacao destas matrizes. ");
	}
	return 0;
}
