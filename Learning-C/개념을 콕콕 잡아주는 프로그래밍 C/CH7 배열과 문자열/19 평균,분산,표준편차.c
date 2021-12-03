#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
	srand(time(NULL));		//random 함수의 루트값 지정 
	
	double fnum[10]={0,};	//실수 10개의 배열 
	double sum = 0;			//실수의 총합 
	int i;
	
	printf("==랜덤 실수 10개==\n");
	for (i=0;i<10;i++)
	{
		fnum[i]=(double)(rand()%1000+1)/10;
		printf("%.1lf ", fnum[i]);
		sum = fnum[i] + sum;
	}
	printf("\n\n");
	
	//평균 (Average) 
	double avg;
	avg = sum / 10;
	printf("1. 평균 : %.3lf\n", avg);
	
	//분산 (Variance) 
	double dev[10] = {0,};		//편차(dev) 배열 변수 
	double d_sum = 0;			//편차 제곱의 총합
	
	for (i=0;i<10;i++)
	{
		dev[i] = fnum[i] - avg;	
		//편차는 각 변량에서 평균을 뺀 값. 
		//printf("편차 : %.1lf ", dev[i]);
		d_sum = pow(dev[i], 2) + d_sum;
	}
	
	double variance;
	variance = d_sum/10;
	printf("2. 분산 : %.3lf\n", variance);
	//분산 = 편차제곱의 총합 / 변량의 개수
	
	printf("3. 표준편차 : %.3lf\n", sqrt(variance) );
	
	return 0;
}

/*
실수 값 10개를 입력받아서

평균, 분산, 표준편차를 각각 구하는 프로그램

분산 = 편차제곱의 총합 / 변량의 개수
편차 : 각 변량에서 평균을 뺀 값
표준편차 = 분산의 루트 
 
*/
