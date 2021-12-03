/**
split string C_version 02
comkiwer
use strtok() function
*/
#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	char word[100][100];
	int wcnt;
	int i, len;
	char *token;
	
	gets(str);
	len = strlen(str);
	
	strtok(str, "\r\n");
	// '\r'또는'\n' 제거
	
	token=strtok(str, " ");
	// str문자열 시작부터 공백이 아닌 처음 위치(*sp)를 찾고
	// 그 이후등장하는 첫 공백 위치(*ep)를 찾아
	// 그 값을 '\0'로 하고 sp를 반환한다.

	while(token)
	{
		strcpy(word[wcnt++], token);
		token = strtok(NULL, " ");
		// strtok함수의 첫 인자를 NULL로 주면 이전에 찾은
		// ep위치 다음부터 공백이 아닌 처음 위치를 찾는다.
		// 공백이 아닌 위치를 찾지 못하면 NULL을 리턴 한다.
	}
	for(i=0; i<wcnt; i++) {
		printf("%s\n", word[i]);
	}
	
	return 0;
}

