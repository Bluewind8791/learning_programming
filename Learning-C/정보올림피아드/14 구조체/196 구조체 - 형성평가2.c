#include <stdio.h>
#include <string.h>

typedef struct Data {
	char name[15];
	char tel[15];
	char addr[15];
}data;

int main()
{
	data d[3];
	int i, j;
	data temp;
	
	for(i=0; i<3; i++)	{
		scanf("%s %s %s", &d[i].name, &d[i].tel, &d[i].addr);
	}
	
	//내림차순 버블정렬 
	for(i=0; i<3-1; i++)	{
		for(j=0; j<3-i-1; j++)	{
			if ( strcmp(d[j].name, d[j+1].name) > 0 ) {
				temp = d[j];
				d[j] = d[j+1];
				d[j+1] = temp;
			}
		}
	}
	
	//사전순 가장 빠른 사람의 자료 출력 
	printf("name : %s\n", d[0].name);
	printf("tel : %s\n", d[0].tel);
	printf("addr : %s\n", d[0].addr);
	
	return 0;
}

/*
이름과 전화번호, 주소를 멤버로하는 
구조체를 정의하고 

3명의 자료를 입력받은 후 

사전순으로 이름이 가장 빠른 사람의 
자료를 출력하는 프로그램을 작성하시오.

이름, 전화번호, 주소는 모두 15자 이하이다.
*/
