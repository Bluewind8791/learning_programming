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
	
	//�������� �������� 
	for(i=0; i<3-1; i++)	{
		for(j=0; j<3-i-1; j++)	{
			if ( strcmp(d[j].name, d[j+1].name) > 0 ) {
				temp = d[j];
				d[j] = d[j+1];
				d[j+1] = temp;
			}
		}
	}
	
	//������ ���� ���� ����� �ڷ� ��� 
	printf("name : %s\n", d[0].name);
	printf("tel : %s\n", d[0].tel);
	printf("addr : %s\n", d[0].addr);
	
	return 0;
}

/*
�̸��� ��ȭ��ȣ, �ּҸ� ������ϴ� 
����ü�� �����ϰ� 

3���� �ڷḦ �Է¹��� �� 

���������� �̸��� ���� ���� ����� 
�ڷḦ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�̸�, ��ȭ��ȣ, �ּҴ� ��� 15�� �����̴�.
*/
