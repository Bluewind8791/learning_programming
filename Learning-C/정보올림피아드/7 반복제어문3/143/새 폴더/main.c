#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, x, y, k;
	scanf("%d", &n);
	
	for (y=0; y<n; y++){
		for (x=0; x<y; x++){
			printf(" ");
		}
		for (x=0; x<2*n-1-2*y; x++){
			printf("*");
		}
		printf("\n");
	}		

	for (y=n, k=0; y<2*n-1; y++, k++){
		for (x=0; x<n-2-k; x++){
			printf(" ");
		}
		for (x=0; x<3+2*k; x++){
			printf("*");
		}
		printf("\n");
	}
	

	return 0;
}
