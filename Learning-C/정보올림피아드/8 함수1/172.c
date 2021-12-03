#include <stdio.h>

int Gugudan (int times, int num) {
	int x;
	for (x=1; x<=num; x++) {
		printf("%d ", times*x);
	}
}

int Square (int n) {
	int y, one = 1;
	for (y=0; y<n; y++) {
		one = 1 + y;
		Gugudan (one, n);
		printf("\n");
	}
}

int main() {
	
	int num;
	scanf("%d", &num);
	
	Square (num);
	
	return 0;
}

/*
 172 : 함수1 - 형성평가3

자연수를 입력받아 
아래와 같은 사각형을 
출력하는 프로그램을 작성하시오.

주어지는 수는 100이하의 자연수이다.
3
1 2 3
2 4 6
3 6 9

*/
