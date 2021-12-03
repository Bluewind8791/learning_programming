#include <stdio.h>
#include <math.h>

double Radius (double area)
{
	return sqrt( (area/3.14) );
}

int main()
{
	double area=0;
	scanf("%lf",&area);
	
	printf("%.2lf", Radius(area));
	
	return 0;
}
/*
원의 넓이를 입력받아 
반지름의 길이를 
소수 둘째자리까지 
출력하는 프로그램을 작성하시오.

원의 넓이 = 반지름 * 반지름 * 3.14 식을 이용하시오.
area = radius * rad * 3.14
radius = root(area / 3.14)
*/
