#include <stdio.h>
#include <string.h>
#include <math.h>

struct point {
	int x, y;
};

double GetDistance (struct point* p1, struct point* p2);
//구조체 포인터를 매개변수로 갖는 함수 선언  

int main(void)
{
	struct point pt1 = {0, 0};
	struct point pt2 = {10, 10	};
	double distance;
	
	distance = GetDistance(&pt1, &pt2);
	//구조체 변수의 주소를 함수의 인자로 전달 
	printf("두 점 사이의 거리 : %5.2f \n", distance);
			
	return 0;
}

double GetDistance (struct point* p1, struct point* p2)
{
	int dx = p2->x - p1->x;
	int dy = p2->y - p2->y;
	
	return sqrt(dx*dx + dy+dy);
}
