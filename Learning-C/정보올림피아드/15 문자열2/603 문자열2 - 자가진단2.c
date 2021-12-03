#include <stdio.h>
#include <string.h>

/*
공백을 포함한 문장을 입력 받아서 
홀수 번째 단어를 
차례로 출력하는 프로그램을 작성하시오.

문장의 길이는 100자 이하이다.
*/

int main()
{
	char str[100];
	gets(str);
	
	char *p = strtok(str, " ");
	int word_cnt = 0;
	
	while(1)
	{
		if (p == NULL) {
			break;
		}
		word_cnt++;
		if (word_cnt % 2 != 0) {
			printf("%s\n", p);
		}
		p = strtok(NULL," ");
	}
	
	return 0;
 } 
 

 
 
 /*
int main()
{
	char str[100];	
	char word[100][100];
	int wcnt = 0;
	int i, len;
	char *token= strtok(str," ");

	gets(str);
	//scanf(" %s", str);
	//왜 scanf 쓰면 안되는지? 
	len = strlen(str);
	
	strtok(str, "\r\n");
	
	while(token)
	{
		strcpy(word[wcnt++], token);
		//여기에 token 왜 쓰는지 모르겠다 
		//strtok(대상문자열, 기준문자);
		//자른 문자열을 반환, 자를 문자열이 없으면 NULL 반환  
		 
		token = strtok(NULL, " ");
	}
	
	for(i=0; i<wcnt; i++) {
		if ((i+1)%2 != 0) {
			printf("%s\n", word[i]);
		}
	}
	
	return 0;
}
*/
 
 
 

