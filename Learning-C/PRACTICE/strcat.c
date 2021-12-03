#include <stdio.h>
#include <string.h>

int main ()
{
	char str[10] = "0123456789";
	strcat(str, "tail");
	printf("%s\n",str);
	
	
	return 0;	
}
