#include <stdio.h>

int GetFact (int n) {
	if (n <= 1) {
		return 1;
	}
	return n + GetFact(n - 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	printf("%d",GetFact(n));
	
	return 0;
}

/*
100 ������ �ڿ��� N�� �Է¹޾� 

����Լ��� �̿��Ͽ� 
1���� N������ 
���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
