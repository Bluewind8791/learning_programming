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
100 �̸��� ������ �Էµȴ�. 
���� n�� �Է¹޾� 
n x n ũ���� ���ڻ簢���� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�̶� ���� n�� ���޹޾� 
���� ���簢���� ����ϴ� �Լ��� �ۼ��ϰ�, 
�Է¹��� ���� n�� �Լ��� �����Ͽ� ����Ѵ�.




*/

