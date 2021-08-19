#include <stdio.h>
#include <malloc.h>

typedef struct no{
	
	int num;
	struct no *next;
	struct no *prev;
	
}Tno;

Tno* novono( int num ){
	
	Tno *aux;
	aux = (Tno *) calloc(1, sizeof(Tno));
	aux->num = num;
	aux->next = NULL;
	aux->prev = NULL;
	return aux;
}

void mostrar( Tno *p ){
	
	Tno *a, *b;
	a = b = p;
	
	printf("\nRoot to next: \n\n");
	while(a != NULL){
		printf("[%p]---------[%p][%d]----------[%p]\n", a->prev, a, a->num, a->next);
		a = a->next;
	}
	
	printf("\nRoot to prev: \n\n");
	while(b != NULL){
		printf("[%p]---------[%p][%d]----------[%p]\n", b->prev, b, b->num, b->next);
		b = b->prev;
	}
}

int main(void){
	
	Tno *root = novono(1);
	root->next = novono(2);
	root->prev = novono(3);
	
	root->next->next = novono(4);
	root->prev->prev = novono(5);
	mostrar(root);
	
	return 0;	
}
