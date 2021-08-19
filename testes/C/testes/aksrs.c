#include <stdio.h>
#include <stdlib.h>

int denominador_comum(int d1, int d2)
{
	return(d1 * d2);
}

int adicao( int n1 ,int d1, int n2, int d2 )
{	
	return((n1 * d2) + (n2 * d1));
}

int subtracao( int n1 ,int d1, int n2, int d2)
{
	return ((n1 * d2)-(n2 * d1));
}

int multiplicacao( int n1, int n2 )
{	
  	return (n1 * n2);
}

int divisao( int n1 ,int d2 )
{
	return (n1 * d2);
}

int denominador_divisao( int n2, int d1 )
{
	return (n2 * d1);
}

void simplificar( int p1, int p2, int *x2, int *x3)
{
	int i = 2, aux1, aux2;
	aux1 = abs(p1);
	aux2 = abs(p2);
	
	
	while((aux1 >= i) && (aux2 >= i))
	{	
		if(((p1 % i) == 0) && ((p2 % i) == 0))
		{
			p1 = p1 / i;
			p2 = p2 / i;
			aux1 = abs(p1);
			aux2 = abs(p2);			
		}
		else
		{
			i++;
		}
	}	
	
	*x2 = p1;
	*x3 = p2;
}

void calcular(int n1, int s1, int d1, int s2, int n2, int s3, int d2)
{
	int xn, xd, p1, p2;
	switch(s2){
		case 43:
			p1 = adicao(n1, d1, n2, d2);
			p2 = denominador_comum(d1, d2);			
			break;
		case 45:
			p1 = subtracao(n1, d1, n2, d2);
			p2 = denominador_comum(d1, d2);	
			break;
		case 42:
			p1 = multiplicacao(n1, n2);
			p2 = denominador_comum(d1, d2);	
			break;					
		default:
			p1 = divisao(n1, d2);
			p2 = denominador_divisao(n2, d1);				 
	}
	
	simplificar(p1, p2, &xn, &xd);	
	printf("%d/%d = %d/%d\n", p1, p2, xn, xd);
}



int main(void)
{
	int i, tam, n1, d1, n2, d2, s1, s2, s3;
	scanf("%d", &tam);
	for(i = 0; i < tam; i++)
	{
		fscanf(stdin,"%d %c %d %c %d %c %d", &n1, &s1, &d1, &s2, &n2, &s3, &d2);
		calcular(n1, s1, d1, s2, n2, s3, d2);		
	}
	return 0;
}
