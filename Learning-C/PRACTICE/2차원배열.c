#include <stdio.h>

int main ()
{
	int a[5][3] = {
		{100,90,80},{90,80,70},
		{75,35,40},{40,15,75},
		{100,35,30}
		};
	int i,j;
	int sum[5] = {0};
	
	for (i=0; i<5; i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",a[i][j]);
			sum[i] = a[i][j] + sum[i];
		}
		printf("\n");
	 } 
	printf("\n각 학생의 총점은\n");

	for (i=0; i<5; i++)
	{
		printf("%d ",sum[i]);
	}
	return 0;
}
