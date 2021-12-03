#include <stdio.h>
#include <math.h>

int main ()
{
	int a[100];
	int i, sum=0, mcount=0;
	double avg;
	
	for(i=0;i<100;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]==0)
		{
			break;
		}
		else if (a[i] % 5 == 0)
		{
			mcount++;
			sum = a[i] + sum;
		}
	}
	avg = (double)sum/mcount;
	printf("Multiples of 5 : %d\n", mcount);
	printf("sum : %d\n", sum);
	printf("avg : %.1lf\n", (round(10*(avg)) )/10 );
	
	return 0;
}

/*
100 개 이하의 정수를 입력받다가 
0 이 입력되면 

그 때까지 입력된 정수 중 
5의 배수의 개수와 
합계 평균을 출력하는 
프로그램을 작성하시오.

평균은 소수점 이하 1자리까지 출력한다.

35 10 23 100 64 51 5 0
*/
