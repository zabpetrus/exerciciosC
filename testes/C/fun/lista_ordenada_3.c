#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define TAM 10

typedef struct no{
	int num;
	int index;
	struct no *next;
}Tno;

void inicializar( Tno **p ){
	
	Tno *aux;
	aux = (Tno *) calloc(1, sizeof(Tno));
	aux->num = 0;
	aux->index = 0;
	aux->next = *p;
	*p = aux;
}

void inserirnofinal( Tno **p , int index, int num){
	
	Tno *aux, *temp;
	aux = (Tno *) calloc(1, sizeof(Tno));
	aux->index = index;
	aux->num = num;
	
	temp = *p;
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	aux->next = temp->next;
	temp->next = aux;	
}

void exibirMegaLista( Tno **aux  ){
	
	int i;
	Tno *temp;	
	for(i = 0; i < TAM; i++){
		printf("Lista %d: \n", i);
		temp = aux[i];
		while(temp != NULL){
			printf("[%02d]) [%02d][%p]-------------[%p]\n", temp->index, temp->num, temp, temp->next);
			temp = temp->next;
		}
		printf("\n");
	}	
}

int ehprimo( int num ){
	
	int i, cont = 0;
	for(i = 2; i <= num; i++){
		if(num % i == 0){
			cont++;			
		}
	}
	
	if(cont==1){
		return 1;
	}
	
	return 0;
}

void esvaziarmemoria(Tno **aux ){
	
	int i;
	Tno **foo, *bar, *temp;
	foo = aux;
	
	for(i = 0; i < TAM; i++ ){
		
		bar = foo[i];
		while(bar != NULL){
			temp = bar;
			bar = bar->next;
			free(temp);			
		}
	}
	
	free(foo);
	return;
}


int main(void){
	
	int i, j, n, temp;
	Tno **source;
	
	source = (Tno **) calloc(TAM, sizeof(Tno));
	for(i = 0; i < TAM; i++){
		source[i] = NULL;		
	}
	
	for(i = 0; i < TAM; i++){		
		inicializar(&source[i]);			
	}
	
	for(i = 0; i <= TAM; i++){
		
		temp = rand()%100;				
			
		if(ehprimo(temp)){
			inserirnofinal(&source[1], i, temp);
		}
		
		if(temp % 2 == 0){
			inserirnofinal(&source[2], i, temp);
		}
		
		if(temp % 3 == 0){
			inserirnofinal(&source[3], i, temp);
		}
		
		if(temp % 4 == 0){
			inserirnofinal(&source[4], i, temp);
		}
		
		if(temp % 5 == 0){
			inserirnofinal(&source[5], i, temp);
		}
		
		if(temp % 6 == 0){
			inserirnofinal(&source[6], i, temp);
		}
		
		if(temp % 7 == 0){
			inserirnofinal(&source[7], i, temp);
		}
		
		if(temp % 8 == 0){
			inserirnofinal(&source[8], i, temp);
		}
		
		if(temp % 9 == 0){
			inserirnofinal(&source[9], i, temp);
		}
		else
		{
			inserirnofinal(&source[0], i, temp);
		}
									
		
	}
	
	exibirMegaLista(source);
	esvaziarmemoria(source);
	return 0;
}
