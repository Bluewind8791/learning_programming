#include <stdio.h>

#define SIZE 3

int main(void)
{
	int matrix_A[SIZE][SIZE] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
	int matrix_B[SIZE][SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int matrix_Sub[SIZE][SIZE] = {0};
	int i, j;
	
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			matrix_Sub[i][j] = matrix_A[i][j] - matrix_B[i][j];
		}
	}

	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			printf("%4d", matrix_Sub[i][j]);
		}
		printf("\n");
	}

	return 0;
}
