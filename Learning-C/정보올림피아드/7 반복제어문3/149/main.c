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
 149 : �ݺ����3 - ������A

1 3 5
7 9 1
3 5 7

10 �̸��� Ȧ���� ����Ͻÿ�.
*/

