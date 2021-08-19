#include <stdio.h>

int main(void){
	
	int i, pcont = 0, icont = 0, poscont = 0, negcont = 0, num;
	for(i = 0; i < 5; i++)
	{		
		scanf("%d", &num);
		
		if(num > 0)
		{
			poscont++;
		}
		
		if(num < 0)
		{
			negcont++;
		}
		
		if(num % 2 == 0){
			pcont++;
		}
		else
		{
			icont++;
		}
	}
	
	printf("%d valor(es) par(es)\n", pcont);
	printf("%d valor(es) impar(es)\n", icont);
	printf("%d valor(es) positivo(s)\n", poscont);
	printf("%d valor(es) negativo(s)\n", negcont);	

	return 0;
}
