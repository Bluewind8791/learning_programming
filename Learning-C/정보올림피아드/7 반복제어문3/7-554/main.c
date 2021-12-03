#include <stdio.h>
int main(int argc, char *argv[]) {
	
	int n, x, y;
	int num;
	char ch = 'A';
	
	scanf("%d", &n);
	num = 1;
	
	for (y=0; y<n; y++)
	{
		for (x=0; x<n+1; x++)
		{
			if (y <= -x+n-1 )
			{
			printf("%d ", num);
			num++;
			}	
			else
			{
				printf("%c ", ch);
				ch++;
			}
		}
		printf("\n");
	}
	return 0;
}
