#include <stdio.h>
#include <math.h>

int main()
{
	double fn[3];
	int i;
	double sum = 0;
	double R_sum=0;
	
	for(i=0; i<3; i++)
	{
		scanf("%lf", &fn[i]);
		sum = sum + fn[i];
		R_sum = R_sum + round(fn[i]);
	}
	
	double avg;
	avg = sum / 3;
	printf("%.lf\n", round(avg));
	
	printf("%.lf", R_sum / 3);
	
	return 0;
}
/*
�� ���� �Ǽ��� �Է¹޾� 

�հ�� ����� ���Ͽ� 
����� �ݿø��� ������ ����ϰ�, 

������ �Է¹��� ���� 
���� ���� �ݿø��� �� 

�հ�� ����� ���Ͽ� 
����� �ݿø��� 

�� ����� ����ϴ� 
���α׷��� �ۼ��Ͻÿ�.
*/
