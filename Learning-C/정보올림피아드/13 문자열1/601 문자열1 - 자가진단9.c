#include <stdio.h>
#include <string.h>

int main()
{
	char str[100]={0};
	
	scanf("%s", str);
	int i, j;
	char temp = 0;
	
	for(i=0; i<strlen(str); i++)
	{
		for(j=0; j<strlen(str)-1; j++)
		{
			temp = str[j+1];
			str[j+1] = str[0];
			str[0] = temp;
		}		
		printf(str);
		printf("\n");
	}

	return 0;
}

/*
문자열을 입력 받아서 
문자수만큼 오른쪽으로 한 바퀴 회전하여 
출력하는 프로그램을 작성하시오. 

문자열의 길이는 100이하이다.
*/
