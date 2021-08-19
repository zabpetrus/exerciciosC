#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencher(int** matriz, int linhas, int colunas);
void exibir(int **matriz, int linhas, int colunas);
void liberar(int ***matriz, int linhas, int colunas);
void criar_matriz(int ***product, int la, int cb);
int colunaresultante( int la, int ca, int lb, int cb  );
int linharesultante( int la, int ca, int lb, int cb  );
int produtopossivel( int la, int ca, int lb, int cb );
int calcdif(int la, int ca, int lb, int cb);
void produto_matriz(int ***product, int **mA, int **mB, int la, int ca, int lb, int cb);

int main(void)
{
	int la, ca, lb, cb, **matA, **matB, **matp, i, lp, cp;
	
	printf("Entre com o numero de linhas da matriz A: ");
	scanf("%d", &la);
	printf("Entre com o numero de colunas da matriz A: ");
	scanf("%d", &ca);
	
	printf("Entre com o numero de linhas da matriz B: ");
	scanf("%d", &lb);
	printf("Entre com o numero de colunas da matriz B: ");
	scanf("%d", &cb);
	
	if(produtopossivel(la,ca,lb,cb))
	{
		lp = linharesultante(la,ca,lb,cb);
		cp = colunaresultante(la,ca,lb,cb);
		
		criar_matriz(&matA, la, ca);
		criar_matriz(&matB, lb, cb);
	
		preencher(matA, la, ca);
		preencher(matB, lb, cb);	
			
		exibir(matA, la, ca);
		exibir(matB, lb, cb);		
		
		criar_matriz(&matp, la, cb);		
		produto_matriz(&matp, matA, matB, la, ca, lb, cb);
		exibir(matp, lp, cp);
		
		liberar(&matA, la, ca);
		liberar(&matB, lb, cb);
		liberar(&matp, lp, cp);
		
	}
	else{
		printf("O produto das matrizes nao eh possivel.");
	}		
	return 0;	
}  


void preencher(int** matriz, int linhas, int colunas){
	int i, j;
	srand(time(NULL));
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			matriz[i][j] = rand()%10;
		}
	}	
}

void exibir(int **matriz, int linhas, int colunas){
	int i, j;
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");	
}

void liberar(int ***matriz, int linhas, int colunas){
	
	int i, j, *p;
	for(i = 0; i < linhas; i++){
		for( j = 0; j < colunas; j++){
			p = matriz[i][j];
			free(p);
		}						
	}	
}

int produtopossivel( int la, int ca, int lb, int cb )
{
	if(ca == lb) {
		return 1;
	}
	return 0;		
}

int linharesultante( int la, int ca, int lb, int cb  )
{
	if(ca == lb){
		return la;
	}
	return 0;
}

int colunaresultante( int la, int ca, int lb, int cb  )
{
	if(ca == lb){
		return cb;
	}
	return 0;	
}

void criar_matriz(int ***product, int la, int cb)
{
	int **temp, a, soma = 0; 
	
	temp = (int** ) calloc(la, sizeof(int* ));
	for(a = 0; a < la; a++){
		temp[a] = (int *) calloc(cb, sizeof(int));
	}	
		
	*product = temp;	
}

void produto_matriz(int ***product, int **mA, int **mB, int la, int ca, int lb, int cb){
	
	int i, j, k, l, **temp, soma = 0, dif;
	temp = *product;
	
	dif = calcdif(la, ca, lb, cb);
	
	for(i = 0; i < la; i++){
		for(j = 0; j < cb; j++){
			for(k = 0; (k < (cb-dif) && k < (la-dif)); k++){
				soma = soma + (mA[i][k] * mB[k][j]);
			}
			temp[i][j] = temp[i][j] + soma;
			soma = 0;			
		}
	}	
}

int calcdif(int la, int ca, int lb, int cb){
	
	int pa, pb;
	pa = abs(la - ca);
	pb = abs(lb - cb);
	if(pa > pb){
		return pa;
	}
	return pb;	
}

