#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int array[n];
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d",&array[i]);
	}
	
	int j;
	int temp=0;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if ( array[i] < array[j] )
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	
	for(i=0; i<n; i++)
	{
		printf("%d ",array[i]);
	}
	
	
	return 0;
}

/*
10 ������ �ڿ��� n�� �Է¹ް� 
n���� ������ �Է¹޾� 

������������ �����Ͽ� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

(�迭�� �����ϴ� �Լ��� �̿��Ѵ�.)
*/
