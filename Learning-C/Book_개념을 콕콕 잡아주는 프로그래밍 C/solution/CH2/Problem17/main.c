

#include <stdio.h>

int main(void)
{
	// Methode 1 : Severial printf statements
	printf("-- Methode 1 : Several statements --\n");
	printf("�ȳ��ϼ���?\n");
	printf("�ݰ����ϴ�.\n");
	printf("�� ������.\n\n\n");
	
	// Methode 2  : One printf statement
	printf("-- Methode 2 : One statement --\n");
	printf("�ȳ��ϼ���?\n�ݰ����ϴ�.\n�Ǹ�����.\n\n\n"); 
	
	// Methode 3 : One printf statement
		printf("-- Methode 3  : One statement --\n");
	printf("�ȳ��ϼ���?\n" "�ݰ����ϴ�.\n" "�� ������.\n"); 
	
	return 0; 
}
