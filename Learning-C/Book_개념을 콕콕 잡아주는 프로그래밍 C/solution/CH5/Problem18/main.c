
#include <stdio.h>

int main(void)
{
	int num;
	char yesOrNo;
		
	do {
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
		
		printf("��� �Ͻðڽ��ϱ�? (Y/N) ");
		scanf(" %c", &yesOrNo);
	} while(yesOrNo=='y' || yesOrNo=='Y');

	return 0;
}
