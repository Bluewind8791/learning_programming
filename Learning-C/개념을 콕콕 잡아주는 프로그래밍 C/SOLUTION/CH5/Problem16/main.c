#include <stdio.h>

int main(void)
{
	int menu;
		
	while(1) {
		printf("1. �޴�1\n");
		printf("2. �޴�2\n");
		printf("3. �޴�3\n"); 
		printf("0. ����\n");
		printf(">>> ���� : ");
		scanf("%d", &menu); 
		
		if(menu == 0) {
			break;
		}
					
		switch(menu) {
			case 1	: 	printf("�޴�1�� ���õǾ����ϴ�.\n");
						break;
			case 2	: 	printf("�޴�2�� ���õǾ����ϴ�.\n");
						break;
			case 3	: 	printf("�޴�3�� ���õǾ����ϴ�.\n");
						break;
			default	: 	printf("�߸� �����ϼ̽��ϴ�..\n");
						break;	 
		} 
	} 
	
	return 0;
}
