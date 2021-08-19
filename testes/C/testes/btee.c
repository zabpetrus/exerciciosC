#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct No{
	int numero;
	struct No *esquerda;
	struct No *direita;	
} No;

void iniTree( No **root ){
	*root = NULL;
}

void inicializa( No **root )
{
    No *aux;
    srand(time(NULL));
    aux = (No *) malloc( sizeof( No ));
	aux->numero = rand()%10;
	aux->direita = NULL;
	aux->esquerda = NULL;
	*root = aux;
}

void addFolha( No *root ){
		
	No *aux, *temp;
	srand(time(NULL));
	temp = root;
	while(temp->direita != NULL){
		temp = temp->direita;
	}
	
	aux = (No *) malloc( sizeof( No ));
	aux->numero = rand()%10;
	aux->direita = temp->direita;
	aux->esquerda = temp;
	temp->direita = aux;	
}


void addNoph( No *root )
{
	No *aux, *temp;
	temp = root;
	
	if( root->esquerda == NULL ){
		
		aux = (No *) malloc( sizeof( No ));
		aux->numero = rand()%10;
		temp->direita = aux;
		temp->esquerda = aux;
		aux->direita = temp;
		aux->esquerda = temp;	
	}	
	else
	{
		aux = (No *) malloc( sizeof( No ));
		aux->numero = rand()%10;
		aux->direita = temp->direita;
		aux->esquerda = temp->esquerda;
		temp->direita = aux;
		temp->esquerda = aux; 
		
	}
}

void exibeDireita( No *right )
{
    printf("\n");
	while(right != NULL)
	{
		printf("[%p] --- [%d][%p] --- [%p]\n", right->esquerda, right->numero, right,  right->direita);
		right = right->direita;
	}
}


void exibeEsquerda( No *start )
{
    printf("\n");
    No *left = start;
	while(left->esquerda != start)
	{
		printf("[%p] --- [%d][%p] --- [%p]\n", left->esquerda, left->numero, left,  left->direita);
		left = left->esquerda;
	}
}

void preenche( No *root ){
		
	int i;
	for(i = 0; i < 6; i++){
		
		addFolha(root);
		root = root->direita;		
	}
}

void preenchecircular( No *root ){
		
	int i;
	for(i = 0; i < 6; i++){
		
		addNoph(root);
		root = root->direita;		
	}
}

int main(void)
{
	No *root;
	iniTree(&root);
	inicializa(&root);
	preenchecircular(root);	
	exibeEsquerda(root);
	
	return 0;
}


