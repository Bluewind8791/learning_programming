#include <stdio.h>

typedef struct Data {
	char name[100];
	char tel[100];
	char addr[100];
}data;

int main()
{
	data d;
	scanf("%s %s %s", &d.name, &d.tel, &d.addr);
	
	printf("name : %s\n", d.name);
	printf("tel : %s\n", d.tel);
	printf("addr : %s\n", d.addr);
	
	return 0;
}

/*
이름과 전화번호, 주소를 멤버로하는 
구조체를 정의하여 

1개의 자료를 입력받고 
출력하는 프로그램을 작성하시오.

각각의 길이는 100자 이하다.
*/
