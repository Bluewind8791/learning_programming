#include <stdio.h>
#define PIE 3.141592
#define AREA(X,Y) (Y)*(X)
#define POW(X) (X)*(X)

int main()
{
	double rad;
	printf("radius : ");
	scanf("%lf", &rad);
	
	double area;
	area = AREA( PIE, POW(rad) );
	
	printf("area = %.3lf", area);
	
	return 0;
}

/*
원주율을 3.141592로 매크로 상수로 정의하고 

원의 넓이를 구하는 매크로 함수를 작성하여 
반지름을 입력받아 

원의 넓이를 출력하는 
프로그램을 작성하시오. 
(소수 넷째자리에서 반올림)
*/
