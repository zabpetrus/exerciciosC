#include <stdio.h>
#include <stdlib.h>
/*
O objetivo deste programa e gerar um arquivo generico alunos.dat
cujas linhas consistem em numero inteiro, que e o codigo do aluno
e cinco doubles que sao cinco medias do aluno referenciado.
*/

int main(void){
	
	int i, j, n;
	double num;
	FILE *fp;
	fp = fopen("alunos.dat", "w");
	if(!fp){
		printf("Erro de abertura do arquivo.");
		exit(1);
	}
	
	printf("Entre com o numero de linhas: ");
	scanf("%d", &n);
	
	fprintf(fp, "%d\n", n);
	
	for(i = 0; i < n; i++){
		
		fprintf(fp, "%04d ", i+1);
		for(j = 0; j < 5; j++)
		{
			//num = (double) 9 * (rand()%100) + 100;
			//num = num + ((rand()%100) / 7.0);
			//fprintf(fp, "%6.1lf ", num);
			
			num = (double) (rand()%10) + 1;
			if(num < 9.0){
				num = num + ((rand()%10) / 7.0);
			}			
			fprintf(fp, "%6.1lf ", num);
			
		}
		fprintf(fp, "\n");
	}
	printf("Arquivo gerado com sucesso!");
	
	return 0;
}
