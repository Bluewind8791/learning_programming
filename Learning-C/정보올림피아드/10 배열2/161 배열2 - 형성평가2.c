#include <stdio.h>

int main()
{
	int score[100]={0,};
	int ScoreRange[11]={0,};
	int i;
	float k;
	
	for(i=0,k=0;;i++)
	{
		scanf("%d",&score[i]);
		if (score[i]==0)
		{
			break;
		}
		else
		{
			k = score[i] / 10.0;
			if (k<1 && k>0)
			{
				ScoreRange[0]++;
			}
			else
			{
				ScoreRange[(int)k]++;
			}
			
		}
	}
	
	for(i=10;i>=0;i--)
	{
		if( ScoreRange[i]==0 )	//1�� ���� ������ ������� �ʴ´�
		{
			continue;
		}
		printf("%d : %d person\n", 10*i, ScoreRange[i] );
	}
	
	return 0;
}

/*
�л����� ������ �Է��� �޴ٰ� 
0�� �ԷµǸ� 

�� ������ �Է¹��� ������ 
10�� ������ �����Ͽ� 

�����뺰 �л� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
(1�� ���� ������ ������� �ʴ´�.)
�л��� �ִ� 100�������̴�.
*/

