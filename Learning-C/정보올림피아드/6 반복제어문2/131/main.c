#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int num1, num2;
	
	scanf(" %d %d", &num1, &num2);
	
	if (num1>num2) {
		for(;num1>=num2;num2++)
			{ printf("%d ", num2);
			}
		}
	
	else if (num1<num2)	{
		for(;num1<=num2;num1++)
			{	printf("%d ", num1);
			}
		}
	
	else
		printf("%d",num1);
	
	return 0;
}

//100 이하의 두 개의 정수를 입력받아 
//작은 수부터 큰 수까지 차례대로 출력하는 프로그램을 작성하시오.

