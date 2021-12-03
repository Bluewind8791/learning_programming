#include <stdio.h>

int main()
{
	int array[5][5]={0,};
	int i,j;
	
	array[0][0]=1;
	array[0][1]=1;
	array[0][2]=1;
	array[0][3]=1;
	array[0][4]=1;
	
	array[0][0]=1;
	array[1][0]=1;
	array[2][0]=1;
	array[3][0]=1;
	array[4][0]=1;
	
	
	for(i=1;i<5;i++)
	{
		for(j=1;j<5;j++)
		{
			array[i][j] = array[i][j-1] + array[i-1][j];
		}
	}
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

/*
배열을 만들어서 아래와 같이 저장한 후 
출력하는 프로그램을 작성하시오. 

규칙은 첫 번째 행은 모두 1로 초기화 하고 
다음 행부터는 바로 위의 값과 바로 왼쪽의 값을 더한 것이다.
*/

