#include <stdio.h>

int main(void) {
	
	int n;

	while(1)
	{
		printf("1. 메뉴1\n2. 메뉴2\n3. 메뉴3\n0. 종료\n>>> 선택 : ");
		scanf(" %d", &n);

		if ( n == 0 )
			break;
		
		else if ( n >= 1 && n <=3 )
			printf("메뉴%d이 선택되었습니다.\n", n);		
		
		else
			printf("잘못 선택하셨습니다.\n");

	}

	return 0;
}
