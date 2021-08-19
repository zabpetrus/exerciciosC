#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 5
#define CTAM 60

/* Faça um programa que seja uma agenda de compromissos e:
Crie e leia um vetor de 5 estruturas de dados com: compromisso (máximo 60 letras)
e data. a data deve ser outra estrutura de dados contendo dia, mes e ano. Lei dois inteiros M e A e mostre todos os compromissos do mes M do ano A
Repita o procedimento ate ler M = 0
*/

typedef struct nasc{	
	int dia;
	int mes;
	int ano;	
}DNasc;

typedef struct ficha{
	
	char comp[CTAM];
	DNasc data;
	
}TComp;

typedef struct infodata{
	
	FILE *arquivo;
	char nfile[30];
		
}Info;

Info info;

void mostrar( TComp *f, int i){
	int k;
	for(k = 0; k < i; k++)
	{
		printf("\n");		
		printf("COMPROMISSO: %s\n", f[k].comp);	
		printf("DATA: %d / %d / %d \n", f[k].data.dia, f[k].data.mes, f[k].data.ano );
	}
}

int modificar( TComp *f , int tam ){
	
	int i, j, n, tmp, d, m, a;
	char temp[CTAM];
	
	for(i = 0; i < tam; i++){
		
		printf("Reg %d\n%s", i, f[i].comp);
		printf("%d / %d / %d \n\n",  f[i].data.dia, f[i].data.mes, f[i].data.ano);
	}
	
	printf("Entre com o numero do registro a ser modificado: ");
	scanf("%d", &n);
	
	printf("Entre com o titulo do evento: <enter> para manter: ");
	
	fflush(stdin);
	fgets(temp, CTAM, stdin);
	tmp = getchar();
	
	if(strlen(temp) > 0){
		strcpy(f[n].comp, temp);
	}
	
	printf("Entre com a data do evento: <enter> para manter: ");
	fgets(temp, CTAM, stdin);
	
	sscanf(temp, "%d / %d / %d ", &d, &m, &a);
	
	if(d > 0)	
	{
		f[n].data.dia = d;
	}
	
	if(m > 0)	
	{
		f[n].data.mes = m;
	}
	
	if(a > 0)	
	{
		f[n].data.ano = a;
	}	
	
	fflush(stdin);
	tmp = getchar();
	return 0;
	
}


int inserir( TComp *f , int i ){
	
	int j, n, tmp;
	char temp[30], ntemp[CTAM], option;
			
	if(!info.arquivo){
		
		printf("Sem nenhum arquivo associado. Deseja criar um? (y/n)");
		fflush(stdin);
		option = getchar();
		if(option == 'y' && option == 'Y'){
			
			tmp = criar(f, i);			
		}
		
	}
	fflush(stdin);
	fscanf(info.arquivo, "%d", &n);			

	printf("Entre com o compromisso: ");	
	fflush(stdin);
	fgets(f[i].comp, CTAM, stdin);	
	
	fflush(stdin);
	printf("Entre com a data do evento: ");
	fgets(temp, 30, stdin);
	sscanf(temp,"%d / %d / %d", &f[i].data.dia,  &f[i].data.mes,  &f[i].data.ano );	
		

	printf("\nRegistros inseridos com sucesso. Clique para continuar...\n");
	fflush(stdin);
	tmp = getchar();
	return 0;
	
}

int excluir( TComp *f , int tam ){
	
	int n, i, k;
	TComp *aux;
	char temp[50], buffer[50];
	aux = f;
	
	printf("Entre com o titulo do compromisso ou a data: ");
	fgets(temp, 50, stdin);
	
	k = 0;	
	for(i = 0; i < tam; i++){
		if(strcmp(temp, f[i].comp) == 0){
			k++;
		}
		else{
			snprintf(buffer, sizeof(buffer), "%d / %d / %d", f[i].data.dia, f[i].data.mes, f[i].data.ano); 
			if(strcmp(temp, buffer) == 0){
				k++;	
			}			
		}
	}
	
	printf("Foram achados %d valores!");
	return 0;
}



int exibir( TComp *f , int i ){
	
	int tmp;
	if(i == 0){
		printf("Arquivo de Comprimento vazio.");		
	}
	else{
		mostrar(f, i);		
	}
	printf("\nClique para continuar...");
	fflush(stdin);
	tmp = getchar();
	return 0;
}

int criar( TComp *f, int i ){
	
	char tmp;
	printf("Entre com o nome do arquivo da agenda: ");
	fscanf(stdin, "%s", info.nfile);
	
	info.arquivo = fopen(info.nfile, "w+");
	if(!info.arquivo){
		printf("Erro durante a criacao do arquivo.");
		exit(1);
	}	
	
	fprintf(info.arquivo, "%d\n", 0);
	printf("Arquivo de registro criado com sucesso! Clique para continuar...");
	
	fflush(stdin);
	tmp = getchar();
	return 0;	                                                                     
}

