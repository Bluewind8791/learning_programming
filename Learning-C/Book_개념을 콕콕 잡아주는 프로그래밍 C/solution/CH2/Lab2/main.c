


#include <stdio.h>

int main(void)
{
	char ch;
	int intVal;
	float floatVal;
	
	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%c", &ch);
	
	printf("������ �Է��ϼ��� : ");
	scanf("%d", &intVal);
	
	printf("�Ǽ��� �Է��ϼ��� : ");
	scanf("%f", &floatVal);
	
	printf("���� = %c, ���� = %d, �Ǽ� = %f\n", ch, intVal, floatVal);
	
	return 0; 
}
