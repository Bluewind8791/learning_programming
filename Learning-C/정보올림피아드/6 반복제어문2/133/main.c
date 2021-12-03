#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int n, i;
	int num;
	float avg;
	
	avg = 0;
	
	scanf(" %d", &n);
	
	for (i=0; i<n; i++)
	{	scanf(" %d", &num);
	avg = num + avg;
	}
	
	printf("%.2f", avg/n);	
	
	return 0;
}
