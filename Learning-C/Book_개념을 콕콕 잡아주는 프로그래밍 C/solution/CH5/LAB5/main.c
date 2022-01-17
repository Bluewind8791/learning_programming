
/* Lab05.c */

#include <stdio.h>

int main(void)
{
	char ch;
	
	while(1) {
		printf("영문자를 입력하세요 : ");
		scanf(" %c", &ch);
		
		if(ch == '.') {
			break;
		}
	
		printf("'%c'는 ",  ch);
		if(ch>='A' && ch<='Z') {
			printf("대문자 입니다.\n"); 
		} 
		else if(ch>='a' && ch<='z') {
			printf("소문자 입니다.\n"); 
		}
		else {
			printf("영문자가 아닙니다.\n"); 
		}
	}
	
	return 0;
}


