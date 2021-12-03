#include <stdio.h>
#include <string.h>

int main()
{
	printf("문자열을 입력하세요 : ");
	char str[1000];
	gets(str);

	int i;
	for(i=0;i<strlen(str);i++)
	{
		str[i] = str[i] - 32;
	}
	printf("변경 후 문자열 : ");
	printf(str);
	
	return 0;
}

/*
문자열을 모두 대문자로 변경하는 프로그램 
*/
