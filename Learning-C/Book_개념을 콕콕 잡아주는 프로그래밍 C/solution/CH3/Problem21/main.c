


#include <stdio.h>
#include <limits.h>

int main(void)
{
	char ch = 0;
	
	// signed char 의 최대값 
	ch = SCHAR_MAX;
	printf("char형의 최대값 : %d\n", ch);
	
	// signed char 의 최대값 + 1 
	ch = SCHAR_MAX + 1;
	printf("char형의 최대값+1 : %d\n", ch);
	
	// signed char 의 최소값 
	ch = SCHAR_MIN;
	printf("char형의 최소값 : %d\n", ch);
	
	// signed char 의 최소값 - 1 
	ch = SCHAR_MIN - 1;
	printf("char형의 최소값-1 : %d\n", ch);
		
	return 0;
}
