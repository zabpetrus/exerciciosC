#include <stdio.h>

typedef struct f{
	int cod;
	char nome[40];	
}Foo;

int achado(int n, Foo *ab){
	
	int i;
	for(i = 0; i < 10; i++){
		if(n == ab[i].cod){
			return 1;
		}
	}
	return 0;
}

void exibir( Foo *ab, int lim){
	int i;
	for(i = 0; i < lim; i++){
		printf("%d - %s\n", ab[i].cod, ab[i].nome);
	}	
}



int inserir( Foo *ab, int i){
		
	printf("Entre com o nome: ");	
	ab[i].cod = rand() % 100;
	fscanf(stdin, "%s", &ab[i].nome);
	fflush(stdin);
	return 0;	
}

int excluir(Foo *ab, int i){
	
	int n;
	printf("Entre com o codigo: ");	
	fscanf(stdin, "%d", &n);
	if(achado(n, ab)){
		
		printf("Encontrado e excluido!");
		
		
		return 0;
	}
	else{
		printf("Nao encontrado!");
		return 0;		
	}
	return 0;	
}

int mostrar( Foo *ab, int i ){
	
	if(i == 0){
	
		printf("\nSem dados\n");	
	}else
	{
		exibir(ab, i);
	}
	
	return 0;
}

int main(void){
	
	int i, f, fx;
	Foo ab[10];
	
	f = 0;
	i = 0;
	do{
		printf("\nEntre com uma opcao: ");
		printf("\n1- Inserir\n2- Excluir\n3- Exibir\n4- Sair\n\n");
		
		scanf("%d", &fx);
		switch(fx){
			
			case 1:
				printf("\n1 - Inserir\n\n");
				f = inserir(ab, i);
				//exibir(ab, i);
				i++;
				break;
				
			case 2:
				printf("\n2 - Excluir\n\n");
				f = excluir(ab, i);
				//exibir(ab, i);				
				break;		
				
			case 3:
				printf("\n3 - Exibir\n\n");
				f = mostrar(ab, i);
				break;
				
			case 4:
				printf("\n4 - Sair");
				f = 1;
				break;						
				
			default:
				printf("\nNao entendi... ");
				
		}
		
		
	}
	while(f == 0);
		
	return 0;
}
