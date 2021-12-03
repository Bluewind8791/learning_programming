#include <stdio.h>

int main()
{
	int a1[2][4]={0,};
	int a2[2][4]={0,};
	int i,j;
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&a1[i][j]);
		}
	}
		
	for(i=0;i<2;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&a2[i][j]);
		}
	}	
	
	printf("first array\nsecond array\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ",a1[i][j] * a2[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
2행 4열의 배열 두 개를 만들어서 
입력을 받고 

두 배열의 곱을 구하여 
출력하는 프로그램을 작성하시오.


*/
