#include <stdio.h>

int main(void)
{
	int menu;
	char ch;
	int num;
	int i, fact = 1;
	int loopOut = 0;
	
	while(1) {
		printf("1. 대소문자 확인\n");
		printf("2. 홀수 짝수 확인\n");
		printf("3. N 팩토리얼 구하기(N!)\n");
		printf("0. 종료\n");
		printf(">>> 선택 : ");
		scanf("%d", &menu);
		
		switch(menu) {
			case 1	:	
				printf("영문자를 입력하세요 : ");
				scanf(" %c", &ch);
				if(ch>='A' && ch<='Z') {
					printf("'%c'는 대문자입니다.\n", ch); 
				} 
				else if(ch>='a' && ch<='z') {
					printf("'%c'는 소문자입니다.\n", ch); 
				}
				else {
					printf("'%c'는 영문자가 아닙니다.\n", ch); 
				}
				break;
				
			case 2	:
				printf("정수를 입력하세요 : ");
				scanf("%d", &num);
				if(num == 0) {
					printf("%d는 짝수도 홀수도 아닙니다.\n", num); 
				} 
				else if(num%2 == 0) {
					printf("%d는 짝수입니다.\n", num); 
				}
				else {
					printf("%d는 홀수입니다.\n", num); 
				}
				break;
				
			case 3	:
				printf("정수를 입력하세요 : ");
				scanf("%d", &num);
				fact = 1;
				if(num == 0) {
					fact = 1;
				} 
				else {
					for(i=1; i<=num; i++) {
						fact *= i;
					}
				}
				printf("%d!는 %d입니다.\n", num, fact); 
				break;
				
			case 0	:
				loopOut = 1;
				break;
				
			default	:
				break;	
		} // switch
		
		if(loopOut == 1) {
			break;
		}
		
		printf("\n");
	} // while(1)
	
	return 0;
} // main()
