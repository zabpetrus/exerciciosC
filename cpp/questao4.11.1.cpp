/*
Lista 4 exercicio 11

Implementar um programa no qual o usu�rio informa um n�mero e verifica-se se ele � um n�mero triangular.
Obs.: Um n�mero � triangular quando ele for resultado do produto de tr�s n�meros consecutivos.
Exemplo: 24 = 2 x 3 x 4.

*/

#include <stdio.h>

int main(void)
{
	int a, b, c, produto, numero;
	
	printf("Entre com um numero: ");
	scanf("%d", &numero);
	
	a = 1;
	b = 2;
	c = 3;
	
	do
	{
		produto = a*b*c;
		
		a++;
		b++;
		c++;
		
	}
	while(produto < numero);
	
	if(produto == numero)
	{
		printf("O numero eh triangular");
	}
	else
	{
		printf("O numero nao eh triangular", numero);
	}
	
	return 0;
}
