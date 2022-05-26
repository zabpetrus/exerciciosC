/*Quest�o 02 [3,0 pontos]:
Desenvolver um programa que simule uma calculadora
que realize as seguintes opera��es: adi��o (+),
subtra��o (-), multiplica��o (x), divis�o (/) e logaritmo
(L). O sistema deve permanecer apresentando um
menu ao usu�rio at� que este opte pela op��o de sa�da
(S). Se a op��o escolhida for uma das 4 opera��es
b�sicas, devem ser solicitados os dois operadores; caso
escolha logaritmo, devem ser solicitados o n�mero
(logaritmando) e a base.

Nota: logba = c <-> b^c = a

Observa��o: todos os operandos s�o n�meros
reais, assim como a base e o logaritmando. Por�m,
o resultado do logaritmo dever� ser inteiro.*/
#include<stdio.h>

int main()
{
	int opcao,contlog=0;
	float valor1,valor2;
	
	//Perguntar qual opera��o o usu�rio deseja
	printf("ADICAO = 1\nSUBTRACAO = 2\nMULTIPLICACAO = 3\nDIVISAO = 4\nLOGARITMO = 5\n");
	printf("Escolha uma opcao(1-5): ");
	scanf("%d",&opcao);
	
	
	
	switch(opcao)
	{
		case 1://Adi��o
			printf("\nPrimeiro valor + Segundo valor = Resultado\n\n");
			
			printf("Insira o primeiro valor: ");
			scanf("%f",&valor1);
			printf("Insira o segundo valor: ");
			scanf("%f",&valor2);
			printf("Resultado = %.1f",valor1+valor2);
			break;
		case 2://Subtra��o
			printf("\nPrimeiro valor - Segundo valor = Resultado\n\n");
		
			printf("Insira o primeiro valor: ");
			scanf("%f",&valor1);
			printf("Insira o segundo valor: ");
			scanf("%f",&valor2);
			printf("Resultado = %.1f",valor1-valor2);
			break;
		case 3://Multiplica��o
			printf("\nPrimeiro valor x Segundo valor = Resultado\n\n");
		
			printf("Insira o primeiro valor: ");
			scanf("%f",&valor1);
			printf("Insira o segundo valor: ");
			scanf("%f",&valor2);
			printf("Resultado = %.1f",valor1*valor2);
			break;
		case 4://Divis�o
			printf("\nPrimeiro valor / Segundo valor = Resultado\n\n");
			
			printf("Insira o primeiro valor: ");
			scanf("%f",&valor1);
			printf("Insira o segundo valor: ");
			scanf("%f",&valor2);
			printf("Resultado = %.1f",valor1/valor2);
			break;
		case 5://Logaritmo
			printf("\nLOGba=c\n\n");
			printf("Insira o valor da base: ");
			scanf("%f",&valor1);
			printf("Insira o valor do logaritmando: ");
			scanf("%f",&valor2);
			
			while(valor1<=valor2)
			{
				valor1*=valor1;
				contlog++;
			}
			printf("Logaritmo = %d",contlog);
			
	}
}
