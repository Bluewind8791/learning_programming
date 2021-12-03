#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int n;
	int sum, count;
	
	count = 0;
	sum = 0;
	
	while(1)
	{
		scanf(" %d", &n);

		if(n == 0)
			{break;
			}
			
		sum = n + sum;
		count++;
		
		if (count >= 20)
		{break;
		}
	}
	
	printf("%d %d", sum, sum/count);
	
	return 0;
}
