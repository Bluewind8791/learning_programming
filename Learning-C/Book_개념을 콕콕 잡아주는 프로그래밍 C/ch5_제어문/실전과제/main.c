#include <stdio.h>

int main(int argc, char *argv[]) {

	char ch;
	
	while(1)
	{
		printf("�����ڸ� �Է��ϼ��� : ");
		scanf(" %c", &ch);
	
		if (ch == '.')
			break;
			
		if ('A' <= ch && ch <= 'Z')
			{printf("'%c'�� �빮���Դϴ�.\n", ch);
				}	
		
		else if ('a' <= ch && ch <= 'z')
			{printf("'%c'�� �ҹ����Դϴ�.\n", ch);
			}
		
		else
			{
			printf("'%c'�� �����ڰ� �ƴմϴ�.\n", ch);
			}		
	}
	
	return 0;
}
