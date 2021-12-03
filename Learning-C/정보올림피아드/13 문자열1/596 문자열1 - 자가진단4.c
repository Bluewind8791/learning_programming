#include <stdio.h>
#include <string.h>

int main()
{
	char str[100] = {0};
	int n;
	
	scanf("%s %d",str, &n);
	
	int i;
	int len;
	len = strlen(str);
	
	if (n >= len)
	{
		for (i=len-1; i>=0; i--)
		{
			printf("%c", str[i]);
		}
	}
	
	else
	{
		for (i=len-1; i>=len-n; i--)
		{
			printf("%c", str[i]);
		}
	}
	
	return 0;
}

/*
문자열을 입력받고 
정수를 입력 받아서 

문자열의 맨 뒤부터 
정수만큼 출력하는 프로그램을 작성하시오.


 만약 입력받은 정수가 
 문자열의 길이보다 크다면 
 맨 뒤부터 맨 처음까지 모두 출력한다.


(문자열 길이는 최대 100자 이하이다. )
*/

