#include <stdio.h>

int main(void){
	
	int i, cont = 0, num;
	for(i = 0; i < 5; i++)
	{		
		scanf("%d", &num);
		if(num % 2 == 0){
			cont++;
		}
	}
	
	printf("%d valores pares\n", cont);

	return 0;
}
