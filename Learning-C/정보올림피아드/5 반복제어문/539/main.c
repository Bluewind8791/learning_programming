#include <stdio.h>
int main( ) {

int num;
int sum = 0;
int count = 0;


for (num = 0; num < 100;)
{
	scanf(" %d", &num);
	sum += num;
	count++;
}

	printf("%d\n%.1f", sum, (float)sum/count);	

	return 0;
}

/*
������ ��� �Է¹޴ٰ� 100 �̻��� ���� �Է��� �Ǹ� ������ 
�Էµ� ���� �����Ͽ� �հ�� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
(����� �ݿø��Ͽ� �Ҽ� ù°�ڸ����� ����Ѵ�.)

*/
