#include <stdio.h>

int main(void){
	
	int i, num, cont= 0;
	scanf("%d", &num);
	while(cont < 6){
				
		if(num % 2 != 0)
		{
			printf("%d\n", num);
			cont++;
		}
		num = num + 1;		
	}
	return 0;
	
}
