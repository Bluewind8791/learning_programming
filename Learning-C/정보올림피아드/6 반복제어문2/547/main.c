#include <stdio.h>
int main(int argc, char *argv[]) 
{
	int i,j;
	int count,count1;
	
	i = 1;
	j = 1;
	count1 = 0;
	
	while(1)
	{
		count = 0;
		while(1)
		{		
			printf("%d ", 1+i);
			i++;
			count++;
			if ( count > 4)
				{
				printf("\n");
				break;
				}						
		}
	
	i=1+j;
	j++;
	count1++;
			
	if ( count1 > 4)
		{
		printf("\n");
		break;
		}			
	}
	return 0;
}

//반복 이중문 
//아래와 같이 출력되는 프로그램을 작성하시오.

/*
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9
6 7 8 9 10
*/
