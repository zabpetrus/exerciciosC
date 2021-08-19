#include <stdio.h>
#include "struct.c"

void exibircpf( CPF num ){
	int i;
	for(i = 0; i < 11; i++){
		printf("%d", num.nm[i] );
	}
	printf("%d%d", num.ver[0], num.ver[1]);
}

void exibirtelefone( Telefone num ){
	int i;
	
	printf("(%2d) ", num.cod);
	for(i = 0; i < 15; i++)
	{
		printf("%d", num.numero[i] );
	}
}

void getcpf( CPF num ){
	int i;
	char temp[20];
	gets(temp);	
	sscanf(temp, "(%d) %d%d%d%d%d - %d%d%d%d", &num.ver, &num.nm[0], &num.nm[1],&num.nm[2],&num.nm[3],&num.nm[4],&num.nm[5],&num.nm[6],&num.nm[7],&num.nm[8], &num.nm[9] );
}






