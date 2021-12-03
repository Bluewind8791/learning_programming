#include <stdio.h>

Square (int a) {
	int x, y, one = 1;
	for (y=0; y<a; y++) {
		for (x=0; x<a; x++) {
			printf("%d ", one++);
		}
		printf("\n");
	}
	return a;
}

int main(int argc, char *argv[]) {
	
	int n;
	scanf("%d", &n);
	
	Square (n);

	return 0;
}

/* 
100 미만의 정수만 입력된다. 
정수 n을 입력받아 
n x n 크기의 숫자사각형을 
출력하는 프로그램을 작성하시오.

이때 정수 n을 전달받아 
숫자 정사각형을 출력하는 함수를 작성하고, 
입력받은 정수 n을 함수로 전달하여 출력한다.




*/

