#include <stdio.h>
#include <string.h>

int main()
{
	char str[100] = {0};
	scanf("%s", str);
	
	int i;
	for(i=0; i<5; i++)
	{
		printf("%c", str[i]);
	}
	
	
	return 0;
}

/*
5�� �̻� 100�� ������ 
���ڷ� �� �ܾ �Է¹��� �� 
�տ������� 5�ڸ� ����ϴ� 
���α׷��� �ۼ��Ͻÿ�.

*/
