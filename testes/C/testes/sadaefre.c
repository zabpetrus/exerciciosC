#include <stdio.h>
#include <stdlib.h>

int vet[64];
int cont = 0;

void inverter(int vet[], int cont)
{
	int i, j, meio, temp;
	meio = cont / 2;
	for(i = 0, j = cont; i <= meio; i++, j--){		
		temp = vet[i];
		vet[i] = vet[j];
		vet[j] = temp;
	}
}

// cria vetor binario

int sdfa( int n, int base){
	int quo = n/base;
	if(quo != 0)
	{
		//printf("%d ", n % base);
		vet[cont] = n % base;		
		cont++;
		return sdfa(quo, base);
	}
	else
	{
		vet[cont] = n % base;
		return n % base;	
	}	
}

void exibepod( int vet[], int cont )
{
	int i;	
	printf("\nExibindo o pseudo vetor: \n");
	
	inverter(vet, cont);
	for(i = 0; i < cont+1; i++)
	{
		if(vet[i] == 10)		
			printf("A ");
		else if(vet[i] == 11)
			printf("B ");
		else if(vet[i] == 12)
			printf("C ");
		else if(vet[i] == 13)
			printf("D ");
		else if(vet[i] == 14)
			printf("E ");
		else if(vet[i] == 15)
			printf("F ");
		else		
			printf("%d ", vet[i]);
	}
}

int main(){
	int base, n, foo;
	printf("\n\nConversor de 64 bits.\n\n");
	printf("Entre com o numero n e a base: ");
	scanf("%d  %d", &n, &base);
	foo = sdfa(n, base);
	exibepod(vet, cont);
	return 0;	
}


