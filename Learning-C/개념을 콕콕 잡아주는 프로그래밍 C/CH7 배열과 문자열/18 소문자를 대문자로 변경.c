#include <stdio.h>
#include <string.h>

int main()
{
	printf("���ڿ��� �Է��ϼ��� : ");
	char str[1000];
	gets(str);

	int i;
	for(i=0;i<strlen(str);i++)
	{
		str[i] = str[i] - 32;
	}
	printf("���� �� ���ڿ� : ");
	printf(str);
	
	return 0;
}

/*
���ڿ��� ��� �빮�ڷ� �����ϴ� ���α׷� 
*/
