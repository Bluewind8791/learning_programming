#include <stdio.h>
#include <string.h>
/*
char* Reverse(const char *str)
{
	static char result[80];
	int i;
	int len = strlen(str);
	
	for(i=0; i<len; i++) {
		result[i] = str[len-i-1];
	}
	result[len] = '\0';
	return result;
}
*/
void Reverse(char *str)
{
	int i, temp;
	int len = strlen(str);
	
	for(i=0; i<len/2; i++) {
		temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
	}
	str[len] = '\0';
}

int main()
{
	char str[] = "Hello World";
//	char *reverse_str = NULL;
	
//	reverse_str = Reverse(str);
	Reverse(str);
	
//	printf("%s", reverse_str);
	printf(str);
	
	return 0;
}


