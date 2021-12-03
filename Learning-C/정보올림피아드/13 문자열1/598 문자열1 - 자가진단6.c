#include <stdio.h>

int main()
{
	char ch;
	
	while(1)
	{
		scanf(" %c", &ch);
		
		if (ch >= 'A' && ch <= 'Z')
		{
			printf("%c\n", ch);
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			printf("%c\n", ch);
		}
		else if (ch >= 48 && ch <= 57)
		{
			printf("%d\n", ch);
		}
		else
		{
			break;
		}
	}
	
	return 0;
}

/*
문자를 입력받아 

알파벳 문자인 경우에는 
그대로 출력하고 

숫자인 경우는 아스키코드값을 
출력하는 작업을 반복하다가 

기타의 문자가 입력되면 
종료하는 프로그램을 작성하시오.


*/
