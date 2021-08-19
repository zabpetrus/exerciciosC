#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int num;
	struct no *next;	
}Tno;

typedef struct dno{
	int num;
	struct dno *next;
	struct dno *prev;	
}Dno;

void inserir_na_cabeca( Tno **lista, int num );
void inserir_na_cauda(Tno **lista, int num );
void remover_da_cabeca(Tno **lista );
void remover_da_cauda(Tno **lista );
void remover_do_meio(Tno **lista, int pos );
void exibir_lista( Tno *lista );



int main(void){
	
	Tno *lista = NULL;
	inserir_na_cabeca(&lista, 0);
	inserir_na_cabeca(&lista, 1);
	inserir_na_cabeca(&lista, 2);
	exibir_lista(lista);
	inserir_na_cauda(&lista, 3);
	inserir_na_cauda(&lista, 4);
	inserir_na_cauda(&lista, 5);
	exibir_lista(lista);
	remover_do_meio(&lista, 2);
	remover_do_meio(&lista, 7);
	exibir_lista(lista);

	return 0;	
}

void exibir_lista( Tno *lista ){
	
	if(lista != NULL){
		printf("%d ", lista->num);
		exibir_lista(lista->next);
	}
	else{
		printf("\n\n");
	}
}

void inserir_na_cabeca( Tno **lista, int n ){
	
	Tno *temp;
	temp = (Tno *) calloc(1, sizeof(Tno));
	temp->num = n;
	temp->next = *lista;
	*lista = temp;	
}

void inserir_na_cauda(Tno **lista, int num ){
	
	Tno *temp;
	Tno *aux = *lista;
	while(aux->next != NULL){
		aux = aux->next;
	}
	temp = (Tno *) malloc(sizeof(Tno));
	temp->num = num;
	temp->next = aux->next;
	aux->next = temp;
	return;
}

void remover_da_cabeca(Tno **lista ){
	
	Tno *temp = (*lista);	
	(*lista) = (*lista)->next;
	free(temp);
}

void remover_da_cauda( Tno **lista ){
	Tno *aux, *temp;
	aux = *lista;
	while(aux->next->next != NULL){
		aux = aux->next;
	}
	temp = aux->next;
  	aux->next = aux->next->next;
  	free(temp);
}



void remover_do_meio(Tno **lista, int pos ){
	
	int i = 0;
	Tno *aux, *temp;
	aux = *lista;
	
	if(aux == NULL){
		printf("lista vazia");
		return;
	}
	
	if(pos == 0){
		remover_da_cabeca(lista);
		return;
	}
	else{
		
		for(i = 0; aux->next != NULL; i++, aux = aux->next){
			if(i == pos-1){
				
				printf("Elemento de posicao %d (%d) localizado e excluido\n\n", pos, aux->next->num);
				temp = aux->next;
				aux->next = aux->next->next;				
				free(temp);
				return;
			}
		}
		
		if(pos >= i){
			printf("Posicao %d nao encontrada!\n\n", pos);
		}
	
	}
	
}






