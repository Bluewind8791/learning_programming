#include <stdio.h>

int main()
{
	int num;
	int *p = &num;
	
	scanf("%d",&*p);
	
	int i;
	for (i=0;i<num;i++)
	{
		printf("*");
	}
	
	return 0;
}
/*
������ ������ �����ϰ�
������ ������ ����Ͽ�
100 ������ ���� �Է¹��� ��
�Է¹��� �� ��ŭ '*'�� ����ϴ� ���α׷�
*/
