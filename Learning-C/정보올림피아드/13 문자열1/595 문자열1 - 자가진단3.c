#include <stdio.h>

int main()
{
	char str[100] = "Hong Gil Dong";
	
	int i;
	for(i=3; i<6+1; i++)
	{
		printf("%c",str[i]);
	}
	
	return 0;
}

/*
���ڿ��� ��Hong Gil Dong������ �ʱ�ȭ �� �� 
3������ 6�������� ���ڸ� ���ʷ� ����Ͻÿ�.
*/
