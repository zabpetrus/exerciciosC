#include <stdio.h>
/*
1 1 6 6 6 2 1 1 1 4 4 3 3 3 3 2 2 0
Sa�da do programa:
1 � 2 vez(es)
6 � 3 vez(es)
2 � 1 vez(es)
1 � 3 vez(es)
4 � 2 vez(es)
3 � 4 vez(es)
2 � 2 vez(es)
*/

int main(void)
{
	int num;
	int ant= 0, cont =0;
	
	do
	{
		printf("\nNumero:");
		scanf("%d", &num);
		
		if(ant == 0)//inicializacao
		{
			ant = num;			
		}
		
		if(ant == num)
		{
			cont = cont + 1;
		}
		else // o diferente aciona a exibi��o
		{
			printf("\n%d - %d vez(es)\n", ant, cont); //Mostra o numero anterior e a contagem;
			ant = num; //adora, d� lugar ao numero recente e
			cont = 1; //reinicia a contagem. come�a no 1 porque o referido numero j� foi digitado.						
		}
		
		//printf("%d: %d vezes", num, cont);
	}
	while(num != 0);
}
