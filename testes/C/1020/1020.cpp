#include <iostream>

using namespace std;

int main(void)
{
	int n, dd, mm, aa;
	cin >> n;
	aa = n / 365;
	n = n % 365;
	mm = n / 30;
	n = n % 30;
	dd = n;
	cout << aa <<" ano(s)\n"<< mm <<" mes(es)\n"<< dd << " dia(s)\n";	
	return 0;
}
