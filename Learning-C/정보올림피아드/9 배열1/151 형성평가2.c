#include <stdio.h>

int main()
{
	int a[5];
	int i, sum=0;
	
	for (i=0;i<5;i++)
	{
		scanf("%d", &a[i]);
		if ((i+1)%2!=0)
		{
			sum = a[i] + sum;
		}
	}
	
	printf("%d",sum);
	
	return 0;
}


/*
5���� ������ �Է¹��� �� 

ù ��° �� ��° �ټ� ��° 
�Է¹��� ������ ���� ����ϴ� 
���α׷��� �ۼ��Ͻÿ�.
*/
