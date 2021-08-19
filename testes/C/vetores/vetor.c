#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

//ERRRADDDOOOOOOOOOOOOOOO

void geraVetor(int n, int a, int *vetor);
void mostraVetor(int *vetor, int n);
void gravaVetor(char *nomearquivo, int* vetor, int n, int a);

int main(void){
	
	int n, a, *vetor;
	char nome[30];
	printf("Entre com o nome do arquivo: ");
	fgets(nome, 128, stdin);
	printf("Entre com o numero de elementos:");
	scanf("%d", &n);
	printf("Entre com a amplitude: ");
	scanf("%d", &a);
	
	vetor = (int *) malloc(n * sizeof(int));
	
	geraVetor(n, a, vetor);
	mostraVetor(vetor, n);
	gravaVetor(nome, vetor, n, a);
	return 0;	
}

void geraVetor(int n, int a, int *vetor){
	int i;	
	srand(time(NULL));
		
	for(i = 0; i < n; i++){
		vetor[i] = rand() % a;
	}
		
}


void mostraVetor(int *vetor, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ", vetor[i]);
	}
}


void gravaVetor(char *nomearquivo, int *vetor, int n, int a){
	int i;
	FILE *fp;
	fp = fopen(nomearquivo, "w+");
	if(!fp){
		printf("Erro de abertura do arquivo.");
		exit(1);		
	}
	
	fprintf(fp, "%d  %d\n",a,  n);
	for(i = 0; i < n; i++){
		fprintf(fp,"%d ", vetor[i]);
	}
	
	fclose(fp);
}
