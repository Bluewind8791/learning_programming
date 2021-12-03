#include <stdio.h>
#include <time.h>

typedef struct _date {
	int year, month, day;
}DATE;

int main()
{
	DATE d;							//date ����ü d�� ����  
	
	time_t t = time(NULL);		//time ����ü t�� ���� 
	printf("time_t�� ��� ���ñ�? %lld\n", t);
	
	struct tm *DateInfo = localtime( &t );
	
	d.year = DateInfo->tm_year + 1900;
	d.month = DateInfo->tm_mon;
	d.day = DateInfo->tm_mday;
	
	printf("Date Info : %d�� %d�� %d��", d.year, d.month, d.day);
	
	return 0;
}

/*
ǥ�� C ���̺귯�� �Լ��� time �Լ��� 
localtime �Լ��� �̿��Ͽ� 
���� �ð��� ���� ��  

��¥ ������ �����ϴ� date ����ü�� �����ϰ� 
����ϴ� ���α׷� �ۼ�  

<time.h> ���̺귯�� ����  
time_t time(time_t *_Time);
struct tm *localtime(const time_t *_Time)
*/
