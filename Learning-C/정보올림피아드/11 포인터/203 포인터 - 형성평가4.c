#include <stdio.h>

int main()
{
	int array[10] = {0,};
	int *p_array[10] = {0,};
	
	int i;
	int evencnt=0, oddcnt=0;
	
	for(i=0; i<10; i++)
	{
		p_array[i] = &array[i];
		scanf("%d", &*p_array[i]);
		if(*p_array[i] % 2 == 0)
		{
			evencnt++;
		}
		else 
		{
			oddcnt++;
		}
	}
	
	printf("odd : %d\neven : %d", oddcnt, evencnt);
	
	return 0;
}

/*
10개의 원소를 저장할 수 있는
배열을 선언한 후

포인터 변수를 이용하여 자료를 입력받아
홀수의 개수와 짝수의 개수를 
출력하는 프로그램 
*/
