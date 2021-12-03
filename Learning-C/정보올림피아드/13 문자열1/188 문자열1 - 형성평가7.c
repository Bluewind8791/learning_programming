#include <stdio.h>
#include <string.h>

int main()
{
	char str[100] = {0};
	fgets(str, sizeof(str), stdin);
	int i, index=1;
	
	printf("%d. ", index);
	index++;
	
	for (i=0; i<strlen(str); i++)
	{
		printf("%c", str[i]);
		
		if (str[i]==' ')
		{
			printf("\n%d. ", index);
			index++;
		}
	}

	return 0;
}

/*
공백을 포함한 문자열을 입력받아 
다음과 같이 분리하여 
번호와 함께 출력하는 프로그램을 작성하시오.

문자열의 길이는 100자 이하이다.

* 문장 입력할 때 gets()함수 대신 
fgets() 함수를 사용하세요.
*/
