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
 578 : �Լ�1 - �ڰ�����8

10 ������ �� ���� ���� ������ �Է¹޾Ƽ� 
���� ������ ū �������� �������� 
���ʴ�� ����ϴ� ���α׷��� ����ȭ�Ͽ� �ۼ��Ͻÿ�.

*/

