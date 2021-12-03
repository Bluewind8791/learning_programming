#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, x, y, num;
	num = 1;
	scanf("%d", &n);
	for(y=0; y<n; y++) {
		for (x=0; x<n; x++) {
			printf("%d ",num);
			num += 2;
			if (num > 10) {
				num = 1;
			}
		}
		printf("\n");
	}
	return 0;
}


/* 
 149 : 반복제어문3 - 형성평가A

1 3 5
7 9 1
3 5 7

10 미만의 홀수만 출력하시오.
*/

