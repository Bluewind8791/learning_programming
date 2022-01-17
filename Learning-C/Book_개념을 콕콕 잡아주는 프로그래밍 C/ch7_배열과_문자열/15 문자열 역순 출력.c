#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	int i, j;
	
	printf("문자열을 입력하시오 : ");
	gets(str);
	
	j = strlen(str);
	
	printf("역순 출력 : ");
	for(i=j-1; i>=0; i--)
	{
		printf("%c", str[i]);
	}
	
	return 0;
}

/*
입력받은 문자열에 대하여 
역순으로 된 문자열을 만들어서
출력하는 프로그램 
*/
