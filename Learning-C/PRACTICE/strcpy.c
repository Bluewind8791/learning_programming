#include <stdio.h>
#include <string.h>

int main ()
{
	char str1[] = "abcde";
	char str2[10] = ;
	
	printf("str1�� ���ڿ� ���� : %d\n", strlen(str1));
	printf("str2�� ���ڿ� ���� : %d\n", strlen(str2));
	printf("%s ���ڿ� ���� : %d\n", "Hello World", strlen("Hello World"));
	
	if (strcmp(str1, str2) == 0)
	{
		printf("�� ���ڿ��� �����ϴ�.\n");
	}
	else if (strcmp(str1, str2) != 0)
	{
		printf("�� ���ڿ��� �ٸ��ϴ�.\n");
	}
	
	
	
	
	
	return 0;
}
