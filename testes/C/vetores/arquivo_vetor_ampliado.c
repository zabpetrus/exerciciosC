#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void geraVetores(int index, int q, int n, int a, int vetor[]);
void mostraVetores(int *vetor, int n);
void gravaVetores(char *nomearquivo, int* vetor, int q, int n, int a);
void gravaTag(char *nomearquivo, int* vetor, int n, int a, int q);


int main(void){
	
	int i, n, a, q, *vetor;
	char nome[30];
	
	printf("Entre com o nome do arquivo: ");
	fgets(nome, 128, stdin);
	printf("Entre com o numero de listas, numero de elementos e a amplitude: ");
	scanf("%d  %d  %d", &q, &n, &a);
	
	vetor = (int *) calloc(n, sizeof(int));
	gravaTag(nome, vetor, n, a, q);
	
	for(i = 0; i < q; i++){
		geraVetores(i, q, n, a, vetor);
		mostraVetores(vetor, n);
		gravaVetores(nome, vetor, q, n, a);		
	}

	free(vetor);
	return 0;	
}

void geraVetores(int index, int q, int n, int a, int vetor[]){
	int i;
	for(i = 0; i < n; i++){
		vetor[i] = (rand() + index )% a;
	}
	
}
void mostraVetores(int *vetor, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
}


void gravaTag(char *nomearquivo, int* vetor, int n, int a, int q){
	int i;
	FILE *fp;
	fp = fopen(nomearquivo, "w+");
	if(!fp){
		printf("Erro de abertura do arquivo.");
		exit(2);		
	}
	
	fprintf(fp, "%d  %d  %d\n",a, n, q);		
	fclose(fp);
}


void gravaVetores(char *nomearquivo, int *vetor, int q, int n, int a){
	int i;
	FILE *fp;
	fp = fopen(nomearquivo, "aw");
	if(!fp){
		printf("Erro de abertura do arquivo.");
		exit(1);		
	}

	for(i = 0; i < n; i++){
		fprintf(fp,"%d ", vetor[i]);
	}
	
	fprintf(fp,"\n");
	fclose(fp);
}

