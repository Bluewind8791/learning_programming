#include <stdio.h>

int IsLower (char input);
int IsUpper (char input);
int IsAlphabetic (char input);

int main() {
	char input;
	while (1) {
		printf("�Ѱ��� ���ڸ� �Է��ϼ���(0 �Է� �� exit): ");
		scanf(" %c", &input);
		if (input == '0') {
			break;
		}
		else if (IsAlphabetic(input)==1) {
			printf("�Է��Ͻ� ���� ���ĺ��Դϴ�.\n", input);
			if (IsLower(input)==1) {
				printf("�Է��Ͻ� ���� ���ĺ� �ҹ����Դϴ�.\n\n", input);
			}
			else if (IsUpper (input)==1) {
				printf("�Է��Ͻ� ���� ���ĺ� �빮���Դϴ�.\n\n", input);
			}
		}
		else {
			printf("�Է��Ͻ� ���� ���ĺ��� �ƴմϴ�.\n\n");
		}
	}
	return 0;
}

int IsLower (char input) {
	/*
	1. Description : ���ڰ� �ҹ������� �Ǵ��ϴ� �Լ�.
	2. Function : char input
	3. Return : 1�̸� �ҹ���, 0�̸� �ҹ��ڰ� �ƴ�. 
	*/
	if (input >= 'a' && input <= 'z') {
		return 1;
	}
	return 0;
}

int IsUpper (char input) {
	/*
	1. Description : ���ڰ� �빮������ �Ǵ��ϴ� �Լ�.
	2. Function : char input
	3. Return : 1�̸� �빮��, 0�̸� �빮�ڰ� �ƴ�. 
	*/
	if (input >= 'A' && input <= 'Z') {
		return 1;
	}
	return 0;
}

int IsAlphabetic (char input) {
	/*
	1. Description : ���ڰ� ���ĺ����� �Ǵ��ϴ� �Լ�.
	2. Function : char input
	3. Return : 1�̸� ���ĺ�, 0�̸� ���ĺ��� �ƴ�. 
	*/
	if ( IsUpper(input) ) {
		return 1;
	}
	else if ( IsLower(input) ) {
		return 1;
	}
	return 0;
}


/*
���ڸ� �Է����� �޾Ƽ�
�ҹ������� �˻��ϴ� IsLower �Լ�
�빮������ �˻��ϴ� IsUpper �Լ� ���� 

IsLower �Լ��� �ҹ��ڸ� 1 �ƴϸ� 0 return
IsUpper �Լ��� ��������

���� �� �Լ��� �̿��Ͽ� ���ĺ����� �˻��ϴ�
IsAlphabetic �Լ� ����

IsAlphabetic �Լ��� ���ĺ��̸� 1, �ƴϸ� 0 return 
*/
