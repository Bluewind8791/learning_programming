#include <stdio.h>
int main(void) {
	
	int n1, n2, sum, count;
	float avg;
	
	sum = 0;
	count = 0;
	
	scanf(" %d %d", &n1, &n2);
	
	if (n1 > n2)
		{ 
		for (; n2 <= n1 ; n2++)
			if (n2 % 3 == 0 || n2 % 5 == 0)
			{
			sum = n2 + sum;
			count++;
			}			
		}
	
	else if (n1 < n2)
		{ 
		for (; n1 <= n2 ; n1++)
			if (n1 % 3 == 0 || n1 % 5 == 0)
			{
			sum = n1 + sum;
			count++;
			}			
		}
	
	else if (n1 = n2)
		{
		if (n1 % 3 == 0 || n1 % 5 == 0)
		sum = n1;
		count++;
		}
	
	avg = (float)sum / count;
	printf("sum : %d\navg : %.1f", sum, avg);
	
	return 0;
}
