#include <stdio.h>

int main()
{
	char str[100] = {0,};
	gets(str);
	
	printf(str);
	printf(str);
	
	return 0;
}

/*
문자열을 입력받은 뒤 
그 문자열을 이어서 
두 번 출력하는 프로그램을 작성하시오.

문자열의 길이는 100이하이다.
*/
