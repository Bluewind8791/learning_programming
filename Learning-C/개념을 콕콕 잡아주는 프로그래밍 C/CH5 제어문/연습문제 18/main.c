/*
	Name: Book_Chapter 5_Q18
	Copyright: none
	Author: Kyung_bin Kim
	Date: 06-04-21 14:16
	Description: Question 18, 홀수인지 아닌지 판단하는 프로그램 
*/

#include <stdio.h>

int main(void) {
	
	int n;
	char cont;
	
	while(1) {
		
		printf("정수를 입력하세요 : ");
		scanf(" %d", &n);
		
		if (n % 2 == 0){
			printf("%d는 짝수입니다.\n", n);
		}
		
		else {
			printf("%d는 홀수입니다.\n", n);
		}
		
		
		printf("계속 하시겠습니까? (Y/N) ");
		scanf(" %c", &cont);	
		
		if (cont == 'N' || cont == 'n') {
			break;}
		
		if (cont == 'y' || cont == 'Y') {
			continue;}
	
	
	
	
	}

	return 0;
}

 
