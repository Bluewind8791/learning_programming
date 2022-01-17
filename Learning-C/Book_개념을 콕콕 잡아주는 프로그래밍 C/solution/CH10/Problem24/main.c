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
		case 0 : strcpy(weekDay, "�Ͽ���"); break;
		case 1 : strcpy(weekDay, "������"); break;
		case 2 : strcpy(weekDay, "ȭ����"); break;
		case 3 : strcpy(weekDay, "������"); break;
		case 4 : strcpy(weekDay, "�����"); break;
		case 5 : strcpy(weekDay, "�ݿ���"); break;
		case 6 : strcpy(weekDay, "�����"); break;  
		default : break;
	}

	printf("%d��/ %02d��/ %2d�� / %s / %02d�� / %02d�� / %02d��\n",  
		d.year, d.month, d.day, weekDay, d.hour, d.minute, d.second);
	
	return 0;
}




