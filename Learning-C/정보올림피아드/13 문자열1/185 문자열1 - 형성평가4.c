#include <stdio.h>
#include <string.h>
int main()
{
	char word[100]={0};
	char ch=0;
	
	scanf("%s", word);
	scanf(" %c", &ch);
	
	int i;
	int cnt=0;
	
	for(i=0; i<100; i++)
	{
		if(word[i] != ch)
		{
			if (word[i] == '\0')
			{
				printf("No");
				break;
			}
			cnt++;
		}
		
		else if (word[i] == ch)
		{
			printf("%d", cnt);
			break;
		}
	}
	
	return 0;
}
/*
�ܾ�� ���� �� ���� �Է¹޾Ƽ� 
�ܾ�� �Է¹��� ���ڿ� 
���� ���ڸ� ã�Ƽ� 
�� ��ġ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�ܾ�� ù ��° ������ ��ġ�� 0���� �ϰ� 
ã�� ���ڰ� ���� ���� ���� 
ó�� ������ ��ġ�� ����Ѵ�.

���� ã�� ���ڰ� ���� ���� 
"No"��� ����Ѵ�. 
��ҹ��ڴ� �����Ǹ� �ܾ�� 100�� �����̴�.

*/
