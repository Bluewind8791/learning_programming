#include <stdio.h>

int OnetoNum (int num) {
	int x;
	int sum = 0;
	for (x=1; x<=num; x++) {
		sum = x + sum;
	}
	return sum;
}


int main(int argc, char *argv[]) {
	int num;
	scanf(" %d", &num);
	printf("%d", OnetoNum(num));
	return 0;
}

/*
 171 : �Լ�1 - ������2

1���� ���޹��� �������� ���� ����ϴ� �Լ��� �ۼ��ϰ� 
1000 ������ �ڿ����� �Է¹޾� 
�ۼ��� �Լ��� �����Ͽ� ����ϴ� 
���α׷��� �ۼ��Ͻÿ�.

*/
