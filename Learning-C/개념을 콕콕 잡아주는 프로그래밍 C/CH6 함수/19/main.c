#include <stdio.h>

double Power(double x, double y);

int main() {
	double x, y;
	scanf("%lf %lf", &x, &y);
	printf("%.2lf ^ %.2lf = %.2lf", x, y, Power (x, y));
	
	return 0;
}

double Power (double x, double y) {
	/*
	1. Description : x�� y���� x^y�� ���ϴ� �Լ�.
	2. Function : int i(��������) ,double x, double y.
 	3. Return : double power
	*/
	int i;
	double power = 1;
	for(i=2; i<=y; i++) {
		power = x * x;
	}
	return power;
}


/*
x�� y���� x^y�� ���ϴ� Power�Լ��� �����Ͻÿ�
�̶� x, y, x^y ��� �Ǽ��̴�. 

*/

