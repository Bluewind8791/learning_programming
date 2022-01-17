#include <stdio.h>
#include <stdbool.h>

#define SIZE 100
#define LINE 10

bool IsPrime(int n);

int main(void)
{
	int num, i;
	int primeArry[SIZE] = {0};
	
	num = 2;
	i = 0;
	while(1) {
		if(IsPrime(num) == true) {
			primeArry[i++] = num;
			if(i == SIZE) {
				break;
			}
		}
		num++;
	}

	for(i=0; i<SIZE; ) {
		printf("%5d", primeArry[i]);	
		if((++i)%LINE == 0)	{
			printf("\n");
		}
	}
	
	return 0;
}

bool IsPrime(int n)
{
	int i;
	for(i=2; i<n; i++) {
		if(n%i == 0) {
			return false;
		}
	}
	
	return true;
}




