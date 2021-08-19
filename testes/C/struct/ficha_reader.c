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

typedef struct data{	
	char nome[30];
	int tam;	
}TData;

TData info;


void limpartela(){
	
	if(system("clear") != 0){
		system("CLS");
	}		
}


int salvarRegistros( TFicha *temp, int i , FILE *fp){
	
	fprintf(fp, "%d\n", temp[i].cod);		
	fprintf(fp, "%s\n", temp[i].nome );			
	fprintf(fp, "%d\n", temp[i].idade);		
	fprintf(fp, "%.2lf\n", temp[i].salario);				
	fprintf(fp, "%d  %d  %d\n", temp[i].horas[0],temp[i].horas[1],temp[i].horas[2]);	
	fprintf(fp, "%d / %d / %d\n", temp[i].data.dia, temp[i].data.mes, temp[i].data.ano );
	fprintf(fp, "\n");
	
	return 0;
}

int exibirRegistros( TFicha *temp, int tam ){
	
	int i;
	
	if(tam == 0){
		printf("Lista vazia\n\n");
		return 0;
	}
	
	for(i = 0; i < tam; i++){		
	
	printf("COD: %d\n", temp[i].cod);		
	printf("Nome: %s\n", temp[i].nome );			
	printf("Idade %d\n", temp[i].idade);		
	printf("Salario: R$ %.2lf\n", temp[i].salario);				
	printf("Hora Extra 1: %d\nHora Extra 2: %d\nHora Extra 3: %d\n", temp[i].horas[0],temp[i].horas[1],temp[i].horas[2]);	
	printf("Data de Nascimento: %d / %d / %d\n", temp[i].data.dia, temp[i].data.mes, temp[i].data.ano );
	printf("\n");
	
	}
	
	return 0;
}


void carregarRegistros( TFicha *temp , int i, FILE *fp ){
	
	char aux[50];
	fscanf(fp, "%d\n", &temp[i].cod);		
	fscanf(fp, "%[^\n]%*c", temp[i].nome );			
	fscanf(fp, "%d\n", &temp[i].idade);		
	fscanf(fp, "%lf\n", &temp[i].salario);	
	fscanf(fp, "%[^\n]%*c", aux);				
	sscanf(aux, "%d  %d  %d\n", &temp[i].horas[0], &temp[i].horas[1], &temp[i].horas[2]);	
	fscanf(fp, "%d / %d / %d\n", &temp[i].data.dia, &temp[i].data.mes, &temp[i].data.ano );	
	fflush(fp);
}

int carregarArquivo( TFicha **aux , int *tam ){
	
	int i, n;
	TFicha *temp;
	FILE *fp;
	char tmp;
	
	printf("\nEntre com o nome do arquivo: ");
	fscanf(stdin, "%s", info.nome);
	
	
	fp = fopen(info.nome, "r");
	if(!fp){
		printf("Cannot open the file!");
		exit(1);
	}
	
	fscanf(fp, "%d\n", &info.tam);
	
	if(n > 0){
		
		temp = (TFicha *) calloc(info.tam, sizeof(TFicha));
		for(i = 0; i < info.tam; i++){
			carregarRegistros(temp, i, fp);
		}
	}
	
	*aux = temp;
	*tam = info.tam;
	fclose(fp);
	
	return 0;	
}


int excluirRegistro(TFicha **temp, int *tam){
	
	int i, x, n, j, k, selec, nselect;	
	TFicha *aux, *aux2;
	aux = aux2 = *temp;
	n = *tam;
	
	if(n < 1){		
		printf("A lista esta vazia. ");
		return 0;
	}
	
	for(i = 0; i < n; i++){
		printf("REG %d -  %d \n", i+1, aux[i].cod);
	}
	
	printf("Quantos registros serao excluidos? ");
	scanf("%d", &nselect);
	
	if(nselect > n){
				
		printf("\nValor invalido. A lista tem %d elementos.", n);
		return 0;
	}
	
	for(i = 0; i < nselect; i++){
		
		printf("Operacao %d de %d\n", i+1, nselect);
		printf("Entre com o codigo do registro a ser excluido: ");
		scanf("%d", &selec);
		
		k = 0;
		for(j = 0; j < n; j++){
			if(selec != aux[j].cod )
			{
				aux2[k].cod = aux[j].cod;		
			    strcpy( aux2[j].nome, aux[j].nome); 			
				aux2[k].idade = aux[j].idade;		
				aux2[k].salario = aux[j].salario;				
				aux2[k].horas[0] = aux[j].horas[0];
				aux2[k].horas[1] = aux[j].horas[1];
				aux2[k].horas[2] = aux[j].horas[2];	
				aux2[k].data.dia = aux[j].data.dia;
				aux2[k].data.mes = aux[j].data.mes;
				aux2[k].data.ano = aux[j].data.ano;
				k++;
			}
		}		
		aux = aux2;				
	}
	
	x = n - nselect;
	*tam = x;
	*temp = aux;	
	printf("\nRemocao efetuada com sucesso.\n");	
	
	return 0;
}



