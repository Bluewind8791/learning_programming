#include <stdio.h>

void Scan(int a[], int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
}

void Print(int a[], int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
}
//�������� 
void Sort(int a[], int n)
{
	int i,j,temp;
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if (a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int i;
	int a[15];
	Scan(a, n);
	Sort(a, n);
	Print(a, n);
	
	return 0;
}

/*
���� N�� �Է¹ް� 
�ٽ� N���� ������ �Է¹޾� 

������������ �����Ͽ� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

(1 �� N �� 15, �Է°� ���, 
������ ��� �Լ��� �̿��� ��)
*/
