#include <stdio.h>
#include <stdlib.h>

int validaCpf( int *vet ){
	
	int i, j, size = 11, pd, sd, soma = 0, soma2 = 0, verif1 = 0, verif2 = 0;
	
	
	if(vet[0] != 0){
		
		for(i = 0, j = 10; i < size-2; i++, j--){		
			soma = soma + vet[i] * j;		
		}	
		pd = (soma * 10) % 11;
		if(pd == 10) pd = 0;
		
		if(pd==vet[9]){
			verif1 = 1;
		}	
			
		for(i = 0, j = 11; i < size-1; i++, j--){		
			soma2 = soma2 + vet[i] * j;		
		}	
		
		sd = (soma2 * 10) % 11;
		if(sd == 10) sd = 0;
		
		if(sd==vet[10]){
			verif2 = 1;
		}		
	}
	else{
		
		for(i = 0, j = 10; i < size-2; i++, j--){		
			soma = soma + vet[i] * j;		
		}	
		pd = (soma * 10) % 11;
		
		if(pd == 10) pd = 0;
		
		if(pd==vet[9]){
			verif1 = 1;
		}	
			
		for(i = 0, j = 11; i < size-1; i++, j--){		
			soma2 = soma2 + vet[i] * j;		
		}	
		
		sd = (soma2 * 10) % 11;
		if(sd == 10) sd = 0;
		
		
		if(sd==vet[10]){
			verif2 = 1;
		}
		
	}
	
	if(verif1 == 1 && verif2 == 1){
		return 1;
	}
	
	return 0;
}


