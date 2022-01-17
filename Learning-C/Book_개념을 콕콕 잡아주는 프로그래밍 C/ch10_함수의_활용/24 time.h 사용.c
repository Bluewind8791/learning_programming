#include <stdio.h>
#include <time.h>

typedef struct _date {
	int year, month, day;
}DATE;

int main()
{
	DATE d;							//date 구조체 d로 정의  
	
	time_t t = time(NULL);		//time 구조체 t로 정의 
	printf("time_t는 어떻게 나올까? %lld\n", t);
	
	struct tm *DateInfo = localtime( &t );
	
	d.year = DateInfo->tm_year + 1900;
	d.month = DateInfo->tm_mon;
	d.day = DateInfo->tm_mday;
	
	printf("Date Info : %d년 %d월 %d일", d.year, d.month, d.day);
	
	return 0;
}

/*
표준 C 라이브러리 함수인 time 함수와 
localtime 함수를 이용하여 
현재 시간을 구한 뒤  

날짜 정보를 저장하는 date 구조체에 저장하고 
출력하는 프로그램 작성  

<time.h> 라이브러리 정보  
time_t time(time_t *_Time);
struct tm *localtime(const time_t *_Time)
*/
