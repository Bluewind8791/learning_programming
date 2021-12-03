
#include <stdio.h>

int IsLower(char ch);
int IsUpper(char ch);
int IsAlphabetic(char ch);

int main(void)
{
	char inputCh;
	
	printf("Input Character : ");
	scanf(" %c", &inputCh);
	
	if(IsAlphabetic(inputCh) == 1) {
		if(IsLower(inputCh) == 1) {
			printf("%c is lowercase chracter.\n", inputCh);
		}
		else if(IsUpper(inputCh) == 1) {
			printf("%c is uppercase character.\n", inputCh);
		}
	}
	else {
		printf("%c is not alphabetic character.\n", inputCh);
	}
	
	return 0;
}

int IsLower(char ch)
{
	if(ch>='a' && ch<='z') {
		return 1;
	}
	else {
		return 0;
	}
}

int IsUpper(char ch)
{
	if(ch>='A' && ch<='Z') {
		return 1;
	}
	else {
		return 0;
	}
}

int IsAlphabetic(char ch)
{
	if(IsLower(ch) || IsUpper(ch)) {
		return 1;
	}
	else {
		return 0;
	}
}




