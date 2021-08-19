#include <stdio.h>

double media( double n1, double n2, double n3, double n4 )
{
	double temp =  ((n1 * 2.0) + (n2 * 3.0) + (n3 * 4.0) + (n4 * 1.0)) / (2.0 + 3.0 + 4.0 + 1.0);
	return temp;
}

double recalcularmedia( double media, double nota )
{
	return ((media + nota) / 2.0);
}

void calcularmedia( double media )
{
	double notaexame, notarecalculada;
	
	if(media >= 7.0)
	{
		printf("Media: %.1lf\n", media);
		printf("Aluno aprovado.\n");
	}
	else
	{
		if(media >= 5.0 && media < 7.0)
		{
			printf("Media: %.1lf\n", media);
			printf("Aluno em exame.\n");
			
			printf("Nota do exame: ");
			scanf("%lf", &notaexame);
			
			notarecalculada = recalcularmedia(media, notaexame);
			
			if(notarecalculada >= 5.0)
			{				
				printf("Aluno aprovado.\n");
				printf("Media final: %.1lf\n", notarecalculada);			
			}
			else
			{				
				printf("Aluno reprovado.\n");
				printf("Media final: %.1lf\n", notarecalculada);			
			}
		}
		else
		{
			printf("Media: %.1lf\n", media);
			printf("Aluno reprovado.\n");
		}
	}
		
}

int main(void)
{
	double n1, n2, n3, n4, media_aluno;
	scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
	media_aluno = media(n1, n2, n3, n4);
	calcularmedia(media_aluno);
	return 0;	
}
