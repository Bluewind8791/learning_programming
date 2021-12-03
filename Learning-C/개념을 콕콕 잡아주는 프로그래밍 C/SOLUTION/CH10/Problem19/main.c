#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef enum order {ASC, DESC} ORDER ;

void GenRandomArray(int *arry, int size, int endNum);
void PrintArray(int *arry, int size);
void Swap(int *a, int *b);
void QuickSort(int *aryr, int start, int end, ORDER dir);

int main(void)
{
	int a[SIZE];
	
	GenRandomArray(a, SIZE, 99);
	printf("Before quick sort            : ");
	PrintArray(a, SIZE);
	
	QuickSort(a, 0, SIZE-1, ASC);
	printf("After quick sort(Ascending)  : ");
	PrintArray(a, SIZE);
	QuickSort(a, 0, SIZE-1, DESC);
	printf("After quick sort(Descending) : ");
	PrintArray(a, SIZE);
	
	return 0;
}


void GenRandomArray(int *arry, int size, int endNum)
{
	int i;
	srand(time(NULL));
	for(i=0; i<size; i++) {
		arry[i] = rand() % (endNum+1);
	}
}


void PrintArray(int *arry, int size)
{
	int i;
	for(i=0; i<size; i++) {
		printf("%5d", arry[i]);
	}
	printf("\n");
}


void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void QuickSort(int *arry, int start, int end, ORDER dir)
{
	int pivot = arry[start];
	int left = start + 1;
	int right = end;
	
	while(left <= right) {
		if(dir == ASC) {
			while(arry[left] < pivot) 
				left++;
			
			while (arry[right] > pivot) 
				right--;
		}
		else {
			while(arry[left] > pivot) 
				left++;
			
			while (arry[right] < pivot) 
				right--;
		}
				
		if(left <= right) {
			Swap(&arry[left], &arry[right]);
		}
	}
	
	if(start < end) {
		Swap(&arry[start], &arry[right]);
		QuickSort(arry, start, right-1, dir);
		QuickSort(arry, right+1, end, dir);
	}
}





