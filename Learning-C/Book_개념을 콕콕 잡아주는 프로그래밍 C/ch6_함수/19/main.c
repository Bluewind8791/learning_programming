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
	1. Description : x의 y승인 x^y를 구하는 함수.
	2. Function : int i(증가변수) ,double x, double y.
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
x의 y승인 x^y를 구하는 Power함수를 정의하시오
이때 x, y, x^y 모두 실수이다. 

*/

