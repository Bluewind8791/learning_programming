#include <stdio.h>

int FindStrLen(char *str);

int main()
{
	char str[100]={0};
	char *p = str;
	int i, len;
	char temp;
	
	gets(p);
	
	len = FindStrLen(p);
	printf("String Length : %d\n", len);
	
	for(i=0, temp=0; i<len/2; i++)
	{
		temp = p[i];
		p[i] = p[len-i-1];
		p[len-i-1] = temp;
	}
	
	printf(str);
	
	return 0;
}

int FindStrLen(char *str)
{
	int i;
	int len = 0;
	for (i=0; ; i++)
	{
		if (str[i] == '\0') {
			break;
		}
		len++;
	}
	return len;
}


/*
입력받은 문자열을 역순으로 만드는 프로그램.
단 문자열을 역순으로 만들때 포인터 사용. 
*/
