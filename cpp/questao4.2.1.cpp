/*
Lista 4 exercicio 2

Desenvolver um programa que calcule a soma dos n�meros de 1 a N, sendo N um n�mero inteiro fornecido pelo usu�rio.

*/

#include <stdio.h>

int main(void)
{
	int i, n;
	int soma = 0;
	
	printf("Entre com o limite da soma: ");
	scanf("%d", &n);
	
	for(i = 1; i <= n; ++i)
	{
		soma = soma + i;
	}
	
	printf("A soma eh: %d", soma);
	return 0;
}
