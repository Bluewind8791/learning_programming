#include <stdio.h>
#include <stdlib.h>

#define EXPO 5


int main(int argc, char *argv[]) 
{


printf("2^5 = %d \n", 1 << 5);
printf("2^10 = %d \n", 1 << 10);
printf("2^15 = %d \n", 1 << 15);
printf("2^20 = %d \n", 1 << 20);
printf("2^25 = %d \n", 1 << 25);
printf("2^30 = %d \n", 1 << 30);

int val = 1;
printf("2ÀÇ 5½Â: %d\n", val = val<<EXPO);
printf("2ÀÇ 10½Â: %d\n", val = val<<EXPO);
printf("2ÀÇ 15½Â: %d\n", val=val<<EXPO);
printf("2ÀÇ 20½Â: %d\n", val=val<<EXPO);
printf("2ÀÇ 25½Â: %d\n", val=val<<EXPO);
printf("2ÀÇ 30½Â: %d\n", val=val<<EXPO);


	return 0;
}
