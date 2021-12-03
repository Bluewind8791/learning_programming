#include <stdio.h>
#include <math.h>

int Count (double fn1, double fn2)
{
	int i;
	int cnt = 0;
	for(i=(int)sqrt(fn2); i<(int)sqrt(fn1); i++)
	{
		cnt++;
	}
	if (sqrt(fn2) == (int)sqrt(fn2))
	{
		cnt++;
	}
	return cnt;
}

int main()
{
	double fn1, fn2;
	
	//fn1 = 12.0;
	//fn2 = 34.789;
	scanf("%lf %lf", &fn1, &fn2);
		
	if ( sqrt(fn1) > sqrt(fn2) )
	{
		printf("%d", Count(fn1, fn2));
	}
	else if ( sqrt(fn1) < sqrt(fn2) )
	{
		printf("%d", Count(fn2, fn1));
	}
	
	return 0;
}



/*
두 개의 실수를 입력받아 
각각의 제곱근을 구하고 

두 제곱근 사이에 존재하는 정수의 개수를 
출력하는 프로그램을 작성하시오.

단, 입력받는 두 실수는 양수이며 
두 제곱근 사이라는 말은 
두 제곱근을 포함한다.

작은 수의 경우 변환하기 전 
원래의 제곱근과 같다면 개수에 포함
*/
