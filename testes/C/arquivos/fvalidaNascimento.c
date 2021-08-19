#include <stdio.h>
#include <stdlib.h>

int validaNascimento(int dia, int mes, int ano )
{
	if(((ano > 1900 ) && (ano < 2020)) && ((mes > 0) && (mes < 13)) && ((dia > 0) && (dia < 31)))
	{
		
		if((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0)))
		{
			if(mes == 2 && dia > 29){
				
				return 0;
			}
			
			return 1;			
		}
		
		if((mes == 4) && (mes == 6) && (mes == 9) && (mes == 11) && (dia == 31))
		{			
			return 0;
		}
		
		return 1;		 
	}
	
	return 0;
}


