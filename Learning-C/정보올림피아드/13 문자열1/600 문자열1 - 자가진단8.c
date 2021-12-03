#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[100]={0};
	fgets(str, 100, stdin);
	
	int i;
	int wordcnt=0;
	
	for(i=0; i<=strlen(str); i++)
	{
		if(str[i]==' ' || str[i]=='\0')
		{
			wordcnt++;
		}
	}
	
	printf("%d",wordcnt);
	
	return 0;
}
/*
공백을 포함한 100글자 이하의 문자열을 입력받아 
문장을 이루는 단어의 개수를 
출력하는 프로그램을 작성하시오.

* 문장입력 할 때 gets()함수 대신 
fgets() 함수를 사용하세요.
*/
