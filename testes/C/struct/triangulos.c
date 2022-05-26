/* Considerando a estrutura: struct Ponto{ int x; int y } para representar um 
ponto em um plano cartesiano, implemente:

a) uma funcao que, dados os pontos X e Y, retorne a �rea do ret�ngulo
definido por x e y. O ponto X informa as coordenadas do v�rtice superior
mais � esquerda do ret�ngulo e o ponto Y, as coordenadas do v�rtice inferior
mais a direita

b) uma fun��o que, dados os pontos P, C e  um float R, verifique se o ponto
P se encontra no interior, sobre ou fora da circunfer�ncia de
centro C e raio R

c) uma fun��o que, dados tr�s pontos x, y e z:
I) Verifique se os tr�s pontos formam um tri�ngulo;
II) Classificar o poss�vel tri�ngulo em equil�tero, is�sceles e escaleno;
*/

#include <stdio.h>
#include <math.h>

typedef struct ponto{
	int x;
	int y;	
}Ponto;

typedef struct area{
	Ponto X;
	Ponto Y;
	double area;	
}PArea;

typedef struct circunscricao{
	Ponto P;
	Ponto C;
	float R;	
}PCirc;

typedef struct triangulo{
	Ponto x;
	Ponto y;
	Ponto z;	
}PTri;

double distanciaDP( Ponto a, Ponto b){
	
	
}


double area( Ponto x, Ponto y ){
	
	int xt, yt;
	xt = abs( y.x - x.x );
	yt = abs( y.y - x.y );
	return xt * yt;
}

int verifica_circunscricao( Ponto P, Ponto C, float R ){
	
	double dpo, difx, dify, raio;
	raio = (double) R;
	
	difx = P.x - C.x;
	dify = P.y - C.y;
	dpo = sqrt( pow(difx, 2) + pow(dify, 2));
	
	if(dpo == raio){
		
		return 1; // ponto pertence ao circulo
	}
	
	if(dpo < raio){	
		
		return 2; // dentro do circulo
		
	}
	
	return 0; // fora do circulo
}

void verificar_triangulo( Ponto x, Ponto y, Ponto z){
	
	
}


int main(void){
	
	
	
	
}


