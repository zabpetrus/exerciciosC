#include <stdio.h>

void pg(double n, double a1, double q)
{
	if(n > 0){
		
		printf("%.0lf ", a1);
		//an = a1 * q^(n - 1);
		pg(n-1, a1*q, q);		
	}
}

int main(void)
{
	double n, a1, q;
	printf("Entre com o numero de termos, o primeiro termo e a razao: ");
	scanf("%lf  %lf  %lf", &n, &a1, &q);
	pg(n, a1, q);
	return 0;
}
