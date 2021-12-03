#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int n, y, x, num;
	scanf(" %d", &n);
	
	
	for (y=0; y<n; y++){
		num = 0;

		for (x=0; x<n-1-y; x++){
			printf("  ");		
		}
		for (x=0; x<y+1; x++){
			num = num + 1;
			printf("%2d", num);
			
		}printf("\n");
	}
	return 0;
}
