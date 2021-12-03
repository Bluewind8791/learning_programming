#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int x, y, n;
	scanf(" %d", &n);
//À­»ï°¢Çü	
	for (y=0; y<n; y++)
	{
		for (x=0; x<n; x++)
		{
			if( y <= x )
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		for (x=n; x<2*n-1; x++)
		{
			if( y <= -x+2*n-2 )
				printf("*");
		}
	printf("\n");
	}
//¾Æ·§»ï°¢Çü 
	for (y=n; y<2*n-1; y++)
	{
		for (x=0; x<n; x++)
		{
			if (y >= -x+2*n-2)
			{printf("*");
			}
			else
			{printf(" ");
				}
		}
		
		for (x=n; x<2*n-1; x++)
		{
			if (y >= x)
			{printf("*");
			}
		}
		
		printf("\n");		
	}


	return 0;
}
