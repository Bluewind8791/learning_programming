#include <stdio.h>

int main ()
{
	int a[100];
	int i;
	int max=0;
	int min=999;
	
	for(i=0; ;i++)
	{
				scanf("%d",&a[i]);
		if (a[i]==999)
		{
			break;
		}
		if (max < a[i])
		{
			max = a[i];
		}
		if (min > a[i])
		{
			min = a[i];
		}
	}
	printf("max : %d\nmin : %d",max,min);
	return 0;
}

/*
세 자리 이하의 정수를 
차례로 입력 받다가 

999가 입력되면 
프로그램을 종료하고 
그 때까지 입력된 최대값과 최소값을 출력하는 
프로그램을 작성하시오.

입력받는 정수는 100개 이하이다.

*/
