#include <stdio.h>
#include <string.h>

int main()
{
	char str[100] = {0};
	int n;
	
	scanf("%s %d",str, &n);
	
	int i;
	int len;
	len = strlen(str);
	
	if (n >= len)
	{
		for (i=len-1; i>=0; i--)
		{
			printf("%c", str[i]);
		}
	}
	
	else
	{
		for (i=len-1; i>=len-n; i--)
		{
			printf("%c", str[i]);
		}
	}
	
	return 0;
}

/*
���ڿ��� �Է¹ް� 
������ �Է� �޾Ƽ� 

���ڿ��� �� �ں��� 
������ŭ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.


 ���� �Է¹��� ������ 
 ���ڿ��� ���̺��� ũ�ٸ� 
 �� �ں��� �� ó������ ��� ����Ѵ�.


(���ڿ� ���̴� �ִ� 100�� �����̴�. )
*/

