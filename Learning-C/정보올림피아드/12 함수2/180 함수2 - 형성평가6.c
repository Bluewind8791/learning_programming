#include <stdio.h>
#define N 7

int main()
{
	int a[N];
	int i;
	for (i=0; i<N; i++)
	{
		scanf("%d", &a[i]);
	}
	
	int j, temp=0;
	for (i=0; i<3; i++)
	{
		for(j=0; j<N-1; j++)
		{
			if (a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
	for(i=0; i<N; i++)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
}

void BubbleSort(int a[])
{
	int i,j,temp=0;
	for(i=0;i<9;i++)
	{
		for(j=0;j<10-1;j++)
		{
			if(a[j] < a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}


/*
�ڷ��� ���� 7�� 
��ũ�� ����� �����Ͽ� 

�ڷ��� ������ŭ ������ �Է¹޾� 
�Է¹��� ������� 
�տ������� ���������� ���鼭 
�ٷ� ���� ���ڿ� ���Ͽ� ũ�� ��ȯ�Ѵ�. 

�̷��� �۾��� �� ���� �ݺ��� �� 

�� ����� �ϳ��� �࿡ 
�������� �����Ͽ� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
