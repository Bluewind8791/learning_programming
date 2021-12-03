#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int num, sum;
	int i;
	sum = 0;
	
	scanf(" %d", &num);
	
	for(i=1; i<=num; i++)
	{
	
	if (i % 5 == 0)
		{
			sum = i + sum;
		}
	}
	
	printf("%d", sum);
	
	
	return 0;
}
