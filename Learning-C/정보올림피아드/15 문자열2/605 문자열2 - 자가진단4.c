#include <stdio.h>
#include <string.h>

int main()
{
	char str[100] = {0,};
	strcpy(str, "Hong Gil Dong");
	
	printf(str);
	
	return 0;
}

/*
���ڿ��� �����ϰ� 
������ ���� "Hong Gil Dong"�̶�� 
�̸��� �����Ͽ� ������ �� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
