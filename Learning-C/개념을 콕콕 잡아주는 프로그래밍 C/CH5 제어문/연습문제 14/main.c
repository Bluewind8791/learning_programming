#include <stdio.h>

int main(void) {
	
	int num;
	
	printf("������ �Է��ϼ��� : ");
	scanf("%d", &num);
	
	switch (num % 2)
	{
		case 0 :
			(num==0) ? printf("%d�� ¦���� Ȧ���� �ƴմϴ�.\n", num) :
				printf("%d�� ¦���Դϴ�.\n", num);
			break;
		case 1 :
			printf("%d�� Ȧ���Դϴ�.\n", num);
			break;
		default : break;
	}


	return 0;
}
