#include <stdio.h>
/*
Leia do teclado um valor n que represente um intervalo de dias. Caso o valor lido
seja menor do que 1 encerre o programa imediatamente. Caso contr�rio leia as
temperaturas m�ximas registradas na cidade nos �ltimos n dias, calcule a m�dia
das mesmas e a exiba no monitor. 
*/

int main(void)
{
	int n, i = 1; 
	float tmax, tsoma = 0; // n dias
	scanf("%d", &n);
	if(n > 1)
	{
		while(i <= n)
		{
			printf("TMAX - %do dia: ", i);
			scanf("%f",&tmax);
			tsoma = tsoma + tmax;
			i++;		
		}
		printf("Media: %.2f", tsoma / n );		
	}	
	return 0;
}
