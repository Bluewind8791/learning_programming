#include <stdio.h>

void RepeatPrint(int n) {
	printf("recursive\n");
	if(n <= 1) {
		return 1;
	}
	return RepeatPrint(n-1);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	RepeatPrint(n);
	
	return 0;
}

/*
20 ������ �ڿ��� N�� �Է¹޾� 

����Լ��� �̿��ؼ� 

���ڿ� ��recursive���� 

N�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
