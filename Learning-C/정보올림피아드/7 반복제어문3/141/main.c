#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int n, i;
	
	scanf("%d", &n);
	
	i = 0;
	
	while(1)
	{
	i++;
	
		if( n*i > 99 )
		{break;
		}
		
	printf("%d ", n*i);
	
	if( (n*i) % 10 == 0)
		{break;
		}
	
	}
	
	return 0;
}

/*1���� 100������ ���� �� 
�� ���� �Է¹޾� 
100 ���� ���� ������� 
���ʷ� ����ϴٰ� 

10 �� ����� ��µǸ� 
���α׷��� �����ϵ��� ���α׷��� �ۼ��Ͻÿ�.
*/

