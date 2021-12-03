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

		//100 미만의 수 중 가장 큰 수
		if ( (array[i]<100) && (max < array[i])) 
		{
			max = array[i];
		}

		//100 이상의 수 중 가장 작은 수
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

