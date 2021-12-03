/* Lab10.c */
#include <stdio.h>

typedef struct point {
	int x, y;
} POINT;

typedef struct rect {
	int left, top, right, bottom;
} RECT;

void Swap(int *x, int *y);
void PrintRect(const char *title, const RECT *rt);
int NormalizeRect(RECT *rt);
int IsPointInRect(const POINT *p, const RECT *rt);

int main(void)
{
	RECT rect1 = {0};
	POINT pt;
	
	printf("�»����/���ϴ����� ��ǥ�� �Է��ϼ���(left, top, right, bottom��)\n");
	scanf("%d %d %d %d", &rect1.left, &rect1.top, &rect1.right, &rect1.bottom);
	
	PrintRect("�Էµ� ���簢��", &rect1);
	if(NormalizeRect(&rect1)) {
		PrintRect("����ȭ�� ���簢��", &rect1); 
	} 
	
	printf("������ ��ǥ�� �Է��ϼ���(x, y) : ");
	scanf("%d %d", &pt.x, &pt.y);
	
	printf("(%d, %d)�� ", pt.x, pt.y);
	if(IsPointInRect(&pt, &rect1)) {
		printf("���簢�� ���ο� �ֽ��ϴ�.\n"); 
	} 
	else {
		printf("���簢�� �ܺο� �ֽ��ϴ�.\n"); 
	}

	return 0;
}


void Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


void PrintRect(const char *title, const RECT *rt)
{
	printf("%s : �»����=(%d,%d), ���ϴ���(%d,%d)\n",
			title, rt->left, rt->top, rt->right, rt->bottom);
}


int NormalizeRect(RECT *rt)
{
	int result = 0;
	if(rt->left > rt->right) {
		Swap(&rt->left, &rt->right);
		result = 1;
	}
	
	if(rt->top > rt->bottom) {
		Swap(&rt->top, &rt->bottom);
		result = 1;
	}
	
	return result;
}


int IsPointInRect(const POINT *p, const RECT *rt)
{
	if((p->x > rt->left) && (p->x < rt->right) && 
	   (p->y > rt->top)  && (p->y < rt->bottom)) {
		return 1;   
	}
	else {
		return 0;
	}
}










