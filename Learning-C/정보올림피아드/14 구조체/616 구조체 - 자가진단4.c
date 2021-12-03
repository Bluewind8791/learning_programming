#include <stdio.h>

struct point {
	int x, y;
};

int main()
{
	struct point t[3] = {0};
	int i;
	double x_wc, y_wc;
	
	for(i=0; i<3; i++)
	{
		scanf("%d %d", &t[i].x, &t[i].y);
		x_wc += t[i].x;
		y_wc += t[i].y;
	}
	
	printf("(%.1lf, %.1lf)", x_wc/3, y_wc/3);
		
	return 0;
}


/*
삼각형의 세 꼭지점의 
정수 좌표를 입력받아 
삼각형의 무게중심의 실수 좌표를 구하여 

소수 첫째자리까지 
출력하는 프로그램을 작성하시오.
*/
