#include <stdio.h>
/*
Fa�a um programa que leia do teclado um n�mero n>=10 e exiba o somat�rio de
todos os m�ltiplos de 3 entre 1 e n. Caso n seja menor do que 10 o programa
deve ser encerrado imediatamente. Dica: utilize um comando enquanto dentro
de um comando se. 
*/

int main(void)
{
	int i = 1, n, soma = 0;
	
	printf("\nEntre com um numero maior que 10:");
	scanf("%d", &n);
	if(n >= 10)
	{
		while(i <= n)
		{
			if(i%3 == 0)
			{
				soma = soma + i;				
			}
			
			i++;
		}
		printf("\nSoma: %d", soma);
	}
	return 0;
}
