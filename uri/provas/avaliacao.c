#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, soma = 0, vet[5], tam = 5;
	srand(time(NULL));
		
	
	for(i = 0; i < tam; i++)
	{
		vet[i] = rand() % 10;
	}
	
	for(i = 0; i < tam; i++)
	{
		printf("%d ", vet[i]);
	}
  printf("\n");
	
	for(i = 0; i < tam; i++)
	{
		soma = soma + vet[i];
	}
	
	printf("\n\nSOMA: %d\n", soma);	
	
}
