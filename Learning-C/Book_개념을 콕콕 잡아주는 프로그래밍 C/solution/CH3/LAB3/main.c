


#include <stdio.h>

int main(void)
{
	int num;
	
	// 10진수 입력 
	printf("정수를 10진수로입력하세요 : ");
	scanf("%d", &num);
	printf("10진수:%d, 8진수:%o, 16진수:%x\n\n", num, num, num);
		
	// 16진수 입력  
	printf("정수를 16진수로입력하세요 : ");
	scanf("%x", &num);
	printf("10진수:%d, 8진수:%o, 16진수:%x\n\n", num, num, num);
	 
	// 8진수 입력 
	printf("정수를 8진수로입력하세요 : ");
	scanf("%o", &num);
	printf("10진수:%d, 8진수:%o, 16진수:%x\n\n", num, num, num);
		
	return 0;
		 
}
