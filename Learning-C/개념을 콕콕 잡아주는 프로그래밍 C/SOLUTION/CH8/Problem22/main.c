#include <stdio.h>

#define SIZE 256

int main(void)
{
	char strSrc[SIZE], strDest[SIZE];
	char *pSrc = strSrc, *pDest = strDest;
	int pos = 0;
	
	printf("Input string : ");
	gets(strSrc);
	
	printf("Before process : %s\n", strSrc);
	
	while(*(pSrc+pos) != '\0') {
		pos++;
	}
	
	while(--pos >= 0) {
		*pDest++ = *(pSrc+pos);
	}
	*pDest = '\0';
	
	printf("After process : %s\n", strDest);

	return 0;
}
