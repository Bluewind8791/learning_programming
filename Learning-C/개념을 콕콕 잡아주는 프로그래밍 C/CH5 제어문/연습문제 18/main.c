/*
	Name: Book_Chapter 5_Q18
	Copyright: none
	Author: Kyung_bin Kim
	Date: 06-04-21 14:16
	Description: Question 18, Ȧ������ �ƴ��� �Ǵ��ϴ� ���α׷� 
*/

#include <stdio.h>

int main(void) {
	
	int n;
	char cont;
	
	while(1) {
		
		printf("������ �Է��ϼ��� : ");
		scanf(" %d", &n);
		
		if (n % 2 == 0){
			printf("%d�� ¦���Դϴ�.\n", n);
		}
		
		else {
			printf("%d�� Ȧ���Դϴ�.\n", n);
		}
		
		
		printf("��� �Ͻðڽ��ϱ�? (Y/N) ");
		scanf(" %c", &cont);	
		
		if (cont == 'N' || cont == 'n') {
			break;}
		
		if (cont == 'y' || cont == 'Y') {
			continue;}
	
	
	
	
	}

	return 0;
}

 