int carregar( TComp *f , int *index ){
	
	int i, n, j, tmp;
	char temp[CTAM];
	printf("Entre com o nome do arquivo de registro: ");
	fscanf(stdin, "%s", info.nfile);
	
	info.arquivo = fopen(info.nfile, "a+");
	if(!info.arquivo){
		printf("Nao foi possivel abrir o arquivo");
		exit(1);	
	}	
	
	i = 0;
	
	while(fscanf(info.arquivo, "%[^\n]%*c ", f[i].comp )!= EOF)
	{		
		fscanf(info.arquivo, "%[^\n]%*c ", temp);
		sscanf(temp, "%d / %d / %d\n", &f[i].data.dia, &f[i].data.mes, &f[i].data.ano );
		i++;			
	}

	
	*index = i;	
	
	
	printf("\nArquivo carregado com sucesso.\nClique para continuar... ");
	
	fflush(stdin);
	tmp = getchar();
	return 0;
	
}

void limpartela(){
	if(system("clear")){
		system("CLS");
	}	
}

int salvar(TComp *ficha, int i){
	
	
	int j, tmp;	
	if(!info.arquivo){
		
		printf("Entre com o nome do arquivo: ");
		fgets(info.nfile, CTAM, stdin);
		info.arquivo = fopen(info.nfile, "aw");				
	}
	
	info.arquivo = fopen(info.nfile, "aw");

	for(j = 0; j < i; j++){
			
		fprintf(info.arquivo, "%s", ficha[j].comp);
		fprintf(info.arquivo, "%d / %d / %d\n", ficha[j].data.dia, ficha[j].data.mes, ficha[j].data.ano);
		fprintf(info.arquivo, "\n");				
	}
	
	printf("\nArquivo salvo com sucesso. \nClique para continuar... ");
	fclose(info.arquivo);
	
	fflush(stdin);
	tmp = getchar();
	return 0;
}

int buscar(TComp *ficha, int i){
	
	int j, m, a, nrecords = 0;
	m = 0;
	
	do{		
		printf("Entre com o mes: ");
		scanf("%d", &m);
		
		printf("Entre com o ano: ");
		scanf("%d", &a);
		
		for(j = 0; j < i; j++){
			
			if((m == ficha[j].data.mes) && (a == ficha[j].data.ano)){
				
				printf("%s\n", ficha[j].comp);
				printf("%d / %d / %d\n", ficha[j].data.dia, ficha[j].data.mes, ficha[j].data.ano);
				nrecords++;				
			}			
		}
	}
	while(m != 0);
	
	printf("\n%d resultados encontrados!", nrecords);
	
	return 0;
}


void checardados(){
	
	//Info info
	int b;	
	if(strlen(info.nfile) > 0){
		printf("\nArquivo: %s \n", info.nfile);
	}
	
}


int main(void){
	
	int i, f, fx;
	TComp ficha[TAM];
	
	f = 0;
	i = 0;
	
	do{	
		limpartela();	
		printf("\nMENU: \n");
		checardados();
		
		printf("\n1- Sair\n2- Criar Novo\n3- Carregar\n4- Inserir\n5- Excluir\n6- Exibir Registro\n7- Modificar Registro\n8- Salvar registro\n");
		printf("\nEntre com uma opcao: ");
		scanf("%d", &fx);
		switch(fx){
			
			case(1):
				printf("\n1 - Sair\n");
				f = 1;
				break;
				
			case(2):
				printf("\n2- Criar Novo\n");
				f = criar(ficha, i);
				break;
				
			case(3):
				printf("\n3- Carregar Registro\n");
				f = carregar(ficha, &i);
				break;
			
			case(4):
				printf("\n4 - Inserir\n");
				f = inserir(ficha, i);
				i++;
				break;
			
			case(5):
				printf("\n5 - Excluir\n");
				f = excluir(ficha, i);
				break;
				
			case(6):
				printf("\n6 - Exibir\n");
				f = exibir(ficha, i);
				break;
				
			case(7):
				printf("\n7 - Modificar\n");
				f = modificar(ficha, i);
				break;
				
			case(8):
				printf("\n8 - Salvar Registros\n");
				f = salvar(ficha, i);
				break;
				
			case(9):
				printf("\n9 - Buscar Registros\n");
				f = buscar(ficha, i);
				break;		
				
			default:
				printf("Nao entendi");		
			
		}		
	}
	while(f == 0);
	return 0;
}
