#include <stdio.h>
#include <string.h>

int RemoveSpace(char *str)
{
	int change = 0;
	int space_cnt = 0;
	
	for(int i=0; i<strlen(str); i++) {
		if (str[i] == ' ') {
			space_cnt++;
		}
		if (str[i] != ' ') {
			str[change] = str[i];
			change++;
		}
	}
	str[change] = '\0';
	return space_cnt;
}

int main()
{
	//char str[256]="C program to remove spaces in input string";
	char str[256];
	printf("���ڿ��� �Է��ϼ��� : ");
	gets(str);
	//printf(str);
	
	printf("\n\nSpace Count : %d\n", RemoveSpace(str));
	
	printf("\nAfter Deleting Space : ");
	printf(str);
	
	
	
	
	return 0;
}

/*
���ڷ� ���޹��� ���ڿ��� ���� 
���鹮�ڸ� �����ϴ� RemoveSpace �Լ� ���� 

�Լ��� ù��° ���ڷ� ���޵Ǵ� ���ڿ��� 
�Լ� �ȿ��� ��뵵 �ǰ� ���浵 �ǹǷ� ����� ���ڷ� ó�� 

���� �Լ��� ���ŵ� ���鹮���� ������ ����  
*/
