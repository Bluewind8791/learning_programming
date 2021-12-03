#include <stdio.h>

int main()
{
	int arr[10]={0,};
	int i;
	int pluscnt=0, minuscnt=0, zerocnt=0;
	for(i=0; i<10; i++)
	{
		scanf("%d",&arr[i]);
		if (arr[i]==0)
		{
			zerocnt++;
		}
		else if (arr[i]>0)
		{
			pluscnt++;
		}
		else
		{
			minuscnt++;
		}
	}
	
	printf("양수의 개수는 : %d\n", pluscnt);
	printf("음수의 개수는 : %d\n", minuscnt);
	printf("0의 개수는 : %d\n", zerocnt);
	
	return 0;
}

/*
정수값을 10개 입력받아서
그 중 양수의 개수와 음수의 개수
0의 개수를 출력하는 프로그램
*/ 
