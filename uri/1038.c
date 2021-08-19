#include <stdio.h>

double lunchValue( int cod, int qte )
{
	switch(cod)
	{
		case 1:
			return (qte * 4.0);
			break;
		
		case 2:
			return (qte * 4.5);
			break;
			
		case 3:
			return (qte * 5.0);
			break;
			
		case 4:
			return (qte * 2.0);
			break;
		
		case 5:
			return (qte * 1.5);
			break;
			
		default:
			return 0;	
		
	}
}

int main(void)
{
	int cod, qte;
	scanf("%d  %d", &cod, &qte);
	printf("Total: R$ %.2lf\n", lunchValue(cod, qte) );
	return 0;
}
