/*
QUEST�O 08: Em uma empresa deseja-se fazer um levantamento sobre algumas informa��es dos seus 250 funcion�rios.
 Cada funcion�rio dever� responder um question�rio ao qual informar� os seguintes dados: 
 matr�cula, sexo, idade, sal�rio e tempo (em anos) de trabalho na empresa. A execu��o do programa deve exibir os seguintes itens:
a) Matr�cula de todos os funcion�rios que ingressaram na empresa com menos de 21 anos;
b) Quantidade de funcion�rios do sexo feminino;
c) M�dia salarial dos homens
*/

#include <stdio.h>

int main (void)
{
	int i, j = 0, k = 0;
	int matr;
	int idade;
	float salario, somedia = 0;
	int anos;
	char sex;
	
	
	
	
	for (i = 0; i <= 4; i++)
	{
		printf ("Entre com a matricula: ");
		scanf("%d", &matr);
		
		printf("\nEntre com o sexo: f ou m");
		scanf("%c", &sex);
		
		printf ("\nEntre com a idade: ");
		scanf("%d", &idade);
		
		printf("\nEntre com o salario: ");
		scanf("%f", &salario);
		
		printf ("\nEntre com os anos de trabalho: ");
		scanf ("%d", &anos);
		
		if( (anos - idade) < 21  ){
			printf ("%d", matr);
		}
		
		if(sexo == 'f')
		{
			j = j + 1;
		}
		else{
			somedia = somedia + salario;
			k = k + 1;
		}		
	}
	printf("\n\nMatricula dos funcionarios que ingressaram na empresa com menos de 21: %d");
	printf("\nExistem %d funcionarios do sexo feminino!", j);
	printf ("\na) A media salarial dos homens �: %d", somedia/k);
	
}
