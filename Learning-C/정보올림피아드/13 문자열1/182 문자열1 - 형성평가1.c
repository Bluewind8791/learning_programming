#include <stdio.h>

int main()
{
	char ch1 = 0;
	char ch2 = 0;
	scanf(" %c %c", &ch1, &ch2);
	
	printf("%d\n", ch1 + ch2);
	
	if (ch1 > ch2)
	{
		printf("%d\n", ch1 - ch2);
	}
	else
	{
		printf("%d\n", ch2 - ch1);
	}
	
	return 0;
}

/*
영문자 두 개를 입력 받아서 
각각의 아스키코드의 
합과 차를 출력하는 프로그램을 작성하시오.
*/
