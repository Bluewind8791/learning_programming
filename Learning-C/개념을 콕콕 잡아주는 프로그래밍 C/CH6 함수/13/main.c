#include <stdio.h>

double Absolute (float num) {
	double abs;
	if (num >= 0) {
		abs = num;
	}
	if (num < 0) {
		abs = num * -1;
	}
	return abs;
}

int main(int argc, char *argv[]) {
	double n;
	scanf("%lf", &n);
	
	printf("%lf's absoulte value = %lf", n, Absolute (n));
	
	return 0;
}

/* �Ǽ����� ���ڷ� �޾Ƽ�
���밪�� ���ϴ�
Absolute �Լ��� �����Ͻÿ�
*/ 
