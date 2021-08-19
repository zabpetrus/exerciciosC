#include <stdio.h>


void validapontos(double x, double y)
{
	if(x != 0.0 && y != 0.0)
	{
		if((x > 0.0) && (y > 0.0)){
			printf("Q1\n");
		}
		else if((x > 0.0) && (y < 0.0)){
			printf("Q4\n");
		}
		else if((x < 0.0) && (y > 0.0)){
			printf("Q2\n");
		}
		else
		{
			printf("Q3\n");
		}
	}
	else
	{
		if(x == 0)
		{
			if(y == 0)
			{
				printf("Origem\n");
			}
			else
			{
				printf("Eixo Y\n");
			}
			
		}
		else
		{
			printf("Eixo X\n");
		}
	}
	
}

int main(void)
{
	double x, y;
	int pt;
	scanf("%lf  %lf", &x, &y);
	validapontos(x, y);
	return 0;
}
	
	
	
