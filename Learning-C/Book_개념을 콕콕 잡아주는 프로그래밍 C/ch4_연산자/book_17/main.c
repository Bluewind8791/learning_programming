#include <stdio.h>


/*연도를 4로 나누어 떨어지면 윤년이다. 4로 나누어 떨어지는 연도 중에서 100으로
나누어 떨어지는 연도는 윤년이 아니다. 100으로 나누어 떨어지는 연도중에서
400으로 나누어 떨어지는 연도는 윤년이다.*/

//참 = 1 거짓 = 0 

int main() {
	
	int year, yun, yun1, yun2;
	char yes[] = "윤년입니다.";
	char no[] = "윤년이 아닙니다.";
	
	printf("연도를 입력해 주세요 : ");
	scanf(" %d", &year);
	

	
	
	yun = ( (year % 4) == 0 ) ? yes : no ;
	printf("연도를 4로 나누어 떨어지면 : %s\n", yun);
	
	
	yun1 = ( ((year % 4) == 0) && ((year % 100) != 0)  ) ? yes : no ;
	printf("그 중에서 100으로 나누어 안 떨어지면 : %s\n", yun1);
	
	
	
	
	yun2 = ( ( ((year % 4) == 0) && ((year % 100) != 0)  ) \
	    ||  ( year % 400 ) == 0 ) ? yes : no ;
	printf("입력하신 년도는 %s\n", yun2);
	
	
	yun2 = ( ( ((year % 4) == 0) && ((year % 100) != 0)  ) 
	    ||  ( year % 400 ) == 0 ) ? yes : no ;
	
	
	
	
	
	return 0;
}
