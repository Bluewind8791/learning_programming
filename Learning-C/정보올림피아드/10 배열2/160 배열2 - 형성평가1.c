#include <stdio.h>

int main()
{
	int dice[6]={1,2,3,4,5,6};
	int dicecnt[6]={0,};
	int i, j;
	int thw[10]={0,};
	
	for(i=0;i<10;i++)
	{
		scanf("%d",&thw[i]);
		for(j=0;j<6;j++)
		{
			if (dice[j]==thw[i])
			{
				dicecnt[j]++;
			}
		}
	}
	
	for(j=0; j<6; j++)
	{
		printf("%d : %d\n",j+1 ,dicecnt[j]);
	}
	
	return 0;
}

/*
������ �ֻ��� ���̸� �ϴٰ� 
�ֻ����� 10�� ������ 
�� ���ڰ� �� ���� ���Դ��� �˾ƺ����� �Ѵ�. 

�ѹ� ���� ������ ���� �ֻ����� ���ڸ� �Է¹޾Ƽ� 
�� ���ڰ� �� ���� ���Դ��� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�
*/
