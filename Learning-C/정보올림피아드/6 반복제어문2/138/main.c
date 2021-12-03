#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int i,j,num;
	
	scanf(" %d", &num);
	
	for(j=1;j<num+1;j++)
	{
		for (i=1; i<num+1; i++)
		{
			printf("(%d, %d) ",j,i);
		}
		printf("\n");
	}
	
	return 0;
}
