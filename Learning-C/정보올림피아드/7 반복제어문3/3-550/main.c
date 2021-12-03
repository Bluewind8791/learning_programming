#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int n, i, j, a;
	
	scanf(" %d", &n);
	a = n;

	for (i=0; i<n; i++)
	{
	a--;
		for(j=0; j<=a; j++)
		{
			printf("*");
		}printf("\n");
	}
	
	for (i=0; i<n; i++)
	{
	a++;
		for(j=0; j<a; j++)
		{
			printf("*");
		}printf("\n");
	}
	
	return 0;
}
