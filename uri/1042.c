#include <stdio.h>

void xcopy(int *vet, int *aux, int tam )
{
	int i;
	for(i = 0; i < tam; i++)
	{
		aux[i] = vet[i];
	}
}

void exibir(int vet[], int tam )
{
	int i;
	for(i = 0; i < tam; i++)
	{
		printf("%d\n",vet[i]);
	}	
}


void simplesort(int vet[], int tam)
{
	int i, j, temp, change = 0;
	i = 0;
	j = 1;
	while((i < tam-1) && (change < tam-1))
	{
		if(vet[i] > vet[j])
		{
			temp = vet[i];
			vet[i] = vet[j];
			vet[j] = temp;			
			i = 0;
			j = 1;			
		}
		else
		{
			i++;
			j++;
			change++;
		}
	}
}


int main(void)
{
	int vet[3], aux[3];
	fflush(stdin);	
	scanf("%d  %d  %d", &vet[0], &vet[1], &vet[2]);	
	xcopy(vet, aux, 3);
	simplesort(vet, 3);
	exibir(vet, 3);
	printf("\n");
	exibir(aux, 3);		
	return 0;	
}
