#include <stdio.h>
#define N 10
int main ()
{
	int array[N];
	int i;
	int min = 10000;
	int max = 0;
	
	for (i=0; i<N; i++)
	 {
		scanf("%d", &array[i]);

		//100 �̸��� �� �� ���� ū ��
		if ( (array[i]<100) && (max < array[i])) 
		{
			max = array[i];
		}

		//100 �̻��� �� �� ���� ���� ��
		else if ( (array[i]>=100) && (min > array[i]) )
		{
			min = array[i];
		}
	}
	
	if (max == 0) {
		max = 100;
	}
	else if (min == 10000) {
		min = 100;
	}
	
	printf("%d %d", max, min);
	return 0;
}

