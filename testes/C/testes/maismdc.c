#include <stdio.h>
#include <stdlib.h>


int maior(int a, int b)
{
	int res;
	(a > b) ? (res = a) : (res = b);
	return res;
}

int menor(int a, int b)
{
	int res;
	(a < b) ? (res = a) : (res = b);
	return res;
}

int divisaosucessiva( int num )
{
	int i = 2;
	while(i <= num)
	{
		if(num % i == 0) 
		{			
			num = num / i;
			printf("%d ", i);			
		}
		else
		{
			i++;
		}
	}
	printf("\n\n");
}

int mdc(int a, int b){
	
	int resto, nmaior, nmenor;
	
	nmaior = maior(a,b);
	nmenor = menor(a,b);
	resto = nmaior % nmenor;
	
	if( resto == 0 )
	{		
		return (nmenor);
	}
	else
	{
	    return mdc(b, resto);
	}	
}

int organizarvetor( int vet[], int tam)
{
	int i, temp;
	for(i = 0; (i < tam) ;)
	{
		if(vet[i] > vet[i+1])
		{
			i++;
		}
		else
		{
			temp = vet[i];
			vet[i] = vet[i + 1];
			vet[i + 1] = temp;
			i = 0;						
		}
	}
}

int mdcmultiplos(int vet[], int tam)
{
	
	
}


void mdcdoisnumeros()
{
	int a, b;
	printf("Entre com dois numeros: ");
	scanf("%d  %d", &a, &b);
	printf("MDC: %d", mdc(a, b));
}


void denelementos()
{
	int i,tam, *elementos;
	printf("Quantos numeros para serem calculados? ");
	scanf("%d", &tam);
	elementos = (int *) malloc(tam * sizeof(int));
	for( i = 0; i < tam; i++)
	{
		printf("Numero %d: ", i+1);
		fscanf(stdin,"%d", &elementos[i]);
	}
	
	organizarvetor(elementos, tam);
	
	for(i = 0; i < tam; i++)
	{
		printf("%d ", elementos[i]);
	}
	
	mdcmultiplos(elementos, tam);
	
}

void menu()
{
	int option;
	printf("Menu do MM0\n\n 1- MDC dois numeros\n2- MDC de n numeros\n\nEntre com uma opcao: ");
	scanf("%d", &option);
	switch(option)
	{
		case 1:
			mdcdoisnumeros();
			break;
		case 2:
			break;
		default:
			printf("\nEscolha um numero, pls.");
	}
}

int main(void)
{	
	denelementos();
	return 0;
}
