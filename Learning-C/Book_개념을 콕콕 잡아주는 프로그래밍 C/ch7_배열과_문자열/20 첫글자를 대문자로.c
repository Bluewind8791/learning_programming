#include <stdio.h>
#include <string.h>

int main ()
{
	char str[100]={0,};
	gets(str);
	
	int i=0;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]>='a' && str[i]<='z')
		{
			str[i] = str[i]-32;
		}
	}
	
	printf(str);
	
	return 0;
}
/*
문자열을 입력받아 
각 단어의 
첫 글자를 대문자로 변경하는 프로그램 

#include <ctype.h>
if( islower(str[i]) )
	str[i] = toupper(str[i]);
*/
