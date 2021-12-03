#include <stdio.h>
#include <string.h>

int main()
{
	char str[100] = {0};
	int n, i;
	scanf("%s", str);
	
	while(1)
	{
		scanf("%d", &n);
		//배열에서 삭제할 위치 입력 

		if ( strlen(str) == 1)
		//남은 문자가 1개일때 break
		{
			break;
		}
	
		for (i=n-1; i<strlen(str)-1; i++)
		//삭제한 위치 바로 뒤 배열부터 앞으로 한칸씩 끌어온다
		{
			str[i] = str[i+1];
		}
		
		str[strlen(str)-1] = '\0';
		//맨 마지막은 NULL 처리 
		printf("%s\n",str);
	}
	return 0;
}

/*
문자열(100자 이하)을 입력받은 후 
정수를 입력받아 
해당위치의 문자를 제거하고 
출력하는 작업을 반복하다가 
문자 1개가 남으면 
종료하는 프로그램을 작성하시오.


첫 번째 문자의 위치는 1이며 
만약 입력받은 번호가 
문자열의 길이 이상이면 
마지막 문자를 제거한다.
*/

