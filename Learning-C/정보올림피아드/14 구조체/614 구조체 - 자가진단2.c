#include <stdio.h>

struct School{
	char school[30];
	int grade;
};

int main()
{
	struct School s1 = {"Jejuelementary", 6};
	struct School s2 = {0};
	
	scanf("%s %d", &s2.school, &s2.grade);
	
	printf("%d grade in %s School\n", s1.grade, s1.school);
	printf("%d grade in %s School\n", s2.grade, s2.school);
	
	return 0;
}

/*
"�б���", "�г�"�� ������ �� �ִ� 
����ü�� 2���� ������ ������ ��,

�� ���� ������ �б��� "Jejuelementary", 
�г⿡ "6"���� ���� �ʱ�ȭ�ϰ� 

�ٸ� �������� ���ο� �б��� �г��� �Է¹޾� 
�Ʒ��� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�б����� 20�� ������ �������̴�.
*/
