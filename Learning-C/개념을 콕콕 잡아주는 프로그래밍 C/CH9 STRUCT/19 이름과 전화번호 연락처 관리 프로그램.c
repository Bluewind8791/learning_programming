#include <stdio.h>

typedef struct Contact {
	char name[20];
	char tel[20];
}contact;

int main()
{
	contact ct[5];
	int i;
	
	for(i=0; i<5; i++){
		printf("��    �� : ");
		gets(ct[i].name);
		printf("��ȭ��ȣ : ");
		gets(ct[i].tel);
	}
	
	printf("--- ��ü ����ó ��� ---\n");
	for(i=0; i<5; i++){
		printf("%s ", ct[i].name);
		printf("%30s\n", ct[i].tel);
	}
	
	return 0;
}

/*
�̸��� ��ȭ��ȣ�� �����ϴ� ������ ����ó ���� ���α׷�

�̸��� ��ȭ��ȣ�� ����� ���� contact ����ü ����

�̸��� ��ȭ��ȣ�� ���� ���ڿ��� ����
�� ���� ũ�Ⱑ 5�� contact ����ü �迭�� �̿��Ͽ�
�̸��� ��ȭ��ȣ�� �Է¹޾� ����ϴ� ���α׷� 
*/
