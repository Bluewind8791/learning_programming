#include <stdio.h>

int main()
{
	
	int i;
	int num;
	int sum = 0;
	//대입하는것이 아니기 떄문에 초기값이 필요하다 
	
	scanf(" %d", &num);
	
	
	i = 1;
	while ( i <= num )
	{
	
		sum += i;
		i++;
	
	}
	
	printf("%d", sum);
	
	return 0;
}

//100 이하의 양의 정수만 입력된다.
//while 문을 이용하여 1부터 입력받은 정수까지의 
//합을 구하여 출력하는 프로그램을 작성하시오.
