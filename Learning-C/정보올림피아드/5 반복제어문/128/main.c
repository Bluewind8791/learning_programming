#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int num, count;
	
	
	count = 0;
	
	while(1)
	{
		scanf(" %d", &num);
			
		if (num == 0)
			break;
		
		else if (num % 3 != 0 && num % 5 != 0)
			count++;
	}
	
	printf("%d",count);
		
	return 0;
}

/*
0 이 입력될 때까지 
정수를 계속 입력받아 
3의 배수와 5의 배수를 제외한 수들의 
개수를 출력하는 프로그램을 작성하시오.
*/


