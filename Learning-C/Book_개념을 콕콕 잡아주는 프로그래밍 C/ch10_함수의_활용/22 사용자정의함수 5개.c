#include <stdio.h>
#include <math.h>
#define CNT 5

void InputArray(double *f);
void PrintArray(const double *f);
double Average(const double *f);
double Variance(const double *f);
double StandardDeviation(const double *f);

int main()
{
	double farray[CNT];
//	double farray[CNT] = {10.2, 10.78, 10.44, 10.84, 10.56};
	printf("5개의 실수를 입력하세요 : ");
	InputArray(farray);

	printf("\n  배열   : ");
	PrintArray(farray);
	
	printf("\n  분산   : ");
	printf("%lf", Variance(farray));
	
	printf("\n표준편차 : ");
	printf("%lf", StandardDeviation(farray));
	return 0;
}

void InputArray(double *f)
{
	for(int i=0; i<CNT; i++) {
		scanf("%lf", &f[i] );
	}
}

void PrintArray(const double *f)
{
	for(int i=0; i<CNT; i++) {
		printf("%.2lf ",f[i]);
	}
}

double Average(const double *f)
{
	double sum = 0, avg;
	for(int i=0; i<CNT; i++) {
		sum += f[i];
	}
	avg = sum/CNT;
	return avg;
}

double Variance(const double *f)
{
	double avg = Average(f);
	double var[CNT] = {0,};
	double variance;
	for(int i=0; i<CNT; i++) {
		var[i] = pow((f[i] - avg), 2);
	}
	variance = Average(var);
	return variance;
}

double StandardDeviation(const double *f)
{
	double var, s_dev;
	var = Variance(f);
	s_dev = sqrt(var);
	return s_dev;
}

/*
실수형 배열을 인자로 받아 
실수값들을 입력받는 InputArray 함수 
실수값들을 출력하는 PrintArray 함수 
실수 값들의 평균을 구하는 Average 함수 
실수값들의 분산을 구하는 Variance 함수 
표준편차를 구하는 StandardDeviation 함수 정의 

각 함수는 배열과 배열의 크기를 인자로 가지며 
함수의 기능에 따라 배열이 입력인자인지 
출력인자인지 적절히 판단하여 데이터형 결정  
*/
