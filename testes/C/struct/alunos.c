#include <stdio.h>
#include <stdlib.h>

//https://repl.it/@belsouza/SturdyDeafeningDisplaymanager#main.c

typedef struct aluno{
	int cod;
	float nmat, nlin, nhum, nnat, nred;
	float media_p;	
}NAluno;


char* status( float num ){	
	if(num >= 6.0){
		return "AP";
	}	
	return "RP";
}


void exibirAlunos (NAluno *ini, NAluno *fin, int tam){
	
	int i;
	
	printf("%s %s     %s     %s     %s     %s   | %s    %s     %s      %s    %s    | %s  %s\n", "Codigo","MAT","LIN","HUM","NAT","RED","MAT","LIN","HUM","NAT","RED","Media _P","Situacao");
	for(i = 0; i < tam; i++){
		
		printf("%04d  %6.1f  %6.1f  %6.1f  %6.1f  %6.1f |", ini[i].cod, ini[i].nmat, ini[i].nlin, ini[i].nhum, ini[i].nnat, ini[i].nred);
		printf("%6.1f  %6.1f  %6.1f  %6.1f  %6.1f | %5.1f  %7s\n", fin[i].nmat, fin[i].nlin, fin[i].nhum, fin[i].nnat, fin[i].nred, fin[i].media_p, status(fin[i].media_p));				
	}
}

int salvarReg(NAluno *ini, NAluno *fin, int tam){
	
	int i;
	FILE *fp;
	fp = fopen("report.dat", "w");
	if(!fp){
		printf("Erro de abertura do arquivo! ");
		return 0;
	}
	
	fprintf(fp, "%d\n", tam);
	for(i = 0; i < tam; i++){
		
		fprintf(fp, "%04d  %6.1f  %6.1f  %6.1f  %6.1f  %6.1f ", ini[i].cod, ini[i].nmat, ini[i].nlin, ini[i].nhum, ini[i].nnat, ini[i].nred);
		fprintf(fp, "%6.1f  %6.1f  %6.1f  %6.1f  %6.1f  %5.1f  %5s\n", fin[i].nmat, fin[i].nlin, fin[i].nhum, fin[i].nnat, fin[i].nred, fin[i].media_p, status(fin[i].media_p));				
	}
	
	fclose(fp);
	return 1;	
}


float media_ponderada( float n1, float n2, float n3, float n4, float n5, float pt ){
	return ((n1 + n2 + n3 + n4 + n5) / pt);
}


int main(void){
	
	FILE *fp;
	
	int i, tam, Pmat, Plin, Phum, Pnat, Pred;	
	float psoma = 0;
	
	
	fp = fopen("alunos.dat", "r");
	if(!fp){
		printf("Erro durante a abertura do arquivo!");
		exit(1);
	}
	
	//Construa um programa em C que tenha como entrada um conjunto de cinco inteiros
	printf("\nEntre com o valor de Pmat: ");
	scanf("%d", &Pmat);
	
	printf("\nEntre com o valor de Plin: ");
	scanf("%d", &Plin);
	
	printf("\nEntre com o valor de Phum: ");
	scanf("%d", &Phum);
	
	printf("\nEntre com o valor de Pnat: ");
	scanf("%d", &Pnat);
	
	printf("\nEntre com o valor de Pred: ");
	scanf("%d", &Pred);	
	
	//primeira linha um inteiro n que informa o número de linhas do arquivo
	fscanf(fp, "%d\n", &tam);
	
	//Leia os dados dos alunos do arquivo alunos.dat e armazene em estruturas que possuam os seguintes campos: codigo, Nmat, Nlin, Nhum, Nnat, Nred e Media_P
	NAluno orig[tam], fin[tam];
	 
	
	
	for(i = 0; i < tam; i++){
		fscanf(fp, "%d  %f  %f  %f  %f  %f \n", &orig[i].cod, &orig[i].nmat, &orig[i].nlin, &orig[i].nhum, &orig[i].nnat, &orig[i].nred);
	}
	
	for(i = 0; i < tam; i++){
		
		fin[i].cod = orig[i].cod;	
		fin[i].nmat = orig[i].nmat * Pmat;
		fin[i].nlin = orig[i].nlin * Plin;
		fin[i].nhum = orig[i].nhum * Phum;
		fin[i].nnat = orig[i].nnat * Pnat;
		fin[i].nred = orig[i].nred * Pred;
		fin[i].media_p = 0;
	}
		
	
	//Calcule a média ponderada para cada um dos alunos utilizando os pesos {Pmat, Plin, Phum, Pnat, Pred} e armazene no campo Media_P.
	psoma = Pmat + Plin + Phum + Pnat + Pred;
	for(i = 0; i < tam; i++){
		fin[i].media_p = media_ponderada(fin[i].nmat, fin[i].nlin, fin[i].nhum, fin[i].nnat, fin[i].nred, psoma);		
	}	
	
	//Apresente no monitor um relatório no seguinte modelo:
	exibirAlunos(orig, fin, tam);
	
	//Armazene o relatório do item anterior em um arquivo report.dat
	if( salvarReg(orig, fin, tam) == 1)
	{
		printf("Registro salvo com sucesso! ");
	}
	
	fclose(fp);
	return 0;
	
}
