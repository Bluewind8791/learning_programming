#include <stdio.h>

typedef struct Tall {
	char name[20];
	int tall;
}tall;

int main()
{
	tall p[5] = {0};
	int i;
	int max = 300;
	int max_i = 0;
	
	
	for(i=0; i<5; i++)
	{
		scanf("%s %d", &p[i].name, &p[i].tall);
		if (max > p[i].tall)
		{
			max = p[i].tall;
			max_i = i;
		}
	}
	
	printf("%s %d", p[max_i].name, p[max_i].tall);
	
	return 0;
}

/*
5명의 이름과 키를 입력받아 

키가 가장 작은 사람의 
이름과 키를 
출력하는 프로그램을 작성하시오. 

이름은 20자 이하이다.
*/
