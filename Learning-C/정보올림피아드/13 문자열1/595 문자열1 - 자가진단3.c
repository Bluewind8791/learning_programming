#include <stdio.h>

int main()
{
	char str[100] = "Hong Gil Dong";
	
	int i;
	for(i=3; i<6+1; i++)
	{
		printf("%c",str[i]);
	}
	
	return 0;
}

/*
문자열을 “Hong Gil Dong”으로 초기화 한 후 
3번부터 6번까지의 문자를 차례로 출력하시오.
*/
