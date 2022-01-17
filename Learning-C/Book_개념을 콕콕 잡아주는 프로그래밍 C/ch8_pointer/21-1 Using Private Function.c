#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
���� ���� �ϳ� �Է� �޾Ƽ�
������ �迭�� ��� ���Ҹ� Ư�� ����ŭ
������Ű�� ���α׷��� �ۼ��Ͻÿ�

�� ������ �迭�� ���Ҹ� ������ų ��
�����͸� �̿��Ͻÿ� 
*/
void InputNumber(int *number);
void PrintArray (int *arr, int number);
void InsertRandomArray (int *arr, int number);
void IncreasingArray (int *arr, int number);

int main() {
	srand(time(NULL));
	int n, i;
	int arr[10] = {0,};
	int *p = arr;
	
	printf("[Original Array]\n");
	
	//Insert Random values in the Array
	InsertRandomArray (p, 100);
	
	//Print Array
	PrintArray(p, 10);

	printf("\nInsert increasing value : ");
	
	//Input a number
	InputNumber(&n);
	
	printf("[After Increasing Array]\n");
	
	//Increase the number in the elements of Array
	IncreasingArray (p, n);
	
	//Print Array
	PrintArray(p, 10);
	
	return 0;
}


void InputNumber(int *number) {
	scanf("%d", number);
}

void PrintArray (int *arr, int number) {
	int i;
	for(i=0; i<number; i++) {
		printf("%d ", arr[i]);
	}
}

void InsertRandomArray (int *arr, int number) {
	int i;
	for(i=0; i<10; i++) {
		arr[i] = rand() % number+1;
	}
}

void IncreasingArray (int *arr, int number)
{
	int i;
	for(i=0; i<10; i++) {
		arr[i] += number;
	}
}
