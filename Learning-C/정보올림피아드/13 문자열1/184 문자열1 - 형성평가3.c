#include <stdio.h>
#include <string.h>

int main()
{
	char str[100]={0};
	scanf("%s", str);
	
	int i;
	for(i=0; i<strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		
		if ( (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9') )
		{
			printf("%c", str[i]);
		}
		else
		{
			continue;
		}		
	}

	return 0;
}

/*
100�� ������ ���ڿ��� �Է¹޾Ƽ� 

�����ڿ� ���ڸ� ����ϵ� 
�����ڴ� ��� �ҹ��ڷ� 

����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
