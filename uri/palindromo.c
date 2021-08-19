#include <stdio.h>
#include <string.h>


void palindromo(char *str, int i, int tam )
{
	if(i < (tam/2)){
		if(str[i] == '') i++;
		if(str[tam-1] == '') tam--;
		if(str[i] == str[tam-1])
		{
			palindromo(str,i+1, tam-1);
		}		
	}
}

int ehpalindromo(char *str )
{
	int tam, ini = 0;
	tam = strlen(str);
	palindromo(str,ini,tam);
	
}

int main(void)
{
	char str[15];
	printf("Entre com a string: ");
	fgets(str, 15, stdin);	
	if(ehpalindromo(str))
	{
		printf("Eh palindromo\n");
	}
	else
	{
		printf("Nao eh palindromo\n");
	}	
	
	return 0;
}
