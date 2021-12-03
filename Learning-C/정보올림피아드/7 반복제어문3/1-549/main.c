#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int n, i;
	int odd_num, odd_sum;
	
	odd_sum = 0;
	odd_num = 0;
	
	scanf(" %d", &n);
	
	for (i=1; ; i++)
	{		
		if (i % 2 != 0)
			{
				odd_sum = i + odd_sum;
				odd_num++;
				
				if (odd_sum >= n)
				{break;
				}	
			}
	}
	
	printf("%d %d", odd_num, odd_sum);
	
	return 0;
}
