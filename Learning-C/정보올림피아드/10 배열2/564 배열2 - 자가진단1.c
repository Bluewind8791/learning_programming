#include <stdio.h>

int main()
{
	char alphabet[26] = {0};
	char ch;
	int i;
	
	while(1)
	{
		scanf(" %c", &ch);
		if (ch < 'A' || ch > 'Z')
		{
			break;
		}
		else
		{
			alphabet[ch-65]++;
		}
	}
	
	for (i=0; i<26; i++)
	{
		if (alphabet[i] != 0)
		{
			printf("%c : %d\n", i+65, alphabet[i]);
		}		
	}
	
	return 0;
}
/*
영문 대문자를 입력받다가 
대문자 이외의 문자가 입력되면 입력을 중단하고

영문 대문자들에 대하여 
1번 이상 입력된 각 문자와 
그 문자의 개수를 
사전 순으로 출력하는 프로그램을 작성하시오.

입력되는 문자의 개수는 2개 이상 100개 이하이다.

//HINT
'A'는 0번 'B'는 1번 'C'는 2번 … 'Z'는 25번에 count 한다. 

'A'는 메모리에 65로 저장된다. 

따라서 입력받은 문자에서 
65 또는 'A'를 빼면 
해당문자의 개수를 저장할 번호가 된다.

('B'-65=1 또는 'B'-'A'=1) 
1을 다시 'B'로 바꾸어 출력하려면 
char(1+65) 또는 char(1+'A')를 출력하면 된다.

*/
