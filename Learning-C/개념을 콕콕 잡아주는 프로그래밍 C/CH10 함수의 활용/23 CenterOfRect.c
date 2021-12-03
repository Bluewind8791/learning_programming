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
	
	printf("�Էµ� ���簢�� : �»����=(%d,%d), ���ϴ���=(%d,%d)\n",
		r1.left, r1.top, r1.right, r1.bottom);
	
	p = CenterOfRect(&r1);
	printf("���簢���� �߽� : (%d,%d)\n", p.x, p.y);
	
	return 0;
}

void InputRect(RECT *r)
{
	printf("�»����/���ϴ����� ��ǥ�� �Է��ϼ���(left, top, right, bottom ��)\n");
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
���簢�� ������ �����ϴ� rect ����ü�� �̿� 
rect ����ü�� �Է����ڷ� �ް� 
���簢���� �߽����� ��ǥ�� ���ϴ� CenterOfRect �Լ� ���� 

���簢�� ������ �Է¹޴� InputRect �Լ� ���� 

�Է¹��� ���簢���� ���ؼ� �߽����� ��ǥ�� ���Ͽ� ���  
*/
