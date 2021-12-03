#include <stdio.h>

int IsLeapYear (int y);

int main() {
	int year;					//�Է¹޴� ���� ��
	while(1) {
		printf("������ �Է��ϼ��� (0 �Է� �� ����) : ");
		scanf("%d", &year);
		
		if (year == 0) {
			break;	}
			
		IsLeapYear(year) ? printf("'%d'�� �����Դϴ�.\n", year)
			: printf("'%d'�� ������ �ƴմϴ�.\n", year);
	}
	return 0;
}

int IsLeapYear (int y) {
	/*
	1. Description : �������� �ƴ��� �Ǵ��ϴ� �Լ�. 
	2. Function : int y (���ڰ�) 
	3. Return : �����̸� 1, ������ �ƴϸ� 0. 
	*/
	
	if ( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ) 
	{
		return 1;
	}
	
	else 
	{
		return 0;
	}
}

/*
������ ���ڷ� �޾Ƽ� �������� �Ǵ��ϴ� IsLeapYear �Լ� ����

�Լ��� �����̸� 1
�׷��� ������ 0�� ����

4�� ������ �������� ���� 1
���߿��� 100���� ������ �������� ���� 0 
���� 400���� ������ �������� 1 
*/
