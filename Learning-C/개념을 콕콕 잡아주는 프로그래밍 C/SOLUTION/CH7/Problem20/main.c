#include <stdio.h>

#define SIZE 40

int main(void)
{
	char str[SIZE];
	int i;
	
	printf("���ڿ��� �Է��ϼ��� : ");
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
	
	printf("���� �� ���ڿ� : %s\n", str); 

	return 0;
}
