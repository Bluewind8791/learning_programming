#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int sixteen;
	
	printf("16진수로 정수를 입력하세요 : ");
	scanf(" %x", &sixteen );
	
	printf("%x는 10진수로 %d입니다.", sixteen, sixteen);
	
	return 0;
}
