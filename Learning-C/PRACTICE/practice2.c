#include <stdio.h>
#include <string.h> 

int main ()
{
	char str1[4] = "abc";
	char str2[7] = "123456";
	char str3[] = "Hello World";
	
	printf("string 1 = %s\n", str1);
	printf("string 2 = %s\n", str2);
	printf("string 3 = %s, and size is %d\n", str3, sizeof(str3));
	
	printf(str3);
	
	printf("\n\nstrcpy(str1, str2) COPY ÈÄ\n");
	strcpy (str1, str2);
	printf(str1);
	
	return 0;
}
