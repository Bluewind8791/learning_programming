#include <stdio.h>

int main ()
{
	int a[100];
	int i, count=0;
	
	for (i=0; i<100; i++)
	{
		scanf("%d", &a[i]);
		count++;
		if (a[i]==0)
		{
			break;
		}
	}
	
	printf("%d\n", count-1);
	for (i=0; i<count-1; i++)
	{
		if (a[i]%2==0)
		{
			a[i] = a[i] / 2;
		}
		else
		{
			a[i] = a[i] * 2;
		}
		printf("%d ",a[i]);
	}
	
	return 0;
}
/*
정수를 입력받다가 
0 이 입력되면 
0 을 제외하고 
그 때까지 입력 받은 
개수를 출력한 후

입력받은 정수를 
차례로 출력하되 

그 수가 홀수이면 2배한 값을, 

짝수인 경우에는 2로 나눈 몫을 
출력하는 프로그램을 작성하시오.

입력되는 정수의 개수는 100개 이하이다. 




*/
