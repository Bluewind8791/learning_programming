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
자료의 개수 7을 
매크로 상수로 정의하여 

자료의 개수만큼 정수를 입력받아 
입력받은 순서대로 
앞에서부터 마지막까지 가면서 
바로 뒤의 숫자와 비교하여 크면 교환한다. 

이러한 작업을 세 번만 반복한 후 

그 결과를 하나의 행에 
공백으로 구분하여 
출력하는 프로그램을 작성하시오.
*/
