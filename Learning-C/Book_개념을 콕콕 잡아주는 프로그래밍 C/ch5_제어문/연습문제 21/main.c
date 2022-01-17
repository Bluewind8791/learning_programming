#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int menu, num, fnum, i, fact;
	char ch;
	
	while(1) {	
	
		printf("1. 대소문자 확인\n");
		printf("2. 홀수 짝수 확인\n");
		printf("3. N 팩토리얼 구하기(N!)\n");
		printf("0. 종료\n");
		printf(">>> 선택 : ");
		scanf(" %d", &menu);
		
		if (menu == 0) {
			break;}
			
		if (menu == 1) {
			printf("영문자를 입력하세요 : ");
			scanf(" %c", &ch);
			if (ch >= 'A' && ch <= 'Z') {
				printf("'%c'는 대문자입니다.\n\n", ch);
			}
			else if (ch >= 'a' && ch <= 'z') {
				printf("'%c'는 소문자입니다.\n\n", ch);
			}
			else {
				printf("'%c'는 영문자가 아닙니다.\n\n", ch);
			}
		}
		
		if (menu == 2) {
			printf("정수를 입력하세요 : ");
			scanf(" %d", &num);
			if (num == 0) {
				printf("%d는 홀수도 짝수도 아닙니다.\n\n");
			}
			else if (num % 2 == 0) {
				printf("%d는 짝수입니다.\n\n", num);
			}
			else {
				printf("%d는 홀수입니다.\n\n", num);
			}
		}
		
		if (menu == 3) {
			printf("정수를 입력하세요 : ");
			scanf(" %d", &fnum);
			if (fnum == 0) {
				fact = 1;
			}
			fact = 1;
			for (i=1; i<=fnum; i++) {
				fact *= i;
			}
			printf("%d!는 %d입니다.\n\n",fnum, fact);
		}

	}

	return 0;
}
