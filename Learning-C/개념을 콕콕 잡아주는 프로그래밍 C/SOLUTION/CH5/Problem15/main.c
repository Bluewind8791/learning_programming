

#include <stdio.h>

int main(void)
{
	int menu;
	
	printf("1. �޴�1\n");
	printf("2. �޴�2\n");
	printf("3. �޴�3\n"); 
	
	printf(">>> ���� : ");
	scanf("%d", &menu); 

	switch(menu) {
		case 1	: 	printf("�޴�1�� ���õǾ����ϴ�.\n");
					break;
		case 2	: 	printf("�޴�2�� ���õǾ����ϴ�.\n");
					break;
		case 3	: 	printf("�޴�3�� ���õǾ����ϴ�.\n");
					break;
		default	: 	printf("1 ~ 3 ������ ���� �Է��ϼ���.\n");
					break;	 
	} 
	
	return 0;
}
