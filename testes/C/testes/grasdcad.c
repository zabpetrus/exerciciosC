#include <stdio.h>
#include <stdlib.h>

typedef struct foo{
	int num;
	struct foo *next;
}Foo;

void exibir( Foo *p )
{
	while(p != NULL)
	{
		printf("[%d][%p].......[%p]\n", p->num, p, p->next);
		p = p->next;
	}
	printf("\n");
}

int aux_validar( Foo *temp, int val )
{
	int found = 0;
	
	while(temp != NULL)
	{
		if(temp->num == val)
		{
			found = found + 1;
		}
		temp = temp->next;
	}
	
	if(found > 0)
	{
		return found;
	}
	
	return -1;	
}

void liberartudo( Foo *p )
{
	Foo* trash;
	while(p != NULL)
	{
		trash = p;		
		p = p->next;
		free(trash);
	}
}

//Cria um no no final
void criarno( Foo **p, int n )
{	
	Foo* aux, *temp;
	temp = *p;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}	
	aux = (Foo *) malloc(sizeof(Foo));
	aux->num = n;
	aux->next = temp->next;
	temp->next = aux;
	*p = temp;
}

void aux_criarno_final( Foo **p  )
{
	int novo;
	Foo *aux = *p;
	printf("Entre com um novo valor para inserir no final: ");
	scanf("%d", &novo);
	criarno(&aux, novo);
	printf("\nValor inserido com sucesso. \n");
	exibir(*p);
}

void aux_excluirno( Foo **p )
{
	int exc;
	Foo *aux = *p;
	printf("\nEntre com um numero para excluir: ");
	scanf("%d", &exc);
	if(excluirno(&aux, exc) == -1)
	{
		printf("Numero nao encontrado.");		
	}
	else
	{
		printf("\nNumero excluido com sucesso.\n");
		exibir(aux);
	}	
}

void aux_alterar( Foo **p )
{
	int old, found, novo;
	Foo *aux = *p;
	printf("\nEntre com o valor a ser alterado: ");
	scanf("%d", &old);
	
	if ( aux_validar( aux, old ) != -1)
	{
		printf("\nEntre com o novo valor a ser substituido: ");
		scanf("%d", &novo);
		
		if(alterarvalor(&aux, old, novo) == 2 )
		{
			printf("\nValor alterado com sucesso. \n");
			exibir(aux);
		}
		else
		{
			printf("\nHouve um erro.");
			liberartudo(aux);
			exit(1)	;
		}
	}
	else
	{
		printf("\nEste valor nao foi encontrado na lista\n");
	}	
}

//Inicializando Foo com varios valores
void inicializar( Foo **p , int tam)
{
	int i;
	Foo *temp, *aux;
	temp = (Foo *) malloc(sizeof(Foo));
	temp->num = 5;
	temp->next = NULL;
	aux = temp;
	
	for(i = 0; i <= tam; i++)
	{		
		criarno(&temp, (i * 10));			
	}
	
	*p = aux;
}

int alterarvalor( Foo **p, int old, int novo )
{
	Foo *aux = *p;
		
	while(aux != NULL)
	{
		if(old == aux->num)
		{
			aux->num = novo;
			aux = aux->next;				
		}
		aux = aux->next;
	}
	
	return 2;	
}

int excluirno( Foo **p, int num )
{
	int i = 0, found = 0;
	Foo *trash;
	Foo *aux1, *aux2;
	aux2 = aux1 = *p;
	while(aux1 != NULL)
	{
		if(aux1->num == num)
		{
			found = found + 1;
			i++;
		}
		aux1 = aux1->next;
	}
	
	if(found > 0)
	{
		while(aux2->next != NULL)
		{
			if(aux2->next->num == num){
				trash = aux2->next;
				aux2->next = aux2->next->next;
				free(trash);
				aux2 = aux2->next;
			}
			aux2 = aux2->next;
		}			
	}	
	else
	{
		return -1;
	}
}

void executarmenu( Foo **p )
{
	int num;
	printf("\n1 - Adicionar no\n2 - Excluir no\n3 - Alterar valor\nEscolha com a operacao: ");
	scanf("%d", &num);
	switch(num){
		case 1:
			aux_criarno_final( p );
			break;
		case 2:
			aux_excluirno( p );
			break;
		case 3:
			aux_alterar( p );
			break;			
		default:
			printf("Valor invalido. Tente de novo.\n");
			scanf("%d", &num);			
	}
}

int main(void)
{
	int tam, exc;
	Foo *p;
	printf("\nEntre com o valor inicial: ");
	scanf("%d", &tam);
	inicializar(&p, tam);
	exibir(p);	
	executarmenu(&p);
	liberartudo(p);	
	return 0;
}
