#include <stdio.h>
#include <math.h>

void CompareInt (int n1, int n2)
{
	if ( abs(n1) > abs(n2) )
	{
		printf("%d\n", n1);
	}
	else
	{
		printf("%d\n", n2);
	}
}

void CompareDouble (double f1, double f2)
{
	if ( fabs(f1) > fabs(f2) )
	{
		printf("%.2lf\n", f2);
	}
	else
	{
		printf("%.2lf\n", f1);
	}
}

int main()
{
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	
	double f1, f2;
	scanf("%lf %lf", &f1, &f2);
		
	CompareInt(n1, n2);
	CompareDouble(f1, f2);
	

	return 0;
}

/*
�� ���� ������ �Է¹޾� 
���밪�� �� ū ���� ����ϰ� 

�� ���� �Ǽ��� �Է¹޾� 
���밪�� ���� ���� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Ǽ��� �Ҽ��� ���� 2�ڸ����� ����Ѵ�.
*/
