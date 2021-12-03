#include <stdio.h>

int main()
{
	char str[256]={0,};
	char *p = str;
	
	gets(str);
	
	int len = 0;
	
	while( *p != '\0' )
	{
		len++;
		p++;
	}
	
	printf("문자열의 길이 : %d\n", len);
	return 0;
}
/*
1. 문자 배열을 선언하고 문자열을 입력받아 저장한다
2. 문자 배열의 주소를 저장할 포인터 변수를 선언한다
3. 배열의 원소를 가르키는 포인터 변수와
반복문을 이용해서 문자 배열의 길이를 구한다 
*/
