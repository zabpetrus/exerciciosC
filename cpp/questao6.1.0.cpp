/*
QUEST�O 02: Um fazendeiro realizou um tratamento sobre sua planta��o de caf� que gerou um crescimento constante de C % em sua produ��o, por ano. 
Considerando que atualmente sua produ��o anual seja de M  u.p., 
implementar um programa que determine a quantidade de anos necess�ria para que a produ��o duplique.
*/

#include <stdio.h>
#include <math.h>



int main(void)
{
	int i;
	float prod, c, cresc;
	float finprod;
	
	printf("Entre com a producao em um ano: ");
	scanf("%f", &prod);
	
	printf("Entre com o crescimento anual (em %%)");
	scanf("%f", &c);
	
	finprod = prod * 2;
	cresc = c / 100;	
		
	i = 1; //ano
	while(prod <= finprod)
	{
		prod = prod + (prod * cresc);
		if(finprod == prod)
		{
			break;
		}
		i++;
    }
	
	printf("\n%d ano(s)", i);
	return 0;	 
	
}
