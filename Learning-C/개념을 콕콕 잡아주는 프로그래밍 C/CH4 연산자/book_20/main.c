#include <stdio.h>
#include <stdlib.h>

/* 3���� ������ �Է¹޾Ƽ�
�հ�� ��� �ִ밪�� �ּҰ��� ����Ѵ�
����� �Ҽ��� ���ϱ��� */

int main(int argc, char *argv[]) 
{

int num1, num2, num3;
float avg;
	
	printf("Please input 3 numbers :");
	scanf(" %d %d %d", &num1, &num2, &num3);
	
	
	printf("SUM = %d\n", num1 + num2 + num3 );
	
	avg = (num1 + num2 + num3)/3;
	printf("AVERAGE = %.2f\n", avg );
	
	printf("MAX = %d\n", (num1 > num2) && (num1 > num3) ? num1 : ( (num2 > num3) ? num2 : num3 ));
	
	printf("MIN = %d\n", (num1 < num2) && (num1 < num3) ? num1 : ( (num2 < num3) ? num2 : num3 ) );
	
	
	return 0;
}
