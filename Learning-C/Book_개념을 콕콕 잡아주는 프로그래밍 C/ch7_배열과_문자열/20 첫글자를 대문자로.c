#include <stdio.h>
#include <string.h>

int main ()
{
	char str[100]={0,};
	gets(str);
	
	int i=0;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]>='a' && str[i]<='z')
		{
			str[i] = str[i]-32;
		}
	}
	
	printf(str);
	
	return 0;
}
/*
���ڿ��� �Է¹޾� 
�� �ܾ��� 
ù ���ڸ� �빮�ڷ� �����ϴ� ���α׷� 

#include <ctype.h>
if( islower(str[i]) )
	str[i] = toupper(str[i]);
*/
