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
�ڿ��� n(n��6)�� �Է¹޾� 
"��� ��"�� ���� �������� �����Ͽ� 
��µǴ� ���α׷��� �ۼ��Ͻÿ�.

����! ���ڴ� �������� �����ϵ� �ٻ��̿� ������ ����.

A B C
D E 0
F 1 2

 */

