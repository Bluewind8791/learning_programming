


#include <stdio.h>

int main(void)
{
	int total_sec;
	int hour, min, sec;
	
	printf("Input total second : ");
	scanf("%d", &total_sec);
	
	hour = total_sec / 3600;
	min = (total_sec % 3600) / 60;
	sec = (total_sec % 3600) % 60;
	
	printf("HH:%02d  MM:%02d  SS:%02d\n", hour, min, sec);
	
	return 0;
}
