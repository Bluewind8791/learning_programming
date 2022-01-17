
#include <stdio.h>
#include <stdbool.h>

bool IsPrime(int num);

int main(void)
{
	int i, cnt = 0;
	
	for(i=2; i<100; i++) {
		if(IsPrime(i) == true) {
			printf("%4d", i);
			cnt++;
			if(cnt%5 == 0) {
				printf("\n");
			}
		}
	}
	return 0;
}

bool IsPrime(int num)
{
	int i;
	
	for(i=2; i<num; i++) {
		if(num%i == 0) {
			return false;
		}
	}
	return true;
}
