#include <stdio.h>

double media( double n1, double n2, double n3, double n4 )
{
	double temp =  ((n1 * 2.0) + (n2 * 3.0) + (n3 * 4.0) + (n4 * 1.0)) / (2.0 + 3.0 + 4.0 + 1.0);
	return temp;
}

double recuperacao( double media, double teste )
{
	return ((media + teste) / 2.0);
}

int main(void)
{
	double n1, n2, n3, n4, media_aluno, teste, media_final;
	scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
	media_aluno = media(n1, n2, n3, n4);
	
	if(media_aluno >= 7.0)
	{
		printf("Media: %.1lf\nAluno aprovado.\n", media_aluno);
	}
	else
	{
		if(media_aluno < 5.0)
		{
			printf("Media: %.1lf\nAluno reprovado.\n", media_aluno);
		}
		else
		{
			printf("Media: %.1lf\nAluno em exame.\n", media_aluno);
			scanf("%lf", &teste);
			
			media_final = recuperacao(media_aluno, teste);
			printf("Nota do exame: %.1lf\n", teste);
			
			if(media_final >= 5.0)
			{
				printf("Aluno aprovado.\nMedia final: %.1lf\n", media_final);
			}
			else
			{
				printf("Aluno reprovado.\nMedia final: %.1lf\n", media_final);
			}
		}
	}
	
	return 0;
}
