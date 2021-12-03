#include <stdio.h>

typedef struct Data {
	int tall;
	double weight;
}data;

int main()
{
	data d[2];
	
	
	scanf("%d %lf", &d[0].tall, &d[0].weight);
	scanf("%d %lf", &d[1].tall, &d[1].weight);
	
	data std;
	std.tall = 5 + (d[0].tall+d[1].tall)/2;
	std.weight = ((d[0].weight+d[1].weight)/2) - 4.5;
	
	printf("height : %dcm\n", std.tall);
	printf("weight : %.1lfkg\n", std.weight);
	
	return 0;
}

/*
어떤 학생의 키는 
아버지와 어머니의 키의 평균보다 5cm 크고 
몸무게는 아버지와 어머니의 
몸무게의 평균보다 4.5kg 가볍다고 한다. 

키와 몸무게를 멤버변수로 갖는 구조체를 정의하고 
아버지와 어머니의 키와 몸무게를 입력받아 
학생의 키와 몸무게를 출력하는 프로그램을 작성하시오. 

키는 정수미만 버림하고 
몸무게는 반올림하여 소수 첫째자리까지 나타낸다.
*/
