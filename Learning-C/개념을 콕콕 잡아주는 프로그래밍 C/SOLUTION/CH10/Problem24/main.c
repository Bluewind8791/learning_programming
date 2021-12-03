#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct date {
	int year, month, day;
	int wday;
	int hour, minute, second;
} DATE;

int main(void)
{
	DATE d;
	time_t tnow;
	struct tm *t;
	char weekDay[10];
	
	tnow = time(NULL);
	t = localtime(&tnow);
	
	d.year = t->tm_year + 1900;
	d.month = t->tm_mon + 1;
	d.day = t->tm_mday;
	d.wday = t->tm_wday;
	d.hour = t->tm_hour;
	d.minute = t->tm_min;
	d.second = t->tm_sec;
		
	switch(d.wday) {
		case 0 : strcpy(weekDay, "일요일"); break;
		case 1 : strcpy(weekDay, "월요일"); break;
		case 2 : strcpy(weekDay, "화요일"); break;
		case 3 : strcpy(weekDay, "수요일"); break;
		case 4 : strcpy(weekDay, "목요일"); break;
		case 5 : strcpy(weekDay, "금요일"); break;
		case 6 : strcpy(weekDay, "토요일"); break;  
		default : break;
	}

	printf("%d년/ %02d월/ %2d일 / %s / %02d시 / %02d분 / %02d초\n",  
		d.year, d.month, d.day, weekDay, d.hour, d.minute, d.second);
	
	return 0;
}




