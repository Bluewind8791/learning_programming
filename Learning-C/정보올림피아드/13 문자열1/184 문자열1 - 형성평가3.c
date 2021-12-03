#include <stdio.h>
#include <string.h>

int main()
{
	char str[100]={0};
	scanf("%s", str);
	
	int i;
	for(i=0; i<strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		
		if ( (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9') )
		{
			printf("%c", str[i]);
		}
		else
		{
			continue;
		}		
	}

	return 0;
}

/*
100개 이하의 문자열을 입력받아서 

영문자와 숫자만 출력하되 
영문자는 모두 소문자로 

출력하는 프로그램을 작성하시오.
*/
