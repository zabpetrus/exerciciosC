#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct no{	
	int index;
	int num;
	struct no *next;	
} Tno;

void inicializarLista( Tno **p , int index){
	
	Tno *temp;
	temp = (Tno *) calloc(1, sizeof(Tno));
	temp->index = index;
	temp->num = rand()%100;
	temp->next = NULL;
	*p = temp;
}

void exibirLista( Tno *p ){
	
	if(p == NULL){
		printf("\nLista Vazia");
		return;
	}
		
	while(p != NULL){
		
		printf("[%d][%d] %p--------%p\n", p->index, p->num, p, p->next);
		p = p->next;		
	}
	printf("\n\n");
}

void inserirnocomeco(Tno **p , int index)
{
	Tno *aux, *temp;
	temp = *p;
	if(temp == NULL){
		
		printf("Lista vazia\n");		
		return;
	}	
	
	aux = (Tno *) calloc(1, sizeof(Tno));
	aux->index = index;
	aux->num = rand()%100;
	aux->next = *p;
	*p = aux;
}

void inserirnoindice( Tno **p, int index, int pos ){
	
	int i = 1;
	Tno *aux, *temp, *temp2, *aux2;
	
	aux2 = *p;
	if(aux == NULL){		
	
		printf("Lista vazia\n");
		return;
	}
	else{
		
		aux = (Tno *) calloc(1, sizeof(Tno));
		aux->index = index;
		aux->num = rand()%100;
		
		temp = *p;
		while(temp != NULL){
			
			if(i == pos){
				
				temp2 = temp->next;
				temp->next = aux;
				aux->next = temp2;			
			}		
			temp = temp->next;
			i++;
		}
				
	}
	
}

void excluirnofinal( Tno **p ){
	
	Tno *aux, *temp;
	aux = *p;
	while(aux->next->next != NULL){
		aux = aux->next;	
	}
	
	temp = aux->next;	
  	aux->next = aux->next->next;
	free(temp);	
}

void excluirnocomeco( Tno **p ){
	
	Tno *aux, *temp;
	temp = *p;
	aux = (*p)->next;
	free(temp);
	*p = aux;
}

void excluirporindice( Tno **p, int indice ){
	
	int hasnumber = 0;
	Tno *aux, *aux2, *temp;
	aux = aux2 = *p;
	if(aux == NULL){
		printf("Lista vazia");
		return;
	}	
	
	while(aux != NULL){
		
		if(aux->index == indice){
			hasnumber += 1;			
		}		
		aux = aux->next;
	}

  	
	
	if(hasnumber > 0){
		
		aux = aux2;
		
	    while(aux2->next != NULL){
	    	
	      //if(indice == aux2->next->index){
	        //temp = aux2->next;
	        //aux2->next = aux2->next->next;
	        //free(temp);
	      //}
	      
	       if(indice == aux2->index){
	        temp = aux2;
	        aux2 = aux2->next;
	        free(temp);
	      }
	      		   
		   aux2 = aux2->next;	      
	    }   
	    
	    *p  = aux;
    
	}
	else{
		printf("\nIndice nao encontrado.");
	}
	return;	
}

void liberarLista( Tno *p ){
	
	Tno *aux;
	while(p != NULL){
		aux = p;
		p = p->next;
		free(aux);		
	}
	printf("\nLiberacao feita com sucesso!\n");
	p = NULL;
	return;
}

int main(void){
	
	int i;
	Tno *p;
	inicializarLista(&p, 0);
	exibirLista(p);
	
	for(i = 1; i < 10; i++){
		inserirnocomeco(&p, i);
	}
	exibirLista(p);
	inserirnoindice(&p, 14, 5);
	exibirLista(p);
	excluirnofinal(&p);
	exibirLista(p);
	excluirnocomeco(&p);
	exibirLista(p);
	excluirporindice(&p, 5);
	exibirLista(p);
	liberarLista(p);
	
	return 0;
}
