#include <stdio.h>

int main ()
{
	char ch[6] = {'J', 'U', 'N', 'G', 'O', 'L'};
	char c;
	int i, count = -1;
	
	scanf(" %c", &c);
	
	for (i=0;i<6;i++)
	{
		if (c == ch[i])
		{
			count = i;
			break;
		}
	}
	if (count == -1)
	{
		printf("none");
	}
	else
	{
		printf("%d", count);		
	}
	
	return 0;
}

/*
6���� ���ڹ迭�� ����� 
{'J', 'U', 'N', 'G', 'O', 'L'} 
���� �ʱ�ȭ �� �� 

���� �� ���� �Է¹޾� 
�迭������ ��ġ�� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù ��° ��ġ�� 0���̸� 
�迭�� ���� ���ڰ� �ԷµǸ� 
"none" ��� �޽����� ����ϰ� 
������ ���α׷��� �ۼ��Ͻÿ�.

*/
