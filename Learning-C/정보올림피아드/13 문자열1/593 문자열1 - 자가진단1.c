#include <stdio.h>

int main()
{
	int ascii=0;
	
	while(1)
	{
		printf("ASCII code =? ");
		scanf("%d", &ascii);
	
		if (CharRange(ascii))
		{
			printf("%c\n", ascii);
		}
		else
		{
			break;
		}
	}
	
	return 0;
}

int CharRange (int ascii)
{
		if (ascii >= 33 && ascii <= 127)
		{
			return 1;
		}
				
		else
		{
			return 0;
		}
}

/*
33부터 127 까지의 숫자를 계속 입력받아 

입력받은 숫자의 아스키코드에 
해당하는 문자를 출력하다가 

범위를 벗어나는 입력이 들어오면 
종료하는 프로그램을 작성하시오.


*/
