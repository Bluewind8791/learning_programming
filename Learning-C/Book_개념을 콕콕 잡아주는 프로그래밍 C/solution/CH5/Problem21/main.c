#include <stdio.h>

int main(void)
{
	int menu;
	char ch;
	int num;
	int i, fact = 1;
	int loopOut = 0;
	
	while(1) {
		printf("1. ��ҹ��� Ȯ��\n");
		printf("2. Ȧ�� ¦�� Ȯ��\n");
		printf("3. N ���丮�� ���ϱ�(N!)\n");
		printf("0. ����\n");
		printf(">>> ���� : ");
		scanf("%d", &menu);
		
		switch(menu) {
			case 1	:	
				printf("�����ڸ� �Է��ϼ��� : ");
				scanf(" %c", &ch);
				if(ch>='A' && ch<='Z') {
					printf("'%c'�� �빮���Դϴ�.\n", ch); 
				} 
				else if(ch>='a' && ch<='z') {
					printf("'%c'�� �ҹ����Դϴ�.\n", ch); 
				}
				else {
					printf("'%c'�� �����ڰ� �ƴմϴ�.\n", ch); 
				}
				break;
				
			case 2	:
				printf("������ �Է��ϼ��� : ");
				scanf("%d", &num);
				if(num == 0) {
					printf("%d�� ¦���� Ȧ���� �ƴմϴ�.\n", num); 
				} 
				else if(num%2 == 0) {
					printf("%d�� ¦���Դϴ�.\n", num); 
				}
				else {
					printf("%d�� Ȧ���Դϴ�.\n", num); 
				}
				break;
				
			case 3	:
				printf("������ �Է��ϼ��� : ");
				scanf("%d", &num);
				fact = 1;
				if(num == 0) {
					fact = 1;
				} 
				else {
					for(i=1; i<=num; i++) {
						fact *= i;
					}
				}
				printf("%d!�� %d�Դϴ�.\n", num, fact); 
				break;
				
			case 0	:
				loopOut = 1;
				break;
				
			default	:
				break;	
		} // switch
		
		if(loopOut == 1) {
			break;
		}
		
		printf("\n");
	} // while(1)
	
	return 0;
} // main()
