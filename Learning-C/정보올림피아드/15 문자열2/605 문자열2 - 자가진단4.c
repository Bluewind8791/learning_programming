#include <stdio.h>
#include <string.h>

int main()
{
	char str[100] = {0,};
	strcpy(str, "Hong Gil Dong");
	
	printf(str);
	
	return 0;
}

/*
문자열을 선언하고 
다음과 같이 "Hong Gil Dong"이라는 
이름을 복사하여 저장한 후 
출력하는 프로그램을 작성하시오.
*/
