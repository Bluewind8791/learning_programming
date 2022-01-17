#include <stdio.h>

int main(void)
{
	int menu;
		
	while(1) {
		printf("1. 메뉴1\n");
		printf("2. 메뉴2\n");
		printf("3. 메뉴3\n"); 
		printf("0. 종료\n");
		printf(">>> 선택 : ");
		scanf("%d", &menu); 
		
		if(menu == 0) {
			break;
		}
					
		switch(menu) {
			case 1	: 	printf("메뉴1이 선택되었습니다.\n");
						break;
			case 2	: 	printf("메뉴2이 선택되었습니다.\n");
						break;
			case 3	: 	printf("메뉴3이 선택되었습니다.\n");
						break;
			default	: 	printf("잘못 선택하셨습니다..\n");
						break;	 
		} 
	} 
	
	return 0;
}
