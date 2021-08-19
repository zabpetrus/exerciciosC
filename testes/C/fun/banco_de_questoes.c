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

void exibirquestoesemarquivo( Nquestions *n, int tam ){
	int i, j;
	FILE *fp;
	char nome[20];
	printf("Digite o nome do arquivo: ");
	fflush(stdin);	
	fscanf(stdin, " %[^\n]%*c", nome);	
	
	fp = fopen(nome, "w");
	if(!fp){
		printf("\nErro de abertura do arquivo.");
		exit(1);
	}
	
	fprintf(fp, "%d\n", tam);
	
	for(i = 0; i < tam; i++){
		fprintf(fp, "%d\n", n[i].cod);
		fprintf(fp, "%s\n", n[i].enunciado);
		for(j = 0; j < 5; j++){
			fprintf(fp, "%s\n", n[i].opcoes[j]);
		}
		fprintf(fp, "%c\n", n[i].gabarito);	
	}
	fprintf(fp, "\n");
	printf("Arquivo salvo com sucesso!");
	fclose(fp);
}

void criarquestoes( Nquestions **n, int index ){
	
	int i, j;
	Nquestions *aux = *n;
	printf("Entre com o numero da questao: ");
	
	fflush(stdin);
	scanf("%d", &aux[index].cod);
	printf("Entre com o enunciado da questao: ");
	
	fflush(stdin);	
	fscanf(stdin, " %[^\n]%*c", aux[index].enunciado);	
	
	printf("\nEntre com as opcoes: \n");
	for(i = 0; i < 5; i++){
		fflush(stdin);
		printf("\nOpcao %c: ", 97 + i);
		fscanf(stdin, " %[^\n]%*c", aux[index].opcoes[i]);
		
	}
	printf("Entre com o gabarito: ");
	fflush(stdin);
	scanf(" %c", &aux[index].gabarito);
	
}


int main(void){
	
	Nquestions *questoes;
	int i, n;
	printf("Entre com o numero de questões: ");
	scanf("%d", &n);
	
	questoes = (Nquestions *) calloc(n, sizeof(Nquestions));
	for(i = 0; i < n; i++){
		criarquestoes(&questoes, i);
	}
	
	exibirquestoes(questoes, n);
	exibirquestoesemarquivo(questoes, n);
	free(questoes);
	return 0;
}
