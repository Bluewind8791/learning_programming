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
10 이하의 자연수 n을 입력받고 
n개의 정수를 입력받아 

내림차순으로 정렬하여 
출력하는 프로그램을 작성하시오. 

(배열을 전달하는 함수를 이용한다.)
*/
