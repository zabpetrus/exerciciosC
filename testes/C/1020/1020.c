#include <stdio.h>


int main(void)
{
	int n, dd, mm, aa;
	scanf("%d", &n);
	aa = n / 365;
	n = n % 365;
	mm = n / 30;
	n = n % 30;
	dd = n;
	printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", aa, mm, dd);	
	return 0;
}
