#include <stdio.h>

int main()
{
	int score[5][4]={0,};
	int sum[5]={0,};
	int i,j;
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&score[i][j]);
			sum[i] = sum[i] + score[i][j];
		}
		
	}
	
	//pass, fail �Ǵ��ϸ� ���. 
	int success=0;
	for(i=0;i<5;i++)
	{
	
		if( (sum[i]/4) >= 80)
		{
			printf("pass\n");
			success++;
		}
		else
		{
			printf("fail\n");
		}
	}
	
	printf("Successful : %d", success);
	
	return 0;
}

/*
5�� �л��� ���� ���� ���� ���� 
4������ ������ �Է� �޾Ƽ� 
�� ���κ��� ����� 80 �̻��̸�
���հݡ� �׷��� �����顰���հݡ��� ����ϰ� 

�հ��� ����� ���� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

1. size����
2. �迭 �޸� �Ҵ� 

*/
