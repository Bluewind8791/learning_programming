#include <stdio.h>

#define SIZE 40

int main(void)
{
	char str[SIZE];
	int i;
	
	printf("문자열을 입력하세요 : ");
	gets(str);
	
	i = 0;
	while(str[i] != '\0') {
		if(i == 0) {
			if(str[i]>='a' && str[i]<='z') {
				str[i] -= 'a' - 'A';
			}			
		}
		else if(str[i] == ' ') {
			if(str[i+1]>='a' && str[i+1]<='z') {
				str[i+1] -= 'a' - 'A';
			}
		}
		i++;
	}
	
	printf("변경 후 문자열 : %s\n", str); 

	return 0;
}
