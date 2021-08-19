#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, n, vet[5], soma = 0;
	srand(time(NULL));
	a = rand()%100;	
	
	for(i = 0; i < 5; i++)
	{		
		vet[i] = rand() % a;
	}
	
	for(i = 0; i < 5; i++)
	{
		printf("%d ", vet[i]);		
		soma = soma + vet[i];
	}
	
	printf("Soma: %d\n", soma);
	return 0;
}
