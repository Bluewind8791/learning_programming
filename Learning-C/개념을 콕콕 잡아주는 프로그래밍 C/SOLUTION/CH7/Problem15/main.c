#include <stdio.h>

#define SIZE 20

int main(void)
{
	int i, lastPos;
	char str[SIZE] = {0};
	
	printf("Input string : ");
	gets(str);
	
	for(i=0; i<SIZE; i++) {
		if(str[i] == '\0') {
			lastPos = i;
			break;
		}
	} 
	
	for(i=lastPos-1; i>=0; i--) {
		printf("%c", str[i]);
	}
	
	printf("\n");
	
	return 0;
}
