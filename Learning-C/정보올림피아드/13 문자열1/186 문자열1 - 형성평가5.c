#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100] = {0};
	char str2[100] = {0};
	
	scanf("%s", str1);
	scanf("%s", str2);
	
	if (strlen(str1) >= strlen(str2))
	{
		printf("%d", strlen(str1));
	}
	
	else if (strlen(str2) > strlen(str1))
	{
		printf("%d", strlen(str2));
	}
	
	return 0;
}

/*
두 개의 단어를 입력받아서 
길이가 긴 단어의 문자 개수를 
출력하는 프로그램을 작성하시오.

단어의 길이는 100자 이하다.
*/
