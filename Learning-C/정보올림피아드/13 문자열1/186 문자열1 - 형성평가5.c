#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100] = {0};
	char str2[100] = {0};
	
	scanf("%s", str1);
	scanf("%s", str2);
	
	if (strlen(str1) >= strlen(str2))
	{
		printf("%d", strlen(str1));
	}
	
	else if (strlen(str2) > strlen(str1))
	{
		printf("%d", strlen(str2));
	}
	
	return 0;
}

/*
�� ���� �ܾ �Է¹޾Ƽ� 
���̰� �� �ܾ��� ���� ������ 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�ܾ��� ���̴� 100�� ���ϴ�.
*/
