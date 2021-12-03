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
//내림차순 
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
정수 N을 입력받고 
다시 N개의 정수를 입력받아 

내림차순으로 정렬하여 
출력하는 프로그램을 작성하시오.

(1 ≤ N ≤ 15, 입력과 출력, 
정렬은 모두 함수를 이용할 것)
*/
