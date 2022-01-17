#include <stdio.h>
#include <limits.h>

int main ()
{
	int a = 16;
	short b = SHRT_MIN;
	
	char c = 'a';
	float d = 1.5;
	
	b = b - 1;
	printf("%x, %d, %d, %d\n", a, b, c, sizeof(d));
	
	
	
	
	return 0;
}
