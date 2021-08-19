#include <stdio.h>
#include <math.h>

double delta(double a, double b, double c)
{
	double delta = (b * b) - (4 * a * c);
	return delta;	
}

void bhaskara(double a, double b, double c)
{
	double vdelta, r1, r2;
	vdelta = delta(a, b, c);
	r1 = (( (-1) * b) + sqrt(vdelta) ) / (2 * a);
	r2 = (( (-1) * b) - sqrt(vdelta)) / (2 * a);
	
	
	if(vdelta < 0 || a == 0){
		printf("Impossivel calcular\n");
	}
	else
	{
		printf("R1 = %.5lf\n",r1 );
		printf("R2 = %.5lf\n",r2 );
	}
}


int main(void)
{
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	bhaskara(a, b, c);
	return 0;
}

