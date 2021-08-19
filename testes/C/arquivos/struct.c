#include <stdio.h>

typedef struct cpf{
	int nm[9];
	int ver[2];
}CPF;

typedef struct tel{
	int cod;
	int numero[15];
}Telefone;


typedef struct agenda{
	int code;
	char nome[20];
	Telefone numero;
	CPF num;
	char email[20];
	int status;
}TAgenda;


