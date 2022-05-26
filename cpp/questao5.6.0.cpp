/*
QUEST�O 06: Fa�a um programa que leia 200 n�meros inteiros. Ao final, exibir:
a) O maior n�mero fornecido, de ordem par (isto �, o maior dentre o segundo, quarto, sexto, oitavo, etc valores fornecidos).
b) A m�dia dos valores pares.
*/

#include <stdio.h>

int main(void)
{
	int i, num, contp = 0;
	float sumpar = 0; //D� errado se n�o colocar float. Contador � inteiro e por isso n�o vou mudar.
	int tot = 5; //original 200. N�o vou colocar 200 n�o >:/
	int maior = 0;
	float media;
	
	for(i = 1; i <= tot; i++)
	{
		printf("\nEntre com o %do numero: ", i);
		scanf("%d", &num);
		
		//Verifica��o da entrada do usuario - se eh par ou impar
				
		if(num%2==0) // se eh par
		{
			sumpar = sumpar + num; //soma os pares
			contp++; //conta os pares
		}
		
		//Verifica��o do contador: so eh contabilizada as entradas pares
		if(i%2 == 0)
		{
			if(maior == 0) // inicializa��o. qualquer numero � maior que 0 a n�o ser se colocar o - na frente.
			{
				maior = num; //come�a com o primeiro numero sendo o maior
			}
			else
			{
				if(num > maior)
				{
					maior = num;
				}
			}
		}	
	}
	
	media = sumpar / contp;
	
	printf("\n********************************** \n");
	printf("\n\nO maior de ordem par eh: %d.\n", maior);
	printf("\nA media dos numeros pares e: %.2f.\n", media);
	return 0;
}
