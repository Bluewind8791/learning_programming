#include <stdio.h>

void RepeatPrint(int n) {
	printf("%d ", n);
	if(n <= 1) {
		return 1;
	}
	return RepeatPrint(n-1);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	RepeatPrint(n);
	
	return 0;
}

/*
자연수 N을 입력받아 
재귀함수를 이용하여 
N부터 1까지 차례대로 출력하는 
프로그램을 작성하시오. 

N은 50이하의 자연수이다.
*/
