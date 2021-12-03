
#include <stdio.h>

double Get_Absolute(double num);

int main(void)
{
	double doubleVal;
	
	printf("Input Real number : ");
	scanf("%lf", &doubleVal);
	
	printf("Absolute Value : %f\n", Get_Absolute(doubleVal));
	
	return 0;
}

double Get_Absolute(double num)
{
	if(num < 0) {
		num = -num;
	}
	
	return num;
}
