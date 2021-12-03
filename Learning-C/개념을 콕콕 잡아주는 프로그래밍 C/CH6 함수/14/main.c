#include <stdio.h>

int Round ();
	
int main(int argc, char *argv[]) {
	double n;
	while(1) {
		scanf("%lf", &n);
		if (n == 0) {
			return;
		}
		printf("Round value = %d\n", Round(n) );
	}
	return 0;
}

int Round (double num) {
	int round;		//return value
	if (num > 0) {
		if ( (num - (int)num) + 0.5 >= 1 ) {	
			round = num + 1;
		} 
		else {
			round = (int)num;
		} 
	}
	else if (num < 0) {
		if ( (num + (int)num) - 0.5 >= -1 ) {	
			round = num - 1;
		}
		else {
			round = (unsigned int)num;
		}
	}
	return round;
}


/* 실수 값을 인자로 받아서
소수 첫째 자리에서 반올림한 정수값을 리턴하는
Round 함수를 정의하라.

반올림함수 Round는 양수일때와 음수일때 모두 동작

예를들어
1.2는 1을
1.7은 2를 리턴

-1.2는 -1을
-1.7은 -2를 리턴
*/ 
