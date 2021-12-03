#include <stdio.h>

int main()
{
	int a[4][3] = 
	{{3, 5, 9}, {2, 11, 5}, {8, 30, 10}, {22, 5, 1}};
	
	int i, j;
	int TotalSum = 0;
	
	for (i=0; i<4; i++)
	{
		for (j=0; j<3; j++)
		{
			printf("%d ", a[i][j]);
			TotalSum = a[i][j] + TotalSum;
		}
		printf("\n");
	}
	printf("%d", TotalSum);
	
	
	return 0;
}

/*
4행 3열의 배열을 선언하고 

아래의 값으로 초기화 한 후 
{{3, 5, 9}, {2, 11, 5}, {8, 30, 10}, {22, 5, 1}}

차례대로 출력한 후 

배열의 모든 값을 더한 
결과를 출력하는 프로그램을 작성하시오.

*/
