#include <stdio.h>

int main(void)
{
	int i, n;
	scanf("%d",&n);
	for(i = 0; (i < 10000) && (i % n == 2); i++){
		printf("%d", i);
	}
	return 0;
}
