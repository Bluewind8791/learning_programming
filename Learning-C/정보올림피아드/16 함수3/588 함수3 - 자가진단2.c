#include <stdio.h>

void RepeatPrint(int n) {
	printf("%d ", n);
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
�ڿ��� N�� �Է¹޾� 
����Լ��� �̿��Ͽ� 
N���� 1���� ���ʴ�� ����ϴ� 
���α׷��� �ۼ��Ͻÿ�. 

N�� 50������ �ڿ����̴�.
*/
