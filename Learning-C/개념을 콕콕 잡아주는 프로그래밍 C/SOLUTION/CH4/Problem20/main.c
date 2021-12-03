

#include <stdio.h>

int main(void)
{
	int num1, num2, num3;
	int min, max;
	float avg;
	
	printf("Input 3 numbers : ");
	scanf("%d %d %d", &num1, &num2, &num3);
	
	min = (num1 < num2)? ((num1 < num3)? num1 : num3) : ((num2 < num3)? num2 : num3);
	max = (num1 > num2)? ((num1 > num3)? num1 : num3) : ((num2 > num3)? num2 : num3);
	avg = (num1 + num2 + num3) / 3.0f;
	
	printf("Mininum : %d\n", min);
	printf("Maximum : %d\n", max);
	printf("Average : %.2f\n", avg);
	
	return 0;
}
