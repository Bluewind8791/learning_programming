#include <stdio.h>
#define SIZE 10

int main () {
	
	int array[] = {88, 123, 659, 15, 443, 1, 99, 313, 105, 48};
	int i, j, temp, min, max;
	
	printf("�������� ����\n");
	for (i=0; i<SIZE-1; i++) {
		min = i;
		for (j=i+1;j<SIZE;j++) {
			if (array[min]>array[j]) {
				min = j;
			}
		}
		temp = array[min];
		array[min] = array[i];
		array[i] = temp;
	}
	
	for (i=0;i<SIZE;i++) {
		printf("%d ",array[i]);
	}
	printf("\n\n");
	
	printf("�������� ����\n");
	for (i=0;i<SIZE-1;i++) {
		max = i;
		for (j=i+1;j<SIZE;j++) {
			if(array[max]<array[j]) {
				max = j;
			}
		}
		temp = array[max];
		array[max] = array[i];
		array[i] = temp;
	}
	
	for (i=0;i<SIZE;i++) {
		printf("%d ",array[i]);
	}
	
	
	return 0;
}