int salvarArquivo( TFicha *temp, int tam ){
	
	int i, n, aux = 0;
	char nome[40];
	FILE *fp;
	
	printf("\nComo deseja salvar seu arquivo?\n\n1- Salvar novo\n2- Sobrescrever\n\n");
	printf("Escolha a opcao: ");
	scanf("%d", &n);
	
	if(n == 1){
		printf("Entre com o nome do novo arquivo: ");
		fscanf(stdin, "%s", nome);
		fp = fopen(nome, "w");
		if(!fp){
			printf("Nao foi possivel criar o arquivo.");
			exit(1);
		}
		
		fprintf(fp, "%d\n", tam);
		
		for(i = 0; i < tam; i++){
			aux += salvarRegistros( temp, i, fp );
		}
		
		printf("\nRegistros salvos com sucesso.");
		fclose(fp);	
		return 0;	
	}
	
	if(n == 2){
		fp = fopen(info.nome, "w");
		if(!fp){
			printf("Nao foi possivel criar o arquivo.");
			exit(2);
		}
		
		fprintf(fp, "%d\n", tam);
		
		for(i = 0; i < tam; i++){
			aux += salvarRegistros( temp, i, fp );
		}
		
		printf("\nRegistros salvos com sucesso.\n");
		fclose(fp);	
		return 0;		
	}
	
	else{
		printf("\nOpcao Desconhecida. ");
		return 0;
	}	
}

int criarRegistros( TFicha **aux, int *tam){
	
	int i, j, n, tmp;
	char str[50], str2[50], c;
	TFicha *temp;
	
	printf("Quantos registros serao incluidos? ");
	scanf("%d", &info.tam);
	
	temp = (TFicha *) calloc(info.tam, sizeof(TFicha));
	
	
	for(i = 0; i < info.tam; i++){
		
		printf("Registro %d de %d\n", i+1, info.tam);	
		
		fflush(stdin);
		temp[i].cod = rand()%100;		
		
		printf("Nome: ");
		fscanf(stdin," %[^\n]%*c", temp[i].nome);
		fflush(stdin); 
				
		printf("Idade: ");
		fscanf(stdin, "%d", &temp[i].idade);
		

		printf("Salario (R$): ");
		fscanf(stdin, "%lf", &temp[i].salario);
		
		
		printf("Horas:\n");
		for(j = 0; j < 3; j++){
			printf("Hora %d: ", j + 1);
			fscanf(stdin,"%d", &temp[i].horas[j]);			
		}		
	
		printf("\nData de Nascimento: ");
		c = getchar();
		fgets(str, 50, stdin);		
		sscanf(str," %d / %d / %d\n", &temp[i].data.dia,  &temp[i].data.mes, &temp[i].data.ano);		
		printf("Dado inserido com sucesso!\n\n");	
		
		printf("Tecle em alguma tecla para continuar... ");
		c = getchar();
		limpartela();
		fflush(stdin);
		
	}
	
	*aux = temp;
	*tam = info.tam;
	return 0;
	
}




int main(void){
	
	int tam, n, stat = 0;
	TFicha *temp;
	tam = 0;	
	
	do{
		printf("Menu\n\n1. Sair\n2. Carregar Arquivo\n3. Exibir Lista\n4. Excluir Registro\n5. Salvar Arquivo\n6. Criar novo\n");
		
		printf("\n\nEscolha uma opcao: ");
		scanf("%d", &n);
		switch(n){
			case 1:
				limpartela();
				printf("1. Sair\n");
				stat = 1;
				break;
			
			case 2:
				limpartela();
				printf("2. Carregar Arquivo\n");
				stat = carregarArquivo(&temp, &tam);
				break;
				
			case 3:
				limpartela();
				printf("3. Exibir Lista\n");
				stat = exibirRegistros(temp, tam);
				break;
				
			case 4:
				limpartela();
				printf("4. Excluir Registro\n");
				stat = excluirRegistro(&temp, &tam);
				break;
				
			case 5:
				limpartela();
				printf("5. Salvar Arquivo\n");
				stat = salvarArquivo(temp, tam);
				break;
				
			case 6:
				limpartela();
				printf("6. Criar Novo\n");
				stat = criarRegistros(&temp, &tam);
				break;
				
			
			default:
				printf("Nao entendi.\n");
			
		}
		
		
	}
	while(stat == 0);		

	return 0;
	
}
