#include <stdio.h>

struct school{
	char name[20];
	char school[20];
	int grade;
};

int main()
{
	struct school s1;
	scanf("%s", &s1.name);	
	scanf("%s", &s1.school);
	scanf("%d", &s1.grade);
	
	printf("Name : %s \n", s1.name);
	printf("School : %s \n", s1.school);
	printf("Grade : %d \n", s1.grade);
	
	return 0;
}

/*
"�̸�", "�б���", "�г�"�� �Է¹޾� 
�Ʒ��� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

(�̸��� �б����� ���� 20�� �����̴�.)
*/
