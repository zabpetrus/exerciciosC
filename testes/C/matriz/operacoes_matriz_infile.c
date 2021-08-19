#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criar( int*** matriz, int m, int n );
void exibir(int** matriz, int m, int n );
void somar(int*** aux, int** mA, int** mB, int m, int n );
void subtrair(int*** aux, int** mA, int** mB, int m, int n );
void multiplicar(int*** aux, int** mA, int** mB, int m, int n, int o, int p );
void liberar( int** matriz, int linhas, int colunas );
int possivelprod(int la, int ca, int lb, int cb);
void guardarimatriz( int ***matr, int linhas, int colunas, char *nome , int code );
int calcdif(int la, int ca, int lb, int cb);


int main(void){
	
	int m, n, o, p;
	int **mA, **mB, **mC;
	char nome[30];
	FILE *fp;
	
	printf("Entre com o nome do arquivo que sera guardado: ");
	fscanf(stdin, "%s", nome);
	
	fp = fopen(nome,"w+");
	
	if(!fp){
		printf("Erro de abertura do arquivo. A execucao sera encerrada!");
		exit(1);
	}
	
	fclose(fp);
	
	printf("Entre com a dimensao da matriz A: \n");
	printf("Comprimento: ");
	scanf("%d", &m);
	
	printf("Largura: ");
	scanf("%d", &n);
	
	criar(&mA, m, n);
	exibir(mA, m, n);
	guardarimatriz(&mA, m, n, nome, 0);
	
	
	printf("Entre com a dimensao da matriz B: \n");
	printf("Comprimento: ");
	scanf("%d", &o);
	
	printf("Largura: ");
	scanf("%d", &p);
	
	criar(&mB, o, p);
	exibir(mB, o, p);
	guardarimatriz(&mB, o, p, nome, 0);
	
	
	if(m == o && n == p)
	{
		printf("\n1. Soma: ");
		somar(&mC, mA, mB, m, n);	
		exibir(mC, m, n);
		guardarimatriz(&mC, m, n, nome, 0);
			
		printf("\n2. Subracao: ");
		subtrair(&mC, mA, mB, m, n);	
		exibir(mC, m, n);
		guardarimatriz(&mC, m, n, nome, 0);
		
	}
	else
	{
		printf("\nAdicao e subtracao nao eh possivel.");	
		printf("\nMatrizes com numero de linhas e colunas diferentes.");
		guardarimatriz(&mA, m, n, nome, 1);
	}
	
	
	if(possivelprod(m,n,o,p) == 1)
	{
		printf("\n\n3. Multiplicacao: \n");
		multiplicar(&mC, mA, mB, m, n, o, p);	
		exibir(mC, m, p);
		guardarimatriz(&mC, m, p, nome, 0);		
	}
	else
	{
		printf("Nao eh possivel efetuar a multiplicacao.\n");
		printf("O numero de colunas de A e diferente do numero de linhas de B.");
		guardarimatriz(&mC, m, p, nome, 2);
	}
			
	
	return 0;
}


void criar( int*** matriz, int m, int n ){
		
	int i, j;
	int **temp;
	srand(time(NULL));
	
	temp = (int** ) malloc(m * sizeof(int*));
	for(i = 0; i < m; i++){
		temp[i] = (int *) malloc(n * sizeof(int));
	}
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			temp[i][j] = rand() % 100;
		}
	}
	
	*matriz = temp;	
}

void exibir(int** matriz, int m, int n )
{
	int i, j;
	printf("\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%2d ",matriz[i][j] );
		}
		printf("\n");
	}
	printf("\n");
}

void somar(int*** aux, int** mA, int** mB, int m, int n ){
	
	int i, j, k, l;
	int **temp;
	
	temp = (int **) malloc(m * sizeof(int*));
	for(i = 0; i < n; i++){
		temp[i] = (int *) malloc(n * sizeof(int));
	}
	
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			temp[i][j] = mA[i][j] + mB[i][j];
		}
	}	
	
	*aux = temp;
}


void subtrair(int*** aux, int** mA, int** mB, int m, int n ){
	
	int i, j, k, l;
	int **temp;
	
	temp = (int **) malloc(m * sizeof(int*));
	for(i = 0; i < n; i++){
		temp[i] = (int *) malloc(n * sizeof(int));
	}
	
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			temp[i][j] = mA[i][j] - mB[i][j];
		}
	}	
	
	*aux = temp;
}

void multiplicar(int*** aux, int** mA, int** mB, int m, int n, int o, int p ){
	
	int i, j, k, l, cp, lp, foo;
	int **temp, soma = 0;
	
	lp = m;
	cp = p;
	
	temp = (int **) calloc(lp, sizeof(int *));
	for(i = 0; i < lp; i++){
		temp[i] = (int *) calloc(cp,sizeof(int));
	}
	
	foo = calcdif(m, n, o, p);


	for(i = 0; i < lp; i++){
		for(j = 0; j < cp; j++){	
						
			for(k = 0; (k < (cp-foo) && k < (lp-foo)); k++){
				soma = soma + (mA[i][k] * mB[k][j]);	
			}
			temp[i][j] = temp[i][j] + soma;	
			soma = 0;
		}
	}	
	
	*aux = temp;
}


void liberar( int** matriz, int linhas, int colunas )
{
	int i, j;
	for(i = 0; i < linhas*colunas;i++){
		free (matriz[i]);
	}
}

int possivelprod(int la, int ca, int lb, int cb){
	
	if(ca == lb){
						
		return 1;		
	}
	
	return 0;	
}

void guardarimatriz( int ***matr, int linhas, int colunas, char *nome , int code ){
	
	int i, j, **temp;
	FILE *fp;
	fp = fopen(nome, "aw");
	if(!fp){
		printf("Erro na abertura para atualizacao!");
		exit(2);
	}
	if(code == 1){
		fprintf(fp, "\nNao eh possivel efetuar a operacao de adicao e subracao\n\n");
	}
	
	else if(code == 2){
		fprintf(fp, "\nNao eh possivel efetuar a operacao de multiplicacao\n\n");
	}
	
	else
	{	
		temp = *matr;
		for(i = 0; i < linhas; i++){
			for(j = 0; j < colunas; j++){
				fprintf(fp, "%2d ", temp[i][j]);
			}
			fprintf(fp, "\n");
		}
		fprintf(fp, "\n");		
	}
	
	fclose(fp);
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

	
	


