#include <stdio.h>

int main ()
{
	char str[3][5]={0,};
	int i,j;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf(" %c",&str[i][j]);
			str[i][j] = str[i][j] + 32;
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%c ", str[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
/*
3행 5열의 2차원 문자배열 형태의 대문자들을 입력 받은 후 

소문자로 바꾸어서 공백으로 구분하여 
출력하는 프로그램을 작성하시오.

*/

