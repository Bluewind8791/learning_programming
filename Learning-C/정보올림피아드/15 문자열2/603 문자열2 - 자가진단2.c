#include <stdio.h>
#include <string.h>

/*
������ ������ ������ �Է� �޾Ƽ� 
Ȧ�� ��° �ܾ 
���ʷ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

������ ���̴� 100�� �����̴�.
*/

int main()
{
	char str[100];
	gets(str);
	
	char *p = strtok(str, " ");
	int word_cnt = 0;
	
	while(1)
	{
		if (p == NULL) {
			break;
		}
		word_cnt++;
		if (word_cnt % 2 != 0) {
			printf("%s\n", p);
		}
		p = strtok(NULL," ");
	}
	
	return 0;
 } 
 

 
 
 /*
int main()
{
	char str[100];	
	char word[100][100];
	int wcnt = 0;
	int i, len;
	char *token= strtok(str," ");

	gets(str);
	//scanf(" %s", str);
	//�� scanf ���� �ȵǴ���? 
	len = strlen(str);
	
	strtok(str, "\r\n");
	
	while(token)
	{
		strcpy(word[wcnt++], token);
		//���⿡ token �� ������ �𸣰ڴ� 
		//strtok(����ڿ�, ���ع���);
		//�ڸ� ���ڿ��� ��ȯ, �ڸ� ���ڿ��� ������ NULL ��ȯ  
		 
		token = strtok(NULL, " ");
	}
	
	for(i=0; i<wcnt; i++) {
		if ((i+1)%2 != 0) {
			printf("%s\n", word[i]);
		}
	}
	
	return 0;
}
*/
 
 
 

