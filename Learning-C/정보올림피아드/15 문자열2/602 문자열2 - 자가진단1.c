#include <stdio.h>
#include <string.h>

int main()
{
	char str[5][30];
	int i;
	char temp[30];
	
	for(i=0; i<5; i++) {
		scanf("%s", &str[i]);
	}
	
	//역순 정렬  
	for(i=5-1; i>2; i--) {
		strcpy(temp, str[i]);
		strcpy(str[i], str[4-i]);
		strcpy(str[4-i], temp);
	}
	
	for(i=0; i<5; i++) {
		printf("%s\n", str[i]);
	}
	
	return 0;
}

/*
5개의 단어를 입력받아 
모든 단어를 입력받은 
역순으로 출력하는 프로그램을 작성하시오.

각 단어의 길이는 30이하이다.
*/
