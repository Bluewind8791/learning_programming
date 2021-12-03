#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int num1, num2, i, j, n, first;
	scanf(" %d %d", &num1, &num2);
	
	if ( num1 > num2)
	{
		n = num1 - num2;
		for (j=1; j < 10; j++) 
		{
			first = num1;
			for (i=0; i <= n; i++)
			{
				printf("%d * %d =%3d   ", first, j, first*j);
				first--;
			}
			printf("\n");
		}	
	}
	
	else if (num2 > num1)
	{
		n = num2 - num1;
		for (j=1; j < 10; j++) 
		{
			first = num1;
			for (i=0; i <= n; i++)
			{
				printf("%d * %d =%3d   ", first, j, first*j);
				first++;
			}
			printf("\n");
		}	
	}	
	
	else
	{
		for (j=1; j < 10; j++) 
		{
		printf("%d * %d =%3d   ", num1, j, num1*j);
		printf("\n");

		}
	}
	return 0;
}


