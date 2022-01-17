

#include <stdio.h>

int main(void)
{
	int exponent = 5;
	int value = 1;
	
	value <<= exponent;
	printf("5th power of 2 : %d\n", value);
	
	value <<= exponent;
	printf("10th power of 2 : %d\n", value);
	
	value <<= exponent;
	printf("15th power of 2 : %d\n", value);
	
	value <<= exponent;
	printf("20th power of 2 : %d\n", value);
	
	value <<= exponent;
	printf("25th power of 2 : %d\n", value);
	
	value <<= exponent;
	printf("30th power of 2 : %d\n", value);
	
	return 0;
}
