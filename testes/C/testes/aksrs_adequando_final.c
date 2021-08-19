#include <stdio.h>
#include <stdlib.h>

typedef struct tda{	
	int n1;
	char s1;
	int d1;
	char s2;
	int n2;
	char s3;
	int d2;
	int p1;
	int p2;
	int xn;
	int xd;		
} TDA;	
	

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

void calcular(TDA *num, int i)
{
	if(num[i].s2 == '+')
	{
		num[i].p1 = adicao(num[i].n1, num[i].d1, num[i].n2, num[i].d2);
		num[i].p2 = denominador_comum(num[i].d1, num[i].d2);
	}
	else
	{
		if(num[i].s2 == '-')
		{
			num[i].p1 = subtracao(num[i].n1, num[i].d1, num[i].n2, num[i].d2);
			num[i].p2 = denominador_comum(num[i].d1, num[i].d2);
		}
		else
		{
			if(num[i].s2 == '*')
			{
				num[i].p1 = multiplicacao(num[i].n1, num[i].n2);
				num[i].p2 = denominador_comum(num[i].d1, num[i].d2);
			}
			else
			{
				num[i].p1 = divisao(num[i].n1, num[i].d2);
				num[i].p2 = denominador_divisao(num[i].n2, num[i].d1);	
			}
		}
	}	
	
	simplificar(num[i].p1, num[i].p2, &num[i].xn, &num[i].xd);		
}

int main(void)
{
	int i, tam;
	TDA *num;
	fscanf(stdin, "%d", &tam);
	num = (TDA *) malloc( tam * sizeof(TDA));
	
	for(i = 0; i < tam; i++)
	{
		fflush(stdin);
		fscanf(stdin,"%d %c %d %c %d %c %d", &num[i].n1, &num[i].s1, &num[i].d1, &num[i].s2, &num[i].n2, &num[i].s3, &num[i].d2);
		calcular(num, i);		
	}
	
	for(i = 0; i < tam; i++)
	{
		printf("%d/%d = %d/%d\n", num[i].p1, num[i].p2, num[i].xn, num[i].xd);
	}	
	return 0;
}
