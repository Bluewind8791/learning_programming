#include <stdio.h>
int main(int argc, char *argv[]) {
	int n, x, y;
	scanf(" %d", &n);
	
	for (y=0; y<n; y++)
	{
		for (x=0; x<-2*y+2*n-2; x++)
		{
		printf(" ");
		}
		
		for (x=0; x<1+2*y; x++)
		{
			printf("*");
		}
	
	printf("\n");
	}
	return 0;
}
