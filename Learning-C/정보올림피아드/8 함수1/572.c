#include <stdio.h>

float Radius(float rad) {
	
	printf("%.2f", rad * rad * 3.14);
	
	return rad;
}

int main() {
	
	float r;
	scanf("%f", &r);
	Radius(r);
	
	return 0;
}

/*

반지름의 길이를 전달받아 
넓이를 출력하는 함수를 작성하고
 
반지름의 길이를 입력받아 함수를 호출하여 
넓이를 출력하는 프로그램을 작성하시오.

단, 원주율(π)은 3.14로 하고 반올림하여 소수 둘째자리까지 출력한다. 
 

원의 넓이 = 반지름(r) * 반지름(r)? * 원주율(π)?이다.


 */
