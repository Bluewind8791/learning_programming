#include <stdio.h>

int main()
{
	int ascii=0;
	
	while(1)
	{
		printf("ASCII code =? ");
		scanf("%d", &ascii);
	
		if (CharRange(ascii))
		{
			printf("%c\n", ascii);
		}
		else
		{
			break;
		}
	}
	
	return 0;
}

int CharRange (int ascii)
{
		if (ascii >= 33 && ascii <= 127)
		{
			return 1;
		}
				
		else
		{
			return 0;
		}
}

/*
33���� 127 ������ ���ڸ� ��� �Է¹޾� 

�Է¹��� ������ �ƽ�Ű�ڵ忡 
�ش��ϴ� ���ڸ� ����ϴٰ� 

������ ����� �Է��� ������ 
�����ϴ� ���α׷��� �ۼ��Ͻÿ�.


*/
