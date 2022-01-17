#include <stdio.h>

int main(int argc, char *argv[]) {

	char ch;
	
	while(1)
	{
		printf("영문자를 입력하세요 : ");
		scanf(" %c", &ch);
	
		if (ch == '.')
			break;
			
		if ('A' <= ch && ch <= 'Z')
			{printf("'%c'는 대문자입니다.\n", ch);
				}	
		
		else if ('a' <= ch && ch <= 'z')
			{printf("'%c'는 소문자입니다.\n", ch);
			}
		
		else
			{
			printf("'%c'는 영문자가 아닙니다.\n", ch);
			}		
	}
	
	return 0;
}
