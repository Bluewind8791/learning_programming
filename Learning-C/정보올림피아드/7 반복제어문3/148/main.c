#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int x, y, n, k;
	scanf("%d", &n);
	
	for (y=0; y<n; y++) {
		for (x=0; x<1+y; x++) {
			printf("# ");
		}
		printf("\n");
	}

	for (y=1; y<n; y++) {
		for (x=0; x<y; x++) {
			printf("  ");
		}
		for (x=0; x<n-y; x++) {
			printf("# ");
		}
		
		printf("\n");
	}
	return 0;
}

/* 
148 : 반복제어문3 - 형성평가9

insert 3

#
# #
# # #
  # #
    #

주의! '#'은 공백으로 구분하되 줄사이에 빈줄은 없다.

*/

