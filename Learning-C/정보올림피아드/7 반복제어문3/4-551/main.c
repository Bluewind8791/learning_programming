#include <stdio.h>

int main(int argc, char *argv[]) {

	int n, y, x, k;
	scanf(" %d",&n);
	for(y=0; y<n; y++)
	{
		for (x=0; x<n; x++)
		{
			if (y <= x)
			{printf("*");
			}
			else
			{printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
