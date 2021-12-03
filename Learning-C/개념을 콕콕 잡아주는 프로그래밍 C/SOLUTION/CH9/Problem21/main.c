#include <stdio.h>

typedef struct rect {
	int left, top;
	int right, bottom;
} RECT;

typedef struct point {
	int x, y;
} POINT;

int main(void)
{
	RECT rect1;
	POINT p1;
	int tempX, tempY; 
	
	printf("좌상단점/우하단점의 좌표를 입력하세요(left, top, right, bottom 순)\n");
	scanf("%d %d %d %d", &rect1.left, &rect1.top, &rect1.right, &rect1.bottom);
	
	printf("입력된 직사각형 : 좌상단점=(%d,%d), 우하단점=(%d,%d)\n", 
							rect1.left, rect1.top, rect1.right, rect1.bottom);
	
	if(rect1.left > rect1.right) {
		tempX = rect1.left;
		rect1.left = rect1.right;
		rect1.right = tempX;
	}

	if(rect1.top > rect1.bottom) {
		tempY = rect1.top;
		rect1.top = rect1.bottom;
		rect1.bottom = tempY;
	}
	
	printf("수정된 직사각형 : 좌상단점=(%d,%d), 우하단점=(%d,%d)\n",
							rect1.left, rect1.top, rect1.right, rect1.bottom);
							
	printf("한점의 좌표를 입력하세요(x, y) : ");
	scanf("%d %d", &p1.x, &p1.y);
	
	if((p1.x>rect1.left) && (p1.x<rect1.right) && (p1.y>rect1.top) && (p1.y<rect1.bottom)) {
		printf("(%d, %d)는 직사각형 내부에 있습니다.\n", p1.x, p1.y); 
	}  
	else {
		printf("(%d, %d)는 직사각형 내부에 있지 않습니다.\n", p1.x, p1.y);
	} 

	return 0;
}










