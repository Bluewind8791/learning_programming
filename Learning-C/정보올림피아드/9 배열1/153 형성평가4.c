#include <stdio.h>

int main ()
{
	int a[100];
	int i, count=0;
	
	for (i=0;i<100;i++)
	{
		scanf("%d",&a[i]);
		count = i+1;
		if (a[i]==-1)
		{
			break;
		}
	}
	if (count < 4)
	{
		for (i=0;i<count-1;i++)
		{
			printf("%d ",a[i]);
		}
	}
	else
	{
		printf("%d %d %d",a[count-4],a[count-3],a[count-2]);
	}
	
	return 0;
}

/*
100개의 정수를 입력받을 수 있는 배열을 선언한 후
 
정수를 차례로 입력 받다가 
-1이 입력되면 입력을 중단하고 

-1을 제외한 
마지막 세 개의 정수를 출력하는 
프로그램을 작성하시오. 

(입력받은 정수가 -1을 제외하고 
3개 미만일 경우에는 
-1을 제외하고 
입력받은 정수를 모두 출력한다.)

*/
