#include <stdio.h>

int main()
{
	int a[5];
	int i, sum=0;
	
	for (i=0;i<5;i++)
	{
		scanf("%d", &a[i]);
		if ((i+1)%2!=0)
		{
			sum = a[i] + sum;
		}
	}
	
	printf("%d",sum);
	
	return 0;
}


/*
5개의 정수를 입력받은 후 

첫 번째 세 번째 다섯 번째 
입력받은 정수의 합을 출력하는 
프로그램을 작성하시오.
*/
