//https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct no{
	int num;
	struct no *next;
}Tno;

void exibirno( Tno *no ){
	
	if(no->next != NULL){
		
		printf("%d[%p]-----[%p]\n", no->num, no, no->next);
		exibirno(no->next);		
	}	
}

void refreshno( Tno *no ){
	
	Tno *aux;
	while(no->next != NULL){
		//printf("Fresh %d ", no->num);
		aux = no;
		free(aux);	
		no= no->next;		
	}
}

int main(void){
	
	int i;
	Tno *m, *aux;
	m = (Tno *) calloc(1, sizeof(Tno));
	m->num = 26;
	m->next = NULL;
	
	for(i = 0; i < 5; i++ ){
		aux = (Tno *) calloc(1, sizeof(Tno));
		aux->num = rand() % 100;
		aux->next = m->next;
		m->next = aux;		
	}
	
	exibirno( m );
	refreshno(m);
	return 0;
}
