#include <stdio.h>
#include <string.h>

int main()
{
	char str1[20]={0}, str2[20]={0};
	scanf("%s %s",str1, str2);
	
	char strplus[3] = {str1[0],str1[1]};
	
	strncpy(str2, str1, 2);
	strcat(str2, strplus);
	
	printf(str2);
	
	return 0;
}

/*
20�� ������ �� ���� ���ڿ��� �Է¹޾� 
ù ��° ���ڿ��� �պκ� ���ڸ� 
�� ��° ���ڿ��� �պκп� �����ϰ� 

�ٽ� �޺κп� �̾� �ٿ��� 
������ �� 

�� ��° ���ڿ��� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
