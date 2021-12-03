
#include <stdio.h>

double Power(double x, double y);

int main(void)
{
	double num1, num2;
	
	printf("Inpt 2 Real numbers : ");
	scanf("%lf %lf", &num1, &num2);
	
	printf("%.4f power of %.4f is %.4f\n", num2, num1, Power(num1, num2));
	
	return 0;
}

double Power(double x, double y)
{
	int i;
	double pow = 1.0;
	
	if(y == 0) {
		pow = 1;
	}
	else {
		for(i=1; i<=y; i++) {
			pow *= x;
		}
	}
	
	return pow;
}
