#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int num, sum, count;
	float avg;
	
	sum = 0;
	count = 0;
	
	while(1)
	{
		scanf(" %d", &num);
	
		if ( (num < 0) || (num > 100) )
			break;
		
		sum += num;
		count++;
	}
	
	avg = (float)sum/count;
	
	printf("sum : %d\navg : %.1f", sum, avg);
	
	return 0;
}

/*
0 ���� 100 ������ ������ ��� �Է¹޴ٰ� 
������ ����� ���� �ԷµǸ� 
�� �������� �Էµ� �ڷ��� 
�հ�� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

(����� �ݿø��Ͽ� �Ҽ� ù°�ڸ����� ����Ѵ�.)*/
