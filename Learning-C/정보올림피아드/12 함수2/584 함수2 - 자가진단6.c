#include <stdio.h>
#define first 1
#define second 2
#define third 3

int main()
{
	int array[3]={first,second,third};
	int i, j;
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d + %d = %d\n", array[i], array[j], array[i]+array[j]);
		}
	}
	
	return 0;
}

/*
main() 함수 내에는 
숫자를 사용하지 말고 

즉, #define 을 이용하여 
1, 2, 3 세 개의 숫자를 조합하여 
가능한 한 모든 합을 출력하는 
프로그램을 작성하시오.

출력예와 같이 출력하시오.

1 + 1 = 2
1 + 2 = 3
1 + 3 = 4
2 + 1 = 3
2 + 2 = 4
2 + 3 = 5
3 + 1 = 4
3 + 2 = 5
3 + 3 = 6

*/
