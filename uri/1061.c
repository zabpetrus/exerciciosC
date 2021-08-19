#include <stdio.h>


void calcular(int d1, int h1, int m1, int s1, int d2, int h2, int m2, int s2){

	int ss, mm, hh, dd, addm = 0, addh = 0, addd = 0;
	
	dd = d2 - d1;
	hh = h2 - h1;
	mm = m2 - m1;
	ss = s2 - s1;
	
	if(ss < 0){
		ss = 60 + ss;
		mm = mm - 1;
	}
	
	if(mm < 0)
	{
		mm = 60 + mm;
		hh = hh - 1;		
	}
	
	if(hh < 0){
		hh = 24 + hh;
		dd = dd - 1;
	}	
	
	printf("%d dia(s)\n", dd);
	printf("%d hora(s)\n", hh);
	printf("%d minuto(s)\n", mm);
	printf("%d segundo(s)\n", ss);
}

int main(void)
{
	int d1, h1, m1, s1;
	int d2, h2, m2, s2;
	
	char lp1[10], lp2[10];
	scanf("%s %d", lp1, &d1);
	scanf("%d : %d : %d", &h1, &m1, &s1);	
	scanf("%s %d", lp2, &d2);
	scanf("%d : %d : %d", &h2, &m2, &s2);
	
	calcular(d1, h1, m1, s1, d2, h2, m2, s2);
	return 0;
}
