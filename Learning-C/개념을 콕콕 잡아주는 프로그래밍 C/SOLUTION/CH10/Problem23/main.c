#include <stdio.h>

typedef struct rect {
	int left, top, right, bottom;
} RECT;

typedef struct point {
	int x, y;
} POINT;

POINT CenterOfRect(const RECT *r);
void InputRect(RECT *r);

int main(void)
{
	RECT rect;
	POINT pt;
	
	InputRect(&rect);
	
	printf("�Էµ� ���簢�� : �»����=(%d,%d), ���ϴ���=(%d,%d)\n",
			rect.left, rect.top, rect.right, rect.bottom);
	
	pt = CenterOfRect(&rect); 
	
	printf("���簢���� �߽� : (%d, %d)\n", pt.x, pt.y); 

	return 0;
}


POINT CenterOfRect(const RECT *r)
{
	POINT p;
	
	p.x = (int)((((r->left) + (r->right)) / 2) + 0.5);	
	p.y = (int)((((r->top) + (r->bottom)) / 2) + 0.5);
	
	return p;
}


void InputRect(RECT *r)
{
	printf("�»����/���ϴ����� ��ǥ�� �Է��ϼ���(left, top, right, bottom ��)\n");
	scanf("%d %d %d %d", &r->left, &r->top, &r->right, &r->bottom); 
}









