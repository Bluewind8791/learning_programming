#include <stdio.h>
int main() 
{
	int num;
	
	{
	printf("number? ");
	scanf(" %d", &num);
	}
	
	
	//초기식
	
	while (num != 0)
	{
		{
		if (num > 0) 
			printf("positive integer\n");
		else
			printf("negative number\n");
		}
	
		{
		printf("number? ");
		scanf(" %d", &num);
		}
	
	}
		
	return 0;
}


/*한 개의 정수를 입력받아 양수(positive integer)인지 음수(negative number)인지 
출력하는 작업을 반복하다가 0이 입력되면 종료하는 프로그램을 작성하시오.*/
