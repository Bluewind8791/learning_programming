#include <stdio.h>

struct point {
	int x, y;
	int x2, y2;
};

int main()
{
	struct point p[2];
	int i, j;
	int triangle[2][2]={0};
	
	for(i=0; i<2; i++)	{
		scanf("%d %d", &p[i].x, &p[i].y);
		scanf("%d %d", &p[i].x2, &p[i].y2);
	}
	
	//compare p[0].x, p[1].x - small one
	if(p[0].x > p[1].x) {
		triangle[0][0] = p[1].x;
	}
	else {
		triangle[0][0] = p[0].x;
	}
	
	//compare p[0].y, p[1].y - small one
	if(p[0].y > p[1].y) {
		triangle[0][1] = p[1].y;
	}
	else {
		triangle[0][1] = p[0].y;
	}
	
	//compare p[0].x2, p[1].x2 - bigger one
	if(p[0].x2 > p[1].x2) {
		triangle[1][0] = p[0].x2;
	}
	else {
		triangle[1][0] = p[1].x2;
	}
	
	//compare p[0].y2, p[1].y2 - bigger one
	if(p[0].y2 > p[1].y2) {
		triangle[1][1] = p[0].y2;
	}
	else {
		triangle[1][1] = p[1].y2;
	}
	
	for(i=0; i<2; i++) {
		for(j=0; j<2; j++) {
			printf("%d ", triangle[i][j]);
		}
	}

	return 0;
 } 
 
/*
직사각형의 왼쪽 아래의 좌표(x, y)와 
오른쪽 위의 좌표(x2, y2)를 저장할 수 있는 
구조체 자료형을 만들고, 

두 개의 직사각형 자료를 입력받아 

두 직사각형을 포함하는 
최소의 직사각형 자료를 구하여 
구조체 변수에 저장하고 
출력하는 프로그램을 작성하시오. 

단, 모든 입력값은 100을 넘지 않는다. 
*/
