#include <stdio.h>

#define SIZE 256

int RemoveSpace(char *str);

int main(void)
{
	char str1[SIZE];
	int count;
	
	printf("문자열을 입력하세요 : ");
	gets(str1);
	
	count = RemoveSpace(str1);
	
	printf("결과 문자열: %s\n", str1);
	printf("제거된 공백 문자 개수 : %d\n", count); 

	return 0;
}


int RemoveSpace(char *str)
{
	char strTemp[SIZE];
	int i, j, cnt = 0;
	
	for(i=0, j=0; str[i]!='\0'; i++) {
		if((str[i]!=' ')  && (str[i]!='\t') && (str[i]!='\v') &&
		   (str[i]!='\n') && (str[i]!='\f') && (str[i]!='\r')) {
			strTemp[j++] = str[i];	   
		}
		else {
			cnt++;
		}
	}
		
	for(i=0; i<j; i++) {
		str[i] = strTemp[i];
	}
	str[i] = '\0';
	
	return cnt;
}





