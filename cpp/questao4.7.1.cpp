/*
Lista 4 exercicio 7
QUEST�O 07:
Desenvolver um programa no qual o usu�rio entre com v�rios n�meros inteiros e positivos e imprima o produto dos n�meros �mpares e a soma dos n�meros pares
*/

#include <stdio.h>

int main(void)
{
	unsigned int num;
	char opcao;
	
	
	 //Corrigir .. tem 4 do whiles ;-;
	
	do	
		do //validando o numero. Enquanto o numero nao for positivo, uma msg de erro apareccera
		{
			printf("Entre com um numero: ");
			scanf("%d", &num);
			
			fflush(stdin);		
			printf("Deseja continuar (s/n)? ");
			scanf("%c", &opcao);
			opcao = toupper (opcao);
		}
		while((opcao != 'N') && (opcao != 'S'));
		
	while(opcao == 'S');
	
	
	printf("\nA soma dos numeros digitados eh: %d", soma);
	printf("\nO produto dos numeros digitados eh: %d", produto);
	return 0;
	
}
