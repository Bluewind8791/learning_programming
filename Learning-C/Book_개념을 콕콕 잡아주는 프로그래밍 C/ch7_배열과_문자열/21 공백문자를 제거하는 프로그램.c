#include <stdio.h>
#include <string.h>

int main ()
{
	char str[100]={0,};
	gets(str);
		
	int i, j;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]==' ')
		{
			for(j=0;;j++)
			{
				str[i+j] = str[i+j+1];
				if(str[i+j]=='\0')
				{
					break;
				}
			}
		}
	}
	
	printf(str);
	
	return 0;
}
/*
���鹮�ڸ� ��� �����ϴ� ���α׷� 
*/
