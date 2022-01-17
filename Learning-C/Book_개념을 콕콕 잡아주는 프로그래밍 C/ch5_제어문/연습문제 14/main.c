#include <stdio.h>

int main(void) {
	
	int num;
	
	printf("정수를 입력하세요 : ");
	scanf("%d", &num);
	
	switch (num % 2)
	{
		case 0 :
			(num==0) ? printf("%d는 짝수도 홀수도 아닙니다.\n", num) :
				printf("%d는 짝수입니다.\n", num);
			break;
		case 1 :
			printf("%d는 홀수입니다.\n", num);
			break;
		default : break;
	}


	return 0;
}
