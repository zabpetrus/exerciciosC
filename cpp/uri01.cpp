#include <stdio.h>
/*
Leia 2 valores inteiros e armazene-os nas vari�veis A e B.
 Efetue a soma de A e B atribuindo o seu resultado na vari�vel X. 
 Imprima X conforme exemplo apresentado abaixo. N
 �o apresente mensagem alguma al�m daquilo que est� sendo especificado
 e n�o esque�a de imprimir o fim de linha ap�s o resultado, 
caso contr�rio, voc� receber� "Presentation Error".
*/
 
int main() {
 
    int a, b, x;
    scanf("%d", &a);
    scanf("%d", &b);
    x = a + b;
    printf("X = %d\0", x); 
    return 0;
}
