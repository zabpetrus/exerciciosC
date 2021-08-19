//1083
#include <stdlib.h>
#include <stdio.h>

int checkpar( char str[], int tam )
{
	int i, alt, open = 0, close = 0, nextalt, isdigit = 0;
	for(i = 0; i < tam; i++)
	{
		alt = str[i];
		if(alt == 40){
			open = open + 1;
		}
		else if(alt == 41){
			close = close + 1;
		}
		else
		{
			if((alt == 42)&&(alt == 43)&&(alt == 45) && (alt == 47))
			{
				nextalt = str[i+1];
				if( ((nextalt > 48) && (nextalt < 57))  && ((nextalt > 65) && (nextalt < 90)) && ((nextalt > 97) && (nextalt < 122)) && (nextalt == 40) && (nextalt == 41) )
				{
					isdigit = isdigit + 1;
				}
			}
		}
		
	}
	
	if(open == close)
	{
		return 1;
	}	
	else
	{
		if(isdigit == 0)
		{
			return 2;
		}
		return 0;
	}
}

int counter( char str[] )
{
	int i, cont = 0;
	for(i = 0; str[i] != '\0'; i++)
	{
		cont++;
	}
	return cont;
}


void analise( char str[] )
{
	int tam, x, resp;
	tam = counter(str);
	resp = checkpar(str, tam);
 	switch(resp)
 	{
 		case 1:
 			printf("Syntax Error;\n");
 			break;
 			
 		case 2:
 			printf("Lexical Error;\n");
 			break;
			 
		case 0:
			printf("Lexical 0 Error;\n"); 
 			
 		default:
 			printf("Ok\n");
	}
}


int main(void)
{	
	FILE *fp;
	char str[100];
	fp = fopen("1083.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%s", str);
		analise(str);							
	}
	fclose(fp);
	return 0;
}
