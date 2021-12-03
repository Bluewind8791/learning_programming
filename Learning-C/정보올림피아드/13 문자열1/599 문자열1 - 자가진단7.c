#include <stdio.h>
#include <string.h>

int main()
{
	char str[100]={0};
	scanf("%s", str);
	
	int i;
	for (i=0; i<strlen(str); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
	}
			
	for (i=0; i<strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			printf("%c", str[i]);
		}
	}
	
	return 0;
}

/*
문자열을 입력받아 
알파벳 문자만 모두 대문자로 
출력하는 프로그램을 작성하시오.

문자열의 길이는 100이하이다.
*/
