#include <stdio.h>
#include <string.h>
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

void mostrar( TFicha *f, int i){
	int k;
	for(k = 0; k < i; k++)
	{
		printf("\n");
		printf("COD: %d\n", f[k].cod);
		printf("NOME: %s", f[k].nome);
		printf("IDADE: %d\n", f[k].idade);
		printf("SALARIO: %lf \n", f[k].salario);
		printf("HORAS: %d  %d  %d\n", f[k].horas[0],f[k].horas[1], f[k].horas[2] );
		printf("DATA DE NASCIMENTO: %d / %d / %d \n", f[k].data.dia, f[k].data.mes, f[k].data.ano );
	}
}

int contem( TFicha *f, int index, int n ){
	
	int i;
	for(i = 0; i < index; i++)
	{
		if(n == f[i].cod)
		{
			return 1;
		}
	}
	
	return 0;
}

int inserir( TFicha *f , int i ){
	
	int j;
	FILE *fp = fopen("ficha.txt", "aw");
	
	char temp[30];
	f[i].cod = rand()%100;
	printf("Entre com o nome: ");	
	fflush(stdin);
	fgets(f[i].nome, 50, stdin);
	
	fflush(stdin);
	printf("Entre com a idade: ");
	fscanf(stdin, "%d", &f[i].idade);
	
	fflush(stdin);
	printf("Entre com o salario: ");
	fscanf(stdin, "%lf", &f[i].salario);
	
	fflush(stdin);
	printf("Entre com as horas: \n");	
	for(j = 0; j < 3; j++){
		
		printf("Entre com a %d hora: ", j+1);
		scanf("%d", &f[i].horas[j]);
		fflush(stdin);
	}	
	
	fflush(stdin);
	printf("Entre com a data de nascimento: ");
	fgets(temp, 30, stdin);
	sscanf(temp,"%d / %d / %d", &f[i].data.dia,  &f[i].data.mes,  &f[i].data.ano );	
	
	
	fprintf(fp,"%d\n", f[i].cod);
	fprintf(fp,"%s", f[i].nome);
	fprintf(fp,"%d\n", f[i].idade);
	fprintf(fp,"%.2lf\n", f[i].salario);
	fprintf(fp,"%d  %d  %d\n", f[i].horas[0], f[i].horas[1], f[i].horas[2]);
	fprintf(fp,"%d / %d / %d\n", f[i].data.dia,f[i].data.mes, f[i].data.ano );
	fprintf(fp,"\n");
	return 0;
	
}

int excluir( TFicha *f , int i ){
	
	int n, j, k;
	Tficha *temp;
	
	printf("\nEntre com o codigo do registro: ");
	scanf("%d", &n);
	
	if(contem(f, i, n))
	{		
		FILE *fp = tmpfile();
		for(k = 0; k < i ; k++){
			if(f[k].cod != n){
				
				fprintf(fp,"%d\n", f[i].cod);
				fprintf(fp,"%s", f[i].nome);
				fprintf(fp,"%d\n", f[i].idade);
				fprintf(fp,"%.2lf\n", f[i].salario);
				fprintf(fp,"%d  %d  %d\n", f[i].horas[0], f[i].horas[1], f[i].horas[2]);
				fprintf(fp,"%d / %d / %d\n", f[i].data.dia,f[i].data.mes, f[i].data.ano );
				fprintf(fp,"\n");
			}
		}
		
		
	}
	else
	{
		printf("\nNao encontrei este codigo...");
	}
	
	return 0;
}

int exibir( TFicha *f , int i ){
	if(i == 0){
		printf("Sem dados");
	}
	else{
		mostrar(f, i);
	}
	return 0;	
}






int main(void){
	
	int i, f, fx;
	TFicha ficha[TAM];
	
	f = 0;
	i = 0;
	
	do{
		
		printf("\nEntre com uma opcao: ");
		printf("\n1- Inserir\n2- Excluir\n3- Exibir\n4- Sair\n\n");
		
		scanf("%d", &fx);
		switch(fx){
			
			case(1):
				printf("\n1 - Inserir\n");
				f = inserir(ficha, i);
				i++;
				break;
			
			case(2):
				printf("\n2 - Excluir\n");
				f = excluir(ficha, i);
				break;
				
			case(3):
				printf("\n3 - Exibir\n\n");
				f = exibir(ficha, i);
				break;
				
			case(4):
				printf("\n4 - Sair");
				f = 1;
				break;
				
			default:
				printf("Nao entendi");		
			
		}		
	}
	while(f == 0);
	return 0;
}
