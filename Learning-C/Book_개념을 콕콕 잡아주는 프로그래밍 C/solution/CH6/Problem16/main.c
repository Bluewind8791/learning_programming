
#include <stdio.h>
#include <stdbool.h>

bool IsLeafYear(int yy);
int GetDaysOfMonth(int yy, int mm);

int main(void)
{
	int year, month;
	
	printf("Input Year : ");
	scanf("%d", &year);
	printf("Input Month : ");
	scanf("%d", &month);
	
	printf("Year:%d / Month:%d => Days:%d\n", year, month, GetDaysOfMonth(year, month));  
	
	return 0;
}

bool IsLeafYear(int yy)
{
	return (((yy%4==0) && (yy%100!=0)) || (yy%400==0));
}

int GetDaysOfMonth(int yy, int mm)
{
	int days;
	
	if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12) {
		days = 31;
	}
	else if(mm==4 || mm==6 || mm==9 || mm==11) {
		days = 30;
	}
	else if(mm==2) {
		if(IsLeafYear(yy) == true) {
			days = 29;
		}
		else {
			days = 28;
		}
	}
	else {
		printf("Wrong month!\n");
		days = 0;
	}

	return days;
}



