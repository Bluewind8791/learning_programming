#include <stdio.h>
#include <string.h>

int main()
{
	char str[100] = {0};
	scanf("%s", str);
	
	int i;
	for(i=0; i<5; i++)
	{
		printf("%c", str[i]);
	}
	
	
	return 0;
}

/*
5개 이상 100개 이하의 
문자로 된 단어를 입력받은 후 
앞에서부터 5자를 출력하는 
프로그램을 작성하시오.

*/
