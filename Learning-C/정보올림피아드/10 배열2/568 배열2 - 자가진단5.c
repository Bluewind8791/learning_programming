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
2�� 4���� �迭 �� ���� ���� 
�Է��� �ް� 

�� �迭�� ���� ���Ͽ� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.


*/
