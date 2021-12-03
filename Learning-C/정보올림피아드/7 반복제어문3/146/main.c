#include <stdio.h>

int main(int argc, char *argv[]) {

	int n, x, y;
	char ch;
	ch = 'A';
	int num = 0;
	scanf(" %d", &n);
	
	for (y=0; y<n; y++) {
		for (x=0; x<n-y; x++) {
			printf("%c ", ch++);
		}
		for (x=0; x<y; x++) {
			printf("%d ", num++);
		}
		printf("\n");
	} 
	return 0;
}



/* 
자연수 n(n≤6)을 입력받아 
"출력 예"와 같이 공백으로 구분하여 
출력되는 프로그램을 작성하시오.

주의! 문자는 공백으로 구분하되 줄사이에 빈줄은 없다.

A B C
D E 0
F 1 2

 */

