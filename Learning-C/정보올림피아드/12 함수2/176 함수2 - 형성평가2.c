#include <stdio.h>
#include <math.h>

int Count (double fn1, double fn2)
{
	int i;
	int cnt = 0;
	for(i=(int)sqrt(fn2); i<(int)sqrt(fn1); i++)
	{
		cnt++;
	}
	if (sqrt(fn2) == (int)sqrt(fn2))
	{
		cnt++;
	}
	return cnt;
}

int main()
{
	double fn1, fn2;
	
	//fn1 = 12.0;
	//fn2 = 34.789;
	scanf("%lf %lf", &fn1, &fn2);
		
	if ( sqrt(fn1) > sqrt(fn2) )
	{
		printf("%d", Count(fn1, fn2));
	}
	else if ( sqrt(fn1) < sqrt(fn2) )
	{
		printf("%d", Count(fn2, fn1));
	}
	
	return 0;
}



/*
�� ���� �Ǽ��� �Է¹޾� 
������ �������� ���ϰ� 

�� ������ ���̿� �����ϴ� ������ ������ 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

��, �Է¹޴� �� �Ǽ��� ����̸� 
�� ������ ���̶�� ���� 
�� �������� �����Ѵ�.

���� ���� ��� ��ȯ�ϱ� �� 
������ �����ٰ� ���ٸ� ������ ����
*/
