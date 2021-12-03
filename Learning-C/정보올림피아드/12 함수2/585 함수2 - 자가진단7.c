#include <stdio.h>

int main()
{
	int a[10]={0,};
	int i, j, k;
	int temp = 0;
	
	for(i=0;i<10;i++)
	{
		scanf("%d", &a[i]);
	}
		
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
		
		for(k=0;k<10;k++)
		{
			printf("%d ", a[k]);
		}
		printf("\n");
	}


	return 0;
}
/*
10개의 정수를 입력받아 
버블정렬로 내림차순 정렬을 하면서 

하나의 단계가 끝날 때마다 
그 정렬결과를 
출력하는 프로그램을 작성하시오.
*/
