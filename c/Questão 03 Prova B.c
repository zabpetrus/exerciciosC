/*Quest�o 03 [2,5 pontos]:
Implementar um programa que leia diversos n�meros
inteiros positivos at� que a terceira pot�ncia de 2 seja
informada pelo usu�rio. Ao final, devem ser exibidos:
a. Total de valores digitados;
b. M�dia dos valores entre a primeira e segunda
pot�ncias de 2.
Observa��o: sempre que um valor n�o positivo for
digitado, uma mensagem de erro dever� ser exibida
ao usu�rio. E estes valores n�o poder�o ser
considerados no c�lculo de cada um dos itens
solicitados.*/
#include<stdio.h>

int main()
{
	int unsigned numero,cont=0,somanumero=0,conttotal=0,somatotal=0;
	
	//Obter n�meros at� que a terceira pot�ncia de 2 seja inserida
	do
	{
		//Obter n�meros
		printf("Insira um numero: ");
		scanf("%d",&numero);
		
		//M�dia dos valores entre a primeira e segunda pot�ncias de 2
		if(numero<4 && numero>2)
		{
			cont++;
			somanumero+=numero;
			conttotal++;
			somatotal+=numero;
		}
		else
		{
			if(numero<0)  //Exibir uma mensagem de erro se o valor inserido for negativo
			{
				printf("Insira um valor valido(valor>=0)");
			
			}
			else  //Total de valores digitados
			{
				conttotal++;
				somatotal+=numero;
			}
		}
	}while(numero!=8);
	
	//Exibir o total de valores digitados
	printf("Quantidade de valores digitados: %d\n",conttotal-1);
	
	//Exibir a soma de todos os valores
	printf("Soma dos valores digitados = %d\n",somatotal-8);
	
	//Exibir a m�dia dos valores entre a primeira e segunda	pot�ncias de 2
	printf("Media dos valores entre a primeira e segunda potencias de 2: %.1f",(float)somanumero/cont);
}
