#include <stdio.h>
#include <stdlib.h>

int tam = 0;

typedef struct cookie{
	int num;
	struct cookie *next;
	struct cookie *prev;
}Cookie;

void addvalue( int **vet, int val )
{
	int *aux;
	*aux = val;
	*vet = aux;
	vet++;
}

void iniciarvetor( int** p, int tam )
{
	int i, *vet;
	vet = (int *) malloc(tam * sizeof(int));
	for(i = 0; i < tam; i++)
	{
		vet[i] = 0;
		
	}
	*p = vet;
}

void exibirvetor( int vet[], int tam )
{
	int i;
	for(i = 0; i < tam; i++)
	{
		printf("%d ", vet[i]);
	}
	printf("\n");
}

void inicializarcookie( Cookie **p, int num )
{
	Cookie *aux;
	aux = (Cookie *) malloc(sizeof(Cookie));
	aux->num = num;
	aux->next = NULL;
	aux->prev = NULL;
	*p = aux;
}

void exibircookie( Cookie *p )
{
	while(p != NULL)
	{
		printf("[%p]......[%p](%d)......[%p]\n", p->prev, p, p->num, p->next );
		p = p->next;
	}
}

int main(void)
{
	Cookie *org;
	int tam, *sequencia;
	printf("Entre com a quantidade de elementos: ");
	scanf("%d", &tam);
	iniciarvetor(&sequencia, tam);
	inicializarcookie(&org, 1000);
	exibircookie(org);	
	exibirvetor(sequencia, tam);
	return 0;
}
