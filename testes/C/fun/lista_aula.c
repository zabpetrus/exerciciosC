#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	
	int num;
	struct no *next;
}Tno;

//Construir uma funcao para

//1. Apresentar os elementos da lista
//2. Inserir no inicio da lista
//3. Remover no final
//4. Remover no inicio
//5. Buscar um elemento e retornar um ponteiro para seu no


//1. Apresentar os elementos da lista
void exibir_lista( Tno *p ){
	 	
	while(p != NULL){		
		printf("[%d] ------- [%p]\n", p->num, p->next);
		p = p->next;
	}
}

//2. Inserir no inicio da lista
Tno* insere_lse_comeco(Tno *p , int num){
	
	Tno *aux;
	aux = (Tno *) calloc(1, sizeof(Tno));
	aux->num = num;
	aux->next = NULL;
	
	if(p == NULL){
		p = aux;
	}
	else{
		aux->next = p;
		p = aux;
	}
		
	return p;
}

//0. Inserir no final da lista
Tno* insere_lse_final( Tno *p , int num){
	
	Tno *aux, *aux2;
	aux = (Tno *) calloc(1, sizeof(Tno));
	aux->num = num;
	aux->next = NULL;
	
	if(p == NULL){
		p = aux;
	}
	
	else{
		aux2 = p;
		while(aux2->next != NULL){
			aux2 = aux2->next;
		}
		aux2->next = aux;		
	}
	
	return p;
}

//0. liberar lista
void liberar_lista( Tno *p ){
	
	Tno *aux;
	while(p != NULL){
		aux = p;
		p = p->next;
		free(aux);
	}
}

//3. Remover no final
Tno* remover_final( Tno* p ){
	
	Tno *aux, *temp;	
	if(p == NULL){
		return p;
	}
	else
	{
		aux = p;
		while(aux->next != NULL){
			aux = aux->next;
		}
		temp = aux;
		aux = aux->next;
		free(temp);	
		p = aux;
	}
	
	return p;
}

//4. Remover no inicio
Tno* remover_comeco( Tno* p ){
	
	Tno *aux, *aux2, *temp;	
	if(p == NULL){
		return p;
	}
	else
	{
		aux2 = p;
		aux = p->next;
		free(aux2);
		p = aux;		
	}
	
	return p;
}

//5. Buscar um elemento e retornar um ponteiro para seu no
Tno* buscar_elemento( Tno* p, int n ){
	
	Tno *aux, *resp;
	aux = p;
	resp = NULL;
			
	
	if(p == NULL){
		return p;
	}
	
	while(aux != NULL){
		if(aux->num == n){
			
			resp = aux;
			return resp;
		}
		aux = aux->next;	
	}
	
	return resp;	
}



int main(void){
	
	int i, num, tam;
	Tno *p, *aux, *temp, *src;
	p = temp = NULL;
	tam = 10;
	
	
	printf("\nInserido no final: \n");
	for(i = 0; i < tam; i++){		
		aux = insere_lse_final( temp, i );	
    	temp = aux;	
	}		
	exibir_lista(temp);
	liberar_lista(temp);
	temp = NULL;
	
	printf("\nInserido no comeco: \n");
	for(i = 0; i < tam; i++){		
		aux = insere_lse_comeco( temp, i );	
    	temp = aux;	
	}		
	exibir_lista(temp);
	
	printf("\nExcluir no final: \n");	
	aux = remover_final(temp);
	exibir_lista(aux);
	
	printf("\nExcluir no comeco: \n");	
	aux = remover_comeco(temp);
	exibir_lista(aux);
	
	printf("\nBuscar um elemento: \n");
	src = buscar_elemento(aux, 2);
	if(src == NULL){
		printf("\nElemento nao encontrado.\n");
	}else{
		printf("\nElemento %d encontrado no endereco %p.\n", src->num, src);
	}
	
	liberar_lista(temp);	
	return 0;
	
}

