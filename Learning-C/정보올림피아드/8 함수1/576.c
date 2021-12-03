// 576 : 함수1 - 자가진단6

#include <stdio.h>

int Calculator (int n1, char cc, int n2) {
	if (cc == '+') {
		printf("%d + %d = %d", n1, n2, n1+n2);
	}
	else if ( cc == '-') {
		printf("%d - %d = %d", n1, n2, n1-n2);
	}
	else if ( cc == '*') {
		printf("%d * %d = %d", n1, n2, n1*n2);
	}
	else if ( cc == '/') {
		printf("%d / %d = %d", n1, n2, n1/n2);
	}
	else {
		printf("%d %c %d = 0", n1, cc, n2);
	}
}
//////////////////////////////////////////////////
int main() {
	
	int num1, num2, result;
	char calc;
	
	scanf(" %d", &num1);
	scanf(" %c", &calc);
	scanf(" %d", &num2);
	
	Calculator (num1, calc, num2);

	return 0;
}
