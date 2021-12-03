// 577 : 함수1 - 자가진단7

#include <stdio.h>
	
int Function (int *n1, int *n2) {
	if (*n1 > *n2) {
		*n1 = *n1 / 2;
		*n2 = *n2 * 2;
	}
	else {
		*n1 = *n1 * 2;
		*n2 = *n2 / 2;
	}
}

int main(void) {
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	Function (&num1, &num2);
	printf("%d %d", num1, num2);
	return 0;
}

/*
서로 다른 두 개의 정수가 주어진다.

두 정수를 입력받아 
큰 수는 2로 나눈 몫을 저장하고 
작은 수는 2를 곱하여 저장한 후 
출력하는 프로그램을 작성하시오.

(참조에 의한 호출을 이용한 함수를 작성하여 
값을 수정하고 출력은 메인함수에서 한다.)

*/
