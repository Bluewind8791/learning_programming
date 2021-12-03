#include <stdio.h>
#include <string.h>

int main()
{
	char word[10][20];
	char alpha;
	int i, j, len;
	
	for(i=0; i<10; i++)
	{
		scanf("%s", &word[i]);
	}
	scanf(" %c", &alpha);
	
	for(i=0; i<10; i++)
	{
		len = strlen(word[i]);
		if (word[i][len-1] == alpha)
		{
			printf("%s\n", word[i]);
		}		
	}
	
	return 0;
}

/*
20개 이하의 문자로 이루어진 
10개의 단어와 
한 개의 문자를 입력받아서 

마지막으로 입력받은 문자로 끝나는 
단어를 모두 출력하는 프로그램을 작성하시오.
*/
