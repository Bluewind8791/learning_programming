#include <stdio.h>

#define SIZE 5

int main(void)
{
	float num[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};
	float *p = num;
	int i;
	float sum = 0.0, avg;
	
	for(i=0; i<SIZE; i++) {
		sum += *(p+i);
	}
	
	avg = sum / SIZE;
	
	printf("Average : %.3f\n", avg);

	return 0;
}
