#include <stdio.h>

int main(int argc, char *argv[]) 

{
	
	int num, count, sum;
	
	scanf(" %d", &num);
	
	sum = 0;
	
	while(1)
	{
		
		sum = num + sum;
		num++;
	
		if ( num > 100 )
			break;
		
	}
		
	printf("%d", sum);
		
	return 0;
}

/*
100 ������ ������ �Է¹޾Ƽ� 
�Է¹��� �������� 
100������ ���� ����ϴ� 
���α׷��� �ۼ��Ͻÿ�.

*/
