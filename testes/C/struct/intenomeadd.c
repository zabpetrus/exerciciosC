#include <stdio.h>

typedef struct f{
	int cod;
	char nome[23];	
}Foo;

int main(void){
	
	int i;
	Foo ab[10];
	for(i = 0; i < 10; i++){
		ab[i].cod = rand() % 100;		
		printf("\nEntre com o %d%c nome: ", i+1, 167);
		fgets(ab[i].nome, 10, stdin);
		fflush(stdin);	
	}
	
	for(i = 0; i < 10; i++){
		printf("COD %d = %s\n", ab[i].cod, ab[i].nome);
	}
	
	return 0;
}
