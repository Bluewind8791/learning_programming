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
	
	//pass, fail 판단하며 출력. 
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
5명 학생의 국어 영어 수학 과학 
4과목의 점수를 입력 받아서 
각 개인별로 평균이 80 이상이면
“합격” 그렇지 않으면“불합격”을 출력하고 

합격한 사람의 수를 
출력하는 프로그램을 작성하시오.

1. size결정
2. 배열 메모리 할당 

*/
