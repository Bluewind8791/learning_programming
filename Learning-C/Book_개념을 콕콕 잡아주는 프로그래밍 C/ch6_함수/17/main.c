#include <stdio.h>

int IsPrime (int n);

int main() {
	int num, x;
	
	printf("1 ���� 100 ������ �Ҽ���...\n");
	for (x=1; x<=100; x++) {
		IsPrime(x) ? printf("%d ", x) : printf(""); ;
	}printf("\n\n");
		
	while (1) {	
		printf("������ �Է��ϼ��� (0 �Է� �� ����) : ");
		scanf("%d", &num);
		if (num == 0) {
			break;
		}
		else if (IsPrime(num)==1) {
			printf("'%d'�� �Ҽ��Դϴ�.\n",num);
		}
		else if (IsPrime(num)==0){
			printf("'%d'�� �Ҽ��� �ƴմϴ�.\n", num);
		}
	}
	return 0;
}

int IsPrime (int n) {
	/*
	1. Description : �Է¹��� ���ڰ� �Ҽ����� �ƴ��� �Ǵ��ϴ� �Լ�. 
	2. Function : int n (����), x(��������)
	3. Return : 1 or 0 (�Ҽ���� 1, �ƴϸ� 0) 
	*/
	int x;
	for (x=2;x<=n-1;x++) {
	//x�� 2���� n-1���� �ϳ��� �÷����鼭 �������� ������ �Ҽ��� �ƴϴ� 
		if (n % x == 0) {
			return 0;	}
	}
	return 1;
}


/*
�������� ���ڷ� �޾Ƽ�
�Ҽ����� �Ǵ��ϴ� IsPrime �Լ� ����.

�Լ��� �̿��ؼ� 1���� 100������
�Ҽ��� ��� ���ؼ� ����ϴ� ���α׷� 
*/

