


#include <stdio.h>
#include <limits.h>

int main(void)
{
	char ch = 0;
	
	// signed char �� �ִ밪 
	ch = SCHAR_MAX;
	printf("char���� �ִ밪 : %d\n", ch);
	
	// signed char �� �ִ밪 + 1 
	ch = SCHAR_MAX + 1;
	printf("char���� �ִ밪+1 : %d\n", ch);
	
	// signed char �� �ּҰ� 
	ch = SCHAR_MIN;
	printf("char���� �ּҰ� : %d\n", ch);
	
	// signed char �� �ּҰ� - 1 
	ch = SCHAR_MIN - 1;
	printf("char���� �ּҰ�-1 : %d\n", ch);
		
	return 0;
}
