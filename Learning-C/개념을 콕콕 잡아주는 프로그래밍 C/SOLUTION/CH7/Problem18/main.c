#include <stdio.h>
#include <string.h>

#define SIZE 40

int main(void)
{
	char str[SIZE];
	int i;
	
	printf("���ڿ��� �Է��ϼ��� : "); 
	gets(str);
	
	///////////////// strupr / strlwr //////////////////
	strupr(str);
	printf("������ ���ڿ�(strupr function) : %s\n", str); 
	
	
	////////////////// per character //////////////////
	i = 0;
	while(str[i] != '\0') {
		if(str[i]>='a' && str[i]<='z') {
			str[i] -= 'a' - 'A';
		}
		i++;
	}
	printf("������ ���ڿ�(per character) : %s\n", str); 

	return 0;
}
