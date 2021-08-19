#include <stdio.h>
#include <math.h>
#define TAM 3

void exibir( double *vet ){
	int i;
	for(i = 0; i < TAM; i++){
		printf("%.0lf ", vet[i]);
	}
}

int ehtriangulo( double *vet ){
	if(vet[0] >= (vet[1] + vet[2]) )
	{
		return 0;
	}	
	return 1;
}

double setSquare( double num ){
	return (pow(num, 2));
}

int ehtriretangulo( double *vet ){
	
	double a2, b2, c2;
	a2 = setSquare( vet[0] );
	b2 = setSquare( vet[1] );
	c2 = setSquare( vet[2] );
	if(a2 == ( b2 + c2 ))
	{
		return 1;
	}
	
	return 0;
}

int ehtriobtusangulo( double *vet ){
	
	double a2, b2, c2;
	a2 = setSquare( vet[0] );
	b2 = setSquare( vet[1] );
	c2 = setSquare( vet[2] );
	if(a2 > ( b2 + c2 ))
	{
		return 1;
	}
	
	return 0;
}


int ehtriacutangulo( double *vet ){
	
	double a2, b2, c2;
	a2 = setSquare( vet[0] );
	b2 = setSquare( vet[1] );
	c2 = setSquare( vet[2] );
	if(a2 < ( b2 + c2 ))
	{
		return 1;
	}
	
	return 0;
}

int ehtriequilatero( double *vet ){
		
	if((vet[0] == vet[1]) && (vet[1] == vet[2]))
	{
		return 1; //eh equilatero
	}
	else
	{
		if((vet[0] == vet[1]) || (vet[1] == vet[2]) || (vet[0] == vet[2]))
		{
			return 2; //eh isosceles
		}
	}
	
	return 0;
}



void tridescendente(double *vet)
{
	int i = 0, j = 1;
	double temp;
	while(j < TAM)
	{
		if(vet[i] < vet[j])
		{
			temp = vet[i];
			vet[i] = vet[j];
			vet[j] = temp;
			i = 0;
			j = 1;
		}
		else
		{
			j++;
			i++;
		}		
	}
}


int main(void)
{
	double triangulo[TAM];
	scanf("%lf %lf %lf", &triangulo[0], &triangulo[1], &triangulo[2]);
	tridescendente(triangulo);
	
	if(ehtriangulo(triangulo))
	{
		if(ehtriretangulo(triangulo))
		{
			printf("TRIANGULO RETANGULO\n");
		}
		if(ehtriobtusangulo(triangulo))
		{
			printf("TRIANGULO OBTUSANGULO\n");
		}
		if(ehtriacutangulo(triangulo))
		{
			printf("TRIANGULO ACUTANGULO\n");
		}
		if(ehtriequilatero(triangulo) == 1)
		{
			printf("TRIANGULO EQUILATERO\n");
		}
		if(ehtriequilatero(triangulo) == 2)
		{
			printf("TRIANGULO ISOSCELES\n");
		}
	}
	else
	{
		printf("NAO FORMA TRIANGULO\n");
	}	
	
	//exibir( triangulo );
	return 0;
}
