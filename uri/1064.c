#include <stdio.h>

int main(void){
	int i, cont = 0;
	double num, soma = 0;
	for(i = 0; i < 6; i++)
	{		
		scanf("%lf", &num);
		if(num > 0){
			soma = soma + num;
			cont++;
		}
	}
	
	printf("%d valores positivos\n", cont);
	printf("%.1lf\n", soma/cont);
	return 0;
}
