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
������ ���� ������ �迭�� ������ �� 

1���� 1���� 3�� 5���� ���� 1�� �ʱ�ȭ�ϰ� 
�������� ��� 0���� �ʱ�ȭ �� �� 

2����ʹ� �ٷ� ������ ���ʰ� �������� ���� ���Ͽ� ä�� �� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

*/
