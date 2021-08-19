#include <stdio.h>

int contaimpar(int a, int b){
	
	int i, maior, menor, soma = 0;
	if(a > b){
		maior = a;
		menor = b;
	}else{
		maior = b;
		menor = a;
	}

	for(i = maior; i > menor; i--){
	
		if((i % 2 != 0) && (i != maior)){
			soma = soma + i;
		}
	}

	return soma;	
}


int main(void)
{
	int x, y, soma;	
	scanf("%d", &x);
	scanf("%d", &y);
	soma = contaimpar(x, y);
	printf("%d\n", soma);
	return 0;
}
