#include <stdio.h>

int intervalo( double n )
{
	if(n >= 0.0 && n <= 100.0)
	{
		if(n >= 0.0 && n <= 25.0)
		{
			return 1; //[0, 25]
		}
		if(n > 25 && n <= 50.0)
		{
			return 2; // (25, 50]
		}
		if(n > 50 && n <= 75)
		{
			return 3; //(50, 75]
		}
		else
		{
			return 4; //(75, 100]
		}				
	}
	else
	{
		return 0; //Fora do intervalo
	}	
}

void verificar( double n )
{
	switch( intervalo(n) )
	{
		case 1:
			printf("Intervalo [0,25]\n");
			break;
			
		case 2:
			printf("Intervalo (25,50]\n");
			break;
			
		case 3:
			printf("Intervalo (50,75]\n");
			break;
		
		case 4:
			printf("Intervalo (75,100]\n");
			break;
			
		default:
			printf("Fora de intervalo\n");
			
	}
}


int main(void)
{
	double n;
	scanf("%lf", &n);
	verificar(n);
	return 0;
}

