#include <stdio.h>

#define SIZE 256

int main(void)
{
	char strSrc[SIZE], strDest[SIZE];
	char *pSrc = strSrc, *pDesc = strDest;
	
	printf("Input string : ");
	gets(strSrc);
	printf("Source string : %s\n", strSrc);
	
	while(*pSrc != '\0') {
		*pDesc++ = *pSrc++;
	}
	*pDesc = '\0';
	
	printf("Desctination string : %s\n", strDest);
	
	return 0;
}
