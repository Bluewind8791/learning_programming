#include <stdio.h>
#define N 10

int main ()
{
	int arr[N];
	int i,j,temp=0;
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
		
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[j];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
		
	
	
	for (i=0;i<N;i++) 
	{
		printf("%d ",arr[i]);
	}
	
	return 0;
}

/*
 563 : 배열1 - 자가진단9
10개의 정수를 입력받아 배열에 저장한 후
내림차순으로 정렬하여 출력하시오.

*/
