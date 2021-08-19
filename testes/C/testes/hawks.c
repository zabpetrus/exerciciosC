#include <stdio.h>
#include <stdlib.h>

typedef struct foo{
	int num;
	struct foo *next;
	struct foo *prev;
} Foo;

void exibir( Foo *p )
{
	Foo *cpy = p;
	printf("\nSentido next: \n");
	while(p != NULL)
	{
		printf("[%p]------ %d[%p]-------[%p]\n", p->prev, p->num, p, p->next );
		p = p->next;
	}
	printf("\nSentido prev: \n");
	
	while(cpy != NULL)
	{
		printf("[%p]------ %d[%p]-------[%p]\n", cpy->prev, cpy->num, cpy, cpy->next );
		cpy = cpy->prev;
	}
	
}

void inicializar( Foo** x  )
{
	int num;
	Foo* cousin;
	printf("Elemento n%c %d: ", 167, 1);
	cousin = (Foo *) malloc(sizeof(Foo));
	scanf("%d", &cousin->num);
	cousin->next = NULL;
	cousin->prev = NULL;
	*x = cousin;
}

void adicionarno( Foo* cousin, int num )
{
	
	Foo* temp;
	Foo* aux = cousin;

	temp = (Foo *) malloc(sizeof(Foo));
	if(num > cousin->num)
	{
		temp->num = num;
		temp->next = aux->next;
		temp->prev = aux;
		aux->next = temp;		
	}
	else
	{
		temp->num = num;
		temp->prev = aux->prev;
		temp->next = aux;
		aux->prev = temp;
		temp = aux;		
	}	
}

int main(void)
{
	
	int tam, i, n;
	Foo *cousin;
	
	printf("Criando uma rede \n\n");
	printf("Entre com o tamanho: ");
	scanf("%d", &tam);
	inicializar(&cousin);
	exibir(cousin);
	for(i = 0; i < tam; i++)
	{
		printf("Elemento n%c %d: ", 167, i+2);
		scanf("%d", &n);
		adicionarno(cousin, n);
		exibir(cousin);
	}	
	return 0;
}
