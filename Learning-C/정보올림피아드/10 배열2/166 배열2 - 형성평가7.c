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
2�� 3�� �迭�� �� �� �����Ͽ� 
������ ���� �Է� ���� �� 

�� �迭�� ���� ��ġ���� ���Ͽ� 
���ο� �迭�� ������ �� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
