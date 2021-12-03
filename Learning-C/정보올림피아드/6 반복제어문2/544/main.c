#include <stdio.h>

int main(int argc, char *argv[]) 

{
	
	int num, count, sum;
	
	scanf(" %d", &num);
	
	sum = 0;
	
	while(1)
	{
		
		sum = num + sum;
		num++;
	
		if ( num > 100 )
			break;
		
	}
		
	printf("%d", sum);
		
	return 0;
}

/*
100 이하의 정수를 입력받아서 
입력받은 정수부터 
100까지의 합을 출력하는 
프로그램을 작성하시오.

*/
