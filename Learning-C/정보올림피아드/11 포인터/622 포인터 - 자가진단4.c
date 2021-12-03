#include <stdio.h>

int main()
{
	int array[5];
	int *PointerArray = array;
	
	
	int i;
	for(i=0;i<5;i++)
	{
		scanf("%d", (PointerArray+i));
	}
	
	for(i=0;i<5;i++)
	{
		if ( (i+1) % 2 != 0)
		{
			printf("%d ", *(PointerArray+i));
		}
	}
	
	return 0;
}

/*
5개짜리 정수형 배열을 선언하고 
포인터 변수에 저장한 후 

포인터 변수를 이용하여 입력을 받은 후 
홀수번째 입력값을 출력하는 프로그램을 작성하시오.
*/
