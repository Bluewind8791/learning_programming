#include <stdio.h>

#define SIZE 256

int main(void)
{
	char str1[SIZE], str2[SIZE];	
	char tempChar1, tempChar2;		
	char *p1 = str1, *p2 = str2;
	
	printf("첫 번째 문자열을 입력하세요 : ");
	gets(str1);
	
	printf("두 번째 문자열을 입력하세요 : ");
	gets(str2);
	 
	while(*p1 != '\0') {
		// string1 => uppercase
		if(*p1>='a' && *p1<='z') {
			tempChar1 = *p1 - ('a'-'A');
		}
		else {
			tempChar1 = *p1;
		}
		
		// string 2 => uppercase
		if(*p2>='a' && *p2<='z') {
			tempChar2 = *p2 - ('a'-'A');
		}
		else {
			tempChar2 = *p2;
		}
		
		// compare string1 and string2
		if(tempChar1 != tempChar2) {
			break;
		}
		
		p1++;
		p2++;
	} 

	// check all match
	if(*p1=='\0' && *p2=='\0') {
		printf("%s와(과) %s는(은) 같습니다.\n", str1, str2); 
		 
	}
	else {
		printf("%s와(과) %s는(은) 같지 않습니다.\n", str1, str2); 
	}
		
	return 0;
}
