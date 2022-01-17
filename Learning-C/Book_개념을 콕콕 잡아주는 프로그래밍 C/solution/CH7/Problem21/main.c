#include <stdio.h>

#define SIZE 100

int main(void)
{
	char str[SIZE];
	int i, j;
	
	printf("문자열을 입력하세요 : ");
	gets(str);
	
	i = 0;
	while(str[i] != '\0') {
		if(str[i]==' '  || str[i]=='\t' || str[i]=='\v' ||
		   str[i]=='\n' || str[i]=='\f') {
		   	j = i;
			while(str[j] != '\0') {
				str[j] = str[j+1];
				j++;
			}
		} 
		i++;
	} 
	
	printf("변경 후 문자열 : %s\n", str);
	
	return 0; 
}
