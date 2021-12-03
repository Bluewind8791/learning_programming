#include <stdio.h>
#include <stdlib.h>
//qsort �Լ� ���� ���  

int Compare (const void *e1, const void *e2);
void PrintArray (const int* arr, int size);

int main()
{
	int x[10] = {34, 50,5,17,82,66,73,1,48,29};
	
	printf("���� �� : ");
	PrintArray(x, 10);
	
	//qsort �Լ��� ȣ��  
	qsort(x, 10, sizeof(int), Compare);
	
	printf("���� �� : ");
	PrintArray(x, 10);	
	
	return 0;
 }
 
int Compare (const void *e1, const void *e2)
{
	int *p1 = (int*) e1;
	int *p2 = (int*) e2;
	return (*p1 - *p2); 	
}

void PrintArray(const int* arr, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("%d ", arr[i]);
	}printf("\n");
}
