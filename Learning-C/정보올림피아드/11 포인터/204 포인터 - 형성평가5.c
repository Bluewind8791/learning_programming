#include <stdio.h>
#include <limits.h>

int i;
	
void InputNumber (int *n);
void PrintMsg (char *msg, int value);
void InputArray (int *arr, int number);
void FindingMax(int *arr, int number, int *max);
void FindingMin(int *arr, int number, int *min);

int main()
{
	int n, max, min;
	InputNumber(&n);
	
	int arr[n];
	int *p = arr;

	char *MaxMsg = "max : %d\n";
	char *MinMsg = "min : %d\n";
	
	InputArray(p, n);
	
	FindingMax(p, n, &max);
	FindingMin(p, n, &min);
	
	PrintMsg (MaxMsg, max);
	PrintMsg (MinMsg, min);
	
	return 0;
}

void InputNumber (int *n) 
{
	scanf("%d", n);
}

void PrintMsg (char *msg, int value)
{
	printf(msg, value);
}

void InputArray (int *arr, int number)
{
	for(i=0; i<number; i++) {
		scanf("%d", &arr[i]);
	}
}

void FindingMax(int *arr, int number, int *max)
{
	*max = 0;
	for(i=0; i<number; i++) {
		if (*max < arr[i]) {
			*max = arr[i];
		}
	}
}

void FindingMin(int *arr, int number, int *min)
{
	*min = INT_MAX;
	for(i=0; i<number; i++) {
		if (*min > arr[i]) {
			*min = arr[i];
		}
	}
}

/*
정수 n을 입력받아 
n개의 정수형 동적배열을 생성하고 
n개의 정수를 입력받아 
최대값과 최소값을 출력하는 프로그램 
*/
