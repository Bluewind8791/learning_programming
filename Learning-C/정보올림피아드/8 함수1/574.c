#include <stdio.h>

Calc_Max (num1, num2, num3) {
	int max;
	if (num1 > num2 && num1 > num3) {
		max = num1;
	}
	else if (num2 > num1 && num2 > num3) {
		max = num2;
	}
	else
		max = num3;
	printf("%d", max);
	return max;
}


int main(void) {
	int n1, n2, n3;
	scanf(" %d %d %d", &n1,&n2,&n3);
	
	Calc_Max (n1, n2, n3);
	
	return 0;
}
