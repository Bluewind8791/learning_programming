#include <stdio.h>

int main()
{
	char ch;
	
	while(1)
	{
		scanf(" %c", &ch);
		
		if (ch >= 'A' && ch <= 'Z')
		{
			printf("%c\n", ch);
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			printf("%c\n", ch);
		}
		else if (ch >= 48 && ch <= 57)
		{
			printf("%d\n", ch);
		}
		else
		{
			break;
		}
	}
	
	return 0;
}

/*
���ڸ� �Է¹޾� 

���ĺ� ������ ��쿡�� 
�״�� ����ϰ� 

������ ���� �ƽ�Ű�ڵ尪�� 
����ϴ� �۾��� �ݺ��ϴٰ� 

��Ÿ�� ���ڰ� �ԷµǸ� 
�����ϴ� ���α׷��� �ۼ��Ͻÿ�.


*/
