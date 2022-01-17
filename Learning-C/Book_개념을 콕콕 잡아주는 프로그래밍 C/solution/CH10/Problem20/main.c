#include <stdio.h>

#define SIZE 256

int Compare(const char *str1, const char *str2, int caseSensitive);

int main(void)
{
	char str1[SIZE], str2[SIZE];
	int result;
	
	printf("Input string 1 : ");
	gets(str1);
	printf("Input string 2 : ");
	gets(str2);
	
	result = Compare(str1, str2, 1);
	printf("Compare strings(    case-sensitive) : %d\n", result);
	
	result = Compare(str1, str2, 0);
	printf("Compare strings(not case-sensitive) : %d\n", result);

	return 0;
}


int Compare(const char *str1, const char *str2, int caseSensitive)
{
	char tempCh1, tempCh2;
	
	if(caseSensitive == 1) {
		while(*str1 != '\0') {
			if(*str1 != *str2) {
				break;
			}
			str1++;
			str2++;
		}
		return (*str1 - *str2);
	}
	else {
		while(*str1 != '\0') {
			if(*str1>='a' && *str1<='z') {
				tempCh1 = *str1 - ('a'-'A');
			}
			else {
				tempCh1 = *str1;
			}
			if(*str2>='a' && *str2<='z') {
				tempCh2 = *str2 - ('a'-'A');
			}
			else {
				tempCh2 = *str2;
			}
			
			if(tempCh1 != tempCh2) {
				break;
			}
			str1++;
			str2++;
		}
		return (tempCh1 - tempCh2);
	}
}








