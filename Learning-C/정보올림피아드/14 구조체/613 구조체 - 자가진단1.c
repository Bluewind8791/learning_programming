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
"이름", "학교명", "학년"을 입력받아 
아래와 같이 출력하는 프로그램을 작성하시오.

(이름과 학교명은 각각 20자 이하이다.)
*/
