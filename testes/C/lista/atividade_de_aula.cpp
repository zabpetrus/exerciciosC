#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//Criar a lista

typedef struct no{
	int num;
	struct no *next;	
}Tno;

void push(Tno** no );
void pop(Tno** no);
void insert( Tno** no );
void erase(Tno** no );
int isEmpty(Tno *no);
int indexOf(Tno *no );
int atPos(Tno *no );
void print(Tno *no );
void menu();

int main(void){
	
	int opt = 0;
	Tno *lista = NULL;
		
	printf("Lista encadeada! Escolha o que quer fazer: (9 pra sair)\n\n");
	printf("1 - Push\n2 - Pop\n3 - Insert\n4 - Erase\n5 - is Empty\n6 - Index Of\n7 - at Post\n8 - Print\n9 - Sair\n\n");
	
	do{			
		scanf("%d", &opt);
		if(opt < 0 || opt > 9){
			printf("Valor nao reconhecido. Tente de novo!\n");			
		}
		else{
			switch(opt){
				case(1):
					printf("Push\n");
					push(&lista);
					print(lista);
					menu();
					break;
				case(2):
					printf("Pop\n");
					pop(&lista);
					print(lista);
					menu();
					break;
				case(3):
					printf("Insert\n");
					menu();
					break;
				case(4):
					printf("Erase\n");
					menu();
					break;
				case(5):
					printf("is Empty\n");
					menu();
					break;
				case(6):
					printf("index OF\n");
					menu();
					break;
				case(7):
					printf("at Pos\n");
					menu();
					break;
				case(8):
					printf("print\n");
					menu();
					break;
								
			}
		}
		
	}while(opt != 9);
	return 0;
}

//Função inserir no começo
void push( Tno** no ){
	
	Tno *aux;	
	aux = (Tno *) malloc(sizeof(Tno));
	printf("Valor: ");
	scanf("%d", &aux->num);
	aux->next = *no;
	*no = aux;
	
}

//Função exibir
void print(Tno *no){
	
	while(no != NULL){
		printf("%d ", no->num);
		no = no->next;
	}
	printf("\n\n");
}

//Função excluir no começo
void pop(Tno** no){
	
	Tno *aux = *no;
	(*no) = (*no)->next;
	free(aux);
	
}


//Função include no final
void insert(Tno** no){
	
	Tno *aux, *temp;
	aux = (*no);
	while(aux->next != NULL){
		aux = aux->next;
	}
	
	temp = (Tno *) malloc(sizeof(Tno));
	printf("Valor: ");
	scanf("%d", &temp->num);
	temp->next = aux->next;
	aux = temp;	
}





void menu(){
	
	fflush(stdin);
	printf("Lista encadeada! Escolha o que quer fazer: (9 pra sair)\n\n");
	printf("1 - Push\n2 - Pop\n3 - Insert\n4 - Erase\n5 - is Empty\n6 - Index Of\n7 - at Post\n8 - Print\n9 - Sair\n\n");
}
