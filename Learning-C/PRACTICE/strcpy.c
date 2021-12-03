#include <stdio.h>
#include <string.h>

int main ()
{
	char str1[] = "abcde";
	char str2[10] = ;
	
	printf("str1의 문자열 길이 : %d\n", strlen(str1));
	printf("str2의 문자열 길이 : %d\n", strlen(str2));
	printf("%s 문자열 길이 : %d\n", "Hello World", strlen("Hello World"));
	
	if (strcmp(str1, str2) == 0)
	{
		printf("두 문자열이 같습니다.\n");
	}
	else if (strcmp(str1, str2) != 0)
	{
		printf("두 문자열이 다릅니다.\n");
	}
	
	
	
	
	
	return 0;
}
