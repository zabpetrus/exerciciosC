#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


typedef struct question{
	int cod;
	char enunciado[400];
	char opcoes[5][20]; //a, b, c, d, e
	char gabarito;	
}Nquestions;


void exibirmatriz(char opcoes[5][20]){
	
	int i, j;
	for(i = 0; i < 5; i++){
		printf("%c) %s\n", 97+i, opcoes[i]);
	}
}

void exibirquestoes( Nquestions *n, int tam ){
	int i;
	for(i = 0; i < tam; i++){
		printf("COD: %d\n", n[i].cod);
		printf("ENUNCIADO: %s\n", n[i].enunciado);
		printf("OPCOES: \n");
		exibirmatriz(n[i].opcoes);
		printf("GABARITO: %c\n", n[i].gabarito);	
	}
}

void salvaremarquivo( Nquestions *n, char *nome, int i ){
	int j;
	FILE *fp;
	fp = fopen(nome, "aw");
	if(!fp){
		printf("\nErro de abertura do arquivo.");
		exit(1);
	}	
	
	fprintf(fp, "%d\n", n[i].cod);
	fprintf(fp, "%s\n", n[i].enunciado);
	for(j = 0; j < 5; j++){
		fprintf(fp, "%s\n", n[i].opcoes[j]);
	}
	fprintf(fp, "%c\n", n[i].gabarito);	
	
	fprintf(fp, "\n");
	printf("\nRegistro salvo!\n");	
}

void criarquestao( Nquestions **n, int index ){
	
	int i, j;
	Nquestions *aux = *n;
	
	printf("Entre com o numero da questao: ");
	scanf("%d", &aux[index].cod);
	
	printf("Entre com o enunciado da questao: ");		
	fscanf(stdin, " %[^\n]%*c", aux[index].enunciado);	
	
	printf("\nEntre com as opcoes: \n");
	for(i = 0; i < 5; i++){
		printf("\nOpcao %c: ", 97 + i);
		fscanf(stdin, " %[^\n]%*c", aux[index].opcoes[i]);
		
	}
	printf("Entre com o gabarito: ");
	fflush(stdin);
	scanf(" %c", &aux[index].gabarito);
	fflush(stdin);
}


int main(void){
	
	Nquestions *questoes;
	int i, n;
	FILE *fp;
	char nome[20], opt, tmp;
	printf("Digite o nome do arquivo: ");
	fflush(stdin);	
	fscanf(stdin, " %[^\n]%*c", nome);
	fp = fopen(nome, "w+");	
	if(!fp){
		printf("\nErro de abertura do arquivo.");
		exit(1);
	}
	
	printf("Entre com o numero de questões: ");
	scanf("%d", &n);
	
	questoes = (Nquestions *) calloc(n, sizeof(Nquestions));
	
	fprintf(fp, "%d\n", n);
	

	
	i = 1;
	do{
		fflush(stdin);
		criarquestao(&questoes, i);
		salvaremarquivo(questoes, nome, i);
		
		printf("Deseja continuar? (y / n): ");
		
		fflush(stdin);
		scanf(" %c", &opt);	
				
		if((opt =='y') && (opt == 'Y')){
					
			i++;
		}			
	}
	while( (i <= n) && ((opt != 'n') && (opt != 'N'))); 
	
	exibirquestoes(questoes, n);
	
	rewind(fp);
	fprintf(fp, "%d\n", i+1);
	
	printf("\nArquivo salvo com sucesso!");
	
	free(questoes);
	fclose(fp);
	return 0;
}
