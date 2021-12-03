#include <stdio.h>
#include <limits.h>


int main(int argc, char *argv[]) 
{

signed char max = CHAR_MAX;
signed char min = CHAR_MIN;

printf("char형의 최대값 : %d\n", max);

signed char max1 = CHAR_MAX+1;

printf("char형의 최대값+1 : %d\n", max1);

printf("char형의 최소값 : %d\n", min);

signed char min1 = CHAR_MIN-1;

printf("char형의 최소값-1 : %d\n", min1);




	return 0;
}
