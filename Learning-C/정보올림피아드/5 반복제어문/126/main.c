#include <stdio.h>
int main(int argc, char *argv[]) {
	
	int num;
	int odd = 0;
	int even = 0;
	
	while(1)
	{
		scanf(" %d", &num);
		
		if (num == 0)
			break;

		else if( num % 2 == 0 )
			even++;
				
		else if ( num % 2 != 0 )
			odd++;
			
	}
	
	printf("odd : %d\n", odd);
	printf("even : %d", even);
		
	
	return 0;
}

/*
0 �̻��� �������� �������� ���еǾ� �ݺ������� �־�����.

0�� �ԷµǸ� �ݺ����� ���߰� �� ������ �Է¹��� ���鿡 ���Ͽ�

Ȧ���� ������ ¦���� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
