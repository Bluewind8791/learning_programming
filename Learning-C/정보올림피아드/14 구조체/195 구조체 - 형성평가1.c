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
�̸��� ��ȭ��ȣ, �ּҸ� ������ϴ� 
����ü�� �����Ͽ� 

1���� �ڷḦ �Է¹ް� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

������ ���̴� 100�� ���ϴ�.
*/
