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
 172 : �Լ�1 - ������3

�ڿ����� �Է¹޾� 
�Ʒ��� ���� �簢���� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�־����� ���� 100������ �ڿ����̴�.
3
1 2 3
2 4 6
3 6 9

*/
