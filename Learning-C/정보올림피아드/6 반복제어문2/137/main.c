#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int i, j, line, row;
	scanf(" %d %d", &row, &line);
	
	for (j=1; j <= row; j++)
	{
			
		for (i=1; i <= line; i++)
		{
		printf("%d ", i*j);
		}
		printf("\n");				
	}
	return 0;
}
