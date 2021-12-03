#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int n, i;
	
	scanf("%d", &n);
	
	i = 0;
	
	while(1)
	{
	i++;
	
		if( n*i > 99 )
		{break;
		}
		
	printf("%d ", n*i);
	
	if( (n*i) % 10 == 0)
		{break;
		}
	
	}
	
	return 0;
}

/*1부터 100까지의 정수 중 
한 개를 입력받아 
100 보다 작은 배수들을 
차례로 출력하다가 

10 의 배수가 출력되면 
프로그램을 종료하도록 프로그램을 작성하시오.
*/

