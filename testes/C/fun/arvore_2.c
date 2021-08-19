#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct leaf{
	int num;
	struct leaf *next;
	struct leaf *prev;	
}Tree;

void exibirFolhagem( Tree *p ){
	
	Tree *a, *b;
	a = b = p;
	
	printf("\nNEXT: \n");
	while(a != NULL){
		printf("[%p]----- [%p][%d] ----- [%p]\n",a->prev, a, a->num, a->next);
		a = a->next;		
	}
	
	printf("\nPREV: \n");
	while(b != NULL){
		printf("[%p]----- [%p][%d] ----- [%p]\n",b->prev, b, b->num, b->next);
		b = b->prev;		
	}
	return;	
}

void inicializararvore( Tree **p , int n ){
	
	Tree *aux;
	aux = (Tree *) calloc(1, sizeof(Tree));
	aux->num = n;
	aux->next = NULL;
	aux->prev = NULL;
	*p = aux;
}


Tree *folhar( int num ){
	
	Tree *aux;
	aux = (Tree *) calloc(1, sizeof(Tree));
	aux->num = num;
	aux->next = NULL;
	aux->prev = NULL;
	return aux;
}

int main(void){
	
	int i, n, fn, aux;
	Tree *p;
	fn = rand()%100;
	inicializararvore(&p, fn);
		
	for(i = 0; i < 50; i++){
		
		n = rand()%100;
		if(n >= fn){
			p->next = folhar(n);
		}
		else{
			p->prev = folhar(n);
		}		
		
	}
	
	exibirFolhagem(p);
	return 0;
}
