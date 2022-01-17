#include <stdio.h>

int main()
{
	int arr[5] = {10,20,30,40,50};
	int *p = NULL;
	int i;
	
	p = arr;
	for(i=0; i<5; i++)
	{
		printf("%d ", (*p+i));
		p++;
	}
	printf("\n");
	
	return 0;
}

/*
포인터로 배열에 접근하여 
배열의 원소를 1 증가시킨 후
출력하는 프로그램 
*/
