#include <stdio.h>

int main()
{
	int num;
	int *p = &num;
	
	scanf("%d",&*p);
	
	int i;
	for (i=0;i<num;i++)
	{
		printf("*");
	}
	
	return 0;
}
/*
정수형 변수를 선언하고
포인터 변수를 사용하여
100 이하의 수를 입력받은 후
입력받은 수 만큼 '*'를 출력하는 프로그램
*/
