#include <stdio.h>

void RepeatPrint(int n) {
	printf("recursive\n");
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
20 이하의 자연수 N을 입력받아 

재귀함수를 이용해서 

문자열 “recursive”를 

N번 출력하는 프로그램을 작성하시오.
*/
