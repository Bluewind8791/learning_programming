#include <stdio.h>

int main()
{
	char str[50]={0};
	gets(str);
	
	char strcpy[50]={0};
	char *p = str;
	
	int i;
	for (i=0; i<50; i++)
	{
		strcpy[i] = p[i];
	}
	
	printf(strcpy);
	
	return 0;
}

/*
문자 배열에 문자열을 입력받아 
또 다른 문자 배열로 복사하는
프로그램을 작성하시오. 

단, 문자열을 복사할때
문자 배열의 원소를 가르키는 포인터를 이용
라이브러리 함수 사용 X 
*/
