/**
split string C_version 02
comkiwer
use strtok() function
*/
#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	char word[100][100];
	int wcnt;
	int i, len;
	char *token;
	
	gets(str);
	len = strlen(str);
	
	strtok(str, "\r\n");
	// '\r'�Ǵ�'\n' ����
	
	token=strtok(str, " ");
	// str���ڿ� ���ۺ��� ������ �ƴ� ó�� ��ġ(*sp)�� ã��
	// �� ���ĵ����ϴ� ù ���� ��ġ(*ep)�� ã��
	// �� ���� '\0'�� �ϰ� sp�� ��ȯ�Ѵ�.

	while(token)
	{
		strcpy(word[wcnt++], token);
		token = strtok(NULL, " ");
		// strtok�Լ��� ù ���ڸ� NULL�� �ָ� ������ ã��
		// ep��ġ �������� ������ �ƴ� ó�� ��ġ�� ã�´�.
		// ������ �ƴ� ��ġ�� ã�� ���ϸ� NULL�� ���� �Ѵ�.
	}
	for(i=0; i<wcnt; i++) {
		printf("%s\n", word[i]);
	}
	
	return 0;
}

