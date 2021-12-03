#include <stdio.h>

struct time {
	unsigned int sec : 6;
	unsigned int min : 6;
	unsigned int hour : 5;
};

int main()
{
	struct time t1;
	printf("The size of Sturct time : %d\n", sizeof(struct time));
	
	t1.hour = 5;
	t1.min = 30;
	t1.sec = 70;
	
	printf("%02d:%02d:%02d\n", t1.hour, t1.min, t1.sec); 
	
	return 0;
}
