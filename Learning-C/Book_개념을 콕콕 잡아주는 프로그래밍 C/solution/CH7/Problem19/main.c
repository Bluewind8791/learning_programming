#include <stdio.h>
#include <math.h>

#define QUANTITY 10

int main(void)
{
	double num[QUANTITY];
	int i;
	double sum = 0.0, avg, variance, stdDeviation;
	
	printf("Input 10 real numbers : ");
	for(i=0; i<QUANTITY; i++) {
		scanf("%lf", &num[i]);
	}
	
	for(i=0; i<QUANTITY; i++) {
		sum += num[i];
	}
	
	/////////////////  average /////////////////
	avg = sum / QUANTITY;
	
	/////////////////  variance /////////////////
	sum = 0.0;
	for(i=0; i<QUANTITY; i++) {
		sum += pow(num[i]-avg, 2);
	}
	variance = sum / QUANTITY;
	
	///////////  standard deviation ////////////
	stdDeviation = sqrt(variance);
	
	printf("Average      : %.4f\n", avg);
	printf("variance     : %.4f\n", variance);
	printf("stdDeviation : %.4f\n", stdDeviation);
		
	return 0;
}








