/*
Lista 4 exercicio 9
QUEST�O 09:
Escrever um programa que encontre o quinto n�mero maior que 1000, cuja divis�o por 11 tenha resto 5.
*/

#include <stdio.h>

int main(void)
{
	int i, j, num, cont = 1;
	for(i = 1000; i < 2000; i++)
	{
		if(i%11==5)
		{
			if(cont == 5)
			{
				printf("O quinto numero eh: %d ", i);
				break;
			}
			else
			{
				cont++;
			}
			
		}
	}
		
	
	return 0;
}


