#include <stdio.h>
#include <stdlib.h>

typedef struct data{
	int dia;
	int mes;
	int ano;	
}Data;

typedef struct cpf{
	long long int cpfnumero;
	int digitos[9];
	int verificador[2];
}CPF;

typedef struct registro{
	char nome[100];
	CPF numero;
	Data nasc;
	char email[100];
	int status;	
}Registro;



void carregardados( Registro* pessoas, int *tam )
{
	Registro temp;
	int i, j, size;	
	char unknown;
	FILE *fp;
	fp = fopen("registro.txt","r");
	
	fscanf(fp,"%d\n",&size);
	
	j = 0;
	while((i < 3)&&(!feof(fp)))
	{
		fscanf(fp, "%[^\n]", pessoas[i].nome);
		fscanf(fp,"%i[^\n]", 
		&pessoas[i].numero.digitos[0], 
		&pessoas[i].numero.digitos[1], 
		&pessoas[i].numero.digitos[2], 
		&pessoas[i].numero.digitos[3], 
		&pessoas[i].numero.digitos[4], 
		&pessoas[i].numero.digitos[5], 
		&pessoas[i].numero.digitos[6], 
		&pessoas[i].numero.digitos[7], 
		&pessoas[i].numero.digitos[8], 
		&pessoas[i].numero.digitos[9], 
		&pessoas[i].numero.verificador[10], 
		&pessoas[i].numero.verificador[11] );
		fscanf(fp,"%d%c%d%c%d", &pessoas[i].nasc.dia, &unknown, &pessoas[i].nasc.mes, &unknown, &pessoas[i].nasc.ano );
		fscanf(fp, "%[^\n]", pessoas[i].email);	
		fscanf(fp, "%d", &pessoas[i].status);
				
		i++;	
	}
	
	*tam = size;
}


void exibirdados( Registro* pessoas, int tam )
{
	int i, j;
	for( i = 0; i < tam; i++)
	{
		printf("%s\n",pessoas[i].nome);
		for(j = 0; j < 11; j++)
		{
			if(i < 9)
			{
				printf("%d", pessoas[i].numero.digitos[j]);
			}
			else
			{
				printf("%d", pessoas[i].numero.verificador[j]);
			}
		}
		printf("\n");
		printf("%d  %d  %d\n", pessoas[i].nasc.dia, pessoas[i].nasc.mes, pessoas[i].nasc.ano );
		printf("%s\n", pessoas[i].email);
		printf("%d\n",pessoas[i].status);
		printf("\n");
	}
}

int main()
{
	int tam;
	Registro pessoas[100];
    carregardados(pessoas, &tam);
	
    exibirdados(pessoas,tam);
	return 0;
}


