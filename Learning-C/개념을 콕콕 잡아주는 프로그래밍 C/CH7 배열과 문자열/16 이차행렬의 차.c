#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));		//�����Լ��� �õ尪�� time�Լ��� �ޱ� 
	
	int i, j;
	int a_minus[3][3]={0,};
	int array_a[3][3]={0,};
	int array_b[3][3]={0,};
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			array_a[i][j] = rand()%100;
			array_b[3][3] = rand()%100;
			a_minus[i][j] = array_a[i][j] - array_b[i][j];
		}
	}
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d ", a_minus[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

/*
3X3 ����� ���� ���ϴ� ���α׷� 
*/
