#include <stdio.h>

int main()
{
	int a[10];
	int i;
	int evenSum=0;
	int oddSum=0;
	
	for (i=0; i<10; i++)
	{
		scanf("%d", &a[i]);
		
		if ((i+1)%2==0)
		{
			evenSum= a[i] + evenSum;
		}
		else
		{
			oddSum= a[i] + oddSum;
		}
	}
	printf("odd : %d\neven : %d",oddSum,evenSum);	
	return 0;
}


/*
10���� ������ �Է¹޾� 

Ȧ�� ��° �Է¹��� ������ �հ� 
¦�� ��° �Է¹��� ������ ���� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
