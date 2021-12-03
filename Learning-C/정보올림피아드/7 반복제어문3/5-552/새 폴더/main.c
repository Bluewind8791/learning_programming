#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int n, x, y;
	
	scanf("%d", &n);
	
	for (y=0; y<n; y++)
	{
		for (x=0; x<n; x++)
		{
			if (x >= y)
			{
				printf("*");
			}
			else
				printf(" ");
		}
		
		for (x=n; x<2*n-1; x++)
		{
			if (y <= -x+(2*n-2))
			{
				printf("*");
			}
		}

		printf("\n");
	}

	return 0;
}
