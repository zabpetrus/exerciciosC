#include <stdio.h>

int moo( int n )
{
	int p;
	if(n > 0)
	{
		p = 10 * (n % 2);
		return (p + moo(n / 2));
	}
}

int main(void)
{
	int p, n = 25;
	p = moo(25);
	printf("\nMoo: %d", p);
	return 0;
	
}
