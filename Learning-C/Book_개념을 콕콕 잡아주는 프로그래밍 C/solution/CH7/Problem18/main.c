#include <stdio.h>
#include <string.h>

#define SIZE 40

int main(void)
{
	char str[SIZE];
	int i;
	
	printf("문자열을 입력하세요 : "); 
	gets(str);
	
	///////////////// strupr / strlwr //////////////////
	strupr(str);
	printf("변경후 문자열(strupr function) : %s\n", str); 
	
	
	////////////////// per character //////////////////
	i = 0;
	while(str[i] != '\0') {
		if(str[i]>='a' && str[i]<='z') {
			str[i] -= 'a' - 'A';
		}
		i++;
	}
	printf("변경후 문자열(per character) : %s\n", str); 

	return 0;
}
