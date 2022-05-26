/* Exercicio 2
Construir um programa em C que o usu�rio entre com:
Entrada:
n, inteiro [quantidade de elementos do vetor]
a, inteiro [amplitude do intervalo de elementos inteiros];

Gere duas matrizes Anxn e Nnxn preenchidas com numeros inteiros escolhidos,
aletoriamente, no intervalo entre [0,a[. Em seguida, construa uma matriz
Cnxn = Anxn + Bnxn e apresente as tr�s matrizes .

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
	int A[3][3], B[3][3], C[3][3];
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
			C[i][j] = (A[i][0] * B[0][i]) + (A[i][1] * B[1][i])	+ (A[i][2] * B[2][i]);			
		}
	}
	
	exibir(C);
	return 0;
	
}


