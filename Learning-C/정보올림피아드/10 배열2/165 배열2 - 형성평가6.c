#include <stdio.h>

int main ()
{
	int array[5][5] = {0,};
	
	array[0][0] = 1;
	array[0][2] = 1;
	array[0][4] = 1;
	
	int i,j;
	
	for(i=1;i<5;i++)
	{
		for(j=0;j<1;j++)
		{
			array[i][j] = array[i-1][j+1];
		}
		
		for(j=1;j<4;j++)
		{
			array[i][j] = array[i-1][j-1]+array[i-1][j+1];	
		}
		
		for(j=4;j<5;j++)
		{
			array[i][j] = array[i-1][j-1];
		}
	}

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
					
	return 0;
}

/*
예제를 보고 적당한 배열을 선언한 후 

1행의 1열과 3열 5열을 각각 1로 초기화하고 
나머지는 모두 0으로 초기화 한 후 

2행부터는 바로 위행의 왼쪽과 오른쪽의 값을 더하여 채운 후 
출력하는 프로그램을 작성하시오.

*/
