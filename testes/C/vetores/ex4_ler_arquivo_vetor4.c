#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Construir um programa para ler um arquivo de dados cujo nome é dado
pelo usuario. Este arquivo deve conter q vetores armazenados conforme nosso
modelo de arquivo. Em seguida:
a) Apresente os valores na tela
b) Apresente media dos valores armazenados
c) Apresente a média dos valores armazenados em todos os vetores
d) Apresente qual o vetor com maior media
e) Apresente qual o vetor com menor media
f) Apresente quantos vetores possuem média superior e inferior a média total.
*/

int mediasuperior( double *vet, double ref , int tam ){
	
	int i, cont = 0;	
	for(i = 0; i < tam; i++){
		if(vet[i] > ref){
			cont++;
		}
	}
	
	return cont;
}


int mediainferior( double *vet, double ref , int tam ){
	
	int i, cont = 0;	
	for(i = 0; i < tam; i++){
		if(vet[i] < ref){
			cont++;
		}
	}
	
	return cont;
}

void exibirmedias( double *vet, int tam ){
	int i, cont = 0;	
	for(i = 0; i < tam; i++){
		printf("MEDIA %d: %.3lf\n", i + 1, vet[i]);
	}
}

double funcmediatotal( double *vet, int tam ){
	int i;	
	double soma = 0;	
	for(i = 0; i < tam; i++){
		soma = soma + vet[i];
	}
	
	return (soma / tam);
}

int main(void){
	
	int **matr, q, a, i, n, offset, soma = 0, nvet, maiorvet, menorvet;
	char nome[30], num[30], *line;
	double media, mediatotal, *nmedia, maiormedia = -999, menormedia = 999;
	FILE *fp;
	
	printf("Entre com o nome do arquivo: ");
	fscanf(stdin, "%s", nome);
	
	fp = fopen(nome, "r");
	if(!fp){
		printf("Erro de abertura do arquivo!");
		exit(1);
	}
	
	fscanf(fp, "%d ", &q);
	nmedia = (double *) calloc(q , sizeof(double));
	
	nvet = 0;
	
	
	while(fgets(num, 128, fp) != NULL){	
		
		
		line = num;
		soma = 0;
		i = 0;
		
		printf("%2d) ", nvet + 1);		
		
		while(sscanf(line," %d%n", &n, &offset) == 1){
		
			line += offset;			
			printf("%3d ", n);			
			soma = soma + n;			
			i++;
		}
		
		media = ((double)soma / (double)i);
		nmedia[nvet] = media;
		
		printf("\n");
		
		if(media > maiormedia){
			maiormedia = media;
			maiorvet = nvet;
		}
		
		if(media < menormedia){
			menormedia = media;
			menorvet = nvet;
		}
		
		nvet++;		
				
	}
	
	printf("\n*********************************\n");	
	exibirmedias(nmedia, nvet);	
	printf("\n*********************************\n");
	
	mediatotal = funcmediatotal(nmedia, nvet);
	
		
	//b) Apresente media dos valores armazenados
	printf("\n\nMEDIA TOTAL: %.2lf", mediatotal);	

	//d) Apresente qual o vetor com maior media
	printf("\nMAIOR MEDIA : %.2lf", maiormedia);
	
	//e) Apresente qual o vetor com menor media
	printf("\nMENOR MEDIA : %.2lf", menormedia);
	
	//f) Apresente quantos vetores possuem média superior e inferior a média total.
	printf("\nQTE VETORES COM MEDIA SUPERIOR: %d", mediasuperior(nmedia, mediatotal, nvet));
	
	printf("\nQTE VETORES COM MEDIA INFERIOR: %d", mediainferior(nmedia, mediatotal, nvet));
	
	free(nmedia);
	fclose(fp);
	return 0;
	
}


