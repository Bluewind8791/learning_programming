#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	int i, j;
	
	printf("���ڿ��� �Է��Ͻÿ� : ");
	gets(str);
	
	j = strlen(str);
	
	printf("���� ��� : ");
	for(i=j-1; i>=0; i--)
	{
		printf("%c", str[i]);
	}
	
	return 0;
}

/*
�Է¹��� ���ڿ��� ���Ͽ� 
�������� �� ���ڿ��� ����
����ϴ� ���α׷� 
*/
