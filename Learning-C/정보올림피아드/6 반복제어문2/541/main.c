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

문자를 입력받아서 
입력받은 문자를 20번 반복하여 
출력하는 프로그램을 작성하시오.

*/
