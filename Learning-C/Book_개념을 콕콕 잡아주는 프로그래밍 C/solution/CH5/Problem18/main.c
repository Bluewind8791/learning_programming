
#include <stdio.h>

int main(void)
{
	int num;
	char yesOrNo;
		
	do {
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
		
		printf("계속 하시겠습니까? (Y/N) ");
		scanf(" %c", &yesOrNo);
	} while(yesOrNo=='y' || yesOrNo=='Y');

	return 0;
}
