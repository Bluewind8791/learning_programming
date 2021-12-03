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
	printf("5���� �Ǽ��� �Է��ϼ��� : ");
	InputArray(farray);

	printf("\n  �迭   : ");
	PrintArray(farray);
	
	printf("\n  �л�   : ");
	printf("%lf", Variance(farray));
	
	printf("\nǥ������ : ");
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
�Ǽ��� �迭�� ���ڷ� �޾� 
�Ǽ������� �Է¹޴� InputArray �Լ� 
�Ǽ������� ����ϴ� PrintArray �Լ� 
�Ǽ� ������ ����� ���ϴ� Average �Լ� 
�Ǽ������� �л��� ���ϴ� Variance �Լ� 
ǥ�������� ���ϴ� StandardDeviation �Լ� ���� 

�� �Լ��� �迭�� �迭�� ũ�⸦ ���ڷ� ������ 
�Լ��� ��ɿ� ���� �迭�� �Է��������� 
����������� ������ �Ǵ��Ͽ� �������� ����  
*/
