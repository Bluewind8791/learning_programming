

#include <stdio.h>

int main(void)
{
	int menu;
	
	printf("1. 메뉴1\n");
	printf("2. 메뉴2\n");
	printf("3. 메뉴3\n"); 
	
	printf(">>> 선택 : ");
	scanf("%d", &menu); 

	switch(menu) {
		case 1	: 	printf("메뉴1이 선택되었습니다.\n");
					break;
		case 2	: 	printf("메뉴2이 선택되었습니다.\n");
					break;
		case 3	: 	printf("메뉴3이 선택되었습니다.\n");
					break;
		default	: 	printf("1 ~ 3 사이의 값을 입력하세요.\n");
					break;	 
	} 
	
	return 0;
}
