#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int menu, num, fnum, i, fact;
	char ch;
	
	while(1) {	
	
		printf("1. ��ҹ��� Ȯ��\n");
		printf("2. Ȧ�� ¦�� Ȯ��\n");
		printf("3. N ���丮�� ���ϱ�(N!)\n");
		printf("0. ����\n");
		printf(">>> ���� : ");
		scanf(" %d", &menu);
		
		if (menu == 0) {
			break;}
			
		if (menu == 1) {
			printf("�����ڸ� �Է��ϼ��� : ");
			scanf(" %c", &ch);
			if (ch >= 'A' && ch <= 'Z') {
				printf("'%c'�� �빮���Դϴ�.\n\n", ch);
			}
			else if (ch >= 'a' && ch <= 'z') {
				printf("'%c'�� �ҹ����Դϴ�.\n\n", ch);
			}
			else {
				printf("'%c'�� �����ڰ� �ƴմϴ�.\n\n", ch);
			}
		}
		
		if (menu == 2) {
			printf("������ �Է��ϼ��� : ");
			scanf(" %d", &num);
			if (num == 0) {
				printf("%d�� Ȧ���� ¦���� �ƴմϴ�.\n\n");
			}
			else if (num % 2 == 0) {
				printf("%d�� ¦���Դϴ�.\n\n", num);
			}
			else {
				printf("%d�� Ȧ���Դϴ�.\n\n", num);
			}
		}
		
		if (menu == 3) {
			printf("������ �Է��ϼ��� : ");
			scanf(" %d", &fnum);
			if (fnum == 0) {
				fact = 1;
			}
			fact = 1;
			for (i=1; i<=fnum; i++) {
				fact *= i;
			}
			printf("%d!�� %d�Դϴ�.\n\n",fnum, fact);
		}

	}

	return 0;
}
