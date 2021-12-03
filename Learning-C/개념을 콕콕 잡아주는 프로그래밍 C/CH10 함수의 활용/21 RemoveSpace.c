#include <stdio.h>
#include <string.h>

int RemoveSpace(char *str)
{
	int change = 0;
	int space_cnt = 0;
	
	for(int i=0; i<strlen(str); i++) {
		if (str[i] == ' ') {
			space_cnt++;
		}
		if (str[i] != ' ') {
			str[change] = str[i];
			change++;
		}
	}
	str[change] = '\0';
	return space_cnt;
}

int main()
{
	//char str[256]="C program to remove spaces in input string";
	char str[256];
	printf("문자열을 입력하세요 : ");
	gets(str);
	//printf(str);
	
	printf("\n\nSpace Count : %d\n", RemoveSpace(str));
	
	printf("\nAfter Deleting Space : ");
	printf(str);
	
	
	
	
	return 0;
}

/*
인자로 전달받은 문자열로 부터 
공백문자를 제거하는 RemoveSpace 함수 정의 

함수의 첫번째 인자로 전달되는 문자열은 
함수 안에서 사용도 되고 변경도 되므로 입출력 인자로 처리 

또한 함수는 제거된 공백문자의 개수를 리턴  
*/
