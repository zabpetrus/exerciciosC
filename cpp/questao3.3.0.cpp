/*
QUEST�O 03: Jo�ozinho investiu Q reais em uma aplica��o com rendimento fixo de R% ao m�s.
 Pede-se a implementa��o de um programa que calcule o valor (e exiba-o) dispon�vel na conta de Jo�ozinho ap�s A anos de investimento.
 https://www.bussoladoinvestidor.com.br/como-calcular-a-rentabilidade-do-investimento/
*/

#include <stdio.h>
int main(void)
{
	float q, rend, tempo, a, r;
	float cops = 1.0;
	int i;
	
	printf ("\nEntre com o valor do valor aplicado: ");
	scanf("%f", &q);
	
	printf ("\nEntre com o valor do rendimento R%% ao mes:  )");
	scanf("%f", &rend);
	
	printf ("\nEntre o tempo a ser calculado (em anos): ");
	scanf("%f", &a);
	
	tempo = a * 12;
	
	
	for(i = 0; i <= (int)tempo; i++)
	{
		cops = (1 + (rend / 100 ) )* cops;
	}
	
	printf ("\n\nCops %.2f", cops);
	
	r = (1 + (rend / 100 )) * ( (  ( cops - 1 ) / (rend / 100 ) ) * q );
	
	printf ("\n\nResposta: %.2f", r);

	return 0;
}
