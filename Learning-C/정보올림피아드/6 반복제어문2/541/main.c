#include <stdio.h>

int main( ) {
	
	char c;
	int	count;

	scanf(" %c", &c);
	
	count = 0;
	
	while(1)
		{
			printf("%c", c);
			count++;
			
			if (count >= 20)
				break;
		}
return 0;
}

/*

���ڸ� �Է¹޾Ƽ� 
�Է¹��� ���ڸ� 20�� �ݺ��Ͽ� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

*/
