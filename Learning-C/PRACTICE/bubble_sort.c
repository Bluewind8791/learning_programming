#include <stdio.h>
#define SIZE 10

int main () {
	
	int array[] = {88, 123, 659, 15, 443, 1, 99, 313, 105, 48};
	int i, j, temp, min, max;
	
	printf("오름차순 정렬\n");
	
	for(i=0; i<SIZE; i++) {
		for(j=0; j<9-i; j++) {
			if (array[j] > array[j+1]) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	
	for(i=0; i<SIZE; i++) {
		printf("%d ",array[i]);
	}
	printf("\n");
	
	printf("내림차순 정렬\n");
	
	for(i=0; i<SIZE; i++) {
		for(j=0; j<9-i; j++) {
			if (array[j] < array[j+1]) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	
	for(i=0; i<SIZE; i++) {
		printf("%d ",array[i]);
	}
	
	

	return 0;
}
