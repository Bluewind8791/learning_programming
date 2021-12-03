#include <stdio.h>
int main(int argc, char *argv[]) {

	int n;
	int x, y;
	
	scanf(" %d", &n);
	
	for(y=0; y<n; y++)
	{
		
		for(x=0; x<n; x++)
		{
			if (x >= y)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		
		
		for(x=n; x<(2*n-1); x++)
		{
			if (x <= -y+2*n-2)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		
	printf("\n");
	}

	return 0;
}
