#include <stdio.h>

#define SIZE 10

int main(void)
{
	int arry[SIZE] = {0, 100, 200, 300, 400, 500, 600, 700, 800, 900};
	int i, firstFoundIndex;
	int searchElement;
	
	printf("Input search element : ");
	scanf("%d", &searchElement);
	
	for(i=0; i<SIZE; i++) {
		if(arry[i] == searchElement) {
			firstFoundIndex = i;
			break;
		}
	}
	
	if(i == SIZE) {
		printf("There is no such element\n");
	}
	else {
		printf("Element's Index : %d\n", firstFoundIndex); 
	}

	return 0;
}
