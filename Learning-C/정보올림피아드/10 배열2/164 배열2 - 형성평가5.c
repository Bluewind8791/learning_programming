#include <stdio.h>

int main()
{
	int score[4][3]={0,};
	int scoreSum[4]={0,};
	int i, j;
	
	for(i=0; i<4; i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&score[i][j]);
			scoreSum[i] = scoreSum[i] + score[i][j];
		}
	}
	
	printf("1class? 2class? 3class? 4class? ");
	for(i=0; i<4; i++)
	{
		printf("%dclass : %d\n", i+1, scoreSum[i]);
	}
	
	return 0;
}

/*
ȣ���̳� �б��� 
6�г��� �� ���� �ִµ� 
�� ���� ��ǥ�� �� �� �����Ͽ� 
�������� ������ �Ͽ���. 

�ݺ��� �� ���� ���⸦ �� ������ �Է¹޾� 
�� �ݺ��� ���⸦ �� ������ 
�հ踦 ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

(�ݵ�� �迭�� �̿��ϰ� �Է��Ŀ� ����ϴ� ������� �ϼ���.)

*/
