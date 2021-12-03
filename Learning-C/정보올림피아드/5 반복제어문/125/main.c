#include <stdio.h>
int main(int argc, char *argv[]) {

int num, i;
int sum = 0;

scanf(" %d", &num);

i = 1;

while (i <= num)
	{
		sum =+ i;
		i++;
		printf("%d ", sum);	
	}
	
	
	return 0;
}
