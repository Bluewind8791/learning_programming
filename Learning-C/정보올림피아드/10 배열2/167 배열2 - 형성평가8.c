#include <stdio.h>

int main()
{
	int a[4][2]={0,};
	int i,j;
	int WidthAvg[4]={0,};
	int HeightAvg[2]={0,};
	int TotalAvg = 0;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&a[i][j]);
			WidthAvg[i] = WidthAvg[i] + a[i][j];
			HeightAvg[j] = HeightAvg[j] + a[i][j];
			TotalAvg = TotalAvg + a[i][j];
		}
		WidthAvg[i] = WidthAvg[i] / 2;
	}
	
	for(i=0;i<4;i++)
	{
		printf("%d ", WidthAvg[i]);
	}
	printf("\n");
	
	for(j=0;j<2;j++)
	{
		HeightAvg[j] = HeightAvg[j] / 4;
		printf("%d ", HeightAvg[j]);
	}
	printf("\n");
	
	printf("%d ", TotalAvg/8);
	
	return 0;
}

/*
4�� 2���� �迭�� �Է¹޾� 
������հ� ������� 
�׸��� ��ü����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
(�Ҽ��� ���ϴ� ���� �Ѵ�.)
*/

