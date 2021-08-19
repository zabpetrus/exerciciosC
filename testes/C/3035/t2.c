#include <stdio.h>
#include <stdlib.h>

typedef struct dupla{
	int c;
	char p[2];
	struct dupla *next;
}Dupla;


typedef struct trupla{
	char p1[2];
	char p2[2];
	int q;
	struct trupla *next;
} Trupla;

void exibir( Dupla *p )
{
	while(p != NULL)
	{
		printf("%s  %d\n",p->p, p->c);
		p = p->next;
	}
	
	printf("\n");
}

void exibirtrupla( Trupla *p )
{
	while(p != NULL)
	{
		printf("%s %s %d\n", p->p1, p->p2, p->q);
		p = p->next;
	}
	
	printf("\n");
}

void inicializar( Dupla **p , int *size)
{
	int i, tam;
	Dupla *aux, *aux2, *destino;
	Trupla *temp, *poo;
	FILE *fp;
	
	fp = fopen("3035.txt","r");
	fscanf(fp,"%d",&tam);
	aux = (Dupla *) malloc( sizeof(Dupla));
	aux->next = NULL;
	
	for(i = 0; i < tam; i++)
	{
		if(i == 0) {
			fscanf(fp, "%s  %d", &aux->p, &aux->c);
		}			
		else
		{
			aux2 = (Dupla *) malloc( sizeof(Dupla));
			fscanf(fp, "%s  %d", &aux2->p, &aux2->c);
			aux2->next = aux->next;
			aux->next = aux2;
		}		
	}
	
	for(i = 0; !feof(fp); i++ ){
		if(i == 0){
			temp = (Trupla *) malloc(sizeof(Trupla));
			fscanf(fp, "%s %s %d", temp->p1, temp->p2, &temp->q );
			temp->next = NULL;			
		}
		else
		{
			poo = (Trupla *) malloc(sizeof(Trupla));
			fscanf(fp, "%s %s %d", poo->p1, poo->p2, &poo->q );
			poo->next = temp->next;
			temp->next = poo;						
		}		
	}	
	exibirtrupla(temp);
	
	while(temp != NULL)
	{
		
	}
	
	
	*p = aux;	
}

int main(void)
{
	int size;
	Dupla *source;
	inicializar(&source, &size);
	exibir(source);
	return 0;
}
