#include <stdio.h>

int main()
{
	char ch1 = 0;
	char ch2 = 0;
	scanf(" %c %c", &ch1, &ch2);
	
	printf("%d\n", ch1 + ch2);
	
	if (ch1 > ch2)
	{
		printf("%d\n", ch1 - ch2);
	}
	else
	{
		printf("%d\n", ch2 - ch1);
	}
	
	return 0;
}

/*
������ �� ���� �Է� �޾Ƽ� 
������ �ƽ�Ű�ڵ��� 
�հ� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
