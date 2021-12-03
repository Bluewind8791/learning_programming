#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int Pascal[11][11] = {{1}};
	
	int i,j;
	
	for (i=1; i<n+1; i++)
	{
		for (j=1; j<n+1; j++)
		{
			Pascal[i][j] = Pascal[i-1][j-1] + Pascal[i-1][j];
		}
	}
	
	for (i=n; i>0; i--)
	{
		for (j=n; j>0; j--)
		{
			if(Pascal[i][j]!=0)
			{
				printf("%d ", Pascal[i][j]);
			}
		}
		printf("\n");
	}
	
	
	return 0;
}
/*
행의 크기를 입력받아 
파스칼 삼각형을 작성하여 
마지막 행부터 첫 번째 행까지 
차례로 출력하는 프로그램을 작성하시오. 

행의 크기는 최대 10이다.
*/
