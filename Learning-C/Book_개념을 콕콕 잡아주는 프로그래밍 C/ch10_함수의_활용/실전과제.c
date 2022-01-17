#include <stdio.h>

typedef struct point {
	int x,y;
}POINT;

typedef struct rect {
	int left, top, right, bottom;
}RECT;

void Swap(int *x, int *y);
void PrintRect(const char *title, const RECT *rt);
int NormalizeRect(RECT *r);
int IsPointInRect(const RECT *r, const POINT *p);

int main()
{
	RECT r = {0,};
	POINT pt;
	
	printf("좌상단점/우하단점의 좌표를 입력(left, top, right, bottom 순)\n");
	scanf("%d %d %d %d", &r.left, &r.top, &r.right ,&r.bottom);
	
	PrintRect("입력된 직사각형", &r);
	if( NormalizeRect( &r ) ) {
		PrintRect("정규화된 직사각형", &r);
	}
	
	printf("한점의 좌표를 입력하세요(x,y) : ");
	scanf("%d %d", &pt.x, &pt.y);
	
	printf("(%d,%d)는 ", pt.x, pt.y);
	if (IsPointInRect( &r, &pt )) {
		printf("직사각형 내부에 있습니다.\n");
	}
	else {
		printf("직사각형 외부에 있습니다.\n");
	}
	
	return 0;
} 

void Swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp; 
}

void PrintRect(const char *title, const RECT *rt){
	printf("%s : 좌상단점=(%d,%d), 우하단점=(%d,%d)\n",
		title, rt->left, rt->top, rt->right, rt->bottom);
}

int NormalizeRect(RECT *r){
	int result = 0;
	if( r->left > r->right ) {
		Swap(&r->left, &r->right);
		result=1;
	}
	if( r->top > r->bottom ) {
		Swap(&r->top, &r->bottom);
		result = 1;
	}
	return result;		//Normalize되면 1, 아니면 0 반환. 
}

int IsPointInRect(const RECT *r, const POINT *p) {
	if(p->x >= r->left && p->x <= r->right) {
		if(p->y >= r->top && p->y <= r->bottom) {
			return 1;
		}
	}
	else {
		return 0;		//내부에 있으면 1, 외부에 있으면 0 반환. 
	}
}


 
 
