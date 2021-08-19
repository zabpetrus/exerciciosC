#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criar( double*** matriz, int m, int n );
void exibir(double** matriz, int m, int n );
void somar(double*** aux, double** mA, double** mB, int m, int n );
void subtrair(double*** aux, double** mA, double** mB, int m, int n );
void multiplicar(double*** aux, double** mA, double** mB, int m, int n, int o, int p );
void inversa(double*** aux, double** mA, int ordem );
void liberar( double** matriz, int linhas, int colunas );


int main(void){
	
	int m, n, o, p;
	double **mA, **mB, **mC;
	
	printf("Entre com a dimensao da matriz A: \n");
	printf("Comprimento: ");
	scanf("%d", &m);
	
	printf("Largura: ");
	scanf("%d", &n);
	
	criar(&mA, m, n);
	exibir(mA, m, n);
	
	printf("Entre com a dimensao da matriz B: \n");
	printf("Comprimento: ");
	scanf("%d", &o);
	
	printf("Largura: ");
	scanf("%d", &p);
	
	criar(&mB, o, p);
	exibir(mB, o, p);
	
	
	if(m == o && n == p)
	{
		printf("\n1. Soma: ");
		somar(&mC, mA, mB, m, n);	
		exibir(mC, m, n);
			
		printf("\n2. Subracao: ");
		subtrair(&mC, mA, mB, m, n);	
		exibir(mC, m, n);
		
	}
	else
	{
		printf("Matrizes com numero de linhas e colunas diferentes.");
	}
	
	
	if(n == o)
	{
		printf("\n3. Multiplicacao: ");
		multiplicar(&mC, mA, mB, m, n, o, p);	
		exibir(mC, m, p);
		
		printf("\n4. Inversa: ");
		inversa(&mC, mA, m);	
		exibir(mC, m, p);
		
	}
	else
	{
		printf("Nao eh possivel efetuar a multiplicacao.\n");
		printf("O numero de colunas de A e diferente do numero de linhas de B.");
	}
			
	
	return 0;
}


void criar( double*** matriz, int m, int n ){
		
	int i, j;
	double **temp;
	srand(time(NULL));
	
	temp = (double **) malloc(m * sizeof(double*));
	for(i = 0; i < n; i++){
		temp[i] = (double *) malloc(n * sizeof(double));
	}
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			temp[i][j] = rand() % 100;
		}
	}
	
	*matriz = temp;	
}

void exibir(double** matriz, int m, int n )
{
	int i, j;
	printf("\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%.0lf ",matriz[i][j] );
		}
		printf("\n");
	}
	printf("\n");
}

void somar(double*** aux, double** mA, double** mB, int m, int n ){
	
	int i, j, k, l;
	double **temp;
	
	temp = (double **) malloc(m * sizeof(double*));
	for(i = 0; i < n; i++){
		temp[i] = (double *) malloc(n * sizeof(double));
	}
	
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			temp[i][j] = mA[i][j] + mB[i][j];
		}
	}	
	
	*aux = temp;
}


void subtrair(double*** aux, double** mA, double** mB, int m, int n ){
	
	int i, j, k, l;
	double **temp;
	
	temp = (double **) malloc(m * sizeof(double*));
	for(i = 0; i < n; i++){
		temp[i] = (double *) malloc(n * sizeof(double));
	}
	
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			temp[i][j] = mA[i][j] - mB[i][j];
		}
	}	
	
	*aux = temp;
}

void multiplicar(double*** aux, double** mA, double** mB, int m, int n, int o, int p ){
	
	int i, j, k, l;
	double **temp, soma = 0;
	
	temp = (double **) malloc(m * sizeof(double*));
	for(i = 0; i < p; i++){
		temp[i] = (double *) malloc(p * sizeof(double));
	}
	
	for(i = 0; i < m; i++){
		for(j = 0; j < p; j++){
			temp[i][j] = 0;
		}
	}
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){	
						
			for(k = 0; k < p; k++){
				soma = soma + (mA[i][k] * mB[k][j]);	
			}
			temp[i][j] = temp[i][j] + soma;	
			soma = 0;
		}
	}	
	
	*aux = temp;
}


void inversa(double*** aux, double** mA, int ordem ){
	
	int i, j;
	double **temp, **ident;
	
	temp = (double **) malloc(ordem * sizeof(double*));
	ident = (double **) malloc(ordem * sizeof(double*));
	
	
	for(i = 0; i < ordem; i++){
		temp[i] = (double *) malloc(ordem * sizeof(double));
		ident[i] = (double *) malloc(ordem * sizeof(double));
	}
	
	for(i = 0; i < ordem; i++){
		for(j = 0; j < ordem; j++){
			if(i==j){
				ident[i][j] = 1;
			}
			else
			{
				ident[i][j] = 0;
			}
		}
	}
	
	multiplicar(&temp, mA, ident, ordem, ordem, ordem, ordem );
	*aux = temp;	
	
}



void liberar( double** matriz, int linhas, int colunas )
{
	int i, j;
	for(i = 0; i < linhas*colunas;i++){
		free (matriz[i]);
	}
}

