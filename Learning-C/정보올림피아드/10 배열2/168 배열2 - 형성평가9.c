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
���� ũ�⸦ �Է¹޾� 
�Ľ�Į �ﰢ���� �ۼ��Ͽ� 
������ ����� ù ��° ����� 
���ʷ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

���� ũ��� �ִ� 10�̴�.
*/
