#include <stdio.h>
#include <ctype.h>

#define SIZE 256

int main(void)
{
	char str[SIZE];
	char *p = str;
	int cnt = 0;
	
	printf("Input string : ");
	gets(str);
	
	while(*p++ != '\0') {
		if(isspace(*p)) {
			cnt++;
		}
	}	

	printf("Count of whitespace : %d\n", cnt);
	
	return 0;
}
