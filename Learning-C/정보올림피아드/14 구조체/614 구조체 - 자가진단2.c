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
"학교명", "학년"을 저장할 수 있는 
구조체로 2개의 변수를 선언한 후,

한 개의 변수는 학교명에 "Jejuelementary", 
학년에 "6"으로 각각 초기화하고 

다른 변수에는 새로운 학교와 학년을 입력받아 
아래와 같이 출력하는 프로그램을 작성하시오.

학교명은 20자 이하의 영문자이다.
*/
