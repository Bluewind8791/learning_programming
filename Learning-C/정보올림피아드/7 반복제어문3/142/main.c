#include <stdio.h>

int main() 
{
int n, x, y;
scanf("%d", &n);

for (y=0; y<n; y++)
{
	for (x=0; x<n; x++)
	{
		if (y >= x)
		{printf("*");
		}
	}printf("\n");
}


for (y=1; y<n; y++)
{
	for (x=0; x<n; x++)
	{
		if( y <= -x+n-1 )
		{
		printf("*");	
		}
	}
	printf("\n");	
}

	return 0;
}

/*

*
**
***
**
*

y >= x

*/
