#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int num, count;
	
	
	count = 0;
	
	while(1)
	{
		scanf(" %d", &num);
			
		if (num == 0)
			break;
		
		else if (num % 3 != 0 && num % 5 != 0)
			count++;
	}
	
	printf("%d",count);
		
	return 0;
}

/*
0 �� �Էµ� ������ 
������ ��� �Է¹޾� 
3�� ����� 5�� ����� ������ ������ 
������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/


