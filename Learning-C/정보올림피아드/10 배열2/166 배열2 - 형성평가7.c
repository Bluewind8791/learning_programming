#include <stdio.h>

int main()
{
	int st_Array[2][3] = {0,};
	int nd_Array[2][3] = {0,};
	int i,j;
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&st_Array[i][j]);
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&nd_Array[i][j]);
		}
	}
	
	//printf("first array\nsecond array\n");
	
	int t_Array[2][3]={0,};
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			t_Array[i][j]=nd_Array[i][j]*st_Array[i][j];
			printf("%d ", t_Array[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
/*
2행 3열 배열을 두 개 선언하여 
각각의 값을 입력 받은 후 

두 배열의 같은 위치끼리 곱하여 
새로운 배열에 저장한 후 
출력하는 프로그램을 작성하시오.
*/
