/*
Lista 5 questao 8
Fa�a um programa que leia um n�mero real x e um n�mero inteiro y. 
Em seguida, o programa deve ler 100 n�meros reais e calcular quantos destes est�o a uma �dist�ncia� de x de, no m�ximo, y.
Exemplo: suponha x = 10 e y = 2. O programa pede para calcular quantos dos 100 n�meros 
fornecidos est�o compreendidos entre 8.0 (a uma dist�ncia de 2 (y) antes de 10 (x)) e 12.0 (a uma dist�ncia de 2 (y) depois de 10 (x))
*/
#include <stdio.h>

int main(void)
{
	int i;
	float y; //int y
	float x, unk, dists = 0, disti = 0;
	int cont = 0;	
	float n = 10; //100
	
	printf("\nEntre com um numero real: ");
	scanf("%f", &x);
		
	printf("\nEntre com o inteiro: ");
	scanf("%f", &y);
	
	
	for(i = 1; i <= n; i++)
	{
		printf("\nEntre com um numero qualquer: ");
		scanf("%f", &unk);
		
		dists = x - y;
		disti = x + y;
		
		if((unk > dists) && (unk < disti))
		{
			cont = cont + 1;			
		}		
	}
	
	printf("Existem %d numeros entre %.0f e %.0f", cont, dists, disti );
	return 0;
	
}
