#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int num, i, times;
	
	times = 1;
	
	scanf(" %d", &num);
	
	for (i=1; i<11; i++)
		{
		times = num * i;
		printf("%d ", times);
		}
	
		
	
	return 0;
}
