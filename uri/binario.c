#include <stdio.h>

int i = 1, soma = 0;

void binario( int num )
{
	if(num > 0)
	{
		printf("%d", num % 2);
	    soma = soma + (num % 2) * i;
	    i = i * 10;
		binario(num / 2);
	}

}

int main(void)
{
	int num;
	printf("Entre com o numero: ");
	scanf("%d", &num);
	binario(num);

  printf("\nSoma: %d\n", soma);
	return 0;
}
