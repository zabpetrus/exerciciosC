#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct vetor{
	int *vetor;
	int tam;
}Vector;

typedef struct data{
	FILE *fp;
	char nomedoarquivo[30];
	Vector alpha;
}TData;


int main(void){
	
	int i;
	FILE *sp;
	char opt;
	TData foo;
	printf("Entre com o nome do arquivo: ");
	fscanf(stdin, "%s", foo.nomedoarquivo);
	
			
	foo.fp = fopen(foo.nomedoarquivo, "r");
	if(!foo.fp){
				
		printf("Erro de leitura do arquivo.");
		exit(1);	
	}
	
	printf("Numero de elementos do vetor: ");
	fscanf(foo.fp, "%d ", &foo.alpha.tam);
	printf("%d \n", foo.alpha.tam);
	
	foo.alpha.vetor = (int *) calloc( foo.alpha.tam , sizeof(int));
	for(i = 0; i < foo.alpha.tam; i++){
		fscanf(foo.fp, "%d ", &foo.alpha.vetor[i]);
	}
	
	for(i = 0; i < foo.alpha.tam; i++){
		printf("%d ",  foo.alpha.vetor[i]);
	}
	
	printf("\nForam lidos do arquivo com sucesso.");
	
	fclose(foo.fp);
	return 0;		
}
