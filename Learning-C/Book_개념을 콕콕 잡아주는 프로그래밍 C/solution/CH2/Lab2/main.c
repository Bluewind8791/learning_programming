


#include <stdio.h>

int main(void)
{
	char ch;
	int intVal;
	float floatVal;
	
	printf("문자를 입력하세요 : ");
	scanf("%c", &ch);
	
	printf("정수를 입력하세요 : ");
	scanf("%d", &intVal);
	
	printf("실수를 입력하세요 : ");
	scanf("%f", &floatVal);
	
	printf("문자 = %c, 정수 = %d, 실수 = %f\n", ch, intVal, floatVal);
	
	return 0; 
}
