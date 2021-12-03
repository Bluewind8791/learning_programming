#include <stdio.h>

int main()
{
	int x1, x2;
	int *p1, *p2;
	p1 = &x1;
	p2 = &x2;
	
	scanf("%d %d", &*p1, &*p2);
	printf("%d + %d = %d\n", *p1, *p2, *p1 + *p2);
	printf("%d - %d = %d\n", *p1, *p2, *p1 - *p2);
	printf("%d * %d = %d\n", *p1, *p2, *p1 * *p2);
	printf("%d / %d = %d\n", *p1, *p2, *p1 / *p2);
	
	return 0;
}
/*
포인터 변수 두 개를 이용하여 
두 수를 입력받고 
사칙 연산을 수행하여 
출력하는 프로그램을 작성하시오.
*/
