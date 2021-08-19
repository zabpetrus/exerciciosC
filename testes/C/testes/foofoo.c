#include <stdio.h>
#include <stdlib.h>

typedef struct mao{
	int num;
	struct mao *next;
	struct mao *prev;
} Mao;

void exibir( Mao* tse , int tam)
{
	int i;
	for(i= 0; i < tam; i++)
	{
		printf("[%p]****** [ %d ][ %p ]*******[%p]\n", tse->prev, tse->num, tse, tse->next);
		tse = tse->next;
	}
}

int insert(Mao** p, Mao** q,  int num ){
	
	Mao *aux, *temp;
	temp = (Mao *) malloc(sizeof(Mao));
	temp->num = num;
	temp->next = NULL;
	temp->prev = NULL;
	
	aux = *p;	
	if(aux == NULL){
		aux = temp;
		aux->next = temp;
		return;
	}
	
	
}


int main(void)
{
	int i;
	Mao *atual, *head;
	head = atual = NULL;
	
	
}
