
#include <stdio.h>

int IsLeafYear(int year);

int main(void)
{
	int year;
	
	printf("Input year : ");
	scanf("%d", &year);
	
	if(IsLeafYear(year) == 1) {
		printf("Year : %d is leaf year.\n", year);
	}
	else {
		printf("Year : %d is not leaf year.\n", year);
	}
	
	return 0;
}

int IsLeafYear(int year)
{
	if(((year%4 == 0) && (year%100 != 0)) || (year%400 == 0)) {
		return 1;
	}
	else 
		return 0;
}

