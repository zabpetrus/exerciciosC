#include <stdio.h>

int multiplos( int n, int v )
{
	if(v > 0)
	{
		if(v % n == 0)
		{
			printf("%d ", v);			
		}
		multiplos(n, v-1);
	}
}

int main(void)
{
	int n, v;
	
	printf("Entre com o numero e o valor: ");
	scanf("%d  %d", &n, &v);
	multiplos(n,v);
	return 0;
}
