/* Exercicio 2
Construir um programa em C que o usuário entre com:
Entrada:
n, inteiro [quantidade de elementos do vetor]
a, inteiro [amplitude do intervalo de elementos inteiros];

Gere duas matrizes Anxn e Nnxn preenchidas com numeros inteiros escolhidos,
aletoriamente, no intervalo entre [0,a[. Em seguida, construa uma matriz
Cnxn = Anxn + Bnxn e apresente as três matrizes .

*/

#include <stdio.h>
#define TAM 3


void exibir(int matriz[3][3])
{
	int i, j;
	
	for(i = 0; i < TAM; i++)
	{
		for(j = 0; j < TAM; j++)
		{
			printf("%4d ", matriz[i][j]);
		}
		
		printf("\n");
	}
	printf("\n\n");
}

int main(void)
{
	int i, j, a;
	
	int **A, **B, **C;
	printf("Entre com o tamanho da matriz: ");	
	scanf("%d", &n);
	
	A = (int **) n * malloc(sizeof(int));
	
	
	srand(time(NULL));
	
	a = rand()%10;
	for(i = 0; i < TAM; i++)
	{
		for(j = 0; j < TAM; j++)
		{
			A[i][j] = rand()%a;
			B[i][j] = rand()%a;			
		}
	}
	
	exibir(A);
	exibir(B);
	
	for(i = 0; i < TAM; i++)
	{
		for(j = 0; j < TAM; j++)
		{
			C[i][j] = A[i][j] + B[i][j];				
		}
	}
	
	exibir(C);
	return 0;
	
}


