#include <stdio.h>
#include <string.h>

int main()
{
	char str[100]={0};
	scanf("%s", str);
	
	int i;
	for (i=0; i<strlen(str); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
	}
			
	for (i=0; i<strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			printf("%c", str[i]);
		}
	}
	
	return 0;
}

/*
���ڿ��� �Է¹޾� 
���ĺ� ���ڸ� ��� �빮�ڷ� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

���ڿ��� ���̴� 100�����̴�.
*/
