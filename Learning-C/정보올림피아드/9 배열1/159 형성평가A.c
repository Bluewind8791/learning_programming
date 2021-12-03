#include <stdio.h>

int main()
{
	int n, i, j, max, temp=0;
	scanf("%d", &n);
	
	int a[n];
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for(i=0; i<n-1; i++)
	{
		max = i;
		for(j=i+1; j<n; j++)
		{
			if (a[max] < a[j])
			{
				max = j;
			}
		}
		temp = a[i];
		a[i] = a[max];
		a[max] = temp;
	}
	
	for(i=0; i<n; i++)
	{
		printf("%d\n", a[i]);
	}
	
	return 0;
}
/*
20 이하의 정수 n을 입력받고 

n명의 점수를 입력받아 

높은 점수부터 차례로 
출력하는 프로그램을 작성하시오

*/
