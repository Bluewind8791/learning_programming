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
		if( ScoreRange[i]==0 )	//1명도 없는 점수는 출력하지 않는다
		{
			continue;
		}
		printf("%d : %d person\n", 10*i, ScoreRange[i] );
	}
	
	return 0;
}

/*
학생들의 점수를 입력을 받다가 
0이 입력되면 

그 때까지 입력받은 점수를 
10점 단위로 구분하여 

점수대별 학생 수를 출력하는 프로그램을 작성하시오. 
(1명도 없는 점수는 출력하지 않는다.)
학생은 최대 100명이하이다.
*/

