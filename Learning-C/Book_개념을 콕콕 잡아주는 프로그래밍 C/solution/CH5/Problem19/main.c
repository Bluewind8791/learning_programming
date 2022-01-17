
#include <stdio.h>

int main(void)
{
	int N;
	int i, fact = 1;
	
	printf("Input number : ");
	scanf("%d", &N);
	
	
	if(N == 0) {
		fact = 1;
	}
	else {
		for(i=1; i<=N; i++) {
			fact *= i;
		}		
	}

	printf("%d factorial = %d\n", N, fact);
	
	return 0; 
}
