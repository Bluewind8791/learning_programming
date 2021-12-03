# include <stdio.h>

int main()
{
	char ch[10] = {0,};
	int i;
	
	for (i=0;i<10;i++)
	{
		scanf(" %c",&ch[i]);
	}
	
	for (i=9;i>=0;i--)
	{
		printf("%c ",ch[i]);
	}
	
	return 0;
}

/*
		


10개의 문자를 입력받아 
마지막으로 입력받은 문자부터 
첫 번째 입력받은 문자까지 
차례로 출력하는 프로그램을 작성하시오.
*/
