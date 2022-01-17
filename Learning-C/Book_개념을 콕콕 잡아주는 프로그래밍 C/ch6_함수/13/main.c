#include <stdio.h>

double Absolute (float num) {
	double abs;
	if (num >= 0) {
		abs = num;
	}
	if (num < 0) {
		abs = num * -1;
	}
	return abs;
}

int main(int argc, char *argv[]) {
	double n;
	scanf("%lf", &n);
	
	printf("%lf's absoulte value = %lf", n, Absolute (n));
	
	return 0;
}

/* 실수값을 인자로 받아서
절대값을 구하는
Absolute 함수를 정의하시오
*/ 
