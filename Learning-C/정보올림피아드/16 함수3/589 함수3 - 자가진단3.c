#include <stdio.h>

int GetFact (int n) {
	if (n <= 1) {
		return 1;
	}
	return n + GetFact(n - 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	printf("%d",GetFact(n));
	
	return 0;
}

/*
100 이하의 자연수 N을 입력받아 

재귀함수를 이용하여 
1부터 N까지의 
합을 구하는 프로그램을 작성하시오.
*/
