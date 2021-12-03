#include <stdio.h>

int main(int argc, char *argv[]) 
{
	
	int i,count;
	
	count = 0;
	
	for (i = 10; ;)
	{
		printf("%d ", i);
		i++;
		count++;
		
		if (count > 10)
			break;
		
	}


	return 0;
}

/*10부터 20까지의 숫자를 
차례대로 출력하는 프로그램을 작성하시오.
for문을 사용하세요.
*/
