#include <stdio.h>
#include <string.h>

int main()
{
	char str[20]={0,};
	char strplus[20] = "fighting";
	scanf("%s",str);
	strcat(str,strplus);
	
	printf(str);
	
	return 0;
}
