#include <stdio.h>
#include <math.h>

struct Test_Result{
	char name[20];
	int korean, english;
	double average;
};

int main()
{
	struct Test_Result s1, s2;
	
	scanf("%s %d %d", &s1.name, &s1.korean, &s1.english);
	scanf("%s %d %d", &s2.name, &s2.korean, &s2.english);
	
	s1.average = (double)(s1.korean + s2.korean) / 2;
	s2.average = (double)(s1.english + s2.english) / 2;
	
	printf("%s %d %d\n", s1.name, s1.korean, s1.english);
	printf("%s %d %d\n", s2.name, s2.korean, s2.english);
	printf("avg %.lf %.lf\n", floor(s1.average), floor(s2.average));
		
	return 0;
}

/*
두 명의 이름과 국어, 영어 점수를 입력받아 
과목별 점수의 평균을 구하여 
출력하는 프로그램을 작성해 보시오.

(이름은 20자 이하이고 
평균의 소수점 이하는 버림한다.)
*/
