#include <stdio.h>
#include <math.h>

int main ()
{
	int a[100];
	int i, sum=0, mcount=0;
	double avg;
	
	for(i=0;i<100;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]==0)
		{
			break;
		}
		else if (a[i] % 5 == 0)
		{
			mcount++;
			sum = a[i] + sum;
		}
	}
	avg = (double)sum/mcount;
	printf("Multiples of 5 : %d\n", mcount);
	printf("sum : %d\n", sum);
	printf("avg : %.1lf\n", (round(10*(avg)) )/10 );
	
	return 0;
}

/*
100 �� ������ ������ �Է¹޴ٰ� 
0 �� �ԷµǸ� 

�� ������ �Էµ� ���� �� 
5�� ����� ������ 
�հ� ����� ����ϴ� 
���α׷��� �ۼ��Ͻÿ�.

����� �Ҽ��� ���� 1�ڸ����� ����Ѵ�.

35 10 23 100 64 51 5 0
*/
