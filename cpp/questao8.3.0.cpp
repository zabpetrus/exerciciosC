/*
QUEST�O 03:
Pede-se a implementa��o de uma fun��o que, dado um vetor contendo n�meros reais, determine se o mesmo encontra-se ordenado de forma crescente.
*/
#include <stdio.h>

void crescente( float *vet, int size )
{
	int i, cont = 0;
	for(i = 0; i <= size; i++)
	{
		if(vet[i] < vet[i+1])
		{
			cont++;
		}
	}
	
	if(cont==size)
	{
		printf("Crescente");
	}
	else
	{
		printf("Decrescente");
	}
}

int main(void)
{
	float vet[5] = {1, 2, 3, 5, 6};
	crescente(vet, 5);
}
