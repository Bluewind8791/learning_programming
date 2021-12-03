#include <stdio.h>
#include <math.h>

int main()
{
	int a[5]; //= {35, -20, 10, 0, 55};
	int i;
	int sum=0;
	
	for(i=0;i<5;i++)
	{
		scanf("%d", &a[i]);
		sum = abs(a[i]) + sum;
	}
	
	printf("%d", sum);
	
	return 0;
}

/*
5개의 정수를 입력받아 
각 정수의 절대값의 합을 
출력하는 프로그램을 작성하시오.
*/
