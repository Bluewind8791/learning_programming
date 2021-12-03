#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int n, i, j, a;
	
	scanf(" %d", &n);
	a = 1;
	
	for (j=0; j<n; j++ )
	{
		for(i=0; i<a; i++)
			{
			printf("*");	
			}printf("\n");
			a++;
	}
	return 0;
}
