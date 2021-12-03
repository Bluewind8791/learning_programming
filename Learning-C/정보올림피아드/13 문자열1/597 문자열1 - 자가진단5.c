#include <stdio.h>
#include <string.h>

int main()
{
	char str1[20]={0};
	char str2[20]={0};
	
	scanf("%s", str1);
	scanf("%s", str2);
	
	printf("%d", strlen(str1)+strlen(str2));
	
	return 0;
}

/*
두 개의 문자열을 입력받아서 
두 문자열의 길이의 합을 
출력하는 프로그램을 작성하시오.

각 문자열의 길이는 20자 미만이다.
*/
