#include <stdio.h>
#include <string.h>

int main()
{
	char str1[20]={0};
	char str2[20]={0};
	
	scanf("%s", str1);
	scanf("%s", str2);
	
	printf("%d", strlen(str1)+strlen(str2));
	
	return 0;
}

/*
�� ���� ���ڿ��� �Է¹޾Ƽ� 
�� ���ڿ��� ������ ���� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�� ���ڿ��� ���̴� 20�� �̸��̴�.
*/
