#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
	srand(time(NULL));		//random �Լ��� ��Ʈ�� ���� 
	
	double fnum[10]={0,};	//�Ǽ� 10���� �迭 
	double sum = 0;			//�Ǽ��� ���� 
	int i;
	
	printf("==���� �Ǽ� 10��==\n");
	for (i=0;i<10;i++)
	{
		fnum[i]=(double)(rand()%1000+1)/10;
		printf("%.1lf ", fnum[i]);
		sum = fnum[i] + sum;
	}
	printf("\n\n");
	
	//��� (Average) 
	double avg;
	avg = sum / 10;
	printf("1. ��� : %.3lf\n", avg);
	
	//�л� (Variance) 
	double dev[10] = {0,};		//����(dev) �迭 ���� 
	double d_sum = 0;			//���� ������ ����
	
	for (i=0;i<10;i++)
	{
		dev[i] = fnum[i] - avg;	
		//������ �� �������� ����� �� ��. 
		//printf("���� : %.1lf ", dev[i]);
		d_sum = pow(dev[i], 2) + d_sum;
	}
	
	double variance;
	variance = d_sum/10;
	printf("2. �л� : %.3lf\n", variance);
	//�л� = ���������� ���� / ������ ����
	
	printf("3. ǥ������ : %.3lf\n", sqrt(variance) );
	
	return 0;
}

/*
�Ǽ� �� 10���� �Է¹޾Ƽ�

���, �л�, ǥ�������� ���� ���ϴ� ���α׷�

�л� = ���������� ���� / ������ ����
���� : �� �������� ����� �� ��
ǥ������ = �л��� ��Ʈ 
 
*/
