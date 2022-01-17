#include <stdio.h>

int main(void) {
	
	int n, i;
	int sum=0, odd_sum=0, even_sum=0;
	
	scanf(" %d", &n);
	
	for(i=1; i<=n; i++)
		{
			sum += i;
		}
	
	i = 1;
	while (i<=n)
		{
			if( i % 2 != 0)
			{ odd_sum += i;
			}
			i++;
		}
	
	i = 0;
	do {
		i++;
		if( i % 2 == 0)
			{
			even_sum += i;
			}
		}
	while (i<=n);

	
	
	printf("1부터 %d까지의 합계 : %d\n", n, sum);
	printf("1부터 %d까지의 홀수의 합계 : %d\n", n, odd_sum);
	printf("1부터 %d까지의 짝수의 합계 : %d\n", n, even_sum);

	return 0;
}
