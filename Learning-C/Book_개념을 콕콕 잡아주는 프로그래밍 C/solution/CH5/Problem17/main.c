#include <stdio.h>

int main(void)
{
	int N;
	int i, sum = 0;
	
	printf("Input number : ");
	scanf("%d", &N);
	
	/////////// 1 ~ N summation //////////
	for(i=1; i<=N; i++) {
		sum += i;
	}
	printf("Summation [1:N] = %d\n", sum);
	//////////////////////////////////////
	
	////////// 1 ~ N odd-summation ///////
	i = 1;
	sum = 0;
	while(i<=N) {
		if(i%2 == 1) {
			sum += i;
		}
		i++;
	}
	printf("Summation [1:N(Odd)] = %d\n", sum);
	//////////////////////////////////////
	
	//////// 1 ~ N even-summation ////////
	i = 1;
	sum = 0;
	do {
		if(i%2 == 0) {
			sum += i;
		}
		i++;
	} while(i<=N);
	printf("Summation [1:N(Even)] = %d\n", sum);
	//////////////////////////////////////
	
	return 0;
}
