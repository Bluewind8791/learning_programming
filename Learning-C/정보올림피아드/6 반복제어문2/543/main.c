#include <stdio.h>

int main(int argc, char *argv[]) 
{
	
	int num,i;
	
	scanf(" %d", &num);
	
	i = 1;
	
	while (1)
	{
	
	i++;
	if ( i % 2 == 0)
		printf("%d ", i);
	
	else if ( i >= num )
		break;
		
	}
	
	return 0;
}

/*
하나의 정수를 입력받아 
1부터 입력받은 정수까지의 
짝수를 차례대로 출력하는 프로그램을 작성하시오.

입력되는 정수는 50이하이다.
*/
