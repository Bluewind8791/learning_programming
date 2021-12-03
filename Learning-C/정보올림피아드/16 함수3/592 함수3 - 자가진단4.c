#include <stdio.h>
#include <math.h>

int Recursive (int n) {
	if (n < 10) {
		return n*n;
	}
	return pow((n%10), 2) + Recursive(n/10);
}

int main()
{
	int n;
	
	scanf("%d", &n);
	
	printf("%d", Recursive(n));
	
	return 0;
}

/*
9�ڸ� ������ �ڿ����� �Է¹޾� 
����Լ��� �̿��Ͽ� 

�� �ڸ� ������ ������ ���� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

( main()�Լ��� ���� �ϳ�, 
����Լ��� �Ű����� �ϳ����� ����� �� �ִ�.)
*/

