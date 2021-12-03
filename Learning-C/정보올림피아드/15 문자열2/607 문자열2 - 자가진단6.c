#include <stdio.h>
#include <string.h>

int main()
{
	char str1[20]={0}, str2[20]={0};
	scanf("%s %s",str1, str2);
	
	char strplus[3] = {str1[0],str1[1]};
	
	strncpy(str2, str1, 2);
	strcat(str2, strplus);
	
	printf(str2);
	
	return 0;
}

/*
20자 이하인 두 개의 문자열을 입력받아 
첫 번째 문자열의 앞부분 두자를 
두 번째 문자열의 앞부분에 복사하고 

다시 뒷부분에 이어 붙여서 
저장한 후 

두 번째 문자열을 
출력하는 프로그램을 작성하시오.
*/
