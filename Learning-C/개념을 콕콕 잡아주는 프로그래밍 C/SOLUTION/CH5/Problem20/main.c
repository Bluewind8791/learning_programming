
#include <stdio.h>

int main(void)
{
	int N;
	int i, j, fact = 1;
	
	printf("Input number : ");
	scanf("%d", &N);
	
	for(i=0; i<=N; i++) {
		if(i == 0) {
			fact = 1;
		}
		else {
			fact = 1;
			for(j=1; j<=i; j++) {
				fact *= j;
			}
		}
		printf("%d! = %d\n", i, fact);
	}
	
	return 0; 
}
