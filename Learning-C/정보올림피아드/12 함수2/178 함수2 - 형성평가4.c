#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int i;
	int pow = 2;
	

	for(i=2; i<=n; i++)
	{
		pow = pow * 2;
	}	
	
	printf("%d", pow );
	
	return 0;
}

/*
���� n�� �Է¹޾� 
2^n�� ���� ����ϴ� 
���α׷��� �ۼ��Ͻÿ�. 
(1 �� n �� 20)
*/
