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
�迭�� ���� �Ʒ��� ���� ������ �� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

��Ģ�� ù ��° ���� ��� 1�� �ʱ�ȭ �ϰ� 
���� ����ʹ� �ٷ� ���� ���� �ٷ� ������ ���� ���� ���̴�.
*/

