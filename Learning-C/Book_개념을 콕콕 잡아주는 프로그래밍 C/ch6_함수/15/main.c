#include <stdio.h>

int IsLeapYear (int y);

int main() {
	int year;					//입력받는 연도 값
	while(1) {
		printf("연도를 입력하세요 (0 입력 시 종료) : ");
		scanf("%d", &year);
		
		if (year == 0) {
			break;	}
			
		IsLeapYear(year) ? printf("'%d'는 윤년입니다.\n", year)
			: printf("'%d'는 윤년이 아닙니다.\n", year);
	}
	return 0;
}

int IsLeapYear (int y) {
	/*
	1. Description : 윤년인지 아닌지 판단하는 함수. 
	2. Function : int y (인자값) 
	3. Return : 윤년이면 1, 윤년이 아니면 0. 
	*/
	
	if ( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ) 
	{
		return 1;
	}
	
	else 
	{
		return 0;
	}
}

/*
연도를 인자로 받아서 윤년인지 판단하는 IsLeapYear 함수 정의

함수는 윤년이면 1
그렇지 않으면 0을 리턴

4로 나누어 떨어지면 윤년 1
그중에서 100으로 나누어 떨어지면 윤년 0 
그중 400으로 나누어 떨어지면 1 
*/
