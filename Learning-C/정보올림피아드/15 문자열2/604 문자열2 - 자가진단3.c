#include <stdio.h>
#include <string.h>

int main()
{
	char word[10][20];
	char alpha;
	int i, j, len;
	
	for(i=0; i<10; i++)
	{
		scanf("%s", &word[i]);
	}
	scanf(" %c", &alpha);
	
	for(i=0; i<10; i++)
	{
		len = strlen(word[i]);
		if (word[i][len-1] == alpha)
		{
			printf("%s\n", word[i]);
		}		
	}
	
	return 0;
}

/*
20�� ������ ���ڷ� �̷���� 
10���� �ܾ�� 
�� ���� ���ڸ� �Է¹޾Ƽ� 

���������� �Է¹��� ���ڷ� ������ 
�ܾ ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
