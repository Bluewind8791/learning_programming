#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int i;
	int pow = 2;
	

	for(i=2; i<=n; i++)
	{
		pow = pow * 2;
	}	
	
	printf("%d", pow );
	
	return 0;
}

/*
정수 n을 입력받아 
2^n의 값을 출력하는 
프로그램을 작성하시오. 
(1 ≤ n ≤ 20)
*/
