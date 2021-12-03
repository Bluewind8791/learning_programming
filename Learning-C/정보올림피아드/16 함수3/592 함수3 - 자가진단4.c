#include <stdio.h>
#include <math.h>

int Recursive (int n) {
	if (n < 10) {
		return n*n;
	}
	return pow((n%10), 2) + Recursive(n/10);
}

int main()
{
	int n;
	
	scanf("%d", &n);
	
	printf("%d", Recursive(n));
	
	return 0;
}

/*
9자리 이하의 자연수를 입력받아 
재귀함수를 이용하여 

각 자리 숫자의 제곱의 합을 
출력하는 프로그램을 작성하시오.

( main()함수에 변수 하나, 
재귀함수에 매개변수 하나만을 사용할 수 있다.)
*/

