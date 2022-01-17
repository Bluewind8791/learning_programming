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
	
	printf("�»����/���ϴ����� ��ǥ�� �Է�(left, top, right, bottom ��)\n");
	scanf("%d %d %d %d", &r.left, &r.top, &r.right ,&r.bottom);
	
	PrintRect("�Էµ� ���簢��", &r);
	if( NormalizeRect( &r ) ) {
		PrintRect("����ȭ�� ���簢��", &r);
	}
	
	printf("������ ��ǥ�� �Է��ϼ���(x,y) : ");
	scanf("%d %d", &pt.x, &pt.y);
	
	printf("(%d,%d)�� ", pt.x, pt.y);
	if (IsPointInRect( &r, &pt )) {
		printf("���簢�� ���ο� �ֽ��ϴ�.\n");
	}
	else {
		printf("���簢�� �ܺο� �ֽ��ϴ�.\n");
	}
	
	return 0;
} 

void Swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp; 
}

void PrintRect(const char *title, const RECT *rt){
	printf("%s : �»����=(%d,%d), ���ϴ���=(%d,%d)\n",
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
	return result;		//Normalize�Ǹ� 1, �ƴϸ� 0 ��ȯ. 
}

int IsPointInRect(const RECT *r, const POINT *p) {
	if(p->x >= r->left && p->x <= r->right) {
		if(p->y >= r->top && p->y <= r->bottom) {
			return 1;
		}
	}
	else {
		return 0;		//���ο� ������ 1, �ܺο� ������ 0 ��ȯ. 
	}
}


 
 
