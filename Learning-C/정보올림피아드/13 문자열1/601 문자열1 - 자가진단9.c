#include <stdio.h>
#include <string.h>

int main()
{
	char str[100]={0};
	
	scanf("%s", str);
	int i, j;
	char temp = 0;
	
	for(i=0; i<strlen(str); i++)
	{
		for(j=0; j<strlen(str)-1; j++)
		{
			temp = str[j+1];
			str[j+1] = str[0];
			str[0] = temp;
		}		
		printf(str);
		printf("\n");
	}

	return 0;
}

/*
���ڿ��� �Է� �޾Ƽ� 
���ڼ���ŭ ���������� �� ���� ȸ���Ͽ� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

���ڿ��� ���̴� 100�����̴�.
*/
