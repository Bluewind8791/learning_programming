# include <stdio.h>

int main()
{
	char ch[10] = {0,};
	int i;
	
	for (i=0;i<10;i++)
	{
		scanf(" %c",&ch[i]);
	}
	
	for (i=9;i>=0;i--)
	{
		printf("%c ",ch[i]);
	}
	
	return 0;
}

/*
		


10���� ���ڸ� �Է¹޾� 
���������� �Է¹��� ���ں��� 
ù ��° �Է¹��� ���ڱ��� 
���ʷ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
