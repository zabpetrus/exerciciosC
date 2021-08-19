#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dupla{
	char p[2];
	double c;	
}Dupla;

typedef struct tripla{
	char p1[2];
	char p2[2];
	double q;
}Tripla;

int extract(char p[], Dupla* lista, int tam){
	int i;
	
	for(i = 0; i < tam; i++)
	{
		if(strcmp(p, lista[i].p) == 0)
		{
			return (lista[i].c);
		}
	}
	
	
}

int indupla( char val[], Dupla *lista, int tam )
{
	int i;
	for(i = 0; i < tam; i++)
	{
		if(strcmp(val, lista[i].p) == 0)
		{
			return 1;
		}
	}
	return 0;
}

void calcular(Dupla* resultado, Dupla* simples, Tripla* compostas, int duplatam, int triplatam){
	
	int i, j, res = 0, num;
	//conta
	
	for(i = 0; i < triplatam; i++)
	{
		if(indupla(compostas[i].p1, simples, duplatam) == 0) //se não esta na lista
		{
			res++;
		}
	}
	resultado = (Dupla *) malloc(res * sizeof(Dupla));
	for(i = 0; i < res; i++)
	{
		resultado[i].c = 0.0;
	}
	
	j = 0;
	for(i = 0; i < triplatam; i++)
	{
		if((indupla(compostas[i].p1, simples, duplatam) == 0) && ( indupla(compostas[i].p2, resultado, res) == 0 )) //se não esta na lista p1 e p2
		{
			strcpy (resultado[i].p, compostas[i].p1 ) ;
			num =  extract(compostas[i].p2, simples, duplatam);
			resultado[i].c = resultado[i].c + num;
		}
		else
		{
			if(indupla(compostas[i].p2, resultado, res) == 0)
			{
				num = extract(compostas[i].p2, resultado, res);
				resultado[i].c = resultado[i].c + num;
			}
		}
		
	}
	
	//correr o arquivo e ver todas as peças possiveis
	// a peca composta nao estiver na lista, sera adicionada
	for(i = 0; i < res; i++)
	{
		printf("%s  %.0f\n", resultado[i].p, resultado[i].c);
	}
}

void organizar( Dupla* simples, Tripla* composta, int duplatam, int triplatam )
{
	int i;
	char c = composta[0].p2[0];
	Tripla *temp = (Tripla *) malloc(sizeof(Tripla));
	
	
	for(i = 0; i < triplatam - 1; )
	{
		if(composta[i].p2[0] > composta[i+1].p2[0] )
		{
			*temp = composta[i];
			composta[i] = composta[i+1];
			composta[i+1] = *temp;
			i = 0;
		}
		else
		{
			i++;
		}
	}	
}


void inicializar( Dupla** simples, Tripla** compostas, int *duplatam, int *triplatam)
{
	int i, n, cont;
	Dupla *s;
	Tripla c[100], *u;
	FILE *fp;
	fp = fopen("3035.txt","r");
	fscanf(fp,"%d",&n);
	
	s = (Dupla *) malloc(n * sizeof(Dupla));
	for(i = 0; i < n; i++)
	{
		fscanf(fp,"%s  %lf", s[i].p, &s[i].c);
	}
	
	cont = 0;
	while(!feof(fp))
	{
		fscanf(fp, "%s %s %lf", c[cont].p1, c[cont].p2, &c[cont].q);
		cont++;
	}
	
	for(i = 0; i < cont; i++ )
	{
		printf("%s  %s  %lf\n", c[i].p1, c[i].p2, c[i].q);
	}
	
	*simples = s;
	*compostas = c;
	
	*duplatam = n;
	*triplatam = cont;
}

int main()
{
	int duplatam, triplatam;
	Dupla *simples, *complexa;
	Tripla *compostas;
	
	inicializar(&simples, &compostas, &duplatam, &triplatam);
	organizar( simples, compostas, duplatam, triplatam );
	calcular(complexa, simples, compostas, duplatam, triplatam);
	
	return 0;
}
