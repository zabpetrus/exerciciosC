#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int num;
	struct no *next;
}Tno;

void exibirnext( Tno *aux ){
	
	if(aux!= NULL){
			printf("%d - ", aux->num);
			exibirnext(aux->next );
	}
}

void criarnofinal( Tno *p , int i){
	Tno *temp;
	while(p->next != NULL){
		p = p->next;
	}
	temp = (Tno *) malloc(sizeof(Tno));
	temp->num = i;	
	temp->next = p->next;
	p->next = temp;
	p = temp;	
}


void criarnocomeco( Tno **aux , int i){
	Tno *temp, *p;
	p = *aux;	
	temp = (Tno *) malloc(sizeof(Tno));
	temp->num = i;	
	temp->next = p;
	*aux = temp;
}

int criarviaindice( Tno *aux, int index, int num ){
	
	int i = 1;
	Tno *p;
	
	while(aux != NULL){
		
		if(index == i){
			p = (Tno *) malloc(sizeof(Tno));
			p->num = num;
			p->next = aux->next->next;
			aux->next = p -> next;
			
		}
		
		aux = aux->next;
		
	}
}



int main(void){
	int i;
	Tno *head;
	head->num = 0;
	head->next = NULL;
	
	for(i = 1; i < 6; i++){
		//criarnofinal(head, i); //ok
		// criarnocomeco(&head,i); //ok
	}
	
	exibirnext(head);
	return 0;
}


