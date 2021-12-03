#include <stdio.h>

void GuGuDan (int n, int n2) {
	int x, y;
	if (n>n2) {
		for (y=0; y<=n-n2; y++) {
				printf("== %ddan ==\n", n2+y);
				for (x=1; x<=9; x++) {
					printf("%d * %d = %2d\n", n2+y, x, x*(n2+y));
			}
			printf("\n");
		}		
	}
	else {
		for (y=0; y<=n2-n; y++) {
				printf("== %ddan ==\n", n+y);
				for (x=1; x<=9; x++) {
					printf("%d * %d = %2d\n", n+y, x, x*(n+y));
			}
			printf("\n");
		}
	}
}

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	GuGuDan (a, b);	
	return 0;
}

/* 
 578 : 함수1 - 자가진단8

10 이하의 두 개의 양의 정수를 입력받아서 
작은 수부터 큰 수까지의 구구단을 
차례대로 출력하는 프로그램을 구조화하여 작성하시오.

*/

