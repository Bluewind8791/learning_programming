#include <stdio.h>
#include <string.h>

int main()
{
	char str[100] = {0};
	fgets(str, sizeof(str), stdin);
	int i, index=1;
	
	printf("%d. ", index);
	index++;
	
	for (i=0; i<strlen(str); i++)
	{
		printf("%c", str[i]);
		
		if (str[i]==' ')
		{
			printf("\n%d. ", index);
			index++;
		}
	}

	return 0;
}

/*
������ ������ ���ڿ��� �Է¹޾� 
������ ���� �и��Ͽ� 
��ȣ�� �Բ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

���ڿ��� ���̴� 100�� �����̴�.

* ���� �Է��� �� gets()�Լ� ��� 
fgets() �Լ��� ����ϼ���.
*/
