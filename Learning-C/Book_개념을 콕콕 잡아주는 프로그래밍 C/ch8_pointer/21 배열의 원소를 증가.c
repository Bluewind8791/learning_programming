#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	int arr[10] = {0};
	int i;
	
	printf("[원본 배열] ");
	for(i=0; i<10; i++)
	{
		arr[i] = rand() % 100+1;
		printf("%3d", arr[i]);
	}
	printf("\n");
		
	int n;
	printf("증가량을 입력하세요 : ");
	scanf("%d", &n);
	
	int *p = arr;
	for(i=0; i<10; i++)
	{
		p[i] = p[i] + n;
	}
	
	printf("[증가 후 배열] ");
	for(i=0; i<10; i++)
	{
		printf("%3d", arr[i]);
	}
	
	return 0;
}

/*
정수 값을 하나 입력 받아서
정수형 배열의 모든 원소를 특정 값만큼
증가시키는 프로그램을 작성하시오

단 정수형 배열의 원소를 증가시킬 때
포인터를 이용하시오 
*/
