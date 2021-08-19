#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int num;
	struct no *next;
	struct no *prev;
}Tno;

void inicializar( Tno **temp , int n ){
	
	Tno *alf;
	alf = (Tno *) malloc(sizeof(Tno));
	alf->num = n;
	alf->next = NULL;
	alf->prev = NULL;
	*temp = alf;
}

void exibir( Tno *alf ){
	while(alf != NULL){
		printf("[%p]------ %d[%p] -------[%p]\n", alf->prev, alf->num, alf, alf->next);
		alf = alf->next;
	}
	printf("\n");
}

void adicionar( Tno **alf , int i ){

	Tno *z, *aux;
	aux = *alf;
	z = (Tno *) malloc(sizeof(Tno));	
	z->num = i;
	z->prev = aux->prev;
	z->next = aux;
	*alf = z;	
}

void adicionar_fim( Tno **alf , int i ){

	Tno *z, *aux;
	aux = *alf;
	while(aux->next != NULL){
		aux = aux->next;
	}	
	
	z = (Tno *) malloc(sizeof(Tno));	
	z->num = i;
	z->next = aux->next;
	z->prev = aux;
	aux->next = z;		
}

int contarnos( Tno **n ){
	
	int cont = 0;
	Tno *aux = *n;
	while(aux != NULL){
		cont++;
		aux = aux->next;
	}
	
	return cont;
}

void inseririndex( Tno **n, int pos ){
	
	int cont, i, index;
	Tno *aux, *temp, *med, *aux2;
	
	med = aux2 =*n;
	cont = contarnos(n);
	
	if(pos > cont){
		printf("\nEsta posicao nao existe.\n");
	}
	if(pos == cont){
		
		while(aux2->next != NULL){
			aux2 = aux2->next;
		}
		
		temp = (Tno *) calloc(1, sizeof(Tno));
		temp->num = 54;
		temp->next = aux2->next;
		temp->prev = aux2;
		aux2->next = temp;	
		
	}
	else
	{
		if(pos == 0){
		
			temp = (Tno *) calloc(1, sizeof(Tno));
			temp->num = 54;
			temp->prev = med->prev;
			temp->next = med;
			*n = temp;		
		}
		else{
			
			aux = med;
			for(i = 1; aux->next != NULL; i++){		
				if(i == pos){
					temp = (Tno *) calloc(1, sizeof(Tno));
					temp->num = 54;
					temp->prev = aux->prev;
					aux->prev = temp;
					temp->next = aux->next;
					aux->next = temp;			
				}
				aux = aux->next;		
			}		
		}
		
	}	
}

void excluir(Tno **alf){
	
	
	if(alf != NULL){
		
		Tno* temp, *aux;
		aux = *alf;
		temp = aux;	
		aux->next->prev = aux->prev;
		aux = aux->next;	
		*alf= aux;
		free(temp);
		
	}		
}

void excluir_ultimo(Tno **alf){

	Tno *temp, *aux;
	aux = *alf;		
	while(aux->next->next != NULL){
		aux = aux->next;
	}
	aux->next = aux->next->next;
	free(aux->next);	
}

void excluir_no_indice( Tno **alf, int pos ){
	
	int i, cont;
	Tno *aux, *temp,*seg, *aux2;
	aux = *alf;
	cont = contarnos(alf);
		
	if(pos > cont){
		printf("Esta posicao nao existe.");
	}
	if(pos == cont){
		
		aux2 = aux;
		while(aux->next != NULL){
			aux = aux->next;
		}
		
		temp = aux;	
		free(temp);	
	
				
	}
	else{
		
		if(pos == 0){
			
			temp = aux;
      		aux->next->prev = aux->prev;
			aux = aux->next;
      		*alf = aux;									
			free(temp);	
				
		}else
		{				
			for(i = 0; aux != NULL; i++ ){				
								
				seg = aux->next;				
				if(i == pos-1){
					temp = seg;
					aux->next = seg->next;
					
					if(seg->next != NULL){
						seg->next->prev = aux;
					}
						
					free(temp);					
				}else
				{
					aux = aux->next;
				}				
			}
		}
		
	}	
}

void liberar( Tno **alf ){
	
	Tno *temp, *aux;
	aux = *alf;
	
	while(aux != NULL){
		temp = aux;
		aux = aux->next;
		free(temp);
	}
}

int main(void){
	
	int i;
	Tno *alf;
	inicializar(&alf, 0);
	for(i = 1; i < 10; i++){
		adicionar(&alf, i);		
	}
	exibir(alf);
	excluir_ultimo(&alf);
	exibir(alf);
	excluir(&alf);
	exibir(alf);
	inseririndex(&alf, 2);
	exibir(alf);
	excluir_no_indice(&alf, 9);
	exibir(alf);
	liberar(&alf);
	
	return 0;
}
