#include <stdio.h>
#include <math.h>

#define SIZE 5

void InputArray(double *array, int size);
void PrintArray(const double *array, int size);
double Average(const double *array, int size);
double Variance(const double *array, int size);
double StandardDeviation(const double *array, int size);

int main(void)
{
	double doubleArray[SIZE];
	
	InputArray(doubleArray, SIZE);
	PrintArray(doubleArray, SIZE);
	
	printf("�л� :  %lf\n", Variance(doubleArray, SIZE));
	printf("ǥ������ : %lf\n", StandardDeviation(doubleArray, SIZE)); 

	return 0;
}


void InputArray(double *array, int size)
{
	int i;
	printf("%d���� �Ǽ��� �Է��ϼ��� : ", SIZE);
	for(i=0; i<size; i++) {
		scanf("%lf", &array[i]);
	} 
}


void PrintArray(const double *array, int size)
{
	int i;
	printf("�迭 : ");
	for(i=0; i<size; i++) {
		printf("%6.2lf ", array[i]);
	} 
	printf("\n");
}


double Average(const double *array, int size)
{
	double sum = 0.0;
	int i;
	for(i=0; i<size; i++) {
		sum += array[i];
	}
	
	return (sum / size);
}


double Variance(const double *array, int size)
{
	double sumSquare = 0.0, avg;
	int i;
	
	avg = Average(array, size);
	
	for(i=0; i<size; i++) {
		sumSquare += pow(array[i]-avg, 2);
	}
	
	return (sumSquare / size);
}


double StandardDeviation(const double *array, int size)
{
	return sqrt(Variance(array, size));
}







