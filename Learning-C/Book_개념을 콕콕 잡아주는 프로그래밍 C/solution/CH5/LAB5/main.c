
/* Lab05.c */

#include <stdio.h>

int main(void)
{
	char ch;
	
	while(1) {
		printf("�����ڸ� �Է��ϼ��� : ");
		scanf(" %c", &ch);
		
		if(ch == '.') {
			break;
		}
	
		printf("'%c'�� ",  ch);
		if(ch>='A' && ch<='Z') {
			printf("�빮�� �Դϴ�.\n"); 
		} 
		else if(ch>='a' && ch<='z') {
			printf("�ҹ��� �Դϴ�.\n"); 
		}
		else {
			printf("�����ڰ� �ƴմϴ�.\n"); 
		}
	}
	
	return 0;
}


