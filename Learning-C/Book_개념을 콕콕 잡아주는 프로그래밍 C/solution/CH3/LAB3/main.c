


#include <stdio.h>

int main(void)
{
	int num;
	
	// 10���� �Է� 
	printf("������ 10�������Է��ϼ��� : ");
	scanf("%d", &num);
	printf("10����:%d, 8����:%o, 16����:%x\n\n", num, num, num);
		
	// 16���� �Է�  
	printf("������ 16�������Է��ϼ��� : ");
	scanf("%x", &num);
	printf("10����:%d, 8����:%o, 16����:%x\n\n", num, num, num);
	 
	// 8���� �Է� 
	printf("������ 8�������Է��ϼ��� : ");
	scanf("%o", &num);
	printf("10����:%d, 8����:%o, 16����:%x\n\n", num, num, num);
		
	return 0;
		 
}
