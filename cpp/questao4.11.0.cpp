/*
Lista 4 exercicio 11

Implementar um programa no qual o usu�rio informa um n�mero e verifica-se se ele � um n�mero triangular.
Obs.: Um n�mero � triangular quando ele for resultado do produto de tr�s n�meros consecutivos.
Exemplo: 24 = 2 x 3 x 4.

*/

#include <stdio.h>

int main(void)
{
	int n, i, temp = 1, num;
	printf("Entre com um numero: ");
	scanf("%d", &n);
	
	for(i = 1; (i <= n)&&(temp != n)); i++)
	{
		temp = i * (i + 1) * (i + 2);
		//printf("%d * %d  * %d \n", i, i+1, i+2);
				
		if (temp == n)
		{
			num = temp;
			break; //M� pr�tica ^^
		}
		else
		{
		 	num = 0;	
		}	
	}
	
	if(num == 0)
	{
		printf("\nO numero nao eh tringular");
	}
	else
	{
		printf("\nO numero eh tringular");
	}
	
	
	return 0;
}
