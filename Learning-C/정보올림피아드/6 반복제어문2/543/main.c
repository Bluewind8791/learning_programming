#include <stdio.h>

int main(int argc, char *argv[]) 
{
	
	int num,i;
	
	scanf(" %d", &num);
	
	i = 1;
	
	while (1)
	{
	
	i++;
	if ( i % 2 == 0)
		printf("%d ", i);
	
	else if ( i >= num )
		break;
		
	}
	
	return 0;
}

/*
�ϳ��� ������ �Է¹޾� 
1���� �Է¹��� ���������� 
¦���� ���ʴ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�ԷµǴ� ������ 50�����̴�.
*/
