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
10개의 정수를 입력받아 

홀수 번째 입력받은 정수의 합과 
짝수 번째 입력받은 정수의 합을 
출력하는 프로그램을 작성하시오.
*/
