#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[100]={0};
	fgets(str, 100, stdin);
	
	int i;
	int wordcnt=0;
	
	for(i=0; i<=strlen(str); i++)
	{
		if(str[i]==' ' || str[i]=='\0')
		{
			wordcnt++;
		}
	}
	
	printf("%d",wordcnt);
	
	return 0;
}
/*
������ ������ 100���� ������ ���ڿ��� �Է¹޾� 
������ �̷�� �ܾ��� ������ 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

* �����Է� �� �� gets()�Լ� ��� 
fgets() �Լ��� ����ϼ���.
*/
