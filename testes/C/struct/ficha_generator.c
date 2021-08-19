#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 10

typedef struct nasc{	
	int dia;
	int mes;
	int ano;	
}DNasc;

typedef struct ficha{
	
	int cod;
	char nome[50];
	int idade;
	double salario;
	int horas[3];
	DNasc data;
	
}TFicha;


void exibirRegistro( TFicha *temp, int i ){
	
	printf("COD: %d\n",temp[i].cod);		
	printf("Nome: %s\n",temp[i].nome );			
	printf("Idade %d\n", temp[i].idade);		
	printf("Salario: R$ %.2lf\n", temp[i].salario);				
	printf("Hora 1: %d\nHora 2: %d\nHora 3: %d\n", temp[i].horas[0],temp[i].horas[1],temp[i].horas[2]);	
	printf("Data de Nascimento: %d / %d / %d\n", temp[i].data.dia, temp[i].data.mes, temp[i].data.ano );
	printf("\n");
}

void gravarRegistro( TFicha *temp, int tam , FILE *fp){
	
	int i;
	for(i = 0; i < tam; i++){
		fprintf(fp, "%d\n", temp[i].cod);		
		fprintf(fp, "%s\n", temp[i].nome );			
		fprintf(fp, "%d\n", temp[i].idade);		
		fprintf(fp, "%.2lf\n", temp[i].salario);				
		fprintf(fp, "%d  %d  %d\n", temp[i].horas[0],temp[i].horas[1],temp[i].horas[2]);	
		fprintf(fp, "%d / %d / %d\n", temp[i].data.dia, temp[i].data.mes, temp[i].data.ano );
		fprintf(fp, "\n");
	}
}


int main(void){
	
	int i, j, n, k;
	FILE *fp;
	TFicha *temp;
	
	char nome[30], aux[40], tmp;
	
	printf("\nEntre com o nome do arquivo: ");
	fscanf(stdin, "%s", nome);
	
	
	fp = fopen(nome, "w");
	if(!fp){
		printf("Cannot create the file!");
		exit(1);
	}
	
	printf("Entre com o numero de registros a serem criados: ");
	fscanf(stdin, "%d", &n);
	temp = (TFicha *) calloc(n, sizeof(TFicha));
	
	fprintf(fp, "%d\n", n);
		
	for(i = 0; i < n; i++){
		
		if(system("clear") != 0){
			system("CLS");
		}			
		
		printf("Registro %d de %d\n", i+1, n);	
		
		fflush(stdin);
		temp[i].cod = rand()%100;		
		
		printf("Nome: ");
		//fgets(temp[i].nome, sizeof(temp[i].nome), stdin);		
		scanf("%[^\n]%*c", temp[i].nome );
		
		printf("Idade: ");
		fscanf(stdin, "%d", &temp[i].idade);
		

		printf("Salario (R$): ");
		fscanf(stdin, "%lf", &temp[i].salario);
		
		
		printf("Horas Extras:\n");
		for(j = 0; j < 3; j++){
			printf("Hora %d: ", j + 1);
			fscanf(stdin,"%d", &temp[i].horas[j]);			
		}		
	
		printf("\nData de Nascimento: ");
		fflush(stdin);		
		//fgets(aux, 40, stdin);
		scanf("%[^\n]%*c", aux );		
		sscanf(aux,"%d / %d / %d\n", &temp[i].data.dia,  &temp[i].data.mes, &temp[i].data.ano);
				
		
		printf("\n*******************************\n");	
		printf("Dado inserido com sucesso!\n\n");
		exibirRegistro(temp, i);
		printf("\n*******************************\n");
		
		printf("Tecle em alguma tecla para continuar... ");
		tmp = getchar();
		
	}
	
	gravarRegistro(temp, n, fp);
	
	free(temp);
	fclose(fp);
	return 0;
	
}
