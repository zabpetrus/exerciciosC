/*
Suponha que, para seguran�a, determinado sistema
codifique as senhas num�ricas de seus usu�rios
acrescentando uma unidade a cada um de seus
algarismos (exceto se o algarismo for 9; neste caso, ele
ser� substitu�do pelo n�mero 0 na codifica��o).

*/

#include <stdio.h>


int codificar (int n)
{
	int i, pos, ant, tmp, sum = 0;
	for(i = 10; i < n*10; i*=10)
	{
		pos = n%i;
		ant = n%(i/10);			
		tmp = (pos - ant) / (i/10);	
			
		if(tmp == 9)
		{
			tmp = 0;			
		}
		else
		{
			tmp = tmp + 1;
		}		
				
		tmp = tmp * (i/10);	
		sum = sum + tmp;		
	}
	return sum;
}

int decodificar (int n)
{
	int i, pos, ant, tmp, sum = 0;
	for(i = 10; i < n*10; i*=10)
	{
		pos = n%i;
		ant = n%(i/10);			
		tmp = (pos - ant) / (i/10);	
			
		if(tmp == 0)
		{
			tmp = 9;			
		}
		else
		{
			tmp = tmp - 1;
		}		
				
		tmp = tmp * (i/10);	
		sum = sum + tmp;		
	}
	return sum;
}

int main(void)
{
	int i, a, cod, dec;
	printf("\nEntre com um numero qualquer: ");
	scanf("%d", &a);
	cod = codificar(a);	
    printf("\nO numero codificado eh: %d", cod);
	dec = decodificar(cod);
	printf("\nO numero decodificado eh: %d", dec);
}


