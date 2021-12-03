#include <stdio.h>
#include <string.h>
int main()
{
	char word[100]={0};
	char ch=0;
	
	scanf("%s", word);
	scanf(" %c", &ch);
	
	int i;
	int cnt=0;
	
	for(i=0; i<100; i++)
	{
		if(word[i] != ch)
		{
			if (word[i] == '\0')
			{
				printf("No");
				break;
			}
			cnt++;
		}
		
		else if (word[i] == ch)
		{
			printf("%d", cnt);
			break;
		}
	}
	
	return 0;
}
/*
단어와 문자 한 개를 입력받아서 
단어에서 입력받은 문자와 
같은 문자를 찾아서 
그 위치를 출력하는 프로그램을 작성하시오.

단어에서 첫 번째 문자의 위치는 0으로 하고 
찾는 문자가 여러 개일 때는 
처음 나오는 위치를 출력한다.

만약 찾는 문자가 없을 때는 
"No"라고 출력한다. 
대소문자는 구별되며 단어는 100자 이하이다.

*/
