#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Construi rum programa para ler um arquivo de dados cujo nome é dado
pelo usuario. Este arquivo deve conter q vetores armazenados conforme nosso
modelo de arquivo. Em seguida:
a) Apresente os valores na tela
b) Apresente media dos valores armazenados
c) Apresente a média dos valores armazenados em todos os vetores
d) Apresente qual o vetor com maior media
e) Apresente qual o veotr com menor media
f) Apresente quantos vetores possuem média superior e inferior a média total.
*/



int main(void){
	
	int *vet;
	int q, a, i, j, tam;
	char nome[30];
	FILE *fp;
	
	printf("Entre com o nome do arquivo: ");
	fscanf(stdin, "%s", nome);
	
	fp = fopen(nome, "w+");
	if(!fp){
		printf("Erro de abertura do arquivo. A execucao sera encerrada.");
		exit(1);
	}
	
	printf("Entre com o numero de vetores: ");
	fscanf(stdin, "%d", &q);
	
	printf("Entre com a amplitude dos numeros: ");
	fscanf(stdin, "%d", &a);
	
	srand(time(NULL));
	
	fprintf(fp, "%d\n", q);
	for(i = 0; i < q; i++){
		tam = (rand() % 10) + 3;		
		vet = (int *) calloc(tam, sizeof(int));		
		for(j = 0; j < tam; j++){
			vet[j] = rand() % a;
			fprintf(fp, "%d ", vet[j]);		
		}
		fprintf(fp, "\n");	
		free(vet);
	}

	
	printf("\nArquivo gerado com sucesso!\n");
	fclose(fp);	
	return 0;
}
