#include <stdio.h>

int main(void) {
	
	int n;

	while(1)
	{
		printf("1. �޴�1\n2. �޴�2\n3. �޴�3\n0. ����\n>>> ���� : ");
		scanf(" %d", &n);

		if ( n == 0 )
			break;
		
		else if ( n >= 1 && n <=3 )
			printf("�޴�%d�� ���õǾ����ϴ�.\n", n);		
		
		else
			printf("�߸� �����ϼ̽��ϴ�.\n");

	}

	return 0;
}
