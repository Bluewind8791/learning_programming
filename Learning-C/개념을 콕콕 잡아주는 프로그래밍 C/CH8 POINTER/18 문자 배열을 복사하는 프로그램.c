#include <stdio.h>

int main()
{
	char str[50]={0};
	gets(str);
	
	char strcpy[50]={0};
	char *p = str;
	
	int i;
	for (i=0; i<50; i++)
	{
		strcpy[i] = p[i];
	}
	
	printf(strcpy);
	
	return 0;
}

/*
���� �迭�� ���ڿ��� �Է¹޾� 
�� �ٸ� ���� �迭�� �����ϴ�
���α׷��� �ۼ��Ͻÿ�. 

��, ���ڿ��� �����Ҷ�
���� �迭�� ���Ҹ� ����Ű�� �����͸� �̿�
���̺귯�� �Լ� ��� X 
*/
