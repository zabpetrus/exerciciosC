/*
lista 5 exercicio 5
QUEST�O 05: Elabore um programa que calcule a m�dia ponderada de n elementos.
Observa��o: na m�dia ponderada, cada elemento possui um peso que representa a sua contribui��o no c�lculo da m�dia final.

ERRADO!!!!!!!!!!!!!!!!!!!! O CERTO EH O 5.5.1!!!!!
*/

#include <stdio.h>

int main(void)
{
	int i, n, elem, num;
	int sumnum = 0, sumden = 0;
	float media;
	
	
	printf("Entre com o numero de termos:  ");
	scanf("%d", &n);
	
	for(i = 1; i <= n; i++)
	{
		printf("\nEntre com o %d termo: ", i);
		scanf("%d", &elem);
		
		num = i * elem; //i � o peso e elem � o elemento. O produto � adicionado
		sumnum = sumnum + num; //soma do numerador = 1 * elem + 2 * elem e assim vai
		sumden = sumden + elem; //pega os valores que foram inseridos pelo usuario.
		
	}
	
	media = sumnum / sumden;
	printf("\n*****************\nA media ponderada dos %d elementos eh %.2f \n", n, media);
	return 0;
}
