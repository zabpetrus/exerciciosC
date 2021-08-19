#include <stdio.h>

int ehmultiplo(int a, int b)
{	
	if(a > b)
	{
		return ((a % b) == 0);
	}
	
	return ((b % a) == 0);
	
}



int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	if(ehmultiplo(a, b))
	{
		printf("Sao Multiplos\n");
	}
	else
	{
		printf("Nao sao Multiplos\n");
	}
	
	return 0;
	
}
