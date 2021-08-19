#include <stdio.h>
#include <stdlib.h>

double perimetro(double a, double b, double c)
{
	return a + b + c;
}

double area(double a, double b, double c)
{
	return (((a + b) * c ) / 2.0 );
}

int ehtriangulo(double a, double b, double c)
{
	int cond1, cond2, cond3, condA, condB, condC;
	condA = a > (abs(b - c));
	condB = b > (abs(a - c));
	condC = c > (abs(a - b));
	
	cond1 = (a < (b + c)) && condA;
	cond2 = (b < (a + c)) && condB;
	cond3 = (c < (a + b)) && condC;
	
	if(cond1 && cond2 && cond3)
	{
		return 1;
	}
	
	return 0;
}

int main(void)
{
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	if(ehtriangulo(a, b, c))
	{
		printf("Perimetro = %.1f\n", perimetro(a, b, c));
	}
	else
	{
		printf("Area = %.1f\n", area(a, b, c));
	}
	
	return 0;	
}
