#include <stdio.h>

int GetDaysOfMonth (int y, int m);
int IsLeapYear (int y);

int main(void) {
	int month, year;
	while(1) {
		printf("Please insert YEAR : ");
		scanf("%d", &year);
		if (year == 0) {
		break;}
		printf("Please insert MONTH : ");
		scanf("%d", &month);
		printf("\nThe days of this month : %d\n\n", GetDaysOfMonth (year,month));			
	}
	return 0;
}

int GetDaysOfMonth (int y, int m) {
/* 
1. description : 연도와 월을 인자로 받아서
그 달의 날짜 수를 리턴하는 함수.
2. parameter : int y, int m
3. return : days
*/
	int days;
	if (m==1||m==3||m==5||m==7||m==8||m==10||m==12) {
		days = 31;
	}
	else if (m==4||m==6||m==9||m==11) {
		days = 30;
	}
	else if (m==2) {
		IsLeapYear(y) ? (days=29) : (days=28);
	}
	return days;
}

int IsLeapYear (int y) {
/* 
1. description : 해당 연도가 윤년인지 아닌지 판단하는 함수. 
2. parameter : int y
3. return : 0 혹은 1로 return 
*/
	int LeapYear;
	if ( (y % 400 == 0)||(y % 4 == 0)&&(y % 100 == 0) ) {
		return 1;
	}
	else {
		return 0;
	}
}

/*
연도와 월을 인자로 받아서
그 달의 날짜 수를 리턴하는
GetDaysOfMonth 함수를 정의

1,3,5,7,8,10,12월은 31일
2,4,6,9,11월은 30일

2월은 윤년에 따라서 윤년이면 29일 윤년이 아니면 28일이다
*/ 
