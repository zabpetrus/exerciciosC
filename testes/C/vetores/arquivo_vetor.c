#include <stdio.h>
#include <stdlib.h>
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
	fgets(foo.nomedoarquivo, 128, stdin);
	
	
	foo.fp = fopen(foo.nomedoarquivo, "w");
	if(!foo.fp){
				
		printf("O arquivo nao existe. Deseja cria-lo agora? (y/n)");
		scanf("%c", &opt);
		
		if(opt == 'y' && opt == 'Y'){
			sp = fopen(foo.nomedoarquivo, "w+");
			if(!sp){
				printf("Erro de criacao do arquivo.");
				exit(2);
			}
			
			fclose(sp);		
		}				
	}
	
	printf("Entre com o numero de elementos do vetor: ");
	scanf("%d",&foo.alpha.tam);
	
	srand(time(NULL));
	foo.alpha.vetor = (int *) malloc(foo.alpha.tam * sizeof(int));
	for(i = 0; i < foo.alpha.tam; i++){
		foo.alpha.vetor[i] = rand() % 100;		
	}
	
	printf("\nOs numeros: \n");
	
	fprintf(foo.fp, "%d \n",foo.alpha.tam );
	for(i = 0; i < foo.alpha.tam; i++){
		fprintf(foo.fp, "%d ",foo.alpha.vetor[i] );
		printf("%d ",foo.alpha.vetor[i] );
	}
	
	printf("\nForam gravados no arquivo com sucesso.");
	
	fclose(foo.fp);
	return 0;		
}
