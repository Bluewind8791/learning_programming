#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int n, x, y;
	int num = 1;
	scanf("%d",&n);
	for(y=0; y<n; y++) {
		for (x=0; x<y; x++) {
			printf("  ");
		}
		for (x=0; x<n-y; x++) {
			printf("%d ", num++);
		}
		printf("\n");
	}
	return 0;
}

/*

자연수 n을 입력받아 "출력 예"와 같이 
공백으로 구분하여 출력되는 프로그램을 작성하시오.

1 2 3
  4 5
    6  
    
*/
