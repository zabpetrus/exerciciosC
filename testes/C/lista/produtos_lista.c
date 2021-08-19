#include <stdio.h>
#include <stdlib.h>

struct Produto{
	int codigo;
	double preco;
	struct Produto *proximo;
};

typedef struct tipo_produto{
	int codigo;
	double preco;
	struct tipo_produto *proximo;
} TProduto;

void inserir(TProduto **cabeca);
void listar(TProduto *cabeca);

int main(){
	TProduto *cabeca = NULL;
	TProduto *noatual;
	char q;
	do{
		printf("\n\nOpcoes:\nI -> para inserir novo produto;\nL -> para listar os produtos;\nS -> para sair \n:");
		scanf("%c", &q);
		switch(q){
			case 'i':case 'I': inserir(&cabeca); break;
			case 'l' : case 'L' : listar(cabeca); break;
			case 's' : case 'S' : break;
			default: printf("\n\nOpcao invalida");			
		}
		fflush(stdin);
	}while((q != 's') && (q != 'S'));
	
	
	noatual = cabeca;
	while(noatual != NULL){
		cabeca = noatual -> proximo;
		free(noatual);
		noatual = cabeca;
	}
}

void listar(TProduto *noatual){
	int i = 0;
	while(noatual != NULL){
		i++;
		printf("\n\nProduto numero %d\nCodigo: %d\nPreco:R$%.2lf", i, noatual->codigo, noatual -> preco);
		noatual = noatual->proximo;
	}
}

void inserir(TProduto **cabeca){
	TProduto *noatual, *novono;
	int cod;
	double preco;
	printf("\nCodigo do novo produto:" );
	scanf("%d", &cod);
	printf("\nPreco do produto: R$:" );
	scanf("%lf", &preco);
	if(*cabeca == NULL){
		*cabeca = (TProduto *) malloc(sizeof(TProduto));
		(*cabeca)->codigo = cod;
		(*cabeca)->preco = preco;
		(*cabeca)->proximo = NULL;
	}
	else{
		noatual = *cabeca;
		while(noatual->proximo != NULL)
			noatual = noatual->proximo;
		novono = (TProduto *) malloc(sizeof(TProduto));
		novono->codigo = cod;
		novono->preco = preco;
		novono->proximo = NULL;
		noatual->proximo = novono;
	}
	
}

