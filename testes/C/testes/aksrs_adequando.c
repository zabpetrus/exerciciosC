#include <stdio.h>
#include <stdlib.h>

typedef struct tda{
	
	int n1;
	int s1;
	int d1;
	int s2;
	int n2;
	int s3;
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
	
	switch(num[i].s2){
		case 43:
			num[i].p1 = adicao(num[i].n1, num[i].d1, num[i].n2, num[i].d2);
			num[i].p2 = denominador_comum(num[i].d1, num[i].d2);			
			break;
		case 45:
			num[i].p1 = subtracao(num[i].n1, num[i].d1, num[i].n2, num[i].d2);
			num[i].p2 = denominador_comum(num[i].d1, num[i].d2);	
			break;
		case 42:
			num[i].p1 = multiplicacao(num[i].n1, num[i].n2);
			num[i].p2 = denominador_comum(num[i].d1, num[i].d2);	
			break;					
		default:
			num[i].p1 = divisao(num[i].n1, num[i].d2);
			num[i].p2 = denominador_divisao(num[i].n2, num[i].d1);				 
	}
	
	simplificar(num[i].p1, num[i].p2, &num[i].xn, &num[i].xd);		
}

int main(void)
{
	int i, tam;
	TDA *num;
	//FILE *fp;
	//fp = fopen("1022.txt","r");	
//	fscanf(fp, "%d", &tam);
	fscanf(stdin, "%d", &tam);
	num = (TDA *) malloc(tam * sizeof(TDA));
	
	for(i = 0; i < tam; i++)
	{
		fscanf(fp,"%d %c %d %c %d %c %d", &num[i].n1, &num[i].s1, &num[i].d1, &num[i].s2, &num[i].n2, &num[i].s3, &num[i].d2);
	//	fscanf(fp,"%d %c %d %c %d %c %d", &n1, &s1, &d1, &s2, &n2, &s3, &d2);
		calcular(num, i);		
	}
	
	for(i = 0; i < 50; i++)
	{
		printf("%d/%d = %d/%d\n", num[i].p1, num[i].p2, num[i].xn, num[i].xd);
	}
	
	free(num);
	return 0;
}
