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
148 : �ݺ����3 - ������9

insert 3

#
# #
# # #
  # #
    #

����! '#'�� �������� �����ϵ� �ٻ��̿� ������ ����.

*/

