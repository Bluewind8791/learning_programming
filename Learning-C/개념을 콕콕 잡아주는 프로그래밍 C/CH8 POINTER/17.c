#include <stdio.h>

int main()
{
	char str[] = "abcdefghij";
	char *p = NULL;
	
	p = str + 1;
	p[0] = 'X';
	
	p = str + 3;
	p[1] = 'Y';

	p = str + 5;
	p[2] = 'Z';
	
	printf("str = %s\n", str);
		
	return 0;
}

/*

*/
