#include <stdio.h>

typedef struct _rect {
	int left, top, right, bottom;
}RECT;

typedef struct _point {
	int x, y;
}POINT;

void InputRect(RECT *r);
POINT CenterOfRect(RECT *r);

int main()
{
	RECT r1;
	POINT p;
	
	InputRect(&r1);
	
	printf("입력된 직사각형 : 좌상단점=(%d,%d), 우하단점=(%d,%d)\n",
		r1.left, r1.top, r1.right, r1.bottom);
	
	p = CenterOfRect(&r1);
	printf("직사각형의 중심 : (%d,%d)\n", p.x, p.y);
	
	return 0;
}

void InputRect(RECT *r)
{
	printf("좌상단점/우하단점의 좌표를 입력하세요(left, top, right, bottom 순)\n");
	scanf("%d %d %d %d",&r->left, &r->top, &r->right, &r->bottom);
}

POINT CenterOfRect(RECT *r)
{
	POINT p;
	POINT *ptr = &p;
	
//	p.x = (int)((r->left + r->right) / 2);
//	p.y = (int)((r->top + r->bottom) / 2);
	
	ptr->x = (int)((r->left + r->right) / 2);
	ptr->y = (int)((r->top + r->bottom) / 2);
	
	return *ptr;
}

/*
직사각형 정보를 저장하는 rect 구조체를 이용 
rect 구조체를 입력인자로 받고 
직사각형의 중심점의 좌표를 구하는 CenterOfRect 함수 정의 

직사각형 정보를 입력받는 InputRect 함수 정의 

입력받은 직사각형에 대해서 중심점의 좌표를 구하여 출력  
*/
