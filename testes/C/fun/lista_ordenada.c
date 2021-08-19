//https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct no{
	int num;
	int index;
	struct no *next;
}Tno;

Tno *head = NULL;


void exibirno( Tno *no ){
	
	if(no != NULL){
		
		printf("(%d) --- %d[%p]-----[%p]\n", no->index, no->num, no, no->next);
		exibirno(no->next);		
	}	
}

void refreshno( Tno *no ){
	
	Tno *aux;
	while(no->next != NULL){	
		aux = no;
		free(aux);	
		no= no->next;		
	}
}

void trocar( Tno *a, Tno *b ){
	
	int temp, temp2;
	temp = a->num;
	temp2 = a->index;
	
	a->num = b->num;
	a->index = b->index;
	
	b->num = temp;
	b->index = temp2;
}

void ordenarnos( Tno *no ){
	
	int temp;
	Tno *aux, *b, *p;
	
	if(no == NULL){
		return;	
	}
	
	p = no;	
	temp = p->num;	
	while(p->next != NULL){
				
		if(temp < p->next->num){
			temp = p->next->num; 			
			trocar(p, p->next);						
		}		
		p = p->next;						
	}
	
	return;
	
}

int main(void){
	
	int i, temp, temp2;
	Tno *m, *aux;
	m = (Tno *) calloc(1, sizeof(Tno));
	m->num = 26;
	m->index = 0;
	m->next = NULL;	
	
	for(i = 1; i < 6; i++ ){
		
		aux = (Tno *) calloc(1, sizeof(Tno));
		aux->num = rand() % 100;
		aux->index = i;		
		aux->next = m->next;
		m->next = aux;
				
	}
	
	exibirno( m );
	ordenarnos( m );
	exibirno( m );	
	refreshno( m );
	return 0;
}
