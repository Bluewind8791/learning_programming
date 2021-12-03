#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int x, y, n;
	char a = 'A';
	
	scanf("%d",&n);
	
	for (y=0; y<n; y++)
	{
		for (x=0; x<n; x++)
		{
			if(y <= -x+n-1)
			{
				printf("%c",a);
				a++;
			}		
		}
		printf("\n");
	}
	return 0;
}
