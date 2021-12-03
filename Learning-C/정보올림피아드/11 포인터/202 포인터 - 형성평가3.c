#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int *p1 = NULL, *p2 = NULL, *p3 = NULL;

	p1 = (int*)malloc(sizeof(int));
	//memory allocation
	p2 = malloc(sizeof(int));
	p3 = malloc(sizeof(int));
	
	scanf("%d %d",&*p1, &*p2);
	
	*p3 = abs(*p1 - *p2);
	printf("%d", *p3);
	
	free(p1);
	free(p2);
	free(p3);
	
	return 0;
}

/*
세개의 포인터 변수를 선언하고
memory 공간을 확보하여
두 수를 입력받아

두 수의 차의 절대값을 저장한 후
출력하는 프로그램 
*/
