/*
QUEST�O 04:
Fazer uma fun��o que armazene em um vetor os 50 primeiros termos da seguinte sequ�ncia:
S = 1, 2, 4, 7, 11, 16, ...
Nota: observem que a diferen�a entre o 1� e 2� elementos � igual a 1, entre o 2� e 3� � igual a 2, entre o 3� e o 4� � igual a 3, e assim sucessivamente.
*/

#include <stdio.h>

void seed (int *vet, int tam)
{
	int i, k = 1;
	for(i = 0; i < tam; i++)
	{
		k = k + i;
		vet[i] = k;
		printf("%d ", vet[i]);
		
	}
}

int main(void)
{
	unsigned int i;
    int vet[i];
	printf("Entre com o numero de elementos: ");
	scanf("%d", &i);
	seed(vet, i);
}
