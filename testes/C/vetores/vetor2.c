#include <stdio.h>
#include <time.h>

//ERRRADOOOOOOOOOO

void mostraVetor(int *vetor, int n, int a){
	
	int i;	
	printf("N: %d\nA: %d\n", n, a);
	
	for(i = 0; i < n; i++){
		printf("%d ", vetor[i]);
	}
}

void learquivo( char *nomedoarquivo, int *vetor, int *n, int *a){
	
	int i, na, aa;
	FILE *fp;
	fp = fopen(nomedoarquivo, "r");
	fscanf(fp, "%d  %d\n", &na, &aa);
	for(i = 0; i < aa; i++){
		fscanf(fp, "%d ", &vetor[i]);
	}
	*n = aa;
	*a = na;
}

int main(void){
	
	int *vetor, n, a;
	char nomedoarquivo[30];
	printf("Entre com o nome do arquivo: ");
	gets(nomedoarquivo);
	learquivo(nomedoarquivo, vetor, &n, &a);
	mostraVetor(vetor, n, a);
	return 0;
}
